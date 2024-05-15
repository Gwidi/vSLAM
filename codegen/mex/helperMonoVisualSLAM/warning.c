/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "warning.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = {
    14,        /* lineNo */
    25,        /* colNo */
    "warning", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warning.m" /* pName */
};

static emlrtMCInfo b_emlrtMCI = {
    14,        /* lineNo */
    9,         /* colNo */
    "warning", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warning.m" /* pName */
};

static emlrtRSInfo af_emlrtRSI = {
    14,        /* lineNo */
    "warning", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warning.m" /* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *m, const mxArray *m1,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)sp, 0, NULL, 2, &pArrays[0], "feval",
                        true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)sp, 1, &m, 2, &pArrays[0],
                               "feval", true, location);
}

void warning(const emlrtStack *sp)
{
  static const int32_T b_iv[2] = {1, 7};
  static const int32_T iv1[2] = {1, 7};
  static const int32_T iv2[2] = {1, 52};
  static const char_T c_u[52] = {
      'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e', 'o', 't', 'r', 'a',
      'n', 's', ':', 't', 'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', 'a',
      't', 'i', 'o', 'n', 'M', 'a', 't', 'r', 'i', 'x', 'B', 'a', 'd',
      'l', 'y', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e', 'd'};
  static const char_T b_u[7] = {'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7] = {'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *propValues;
  const mxArray *y;
  const char_T *propClasses = "coder.internal.string";
  const char_T *propNames = "Value";
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  propValues = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, propValues, &u[0]);
  emlrtAssign(&y, propValues);
  b_y = NULL;
  propValues = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 7, propValues, &b_u[0]);
  emlrtAssign(&b_y, propValues);
  c_y = NULL;
  m = NULL;
  emlrtAssign(&c_y, emlrtCreateClassInstance2022a((emlrtCTX)sp,
                                                  "coder.internal.string"));
  m = NULL;
  d_y = NULL;
  propValues = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)sp, 52, propValues, &c_u[0]);
  emlrtAssign(&d_y, propValues);
  emlrtAssign(&m, d_y);
  propValues = m;
  emlrtSetAllProperties((emlrtCTX)sp, &c_y, 0, 1, (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  emlrtAssign(&c_y, emlrtConvertInstanceToRedirectSource(
                        (emlrtCTX)sp, c_y, 0, "coder.internal.string"));
  st.site = &af_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

/* End of code generation (warning.c) */
