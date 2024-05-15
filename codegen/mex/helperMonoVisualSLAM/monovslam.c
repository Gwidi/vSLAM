/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * monovslam.c
 *
 * Code generation for function 'monovslam'
 *
 */

/* Include files */
#include "monovslam.h"
#include "helperMonoVisualSLAM_data.h"
#include "helperMonoVisualSLAM_internal_types.h"
#include "helperMonoVisualSLAM_types.h"
#include "rt_nonfinite.h"
#include "libmwrgb2gray_tbb.h"
#include "mwmathutil.h"
#include "vslam_core_api.hpp"

/* Variable Definitions */
static emlrtRSInfo qb_emlrtRSI = {
    99,                   /* lineNo */
    "monovslam/addFrame", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo rb_emlrtRSI = {
    101,                  /* lineNo */
    "monovslam/addFrame", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo sb_emlrtRSI = {
    104,                  /* lineNo */
    "monovslam/addFrame", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRTEInfo h_emlrtRTEI = {
    10,             /* lineNo */
    23,             /* colNo */
    "validatesize", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatesize.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    15,             /* lineNo */
    19,             /* colNo */
    "validatesize", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatesize.m" /* pName */
};

/* Function Definitions */
void monovslam_addFrame(helperMonoVisualSLAMStackData *SD, const emlrtStack *sp,
                        monovslam *b_vslam, const uint8_T b_I[921600])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  rgb2gray_tbb_uint8(&b_I[0], 307200.0, &SD->f0.Iu8_gray[0], true);
  st.site = &rb_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  p = true;
  for (k = 0; k < 2; k++) {
    if (p) {
      d = b_vslam->Intrinsics.ImageSize[k];
      if ((!(d != d)) && (muDoubleScalarIsInf(d) || (!(d >= 0.0)) ||
                          (!(d == muDoubleScalarFloor(d))))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
                                  "MATLAB:validateattributes:badSizeArray",
                                  "MATLAB:validateattributes:badSizeArray", 0);
  }
  p = true;
  for (k = 0; k < 2; k++) {
    if (p) {
      d = b_vslam->Intrinsics.ImageSize[k];
      if ((!(d != d)) && (!(d == 160.0 * (real_T)k + 480.0))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:monovslam:incorrectSize", 3, 4, 1, "I");
  }
  st.site = &sb_emlrtRSI;
  MonoVisualSLAM_addFrame(b_vslam->SlamObj.SlamInternal, &SD->f0.Iu8_gray[0],
                          480, 640, true);
}

/* End of code generation (monovslam.c) */
