//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// CameraParametersImpl.cpp
//
// Code generation for function 'CameraParametersImpl'
//

// Include files
#include "CameraParametersImpl.h"
#include "DistWrapper_data.h"
#include "DistWrapper_internal_types.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo n_emlrtRSI{
    365,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    385,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    930,                            // lineNo
    "checkAssignedIntrinsicMatrix", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    935,                            // lineNo
    "checkAssignedIntrinsicMatrix", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    620,                                         // lineNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    641,                                          // lineNo
    "CameraParametersImpl/checkRadialDistortion", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    651,                                              // lineNo
    "CameraParametersImpl/checkTangentialDistortion", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    661,                                   // lineNo
    "CameraParametersImpl/checkImageSize", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    635,                                                     // lineNo
    13,                                                      // colNo
    "CameraParametersImpl/checkIntrinsicMatrixPostMultiply", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    625,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    13,                // lineNo
    37,                // colNo
    "validateinteger", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" // pName
};

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void CameraParametersImpl::checkImageSize(const emlrtStack &sp,
                                          const real_T imageSize[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &fb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (muDoubleScalarFloor(imageSize[k]) == imageSize[k]) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(imageSize[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:CameraParametersImpl:expectedPositive", 3, 4, 9, "imageSize");
  }
}

void CameraParametersImpl::checkRadialDistortion(
    const emlrtStack &sp, const real_T radialDistortion[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(radialDistortion[k])) &&
        (!muDoubleScalarIsNaN(radialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 16, "RadialDistortion");
  }
}

void CameraParametersImpl::checkTangentialDistortion(
    const emlrtStack &sp, const real_T tangentialDistortion[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(tangentialDistortion[k])) &&
        (!muDoubleScalarIsNaN(tangentialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 20,
        "TangentialDistortion");
  }
}

void CameraParametersImpl::parseInputsCodegen(const emlrtStack &sp,
                                              const real_T varargin_2[9],
                                              const real_T varargin_4[2],
                                              const real_T varargin_6[2],
                                              const real_T varargin_8[2],
                                              struct_T &paramStruct)
{
  static const int8_T b_varargin_2[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
  static const int8_T iv[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
  static const int8_T iv1[3]{1, 2, 5};
  static const int8_T iv2[3]{3, 6, 7};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  validateattributes(st, varargin_2);
  for (k = 0; k < 9; k++) {
    paramStruct.IntrinsicMatrix[k] = b_varargin_2[k];
  }
  st.site = &o_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!(varargin_2[k] == iv[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (b_varargin_2[k] != iv[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    b_st.site = &q_emlrtRSI;
    c_st.site = &s_emlrtRSI;
    validateattributes(c_st, varargin_2);
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      real_T d;
      d = varargin_2[iv1[k]];
      if ((d == 0.0) || muDoubleScalarIsNaN(d)) {
        k++;
      } else {
        p = true;
        exitg1 = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &b_emlrtRTEI,
          "vision:calibrate:kIntrinsicMatrixNonZeroElements",
          "vision:calibrate:kIntrinsicMatrixNonZeroElements", 0);
    }
    for (k = 0; k < 3; k++) {
      paramStruct.IntrinsicMatrix[3 * k] = varargin_2[k];
      paramStruct.IntrinsicMatrix[3 * k + 1] = varargin_2[k + 3];
      paramStruct.IntrinsicMatrix[3 * k + 2] = varargin_2[k + 6];
    }
  } else if (!b_p) {
    b_st.site = &r_emlrtRSI;
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (b_varargin_2[iv2[k]] != 0) {
        p = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "vision:calibrate:intrinsicMatrixNonZeroElements",
          "vision:calibrate:intrinsicMatrixNonZeroElements", 0);
    }
  }
  paramStruct.RadialDistortion[0] = varargin_4[0];
  paramStruct.TangentialDistortion[0] = varargin_6[0];
  paramStruct.ImageSize[0] = varargin_8[0];
  paramStruct.RadialDistortion[1] = varargin_4[1];
  paramStruct.TangentialDistortion[1] = varargin_6[1];
  paramStruct.ImageSize[1] = varargin_8[1];
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (CameraParametersImpl.cpp)
