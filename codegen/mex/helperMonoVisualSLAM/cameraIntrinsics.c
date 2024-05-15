/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cameraIntrinsics.c
 *
 * Code generation for function 'cameraIntrinsics'
 *
 */

/* Include files */
#include "cameraIntrinsics.h"
#include "CameraParametersImpl.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = {
    26,                                  /* lineNo */
    "cameraIntrinsics/cameraIntrinsics", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    25,                                  /* lineNo */
    "cameraIntrinsics/cameraIntrinsics", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    100,                                         /* lineNo */
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    136,                                     /* lineNo */
    "cameraIntrinsicsImpl/cameraParameters", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI =
    {
        210,                                 /* lineNo */
        "cameraParameters/cameraParameters", /* fcnName */
        "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/"
        "cameraParameters.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI =
    {
        211,                                 /* lineNo */
        "cameraParameters/cameraParameters", /* fcnName */
        "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/"
        "cameraParameters.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    9,                             /* lineNo */
    "CustomDisplay/CustomDisplay", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/CustomDisplay.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    245,                                         /* lineNo */
    "CameraParametersImpl/CameraParametersImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    241,                                         /* lineNo */
    "CameraParametersImpl/CameraParametersImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    247,                                         /* lineNo */
    "CameraParametersImpl/CameraParametersImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    266,                                         /* lineNo */
    "CameraParametersImpl/CameraParametersImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    364,                                       /* lineNo */
    "CameraParametersImpl/parseInputsCodegen", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    384,                                       /* lineNo */
    "CameraParametersImpl/parseInputsCodegen", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    1185,                           /* lineNo */
    "checkAssignedIntrinsicMatrix", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    6,                             /* lineNo */
    "HandleCodegen/HandleCodegen", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+enforcescalar/HandleCodegen.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    289,                                   /* lineNo */
    "CameraParametersImpl/validateInputs", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    292,                                   /* lineNo */
    "CameraParametersImpl/validateInputs", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    295,                                   /* lineNo */
    "CameraParametersImpl/validateInputs", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    296,                                   /* lineNo */
    "CameraParametersImpl/validateInputs", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    313,                                   /* lineNo */
    "CameraParametersImpl/validateInputs", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    472,                                  /* lineNo */
    "CameraParametersImpl/set.ImageSize", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    43,                                  /* lineNo */
    "ImageTransformer/ImageTransformer", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    305,                                                    /* lineNo */
    "cameraIntrinsics/initializeCameraIntrinsicsArrayData", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    34,                                            /* lineNo */
    "cameraIntrinsicsArray/cameraIntrinsicsArray", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsicsArray.m" /* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    624,                                         /* lineNo */
    13,                                          /* colNo */
    "CameraParametersImpl/checkIntrinsicMatrix", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pName */
};

/* Function Definitions */
real_T c_cameraIntrinsics_cameraIntrin(const emlrtStack *sp,
                                       real_T this_FocalLength[2],
                                       real_T this_PrincipalPoint[2],
                                       real_T this_ImageSize[2],
                                       real_T this_RadialDistortion[2],
                                       real_T this_TangentialDistortion[2],
                                       real_T this_K[9])
{
  static const real_T dv[9] = {535.4, 0.0,   0.0,   0.0, 539.2,
                               0.0,   320.1, 247.6, 1.0};
  static const int8_T b_iv[3] = {1, 2, 5};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T dv1[2];
  real_T this_Skew;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
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
  memcpy(&this_K[0], &dv[0], 9U * sizeof(real_T));
  st.site = &h_emlrtRSI;
  this_FocalLength[0] = 535.4;
  this_PrincipalPoint[0] = 320.1;
  this_ImageSize[0] = 480.0;
  this_RadialDistortion[0] = 0.0;
  this_TangentialDistortion[0] = 0.0;
  this_FocalLength[1] = 539.2;
  this_PrincipalPoint[1] = 247.6;
  this_ImageSize[1] = 640.0;
  this_RadialDistortion[1] = 0.0;
  this_TangentialDistortion[1] = 0.0;
  this_Skew = 0.0;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  e_st.site = &m_emlrtRSI;
  d_st.site = &l_emlrtRSI;
  e_st.site = &n_emlrtRSI;
  f_st.site = &r_emlrtRSI;
  f_st.site = &s_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!(this_K[k] == iv[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    g_st.site = &u_emlrtRSI;
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(this_K[b_iv[k]] == 0.0)) {
        p = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &g_st, &f_emlrtRTEI,
          "vision:calibrate:kIntrinsicMatrixNonZeroElements",
          "vision:calibrate:kIntrinsicMatrixNonZeroElements", 0);
    }
  }
  e_st.site = &o_emlrtRSI;
  f_st.site = &w_emlrtRSI;
  e_st.site = &p_emlrtRSI;
  f_st.site = &y_emlrtRSI;
  f_st.site = &ab_emlrtRSI;
  dv1[0] = 480.0;
  dv1[1] = 640.0;
  f_st.site = &bb_emlrtRSI;
  c_CameraParametersImpl_checkIma(&f_st, dv1);
  f_st.site = &cb_emlrtRSI;
  dv1[0] = 480.0;
  dv1[1] = 640.0;
  g_st.site = &hb_emlrtRSI;
  c_CameraParametersImpl_checkIma(&g_st, dv1);
  f_st.site = &db_emlrtRSI;
  e_st.site = &q_emlrtRSI;
  f_st.site = &jb_emlrtRSI;
  st.site = &g_emlrtRSI;
  b_st.site = &kb_emlrtRSI;
  c_st.site = &lb_emlrtRSI;
  return this_Skew;
}

/* End of code generation (cameraIntrinsics.c) */
