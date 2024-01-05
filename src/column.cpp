#include 	"column.h"

#include    <algorithm>
#include    <fstream>
#include    <iostream>
#include    <omp.h>
#include <cstring>
#include <set>

Column::Column(size_t num) :num_tuples_(num) {
    size_t alloc_size = CEILING((sizeof(WordUnit)*num_tuples_), cacheline_alignment) * cacheline_alignment;
    assert(alloc_size % cacheline_alignment == 0);
    array_ = (WordUnit*)(os_aligned_alloc(alloc_size, cacheline_alignment));
    assert((size_t)array_%cacheline_alignment == 0);
    memset(array_, 0, num_tuples_ * sizeof(WordUnit));
}

Column::~Column() {
	Destroy();
}

void Column::Destroy() {
    os_aligned_free(array_);
    array_ = nullptr;
}



