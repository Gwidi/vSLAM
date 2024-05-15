/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constrainToRotationMatrix3D.c
 *
 * Code generation for function 'constrainToRotationMatrix3D'
 *
 */

/* Include files */
#include "constrainToRotationMatrix3D.h"
#include "helperMonoVisualSLAM_data.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "xzgetrf.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = {
    10,                            /* lineNo */
    "constrainToRotationMatrix3D", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/constrainToRotationMatrix3D.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    17,                            /* lineNo */
    "constrainToRotationMatrix3D", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/constrainToRotationMatrix3D.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    35,                            /* lineNo */
    "constrainToRotationMatrix3D", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/constrainToRotationMatrix3D.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    36,    /* lineNo */
    "svd", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    rd_emlrtRSI =
        {
            52,    /* lineNo */
            "svd", /* fcnName */
            "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
            "svd.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    21,    /* lineNo */
    "det", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/matfun/det.m" /* pathName
                                                                           */
};

/* Function Definitions */
void constrainToRotationMatrix3D(const emlrtStack *sp, const real_T R[9],
                                 real_T Rc[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T R_clamped[9];
  real_T V[9];
  real_T b_R_clamped[9];
  real_T minval[9];
  real_T d;
  int32_T ipiv[3];
  int32_T i;
  int32_T k;
  boolean_T isodd;
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
  for (k = 0; k < 9; k++) {
    R_clamped[k] = muDoubleScalarMax(muDoubleScalarMin(R[k], 1.0), -1.0);
  }
  real_T S[3];
  st.site = &nd_emlrtRSI;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  d_st.site = &sd_emlrtRSI;
  memcpy(&b_R_clamped[0], &R_clamped[0], 9U * sizeof(real_T));
  e_st.site = &td_emlrtRSI;
  xzsvdc(&e_st, b_R_clamped, minval, S, V);
  for (i = 0; i < 3; i++) {
    real_T b_d;
    real_T d1;
    d = minval[i];
    b_d = minval[i + 3];
    d1 = minval[i + 6];
    for (k = 0; k < 3; k++) {
      Rc[i + 3 * k] = (d * V[k] + b_d * V[k + 3]) + d1 * V[k + 6];
    }
  }
  st.site = &od_emlrtRSI;
  b_st.site = &ud_emlrtRSI;
  memcpy(&minval[0], &Rc[0], 9U * sizeof(real_T));
  c_st.site = &vd_emlrtRSI;
  xzgetrf(&c_st, minval, ipiv);
  isodd = (ipiv[0] > 1);
  d = minval[0] * minval[4] * minval[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    d = -d;
  }
  if (d < 0.0) {
    for (i = 0; i < 3; i++) {
      k = 3 * i + 1;
      d = Rc[3 * i];
      Rc[3 * i] = Rc[k];
      Rc[k] = d;
    }
  }
  for (i = 0; i < 9; i++) {
    minval[i] = R_clamped[i] - Rc[i];
  }
  st.site = &pd_emlrtRSI;
  d = b_norm(&st, minval) / 2.2204460492503131E-16;
  if (d < 10.0) {
    memcpy(&Rc[0], &R_clamped[0], 9U * sizeof(real_T));
  }
}

/* End of code generation (constrainToRotationMatrix3D.c) */
