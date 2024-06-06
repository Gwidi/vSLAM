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
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo x_emlrtRSI{
    641,                                          // lineNo
    "CameraParametersImpl/checkRadialDistortion", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    661,                                   // lineNo
    "CameraParametersImpl/checkImageSize", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
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
  st.site = &ub_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(imageSize[k])) &&
        (!muDoubleScalarIsNaN(imageSize[k])) &&
        (muDoubleScalarFloor(imageSize[k]) == imageSize[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }
  b_st.site = &u_emlrtRSI;
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
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &u_emlrtRSI;
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
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 16, "RadialDistortion");
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (CameraParametersImpl.cpp)
