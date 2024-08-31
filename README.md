# Cabin

Cabin is a promising scan index for main-memory analytical database that can achieve better time-space tradeoff than state-of-the-art scan solutions for the scan operations in-memory column stores. [[1]](#1)

This code repository provides a prototype  implement for Cabin and tested in 64-bit Ubuntu Server 20.04 and g++ 9.4 with optimization flag -O3 and SIMD flag -mavx, -mavx2, -mbmi1, -mbmi2.

## Build

```
#in the root directory of Cabin's repository
mkdir build && cd build
cmake ..
make -j4
```



## Tests

```
#in the root directory of Cabin's repository
cd bin

#case 1 (test Cabin with a secific selectivity (for example: 50%))
./Cabin -s 10000000 -p 0 -y 50 -a 0

#case 2 (test Cabin with 0~100% selectivities (step 0.1%))
./Cabin -s 10000000 -p 1 -a 0

#case 3 (test Cabin with a given query workload)
./Cabin -s 10000000 -p 2 -a 0

#case 4 (test Cabin with a given query workload and a specified space budget (for example: 0.0745GB))
./Cabin -s 10000000 -p 3 -a 0 -m 0.0745
```

You can also customize the test cases you want in the test.cpp and test.h files based on the relevant functions.



## Clarifications

1. Possible reasons of bugs:

   - test cases not currently covered.

   - test cases not currently implemented.

   - errors caused by differences in compilers, architectures, etc.

   - ...

2. The parameters are determined based on our own test machine and could vary on other devices.

   - The parameters for estimating performance in the optimal design algorithm.
   - The prefetch stride applied during the refinement of the middle result.

   

## References
<a id="1">[1]</a> Yiyuan Chen, Shimin Chen: Cabin: A Compressed Adaptive Binned Scan Index. Proc. ACM Manag. Data 2(1): 57:1-57:26 (2024)
