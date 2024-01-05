//
// Created by chen1yuan on 2022/3/30.
//


#include "queryqueue.h"

QueryQueue::QueryQueue() {}

QueryQueue::~QueryQueue() {}

void QueryQueue::QuerySet(WordUnit x) {
    query.push_back(x);
}

WordUnit QueryQueue::QueryLook(size_t index) {
    assert(index < query.size());
    return query[index];
}

WordUnit QueryQueue::QueryLook_l(size_t index) {
    assert(index < query_l.size());
    return query_l[index];
}

WordUnit QueryQueue::QueryLook_h(size_t index) {
    assert(index < query_h.size());
    return query_h[index];
}

void QueryQueue::QueryGenerate(Column* column, arg_t arg) {
    std::vector<WordUnit> copied_array_;
    copied_array_.assign(column->array_, column->array_+column->num_tuples_);

    size_t percent = column->num_tuples_ / 100;

    if(arg.patch_type == 0) {
        //WordUnit x = FractionOfArray(arg.selectivity, sorted_sample_array_);
        size_t nth = (arg.selectivity == 100) ? column->num_tuples_-1 : arg.selectivity*percent;

        std::nth_element(copied_array_.begin(), copied_array_.begin() + nth, copied_array_.end());
        query.push_back(*(copied_array_.begin() + nth));
    } else if(arg.patch_type == 1 || arg.patch_type == 2 || arg.patch_type == 3){
        // size_t stride = (100 / arg.patch_num) * percent;
        size_t stride = column->num_tuples_ / arg.patch_num;
        auto start = copied_array_.begin();
        std::nth_element(start, start, copied_array_.end());
        query.push_back(*start);
        for(size_t i = 0; i < arg.patch_num-1; i++)
        {
            std::nth_element(start, start+stride, copied_array_.end());
            //std::cout << *(start) << std::endl;
            query.push_back(*(start+stride));
            start += stride;
        }
        std::nth_element(start, copied_array_.end()-1, copied_array_.end());
        query.push_back(*(copied_array_.end()-1));
    } 
}

void QueryQueue::QueryGenerateFromFile_l(std::string path)
{
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            int32_t q;
            q =atoi(line.c_str());
            query_l.emplace_back(q);
        }
        file.close();
    }
}

void QueryQueue::QueryGenerateFromFile_h(std::string path)
{
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            int32_t q;
            q = atoi(line.c_str());
            query_h.emplace_back(q);
        }
        file.close();
    }
}

void QueryQueue::QueryGenerateFromFile_float(std::string path)
{
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            float q;
            q = std::stof(line);
            query.emplace_back(q);
        }
        file.close();
    }
}

void QueryQueue::QueryGenerateFromFile_double(std::string path)
{
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            double q;
            q = std::stod(line);
            query.emplace_back(q);
        }
        file.close();
    }
}

void QueryQueue::QueryGenerateFromFile_int(std::string path)
{
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            int q;
            q = std::stoi(line);
            query.emplace_back(q);
        }
        file.close();
    }
}



