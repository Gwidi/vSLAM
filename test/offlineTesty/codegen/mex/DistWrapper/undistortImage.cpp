//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// undistortImage.cpp
//
// Code generation for function 'undistortImage'
//

// Include files
#include "undistortImage.h"
#include "CameraParametersImpl.h"
#include "DistWrapper_data.h"
#include "DistWrapper_internal_types.h"
#include "cameraIntrinsics.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo mb_emlrtRSI{
    14,               // lineNo
    "undistortImage", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/undistortImage.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    28,               // lineNo
    "undistortImage", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/undistortImage.m" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    29,               // lineNo
    "undistortImage", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/undistortImage.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    33,               // lineNo
    "undistortImage", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/undistortImage.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    34,               // lineNo
    "undistortImage", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/undistortImage.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    82,                                          // lineNo
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    99,                                          // lineNo
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    167,           // lineNo
    "parseInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    209,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    212,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    239,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo ld_emlrtRSI{
    8,                     // lineNo
    "validateFocalLength", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+inputValidation/validateFocalLength.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    8,                        // lineNo
    "validatePrincipalPoint", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+inputValidation/validatePrincipalPoint.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    150,                              // lineNo
    "cameraIntrinsicsImpl/checkSkew", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRTEInfo f_emlrtRTEI{
    17,               // lineNo
    9,                // colNo
    "checkImageSize", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+inputValidation/checkImageSize.m" // pName
};

// Function Definitions
namespace coder {
void undistortImage(const emlrtStack &sp, const uint8_T b_I[1310720],
                    cameraIntrinsics &intrinsics, uint8_T J[1310720])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  struct_T expl_temp;
  real_T b_focalLength[9];
  real_T focalLength[2];
  real_T newOrigin[2];
  real_T principalPoint[2];
  real_T skew;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &mb_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(256.0 * static_cast<real_T>(k) + 1024.0 == intrinsics.ImageSize[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
                                  "vision:calibrate:inconsistentImageSize",
                                  "vision:calibrate:inconsistentImageSize", 0);
  }
  st.site = &nb_emlrtRSI;
  intrinsics.CameraParameters->undistortImageImpl(st, b_I, J, newOrigin);
  st.site = &ob_emlrtRSI;
  principalPoint[0] = intrinsics.CameraParameters->K[6];
  principalPoint[1] = intrinsics.CameraParameters->K[7];
  st.site = &pb_emlrtRSI;
  focalLength[0] = intrinsics.CameraParameters->K[0];
  focalLength[1] = intrinsics.CameraParameters->K[4];
  st.site = &qb_emlrtRSI;
  skew = intrinsics.CameraParameters->K[3];
  st.site = &pb_emlrtRSI;
  principalPoint[0] -= newOrigin[0];
  principalPoint[1] -= newOrigin[1];
  b_st.site = &d_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  d_st.site = &hd_emlrtRSI;
  e_st.site = &id_emlrtRSI;
  f_st.site = &ld_emlrtRSI;
  g_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(focalLength[k])) &&
        (!muDoubleScalarIsNaN(focalLength[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &g_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraIntrinsics:expectedFinite", 3, 4, 11, "focalLength");
  }
  g_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(focalLength[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &g_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:cameraIntrinsics:expectedPositive", 3, 4, 11, "focalLength");
  }
  e_st.site = &jd_emlrtRSI;
  f_st.site = &md_emlrtRSI;
  g_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(principalPoint[k])) &&
        (!muDoubleScalarIsNaN(principalPoint[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &g_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraIntrinsics:expectedFinite", 3, 4, 14, "principalPoint");
  }
  g_st.site = &p_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(principalPoint[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &g_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:cameraIntrinsics:expectedPositive", 3, 4, 14, "principalPoint");
  }
  e_st.site = &kd_emlrtRSI;
  f_st.site = &nd_emlrtRSI;
  g_st.site = &p_emlrtRSI;
  if (muDoubleScalarIsInf(skew) || muDoubleScalarIsNaN(skew)) {
    emlrtErrorWithMessageIdR2018a(
        &g_st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraIntrinsics:expectedFinite", 3, 4, 4, "Skew");
  }
  c_st.site = &gd_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  e_st.site = &g_emlrtRSI;
  f_st.site = &i_emlrtRSI;
  e_st.site = &h_emlrtRSI;
  b_focalLength[0] = focalLength[0];
  b_focalLength[3] = skew;
  b_focalLength[6] = principalPoint[0];
  b_focalLength[1] = 0.0;
  b_focalLength[4] = focalLength[1];
  b_focalLength[7] = principalPoint[1];
  b_focalLength[2] = 0.0;
  b_focalLength[5] = 0.0;
  b_focalLength[8] = 1.0;
  newOrigin[0] = 0.0;
  principalPoint[0] = 0.0;
  focalLength[0] = 1024.0;
  newOrigin[1] = 0.0;
  principalPoint[1] = 0.0;
  focalLength[1] = 1280.0;
  f_st.site = &j_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::parseInputsCodegen(
      f_st, b_focalLength, newOrigin, principalPoint, focalLength, expl_temp);
  f_st.site = &k_emlrtRSI;
  g_st.site = &u_emlrtRSI;
  f_st.site = &k_emlrtRSI;
  g_st.site = &v_emlrtRSI;
  f_st.site = &l_emlrtRSI;
  g_st.site = &x_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkRadialDistortion(
      g_st, expl_temp.RadialDistortion);
  g_st.site = &y_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::
      checkTangentialDistortion(g_st, expl_temp.TangentialDistortion);
  g_st.site = &ab_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkImageSize(
      g_st, expl_temp.ImageSize);
  g_st.site = &bb_emlrtRSI;
  h_st.site = &gb_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkImageSize(
      h_st, expl_temp.ImageSize);
  g_st.site = &cb_emlrtRSI;
  f_st.site = &m_emlrtRSI;
  g_st.site = &ib_emlrtRSI;
  b_st.site = &c_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  d_st.site = &lb_emlrtRSI;
}

} // namespace coder

// End of code generation (undistortImage.cpp)
