
#include <queue>
#include <bitset>
#include "cabin.h"


Cabin::Cabin(): fv_(nullptr), sv_(nullptr), area_(nullptr), rv_(nullptr), bmn_(0), group_(11), code_num_(3) {
    volume_ = (1 << code_num_) - 2;
    partition_num_ = group_ * volume_;
    filter_v_num_ = group_ * code_num_;
}

Cabin::Cabin(Column* column, QueryQueue* query): fv_(nullptr), sv_(nullptr), area_(nullptr), rv_(nullptr), bmn_(0), group_(6), code_num_(5) {
    column_ = column;
    query_ = query;
    volume_ = std::max((1 << code_num_) - 2, 1);
    partition_num_ = group_ * volume_;
    filter_v_num_ = group_ * code_num_;
    manual_configure = true;
}

Cabin::Cabin(Column* column, QueryQueue* query, workloadFeature* wf): fv_(nullptr), sv_(nullptr), area_(nullptr), rv_(nullptr), bmn_(0) {
    column_ = column;
    query_ = query;
    workload_feature_ = wf;
    manual_configure = false;
}

Cabin::~Cabin() {
    Destroy();
}

void Cabin::Destroy() {
//     std::cout << "query with position array: " << query_w_pa_num << std::endl;
//     std::cout << "query without position array: " << query_wo_pa_num << std::endl;
// #ifdef TIME_ANALYSIS
//     std::cout << "total compute time (with position array): " << compute_time << std::endl;
//     //std::cout << "compute (without read and write memory) time: " << compute_cal_time << std::endl;
//     std::cout << "total compute time (without position array): " << compute_time_wo_sp << std::endl;
//     std::cout << "total compute time (bitmap copying): " << compute_time_bitmap << std::endl;
//     std::cout << "total refine time: " << refine_time << std::endl;
// #endif
//     std::cout << "total shortcut time: " << shortcut_num << std::endl;
    os_aligned_free(fv_);
    fv_ = nullptr;

    os_aligned_free(sv_);
    sv_ = nullptr;
    os_aligned_free(sv1);
    sv1 = nullptr;
    os_aligned_free(sv2);
    sv2 = nullptr;

    delete []area_;
    area_ = nullptr;
    delete []area_val_;
    area_val_ = nullptr;
    delete []area_pos_;
    area_pos_ = nullptr;
    delete []area_len_;
    area_len_ = nullptr;

    delete []rv_;
    rv_ = nullptr;

    delete simd;
    simd = nullptr;

    delete[]positionSegArray;
    positionSegArray = nullptr;
}

void Cabin::ParameterDetermination(workloadFeature* wf)
{
    size_t tuple_number = value_num_;
    double available_memory = wf->available_memory;

    size_t p_k,p_m;
    double p_p;
    const double a_1 = 5.974237;
    const double a_2 = 2244.582424;
    const double a_3 = 10.3489;
    const double a_4 = 24453.1697;

    double T  = std::numeric_limits<double>::max();
    size_t b_1,b_2;
    for(size_t k = 2; k <= 9; k++)
    {
        int max_m = ((double)available_memory * 8 * 1024 * 1024 * 1024) / (tuple_number*k);
        int min_m = (((double)available_memory * 8 * 1024 * 1024 * 1024) / tuple_number - 8*sizeof(PosWidth)) / k;
        min_m = (min_m <= 1) ? 1 : min_m;
        for(int m = min_m; m <= max_m ; m++)
        {
            double p = ((double)available_memory * 1024 * 1024 * 1024 / tuple_number - ((double)m*k/8)) / sizeof(PosWidth);
            if(p > 1) p = 1;
            b_1 = 0, b_2 = 0;
            size_t partition = m * ((1 << k) - 2);
            b_1 = query_->QuerySize()*p;
            b_2 = query_->QuerySize() - b_1;
            //std::cout << b_2 << std::endl;
            double T_1 = (a_1 * k + a_2 / partition) * tuple_number / 1000000000;   //cabin_B
            double T_2 = (a_3 * k + a_4 / partition) * tuple_number / 1000000000;   //cabin_S
            double totalT = b_1 * T_1 + b_2 * T_2;

            if(totalT < T) {
                T = totalT;
                p_k = k;
                p_m = m;
                p_p = p;
            }
        }
    }

    code_num_ = p_k;
    group_ = p_m;
    proportion_ = p_p;
    volume_ = (1 << code_num_) - 2;
    partition_num_ = group_ * volume_;
    filter_v_num_ = group_ * code_num_;

    positionSegArray = new size_t[partition_num_];
    std::fill(positionSegArray, positionSegArray+partition_num_, 0);
    b_1 = 0, b_2 = 0;

    size_t stored_interval_num = partition_num_ * proportion_;
    // the flags should be random (for zipf test of cabin without selective position array)
    std::vector<int> deck(partition_num_);
    std::iota(deck.begin(), deck.end(), 0);
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(232));
    for(size_t index = 0; index < stored_interval_num; index++)
    {
        positionSegArray[deck[index]] = 1;
    }


    b_1 = query_->QuerySize()*p_p;
    b_2 = query_->QuerySize() - b_1;
}

void Cabin::SkewCandidate(double memoryBudget, size_t tupleNumber, std::map<WordUnit, size_t> &skew_value)
{
    size_t intervalMaxNum = 0;
    for(size_t k = 2; k <= 9; k++) {
        int max_m = ((double) memoryBudget * 8 * 1024 * 1024 * 1024) / (tupleNumber * k);
        size_t partition = max_m * ((1 << k) - 2);
        if(partition > intervalMaxNum) intervalMaxNum = partition;
    }

    // obtain the skew candidates
    size_t threshold = tupleNumber / intervalMaxNum;
    size_t value_count = 1;
    WordUnit value = column_->GetTuple(rv_[0]);
    for(size_t i = 1; i < tupleNumber; i++)
    {
        if(column_->GetTuple(rv_[i]) == value) {
            value_count++;
        } else {
            if(value_count > threshold) {
                skew_value.insert(std::make_pair(value,value_count));
                total_popular_num_ += value_count;
            }
            value = column_->GetTuple(rv_[i]);
            value_count = 1;
        }
    }
    if(value_count > threshold) {
        skew_value.insert(std::make_pair(value,value_count));
        total_popular_num_ += value_count;
    }
}

void Cabin::SkewCandidate_sampling(double memoryBudget, size_t tupleNumber, std::vector<WordUnit> &sampling_vec, std::map<WordUnit, size_t> &skew_value)
{
    size_t intervalMaxNum = 0;
    for(size_t k = 2; k <= 9; k++) {
        int max_m = ((double) memoryBudget * 8 * 1024 * 1024 * 1024) / (tupleNumber * k);
        size_t partition = max_m * ((1 << k) - 2);
        if(partition > intervalMaxNum) intervalMaxNum = partition;
    }

    // obtain the skew candidates
    size_t threshold = tupleNumber / intervalMaxNum;
    size_t value_count = 1;
    WordUnit value = sampling_vec[0];
    for(size_t i = 1; i < sampling_vec.size(); i++)
    {
        if(sampling_vec[i] == value) {
            value_count++;
        } else {
            if(value_count > threshold) {
                skew_value.insert(std::make_pair(value,value_count));
            }
            value = sampling_vec[i];
            value_count = 1;
        }
    }
    if(value_count > threshold) {
        skew_value.insert(std::make_pair(value,value_count));
    }
}

void Cabin::DataAwareInterval(size_t partition, size_t group, size_t tupleNumber, const std::map<WordUnit, size_t> &skew_value, \
                             double &skewed_interval_group_prop, double &skewed_interval_prop, size_t &skewed_interval_group_num)
{
    skewed_interval_group_prop = 0.0;
    skewed_interval_prop = 0.0;
    skewed_interval_group_num = 0;
    size_t skewed_interval_group_value_num = 0;
    size_t skewed_interval_value_num = 0;
    size_t current_interval_size = tupleNumber / partition;
    size_t current_interval_group_size = tupleNumber / group;

    size_t skewed_value_num = 0;
    for(auto v : skew_value){
        if(v.second > current_interval_group_size) {
            skewed_interval_group_value_num += v.second;
            skewed_interval_group_num++;
        } else if (v.second > current_interval_size) {
            skewed_interval_value_num += v.second;
        }
    }
    skewed_interval_group_prop = (double)skewed_interval_group_value_num / (double)tupleNumber;
    skewed_interval_prop = (double)skewed_interval_value_num / (double)tupleNumber;
}

void Cabin::SetSkewedDataTable(size_t partition, size_t group, size_t tupleNumber, const std::map<WordUnit, size_t> &skew_value, \
                             std::vector<std::pair<WordUnit,size_t>> &skewed_interval_group_values, std::vector<std::pair<WordUnit,size_t>> &skewed_interval_values, double &skew_prop)
{
    size_t current_interval_size = tupleNumber / partition;
    size_t current_interval_group_size = tupleNumber / group;

    size_t skewed_value_num = 0;
    for(auto v : skew_value){
        if(v.second > current_interval_group_size) {
            skewed_interval_group_values.emplace_back(v.first,v.second);
            skewed_value_num += v.second;
        } else if (v.second > current_interval_size) {
            skewed_interval_values.emplace_back(v.first,v.second);
            skewed_value_num += v.second;
        }
    }
    skew_prop = (double)skewed_value_num / tupleNumber;
}

void Cabin::SetSkewedDataTableNDV(std::vector<std::pair<WordUnit,size_t>> &skewed_interval_group_values)
{
    std::unordered_map<WordUnit,size_t> hash_table;
    for(size_t i = 0; i < value_num_; i++)
    {
        hash_table[column_->GetTuple(i)]++;
    }
    for(auto i : hash_table)
    {
        skewed_interval_group_values.emplace_back(i);
    }
    std::sort(skewed_interval_group_values.begin(), skewed_interval_group_values.end(),[&](std::pair<WordUnit, size_t> &a, std::pair<WordUnit, size_t> &b)
    {return a.first < b.first;});
    for (auto i : skewed_interval_group_values) {
        std::cout << "values: " << i.first << ", number: " << i.second << std::endl;
    }
}

bool Cabin::ObtainNDV_baseline(size_t ndv_bound)
{
    WordUnit pre = column_->GetTuple(rv_[0]);
    size_t ndv = 1;
    for(size_t i = 1; i < value_num_; i++)
    {
        WordUnit cur = column_->GetTuple(rv_[i]);
        if(cur != pre) {
            ndv++;
            if(ndv > ndv_bound) return false;
            pre = cur;
        }
    }
    ndv_ = ndv;
    return true;
}

void Cabin::ParameterDetermination_baseline(workloadFeature* wf)
{
    size_t tuple_number = value_num_;
    double available_memory = wf->available_memory;

    std::map<WordUnit, size_t> skew_value;
#ifdef CREATE_INFO
    PRINT_EXCECUTION_TIME("SkewCandidate", SkewCandidate(available_memory, tuple_number, skew_value))
#else
    SkewCandidate(available_memory, tuple_number, skew_value);
#endif    
    if(skew_value.empty()) {
        ParameterDetermination(workload_feature_);
    } else {
        size_t ndv_bound = available_memory / (double)((double)value_num_ / ((size_t)8* 1024 * 1024 * 1024));
        bool ndv_shortcut;
#ifdef CREATE_INFO        
        PRINT_EXCECUTION_TIME("NDV", ndv_shortcut = ObtainNDV_baseline(ndv_bound))
#else
        ndv_shortcut = ObtainNDV_baseline(ndv_bound);
#endif
        if(!ndv_shortcut) {
            size_t p_k,p_m;
            double p_p;
            const double a_1 = 5.974237;
            const double a_2 = 2244.582424;
            const double a_3 = 10.3489;
            const double a_4 = 24453.1697;

            double T  = std::numeric_limits<double>::max();
            size_t b_1, b_2, b_3, b_4;
            double space_usage = 0;
            for(size_t k = 2; k <= 9; k++)
            {
                int max_m = ((double)available_memory * 8 * 1024 * 1024 * 1024) / (tuple_number*k);
                int min_m = (((double)available_memory * 8 * 1024 * 1024 * 1024) / tuple_number - 8*sizeof(PosWidth)) / k;
                min_m = (min_m <= 1) ? 1 : min_m;
                for(int m = min_m; m <= max_m ; m++)
                {
                    size_t partition = m * ((1 << k) - 2);
                    double p = ((double)available_memory * 1024 * 1024 * 1024 / tuple_number - ((double)m*k/8)) / sizeof(PosWidth);
                    if(p > 1) p = 1;

                    double skewed_interval_group_prop;
                    double skewed_interval_prop;
                    size_t skewed_interval_group_num = 0;

                    DataAwareInterval(partition, m, tuple_number, skew_value, skewed_interval_group_prop, skewed_interval_prop, skewed_interval_group_num);

                    // query uniformly distributed
                    b_1 = 0; // query num of cabin_fs with selective position array
                    b_2 = 0; // query num of cabin_fs without selective position array
                    b_3 = query_->QuerySize()*skewed_interval_prop;   // query num of cabin_fsd for skewed interval
                    b_4 = query_->QuerySize()*skewed_interval_group_prop;   // query num of cabin_fsd for skewed interval group

                    double p_compensation = (double)skewed_interval_group_num*(k-1) / (8*sizeof(PosWidth));   // as for in skewed interval group, cabin only store 1 bit vector but not k bit vector

                    p += p_compensation;
                    if(skewed_interval_group_prop + skewed_interval_prop >= 1) {
                        b_1 = b_2 = 0;
                        p = 0;
                    }
                    if(skewed_interval_group_prop + skewed_interval_prop + p > 1) {
                        b_1 = query_->QuerySize() - b_3 - b_4;
                        b_2 = 0;
                        p = 1 - skewed_interval_group_prop - skewed_interval_prop;
                    } else {
                        b_1 = query_->QuerySize()*p;
                        b_2 = query_->QuerySize() - b_1 - b_3 - b_4;
                    }

                    size_t non_skewed_tuple_number = tuple_number * (1 - skewed_interval_group_prop - skewed_interval_prop);
                    size_t non_skewed_partition = partition - skewed_interval_group_num * ((1 << k) - 2);

                    double T_1 = (a_1 * k) * tuple_number / 1000000000 + (a_2 / non_skewed_partition) * non_skewed_tuple_number / 1000000000;   //cabin_fs with selective position array
                    double T_2 = (a_3 * k) * tuple_number / 1000000000 + (a_4 / non_skewed_partition) * non_skewed_tuple_number / 1000000000;   //cabin_fs without selective position array
                    double T_3 = (a_1 * k) * tuple_number / 1000000000;   //cabin_fsd for skewed interval
                    double T_4 = (a_1 * 1) * tuple_number / 1000000000;   //cabin_fsd for skewed interval group
                    double totalT = b_1 * T_1 + b_2 * T_2 + b_3 * T_3 + b_4 * T_4;
                    double space_usage_tmp = (p * (double)sizeof(PosWidth) + skewed_interval_group_num / 8 + (m - skewed_interval_group_num) * (double)k / 8) * tuple_number / (1024 * 1024 * 1024);

                    if(totalT < T) {
                        T = totalT;
                        p_k = k;
                        p_m = m;
                        p_p = p;
                        space_usage = space_usage_tmp;
                    }
                }
            }


            code_num_ = p_k;
            group_ = p_m;
            proportion_ = p_p;
            volume_ = (1 << code_num_) - 2;
            partition_num_ = group_ * volume_;
            filter_v_num_ = group_ * code_num_;

            positionSegArray = new size_t[partition_num_];
            std::fill(positionSegArray, positionSegArray+partition_num_, 0);

            // prepare for the area map generation
            double skew_prop = 0.0;
            SetSkewedDataTable(partition_num_, group_, tuple_number, skew_value, skewed_interval_group_values_, skewed_interval_values_, skew_prop);
            // Here we assume the skewed data is zipf distribution where the lower value, the larger proportion
            int interval_id = 0;
            while (interval_id < skewed_interval_group_values_.size()*volume_)
            {
                positionSegArray[interval_id++] = 3;  // skewed interval group
            }
            while (interval_id < skewed_interval_group_values_.size()*volume_ + skewed_interval_values_.size())
            {
                positionSegArray[interval_id++] = 2;  // skewed interval
            }
            size_t non_skewed_partition_num = partition_num_ - interval_id;
            size_t non_skewed_partition_num_with_sp;
            if(fabs(proportion_ + skew_prop - 1) < 1e-5) {
                non_skewed_partition_num_with_sp = non_skewed_partition_num;
            } else {
                non_skewed_partition_num_with_sp = (double)non_skewed_partition_num * (proportion_/(1-skew_prop));
            }

            // the flags should be random (for zipf test of cabin without selective position array)
            size_t first_interval_id_with_sp = skewed_interval_group_values_.size()*volume_ + skewed_interval_values_.size();
            size_t last_interval_id_with_sp = first_interval_id_with_sp + non_skewed_partition_num_with_sp;
            assert(last_interval_id_with_sp <= partition_num_);
            std::vector<int> deck(partition_num_ - first_interval_id_with_sp);
            std::iota(deck.begin(), deck.end(), first_interval_id_with_sp);
            std::shuffle(deck.begin(), deck.end(), std::default_random_engine(232));
            for(size_t index = 0; index < non_skewed_partition_num_with_sp; index++)
            {
                positionSegArray[deck[index]] = 1;
            }
        } else {
            double bitmap_index_style_s = (double)ndv_ * value_num_ / ((size_t)8* 1024 * 1024 * 1024);
            std::cout << "bitmap index style, storage usage: " << bitmap_index_style_s << std::endl;

            code_num_ = 1;
            group_ = ndv_;
            proportion_ = 0;
            volume_ = 1;
            partition_num_ = group_ * volume_;
            filter_v_num_ = group_ * code_num_;
            std::cout << LONGLINE << LONGLINE << std::endl;
            std::cout << "k,m,p: " << code_num_ << " " << group_ << " " << proportion_ << std::endl;
            std::cout << "estimate total time cost: " << query_->QuerySize() * 5.974237 * value_num_ / 1000000000 << std::endl;
            std::cout << "estimate space usage: " << bitmap_index_style_s << std::endl;

            positionSegArray = new size_t[partition_num_];
            std::fill(positionSegArray, positionSegArray+partition_num_, 0);
            SetSkewedDataTableNDV(skewed_interval_group_values_);

            int interval_id = 0;
            while (interval_id < ndv_)
            {
                positionSegArray[interval_id++] = 3;  // skewed interval group
            }
        }
    }
}

void Cabin::CreateIndex_sampling_beta()
{
    /* sampling */
    double sampling_prop = 0.01;
    size_t sampling_number = value_num_ * sampling_prop;
    std::vector<WordUnit> sampling_vector(sampling_number);

    sampling_vector.assign(column_->array_, column_->array_ + sampling_number);
    std::sort(sampling_vector.begin(), sampling_vector.end());

    /* parameter configure */
    std::map<WordUnit, size_t> skew_value;
#ifdef CREATE_INFO        
    PRINT_EXCECUTION_TIME("SkewCandidate", SkewCandidate_sampling((workload_feature_->available_memory)*sampling_prop, sampling_number, sampling_vector, skew_value))
#else
    SkewCandidate_sampling((workload_feature_->available_memory)*sampling_prop, sampling_number, sampling_vector, skew_value);
#endif
    if(skew_value.empty()) {
        ParameterDetermination(workload_feature_);
    }
    else {
        // to-do
        std::cout << "removed the past implementation" << std::endl;
        exit(EXIT_FAILURE);
    }

    /* sorting */
    area_val_ = new WordUnit [partition_num_];
    area_pos_ = new PosWidth [partition_num_];
    area_len_ = new size_t [partition_num_];
    std::map<WordUnit, size_t> area_val_map;
    // get the boundary of the areas according to the sampling sorted vector
    size_t average_area_size = (double)sampling_number / partition_num_;
    for(size_t area_id = 0; area_id < partition_num_; area_id++) {
        area_val_[area_id] = sampling_vector[area_id * average_area_size];
        area_val_map.insert(std::make_pair(sampling_vector[area_id * average_area_size], area_id));
    }
    area_id_array_ = new int[value_num_];
    for(size_t id = 0; id < value_num_; id++) {
        WordUnit value = column_->GetTuple(id);
        size_t target_area_id;
        auto it = area_val_map.upper_bound(value);
        if(it == area_val_map.end()) target_area_id = partition_num_-1;
        else if(it == area_val_map.begin()) {target_area_id = 0; area_val_[0] = std::min(area_val_[0], value);}
        else target_area_id = it->second-1;
        area_id_array_[id] = target_area_id;
    }

    size_t rv_num = 0;
    std::vector<std::vector<std::pair<WordUnit, PosWidth>>> buckets(partition_num_);

    //sorting each area buckets (and storing data into rv)
    for(size_t area_id = 0; area_id < partition_num_; area_id++) {
        buckets[area_id].reserve((double)value_num_/partition_num_*1.1);
    }
    for(size_t id = 0; id < value_num_; id++) {
        if(positionSegArray[area_id_array_[id]] == 1) {
            WordUnit value = column_->GetTuple(id);
            buckets[area_id_array_[id]].emplace_back(std::make_pair(value, id));
            rv_num++;
        }
    }
    rv_ = new PosWidth[rv_num];
    size_t rv_end = 0;

    for(size_t area_id = 0; area_id < partition_num_; area_id++) {
        area_len_[area_id] = buckets[area_id].size();
        if(positionSegArray[area_id] != 1) continue;

        std::sort(buckets[area_id].begin(), buckets[area_id].end(), [&](std::pair<WordUnit, PosWidth> &a, std::pair<WordUnit, PosWidth> &b)
        {return a.first < b.first;});
    }
    for(size_t area_id = 0; area_id < partition_num_; area_id++) {
        for(auto & i : buckets[area_id]) {
            rv_[rv_end++] = i.second;
        }
    }
    for(size_t area_id = 0; area_id < partition_num_; area_id++) {
        std::vector<std::pair<WordUnit, PosWidth> >().swap(buckets[area_id]);    // free the memory of the vector
    }
    std::vector<std::vector<std::pair<WordUnit, PosWidth>>>().swap(buckets);    // free the memory of the vector

    CodeGen(code_num_);
    /* area map */
    area_ = new m_area_t [partition_num_];
    for(size_t area_id = 0; area_id < partition_num_; area_id++) {
        area_[area_id].val = area_val_[area_id];
        area_[area_id].len = area_len_[area_id];
    }
    area_[0].pos = area_pos_[0] = 0;
    for(size_t area_id = 1; area_id < partition_num_; area_id++) {
        area_[area_id].pos = area_pos_[area_id] = area_[area_id-1].pos + area_[area_id-1].len;
    }

    /* filter sketches */
    fv_ = static_cast<bitmap_t *>(os_aligned_alloc(filter_v_num_*aligned_slot, 32));
    memset(fv_, 0, filter_v_num_ * aligned_slot);
    GenIndex();
}

void Cabin::CreateIndex_baseline()
{
    // position array
    rv_ = new PosWidth[value_num_];

    std::vector<std::pair<WordUnit, PosWidth> > tmp_data_pair_array(value_num_);
    for(size_t i = 0; i < value_num_; i++)
    {
        tmp_data_pair_array[i] = std::make_pair(column_->GetTuple(i), i);
    }
#ifdef CREATE_INFO
    PRINT_EXCECUTION_TIME("sort", std::sort(tmp_data_pair_array.begin(), tmp_data_pair_array.end(), [&](std::pair<WordUnit, PosWidth> &a, std::pair<WordUnit, PosWidth> &b)
    {return a.first < b.first;}););
#else
    std::sort(tmp_data_pair_array.begin(), tmp_data_pair_array.end(), [&](std::pair<WordUnit, PosWidth> &a, std::pair<WordUnit, PosWidth> &b)
    {return a.first < b.first;});
#endif
    for(size_t i = 0; i < value_num_; i++)
    {
        rv_[i] = tmp_data_pair_array[i].second;
    }
    std::vector<std::pair<WordUnit, PosWidth> >().swap(tmp_data_pair_array);    // free the memory of the vector

    // parameter configure
    if(manual_configure == false) {
#ifdef CREATE_INFO
        PRINT_EXCECUTION_TIME("design selection", ParameterDetermination_baseline(workload_feature_))
#else
        ParameterDetermination_baseline(workload_feature_);
#endif        
    } else {
        group_ = 6, code_num_ = 5, proportion_ = 1;
        volume_ = std::max((1 << code_num_) - 2, 1);
        partition_num_ = group_ * volume_;
        filter_v_num_ = group_ * code_num_;

        positionSegArray = new size_t[partition_num_];
        std::fill(positionSegArray, positionSegArray + partition_num_, 0);
        size_t stored_interval_num = partition_num_ * proportion_;

        // the flags should be random (for zipf test of cabin without selective position array)
        std::vector<int> deck(partition_num_);
        std::iota(deck.begin(), deck.end(), 0);
        std::shuffle(deck.begin(), deck.end(), std::default_random_engine(232));
        for(size_t index = 0; index < stored_interval_num; index++)
        {
            positionSegArray[deck[index]] = 1;
        }
    }
#ifdef CREATE_INFO
        std::cout << "group: " << group_ << std::endl;
        std::cout << "code num: " << code_num_ << std::endl;
        std::cout << "pro: " << proportion_ << std::endl;
#endif
    CodeGen(code_num_);

    // area map
    if(!skewed_interval_group_values_.empty() || !skewed_interval_values_.empty())
        GenAreaMapDataAware();
    else
        GenAreaMap();

    area_val_ = new WordUnit [partition_num_];
    area_pos_ = new PosWidth [partition_num_];
    area_len_ = new size_t [partition_num_];
    for(size_t i = 0; i < partition_num_; i++)
    {
        area_val_[i] = area_[i].val;
        area_pos_[i] = area_[i].pos;
        area_len_[i] = area_[i].len;
    }
#ifdef CREATE_INFO
    std::cout << "[INFO ] area_ done" << std::endl;
#endif

    //filter bit vector
    fv_ = static_cast<bitmap_t *>(os_aligned_alloc(filter_v_num_*aligned_slot, 32));
    memset(fv_, 0, filter_v_num_ * aligned_slot);

    if(!skewed_interval_group_values_.empty())
        GenIndexDataAware();
    else
        GenIndex();

#ifdef CREATE_INFO
    std::cout << "[INFO ] fv_ done" << std::endl;
#endif
}

void Cabin::CreateIndex()
{

    value_num_ = column_->GetNumTuples();
    bmn_ = CEILING(value_num_, BITMAPWIDTH);
    // SIMD needs the addresses are aligned to a 32-byte boundary
    aligned_slot = CEILING((sizeof(bitmap_t)*bmn_), 32) * 32;    //unit: byte
#ifdef CREATE_INFO
    std::cout << "bmn: " << bmn_ << std::endl;
    std::cout << "aligned_slot: " << aligned_slot << " byte" << std::endl;
#endif


#ifdef CREATEINDEX_BETA
    CreateIndex_sampling_beta();
#elif defined(CREATEINDEX_BASELINE)
    CreateIndex_baseline();
#endif
    // scratch vector
    sv_ = static_cast<bitmap_t *>(os_aligned_alloc(aligned_slot, 32));
    memset(sv_, 0, aligned_slot);
    sv1 = static_cast<bitmap_t *>(os_aligned_alloc(aligned_slot, 32));
    memset(sv1, 0, aligned_slot);
    sv2 = static_cast<bitmap_t *>(os_aligned_alloc(aligned_slot, 32));
    memset(sv2, 0, aligned_slot);

    simd = new SimdCompute();
}

void Cabin::GenAreaMap()
{
#ifdef CREATE_INFO
    std::cout << "equal partition" << std::endl;
#endif
    area_ = new m_area_t [partition_num_];

    size_t outer_arean = value_num_ / filter_v_num_;
    size_t num_inner = (partition_num_ / filter_v_num_)-1;
    size_t inner_arean = outer_arean / (partition_num_ / filter_v_num_);

    size_t index = 0;
    for(int i = 0; i < filter_v_num_-1; i++) {
        size_t p = i * outer_arean;
        area_[index].val = column_->GetTuple(rv_[p]);
        area_[index].pos = p;
        index++;
        for(int k = 0; k < num_inner; k++) {
            p += inner_arean;
            area_[index].val = column_->GetTuple(rv_[p]);
            area_[index].pos = p;
            index++;
        }
    }
    size_t p = (filter_v_num_-1) * outer_arean;
    area_[index].val = column_->GetTuple(rv_[p]);
    area_[index].pos = p;
    index++;
    size_t last_index = partition_num_ - index;
    size_t last_inner_arean = (value_num_ - p) / (last_index+1);
    for(int k = 0; k < last_index; k++) {
        p += last_inner_arean;
        area_[index].val = column_->GetTuple(rv_[p]);
        area_[index].pos = p;
        index++;
    }

    assert(index==partition_num_);

    for(int i = 0; i < partition_num_-1; i++) {
        area_[i].len = area_[i+1].pos - area_[i].pos;
    }
    area_[partition_num_-1].len = value_num_-area_[partition_num_-1].pos;
}

void Cabin::GenAreaMapDataAware()    // only for zipf and low ndv
{
#ifdef CREATE_INFO
    std::cout << "data-aware partition" << std::endl;
#endif
    area_ = new m_area_t [partition_num_];

    size_t rv_id = 0;
    size_t interval_id = 0;
    for(int idx = 0; idx < skewed_interval_group_values_.size(); idx++)
    {
        WordUnit cur_val = skewed_interval_group_values_[idx].first;
        size_t size = skewed_interval_group_values_[idx].second;
        rv_id += size;
        for(size_t i = 0; i < volume_; i++)
        {
            area_[interval_id].val = cur_val;
            area_[interval_id].pos = rv_id - size;
            area_[interval_id].len = size;
            interval_id++;
        }
    }

    for(int idx = 0; idx < skewed_interval_values_.size(); idx++)
    {
        WordUnit cur_val = skewed_interval_values_[idx].first;
        size_t size = skewed_interval_values_[idx].second;
        rv_id += size;
        area_[interval_id].val = cur_val;
        area_[interval_id].pos = rv_id - size;
        area_[interval_id].len = size;
        interval_id++;
    }

    assert(interval_id <= partition_num_);
    assert(rv_id <= value_num_);

    if(interval_id < partition_num_ && rv_id < value_num_) {
        size_t stride = (value_num_ - rv_id) / (partition_num_ - interval_id);
        while(interval_id < partition_num_)
        {
            WordUnit cur_val = column_->GetTuple(rv_[rv_id]);
            area_[interval_id].val = cur_val;
            area_[interval_id].pos = rv_id;
            area_[interval_id].len = (interval_id == partition_num_-1) ? value_num_-rv_id : stride;
            rv_id += stride;
            interval_id++;
        }
    } else if (interval_id < partition_num_ && rv_id == value_num_) {
        while(interval_id < partition_num_)
        {
            area_[interval_id].val = std::numeric_limits<WordUnit>::max();
            area_[interval_id].pos = value_num_;    // ? segment fault?
            area_[interval_id].len = 0;
            interval_id++;
        }
    }
    assert(interval_id == partition_num_);
}

void Cabin::CodeGen(size_t depth) {
    int size = pow(2, depth);
    code_list_.resize(size);
    for(int i = 0; i < size; i++)
    {
        code_list_[i] = size - 1 - i;
    }
}

void Cabin::GenIndex()
{
    //PRINT_EXCECUTION_TIME("Generate index from base data", GenIndexFromBaseData());
    GenIndexFromBaseData();
}

void Cabin::GenIndexDataAware()
{
    //PRINT_EXCECUTION_TIME("Generate index from position array by group", GenIndexFromPositionArrayByGroup());
    GenIndexFromPositionArrayByGroup();
}

void Cabin::GenIndexFromPositionArrayByGroup()
{
    for(size_t groupId = 0; groupId < group_; groupId++)
    {
        if(positionSegArray[groupId * volume_] == 3)
            GenBitmapIndex(groupId);
        else
            GenIndexFromPositionArrayBySingleGroup(groupId);
    }
}

void Cabin::GenBitmapIndex(size_t groupId)
{
    bitmap_t* filterSketch = (bitmap_t *)((char *)fv_ + aligned_slot*(groupId * code_num_));    // only set the first bit vector
    for(size_t i = 0; i < value_num_; i++) {
        size_t index = BinarySearchLastOne<WordUnit>(area_val_, partition_num_, column_->GetTuple(i));
        size_t t_area_group = index / volume_;

        size_t pos = i;
        filterSketch[pos / BITMAPWIDTH] |= ((bitmap_t)(groupId >= t_area_group)) << (pos % BITMAPWIDTH);
    }
}

void Cabin::GenIndexFromPositionArrayBySingleGroup(size_t groupId)
{
    for (int areaIndex = 0; areaIndex < partition_num_; areaIndex++) {
        size_t first = area_[areaIndex].pos;
        size_t last = first + area_[areaIndex].len;

        size_t t_area_group = areaIndex / volume_;
        size_t t_area_indexInGroup = areaIndex % volume_;
        size_t code = CodeGet(t_area_indexInGroup+1);

        if(groupId < t_area_group) { // case 1:  groupId < t_area_group (0 0 0 ...)
            
        } else if(groupId == t_area_group) { // case 2:  groupId = t_area_group
            for(size_t FsId = 0; FsId < code_num_; FsId++) {
                bitmap_t* filterSketch = (bitmap_t *)((char *)fv_ + aligned_slot*(groupId * code_num_ + FsId));
                for(size_t arrayId = first; arrayId < last; arrayId++) {
                    size_t pos = rv_[arrayId];
                    filterSketch[pos / BITMAPWIDTH] ^= ((unsigned long long)((code & (1 << FsId)) != 0)) << (pos % BITMAPWIDTH);
                }
            }
        } else {  // case 3:  groupId > t_area_group (1 1 1 ...) 
            for(size_t FsId = 0; FsId < code_num_; FsId++) {
                bitmap_t* filterSketch = (bitmap_t *)((char *)fv_ + aligned_slot*(groupId * code_num_ + FsId));
                for(size_t arrayId = first; arrayId < last; arrayId++) {
                    size_t pos = rv_[arrayId];
                    filterSketch[pos / BITMAPWIDTH] |= 1ULL << (pos % BITMAPWIDTH);
                }
            }
        }
    }
}

template<typename T>
size_t Cabin::BinarySearchLastOne(T* arr, size_t arr_size, T val)
{
    size_t first = 0;
    size_t last = arr_size;
    size_t mid;
    while (last > first) {
        mid = first + (last - first) / 2;
        if (arr[mid] <= val)
            first = mid + 1;
        else
            last = mid;
    }
    // the last matched value's position. for example, found 4 in 1,4,4,4, the answer is 3.
    // when index == 0, it means that incmp is <= area_[0].val
    return (first == 0) ? 0 : (first - 1);
}

void Cabin::GenIndexFromBaseData()
{
    bitmap_t tmpbm[filter_v_num_];

    for(size_t i = 0; i < value_num_; i++)
    {
#if defined(CREATEINDEX_BETA)
        size_t index = area_id_array_[i];
#else
        size_t index = BinarySearchLastOne<WordUnit>(area_val_, partition_num_, column_->GetTuple(i));
#endif
        size_t t_area_group = index / volume_;
        size_t t_area_indexInGroup = index % volume_;

        size_t code = CodeGet(t_area_indexInGroup+1);

        size_t pos = i;
        // case 1:  groupId < t_area_group (0 0 0 ...)
        // case 2:  groupId = t_area_group
        for(size_t FsId = 0; FsId < code_num_; FsId++) {
            ((bitmap_t *)((char *)fv_ + aligned_slot*(t_area_group * code_num_ + FsId)))[pos / BITMAPWIDTH] |= ((unsigned long long)((code & (1 << FsId)) != 0)) << (pos % BITMAPWIDTH);
        }
        // case 3:  groupId > t_area_group (1 1 1 ...)
        for(int groupId = t_area_group+1; groupId < group_; groupId++)
        {
            for(size_t FsId = 0; FsId < code_num_; FsId++) {
                ((bitmap_t *)((char *)fv_ + aligned_slot*(groupId * code_num_ + FsId)))[pos / BITMAPWIDTH] |= 1ULL << (pos % BITMAPWIDTH);
            }
        }
    }

    GenIndexFromBaseDataFixing();
}

void Cabin::GenIndexFromBaseDataFixing()
{
    // fixing
    size_t rv_pos = 0;
    for(size_t area_group_id = 0; area_group_id < group_; area_group_id++)
    {
        for(size_t area_ingroup_id = 0; area_ingroup_id < volume_; area_ingroup_id++)
        {
            size_t area_id = area_group_id*volume_+area_ingroup_id;
            if(area_id == 0) continue;
            if(positionSegArray[area_id-1] != 1) continue;

            rv_pos += area_[area_id-1].len;
            if(rv_pos >= value_num_) break;

            WordUnit pivot = column_->GetTuple(rv_[rv_pos]);
            for(size_t forward = 1; forward <= area_[area_id-1].len; forward++) {
                size_t forward_id = rv_pos - forward;
                if(column_->GetTuple(rv_[forward_id]) != pivot)
                    break;
                else {
                    size_t column_pos = rv_[forward_id];
                    //std::cout << "fix: " << column_pos << std::endl;
                    size_t t_area_group = (area_ingroup_id == 0) ? area_group_id-1 : area_group_id;
                    size_t t_area_indexInGroup = (area_ingroup_id == 0) ? volume_-1 : area_ingroup_id-1;
                    size_t code = CodeGet(t_area_indexInGroup+1);

                    for(int g = 0; g < group_; g++)
                    {
                        if( g < t_area_group ) {   // 0 0 0
                            for(size_t idx = 0; idx < code_num_; idx++) {
                                ((bitmap_t *)((char *)fv_ + aligned_slot*(g*code_num_ + idx)))[column_pos / BITMAPWIDTH] &= ~(1ULL << (column_pos % BITMAPWIDTH));
                            }
                        } else if( g == t_area_group ) {
                            for(size_t idx = 0; idx < code_num_; idx++) {
                                if(code & (1 << idx)) {    // 1
                                    ((bitmap_t *)((char *)fv_ + aligned_slot*(g*code_num_ + idx)))[column_pos / BITMAPWIDTH] |= 1ULL << (column_pos % BITMAPWIDTH);
                                }
                                else {  // 0
                                    ((bitmap_t *)((char *)fv_ + aligned_slot*(g*code_num_ + idx)))[column_pos / BITMAPWIDTH] &= ~(1ULL << (column_pos % BITMAPWIDTH));
                                }
                            }
                        } else {    // 1 1 1
                            for(size_t idx = 0; idx < code_num_; idx++) {
                                ((bitmap_t *)((char *)fv_ + aligned_slot*(g*code_num_ + idx)))[column_pos / BITMAPWIDTH] |= 1ULL << (column_pos % BITMAPWIDTH);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Cabin:: CabinRefineSV(void *sv_arg, PosWidth *rv_arg, size_t start, size_t end)
{
    auto *sv_act = (bitmap_t *)sv_arg;
    PosWidth *cur = rv_arg + start;
    size_t stride = 33;

    //after test in the server machine (the tuple number is 10^9), when the stride >= 33 (locality = 0) the spending time converge at the minimum
    //pipeline prepare
    size_t i = 0;
    while ( i <  stride) {
        PosWidth prefetch_pos = *(cur + i);
        __builtin_prefetch (&sv_act[prefetch_pos / BITMAPWIDTH], 0, 0);
        i++;
    }
    while (cur < rv_arg + end - stride) {
        PosWidth pos = *cur++;
        PosWidth prefetch_pos = *(cur + stride);
        __builtin_prefetch (&sv_act[prefetch_pos / BITMAPWIDTH], 0, 0);
        sv_act[pos / BITMAPWIDTH] ^= 1ULL << (pos % BITMAPWIDTH);
    }
    while (cur < rv_arg + end) {
        PosWidth pos = *cur++;
        sv_act[pos / BITMAPWIDTH] ^= 1ULL << (pos % BITMAPWIDTH);
    }
}

void Cabin::Scan(WordUnit x_h, WordUnit x_l, op_class op)
{
    ScanPlan(x_h, x_l, op);
}

void Cabin::ScanPlan(WordUnit x_h, WordUnit x_l, op_class op)
{
    switch (op) {
        case (op_le):
        case (op_ge): {
            size_t area_id;
            PosWidth positionArrayPos;

            WordUnit operand = (op == op_le) ? x_h : x_l;
            AreaID(operand, area_id, op);

            if (positionSegArray[area_id] == 0) {
                query_wo_pa_num++;
                CabinGenFV_cs(area_id, op == op_ge, sv_, x_h, x_l);
            } else if (positionSegArray[area_id] == 3) {
                size_t t_group = area_id / volume_;
                CopyFv(t_group, op == op_ge, sv_);
            } else if (positionSegArray[area_id] == 2) {
                bool WaxWane = true;
                CabinGenFV(area_id, op == op_ge, WaxWane, sv_);
            } else {
                query_w_pa_num++;
                OperandLocInSortedPosArray(operand, area_id, op, positionArrayPos);

                // shortcut
                size_t threshold = value_num_*0.005;    // 0.005 is a heuristic factor
                if(positionArrayPos - 0 <= threshold) {
                    bool continuous_flag = true;
                    for(size_t id = 0; id < area_id; id++) {
                        if(positionSegArray[id] == 0) {
                            continuous_flag = false;
                            break;
                        }
                    }
                    if(continuous_flag) {
                        shortcut_num++;
                        if(op == op_le)
                            memset(sv_, 0, aligned_slot);
                        else
                            memset(sv_, 0xFF, aligned_slot);
                        sv_[bmn_ - 1] &= ~0ULL >> (bmn_ * BITMAPWIDTH - value_num_);
                        CabinRefineSV(sv_, rv_, 0, positionArrayPos);
                        refine_num += positionArrayPos;
                        return;
                    }
                } else if (area_[partition_num_-1].pos + area_[partition_num_-1].len - positionArrayPos <= threshold ) {
                    bool continuous_flag = true;
                    for(size_t id = area_id+1; id < partition_num_; id++) {
                        if(positionSegArray[id] == 0) {
                            continuous_flag = false;
                            break;
                        }
                    }
                    if(continuous_flag) {
                        shortcut_num++;
                        if(op == op_ge)
                            memset(sv_, 0, aligned_slot);
                        else
                            memset(sv_, 0xFF, aligned_slot);
                        sv_[bmn_ - 1] &= ~0ULL >> (bmn_ * BITMAPWIDTH - value_num_);
                        CabinRefineSV(sv_, rv_, positionArrayPos, area_[partition_num_-1].pos + area_[partition_num_-1].len);
                        refine_num += area_[partition_num_-1].pos + area_[partition_num_-1].len - positionArrayPos;
                        return;
                    }
                }

                bool WaxWane;
                size_t start, end;

                UpperOrLowerBound(WaxWane, start, end, area_id, positionArrayPos);

                CabinGenFV(area_id, op == op_ge, WaxWane, sv_);
                CabinRefineSV(sv_, rv_, start, end);
                refine_num += end-start;
            }
        }
            break;
        case (op_ab):
        case (op_bt):
        {
            size_t area_id_l;
            size_t area_id_h;
            PosWidth positionArrayPos_l;
            PosWidth positionArrayPos_h;

            op_class op_l = (op == op_ab) ? op_le : op_ge;
            op_class op_h = (op == op_bt) ? op_le : op_ge;
            AreaID(x_l, area_id_l, op_l);
            AreaID(x_h, area_id_h, op_h);

            // the first three cases only support op_bt right now
            if(positionSegArray[area_id_l] == 0 && positionSegArray[area_id_h] == 0) {
                //std::cout << "type 1" << std::endl;
                query_wo_pa_num += 2;
                CabinGenFV_cs_BETWEEN(area_id_h, area_id_l, sv_, x_h, x_l);
            } else if (positionSegArray[area_id_l] == 0 && positionSegArray[area_id_h] == 1) {
                query_wo_pa_num += 1;
                query_w_pa_num += 1;
                //std::cout << "type 2" << std::endl;

                OperandLocInSortedPosArray(x_h, area_id_h, op_le, positionArrayPos_h);
                bool WaxWane;
                size_t start, end;
                UpperOrLowerBound(WaxWane, start, end, area_id_h, positionArrayPos_h);
                CabinGenFV_mix_BETWEEN(area_id_h, area_id_l, sv_, x_h, x_l, WaxWane, true);
                CabinRefineSV(sv_, rv_, start, end);
            } else if (positionSegArray[area_id_h] == 0 && positionSegArray[area_id_l] == 1) {
                query_wo_pa_num += 1;
                query_w_pa_num += 1;
                //std::cout << "type 3" << std::endl;

                OperandLocInSortedPosArray(x_l, area_id_l, op_ge, positionArrayPos_l);
                bool WaxWane;
                size_t start, end;
                UpperOrLowerBound(WaxWane, start, end, area_id_l, positionArrayPos_l);
                CabinGenFV_mix_BETWEEN(area_id_h, area_id_l, sv_, x_h, x_l, WaxWane, false);
                CabinRefineSV(sv_, rv_, start, end);
            } else {
                //std::cout << "type 4" << std::endl;
                query_w_pa_num += 2;
                OperandLocInSortedPosArray(x_l, area_id_l, op_l, positionArrayPos_l);
                OperandLocInSortedPosArray(x_h, area_id_h, op_h, positionArrayPos_h);

                // shortcut 1
                size_t threshold = value_num_*0.005;    // 0.005 is a heuristic factor
                if(positionArrayPos_h - positionArrayPos_l <= threshold) {
                    shortcut_num++;
                    if(op == op_bt)
                        memset(sv_, 0, aligned_slot);
                    else
                        memset(sv_, 0xFF, aligned_slot);
                    sv_[bmn_ - 1] &= ~0ULL >> (bmn_ * BITMAPWIDTH - value_num_);
                    CabinRefineSV(sv_, rv_, positionArrayPos_l, positionArrayPos_h);
                    return;
                }

                bool WaxWane_l;
                bool WaxWane_h;
                size_t start_l, end_l;
                size_t start_h, end_h;

                UpperOrLowerBound(WaxWane_l, start_l, end_l, area_id_l, positionArrayPos_l);
                UpperOrLowerBound(WaxWane_h, start_h, end_h, area_id_h, positionArrayPos_h);

                Cabinmerge(area_id_l, area_id_h, WaxWane_l, WaxWane_h, op==op_bt, sv_);
                CabinRefineSV(sv_, rv_, start_l, end_l);
                CabinRefineSV(sv_, rv_, start_h, end_h);
            }
        }
            break;
        default:
            break;
    }
}

void Cabin::CopyFv(int groupId, bool anti, bitmap_t* sv)
{
    bitmap_t *result = sv;
    //bitmap_t *fv = fv_ + fvi * bmn_;

    assert(groupId >= -1);
    assert(groupId < (int)group_);

    if ((groupId == -1 && !anti) || (groupId == group_ - 1 && anti)) {
        memset(result, 0, bmn_ * sizeof(bitmap_t));
    } else if ((groupId == -1 && anti) || (groupId == group_ - 1 && !anti)) {
        memset(result, 0xff, bmn_ * sizeof(bitmap_t));
    } else {
        //auto *fv = (bitmap_t*)((char *)fv_ + fvi * aligned_slot_);
        bitmap_t *fv = (bitmap_t*)((char *)fv_ + groupId * code_num_ * aligned_slot);
        for (size_t i = 0; i < bmn_; i++)
            result[i] = anti ? (~fv[i]) : fv[i];
    }
    result[bmn_ - 1] &= ~0ULL >> (bmn_ * BITMAPWIDTH - value_num_);
}

/*
 * If anti is set, copy the bitwise-not fv.
 * If andop is set, merge with bitwise-and, otherwise merge with bitwise-or
 */
void Cabin::Cabinmerge(size_t aid1, size_t aid2, bool ww1, bool ww2, bool anti, bitmap_t* sv)
{
    CabinGenFV_BETWEEN(aid1, aid2, ww1, ww2, anti, sv);
}

void Cabin::CabinGenFV_BETWEEN(size_t area_id_l, size_t area_id_h, bool WaxWane_l, bool WaxWane_h, bool anti, bitmap_t* sv)
{
    size_t t_group_l = area_id_l / volume_;
    size_t t_indexInGroup_l = area_id_l % volume_;

    size_t index_l;
    if(WaxWane_l == 0)
        index_l = t_indexInGroup_l;
    else
        index_l = t_indexInGroup_l + 1;

    size_t t_group_h = area_id_h / volume_;
    size_t t_indexInGroup_h = area_id_h % volume_;

    size_t index_h;
    if(WaxWane_h == 0)
        index_h = t_indexInGroup_h;
    else
        index_h = t_indexInGroup_h + 1;

    switch (code_num_) {
        case 5:
        {
            __m256i code_array[5];
            bitmap_t bitmap_array[5];
            GenTempResult_between_general(t_group_l, index_l, t_group_h, index_h, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN5[index_h], simd->SIMD256_COMPUTEa_CN5[index_l], \
                                simd->SIMD256_COMPUTE_CN5[index_l], simd->SIMD256_COMPUTEa_CN5[index_h], \
                                bitmap_array, simd->BITMAP_COMPUTE_CN5[index_h], simd->BITMAP_COMPUTEa_CN5[index_l], \
                                simd->BITMAP_COMPUTE_CN5[index_l], simd->BITMAP_COMPUTEa_CN5[index_h]);
            break;
        }
        case 6:
        {
            __m256i code_array[6];
            bitmap_t bitmap_array[6];
            GenTempResult_between_general(t_group_l, index_l, t_group_h, index_h, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN6[index_h], simd->SIMD256_COMPUTEa_CN6[index_l], \
                                simd->SIMD256_COMPUTE_CN6[index_l], simd->SIMD256_COMPUTEa_CN6[index_h], \
                                bitmap_array, simd->BITMAP_COMPUTE_CN6[index_h], simd->BITMAP_COMPUTEa_CN6[index_l], \
                                simd->BITMAP_COMPUTE_CN6[index_l], simd->BITMAP_COMPUTEa_CN6[index_h]);
            break;
        }
        default: {
            std::cout << "the code num haven't been supported" << std::endl;
            exit(EXIT_FAILURE);
        }
            break;
    }
}

void Cabin::CabinGenFV(size_t area_id, bool anti, bool WaxWane, bitmap_t* sv)
{
    size_t t_group = area_id / volume_;
    size_t t_indexInGroup = area_id % volume_;

    //simple optimization tactics, only considering the least random access

    size_t index;   // the index in code group; 00,01,10,11,...
    if(WaxWane == 0)
        index = t_indexInGroup;
    else
        index = t_indexInGroup + 1;

    switch (code_num_) {
        case 2:
            GenTempResult_2(t_group, index, anti, sv);
            break;
        case 3:
        {
            __m256i code_array[3];
            bitmap_t bitmap_array[3];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN3[index], simd->SIMD256_COMPUTEa_CN3[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN3[index], simd->BITMAP_COMPUTEa_CN3[index]);
            break;
        }
        case 4:
        {
            __m256i code_array[4];
            bitmap_t bitmap_array[4];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN4[index], simd->SIMD256_COMPUTEa_CN4[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN4[index], simd->BITMAP_COMPUTEa_CN4[index]);
            break;
        }
        case 5:
        {
            __m256i code_array[5];
            bitmap_t bitmap_array[5];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN5[index], simd->SIMD256_COMPUTEa_CN5[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN5[index], simd->BITMAP_COMPUTEa_CN5[index]);
            break;
        }
        case 6:
        {
            __m256i code_array[6];
            bitmap_t bitmap_array[6];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN6[index], simd->SIMD256_COMPUTEa_CN6[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN6[index], simd->BITMAP_COMPUTEa_CN6[index]);
            break;
        }
        case 7:
        {
            __m256i code_array[7];
            bitmap_t bitmap_array[7];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN7[index], simd->SIMD256_COMPUTEa_CN7[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN7[index], simd->BITMAP_COMPUTEa_CN7[index]);
            break;
        }
        case 8:
        {
            __m256i code_array[8];
            bitmap_t bitmap_array[8];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN8[index], simd->SIMD256_COMPUTEa_CN8[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN8[index], simd->BITMAP_COMPUTEa_CN8[index]);
            break;
        }
        case 9:
        {
            __m256i code_array[9];
            bitmap_t bitmap_array[9];
            GenTempResult_general(t_group, index, anti, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN9[index], simd->SIMD256_COMPUTEa_CN9[index],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN9[index], simd->BITMAP_COMPUTEa_CN9[index]);
            break;
        }
        default: {
            std::cout << "the code num haven't been supported" << std::endl;
            exit(EXIT_FAILURE);
        }
            break;
    }
}

void Cabin::CabinGenFV_cs(size_t area_id, bool anti, bitmap_t* sv, WordUnit x_h, WordUnit x_l) {
    size_t t_group = area_id / volume_;
    size_t t_indexInGroup = area_id % volume_;

    switch (code_num_) {
        case 2:
            GenTempResult_2_cs_le(t_group, t_indexInGroup, anti, x_h, sv);
            break;
        case 3:
        {
            __m256i code_array[3];
            bitmap_t bitmap_array[3];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN3[t_indexInGroup], simd->SIMD256_COMPUTEa_CN3[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN3[t_indexInGroup], simd->BITMAP_COMPUTEa_CN3[t_indexInGroup]);
            break;
        }
        case 4:
        {
            __m256i code_array[4];
            bitmap_t bitmap_array[4];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN4[t_indexInGroup], simd->SIMD256_COMPUTEa_CN4[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN4[t_indexInGroup], simd->BITMAP_COMPUTEa_CN4[t_indexInGroup]);
            break;
        }
        case 5:
        {
            __m256i code_array[5];
            bitmap_t bitmap_array[5];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN5[t_indexInGroup], simd->SIMD256_COMPUTEa_CN5[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN5[t_indexInGroup], simd->BITMAP_COMPUTEa_CN5[t_indexInGroup]);
            break;
        }
        case 6:
        {
            __m256i code_array[6];
            bitmap_t bitmap_array[6];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN6[t_indexInGroup], simd->SIMD256_COMPUTEa_CN6[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN6[t_indexInGroup], simd->BITMAP_COMPUTEa_CN6[t_indexInGroup]);
            break;
        }
        case 7:
        {
            __m256i code_array[7];
            bitmap_t bitmap_array[7];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN7[t_indexInGroup], simd->SIMD256_COMPUTEa_CN7[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN7[t_indexInGroup], simd->BITMAP_COMPUTEa_CN7[t_indexInGroup]);
            break;
        }
        case 8:
        {
            __m256i code_array[8];
            bitmap_t bitmap_array[8];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN8[t_indexInGroup], simd->SIMD256_COMPUTEa_CN8[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN8[t_indexInGroup], simd->BITMAP_COMPUTEa_CN8[t_indexInGroup]);
            break;
        }
        case 9:
        {
            __m256i code_array[9];
            bitmap_t bitmap_array[9];
            GenTempResult_cs_general(t_group, t_indexInGroup, anti, x_h, x_l, sv, \
                                code_array, simd->SIMD256_COMPUTE_CN9[t_indexInGroup], simd->SIMD256_COMPUTEa_CN9[t_indexInGroup],\
                                bitmap_array, simd->BITMAP_COMPUTE_CN9[t_indexInGroup], simd->BITMAP_COMPUTEa_CN9[t_indexInGroup]);
            break;
        }
        default: {
            std::cout << "the code num haven't been supported" << std::endl;
            exit(EXIT_FAILURE);
        }
            break;
    }
}

void Cabin::CabinGenFV_cs_BETWEEN(size_t area_id_h, size_t area_id_l, bitmap_t* sv, WordUnit x_h, WordUnit x_l) {
    size_t group_l = area_id_l / volume_;
    size_t indexInGroup_l = area_id_l % volume_;
    size_t group_h = area_id_h / volume_;
    size_t indexInGroup_h = area_id_h % volume_;

    switch (code_num_) {
        case 3:
        {
            __m256i code_array[3];
            bitmap_t bitmap_array[3];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN3[indexInGroup_h], simd->SIMD256_COMPUTEa_CN3[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN3[indexInGroup_h], simd->BITMAP_COMPUTEa_CN3[indexInGroup_l+1]);
            break;
        }
        case 4:
        {
            __m256i code_array[4];
            bitmap_t bitmap_array[4];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN4[indexInGroup_h], simd->SIMD256_COMPUTEa_CN4[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN4[indexInGroup_h], simd->BITMAP_COMPUTEa_CN4[indexInGroup_l+1]);
            break;
        }
        case 5:
        {
            __m256i code_array[5];
            bitmap_t bitmap_array[5];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN5[indexInGroup_h], simd->SIMD256_COMPUTEa_CN5[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN5[indexInGroup_h], simd->BITMAP_COMPUTEa_CN5[indexInGroup_l+1]);
            break;
        }
        case 6:
        {
            __m256i code_array[6];
            bitmap_t bitmap_array[6];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN6[indexInGroup_h], simd->SIMD256_COMPUTEa_CN6[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN6[indexInGroup_h], simd->BITMAP_COMPUTEa_CN6[indexInGroup_l+1]);
            break;
        }
        case 7:
        {
            __m256i code_array[7];
            bitmap_t bitmap_array[7];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN7[indexInGroup_h], simd->SIMD256_COMPUTEa_CN7[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN7[indexInGroup_h], simd->BITMAP_COMPUTEa_CN7[indexInGroup_l+1]);
            break;
        }
        case 8:
        {
            __m256i code_array[8];
            bitmap_t bitmap_array[8];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN8[indexInGroup_h], simd->SIMD256_COMPUTEa_CN8[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN8[indexInGroup_h], simd->BITMAP_COMPUTEa_CN8[indexInGroup_l+1]);
            break;
        }
        case 9:
        {
            __m256i code_array[9];
            bitmap_t bitmap_array[9];
            GenTempResult_cs_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv,\
                                            code_array, simd->SIMD256_COMPUTE_CN9[indexInGroup_h], simd->SIMD256_COMPUTEa_CN9[indexInGroup_l+1],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN9[indexInGroup_h], simd->BITMAP_COMPUTEa_CN9[indexInGroup_l+1]);
            break;
        }
        default: {
            std::cout << "the code num haven't been supported" << std::endl;
            exit(EXIT_FAILURE);
        }
            break;
    }
}

void Cabin::CabinGenFV_mix_BETWEEN(size_t area_id_h, size_t area_id_l, bitmap_t* sv, WordUnit x_h, WordUnit x_l, bool WaxWane, bool w_wo) {
    // w_wo == true: x_h with selective position array; x_l without selective position array
    // w_wo == false: x_h without selective position array; x_l with selective position array
    size_t group_l = area_id_l / volume_;
    size_t indexInGroup_l = area_id_l % volume_;
    size_t group_h = area_id_h / volume_;
    size_t indexInGroup_h = area_id_h % volume_;

    size_t func_index_h, func_index_l;
    if(w_wo && WaxWane) {
        func_index_h = indexInGroup_h + 1;
        func_index_l = indexInGroup_l + 1;
    } else if (w_wo && !WaxWane) {
        func_index_h = indexInGroup_h;
        func_index_l = indexInGroup_l + 1;
    } else if (!w_wo && WaxWane) {
        func_index_h = indexInGroup_h;
        func_index_l = indexInGroup_l + 1;
    } else {
        func_index_h = indexInGroup_h;
        func_index_l = indexInGroup_l;
    }

    switch (code_num_) {
        case 8:
        {
            __m256i code_array[8];
            bitmap_t bitmap_array[8];
            GenTempResult_mix_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv, WaxWane, w_wo,\
                                            code_array, simd->SIMD256_COMPUTE_CN8[func_index_h], simd->SIMD256_COMPUTEa_CN8[func_index_l],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN8[func_index_h], simd->BITMAP_COMPUTEa_CN8[func_index_l]);
            break;
        }
        case 9:
        {
            __m256i code_array[9];
            bitmap_t bitmap_array[9];
            GenTempResult_mix_between_general(area_id_h, area_id_l, group_h, group_l, indexInGroup_h, indexInGroup_l, x_h, x_l, sv, WaxWane, w_wo,\
                                            code_array, simd->SIMD256_COMPUTE_CN9[func_index_h], simd->SIMD256_COMPUTEa_CN9[func_index_l],\
                                            bitmap_array, simd->BITMAP_COMPUTE_CN9[func_index_h], simd->BITMAP_COMPUTEa_CN9[func_index_l]);
            break;
        }
        default: {
            std::cout << "the code num haven't been supported" << std::endl;
            exit(EXIT_FAILURE);
        }
            break;
    }
}

size_t Cabin::LoadNum(size_t depth, size_t x) {
    if(depth == 1) {
        return 1;
    }

    if (x == (1 << (depth-1))-1) {
        return 1;
    } else if (x < (1 << (depth-1))-1) {
        return 1 + LoadNum(depth-1, x % (1 << (depth-1)));
    } else {
        return 1 + LoadNum(depth-1, x % (1 << (depth-1)));
    }
}

void Cabin::GenTempResult_general(size_t group, size_t index, bool anti, bitmap_t* sv, \
                                __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address))
{
    bitmap_t result_tmp;

    std::vector<size_t> base(code_num_);
    std::vector<bitmap_t*> address(code_num_);
    for(size_t i = 0; i < code_num_; i++) {
        base[i] = (group*code_num_+i)*aligned_slot;
        address[i] = (bitmap_t*)((char *)fv_ + base[i]);
    }

    // data slice
    size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4

    //size_t remainder = bmn_ - SIMDUnitNum*4;
    size_t unit;
    size_t remainBitMapBeginId = SIMDUnitNum * 4;

    bitmap_t tmpBitMap0,tmpBitMap1,tmpBitMap2,tmpBitMap3,tmpBitMap;

    // If changing the code num, change the below 4
    // bitmap_t bm[4];
    // __m256i codes[4];

    size_t computeNum = LoadNum(code_num_, index);


    if(anti == 0)   // <=
    {
        for (unit = 0; unit < SIMDUnitNum; unit++) {
            for(size_t i = code_num_ - computeNum; i < code_num_; i++) {
                code_array[i] = _mm256_load_si256((__m256i const *) (address[i] + (unit<<2)));
            }
            // change x
            (simd->*(simd_compute_le))(code_array);

            _mm256_store_si256((__m256i *) (sv + (unit<<2)), simd->tmp);
        }

        // handle the remainder
        for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
            for(size_t i = code_num_ - computeNum; i < code_num_; i++) {
                bitmap_array[i] = address[i][remain];
            }
            // change x
            (simd->*(bitmap_compute_le))(bitmap_array);
            tmpBitMap = simd->tmp_bm;
            tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

            sv[remain] = tmpBitMap;
        }
    } else {    // >=
        for (unit = 0; unit < SIMDUnitNum; unit++) {
            for(size_t i = code_num_ - computeNum; i < code_num_; i++) {
                code_array[i] = _mm256_load_si256((__m256i const *) (address[i] + (unit<<2)));
            }

            // change x
            (simd->*(simd_compute_ge))(code_array);

            _mm256_store_si256((__m256i *) (sv + (unit<<2)), simd->tmp);
        }

        // handle the remainder
        for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
            for(size_t i = code_num_ - computeNum; i < code_num_; i++) {
                bitmap_array[i] = address[i][remain];
            }
            // change x
            (simd->*(bitmap_compute_ge))(bitmap_array);
            tmpBitMap = simd->tmp_bm;
            tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

            sv[remain] = tmpBitMap;
        }
    }

}

void Cabin::GenTempResult_2(size_t group, size_t index, bool anti, bitmap_t* sv)
{
    bitmap_t result_tmp;
    size_t base1 = group*code_num_*aligned_slot;
    size_t base2 = (group*code_num_+1)*aligned_slot;
    bitmap_t* address1 = (bitmap_t*)((char *)fv_ + base1);
    bitmap_t* address2 = (bitmap_t*)((char *)fv_ + base2);
    __m256i codes[2];
    __m256i tmp;
    __m256i c = _mm256_set1_epi32(-1);

    // data slice
    size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4

    //size_t remainder = bmn_ - SIMDUnitNum*4;
    size_t unit;
    size_t remainBitMapBeginId = SIMDUnitNum * 4;

    bitmap_t tmpBitMap1,tmpBitMap2,tmpBitMap3;
    //std::cout << "index: " << index << std::endl;

    if(value_num_ >= 256) {
        switch (index) {
            case 0: // each code matching 00 will give 1 result
            {
                for (unit = 0; unit < SIMDUnitNum; unit++) {
                    codes[0] = _mm256_load_si256((__m256i const *) (address1 + (unit<<2))); // 256/64 ==> 4 ==> 2^2
                    codes[1] = _mm256_load_si256((__m256i const *) (address2 + (unit<<2)));
                    // or
                    tmp = _mm256_or_si256(codes[0], codes[1]);

                    // not
                    tmp = _mm256_xor_si256(c, tmp);
                    _mm256_store_si256((__m256i *) (sv_ + (unit<<2)), tmp);
                }

                // handle the remainder
                for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                    tmpBitMap1 = address1[remain];
                    tmpBitMap2 = address2[remain];
                    tmpBitMap3 = ~(tmpBitMap1 | tmpBitMap2);
                    tmpBitMap3 &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                    sv_[remain] = tmpBitMap3;
                }
            }
                break;
            case 1: // each code matching 00&01 will give 1 result
            {
                for (unit = 0; unit < SIMDUnitNum; unit++) {
                    codes[1] = _mm256_load_si256((__m256i const *) (address2 + (unit<<2)));
                    // not
                    tmp = _mm256_xor_si256(c, codes[1]);
                    _mm256_store_si256((__m256i *) (sv_ + (unit<<2)), tmp);
                }

                // handle the remainder
                for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                    tmpBitMap2 = address2[remain];
                    tmpBitMap3 = ~tmpBitMap2;
                    tmpBitMap3 &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                    sv_[remain] = tmpBitMap3;
                }
            }
                break;
            case 2: // each code matching 00&01&11 will give 1 result
            {
                for (unit = 0; unit < SIMDUnitNum; unit++) {
                    codes[0] = _mm256_load_si256((__m256i const *) (address1 + (unit<<2)));
                    codes[1] = _mm256_load_si256((__m256i const *) (address2 + (unit<<2)));
                    // and
                    tmp = _mm256_andnot_si256(codes[0], codes[1]);

                    // not
                    tmp = _mm256_xor_si256(c, tmp);
                    _mm256_store_si256((__m256i *) (sv_ + (unit<<2)), tmp);
                }

                // handle the remainder
                for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                    tmpBitMap1 = address1[remain];
                    tmpBitMap2 = address2[remain];
                    tmpBitMap3 = ~(~tmpBitMap1 & tmpBitMap2);
                    tmpBitMap3 &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                    sv_[remain] = tmpBitMap3;
                }
            }
                break;
            default:
                break;
        }
    }
}

void Cabin::GenTempResult_between_general(size_t group_l, size_t index_l, size_t group_h, size_t index_h, bool anti, bitmap_t* sv, \
                                __m256i* code_array, void (SimdCompute::*simd_compute_bt_le)(__m256i* codes), void (SimdCompute::*simd_compute_bt_ge)(__m256i* codes), \
                                void (SimdCompute::*simd_compute_ab_le)(__m256i* codes), void (SimdCompute::*simd_compute_ab_ge)(__m256i* codes), \
                                bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_bt_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_bt_ge)(bitmap_t* address),\
                                void (SimdCompute::*bitmap_compute_ab_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ab_ge)(bitmap_t* address))
{
    if(group_l*volume_+index_l == group_h*volume_+index_h) {
        //compute_time++;
        if(anti == 0)   // op_ab
        {
            memset(sv, 0xFF, aligned_slot);
            sv[bmn_ - 1] &= ~0ULL >> (bmn_ * BITMAPWIDTH - value_num_);
        } else {    // op_bt
            memset(sv, 0, aligned_slot);
            sv[bmn_ - 1] &= ~0ULL >> (bmn_ * BITMAPWIDTH - value_num_);
        }
    } else {
        //refine_time++;
        bitmap_t result_tmp;

        std::vector<size_t> base_l(code_num_);
        std::vector<bitmap_t*> address_l(code_num_);
        for(size_t i = 0; i < code_num_; i++) {
            base_l[i] = (group_l*code_num_+i)*aligned_slot;
            address_l[i] = (bitmap_t*)((char *)fv_ + base_l[i]);
        }
        std::vector<size_t> base_h(code_num_);
        std::vector<bitmap_t*> address_h(code_num_);
        for(size_t i = 0; i < code_num_; i++) {
            base_h[i] = (group_h*code_num_+i)*aligned_slot;
            address_h[i] = (bitmap_t*)((char *)fv_ + base_h[i]);
        }

        // data slice
        size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4
        //size_t remainder = bmn_ - SIMDUnitNum*4;
        size_t unit;
        size_t remainBitMapBeginId = SIMDUnitNum * 4;

        bitmap_t tmpBitMap0,tmpBitMap1,tmpBitMap2,tmpBitMap3,tmpBitMap;

        // If changing the code num, change the below x
        // bitmap_t bm[5];
        // __m256i codes[5];
        __m256i mid_res;

        size_t computeNum_l = LoadNum(code_num_, index_l);
        size_t computeNum_h = LoadNum(code_num_, index_h);

        if(anti == 0)   // op_ab (v <= vl || v >= vh)
        {
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                for(size_t i = code_num_ - computeNum_l; i < code_num_; i++) {
                    code_array[i] = _mm256_load_si256((__m256i const *) (address_l[i] + (unit<<2)));
                }

                // change x
                (simd->*(simd_compute_ab_le))(code_array);

                mid_res = simd->tmp;

                for(size_t i = code_num_ - computeNum_h; i < code_num_; i++) {
                    code_array[i] = _mm256_load_si256((__m256i const *) (address_h[i] + (unit<<2)));
                }

                // change x
                (simd->*(simd_compute_ab_ge))(code_array);

                mid_res = _mm256_or_si256(mid_res, simd->tmp);  //?

                _mm256_store_si256((__m256i *) (sv + (unit<<2)), mid_res);
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                for(size_t i = code_num_ - computeNum_l; i < code_num_; i++) {
                    bitmap_array[i] = address_l[i][remain];
                }
                // change x
                (simd->*(bitmap_compute_ab_le))(bitmap_array);
                tmpBitMap = simd->tmp_bm;

                for(size_t i = code_num_ - computeNum_h; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                }
                // change x
                (simd->*(bitmap_compute_ab_ge))(bitmap_array);
                tmpBitMap |= simd->tmp_bm;  //?

                tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        } else {    // op_bt (v >= vl && v <= vh)
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                for(size_t i = code_num_ - computeNum_l; i < code_num_; i++) {
                    code_array[i] = _mm256_load_si256((__m256i const *) (address_l[i] + (unit<<2)));
                }

                // change x
                (simd->*(simd_compute_bt_ge))(code_array);

                mid_res = simd->tmp;

                for(size_t i = code_num_ - computeNum_h; i < code_num_; i++) {
                    code_array[i] = _mm256_load_si256((__m256i const *) (address_h[i] + (unit<<2)));
                }

                // change x
                (simd->*(simd_compute_bt_le))(code_array);

                mid_res = _mm256_and_si256(mid_res, simd->tmp);  //?

                _mm256_store_si256((__m256i *) (sv + (unit<<2)), mid_res);
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                for(size_t i = code_num_ - computeNum_l; i < code_num_; i++) {
                    bitmap_array[i] = address_l[i][remain];
                }
                // change x
                (simd->*(bitmap_compute_bt_ge))(bitmap_array);
                tmpBitMap = simd->tmp_bm;

                for(size_t i = code_num_ - computeNum_h; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                }
                // change x
                (simd->*(bitmap_compute_bt_le))(bitmap_array);
                tmpBitMap &= simd->tmp_bm;  //?

                tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        }
    }
}

void Cabin::GenTempResult_cs_general(size_t group, size_t index, bool anti, WordUnit x_h, WordUnit x_l, bitmap_t* sv,\
                                    __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                    bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address))
{
    bitmap_t result_tmp;

    std::vector<size_t> base(code_num_);
    std::vector<bitmap_t*> address(code_num_);
    for(size_t i = 0; i < code_num_; i++) {
        base[i] = (group*code_num_+i)*aligned_slot;
        address[i] = (bitmap_t*)((char *)fv_ + base[i]);
    }

    // data slice
    size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4
    //size_t remainder = bmn_ - SIMDUnitNum*4;
    size_t unit;
    size_t remainBitMapBeginId = SIMDUnitNum * 4;

    bitmap_t tmpBitMap, tmpCodeBitMap;

    // If changing the code num, change the below 4
    // bitmap_t bm[9];
    // __m256i codes[9];
    __m256i tmp;
    uint64_t * tmp_result = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));
    uint64_t * tmpLoc = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));
    size_t code = CodeGet(index+1);
    std::bitset<10> one_hot;
    for(size_t idx = 0; idx < code_num_; idx++) {
        one_hot.set(idx, ((code & (1 << idx)) != 0));
    }
    __m256i AllOne = _mm256_set1_epi32(-1);
    WordUnit check_value;
    uint64_t bitmap_1_pos;

    size_t computeNum = LoadNum(code_num_, index);

    if(anti == 0)   //<=
    {
        for (unit = 0; unit < SIMDUnitNum; unit++) {
            tmp = AllOne;
            for(size_t idx = 0; idx < code_num_; idx++) {
                code_array[idx] = _mm256_load_si256((__m256i const *) (address[idx] + (unit<<2)));
                tmp = one_hot.test(idx) ? _mm256_and_si256(code_array[idx], tmp) : _mm256_andnot_si256(code_array[idx], tmp);
            }
            // change x
            (simd->*(simd_compute_le))(code_array);

            tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
            tmp_result = reinterpret_cast<uint64_t *>(&simd->tmp);
            for(size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                while(tmpLoc[i] != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                    check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                    tmp_result[i] |= ((bitmap_t)(check_value <= x_h)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                }
            }
            _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
        }

        // handle the remainder
        for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
            tmpCodeBitMap = -1;
            for(size_t i = 0; i < code_num_; i++) {
                bitmap_array[i] = address[i][remain];
                tmpCodeBitMap = one_hot.test(i) ? (address[i][remain] & tmpCodeBitMap) : (~address[i][remain] & tmpCodeBitMap);
            }
            // change x
            (simd->*(bitmap_compute_le))(bitmap_array);
            tmpBitMap = simd->tmp_bm;

            while(tmpCodeBitMap != 0) {
                bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                tmpBitMap |= ((bitmap_t)(check_value <= x_h)) << bitmap_1_pos;
                //tmpLoc[i] ^= 1 << bitmap_1_pos;
                tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
            }

            tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

            sv[remain] = tmpBitMap;
        }
    } else {    // >=
    }

}

void Cabin::GenTempResult_2_cs_le(size_t group, size_t index, bool anti, WordUnit x_h, bitmap_t* sv)
{
    //if(x_h != -386010935) return;
    bitmap_t result_tmp;

    std::vector<size_t> base(code_num_);
    std::vector<bitmap_t*> address(code_num_);
    for(size_t i = 0; i < code_num_; i++) {
        base[i] = (group*code_num_+i)*aligned_slot;
        address[i] = (bitmap_t*)((char *)fv_ + base[i]);
    }

    // data slice
    size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4
    //size_t remainder = bmn_ - SIMDUnitNum*4;
    size_t unit;
    size_t remainBitMapBeginId = SIMDUnitNum * 4;

    bitmap_t tmpBitMap, tmpCodeBitMap;

    // If changing the code num, change the below 4
    bitmap_t bm[2];
    __m256i codes[2];
    __m256i tmp;
    __m256i simd_tmp;
    bitmap_t simd_tmp_bm;
    uint64_t * tmp_result = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));
    uint64_t * tmpLoc = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));
    size_t code = CodeGet(index+1);
    std::bitset<10> one_hot;
    for(size_t idx = 0; idx < code_num_; idx++) {
        one_hot.set(idx, ((code & (1 << idx)) != 0));
    }
    __m256i AllOne = _mm256_set1_epi32(-1);
    WordUnit check_value;
    uint64_t bitmap_1_pos;

    size_t computeNum = LoadNum(code_num_, index);
    __m256i c = _mm256_set1_epi32(-1);

    if(anti == 0)   //<=
    {
        for (unit = 0; unit < SIMDUnitNum; unit++) {
            tmp = AllOne;
            for(size_t idx = 0; idx < code_num_; idx++) {
                codes[idx] = _mm256_load_si256((__m256i const *) (address[idx] + (unit<<2)));
                tmp = one_hot.test(idx) ? _mm256_and_si256(codes[idx], tmp) : _mm256_andnot_si256(codes[idx], tmp);
            }

            switch (index) {
                case 0: // each code matching 00 will give 1 result
                {
                    // or
                    simd_tmp = _mm256_or_si256(codes[0], codes[1]);
                    // not
                    simd_tmp = _mm256_xor_si256(c, simd_tmp);
                }
                    break;
                case 1: // each code matching 00&01 will give 1 result
                {
                    // not
                    simd_tmp = _mm256_xor_si256(c, codes[1]);
                }
                    break;
                case 2: // each code matching 00&01&11 will give 1 result
                {
                    // and
                    simd_tmp = _mm256_andnot_si256(codes[0], codes[1]);
                    // not
                    simd_tmp = _mm256_xor_si256(c, simd_tmp);
                }
                    break;
                default:
                    break;
            }

            tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
            tmp_result = reinterpret_cast<uint64_t *>(&simd_tmp);
            for(size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                while(tmpLoc[i] != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                    check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                    tmp_result[i] |= ((bitmap_t)(check_value <= x_h)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                }
            }
            _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
        }

        // handle the remainder
        for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
            tmpCodeBitMap = -1;
            for(size_t i = 0; i < code_num_; i++) {
                bm[i] = address[i][remain];
                tmpCodeBitMap = one_hot.test(i) ? (address[i][remain] & tmpCodeBitMap) : (~address[i][remain] & tmpCodeBitMap);
            }
            switch (index) {
                case 0: // each code matching 00 will give 1 result
                {
                    simd_tmp_bm = ~(bm[0] | bm[1]);
                }
                    break;
                case 1: // each code matching 00&01 will give 1 result
                {
                    simd_tmp_bm = ~bm[1];
                }
                    break;
                case 2: // each code matching 00&01&11 will give 1 result
                {
                    simd_tmp_bm = ~(~bm[0] & bm[1]);
                }
                    break;
                default:
                    break;
            }
            tmpBitMap = simd_tmp_bm;

            while(tmpCodeBitMap != 0) {
                bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                tmpBitMap |= ((bitmap_t)(check_value <= x_h)) << bitmap_1_pos;
                //tmpLoc[i] ^= 1 << bitmap_1_pos;
                tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
            }

            tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

            sv[remain] = tmpBitMap;
        }
    } else {    // >=
    }

}

void Cabin::GenTempResult_cs_between_general(size_t area_id_h, size_t area_id_l, size_t group_h, size_t group_l, size_t indexInGroup_h, size_t indexInGroup_l, WordUnit x_h, WordUnit x_l, bitmap_t* sv,\
                                            __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                            bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address))
{
    // If changing the code num, change the below 4
    // bitmap_t bm[9];
    // __m256i codes[9];
    __m256i tmp,tmp_l,tmp_h;
    uint64_t * tmp_result = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));
    uint64_t * tmpLoc = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));

    // data slice
    size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4
    //size_t remainder = bmn_ - SIMDUnitNum*4;
    size_t unit;
    size_t remainBitMapBeginId = SIMDUnitNum * 4;

    bitmap_t tmpBitMap, tmpCodeBitMap,tmpCodeBitMap_l, tmpCodeBitMap_h;
    __m256i AllOne = _mm256_set1_epi32(-1);
    __m256i AllZero = _mm256_set1_epi32(0);
    WordUnit check_value;
    uint64_t bitmap_1_pos;

    __m256i mid_res;

    if(area_id_l == area_id_h) {
        //compute_time++;
        size_t group = area_id_l / volume_;
        size_t indexInGroup = area_id_l % volume_;

        std::vector<size_t> base(code_num_);
        std::vector<bitmap_t*> address(code_num_);
        for(size_t i = 0; i < code_num_; i++) {
            base[i] = (group*code_num_+i)*aligned_slot;
            address[i] = (bitmap_t*)((char *)fv_ + base[i]);
        }

        size_t code = CodeGet(indexInGroup+1);
        std::bitset<10> one_hot;
        for(size_t idx = 0; idx < code_num_; idx++) {
            one_hot.set(idx, ((code & (1 << idx)) != 0));
        }

        for (unit = 0; unit < SIMDUnitNum; unit++) {
            tmp = AllOne;
            for(size_t idx = 0; idx < code_num_; idx++) {
                code_array[idx] = _mm256_load_si256((__m256i const *) (address[idx] + (unit<<2)));
                tmp = one_hot.test(idx) ? _mm256_and_si256(code_array[idx], tmp) : _mm256_andnot_si256(code_array[idx], tmp);
            }

            mid_res = AllZero;

            tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
            tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
            for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                while (tmpLoc[i] != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                    check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                    tmp_result[i] |= ((bitmap_t) (check_value <= x_h && check_value >= x_l)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                }
            }
            _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
        }

        // handle the remainder
        for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
            tmpCodeBitMap = -1;
            for(size_t i = 0; i < code_num_; i++) {
                bitmap_array[i] = address[i][remain];
                tmpCodeBitMap = one_hot.test(i) ? (address[i][remain] & tmpCodeBitMap) : (~address[i][remain] & tmpCodeBitMap);
            }
            tmpBitMap = 0;

            while(tmpCodeBitMap != 0) {
                bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                tmpBitMap |= ((bitmap_t)(check_value <= x_h && check_value >= x_l)) << bitmap_1_pos;
                //tmpLoc[i] ^= 1 << bitmap_1_pos;
                tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
            }

            tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

            sv[remain] = tmpBitMap;
        }
    } else {
        std::vector<size_t> base_h(code_num_);
        std::vector<bitmap_t*> address_h(code_num_);
        for(size_t i = 0; i < code_num_; i++) {
            base_h[i] = (group_h*code_num_+i)*aligned_slot;
            address_h[i] = (bitmap_t*)((char *)fv_ + base_h[i]);
        }

        std::vector<size_t> base_l(code_num_);
        std::vector<bitmap_t*> address_l(code_num_);
        for(size_t i = 0; i < code_num_; i++) {
            base_l[i] = (group_l*code_num_+i)*aligned_slot;
            address_l[i] = (bitmap_t*)((char *)fv_ + base_l[i]);
        }

        size_t code_h = CodeGet(indexInGroup_h+1);
        size_t code_l = CodeGet(indexInGroup_l+1);
        std::bitset<10> one_hot_h;
        for(size_t idx = 0; idx < code_num_; idx++) {
            one_hot_h.set(idx, ((code_h & (1 << idx)) != 0));
        }
        std::bitset<10> one_hot_l;
        for(size_t idx = 0; idx < code_num_; idx++) {
            one_hot_l.set(idx, ((code_l & (1 << idx)) != 0));
        }

        if(area_id_h - area_id_l == 1) {
            //refine_time++;
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                tmp_h = tmp_l = AllOne;
                for(size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_h[idx] + (unit<<2)));
                    tmp_h = one_hot_h.test(idx) ? _mm256_and_si256(code_array[idx], tmp_h) : _mm256_andnot_si256(code_array[idx], tmp_h);
                }

                for(size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_l[idx] + (unit<<2)));
                    tmp_l = one_hot_l.test(idx) ? _mm256_and_si256(code_array[idx], tmp_l) : _mm256_andnot_si256(code_array[idx], tmp_l);
                }
                mid_res = AllZero;
                tmp = _mm256_or_si256(tmp_h, tmp_l);

                tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
                tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
                for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                    while (tmpLoc[i] != 0) {
                        bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                        check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                        tmp_result[i] |= ((bitmap_t) (check_value <= x_h && check_value >= x_l)) << bitmap_1_pos;
                        //tmpLoc[i] ^= 1 << bitmap_1_pos;
                        tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                    }
                }
                _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                tmpCodeBitMap_h = tmpCodeBitMap_l = -1;
                for(size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                    tmpCodeBitMap_h = one_hot_h.test(i) ? (address_h[i][remain] & tmpCodeBitMap_h) : (~address_h[i][remain] & tmpCodeBitMap_h);
                }

                for(size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_l[i][remain];
                    tmpCodeBitMap_l = one_hot_l.test(i) ? (address_l[i][remain] & tmpCodeBitMap_l) : (~address_l[i][remain] & tmpCodeBitMap_l);
                }
                tmpBitMap = 0;
                tmpCodeBitMap = tmpCodeBitMap_h | tmpCodeBitMap_l;

                while(tmpCodeBitMap != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                    check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                    tmpBitMap |= ((bitmap_t)(check_value <= x_h && check_value >= x_l)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
                }

                tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        } else {
            //shortcut_num++;
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                tmp_h = tmp_l = AllOne;
                for(size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_h[idx] + (unit<<2)));
                    tmp_h = one_hot_h.test(idx) ? _mm256_and_si256(code_array[idx], tmp_h) : _mm256_andnot_si256(code_array[idx], tmp_h);
                }
                // change x
                (simd->*(simd_compute_le))(code_array);
                mid_res = simd->tmp;

                for(size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_l[idx] + (unit<<2)));
                    tmp_l = one_hot_l.test(idx) ? _mm256_and_si256(code_array[idx], tmp_l) : _mm256_andnot_si256(code_array[idx], tmp_l);
                }
                // change x
                (simd->*(simd_compute_ge))(code_array);
                mid_res = _mm256_and_si256(mid_res, simd->tmp); // op_bt
                tmp = _mm256_or_si256(tmp_h, tmp_l);

                tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
                tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
                for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                    while (tmpLoc[i] != 0) {
                        bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                        check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                        tmp_result[i] |= ((bitmap_t) (check_value <= x_h && check_value >= x_l)) << bitmap_1_pos;
                        //tmpLoc[i] ^= 1 << bitmap_1_pos;
                        tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                    }
                }
                _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                tmpCodeBitMap_h = tmpCodeBitMap_l = -1;
                for(size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                    tmpCodeBitMap_h = one_hot_h.test(i) ? (address_h[i][remain] & tmpCodeBitMap_h) : (~address_h[i][remain] & tmpCodeBitMap_h);
                }
                // change x
                (simd->*(bitmap_compute_le))(bitmap_array);
                tmpBitMap = simd->tmp_bm;

                for(size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_l[i][remain];
                    tmpCodeBitMap_l = one_hot_l.test(i) ? (address_l[i][remain] & tmpCodeBitMap_l) : (~address_l[i][remain] & tmpCodeBitMap_l);
                }
                // change x
                (simd->*(bitmap_compute_ge))(bitmap_array);
                tmpBitMap &= simd->tmp_bm;
                tmpCodeBitMap = tmpCodeBitMap_h | tmpCodeBitMap_l;

                while(tmpCodeBitMap != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                    check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                    tmpBitMap |= ((bitmap_t)(check_value <= x_h && check_value >= x_l)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
                }

                tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        }
    }
}

void Cabin::GenTempResult_mix_between_general(size_t area_id_h, size_t area_id_l,  size_t group_h, size_t group_l, size_t indexInGroup_h, size_t indexInGroup_l, WordUnit x_h, WordUnit x_l, bitmap_t* sv, bool WaxWane, bool w_wo,\
                                            __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                            bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address))
{
    // If changing the code num, change the below 4
    // bitmap_t bm[8];
    // __m256i codes[8];
    __m256i tmp,tmp_l,tmp_h;
    uint64_t * tmp_result = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));
    uint64_t * tmpLoc = static_cast<bitmap_t *>(os_aligned_alloc(4*sizeof(bitmap_t), 32));

    // data slice
    size_t SIMDUnitNum = (bmn_ - 1) / 4;    // the last bitmap may have some parts undefined, so minus 1; 256/64 ==> 4
    //size_t remainder = bmn_ - SIMDUnitNum*4;
    size_t unit;
    size_t remainBitMapBeginId = SIMDUnitNum * 4;

    bitmap_t tmpBitMap, tmpCodeBitMap,tmpCodeBitMap_l, tmpCodeBitMap_h;
    __m256i AllOne = _mm256_set1_epi32(-1);
    __m256i AllZero = _mm256_set1_epi32(0);
    WordUnit check_value;
    uint64_t bitmap_1_pos;

    __m256i mid_res;

    std::vector<size_t> base_h(code_num_);
    std::vector<bitmap_t*> address_h(code_num_);
    for(size_t i = 0; i < code_num_; i++) {
        base_h[i] = (group_h*code_num_+i)*aligned_slot;
        address_h[i] = (bitmap_t*)((char *)fv_ + base_h[i]);
    }

    std::vector<size_t> base_l(code_num_);
    std::vector<bitmap_t*> address_l(code_num_);
    for(size_t i = 0; i < code_num_; i++) {
        base_l[i] = (group_l*code_num_+i)*aligned_slot;
        address_l[i] = (bitmap_t*)((char *)fv_ + base_l[i]);
    }

    if(w_wo == true) {         // w_wo == true: x_h with selective position array; x_l without selective position array
        if(WaxWane == 1)
            indexInGroup_h += 1;
        size_t computeNum_h = LoadNum(code_num_, indexInGroup_h);
        size_t code_l = CodeGet(indexInGroup_l+1);
        std::bitset<10> one_hot_l;
        for(size_t idx = 0; idx < code_num_; idx++) {
            one_hot_l.set(idx, ((code_l & (1 << idx)) != 0));
        }

        if(group_h*volume_+indexInGroup_h == group_l*volume_+indexInGroup_l+1) {
            compute_time++;
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                tmp_l = AllOne;
                for(size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_l[idx] + (unit<<2)));
                    tmp_l = one_hot_l.test(idx) ? _mm256_and_si256(code_array[idx], tmp_l) : _mm256_andnot_si256(code_array[idx], tmp_l);
                }

                mid_res = AllZero; // op_bt
                tmp = tmp_l;

                tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
                tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
                for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                    while (tmpLoc[i] != 0) {
                        bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                        check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                        tmp_result[i] |= ((bitmap_t) (check_value >= x_l)) << bitmap_1_pos;
                        //tmpLoc[i] ^= 1 << bitmap_1_pos;
                        tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                    }
                }
                _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                tmpCodeBitMap_l = -1;
                for(size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_l[i][remain];
                    tmpCodeBitMap_l = one_hot_l.test(i) ? (address_l[i][remain] & tmpCodeBitMap_l) : (~address_l[i][remain] & tmpCodeBitMap_l);
                }
                tmpBitMap = 0;
                tmpCodeBitMap = tmpCodeBitMap_l;

                while(tmpCodeBitMap != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                    check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                    tmpBitMap |= ((bitmap_t)(check_value >= x_l)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
                }

                tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        } else {
            //compute_time_wo_sp++;
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                for(size_t i = code_num_ - computeNum_h; i < code_num_; i++) {
                    code_array[i] = _mm256_load_si256((__m256i const *) (address_h[i] + (unit<<2)));
                }

                // change x
                (simd->*(simd_compute_le))(code_array);
                mid_res = simd->tmp;

                tmp_l = AllOne;
                for(size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_l[idx] + (unit<<2)));
                    tmp_l = one_hot_l.test(idx) ? _mm256_and_si256(code_array[idx], tmp_l) : _mm256_andnot_si256(code_array[idx], tmp_l);
                }
                // change x
                (simd->*(simd_compute_ge))(code_array);
                mid_res = _mm256_and_si256(mid_res, simd->tmp); // op_bt
                tmp = tmp_l;

                tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
                tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
                for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                    while (tmpLoc[i] != 0) {
                        bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                        check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                        tmp_result[i] |= ((bitmap_t) (check_value >= x_l)) << bitmap_1_pos;
                        //tmpLoc[i] ^= 1 << bitmap_1_pos;
                        tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                    }
                }
                _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                for(size_t i = code_num_ - computeNum_h; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                }
                // change x
                (simd->*(bitmap_compute_le))(bitmap_array);
                tmpBitMap = simd->tmp_bm;  //?

                tmpCodeBitMap_l = -1;
                for(size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_l[i][remain];
                    tmpCodeBitMap_l = one_hot_l.test(i) ? (address_l[i][remain] & tmpCodeBitMap_l) : (~address_l[i][remain] & tmpCodeBitMap_l);
                }
                // change x
                (simd->*(bitmap_compute_ge))(bitmap_array);
                tmpBitMap &= simd->tmp_bm;
                tmpCodeBitMap = tmpCodeBitMap_l;

                while(tmpCodeBitMap != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                    check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                    tmpBitMap |= ((bitmap_t)(check_value >= x_l)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
                }

                tmpBitMap &= (remain == bmn_-1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        }
    } else {                // w_wo == false: x_h without selective position array; x_l with selective position array
        if(WaxWane == 1)
            indexInGroup_l += 1;
        size_t computeNum_l = LoadNum(code_num_, indexInGroup_l);
        size_t code_h = CodeGet(indexInGroup_h+1);
        std::bitset<10> one_hot_h;
        for(size_t idx = 0; idx < code_num_; idx++) {
            one_hot_h.set(idx, ((code_h & (1 << idx)) != 0));
        }

        if(group_h*volume_+indexInGroup_h == group_l*volume_+indexInGroup_l) {
            //shortcut_num++;
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                tmp_h = AllOne;
                for (size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_h[idx] + (unit << 2)));
                    tmp_h = one_hot_h.test(idx) ? _mm256_and_si256(code_array[idx], tmp_h) : _mm256_andnot_si256(code_array[idx], tmp_h);
                }

                mid_res = AllZero; // op_bt
                tmp = tmp_h;

                tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
                tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
                for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                    while (tmpLoc[i] != 0) {
                        bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                        check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                        tmp_result[i] |= ((bitmap_t) (check_value <= x_h)) << bitmap_1_pos;
                        //tmpLoc[i] ^= 1 << bitmap_1_pos;
                        tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                    }
                }
                _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                tmpCodeBitMap_h = -1;
                for (size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                    tmpCodeBitMap_h = one_hot_h.test(i) ? (address_h[i][remain] & tmpCodeBitMap_h) : (~address_h[i][remain] & tmpCodeBitMap_h);
                }

                tmpBitMap = 0;
                tmpCodeBitMap = tmpCodeBitMap_h;

                while (tmpCodeBitMap != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                    check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                    tmpBitMap |= ((bitmap_t) (check_value <= x_h)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
                }

                tmpBitMap &= (remain == bmn_ - 1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        } else {
            //refine_time++;
            for (unit = 0; unit < SIMDUnitNum; unit++) {
                tmp_h = AllOne;
                for (size_t idx = 0; idx < code_num_; idx++) {
                    code_array[idx] = _mm256_load_si256((__m256i const *) (address_h[idx] + (unit << 2)));
                    tmp_h = one_hot_h.test(idx) ? _mm256_and_si256(code_array[idx], tmp_h) : _mm256_andnot_si256(code_array[idx], tmp_h);
                }
                // change x
                (simd->*(simd_compute_le))(code_array);
                mid_res = simd->tmp;

                for (size_t i = code_num_ - computeNum_l; i < code_num_; i++) {
                    code_array[i] = _mm256_load_si256((__m256i const *) (address_l[i] + (unit << 2)));
                }

                // change x
                (simd->*(simd_compute_ge))(code_array);
                mid_res = _mm256_and_si256(mid_res, simd->tmp); // op_bt
                tmp = tmp_h;

                tmpLoc = reinterpret_cast<uint64_t *>(&tmp);
                tmp_result = reinterpret_cast<uint64_t *>(&mid_res);
                for (size_t i = 0; i < 4; i++) { // 256 / 64 = 4
                    while (tmpLoc[i] != 0) {
                        bitmap_1_pos = _tzcnt_u64(tmpLoc[i]);

                        check_value = column_->GetTuple(unit * 256 + 64 * i + bitmap_1_pos);
                        tmp_result[i] |= ((bitmap_t) (check_value <= x_h)) << bitmap_1_pos;
                        //tmpLoc[i] ^= 1 << bitmap_1_pos;
                        tmpLoc[i] = _blsr_u64(tmpLoc[i]);
                    }
                }
                _mm256_store_si256((__m256i *) (sv + (unit<<2)), *(__m256i*)(tmp_result));
            }

            // handle the remainder
            for (size_t remain = remainBitMapBeginId; remain < bmn_; remain++) {
                tmpCodeBitMap_h = -1;
                for (size_t i = 0; i < code_num_; i++) {
                    bitmap_array[i] = address_h[i][remain];
                    tmpCodeBitMap_h = one_hot_h.test(i) ? (address_h[i][remain] & tmpCodeBitMap_h) : (~address_h[i][remain] & tmpCodeBitMap_h);
                }
                // change x
                (simd->*(bitmap_compute_le))(bitmap_array);
                tmpBitMap = simd->tmp_bm;

                for (size_t i = 0; i < code_num_ - computeNum_l; i++) {
                    bitmap_array[i] = address_l[i][remain];
                }
                // change x
                (simd->*(bitmap_compute_ge))(bitmap_array);
                tmpBitMap &= simd->tmp_bm;
                tmpCodeBitMap = tmpCodeBitMap_h;

                while (tmpCodeBitMap != 0) {
                    bitmap_1_pos = _tzcnt_u64(tmpCodeBitMap);

                    check_value = column_->GetTuple(64 * remain + bitmap_1_pos);
                    tmpBitMap |= ((bitmap_t) (check_value <= x_h)) << bitmap_1_pos;
                    //tmpLoc[i] ^= 1 << bitmap_1_pos;
                    tmpCodeBitMap = _blsr_u64(tmpCodeBitMap);
                }

                tmpBitMap &= (remain == bmn_ - 1) ? (~0ULL >> (bmn_ * BITMAPWIDTH - value_num_)) : ~0ULL;

                sv[remain] = tmpBitMap;
            }
        }
    }

}

void Cabin::OperandLocInSortedPosArray(WordUnit operand, size_t area_id, op_class op, PosWidth &position) {
    // binary search
    m_area_t theArea;
    size_t first_p, last_p, mid_p;
    size_t pos;
    switch (op) {
        case op_le:
        {
            theArea = area_[area_id];
            first_p = theArea.pos;
            last_p = first_p + theArea.len;
            while (first_p < last_p) {
                mid_p = first_p + (last_p - first_p) / 2;
                if (column_->GetTuple(rv_[mid_p]) <= operand)
                    first_p = mid_p + 1;
                else
                    last_p = mid_p;
            }
            // the last matched value's position+1. for example, found 4 in 1,4,4,4, the answer is 4.
            // when *pu == theArea->pos, it means that incmp < all values in area_[*au]
            pos = first_p;
        }
            break;
        case op_ge:
        {
            theArea = area_[area_id];
            first_p = theArea.pos;
            last_p = first_p + theArea.len;
            while (first_p < last_p) {
                mid_p = first_p + (last_p - first_p) / 2;
                if (column_->GetTuple(rv_[mid_p]) < operand)
                    first_p = mid_p + 1;
                else
                    last_p = mid_p;
            }
            // the first matched value's position. for example, found 4 in 1,4,4,4, the answer is 1.
            // when *pu == theArea->pos, it means that incmp <= all values in area_[*au]
            pos = first_p;
        }
            break;
        default:
            break;
    }

    position = pos;
}

void Cabin::AreaID(WordUnit operand, size_t &area_id, op_class op)
{
    m_area_t *thearea;
    size_t first, last, mid;
    switch (op) {
        case op_le:
        {
            first = 0;
            last = partition_num_;
            while (last > first) {
                mid = first + (last - first) / 2;
                if (area_[mid].val <= operand)
                    first = mid + 1;
                else
                    last = mid;
            }
            // the last matched value's position. for example, found 4 in 1,4,4,4, the answer is 3.
            // when *au == 0, it means that incmp is <= area_[0].val
            area_id = (first == 0) ? 0 : (first - 1);
        }
            break;
        case op_ge:
        {
            first = 0;
            last = partition_num_;
            while (last > first) {
                mid = first + (last - first) / 2;
                if (area_[mid].val < operand)
                    first = mid + 1;
                else
                    last = mid;
            }
            // the first matched value's previous position. for example, found 4 in 1,4,4,4, the answer is 0.
            // when *al == 0, it means that incmp is <= area_[1].val
            area_id = (first == 0) ? 0 : (first - 1);
        }
            break;
        default:
            break;
    }
}

void Cabin::UpperOrLowerBound(bool &WaxWane, size_t &start, size_t &end, size_t area_id, PosWidth pos) {

    m_area_t a = area_[area_id];

    // todo: add the penalty of codes computation and bit vectors reading
    if ((pos - a.pos) < (a.len / 2)) {
        /* left part */
        WaxWane = false;
        start = a.pos;
        end = pos;
    } else {
        /* right part */
        WaxWane = true;
        start = pos;
        end = a.pos + a.len;
    }
}

bool Cabin::CheckResult(WordUnit xh, WordUnit xl, op_class op)
{
    int flag = 0;
    switch (op) {
        case op_le:
        {
            for(size_t i = 0; i < bmn_; i++)
            {
                bitmap_t tmp = 0;
                for(size_t j = 0; j < BITMAPWIDTH; j++)
                {
                    size_t id = i*BITMAPWIDTH+j;
                    if(id >= value_num_)
                        break;
                    if(column_->GetTuple(id) <= xh)
                    {
                        tmp |= 1ULL << j;   //changed with bit width
                    }
                }

                if(tmp != sv_[i]) {
                    flag = 1;
                    std::cout << "right: " << tmp << std::endl;
                    std::cout << "wrong: " << sv_[i] << std::endl;
                    std::cout << "wrong answer in id: " << i << std::endl;
                    break;
                }
            }
            if(flag == 0) {
                //std::cout << "Right Answer" << std::endl;
                return true;
            }
        };
            break;
        case op_ge:
        {
            for(size_t i = 0; i < bmn_; i++)
            {
                bitmap_t tmp = 0;
                for(size_t j = 0; j < BITMAPWIDTH; j++)
                {
                    size_t id = i*BITMAPWIDTH+j;
                    if(id >= value_num_)
                        break;
                    if(column_->GetTuple(id) >= xl)
                    {
                        tmp |= 1ULL << j;   //changed with bit width
                    }
                }

                if(tmp != sv_[i]) {
                    flag = 1;
                    std::cout << tmp << std::endl;
                    std::cout << sv_[i] << std::endl;
                    std::cout << "wrong answer in id: " << i << std::endl;
                    break;
                }
            }
            if(flag == 0) {
                //std::cout << "Right Answer" << std::endl;
                return true;
            }
        };
            break;
        case op_bt:
        {
            for(size_t i = 0; i < bmn_; i++)
            {
                bitmap_t tmp = 0;
                for(size_t j = 0; j < BITMAPWIDTH; j++)
                {
                    size_t id = i*BITMAPWIDTH+j;
                    if(id >= value_num_)
                        break;
                    if(column_->GetTuple(id) >= xl && column_->GetTuple(id) <= xh)
                    {
                        tmp |= 1ULL << j;   //changed with bit width
                    }
                }

                if(tmp != sv_[i]) {
                    flag = 1;
                    std::cout << tmp << std::endl;
                    std::cout << sv_[i] << std::endl;
                    std::cout << "wrong answer in id: " << i << std::endl;
                    break;
                }
            }
            if(flag == 0) {
                //std::cout << "Right Answer" << std::endl;
                return true;
            }
        }
            break;
        case op_ab:
        {
            for(size_t i = 0; i < bmn_; i++)
            {
                bitmap_t tmp = 0;
                for(size_t j = 0; j < BITMAPWIDTH; j++)
                {
                    size_t id = i*BITMAPWIDTH+j;
                    if(id >= value_num_)
                        break;
                    if(column_->GetTuple(id) <= xl || column_->GetTuple(id) >= xh)
                    {
                        tmp |= 1ULL << j;   //changed with bit width
                    }
                }

                if(tmp != sv_[i]) {
                    flag = 1;
                    std::cout << tmp << std::endl;
                    std::cout << sv_[i] << std::endl;
                    std::cout << "wrong answer in id: " << i << std::endl;
                    break;
                }
            }
            if(flag == 0) {
                //std::cout << "Right Answer" << std::endl;
                return true;
            }
        }
            break;
        default:
            break;
    }
    return false;
}