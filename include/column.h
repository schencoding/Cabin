#ifndef COLUMN_H
#define COLUMN_H


#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>

#include "types.h"
#include "configure.h"

class Column{
public:
    Column(size_t num=0);
    ~Column();
    void Destroy();

    WordUnit GetTuple(size_t id) const;
    void SetTuple(size_t id, WordUnit value) const;

    size_t GetNumTuples() const { return num_tuples_;}

    WordUnit * array_;

    size_t num_tuples_;
};

inline WordUnit Column::GetTuple(size_t id) const {
    return array_[id];
}

inline void Column::SetTuple(size_t id, WordUnit value) const {
    array_[id] = value;
}

#endif  //COLUMN_H
