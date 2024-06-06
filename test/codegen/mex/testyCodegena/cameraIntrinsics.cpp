//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cameraIntrinsics.cpp
//
// Code generation for function 'cameraIntrinsics'
//

// Include files
#include "cameraIntrinsics.h"
#include "CameraParametersImpl.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "validateattributes.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo j_emlrtRSI{
    26,                                  // lineNo
    "cameraIntrinsics/cameraIntrinsics", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    25,                                  // lineNo
    "cameraIntrinsics/cameraIntrinsics", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    82,                                          // lineNo
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    99,                                          // lineNo
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    100,                                         // lineNo
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    167,           // lineNo
    "parseInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    209,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    212,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    215,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    231,                  // lineNo
    "parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    8,                     // lineNo
    "validateFocalLength", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+inputValidation/validateFocalLength.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    8,                        // lineNo
    "validatePrincipalPoint", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+inputValidation/validatePrincipalPoint.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    8,                   // lineNo
    "validateImageSize", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+inputValidation/validateImageSize.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    136,                                     // lineNo
    "cameraIntrinsicsImpl/cameraParameters", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

static emlrtRSInfo
    ab_emlrtRSI{
        47,                                  // lineNo
        "cameraParameters/cameraParameters", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/"
        "cameraParameters.m" // pathName
    };

static emlrtRSInfo
    bb_emlrtRSI{
        48,                                  // lineNo
        "cameraParameters/cameraParameters", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/"
        "cameraParameters.m" // pathName
    };

static emlrtRSInfo cb_emlrtRSI{
    9,                             // lineNo
    "CustomDisplay/CustomDisplay", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/CustomDisplay.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    246,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    242,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    248,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    267,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    365,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    385,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    930,                            // lineNo
    "checkAssignedIntrinsicMatrix", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    620,                                         // lineNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    1,                                           // lineNo
    "cameraIntrinsicsBase/cameraIntrinsicsBase", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsBase.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    6,                             // lineNo
    "HandleCodegen/HandleCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+enforcescalar/HandleCodegen.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    6,                       // lineNo
    "HandleBase/HandleBase", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+enforcescalar/HandleBase.m" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    290,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    293,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    296,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    297,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    314,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    651,                                              // lineNo
    "CameraParametersImpl/checkTangentialDistortion", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    473,                                  // lineNo
    "CameraParametersImpl/set.ImageSize", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    716,                                         // lineNo
    "CameraParametersImpl/checkNumRadialCoeffs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    23,                                  // lineNo
    "ImageTransformer/ImageTransformer", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    43,                                          // lineNo
    "ImageTransformerBase/ImageTransformerBase", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    305,                                                    // lineNo
    "cameraIntrinsics/initializeCameraIntrinsicsArrayData", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    34,                                            // lineNo
    "cameraIntrinsicsArray/cameraIntrinsicsArray", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsicsArray.m" // pathName
};

static emlrtRTEInfo t_emlrtRTEI{
    625,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/checkIntrinsicMatrix", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pName
};

// Function Definitions
namespace coder {
void cameraIntrinsics::b_cameraParameters(const emlrtStack &sp) const
{
  static const int8_T b_iv[3]{1, 2, 5};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &y_emlrtRSI;
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
  b_st.site = &ab_emlrtRSI;
  c_st.site = &cb_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  d_st.site = &hb_emlrtRSI;
  validateattributes(d_st, K);
  d_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!(K[k] == iv[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    e_st.site = &jb_emlrtRSI;
    f_st.site = &kb_emlrtRSI;
    validateattributes(f_st, K);
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      real_T d;
      d = K[b_iv[k]];
      if ((d == 0.0) || muDoubleScalarIsNaN(d)) {
        k++;
      } else {
        p = true;
        exitg1 = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &t_emlrtRTEI,
          "vision:calibrate:kIntrinsicMatrixNonZeroElements",
          "vision:calibrate:kIntrinsicMatrixNonZeroElements", 0);
    }
  }
  c_st.site = &eb_emlrtRSI;
  d_st.site = &lb_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &mb_emlrtRSI;
  e_st.site = &nb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  d_st.site = &ob_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkRadialDistortion(
      d_st, RadialDistortion);
  d_st.site = &pb_emlrtRSI;
  e_st.site = &tb_emlrtRSI;
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(TangentialDistortion[k])) &&
        (!muDoubleScalarIsNaN(TangentialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraParameters:expectedFinite", 3, 4, 20,
        "TangentialDistortion");
  }
  d_st.site = &qb_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkImageSize(
      d_st, ImageSize);
  d_st.site = &rb_emlrtRSI;
  e_st.site = &vb_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkImageSize(
      e_st, ImageSize);
  d_st.site = &sb_emlrtRSI;
  e_st.site = &wb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  d_st.site = &xb_emlrtRSI;
  e_st.site = &yb_emlrtRSI;
}

void cameraIntrinsics::init(const emlrtStack &sp, const real_T varargin_1[2],
                            const real_T varargin_2[2],
                            const real_T varargin_3[2],
                            const real_T varargin_5[2],
                            cameraParameters &iobj_0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
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
  st.site = &k_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &o_emlrtRSI;
  d_st.site = &p_emlrtRSI;
  e_st.site = &t_emlrtRSI;
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) &&
        (!muDoubleScalarIsNaN(varargin_1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraIntrinsics:expectedFinite", 3, 4, 11, "focalLength");
  }
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:cameraIntrinsics:expectedPositive", 3, 4, 11, "focalLength");
  }
  d_st.site = &q_emlrtRSI;
  e_st.site = &v_emlrtRSI;
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(varargin_2[k])) &&
        (!muDoubleScalarIsNaN(varargin_2[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cameraIntrinsics:expectedFinite", 3, 4, 14, "principalPoint");
  }
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_2[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:cameraIntrinsics:expectedPositive", 3, 4, 14, "principalPoint");
  }
  d_st.site = &r_emlrtRSI;
  e_st.site = &w_emlrtRSI;
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(varargin_3[k])) &&
        (!muDoubleScalarIsNaN(varargin_3[k])) &&
        (muDoubleScalarFloor(varargin_3[k]) == varargin_3[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:cameraIntrinsics:expectedInteger", 3, 4, 9, "imageSize");
  }
  f_st.site = &u_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_3[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &f_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:cameraIntrinsics:expectedPositive", 3, 4, 9, "imageSize");
  }
  d_st.site = &s_emlrtRSI;
  vision::internal::calibration::CameraParametersImpl::checkRadialDistortion(
      d_st, varargin_5);
  FocalLength[0] = varargin_1[0];
  FocalLength[1] = varargin_1[1];
  PrincipalPoint[0] = varargin_2[0];
  PrincipalPoint[1] = varargin_2[1];
  ImageSize[0] = varargin_3[0];
  ImageSize[1] = varargin_3[1];
  RadialDistortion[0] = varargin_5[0];
  RadialDistortion[1] = varargin_5[1];
  TangentialDistortion[0] = 0.0;
  TangentialDistortion[1] = 0.0;
  Skew = 0.0;
  b_st.site = &m_emlrtRSI;
  K[0] = varargin_1[0];
  K[3] = 0.0;
  K[6] = varargin_2[0];
  K[1] = 0.0;
  K[4] = varargin_1[1];
  K[7] = varargin_2[1];
  K[2] = 0.0;
  K[5] = 0.0;
  K[8] = 1.0;
  b_st.site = &n_emlrtRSI;
  b_cameraParameters(b_st);
  CameraParameters = &iobj_0;
  st.site = &j_emlrtRSI;
  b_st.site = &ac_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
}

} // namespace coder

// End of code generation (cameraIntrinsics.cpp)
