//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ImageTransformer.cpp
//
// Code generation for function 'ImageTransformer'
//

// Include files
#include "ImageTransformer.h"
#include "assertValidSizeArg.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include "omp.h"

// Variable Definitions
static emlrtRSInfo uc_emlrtRSI{
    147,                                // lineNo
    "ImageTransformerBase/generateMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo vc_emlrtRSI{
    148,                                // lineNo
    "ImageTransformerBase/generateMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo wc_emlrtRSI{
    150,                                // lineNo
    "ImageTransformerBase/generateMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo xc_emlrtRSI{
    152,                                // lineNo
    "ImageTransformerBase/generateMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo yc_emlrtRSI{
    40,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

static emlrtRTEInfo k_emlrtRTEI{
    74,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    79,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    81,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    150,                    // lineNo
    48,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    150,                    // lineNo
    17,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    152,                    // lineNo
    48,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    152,                    // lineNo
    17,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void ImageTransformer::generateMap(const emlrtStack &sp,
                                   const array<real_T, 2U> &ptsOut)
{
  static const char_T cv[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  ImageTransformer *tmp_this;
  array<real_T, 1U> b_ptsOut;
  emlrtStack b_st;
  emlrtStack st;
  real_T m;
  real_T n;
  int32_T generateMap_numThreads;
  int32_T kstr;
  boolean_T b_bool;
  tmp_this = this;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  m = (tmp_this->YBounds[1] - tmp_this->YBounds[0]) + 1.0;
  n = (tmp_this->XBounds[1] - tmp_this->XBounds[0]) + 1.0;
  b_bool = false;
  if (tmp_this->ClassOfImage.size(1) == 6) {
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (tmp_this->ClassOfImage[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    real_T dv[2];
    int32_T i;
    int32_T maxdimlen;
    kstr = ptsOut.size(0);
    dv[0] = m;
    dv[1] = n;
    st.site = &uc_emlrtRSI;
    b_st.site = &yc_emlrtRSI;
    ::coder::internal::assertValidSizeArg(b_st, dv);
    maxdimlen = ptsOut.size(0);
    if (ptsOut.size(0) < 1) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(kstr, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_bool = (static_cast<int32_T>(m) >= 0);
    if ((!b_bool) || (static_cast<int32_T>(n) < 0)) {
      b_bool = false;
    }
    if (!b_bool) {
      emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    i = static_cast<int32_T>(m) * static_cast<int32_T>(n);
    if (i != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &m_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    st.site = &vc_emlrtRSI;
    b_st.site = &yc_emlrtRSI;
    ::coder::internal::assertValidSizeArg(b_st, dv);
    maxdimlen = ptsOut.size(0);
    if (ptsOut.size(0) < 1) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(kstr, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_bool = (static_cast<int32_T>(m) >= 0);
    if ((!b_bool) || (static_cast<int32_T>(n) < 0)) {
      b_bool = false;
    }
    if (!b_bool) {
      emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    if (i != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &m_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
  } else {
    real_T dv[2];
    int32_T i;
    int32_T loop_ub;
    int32_T maxdimlen;
    int32_T num_tmp_idx_0;
    int32_T num_tmp_idx_0_tmp;
    int32_T num_tmp_idx_1;
    int32_T num_tmp_idx_1_tmp;
    int32_T nx_tmp;
    dv[0] = m;
    dv[1] = n;
    st.site = &wc_emlrtRSI;
    nx_tmp = ptsOut.size(0);
    b_st.site = &yc_emlrtRSI;
    ::coder::internal::assertValidSizeArg(b_st, dv);
    num_tmp_idx_0_tmp = static_cast<int32_T>(m);
    num_tmp_idx_0 = static_cast<int32_T>(m);
    num_tmp_idx_1_tmp = static_cast<int32_T>(n);
    num_tmp_idx_1 = static_cast<int32_T>(n);
    maxdimlen = ptsOut.size(0);
    if (ptsOut.size(0) < 1) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(nx_tmp, maxdimlen);
    if (static_cast<int32_T>(m) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (static_cast<int32_T>(n) > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_bool = (static_cast<int32_T>(m) >= 0);
    if ((!b_bool) || (static_cast<int32_T>(n) < 0)) {
      b_bool = false;
    }
    if (!b_bool) {
      emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    loop_ub = static_cast<int32_T>(m) * static_cast<int32_T>(n);
    if (loop_ub != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &m_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b_ptsOut.set_size(&dc_emlrtRTEI, &sp, ptsOut.size(0));
    kstr = ptsOut.size(0);
    i = (ptsOut.size(0) < 600);
    if (i) {
      for (int32_T i1{0}; i1 < nx_tmp; i1++) {
        b_ptsOut[i1] = ptsOut[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      generateMap_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(generateMap_numThreads)

      for (int32_T i1 = 0; i1 < kstr; i1++) {
        b_ptsOut[i1] = ptsOut[i1];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    tmp_this->XmapSingle.set_size(&ec_emlrtRTEI, &sp, num_tmp_idx_0_tmp,
                                  num_tmp_idx_1_tmp);
    kstr = (loop_ub < 600);
    if (kstr) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        tmp_this->XmapSingle[i1] = static_cast<real32_T>(b_ptsOut[i1]);
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      generateMap_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(generateMap_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        tmp_this->XmapSingle[i1] = static_cast<real32_T>(b_ptsOut[i1]);
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    st.site = &xc_emlrtRSI;
    b_st.site = &yc_emlrtRSI;
    ::coder::internal::assertValidSizeArg(b_st, dv);
    maxdimlen = nx_tmp;
    if (ptsOut.size(0) < 1) {
      maxdimlen = 1;
    }
    maxdimlen = muIntScalarMax_sint32(nx_tmp, maxdimlen);
    if (num_tmp_idx_0 > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (num_tmp_idx_1 > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b_bool = (num_tmp_idx_0 >= 0);
    if ((!b_bool) || (num_tmp_idx_1 < 0)) {
      b_bool = false;
    }
    if (!b_bool) {
      emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                    "MATLAB:checkDimCommon:nonnegativeSize",
                                    "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }
    if (loop_ub != ptsOut.size(0)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &m_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    b_ptsOut.set_size(&fc_emlrtRTEI, &sp, nx_tmp);
    if (i) {
      for (int32_T i1{0}; i1 < nx_tmp; i1++) {
        b_ptsOut[i1] = ptsOut[i1 + ptsOut.size(0)];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      generateMap_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(generateMap_numThreads)

      for (int32_T i1 = 0; i1 < nx_tmp; i1++) {
        b_ptsOut[i1] = ptsOut[i1 + ptsOut.size(0)];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    tmp_this->YmapSingle.set_size(&gc_emlrtRTEI, &sp, num_tmp_idx_0_tmp,
                                  num_tmp_idx_1_tmp);
    if (kstr) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        tmp_this->YmapSingle[i1] = static_cast<real32_T>(b_ptsOut[i1]);
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      generateMap_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(generateMap_numThreads)

      for (int32_T i1 = 0; i1 < loop_ub; i1++) {
        tmp_this->YmapSingle[i1] = static_cast<real32_T>(b_ptsOut[i1]);
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (ImageTransformer.cpp)
