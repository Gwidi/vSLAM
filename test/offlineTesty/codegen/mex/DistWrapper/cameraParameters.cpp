//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cameraParameters.cpp
//
// Code generation for function 'cameraParameters'
//

// Include files
#include "cameraParameters.h"
#include "DistWrapper_data.h"
#include "ImageTransformer.h"
#include "colon.h"
#include "distortPoints.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimterp2d.h"
#include "mwmathutil.h"
#include "omp.h"

// Variable Definitions
static emlrtRSInfo rb_emlrtRSI{
    594,                                       // lineNo
    "CameraParametersImpl/undistortImageImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    598,                                       // lineNo
    "CameraParametersImpl/undistortImageImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    603,                                       // lineNo
    "CameraParametersImpl/undistortImageImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    32,                        // lineNo
    "ImageTransformer/update", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    37,                        // lineNo
    "ImageTransformer/update", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    49,                            // lineNo
    "ImageTransformer/computeMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    60,                            // lineNo
    "ImageTransformer/computeMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    69,                            // lineNo
    "ImageTransformer/computeMap", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    121,                                    // lineNo
    "ImageTransformerBase/sampleMapPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    122,                                    // lineNo
    "ImageTransformerBase/sampleMapPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    123,                                    // lineNo
    "ImageTransformerBase/sampleMapPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    28,      // lineNo
    "colon", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/ops/colon.m" // pathName
};

static emlrtRSInfo ec_emlrtRSI{
    125,     // lineNo
    "colon", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/ops/colon.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    20,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" // pathName
};

static emlrtRSInfo
    ic_emlrtRSI{
        31,         // lineNo
        "meshgrid", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elmat/"
        "meshgrid.m" // pathName
    };

static emlrtRSInfo
    jc_emlrtRSI{
        32,         // lineNo
        "meshgrid", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elmat/"
        "meshgrid.m" // pathName
    };

static emlrtRSInfo ad_emlrtRSI{
    91,                                    // lineNo
    "ImageTransformerBase/transformImage", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    32,         // lineNo
    "interp2d", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/interp2d.m" // pathName
};

static emlrtRSInfo cd_emlrtRSI{
    34,         // lineNo
    "interp2d", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/interp2d.m" // pathName
};

static emlrtRSInfo dd_emlrtRSI{
    98,         // lineNo
    "interp2d", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/interp2d.m" // pathName
};

static emlrtRSInfo ed_emlrtRSI{
    138,                   // lineNo
    "interpolate_imterp2", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/interp2d.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    607,                                       // lineNo
    47,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                        // iFirst
    -1,                                        // iLast
    607,                                       // lineNo
    33,                                        // colNo
    "",                                        // aName
    "CameraParametersImpl/undistortImageImpl", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo g_emlrtRTEI{
    44,         // lineNo
    1,          // colNo
    "interp2d", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/interp2d.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatenonnan", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnan.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    111,                    // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    112,                    // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    113,                    // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    28,      // lineNo
    9,       // colNo
    "colon", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/ops/colon.m" // pName
};

static emlrtRTEInfo
    ab_emlrtRTEI{
        20,         // lineNo
        25,         // colNo
        "meshgrid", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elmat/"
        "meshgrid.m" // pName
    };

static emlrtRTEInfo
    bb_emlrtRTEI{
        21,         // lineNo
        25,         // colNo
        "meshgrid", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elmat/"
        "meshgrid.m" // pName
    };

static emlrtRTEInfo cb_emlrtRTEI{
    310,   // lineNo
    14,    // colNo
    "cat", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    118,        // lineNo
    30,         // colNo
    "interp2d", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/interp2d.m" // pName
};

// Function Definitions
namespace coder {
void cameraParameters::undistortImageImpl(const emlrtStack &sp,
                                          const uint8_T b_I[1310720],
                                          uint8_T Jout[1310720],
                                          real_T newOrigin[2])
{
  static const char_T a[5]{'u', 'i', 'n', 't', '8'};
  static const char_T cv[5]{'u', 'i', 'n', 't', '8'};
  static const char_T cv1[4]{'s', 'a', 'm', 'e'};
  array<real_T, 2U> X;
  array<real_T, 2U> Y;
  array<real_T, 2U> b_X;
  array<real_T, 2U> b_y;
  array<real_T, 2U> ptsOut;
  array<real_T, 2U> y;
  array<uint8_T, 2U> outputImage;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T inputImageSize[3];
  real_T outputImageSize[2];
  real_T b;
  real_T b_a;
  int32_T b_i;
  int32_T exitg2;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T ny_tmp;
  int32_T undistortImageImpl_numThreads;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  uint8_T fillValues;
  boolean_T b_p;
  boolean_T emlrtHadParallelError{false};
  boolean_T exitg1;
  boolean_T p;
  boolean_T sameClass;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &rb_emlrtRSI;
  p = (UndistortMap.SizeOfImage.size(1) == 2);
  if (p && (UndistortMap.SizeOfImage.size(1) != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(UndistortMap.SizeOfImage[k] ==
            256.0 * static_cast<real_T>(k) + 1024.0)) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  sameClass = false;
  if (UndistortMap.ClassOfImage.size(1) == 5) {
    k = 0;
    do {
      exitg2 = 0;
      if (k < 5) {
        if (cv[k] != UndistortMap.ClassOfImage[k]) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        sameClass = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  b_p = (UndistortMap.OutputView.size(1) == 4);
  if (b_p && (UndistortMap.OutputView.size(1) != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (UndistortMap.OutputView[k] != cv1[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (p && sameClass && b_p) {
    p = true;
  } else {
    p = false;
  }
  if (!p) {
    st.site = &sb_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    UndistortMap.SizeOfImage.set_size(&v_emlrtRTEI, &b_st, 1, 2);
    UndistortMap.SizeOfImage[0] = 1024.0;
    UndistortMap.SizeOfImage[1] = 1280.0;
    UndistortMap.ClassOfImage.set_size(&w_emlrtRTEI, &b_st, 1, 5);
    for (ny_tmp = 0; ny_tmp < 5; ny_tmp++) {
      UndistortMap.ClassOfImage[ny_tmp] = a[ny_tmp];
    }
    UndistortMap.OutputView.set_size(&x_emlrtRTEI, &b_st, 1, 4);
    UndistortMap.OutputView[0] = 's';
    UndistortMap.OutputView[1] = 'a';
    UndistortMap.OutputView[2] = 'm';
    UndistortMap.OutputView[3] = 'e';
    UndistortMap.XBounds[0] = 1.0;
    UndistortMap.YBounds[0] = 1.0;
    UndistortMap.XBounds[1] = 1280.0;
    UndistortMap.YBounds[1] = 1024.0;
    b_st.site = &vb_emlrtRSI;
    c_st.site = &wb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    b_a = UndistortMap.XBounds[0];
    b = UndistortMap.XBounds[1];
    e_st.site = &dc_emlrtRSI;
    if (muDoubleScalarIsNaN(b_a) || muDoubleScalarIsNaN(b)) {
      y.set_size(&y_emlrtRTEI, &e_st, 1, 1);
      y[0] = rtNaN;
    } else if (b < b_a) {
      y.set_size(&y_emlrtRTEI, &e_st, 1, 0);
    } else if ((muDoubleScalarIsInf(b_a) || muDoubleScalarIsInf(b)) &&
               (b_a == b)) {
      y.set_size(&y_emlrtRTEI, &e_st, 1, 1);
      y[0] = rtNaN;
    } else if (muDoubleScalarFloor(b_a) == b_a) {
      k = static_cast<int32_T>(b - b_a);
      y.set_size(&y_emlrtRTEI, &e_st, 1, k + 1);
      if (static_cast<int32_T>(k + 1 < 600)) {
        for (i = 0; i <= k; i++) {
          y[i] = b_a + static_cast<real_T>(i);
        }
      } else {
        emlrtEnterParallelRegion(&e_st,
                                 static_cast<boolean_T>(omp_in_parallel()));
        undistortImageImpl_numThreads = emlrtAllocRegionTLSs(
            e_st.tls, static_cast<boolean_T>(omp_in_parallel()),
            omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(undistortImageImpl_numThreads)

        for (i = 0; i <= k; i++) {
          y[i] = b_a + static_cast<real_T>(i);
        }
        emlrtExitParallelRegion(&e_st,
                                static_cast<boolean_T>(omp_in_parallel()));
      }
    } else {
      f_st.site = &ec_emlrtRSI;
      eml_float_colon(f_st, b_a, b, y);
    }
    d_st.site = &bc_emlrtRSI;
    b_a = UndistortMap.YBounds[0];
    b = UndistortMap.YBounds[1];
    e_st.site = &dc_emlrtRSI;
    if (muDoubleScalarIsNaN(b_a) || muDoubleScalarIsNaN(b)) {
      b_y.set_size(&y_emlrtRTEI, &e_st, 1, 1);
      b_y[0] = rtNaN;
    } else if (b < b_a) {
      b_y.set_size(&y_emlrtRTEI, &e_st, 1, 0);
    } else if ((muDoubleScalarIsInf(b_a) || muDoubleScalarIsInf(b)) &&
               (b_a == b)) {
      b_y.set_size(&y_emlrtRTEI, &e_st, 1, 1);
      b_y[0] = rtNaN;
    } else if (muDoubleScalarFloor(b_a) == b_a) {
      k = static_cast<int32_T>(b - b_a);
      b_y.set_size(&y_emlrtRTEI, &e_st, 1, k + 1);
      if (static_cast<int32_T>(k + 1 < 600)) {
        for (i = 0; i <= k; i++) {
          b_y[i] = b_a + static_cast<real_T>(i);
        }
      } else {
        emlrtEnterParallelRegion(&e_st,
                                 static_cast<boolean_T>(omp_in_parallel()));
        undistortImageImpl_numThreads = emlrtAllocRegionTLSs(
            e_st.tls, static_cast<boolean_T>(omp_in_parallel()),
            omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(undistortImageImpl_numThreads)

        for (i = 0; i <= k; i++) {
          b_y[i] = b_a + static_cast<real_T>(i);
        }
        emlrtExitParallelRegion(&e_st,
                                static_cast<boolean_T>(omp_in_parallel()));
      }
    } else {
      f_st.site = &ec_emlrtRSI;
      eml_float_colon(f_st, b_a, b, b_y);
    }
    d_st.site = &ac_emlrtRSI;
    k = y.size(1);
    ny_tmp = b_y.size(1);
    X.set_size(&ab_emlrtRTEI, &d_st, b_y.size(1), y.size(1));
    Y.set_size(&bb_emlrtRTEI, &d_st, b_y.size(1), y.size(1));
    if ((y.size(1) != 0) && (b_y.size(1) != 0)) {
      e_st.site = &ic_emlrtRSI;
      if (y.size(1) > 2147483646) {
        f_st.site = &hc_emlrtRSI;
        check_forloop_overflow_error(f_st);
      }
      for (j = 0; j < k; j++) {
        e_st.site = &jc_emlrtRSI;
        if (ny_tmp > 2147483646) {
          f_st.site = &hc_emlrtRSI;
          check_forloop_overflow_error(f_st);
        }
        for (b_i = 0; b_i < ny_tmp; b_i++) {
          X[b_i + X.size(0) * j] = y[j];
          Y[b_i + Y.size(0) * j] = b_y[b_i];
        }
      }
    }
    d_st.site = &cc_emlrtRSI;
    e_st.site = &kc_emlrtRSI;
    k = Y.size(0) * Y.size(1);
    b_X.set_size(&cb_emlrtRTEI, &b_st, k, 2);
    if (static_cast<int32_T>(k < 600)) {
      for (i = 0; i < k; i++) {
        b_X[i] = X[i];
      }
      for (i = 0; i < k; i++) {
        b_X[i + b_X.size(0)] = Y[i];
      }
    } else {
      emlrtEnterParallelRegion(&b_st,
                               static_cast<boolean_T>(omp_in_parallel()));
      undistortImageImpl_numThreads = emlrtAllocRegionTLSs(
          b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(undistortImageImpl_numThreads)

      for (i = 0; i < k; i++) {
        b_X[i] = X[i];
      }
      emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
      emlrtEnterParallelRegion(&b_st,
                               static_cast<boolean_T>(omp_in_parallel()));
      undistortImageImpl_numThreads = emlrtAllocRegionTLSs(
          b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(undistortImageImpl_numThreads)

      for (i = 0; i < k; i++) {
        b_X[i + b_X.size(0)] = Y[i];
      }
      emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    }
    c_st.site = &xb_emlrtRSI;
    vision::internal::calibration::distortPoints(c_st, b_X, K, RadialDistortion,
                                                 TangentialDistortion, ptsOut);
    c_st.site = &yb_emlrtRSI;
    UndistortMap.generateMap(c_st, ptsOut);
  }
  st.site = &tb_emlrtRSI;
  b_st.site = &ad_emlrtRSI;
  c_st.site = &bd_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  p = true;
  ny_tmp = UndistortMap.XmapSingle.size(0) * UndistortMap.XmapSingle.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= ny_tmp - 1)) {
    if (!muSingleScalarIsNaN(UndistortMap.XmapSingle[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "X");
  }
  c_st.site = &cd_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  p = true;
  ny_tmp = UndistortMap.YmapSingle.size(0) * UndistortMap.YmapSingle.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= ny_tmp - 1)) {
    if (!muSingleScalarIsNaN(UndistortMap.YmapSingle[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "Y");
  }
  varargin_1[0] = static_cast<uint32_T>(UndistortMap.XmapSingle.size(0));
  varargin_2[0] = static_cast<uint32_T>(UndistortMap.YmapSingle.size(0));
  varargin_1[1] = static_cast<uint32_T>(UndistortMap.XmapSingle.size(1));
  varargin_2[1] = static_cast<uint32_T>(UndistortMap.YmapSingle.size(1));
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int32_T>(varargin_1[k]) !=
        static_cast<int32_T>(varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                  "images:interp2d:inconsistentXYSize",
                                  "images:interp2d:inconsistentXYSize", 0);
  }
  c_st.site = &dd_emlrtRSI;
  outputImage.set_size(&db_emlrtRTEI, &c_st, UndistortMap.XmapSingle.size(0),
                       UndistortMap.XmapSingle.size(1));
  d_st.site = &ed_emlrtRSI;
  fillValues = 0U;
  outputImageSize[0] = outputImage.size(0);
  outputImageSize[1] = outputImage.size(1);
  inputImageSize[0] = 1024.0;
  inputImageSize[1] = 1280.0;
  inputImageSize[2] = 1.0;
  imterp2d32f_uint8(&b_I[0], &inputImageSize[0], &UndistortMap.YmapSingle[0],
                    &UndistortMap.XmapSingle[0], &outputImageSize[0], 2.0, true,
                    &fillValues, &outputImage[0]);
  newOrigin[0] = UndistortMap.XBounds[0] - 1.0;
  newOrigin[1] = UndistortMap.YBounds[0] - 1.0;
  k = outputImage.size(0);
  ny_tmp = outputImage.size(1);
  emlrtEnterParallelRegion((emlrtCTX)&sp,
                           static_cast<boolean_T>(omp_in_parallel()));
  undistortImageImpl_numThreads =
      emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                           omp_get_max_threads(), 6);
#pragma omp parallel num_threads(undistortImageImpl_numThreads) private(       \
        i1, g_st) firstprivate(emlrtHadParallelError)
  {
    try {
      g_st.prev = &sp;
      g_st.tls = emlrtAllocTLS((emlrtCTX)&sp, omp_get_thread_num());
      g_st.site = nullptr;
    } catch (...) {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (i = 0; i < 1280; i++) {
      if (emlrtHadParallelError) {
        continue;
      }
      try {
        for (i1 = 0; i1 < 1024; i1++) {
          if (i + 1 > ny_tmp) {
            emlrtDynamicBoundsCheckR2012b(i + 1, 1, ny_tmp, &emlrtBCI, &g_st);
          }
          if (i1 + 1 > k) {
            emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, k, &b_emlrtBCI, &g_st);
          }
          Jout[i1 + (i << 10)] = outputImage[i1 + outputImage.size(0) * i];
        }
      } catch (...) {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtExitParallelRegion((emlrtCTX)&sp,
                          static_cast<boolean_T>(omp_in_parallel()));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder

// End of code generation (cameraParameters.cpp)
