#ifndef TYPES_H
#define TYPES_H

//#include "configure.h"
#include    <x86intrin.h>
#include    <cstdint>
#include    <iostream>
#include    <cinttypes>
#include <emmintrin.h>
#include <immintrin.h>
#include <sys/time.h>
#include <ctime>
#include <vector>

typedef int32_t WordUnit;
typedef uint32_t PosWidth;
typedef uint64_t bitmap_t;

#define CEILING(x,y) (((x) + (y) - 1) / (y))

#define LONGLINE "**------------------**"

#define BITMAPWIDTH (sizeof(bitmap_t) << 3) //64 bit
#define SIMDWIDTH 256 // bit
#define cacheline_alignment 64 //64 bytes



 /**
  * op_le = 0,	v <= vh
  * op_ge,      v >= vl
  * op_bt,		(v >= vl && v <= vh)
  * op_ab,		(v <= vl || v >= vh)
 */
enum op_class {op_le, op_ge, op_bt, op_ab};

enum algorithm {cabin};

typedef struct arg_t {
    size_t      size    = 10000000;
    double      selectivity = 50;  //0~100
    size_t      repeat  = 1;
    algorithm   algo = cabin;
    size_t      patch_type = 6;
    size_t      patch_num = 1000; // patch = 10 means selectivity = 0, 10%, 20%, ... 100%; patch = 100 means selectivity = 0, 1%, 2%, ... 100%
    double      available_memory = 7.450580597/100;   // GB
} arg_t;

typedef struct workloadFeature {
    double      available_memory;
} workloadFeature;

#endif //TYPES_H