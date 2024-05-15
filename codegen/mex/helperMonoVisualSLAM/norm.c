/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "norm.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wd_emlrtRSI = {
    119,    /* lineNo */
    "norm", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/matfun/norm.m" /* pathName
                                                                            */
};

static emlrtRSInfo xd_emlrtRSI = {
    156,        /* lineNo */
    "mat2norm", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/matfun/norm.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    yd_emlrtRSI =
        {
            28,    /* lineNo */
            "svd", /* fcnName */
            "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
            "svd.m" /* pathName */
};

/* Function Definitions */
real_T b_norm(const emlrtStack *sp, const real_T x[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_x[9];
  real_T y;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  y = 0.0;
  for (i = 0; i < 9; i++) {
    real_T absx;
    absx = muDoubleScalarAbs(x[i]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
    real_T s[3];
    b_st.site = &xd_emlrtRSI;
    c_st.site = &yd_emlrtRSI;
    d_st.site = &sd_emlrtRSI;
    memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
    e_st.site = &td_emlrtRSI;
    b_xzsvdc(&e_st, b_x, s);
    y = s[0];
  }
  return y;
}

real_T c_norm(const emlrtStack *sp, const real_T x[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_x[16];
  real_T y;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  y = 0.0;
  for (i = 0; i < 16; i++) {
    real_T absx;
    absx = muDoubleScalarAbs(x[i]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
    real_T s[4];
    b_st.site = &xd_emlrtRSI;
    c_st.site = &yd_emlrtRSI;
    d_st.site = &sd_emlrtRSI;
    memcpy(&b_x[0], &x[0], 16U * sizeof(real_T));
    e_st.site = &td_emlrtRSI;
    c_xzsvdc(&e_st, b_x, s);
    y = s[0];
  }
  return y;
}

/* End of code generation (norm.c) */
