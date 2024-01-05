
#ifndef SCANCODE_QUERYQUEUE_H
#define SCANCODE_QUERYQUEUE_H

#include "column.h"
#include "types.h"
#include "configure.h"

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <random>


class QueryQueue {
public:
    QueryQueue();
    ~QueryQueue();

    void QuerySet(WordUnit x);

    std::vector<WordUnit> query;
    std::vector<WordUnit> query_l;
    std::vector<WordUnit> query_h;

    WordUnit QueryLook(size_t index);
    WordUnit QueryLook_l(size_t index);
    WordUnit QueryLook_h(size_t index);

    void QueryGenerate(Column *column, arg_t arg);

    size_t QuerySize() const {return query.size();};
    size_t QuerySize_l() const {return query_l.size();};
    size_t QuerySize_h() const {return query_h.size();};

    void QueryGenerateFromFile_l(std::string path);
    void QueryGenerateFromFile_h(std::string path);

    void QueryGenerateFromFile_int(std::string path);
    void QueryGenerateFromFile_float(std::string path);
    void QueryGenerateFromFile_double(std::string path);
};


#endif //SCANCODE_QUERYQUEUE_H
