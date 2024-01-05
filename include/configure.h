
#ifndef SCANCODE_CONFIGURE_H
#define SCANCODE_CONFIGURE_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define os_aligned_alloc(size, alignment) _aligned_malloc((size), (alignment))
    #define os_aligned_free(pointer) _aligned_free(pointer)
#elif __linux__
    #define os_aligned_alloc(size, alignment) aligned_alloc((alignment), (size))
    #define os_aligned_free(pointer) free(pointer)
#endif


#define TIME_ANALYSIS 1
//#define PRINT_AUXILIARY_INFO 1
//#define CREATE_INFO 1
//#define CREATEINDEX_BETA
#define CREATEINDEX_BASELINE

#define TEST_TYPE 0

#define PRINT_EXCECUTION_TIME(msg, code)                                       \
  do {                                                                         \
    struct timeval t1, t2;                                                     \
    double elapsed;                                                            \
    gettimeofday(&t1, NULL);                                                   \
    do {                                                                       \
      code;                                                                    \
    } while (0);                                                               \
    gettimeofday(&t2, NULL);                                                   \
    elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;                                \
    elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;                             \
    printf(msg " time: %f ms\n", elapsed);                                     \
  } while (0);

#define EXCECUTION_TIME_ACC(msg, code, time)                              \
  do {                                                                         \
    struct timeval t1, t2;                                                     \
    double elapsed;                                                            \
    gettimeofday(&t1, NULL);                                                   \
    do {                                                                       \
      code;                                                                    \
    } while (0);                                                               \
    gettimeofday(&t2, NULL);                                                   \
    time += (t2.tv_sec - t1.tv_sec) * 1000.0;                                \
    time += (t2.tv_usec - t1.tv_usec) / 1000.0;                             \
    } while(0);

#endif //SCANCODE_CONFIGURE_H
