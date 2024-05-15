/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CameraParametersImpl.c
 *
 * Code generation for function 'CameraParametersImpl'
 *
 */

/* Include files */
#include "CameraParametersImpl.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = {
    660,                                   /* lineNo */
    "CameraParametersImpl/checkImageSize", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" /* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" /* pName */
};

/* Function Definitions */
void c_CameraParametersImpl_checkIma(const emlrtStack *sp,
                                     const real_T imageSize[2])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &t_emlrtRSI;
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
        &b_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }
}

/* End of code generation (CameraParametersImpl.c) */
