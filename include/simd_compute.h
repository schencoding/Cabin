
#ifndef SCANCODE_SIMD_COMPUTE_H
#define SCANCODE_SIMD_COMPUTE_H

#include "types.h"

class SimdCompute {
public:
    SimdCompute();

    static __m256i MinusOne;
    __m256i tmp;
    bitmap_t tmp_bm;

    void (SimdCompute::*SIMD256_COMPUTE_CN4[15])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN4[15])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN4[15])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN4[15])(bitmap_t* address);

    void (SimdCompute::*SIMD256_COMPUTE_CN3[7])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN3[7])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN3[7])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN3[7])(bitmap_t* address);

    void (SimdCompute::*SIMD256_COMPUTE_CN6[63])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN6[63])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN6[63])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN6[63])(bitmap_t* address);

    void (SimdCompute::*SIMD256_COMPUTE_CN5[31])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN5[31])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN5[31])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN5[31])(bitmap_t* address);

    void (SimdCompute::*SIMD256_COMPUTE_CN7[127])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN7[127])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN7[127])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN7[127])(bitmap_t* address);

    void (SimdCompute::*SIMD256_COMPUTE_CN8[255])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN8[255])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN8[255])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN8[255])(bitmap_t* address);

    void (SimdCompute::*SIMD256_COMPUTE_CN9[511])(__m256i* codes);
    void (SimdCompute::*SIMD256_COMPUTEa_CN9[511])(__m256i* codes);

    void (SimdCompute::*BITMAP_COMPUTE_CN9[511])(bitmap_t* address);
    void (SimdCompute::*BITMAP_COMPUTEa_CN9[511])(bitmap_t* address);

    void SIMD256_COMPUTE_CN3_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN3_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN3_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN3_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN3_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN3_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN3_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN3_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN3_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN3_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No7(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No7(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No8(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No8(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No9(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No9(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No10(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No10(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No11(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No11(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No12(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No12(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No13(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No13(bitmap_t* bm);

    void SIMD256_COMPUTE_CN4_No14(__m256i* codes);
    void BITMAP_COMPUTE_CN4_No14(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No7(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No7(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No8(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No8(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No9(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No9(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No10(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No10(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No11(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No11(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No12(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No12(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No13(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No13(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN4_No14(__m256i* codes);
    void BITMAP_COMPUTEa_CN4_No14(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No7(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No7(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No8(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No8(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No9(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No9(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No10(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No10(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No11(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No11(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No12(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No12(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No13(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No13(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No14(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No14(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No15(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No15(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No16(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No16(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No17(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No17(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No18(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No18(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No19(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No19(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No20(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No20(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No21(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No21(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No22(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No22(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No23(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No23(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No24(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No24(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No25(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No25(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No26(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No26(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No27(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No27(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No28(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No28(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No29(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No29(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No30(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No30(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No31(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No31(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No32(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No32(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No33(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No33(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No34(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No34(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No35(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No35(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No36(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No36(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No37(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No37(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No38(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No38(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No39(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No39(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No40(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No40(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No41(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No41(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No42(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No42(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No43(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No43(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No44(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No44(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No45(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No45(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No46(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No46(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No47(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No47(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No48(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No48(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No49(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No49(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No50(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No50(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No51(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No51(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No52(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No52(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No53(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No53(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No54(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No54(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No55(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No55(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No56(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No56(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No57(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No57(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No58(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No58(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No59(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No59(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No60(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No60(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No61(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No61(bitmap_t* bm);

    void SIMD256_COMPUTE_CN6_No62(__m256i* codes);
    void BITMAP_COMPUTE_CN6_No62(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No7(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No7(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No8(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No8(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No9(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No9(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No10(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No10(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No11(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No11(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No12(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No12(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No13(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No13(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No14(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No14(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No15(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No15(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No16(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No16(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No17(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No17(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No18(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No18(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No19(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No19(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No20(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No20(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No21(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No21(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No22(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No22(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No23(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No23(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No24(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No24(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No25(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No25(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No26(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No26(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No27(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No27(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No28(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No28(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No29(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No29(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No30(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No30(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No31(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No31(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No32(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No32(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No33(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No33(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No34(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No34(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No35(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No35(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No36(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No36(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No37(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No37(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No38(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No38(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No39(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No39(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No40(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No40(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No41(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No41(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No42(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No42(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No43(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No43(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No44(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No44(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No45(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No45(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No46(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No46(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No47(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No47(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No48(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No48(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No49(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No49(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No50(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No50(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No51(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No51(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No52(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No52(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No53(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No53(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No54(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No54(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No55(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No55(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No56(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No56(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No57(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No57(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No58(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No58(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No59(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No59(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No60(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No60(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No61(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No61(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN6_No62(__m256i* codes);
    void BITMAP_COMPUTEa_CN6_No62(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No7(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No7(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No8(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No8(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No9(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No9(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No10(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No10(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No11(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No11(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No12(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No12(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No13(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No13(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No14(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No14(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No15(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No15(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No16(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No16(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No17(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No17(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No18(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No18(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No19(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No19(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No20(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No20(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No21(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No21(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No22(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No22(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No23(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No23(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No24(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No24(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No25(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No25(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No26(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No26(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No27(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No27(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No28(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No28(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No29(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No29(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN5_No30(__m256i* codes);
    void BITMAP_COMPUTEa_CN5_No30(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No7(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No7(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No8(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No8(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No9(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No9(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No10(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No10(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No11(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No11(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No12(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No12(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No13(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No13(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No14(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No14(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No15(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No15(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No16(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No16(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No17(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No17(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No18(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No18(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No19(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No19(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No20(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No20(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No21(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No21(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No22(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No22(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No23(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No23(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No24(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No24(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No25(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No25(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No26(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No26(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No27(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No27(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No28(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No28(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No29(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No29(bitmap_t* bm);

    void SIMD256_COMPUTE_CN5_No30(__m256i* codes);
    void BITMAP_COMPUTE_CN5_No30(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No7(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No7(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No8(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No8(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No9(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No9(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No10(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No10(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No11(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No11(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No12(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No12(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No13(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No13(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No14(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No14(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No15(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No15(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No16(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No16(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No17(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No17(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No18(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No18(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No19(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No19(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No20(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No20(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No21(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No21(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No22(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No22(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No23(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No23(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No24(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No24(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No25(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No25(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No26(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No26(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No27(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No27(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No28(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No28(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No29(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No29(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No30(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No30(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No31(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No31(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No32(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No32(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No33(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No33(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No34(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No34(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No35(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No35(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No36(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No36(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No37(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No37(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No38(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No38(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No39(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No39(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No40(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No40(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No41(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No41(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No42(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No42(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No43(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No43(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No44(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No44(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No45(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No45(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No46(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No46(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No47(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No47(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No48(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No48(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No49(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No49(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No50(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No50(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No51(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No51(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No52(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No52(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No53(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No53(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No54(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No54(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No55(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No55(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No56(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No56(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No57(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No57(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No58(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No58(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No59(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No59(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No60(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No60(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No61(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No61(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No62(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No62(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No63(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No63(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No64(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No64(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No65(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No65(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No66(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No66(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No67(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No67(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No68(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No68(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No69(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No69(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No70(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No70(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No71(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No71(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No72(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No72(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No73(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No73(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No74(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No74(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No75(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No75(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No76(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No76(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No77(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No77(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No78(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No78(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No79(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No79(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No80(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No80(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No81(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No81(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No82(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No82(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No83(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No83(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No84(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No84(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No85(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No85(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No86(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No86(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No87(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No87(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No88(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No88(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No89(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No89(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No90(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No90(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No91(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No91(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No92(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No92(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No93(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No93(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No94(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No94(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No95(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No95(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No96(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No96(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No97(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No97(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No98(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No98(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No99(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No99(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No100(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No100(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No101(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No101(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No102(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No102(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No103(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No103(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No104(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No104(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No105(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No105(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No106(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No106(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No107(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No107(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No108(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No108(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No109(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No109(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No110(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No110(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No111(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No111(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No112(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No112(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No113(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No113(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No114(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No114(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No115(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No115(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No116(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No116(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No117(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No117(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No118(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No118(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No119(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No119(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No120(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No120(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No121(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No121(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No122(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No122(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No123(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No123(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No124(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No124(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No125(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No125(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN7_No126(__m256i* codes);
    void BITMAP_COMPUTEa_CN7_No126(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No7(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No7(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No8(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No8(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No9(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No9(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No10(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No10(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No11(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No11(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No12(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No12(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No13(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No13(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No14(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No14(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No15(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No15(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No16(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No16(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No17(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No17(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No18(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No18(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No19(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No19(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No20(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No20(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No21(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No21(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No22(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No22(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No23(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No23(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No24(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No24(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No25(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No25(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No26(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No26(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No27(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No27(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No28(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No28(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No29(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No29(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No30(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No30(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No31(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No31(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No32(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No32(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No33(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No33(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No34(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No34(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No35(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No35(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No36(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No36(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No37(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No37(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No38(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No38(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No39(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No39(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No40(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No40(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No41(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No41(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No42(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No42(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No43(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No43(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No44(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No44(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No45(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No45(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No46(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No46(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No47(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No47(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No48(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No48(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No49(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No49(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No50(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No50(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No51(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No51(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No52(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No52(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No53(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No53(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No54(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No54(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No55(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No55(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No56(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No56(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No57(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No57(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No58(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No58(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No59(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No59(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No60(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No60(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No61(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No61(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No62(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No62(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No63(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No63(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No64(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No64(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No65(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No65(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No66(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No66(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No67(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No67(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No68(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No68(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No69(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No69(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No70(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No70(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No71(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No71(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No72(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No72(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No73(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No73(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No74(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No74(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No75(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No75(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No76(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No76(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No77(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No77(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No78(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No78(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No79(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No79(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No80(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No80(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No81(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No81(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No82(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No82(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No83(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No83(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No84(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No84(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No85(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No85(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No86(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No86(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No87(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No87(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No88(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No88(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No89(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No89(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No90(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No90(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No91(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No91(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No92(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No92(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No93(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No93(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No94(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No94(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No95(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No95(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No96(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No96(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No97(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No97(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No98(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No98(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No99(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No99(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No100(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No100(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No101(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No101(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No102(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No102(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No103(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No103(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No104(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No104(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No105(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No105(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No106(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No106(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No107(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No107(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No108(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No108(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No109(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No109(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No110(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No110(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No111(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No111(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No112(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No112(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No113(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No113(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No114(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No114(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No115(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No115(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No116(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No116(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No117(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No117(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No118(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No118(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No119(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No119(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No120(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No120(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No121(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No121(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No122(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No122(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No123(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No123(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No124(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No124(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No125(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No125(bitmap_t* bm);

    void SIMD256_COMPUTE_CN7_No126(__m256i* codes);
    void BITMAP_COMPUTE_CN7_No126(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No7(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No7(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No8(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No8(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No9(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No9(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No10(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No10(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No11(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No11(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No12(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No12(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No13(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No13(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No14(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No14(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No15(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No15(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No16(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No16(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No17(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No17(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No18(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No18(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No19(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No19(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No20(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No20(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No21(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No21(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No22(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No22(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No23(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No23(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No24(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No24(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No25(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No25(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No26(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No26(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No27(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No27(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No28(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No28(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No29(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No29(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No30(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No30(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No31(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No31(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No32(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No32(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No33(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No33(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No34(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No34(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No35(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No35(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No36(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No36(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No37(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No37(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No38(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No38(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No39(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No39(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No40(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No40(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No41(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No41(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No42(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No42(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No43(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No43(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No44(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No44(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No45(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No45(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No46(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No46(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No47(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No47(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No48(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No48(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No49(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No49(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No50(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No50(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No51(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No51(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No52(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No52(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No53(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No53(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No54(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No54(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No55(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No55(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No56(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No56(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No57(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No57(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No58(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No58(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No59(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No59(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No60(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No60(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No61(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No61(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No62(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No62(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No63(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No63(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No64(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No64(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No65(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No65(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No66(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No66(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No67(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No67(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No68(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No68(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No69(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No69(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No70(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No70(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No71(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No71(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No72(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No72(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No73(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No73(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No74(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No74(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No75(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No75(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No76(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No76(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No77(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No77(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No78(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No78(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No79(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No79(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No80(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No80(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No81(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No81(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No82(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No82(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No83(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No83(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No84(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No84(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No85(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No85(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No86(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No86(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No87(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No87(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No88(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No88(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No89(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No89(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No90(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No90(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No91(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No91(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No92(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No92(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No93(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No93(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No94(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No94(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No95(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No95(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No96(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No96(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No97(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No97(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No98(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No98(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No99(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No99(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No100(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No100(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No101(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No101(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No102(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No102(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No103(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No103(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No104(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No104(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No105(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No105(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No106(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No106(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No107(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No107(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No108(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No108(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No109(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No109(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No110(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No110(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No111(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No111(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No112(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No112(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No113(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No113(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No114(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No114(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No115(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No115(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No116(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No116(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No117(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No117(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No118(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No118(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No119(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No119(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No120(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No120(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No121(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No121(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No122(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No122(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No123(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No123(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No124(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No124(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No125(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No125(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No126(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No126(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No127(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No127(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No128(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No128(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No129(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No129(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No130(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No130(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No131(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No131(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No132(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No132(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No133(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No133(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No134(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No134(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No135(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No135(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No136(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No136(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No137(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No137(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No138(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No138(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No139(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No139(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No140(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No140(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No141(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No141(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No142(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No142(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No143(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No143(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No144(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No144(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No145(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No145(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No146(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No146(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No147(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No147(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No148(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No148(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No149(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No149(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No150(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No150(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No151(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No151(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No152(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No152(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No153(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No153(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No154(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No154(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No155(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No155(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No156(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No156(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No157(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No157(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No158(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No158(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No159(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No159(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No160(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No160(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No161(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No161(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No162(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No162(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No163(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No163(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No164(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No164(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No165(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No165(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No166(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No166(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No167(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No167(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No168(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No168(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No169(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No169(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No170(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No170(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No171(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No171(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No172(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No172(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No173(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No173(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No174(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No174(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No175(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No175(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No176(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No176(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No177(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No177(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No178(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No178(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No179(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No179(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No180(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No180(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No181(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No181(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No182(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No182(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No183(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No183(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No184(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No184(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No185(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No185(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No186(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No186(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No187(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No187(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No188(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No188(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No189(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No189(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No190(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No190(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No191(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No191(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No192(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No192(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No193(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No193(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No194(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No194(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No195(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No195(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No196(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No196(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No197(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No197(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No198(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No198(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No199(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No199(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No200(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No200(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No201(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No201(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No202(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No202(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No203(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No203(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No204(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No204(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No205(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No205(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No206(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No206(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No207(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No207(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No208(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No208(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No209(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No209(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No210(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No210(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No211(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No211(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No212(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No212(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No213(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No213(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No214(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No214(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No215(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No215(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No216(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No216(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No217(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No217(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No218(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No218(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No219(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No219(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No220(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No220(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No221(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No221(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No222(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No222(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No223(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No223(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No224(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No224(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No225(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No225(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No226(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No226(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No227(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No227(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No228(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No228(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No229(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No229(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No230(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No230(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No231(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No231(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No232(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No232(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No233(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No233(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No234(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No234(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No235(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No235(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No236(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No236(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No237(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No237(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No238(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No238(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No239(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No239(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No240(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No240(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No241(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No241(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No242(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No242(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No243(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No243(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No244(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No244(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No245(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No245(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No246(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No246(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No247(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No247(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No248(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No248(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No249(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No249(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No250(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No250(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No251(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No251(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No252(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No252(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No253(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No253(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN8_No254(__m256i* codes);
    void BITMAP_COMPUTEa_CN8_No254(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No7(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No7(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No8(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No8(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No9(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No9(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No10(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No10(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No11(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No11(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No12(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No12(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No13(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No13(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No14(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No14(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No15(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No15(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No16(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No16(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No17(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No17(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No18(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No18(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No19(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No19(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No20(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No20(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No21(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No21(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No22(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No22(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No23(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No23(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No24(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No24(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No25(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No25(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No26(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No26(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No27(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No27(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No28(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No28(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No29(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No29(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No30(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No30(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No31(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No31(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No32(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No32(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No33(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No33(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No34(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No34(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No35(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No35(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No36(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No36(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No37(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No37(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No38(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No38(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No39(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No39(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No40(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No40(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No41(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No41(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No42(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No42(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No43(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No43(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No44(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No44(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No45(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No45(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No46(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No46(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No47(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No47(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No48(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No48(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No49(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No49(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No50(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No50(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No51(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No51(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No52(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No52(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No53(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No53(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No54(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No54(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No55(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No55(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No56(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No56(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No57(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No57(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No58(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No58(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No59(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No59(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No60(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No60(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No61(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No61(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No62(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No62(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No63(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No63(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No64(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No64(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No65(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No65(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No66(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No66(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No67(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No67(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No68(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No68(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No69(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No69(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No70(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No70(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No71(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No71(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No72(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No72(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No73(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No73(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No74(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No74(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No75(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No75(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No76(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No76(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No77(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No77(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No78(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No78(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No79(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No79(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No80(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No80(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No81(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No81(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No82(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No82(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No83(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No83(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No84(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No84(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No85(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No85(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No86(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No86(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No87(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No87(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No88(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No88(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No89(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No89(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No90(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No90(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No91(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No91(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No92(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No92(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No93(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No93(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No94(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No94(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No95(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No95(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No96(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No96(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No97(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No97(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No98(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No98(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No99(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No99(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No100(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No100(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No101(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No101(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No102(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No102(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No103(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No103(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No104(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No104(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No105(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No105(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No106(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No106(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No107(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No107(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No108(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No108(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No109(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No109(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No110(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No110(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No111(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No111(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No112(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No112(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No113(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No113(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No114(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No114(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No115(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No115(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No116(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No116(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No117(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No117(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No118(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No118(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No119(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No119(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No120(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No120(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No121(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No121(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No122(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No122(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No123(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No123(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No124(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No124(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No125(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No125(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No126(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No126(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No127(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No127(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No128(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No128(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No129(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No129(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No130(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No130(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No131(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No131(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No132(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No132(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No133(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No133(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No134(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No134(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No135(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No135(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No136(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No136(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No137(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No137(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No138(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No138(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No139(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No139(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No140(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No140(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No141(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No141(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No142(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No142(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No143(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No143(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No144(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No144(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No145(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No145(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No146(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No146(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No147(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No147(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No148(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No148(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No149(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No149(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No150(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No150(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No151(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No151(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No152(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No152(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No153(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No153(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No154(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No154(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No155(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No155(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No156(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No156(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No157(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No157(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No158(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No158(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No159(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No159(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No160(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No160(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No161(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No161(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No162(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No162(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No163(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No163(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No164(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No164(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No165(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No165(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No166(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No166(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No167(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No167(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No168(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No168(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No169(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No169(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No170(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No170(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No171(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No171(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No172(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No172(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No173(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No173(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No174(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No174(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No175(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No175(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No176(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No176(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No177(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No177(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No178(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No178(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No179(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No179(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No180(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No180(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No181(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No181(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No182(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No182(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No183(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No183(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No184(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No184(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No185(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No185(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No186(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No186(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No187(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No187(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No188(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No188(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No189(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No189(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No190(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No190(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No191(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No191(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No192(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No192(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No193(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No193(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No194(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No194(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No195(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No195(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No196(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No196(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No197(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No197(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No198(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No198(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No199(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No199(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No200(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No200(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No201(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No201(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No202(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No202(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No203(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No203(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No204(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No204(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No205(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No205(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No206(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No206(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No207(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No207(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No208(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No208(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No209(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No209(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No210(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No210(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No211(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No211(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No212(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No212(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No213(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No213(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No214(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No214(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No215(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No215(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No216(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No216(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No217(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No217(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No218(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No218(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No219(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No219(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No220(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No220(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No221(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No221(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No222(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No222(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No223(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No223(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No224(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No224(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No225(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No225(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No226(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No226(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No227(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No227(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No228(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No228(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No229(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No229(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No230(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No230(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No231(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No231(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No232(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No232(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No233(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No233(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No234(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No234(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No235(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No235(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No236(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No236(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No237(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No237(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No238(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No238(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No239(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No239(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No240(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No240(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No241(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No241(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No242(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No242(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No243(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No243(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No244(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No244(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No245(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No245(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No246(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No246(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No247(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No247(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No248(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No248(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No249(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No249(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No250(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No250(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No251(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No251(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No252(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No252(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No253(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No253(bitmap_t* bm);

    void SIMD256_COMPUTE_CN8_No254(__m256i* codes);
    void BITMAP_COMPUTE_CN8_No254(bitmap_t* bm);


    void SIMD256_COMPUTE_CN9_No0(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No0(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No1(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No1(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No2(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No2(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No3(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No3(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No4(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No4(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No5(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No5(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No6(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No6(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No7(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No7(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No8(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No8(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No9(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No9(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No10(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No10(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No11(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No11(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No12(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No12(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No13(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No13(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No14(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No14(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No15(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No15(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No16(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No16(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No17(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No17(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No18(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No18(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No19(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No19(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No20(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No20(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No21(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No21(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No22(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No22(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No23(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No23(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No24(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No24(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No25(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No25(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No26(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No26(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No27(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No27(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No28(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No28(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No29(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No29(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No30(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No30(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No31(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No31(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No32(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No32(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No33(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No33(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No34(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No34(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No35(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No35(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No36(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No36(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No37(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No37(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No38(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No38(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No39(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No39(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No40(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No40(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No41(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No41(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No42(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No42(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No43(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No43(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No44(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No44(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No45(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No45(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No46(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No46(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No47(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No47(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No48(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No48(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No49(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No49(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No50(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No50(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No51(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No51(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No52(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No52(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No53(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No53(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No54(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No54(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No55(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No55(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No56(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No56(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No57(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No57(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No58(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No58(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No59(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No59(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No60(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No60(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No61(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No61(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No62(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No62(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No63(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No63(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No64(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No64(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No65(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No65(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No66(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No66(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No67(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No67(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No68(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No68(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No69(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No69(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No70(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No70(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No71(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No71(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No72(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No72(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No73(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No73(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No74(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No74(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No75(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No75(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No76(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No76(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No77(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No77(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No78(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No78(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No79(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No79(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No80(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No80(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No81(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No81(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No82(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No82(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No83(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No83(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No84(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No84(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No85(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No85(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No86(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No86(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No87(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No87(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No88(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No88(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No89(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No89(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No90(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No90(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No91(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No91(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No92(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No92(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No93(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No93(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No94(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No94(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No95(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No95(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No96(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No96(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No97(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No97(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No98(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No98(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No99(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No99(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No100(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No100(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No101(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No101(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No102(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No102(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No103(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No103(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No104(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No104(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No105(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No105(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No106(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No106(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No107(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No107(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No108(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No108(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No109(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No109(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No110(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No110(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No111(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No111(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No112(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No112(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No113(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No113(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No114(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No114(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No115(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No115(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No116(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No116(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No117(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No117(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No118(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No118(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No119(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No119(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No120(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No120(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No121(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No121(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No122(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No122(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No123(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No123(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No124(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No124(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No125(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No125(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No126(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No126(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No127(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No127(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No128(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No128(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No129(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No129(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No130(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No130(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No131(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No131(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No132(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No132(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No133(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No133(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No134(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No134(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No135(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No135(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No136(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No136(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No137(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No137(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No138(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No138(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No139(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No139(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No140(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No140(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No141(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No141(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No142(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No142(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No143(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No143(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No144(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No144(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No145(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No145(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No146(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No146(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No147(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No147(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No148(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No148(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No149(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No149(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No150(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No150(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No151(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No151(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No152(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No152(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No153(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No153(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No154(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No154(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No155(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No155(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No156(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No156(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No157(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No157(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No158(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No158(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No159(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No159(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No160(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No160(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No161(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No161(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No162(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No162(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No163(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No163(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No164(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No164(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No165(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No165(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No166(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No166(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No167(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No167(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No168(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No168(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No169(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No169(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No170(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No170(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No171(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No171(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No172(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No172(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No173(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No173(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No174(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No174(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No175(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No175(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No176(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No176(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No177(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No177(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No178(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No178(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No179(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No179(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No180(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No180(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No181(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No181(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No182(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No182(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No183(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No183(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No184(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No184(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No185(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No185(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No186(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No186(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No187(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No187(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No188(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No188(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No189(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No189(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No190(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No190(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No191(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No191(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No192(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No192(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No193(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No193(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No194(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No194(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No195(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No195(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No196(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No196(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No197(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No197(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No198(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No198(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No199(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No199(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No200(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No200(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No201(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No201(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No202(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No202(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No203(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No203(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No204(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No204(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No205(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No205(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No206(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No206(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No207(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No207(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No208(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No208(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No209(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No209(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No210(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No210(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No211(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No211(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No212(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No212(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No213(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No213(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No214(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No214(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No215(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No215(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No216(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No216(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No217(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No217(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No218(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No218(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No219(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No219(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No220(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No220(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No221(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No221(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No222(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No222(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No223(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No223(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No224(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No224(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No225(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No225(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No226(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No226(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No227(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No227(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No228(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No228(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No229(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No229(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No230(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No230(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No231(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No231(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No232(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No232(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No233(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No233(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No234(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No234(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No235(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No235(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No236(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No236(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No237(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No237(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No238(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No238(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No239(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No239(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No240(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No240(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No241(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No241(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No242(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No242(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No243(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No243(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No244(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No244(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No245(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No245(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No246(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No246(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No247(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No247(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No248(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No248(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No249(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No249(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No250(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No250(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No251(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No251(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No252(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No252(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No253(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No253(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No254(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No254(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No255(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No255(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No256(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No256(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No257(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No257(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No258(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No258(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No259(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No259(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No260(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No260(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No261(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No261(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No262(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No262(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No263(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No263(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No264(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No264(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No265(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No265(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No266(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No266(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No267(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No267(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No268(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No268(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No269(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No269(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No270(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No270(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No271(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No271(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No272(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No272(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No273(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No273(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No274(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No274(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No275(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No275(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No276(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No276(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No277(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No277(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No278(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No278(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No279(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No279(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No280(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No280(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No281(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No281(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No282(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No282(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No283(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No283(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No284(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No284(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No285(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No285(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No286(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No286(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No287(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No287(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No288(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No288(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No289(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No289(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No290(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No290(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No291(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No291(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No292(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No292(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No293(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No293(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No294(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No294(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No295(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No295(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No296(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No296(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No297(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No297(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No298(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No298(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No299(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No299(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No300(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No300(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No301(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No301(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No302(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No302(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No303(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No303(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No304(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No304(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No305(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No305(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No306(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No306(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No307(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No307(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No308(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No308(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No309(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No309(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No310(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No310(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No311(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No311(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No312(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No312(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No313(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No313(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No314(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No314(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No315(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No315(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No316(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No316(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No317(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No317(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No318(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No318(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No319(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No319(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No320(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No320(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No321(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No321(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No322(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No322(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No323(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No323(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No324(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No324(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No325(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No325(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No326(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No326(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No327(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No327(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No328(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No328(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No329(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No329(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No330(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No330(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No331(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No331(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No332(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No332(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No333(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No333(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No334(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No334(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No335(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No335(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No336(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No336(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No337(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No337(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No338(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No338(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No339(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No339(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No340(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No340(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No341(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No341(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No342(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No342(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No343(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No343(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No344(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No344(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No345(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No345(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No346(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No346(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No347(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No347(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No348(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No348(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No349(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No349(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No350(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No350(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No351(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No351(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No352(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No352(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No353(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No353(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No354(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No354(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No355(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No355(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No356(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No356(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No357(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No357(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No358(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No358(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No359(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No359(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No360(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No360(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No361(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No361(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No362(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No362(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No363(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No363(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No364(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No364(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No365(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No365(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No366(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No366(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No367(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No367(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No368(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No368(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No369(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No369(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No370(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No370(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No371(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No371(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No372(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No372(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No373(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No373(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No374(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No374(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No375(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No375(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No376(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No376(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No377(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No377(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No378(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No378(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No379(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No379(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No380(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No380(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No381(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No381(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No382(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No382(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No383(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No383(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No384(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No384(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No385(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No385(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No386(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No386(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No387(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No387(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No388(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No388(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No389(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No389(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No390(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No390(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No391(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No391(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No392(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No392(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No393(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No393(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No394(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No394(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No395(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No395(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No396(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No396(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No397(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No397(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No398(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No398(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No399(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No399(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No400(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No400(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No401(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No401(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No402(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No402(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No403(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No403(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No404(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No404(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No405(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No405(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No406(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No406(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No407(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No407(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No408(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No408(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No409(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No409(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No410(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No410(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No411(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No411(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No412(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No412(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No413(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No413(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No414(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No414(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No415(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No415(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No416(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No416(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No417(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No417(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No418(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No418(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No419(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No419(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No420(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No420(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No421(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No421(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No422(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No422(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No423(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No423(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No424(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No424(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No425(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No425(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No426(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No426(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No427(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No427(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No428(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No428(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No429(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No429(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No430(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No430(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No431(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No431(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No432(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No432(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No433(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No433(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No434(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No434(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No435(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No435(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No436(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No436(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No437(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No437(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No438(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No438(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No439(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No439(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No440(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No440(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No441(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No441(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No442(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No442(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No443(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No443(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No444(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No444(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No445(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No445(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No446(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No446(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No447(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No447(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No448(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No448(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No449(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No449(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No450(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No450(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No451(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No451(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No452(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No452(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No453(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No453(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No454(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No454(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No455(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No455(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No456(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No456(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No457(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No457(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No458(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No458(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No459(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No459(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No460(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No460(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No461(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No461(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No462(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No462(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No463(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No463(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No464(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No464(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No465(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No465(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No466(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No466(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No467(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No467(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No468(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No468(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No469(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No469(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No470(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No470(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No471(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No471(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No472(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No472(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No473(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No473(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No474(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No474(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No475(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No475(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No476(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No476(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No477(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No477(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No478(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No478(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No479(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No479(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No480(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No480(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No481(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No481(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No482(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No482(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No483(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No483(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No484(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No484(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No485(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No485(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No486(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No486(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No487(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No487(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No488(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No488(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No489(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No489(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No490(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No490(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No491(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No491(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No492(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No492(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No493(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No493(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No494(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No494(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No495(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No495(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No496(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No496(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No497(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No497(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No498(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No498(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No499(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No499(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No500(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No500(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No501(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No501(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No502(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No502(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No503(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No503(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No504(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No504(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No505(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No505(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No506(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No506(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No507(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No507(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No508(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No508(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No509(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No509(bitmap_t* bm);

    void SIMD256_COMPUTE_CN9_No510(__m256i* codes);
    void BITMAP_COMPUTE_CN9_No510(bitmap_t* bm);


    void SIMD256_COMPUTEa_CN9_No0(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No0(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No1(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No1(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No2(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No2(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No3(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No3(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No4(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No4(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No5(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No5(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No6(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No6(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No7(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No7(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No8(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No8(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No9(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No9(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No10(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No10(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No11(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No11(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No12(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No12(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No13(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No13(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No14(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No14(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No15(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No15(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No16(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No16(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No17(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No17(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No18(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No18(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No19(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No19(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No20(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No20(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No21(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No21(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No22(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No22(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No23(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No23(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No24(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No24(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No25(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No25(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No26(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No26(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No27(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No27(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No28(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No28(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No29(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No29(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No30(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No30(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No31(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No31(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No32(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No32(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No33(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No33(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No34(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No34(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No35(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No35(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No36(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No36(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No37(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No37(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No38(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No38(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No39(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No39(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No40(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No40(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No41(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No41(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No42(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No42(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No43(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No43(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No44(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No44(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No45(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No45(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No46(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No46(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No47(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No47(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No48(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No48(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No49(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No49(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No50(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No50(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No51(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No51(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No52(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No52(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No53(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No53(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No54(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No54(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No55(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No55(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No56(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No56(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No57(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No57(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No58(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No58(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No59(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No59(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No60(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No60(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No61(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No61(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No62(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No62(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No63(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No63(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No64(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No64(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No65(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No65(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No66(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No66(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No67(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No67(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No68(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No68(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No69(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No69(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No70(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No70(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No71(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No71(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No72(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No72(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No73(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No73(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No74(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No74(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No75(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No75(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No76(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No76(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No77(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No77(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No78(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No78(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No79(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No79(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No80(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No80(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No81(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No81(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No82(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No82(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No83(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No83(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No84(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No84(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No85(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No85(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No86(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No86(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No87(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No87(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No88(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No88(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No89(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No89(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No90(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No90(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No91(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No91(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No92(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No92(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No93(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No93(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No94(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No94(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No95(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No95(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No96(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No96(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No97(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No97(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No98(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No98(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No99(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No99(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No100(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No100(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No101(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No101(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No102(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No102(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No103(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No103(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No104(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No104(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No105(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No105(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No106(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No106(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No107(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No107(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No108(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No108(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No109(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No109(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No110(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No110(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No111(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No111(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No112(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No112(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No113(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No113(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No114(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No114(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No115(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No115(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No116(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No116(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No117(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No117(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No118(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No118(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No119(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No119(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No120(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No120(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No121(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No121(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No122(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No122(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No123(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No123(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No124(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No124(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No125(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No125(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No126(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No126(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No127(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No127(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No128(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No128(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No129(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No129(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No130(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No130(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No131(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No131(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No132(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No132(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No133(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No133(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No134(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No134(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No135(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No135(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No136(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No136(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No137(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No137(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No138(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No138(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No139(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No139(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No140(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No140(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No141(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No141(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No142(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No142(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No143(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No143(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No144(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No144(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No145(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No145(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No146(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No146(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No147(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No147(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No148(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No148(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No149(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No149(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No150(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No150(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No151(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No151(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No152(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No152(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No153(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No153(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No154(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No154(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No155(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No155(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No156(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No156(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No157(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No157(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No158(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No158(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No159(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No159(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No160(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No160(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No161(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No161(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No162(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No162(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No163(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No163(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No164(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No164(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No165(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No165(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No166(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No166(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No167(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No167(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No168(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No168(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No169(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No169(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No170(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No170(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No171(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No171(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No172(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No172(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No173(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No173(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No174(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No174(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No175(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No175(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No176(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No176(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No177(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No177(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No178(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No178(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No179(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No179(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No180(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No180(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No181(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No181(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No182(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No182(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No183(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No183(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No184(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No184(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No185(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No185(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No186(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No186(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No187(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No187(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No188(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No188(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No189(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No189(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No190(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No190(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No191(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No191(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No192(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No192(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No193(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No193(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No194(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No194(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No195(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No195(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No196(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No196(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No197(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No197(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No198(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No198(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No199(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No199(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No200(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No200(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No201(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No201(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No202(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No202(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No203(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No203(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No204(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No204(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No205(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No205(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No206(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No206(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No207(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No207(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No208(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No208(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No209(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No209(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No210(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No210(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No211(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No211(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No212(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No212(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No213(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No213(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No214(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No214(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No215(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No215(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No216(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No216(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No217(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No217(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No218(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No218(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No219(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No219(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No220(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No220(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No221(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No221(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No222(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No222(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No223(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No223(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No224(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No224(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No225(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No225(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No226(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No226(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No227(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No227(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No228(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No228(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No229(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No229(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No230(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No230(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No231(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No231(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No232(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No232(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No233(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No233(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No234(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No234(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No235(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No235(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No236(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No236(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No237(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No237(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No238(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No238(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No239(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No239(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No240(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No240(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No241(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No241(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No242(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No242(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No243(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No243(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No244(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No244(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No245(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No245(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No246(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No246(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No247(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No247(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No248(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No248(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No249(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No249(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No250(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No250(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No251(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No251(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No252(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No252(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No253(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No253(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No254(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No254(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No255(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No255(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No256(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No256(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No257(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No257(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No258(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No258(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No259(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No259(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No260(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No260(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No261(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No261(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No262(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No262(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No263(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No263(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No264(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No264(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No265(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No265(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No266(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No266(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No267(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No267(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No268(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No268(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No269(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No269(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No270(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No270(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No271(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No271(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No272(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No272(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No273(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No273(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No274(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No274(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No275(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No275(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No276(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No276(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No277(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No277(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No278(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No278(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No279(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No279(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No280(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No280(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No281(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No281(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No282(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No282(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No283(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No283(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No284(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No284(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No285(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No285(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No286(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No286(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No287(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No287(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No288(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No288(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No289(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No289(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No290(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No290(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No291(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No291(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No292(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No292(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No293(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No293(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No294(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No294(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No295(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No295(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No296(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No296(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No297(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No297(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No298(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No298(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No299(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No299(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No300(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No300(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No301(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No301(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No302(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No302(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No303(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No303(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No304(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No304(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No305(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No305(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No306(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No306(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No307(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No307(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No308(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No308(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No309(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No309(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No310(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No310(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No311(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No311(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No312(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No312(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No313(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No313(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No314(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No314(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No315(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No315(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No316(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No316(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No317(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No317(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No318(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No318(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No319(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No319(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No320(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No320(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No321(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No321(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No322(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No322(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No323(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No323(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No324(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No324(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No325(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No325(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No326(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No326(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No327(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No327(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No328(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No328(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No329(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No329(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No330(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No330(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No331(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No331(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No332(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No332(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No333(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No333(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No334(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No334(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No335(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No335(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No336(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No336(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No337(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No337(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No338(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No338(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No339(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No339(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No340(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No340(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No341(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No341(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No342(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No342(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No343(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No343(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No344(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No344(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No345(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No345(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No346(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No346(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No347(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No347(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No348(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No348(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No349(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No349(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No350(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No350(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No351(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No351(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No352(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No352(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No353(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No353(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No354(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No354(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No355(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No355(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No356(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No356(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No357(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No357(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No358(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No358(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No359(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No359(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No360(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No360(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No361(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No361(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No362(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No362(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No363(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No363(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No364(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No364(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No365(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No365(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No366(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No366(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No367(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No367(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No368(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No368(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No369(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No369(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No370(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No370(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No371(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No371(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No372(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No372(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No373(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No373(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No374(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No374(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No375(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No375(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No376(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No376(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No377(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No377(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No378(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No378(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No379(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No379(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No380(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No380(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No381(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No381(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No382(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No382(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No383(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No383(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No384(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No384(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No385(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No385(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No386(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No386(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No387(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No387(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No388(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No388(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No389(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No389(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No390(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No390(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No391(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No391(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No392(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No392(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No393(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No393(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No394(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No394(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No395(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No395(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No396(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No396(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No397(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No397(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No398(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No398(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No399(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No399(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No400(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No400(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No401(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No401(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No402(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No402(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No403(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No403(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No404(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No404(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No405(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No405(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No406(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No406(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No407(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No407(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No408(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No408(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No409(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No409(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No410(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No410(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No411(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No411(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No412(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No412(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No413(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No413(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No414(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No414(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No415(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No415(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No416(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No416(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No417(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No417(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No418(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No418(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No419(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No419(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No420(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No420(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No421(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No421(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No422(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No422(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No423(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No423(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No424(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No424(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No425(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No425(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No426(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No426(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No427(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No427(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No428(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No428(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No429(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No429(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No430(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No430(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No431(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No431(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No432(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No432(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No433(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No433(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No434(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No434(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No435(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No435(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No436(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No436(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No437(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No437(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No438(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No438(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No439(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No439(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No440(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No440(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No441(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No441(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No442(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No442(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No443(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No443(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No444(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No444(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No445(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No445(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No446(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No446(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No447(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No447(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No448(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No448(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No449(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No449(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No450(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No450(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No451(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No451(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No452(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No452(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No453(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No453(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No454(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No454(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No455(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No455(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No456(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No456(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No457(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No457(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No458(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No458(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No459(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No459(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No460(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No460(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No461(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No461(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No462(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No462(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No463(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No463(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No464(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No464(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No465(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No465(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No466(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No466(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No467(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No467(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No468(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No468(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No469(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No469(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No470(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No470(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No471(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No471(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No472(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No472(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No473(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No473(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No474(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No474(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No475(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No475(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No476(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No476(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No477(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No477(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No478(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No478(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No479(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No479(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No480(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No480(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No481(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No481(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No482(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No482(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No483(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No483(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No484(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No484(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No485(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No485(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No486(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No486(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No487(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No487(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No488(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No488(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No489(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No489(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No490(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No490(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No491(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No491(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No492(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No492(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No493(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No493(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No494(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No494(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No495(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No495(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No496(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No496(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No497(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No497(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No498(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No498(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No499(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No499(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No500(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No500(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No501(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No501(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No502(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No502(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No503(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No503(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No504(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No504(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No505(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No505(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No506(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No506(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No507(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No507(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No508(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No508(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No509(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No509(bitmap_t* bm);

    void SIMD256_COMPUTEa_CN9_No510(__m256i* codes);
    void BITMAP_COMPUTEa_CN9_No510(bitmap_t* bm);

};


#endif //SCANCODE_SIMD_COMPUTE_H
