//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// norm.cpp
//
// Code generation for function 'norm'
//

// Include files
#include "norm.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo df_emlrtRSI{
    119,    // lineNo
    "norm", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/matfun/norm.m" // pathName
};

static emlrtRSInfo ef_emlrtRSI{
    156,        // lineNo
    "mat2norm", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/matfun/norm.m" // pathName
};

static emlrtRSInfo ff_emlrtRSI{
    28,    // lineNo
    "svd", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/svd.m" // pathName
};

// Function Definitions
namespace coder {
real_T b_norm(const emlrtStack &sp, const real_T x[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_x[9];
  real_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &df_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  y = 0.0;
  for (int32_T i{0}; i < 9; i++) {
    real_T absx;
    absx = muDoubleScalarAbs(x[i]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
    real_T s[3];
    b_st.site = &ef_emlrtRSI;
    c_st.site = &ff_emlrtRSI;
    d_st.site = &ud_emlrtRSI;
    std::copy(&x[0], &x[9], &b_x[0]);
    e_st.site = &vd_emlrtRSI;
    internal::reflapack::xzsvdc(e_st, b_x, s);
    y = s[0];
  }
  return y;
}

real_T c_norm(const emlrtStack &sp, const real_T x[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_x[16];
  real_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &df_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  y = 0.0;
  for (int32_T i{0}; i < 16; i++) {
    real_T absx;
    absx = muDoubleScalarAbs(x[i]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
    real_T s[4];
    b_st.site = &ef_emlrtRSI;
    c_st.site = &ff_emlrtRSI;
    d_st.site = &ud_emlrtRSI;
    std::copy(&x[0], &x[16], &b_x[0]);
    e_st.site = &vd_emlrtRSI;
    internal::reflapack::b_xzsvdc(e_st, b_x, s);
    y = s[0];
  }
  return y;
}

} // namespace coder

// End of code generation (norm.cpp)
