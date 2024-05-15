/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xscal.c
 *
 * Code generation for function 'xscal'
 *
 */

/* Include files */
#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo wc_emlrtRSI = {
    31,      /* lineNo */
    "xscal", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+blas/"
    "xscal.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    18,      /* lineNo */
    "xscal", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+refblas/"
    "xscal.m" /* pathName */
};

/* Function Definitions */
void b_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 2;
  b_st.site = &xc_emlrtRSI;
  if ((ix0 <= ix0 + 2) && (ix0 + 2 > 2147483646)) {
    c_st.site = &tc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void c_xscal(const emlrtStack *sp, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 2;
  b_st.site = &xc_emlrtRSI;
  if ((ix0 <= ix0 + 2) && (ix0 + 2 > 2147483646)) {
    c_st.site = &tc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] = -x[k - 1];
  }
}

void d_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[16],
             int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &xc_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &tc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void e_xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[4],
             int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &xc_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &tc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void f_xscal(real_T a, real_T x[3])
{
  int32_T k;
  for (k = 2; k < 4; k++) {
    x[k - 1] *= a;
  }
}

void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &xc_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &tc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* End of code generation (xscal.c) */
