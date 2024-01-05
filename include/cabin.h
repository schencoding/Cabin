
#ifndef SCANCODE_CABIN_H
#define SCANCODE_CABIN_H

#include "column.h"
#include "queryqueue.h"
#include "types.h"
#include "configure.h"
#include "simd_compute.h"

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <chrono>
#include <unordered_set>
#include <unordered_map>

/*
 * the area struct
 */
typedef struct {
    WordUnit val;	/* storage is first in the record */
    PosWidth pos;
    size_t len;
} m_area_t;


class Cabin {
public:
    Cabin();
    Cabin(Column* column, QueryQueue* query);
    Cabin(Column* column, QueryQueue* query, workloadFeature* wf);
    ~Cabin();
    void Destroy();
    void CreateIndex();
    void Scan(WordUnit x_h, WordUnit x_l, op_class op);
    bool CheckResult(WordUnit xh, WordUnit xl, op_class op);

    std::string name = "Cabin";
    size_t refine_num = 0;
    int query_w_pa_num = 0;
    int query_wo_pa_num = 0;
    double refine_time = 0.0;
    double compute_time = 0.0;
    double compute_cal_time = 0.0;
    double compute_time_wo_sp = 0.0;
    double compute_time_bitmap = 0.0;
    double compute_instruction_num = 0.0;
    int shortcut_num = 0;

private:
    bitmap_t *fv_;		/* filter sketches */
    bitmap_t *sv_;		/* draft bit vector */
    m_area_t *area_;		/* interval table */
    WordUnit *area_val_;		
    PosWidth *area_pos_;		
    size_t *area_len_;		
    PosWidth *rv_;		/* position array */
    int * area_id_array_;
    size_t bmn_;		
    std::vector<WordUnit> virtual_value_space_;
    size_t value_num_;
    workloadFeature *workload_feature_;
    bool manual_configure = true;

    bitmap_t* sv1;
    bitmap_t* sv2;

    Column* column_;
    QueryQueue* query_;

    size_t group_;
    size_t code_num_;
    size_t volume_;
    size_t partition_num_; 
    size_t filter_v_num_; 
    size_t aligned_slot;
    double proportion_;
    size_t ndv_;    // number of distinct values

    size_t* positionSegArray;   // whether the segment has a position array 
                                // 0: interval without position array; 1: interval with position array
                                // 2: skew interval; 3: skew interval group

    SimdCompute* simd;

    std::vector<int> code_list_;

    std::vector<std::pair<WordUnit,size_t>> skewed_interval_group_values_;
    std::vector<std::pair<WordUnit,size_t>> skewed_interval_values_;

    void CreateIndex_baseline();
    void ParameterDetermination_baseline(workloadFeature* wf);
    void CreateIndex_sampling_beta();
    size_t total_popular_num_ = 0;

    void CabinRefineSV(void *sv_arg, PosWidth *rv_arg, size_t start, size_t end);

    void AreaID(WordUnit operand, size_t &area_id, op_class op);

    void OperandLocInSortedPosArray(WordUnit operand, size_t area_id, op_class op, PosWidth &position);

    void UpperOrLowerBound(bool &WaxWane, size_t &start, size_t &end, size_t area_id, PosWidth pos);

    void GenAreaMap();

    void CodeGen(size_t depth);
    inline size_t CodeGet(size_t x) { return code_list_[x];}
    
    size_t LoadNum(size_t depth, size_t x);

    void GenIndex();
    template<typename T>
    size_t BinarySearchLastOne(T *arr, size_t arr_size, T val);
    void GenIndexFromBaseData();
    void GenIndexFromBaseDataFixing();
    void GenIndexDataAware();
    void GenIndexFromPositionArrayByGroup();
    void GenBitmapIndex(size_t groupId);
    void GenIndexFromPositionArrayBySingleGroup(size_t groupId);

    void ScanPlan(WordUnit x_h, WordUnit x_l, op_class op);

    void ParameterDetermination(workloadFeature* wf);

    void SkewCandidate(double memoryBudget, size_t tupleNumber, std::map<WordUnit, size_t> &skew_value);
    void SkewCandidate_sampling(double memoryBudget, size_t tupleNumber, std::vector<WordUnit> &sampling_vec, std::map<WordUnit, size_t> &skew_value);

    void DataAwareInterval(size_t partition, size_t group, size_t tupleNumber, const std::map<WordUnit, size_t> &skew_value,
                      double &skewed_interval_group_prop, double &skewed_interval_prop, size_t &skewed_interval_group_num);

    void SetSkewedDataTable(size_t partition, size_t group, size_t tupleNumber, const std::map<WordUnit, size_t> &skew_value,
                       std::vector<std::pair<WordUnit,size_t>> &skewed_interval_group_values,
                       std::vector<std::pair<WordUnit,size_t>> &skewed_interval_values, double &skew_prop);

    bool ObtainNDV_baseline(size_t ndv_bound);

    void GenAreaMapDataAware();

    void SetSkewedDataTableNDV(std::vector<std::pair<WordUnit,size_t>> &skewed_interval_group_values);

    void CopyFv(int fvi, bool anti, bitmap_t *sv);

    void CabinGenFV(size_t area_id, bool anti, bool WaxWane, bitmap_t* sv);
    void GenTempResult_general(size_t group, size_t index, bool anti, bitmap_t* sv, \
                            __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                            bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address));
    void GenTempResult_2(size_t group, size_t index, bool anti, bitmap_t* sv);

    void CabinGenFV_cs(size_t area_id, bool anti, bitmap_t *sv, WordUnit x_h, WordUnit x_l);
    void GenTempResult_cs_general(size_t group, size_t index, bool anti, WordUnit x_h, WordUnit x_l, bitmap_t *sv,\
                                __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address));
    void GenTempResult_2_cs_le(size_t group, size_t index, bool anti, WordUnit x_h, bitmap_t *sv);

    void Cabinmerge(size_t aid1, size_t aid2, bool ww1, bool ww2, bool anti, bitmap_t *sv);
    void CabinGenFV_BETWEEN(size_t area_id_1, size_t area_id_2, bool WaxWane_1, bool WaxWane_2, bool anti, bitmap_t *sv);
    void GenTempResult_between_general(size_t group_1, size_t index_1, size_t group_2, size_t index_2, bool anti, bitmap_t *sv, \
                                __m256i* code_array, void (SimdCompute::*simd_compute_bt_le)(__m256i* codes), void (SimdCompute::*simd_compute_bt_ge)(__m256i* codes), \
                                void (SimdCompute::*simd_compute_ab_le)(__m256i* codes), void (SimdCompute::*simd_compute_ab_ge)(__m256i* codes), \
                                bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_bt_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_bt_ge)(bitmap_t* address),\
                                void (SimdCompute::*bitmap_compute_ab_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ab_ge)(bitmap_t* address));

    void CabinGenFV_cs_BETWEEN(size_t area_id_h, size_t area_id_l, bitmap_t *sv, WordUnit x_h, WordUnit x_l);
    void GenTempResult_cs_between_general(size_t area_id_h, size_t area_id_l, size_t group_h, size_t group_l, size_t indexInGroup_h, size_t indexInGroup_l, WordUnit x_h, WordUnit x_l, bitmap_t* sv,\
                                        __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                        bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address));

    void CabinGenFV_mix_BETWEEN(size_t area_id_h, size_t area_id_l, bitmap_t *sv, WordUnit x_h, WordUnit x_l, bool WaxWane, bool w_wo);
    void GenTempResult_mix_between_general(size_t area_id_h, size_t area_id_l,  size_t group_h, size_t group_l, size_t indexInGroup_h, size_t indexInGroup_l, WordUnit x_h, WordUnit x_l, bitmap_t* sv, bool WaxWane, bool w_wo,\
                                            __m256i* code_array, void (SimdCompute::*simd_compute_le)(__m256i* codes), void (SimdCompute::*simd_compute_ge)(__m256i* codes), \
                                            bitmap_t* bitmap_array, void (SimdCompute::*bitmap_compute_le)(bitmap_t* address), void (SimdCompute::*bitmap_compute_ge)(bitmap_t* address));
};

#endif //SCANCODE_CABIN_H
