//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_mtimes_helper.cpp
//
// Code generation for function 'eml_mtimes_helper'
//

// Include files
#include "eml_mtimes_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"

// Variable Definitions
static emlrtRTEInfo ic_emlrtRTEI{
    76,                  // lineNo
    13,                  // colNo
    "eml_mtimes_helper", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" // pName
};

// Function Definitions
void binary_expand_op(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                      const real_T in2[2], const coder::array<real_T, 1U> &in3)
{
  coder::array<real_T, 1U> c_in2;
  real_T b_in2;
  int32_T binary_expand_op_numThreads;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  b_in2 = in2[0];
  if (in3.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  c_in2.set_size(&ic_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  i = (loop_ub < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      c_in2[i1] = b_in2 * (in1[i1 * stride_0_0] + in3[i1 * stride_1_0]);
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(binary_expand_op_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      c_in2[i1] = b_in2 * (in1[i1 * stride_0_0] + in3[i1 * stride_1_0]);
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  in1.set_size(&ic_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1] = c_in2[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(binary_expand_op_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      in1[i1] = c_in2[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void binary_expand_op_1(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                        const real_T in2[2],
                        const coder::array<real_T, 1U> &in3)
{
  coder::array<real_T, 1U> c_in2;
  real_T b_in2;
  int32_T binary_expand_op_1_numThreads;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  b_in2 = in2[1];
  if (in1.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  c_in2.set_size(&ic_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  i = (loop_ub < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      c_in2[i1] = b_in2 * (in3[i1 * stride_0_0] + in1[i1 * stride_1_0]);
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_1_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(binary_expand_op_1_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      c_in2[i1] = b_in2 * (in3[i1 * stride_0_0] + in1[i1 * stride_1_0]);
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  in1.set_size(&ic_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1] = c_in2[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_1_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(binary_expand_op_1_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      in1[i1] = c_in2[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

// End of code generation (eml_mtimes_helper.cpp)
