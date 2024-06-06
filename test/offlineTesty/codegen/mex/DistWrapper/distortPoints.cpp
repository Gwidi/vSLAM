//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// distortPoints.cpp
//
// Code generation for function 'distortPoints'
//

// Include files
#include "distortPoints.h"
#include "DistWrapper_data.h"
#include "eml_mtimes_helper.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"

// Variable Definitions
static emlrtRSInfo lc_emlrtRSI{
    113,        // lineNo
    "cat_impl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    24,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    41,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    42,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    45,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo qc_emlrtRSI{
    46,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    47,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    55,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo tc_emlrtRSI{
    71,      // lineNo
    "power", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRTEInfo i_emlrtRTEI{
    288,                   // lineNo
    27,                    // colNo
    "check_non_axis_size", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

static emlrtECInfo emlrtECI{
    1,               // nDims
    24,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtECInfo b_emlrtECI{
    1,               // nDims
    41,              // lineNo
    47,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtECInfo c_emlrtECI{
    1,               // nDims
    41,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtECInfo d_emlrtECI{
    1,               // nDims
    42,              // lineNo
    24,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtECInfo e_emlrtECI{
    1,               // nDims
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtECInfo f_emlrtECI{
    1,               // nDims
    46,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtECInfo g_emlrtECI{
    1,               // nDims
    46,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    60,       // lineNo
    20,       // colNo
    "bsxfun", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elmat/bsxfun.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    20,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    21,              // lineNo
    36,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    21,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    24,              // lineNo
    6,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    24,              // lineNo
    19,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    25,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    36,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    40,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    41,              // lineNo
    52,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    41,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    41,              // lineNo
    39,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    42,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    45,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    46,              // lineNo
    68,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    46,              // lineNo
    48,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo vb_emlrtRTEI{
    46,              // lineNo
    29,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    47,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    46,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo yb_emlrtRTEI{
    50,              // lineNo
    20,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    51,              // lineNo
    5,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    52,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    55,              // lineNo
    1,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    42,              // lineNo
    16,              // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    21,              // lineNo
    9,               // colNo
    "distortPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pName
};

static emlrtRSInfo pd_emlrtRSI{
    76,                  // lineNo
    "eml_mtimes_helper", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    40,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    21,              // lineNo
    "distortPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/distortPoints.m" // pathName
};

// Function Declarations
static void binary_expand_op_2(const emlrtStack &sp,
                               coder::array<real_T, 1U> &in1,
                               const coder::array<real_T, 2U> &in2,
                               const real_T in3[9]);

static void plus(const emlrtStack &sp, coder::array<real_T, 2U> &in1,
                 const coder::array<real_T, 2U> &in2);

static void plus(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                 const coder::array<real_T, 1U> &in2);

static void times(const emlrtStack &sp, coder::array<real_T, 2U> &in1,
                  const coder::array<real_T, 2U> &in2);

static void times(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                  const coder::array<real_T, 1U> &in2,
                  const coder::array<real_T, 1U> &in3);

// Function Definitions
static void binary_expand_op_2(const emlrtStack &sp,
                               coder::array<real_T, 1U> &in1,
                               const coder::array<real_T, 2U> &in2,
                               const real_T in3[9])
{
  coder::array<real_T, 1U> b_in2;
  real_T b_in3;
  int32_T binary_expand_op_2_numThreads;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  b_in3 = in3[0];
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  b_in2.set_size(&jc_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  i = (loop_ub < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1] = (in2[i1 * stride_0_0] - in1[i1 * stride_1_0]) / b_in3;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_2_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(binary_expand_op_2_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      b_in2[i1] = (in2[i1 * stride_0_0] - in1[i1 * stride_1_0]) / b_in3;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  in1.set_size(&jc_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1] = b_in2[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_2_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(binary_expand_op_2_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      in1[i1] = b_in2[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void plus(const emlrtStack &sp, coder::array<real_T, 2U> &in1,
                 const coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 2U> b_in1;
  int32_T i;
  int32_T i2;
  int32_T loop_ub;
  int32_T plus_numThreads;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(&vb_emlrtRTEI, &sp, loop_ub, 2);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  i = ((loop_ub << 1) < 600);
  if (i) {
    for (int32_T i1{0}; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1[i2 + b_in1.size(0) * i1] =
            in1[i2 * stride_0_0 + in1.size(0) * i1] +
            in2[i2 * stride_1_0 + in2.size(0) * i1];
      }
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    plus_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(plus_numThreads) private(i2)

    for (int32_T i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1[i2 + b_in1.size(0) * i1] =
            in1[i2 * stride_0_0 + in1.size(0) * i1] +
            in2[i2 * stride_1_0 + in2.size(0) * i1];
      }
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  in1.set_size(&vb_emlrtRTEI, &sp, loop_ub, 2);
  if (i) {
    for (int32_T i1{0}; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1[i2 + in1.size(0) * i1] = b_in1[i2 + b_in1.size(0) * i1];
      }
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    plus_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(plus_numThreads) private(i2)

    for (int32_T i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1[i2 + in1.size(0) * i1] = b_in1[i2 + b_in1.size(0) * i1];
      }
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void plus(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                 const coder::array<real_T, 1U> &in2)
{
  coder::array<real_T, 1U> b_in1;
  int32_T i;
  int32_T loop_ub;
  int32_T plus_numThreads;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(&hc_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  i = (loop_ub < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1] = in1[i1 * stride_0_0] + in2[i1 * stride_1_0];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    plus_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(plus_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      b_in1[i1] = in1[i1 * stride_0_0] + in2[i1 * stride_1_0];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  in1.set_size(&hc_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1] = b_in1[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    plus_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(plus_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      in1[i1] = b_in1[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void times(const emlrtStack &sp, coder::array<real_T, 2U> &in1,
                  const coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 2U> b_in2;
  int32_T i;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T times_numThreads;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  b_in2.set_size(&ub_emlrtRTEI, &sp, loop_ub, 2);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  i = ((loop_ub << 1) < 600);
  if (i) {
    for (int32_T i1{0}; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in2[i2 + b_in2.size(0) * i1] =
            in2[i2 * stride_0_0 + in2.size(0) * i1] *
            in1[i2 * stride_1_0 + in1.size(0) * i1];
      }
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    times_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(times_numThreads) private(i2)

    for (int32_T i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in2[i2 + b_in2.size(0) * i1] =
            in2[i2 * stride_0_0 + in2.size(0) * i1] *
            in1[i2 * stride_1_0 + in1.size(0) * i1];
      }
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  in1.set_size(&ub_emlrtRTEI, &sp, loop_ub, 2);
  if (i) {
    for (int32_T i1{0}; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1[i2 + in1.size(0) * i1] = b_in2[i2 + b_in2.size(0) * i1];
      }
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    times_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(times_numThreads) private(i2)

    for (int32_T i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1[i2 + in1.size(0) * i1] = b_in2[i2 + b_in2.size(0) * i1];
      }
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void times(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                  const coder::array<real_T, 1U> &in2,
                  const coder::array<real_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T times_numThreads;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(&nb_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (static_cast<int32_T>(loop_ub < 600)) {
    for (int32_T i{0}; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    times_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(times_numThreads)

    for (int32_T i = 0; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
}

namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void distortPoints(const emlrtStack &sp, const array<real_T, 2U> &points,
                   const real_T K[9], const real_T radialDistortion[2],
                   const real_T tangentialDistortion[2],
                   array<real_T, 2U> &distortedPoints)
{
  array<real_T, 2U> centeredPoints;
  array<real_T, 2U> r1;
  array<real_T, 1U> dxTangential;
  array<real_T, 1U> r;
  array<real_T, 1U> r2;
  array<real_T, 1U> r4;
  array<real_T, 1U> xNorm;
  array<real_T, 1U> xyProduct;
  array<real_T, 1U> yNorm;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T center[2];
  real_T c_k;
  real_T d_k;
  real_T k_idx_0;
  real_T k_idx_1;
  real_T varargin_1;
  int32_T acoef;
  int32_T b_k;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T distortPoints_numThreads;
  int32_T i;
  int32_T i2;
  int32_T i3;
  int32_T k;
  int32_T loop_ub;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  center[0] = K[6];
  center[1] = K[7];
  loop_ub = points.size(0);
  centeredPoints.set_size(&fb_emlrtRTEI, &sp, points.size(0), 2);
  if (points.size(0) != 0) {
    acoef = (points.size(0) != 1);
    for (k = 0; k < 2; k++) {
      i = centeredPoints.size(0) - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        centeredPoints[b_k + centeredPoints.size(0) * k] =
            points[acoef * b_k + points.size(0) * k] - center[k];
      }
    }
  }
  k_idx_0 = K[4];
  yNorm.set_size(&gb_emlrtRTEI, &sp, points.size(0));
  acoef = points.size(0);
  i = (centeredPoints.size(0) < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      yNorm[i1] = centeredPoints[i1 + centeredPoints.size(0)] / k_idx_0;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < acoef; i1++) {
      yNorm[i1] = centeredPoints[i1 + centeredPoints.size(0)] / k_idx_0;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  k_idx_0 = K[3];
  xNorm.set_size(&hb_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      xNorm[i1] = k_idx_0 * yNorm[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      xNorm[i1] = k_idx_0 * yNorm[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  if (centeredPoints.size(0) == xNorm.size(0)) {
    k_idx_0 = K[0];
    xNorm.set_size(&ib_emlrtRTEI, &sp, loop_ub);
    if (i) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        xNorm[i1] = (centeredPoints[i1] - xNorm[i1]) / k_idx_0;
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        xNorm[i1] = (centeredPoints[i1] - xNorm[i1]) / k_idx_0;
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &rd_emlrtRSI;
    binary_expand_op_2(st, xNorm, centeredPoints, K);
  }
  st.site = &mc_emlrtRSI;
  b_st.site = &tc_emlrtRSI;
  acoef = xNorm.size(0);
  r2.set_size(&jb_emlrtRTEI, &b_st, xNorm.size(0));
  k = xNorm.size(0);
  b_k = (xNorm.size(0) < 600);
  if (b_k) {
    for (int32_T i1{0}; i1 < acoef; i1++) {
      k_idx_0 = xNorm[i1];
      r2[i1] = k_idx_0 * k_idx_0;
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads) private(        \
        varargin_1)

    for (int32_T i1 = 0; i1 < k; i1++) {
      varargin_1 = xNorm[i1];
      r2[i1] = varargin_1 * varargin_1;
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  st.site = &mc_emlrtRSI;
  b_st.site = &tc_emlrtRSI;
  r.set_size(&kb_emlrtRTEI, &b_st, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      k_idx_0 = yNorm[i1];
      r[i1] = k_idx_0 * k_idx_0;
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads) private(        \
        varargin_1)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = yNorm[i1];
      r[i1] = varargin_1 * varargin_1;
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  if ((acoef != loop_ub) && ((acoef != 1) && (loop_ub != 1))) {
    emlrtDimSizeImpxCheckR2021b(acoef, loop_ub, &emlrtECI, (emlrtConstCTX)&sp);
  }
  if (r2.size(0) == r.size(0)) {
    if (b_k) {
      for (int32_T i1{0}; i1 < acoef; i1++) {
        r2[i1] = r2[i1] + r[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < acoef; i1++) {
        r2[i1] = r2[i1] + r[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &mc_emlrtRSI;
    plus(st, r2, r);
  }
  loop_ub = r2.size(0);
  r4.set_size(&lb_emlrtRTEI, &sp, r2.size(0));
  k = r2.size(0);
  i = (r2.size(0) < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      r4[i1] = r2[i1] * r2[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < k; i1++) {
      r4[i1] = r2[i1] * r2[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  k_idx_0 = radialDistortion[0];
  k_idx_1 = radialDistortion[1];
  c_k = radialDistortion[0];
  d_k = radialDistortion[1];
  r4.set_size(&mb_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      r4[i1] = (k_idx_0 * r2[i1] + k_idx_1 * r4[i1]) + 0.0 * (r2[i1] * r4[i1]);
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads) private(        \
        varargin_1)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = (c_k * r2[i1] + d_k * r4[i1]) + 0.0 * (r2[i1] * r4[i1]);
      r4[i1] = varargin_1;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  if (xNorm.size(0) == yNorm.size(0)) {
    xyProduct.set_size(&nb_emlrtRTEI, &sp, acoef);
    if (b_k) {
      for (int32_T i1{0}; i1 < acoef; i1++) {
        xyProduct[i1] = xNorm[i1] * yNorm[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < acoef; i1++) {
        xyProduct[i1] = xNorm[i1] * yNorm[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &qd_emlrtRSI;
    times(st, xyProduct, xNorm, yNorm);
  }
  st.site = &nc_emlrtRSI;
  b_st.site = &tc_emlrtRSI;
  acoef = xNorm.size(0);
  r.set_size(&ob_emlrtRTEI, &sp, xNorm.size(0));
  k = xNorm.size(0);
  b_k = (xNorm.size(0) < 600);
  if (b_k) {
    for (int32_T i1{0}; i1 < acoef; i1++) {
      k_idx_0 = xNorm[i1];
      r[i1] = 2.0 * (k_idx_0 * k_idx_0);
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads) private(        \
        varargin_1)

    for (int32_T i1 = 0; i1 < k; i1++) {
      varargin_1 = xNorm[i1];
      r[i1] = 2.0 * (varargin_1 * varargin_1);
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  if ((loop_ub != acoef) && ((loop_ub != 1) && (acoef != 1))) {
    emlrtDimSizeImpxCheckR2021b(loop_ub, acoef, &b_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  k_idx_0 = 2.0 * tangentialDistortion[0];
  k = xyProduct.size(0);
  dxTangential.set_size(&pb_emlrtRTEI, &sp, xyProduct.size(0));
  b_loop_ub = xyProduct.size(0);
  i2 = (xyProduct.size(0) < 600);
  if (i2) {
    for (int32_T i1{0}; i1 < k; i1++) {
      dxTangential[i1] = k_idx_0 * xyProduct[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < b_loop_ub; i1++) {
      dxTangential[i1] = k_idx_0 * xyProduct[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  if (r2.size(0) == r.size(0)) {
    k_idx_0 = tangentialDistortion[1];
    r.set_size(&qb_emlrtRTEI, &sp, loop_ub);
    if (i) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        r[i1] = k_idx_0 * (r2[i1] + r[i1]);
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        r[i1] = k_idx_0 * (r2[i1] + r[i1]);
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &pd_emlrtRSI;
    binary_expand_op_1(st, r, tangentialDistortion, r2);
  }
  if ((k != r.size(0)) && ((k != 1) && (r.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(k, r.size(0), &c_emlrtECI, (emlrtConstCTX)&sp);
  }
  if (dxTangential.size(0) == r.size(0)) {
    if (i2) {
      for (int32_T i1{0}; i1 < k; i1++) {
        dxTangential[i1] = dxTangential[i1] + r[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < k; i1++) {
        dxTangential[i1] = dxTangential[i1] + r[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &nc_emlrtRSI;
    plus(st, dxTangential, r);
  }
  st.site = &oc_emlrtRSI;
  b_st.site = &tc_emlrtRSI;
  b_loop_ub = yNorm.size(0);
  r.set_size(&rb_emlrtRTEI, &sp, yNorm.size(0));
  c_loop_ub = yNorm.size(0);
  i3 = (yNorm.size(0) < 600);
  if (i3) {
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      k_idx_0 = yNorm[i1];
      r[i1] = 2.0 * (k_idx_0 * k_idx_0);
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads) private(        \
        varargin_1)

    for (int32_T i1 = 0; i1 < c_loop_ub; i1++) {
      varargin_1 = yNorm[i1];
      r[i1] = 2.0 * (varargin_1 * varargin_1);
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  c_loop_ub = r2.size(0);
  if ((r2.size(0) != b_loop_ub) && ((r2.size(0) != 1) && (b_loop_ub != 1))) {
    emlrtDimSizeImpxCheckR2021b(r2.size(0), b_loop_ub, &d_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (r2.size(0) == r.size(0)) {
    int32_T d_loop_ub;
    k_idx_0 = tangentialDistortion[0];
    d_loop_ub = r2.size(0);
    if (static_cast<int32_T>(r2.size(0) < 600)) {
      for (int32_T i1{0}; i1 < c_loop_ub; i1++) {
        r2[i1] = k_idx_0 * (r2[i1] + r[i1]);
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < d_loop_ub; i1++) {
        r2[i1] = k_idx_0 * (r2[i1] + r[i1]);
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &pd_emlrtRSI;
    binary_expand_op(st, r2, tangentialDistortion, r);
  }
  k_idx_0 = 2.0 * tangentialDistortion[1];
  if (i2) {
    for (int32_T i1{0}; i1 < k; i1++) {
      xyProduct[i1] = k_idx_0 * xyProduct[i1];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < k; i1++) {
      xyProduct[i1] = k_idx_0 * xyProduct[i1];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  c_loop_ub = r2.size(0);
  if ((r2.size(0) != k) && ((r2.size(0) != 1) && (k != 1))) {
    emlrtDimSizeImpxCheckR2021b(r2.size(0), k, &e_emlrtECI, (emlrtConstCTX)&sp);
  }
  if (r2.size(0) == xyProduct.size(0)) {
    k = r2.size(0);
    if (static_cast<int32_T>(r2.size(0) < 600)) {
      for (int32_T i1{0}; i1 < c_loop_ub; i1++) {
        r2[i1] = r2[i1] + xyProduct[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < k; i1++) {
        r2[i1] = r2[i1] + xyProduct[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &oc_emlrtRSI;
    plus(st, r2, xyProduct);
  }
  st.site = &pc_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  centeredPoints.set_size(&sb_emlrtRTEI, &b_st, acoef, 2);
  if (b_k) {
    for (int32_T i1{0}; i1 < acoef; i1++) {
      centeredPoints[i1] = xNorm[i1];
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < acoef; i1++) {
      centeredPoints[i1] = xNorm[i1];
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  if (i3) {
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      centeredPoints[i1 + centeredPoints.size(0)] = yNorm[i1];
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < b_loop_ub; i1++) {
      centeredPoints[i1 + centeredPoints.size(0)] = yNorm[i1];
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  st.site = &qc_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  r1.set_size(&tb_emlrtRTEI, &b_st, loop_ub, 2);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      r1[i1] = r4[i1];
      r1[i1 + r1.size(0)] = r4[i1];
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      r1[i1] = r4[i1];
      r1[i1 + r1.size(0)] = r4[i1];
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  if ((acoef != loop_ub) && ((acoef != 1) && (loop_ub != 1))) {
    emlrtDimSizeImpxCheckR2021b(acoef, loop_ub, &f_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (centeredPoints.size(0) == r1.size(0)) {
    loop_ub = centeredPoints.size(0) << 1;
    r1.set_size(&ub_emlrtRTEI, &sp, acoef, 2);
    if (static_cast<int32_T>(loop_ub < 600)) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        r1[i1] = centeredPoints[i1] * r1[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        r1[i1] = centeredPoints[i1] * r1[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &qc_emlrtRSI;
    times(st, r1, centeredPoints);
  }
  if ((centeredPoints.size(0) != r1.size(0)) &&
      ((centeredPoints.size(0) != 1) && (r1.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(centeredPoints.size(0), r1.size(0), &g_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (centeredPoints.size(0) == r1.size(0)) {
    loop_ub = centeredPoints.size(0) << 1;
    centeredPoints.set_size(&vb_emlrtRTEI, &sp, centeredPoints.size(0), 2);
    if (static_cast<int32_T>(loop_ub < 600)) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        centeredPoints[i1] = centeredPoints[i1] + r1[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        centeredPoints[i1] = centeredPoints[i1] + r1[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &qc_emlrtRSI;
    plus(st, centeredPoints, r1);
  }
  st.site = &rc_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  if (r2.size(0) != dxTangential.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  loop_ub = dxTangential.size(0);
  r1.set_size(&wb_emlrtRTEI, &b_st, dxTangential.size(0), 2);
  acoef = dxTangential.size(0);
  if (static_cast<int32_T>(dxTangential.size(0) < 600)) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      r1[i1] = dxTangential[i1];
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < acoef; i1++) {
      r1[i1] = dxTangential[i1];
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  acoef = r2.size(0);
  if (static_cast<int32_T>(r2.size(0) < 600)) {
    for (int32_T i1{0}; i1 < acoef; i1++) {
      r1[i1 + r1.size(0)] = r2[i1];
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < acoef; i1++) {
      r1[i1 + r1.size(0)] = r2[i1];
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  if ((centeredPoints.size(0) != loop_ub) &&
      ((centeredPoints.size(0) != 1) && (loop_ub != 1))) {
    emlrtDimSizeImpxCheckR2021b(centeredPoints.size(0), loop_ub, &g_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (centeredPoints.size(0) == r1.size(0)) {
    loop_ub = centeredPoints.size(0) << 1;
    centeredPoints.set_size(&xb_emlrtRTEI, &sp, centeredPoints.size(0), 2);
    if (static_cast<int32_T>(loop_ub < 600)) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        centeredPoints[i1] = centeredPoints[i1] + r1[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      distortPoints_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        centeredPoints[i1] = centeredPoints[i1] + r1[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  } else {
    st.site = &qc_emlrtRSI;
    plus(st, centeredPoints, r1);
  }
  k_idx_0 = K[0];
  loop_ub = centeredPoints.size(0);
  xNorm.set_size(&yb_emlrtRTEI, &sp, centeredPoints.size(0));
  acoef = centeredPoints.size(0);
  k_idx_1 = K[3];
  r.set_size(&ac_emlrtRTEI, &sp, centeredPoints.size(0));
  i = (centeredPoints.size(0) < 600);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      xNorm[i1] = centeredPoints[i1] * k_idx_0;
      r[i1] = k_idx_1 * centeredPoints[i1 + centeredPoints.size(0)];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < acoef; i1++) {
      xNorm[i1] = centeredPoints[i1] * k_idx_0;
      r[i1] = k_idx_1 * centeredPoints[i1 + centeredPoints.size(0)];
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  k_idx_0 = K[6];
  k_idx_1 = K[4];
  c_k = K[7];
  yNorm.set_size(&bc_emlrtRTEI, &sp, loop_ub);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      xNorm[i1] = (xNorm[i1] + k_idx_0) + r[i1];
      yNorm[i1] = centeredPoints[i1 + centeredPoints.size(0)] * k_idx_1 + c_k;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      xNorm[i1] = (xNorm[i1] + k_idx_0) + r[i1];
      yNorm[i1] = centeredPoints[i1 + centeredPoints.size(0)] * k_idx_1 + c_k;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  st.site = &sc_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  if (yNorm.size(0) != xNorm.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  distortedPoints.set_size(&cc_emlrtRTEI, &b_st, loop_ub, 2);
  if (i) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      distortedPoints[i1] = xNorm[i1];
      distortedPoints[i1 + distortedPoints.size(0)] = yNorm[i1];
    }
  } else {
    emlrtEnterParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    distortPoints_numThreads = emlrtAllocRegionTLSs(
        b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(distortPoints_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub; i1++) {
      distortedPoints[i1] = xNorm[i1];
      distortedPoints[i1 + distortedPoints.size(0)] = yNorm[i1];
    }
    emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (distortPoints.cpp)
