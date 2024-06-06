//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzgetrf.cpp
//
// Code generation for function 'xzgetrf'
//

// Include files
#include "xzgetrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace reflapack {
int32_T xzgetrf(const emlrtStack &sp, real_T A[9], int32_T ipiv[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T info;
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
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  info = 0;
  for (int32_T j{0}; j < 2; j++) {
    real_T smax;
    int32_T a;
    int32_T b_tmp;
    int32_T jA;
    int32_T jp1j;
    int32_T k;
    b_tmp = j << 2;
    jp1j = b_tmp + 2;
    jA = 3 - j;
    a = 0;
    smax = muDoubleScalarAbs(A[b_tmp]);
    for (k = 2; k <= jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (A[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = jA + 1;
        smax = A[j];
        A[j] = A[jA];
        A[jA] = smax;
        smax = A[j + 3];
        A[j + 3] = A[jA + 3];
        A[jA + 3] = smax;
        smax = A[j + 6];
        A[j + 6] = A[jA + 6];
        A[jA + 6] = smax;
      }
      k = (b_tmp - j) + 3;
      st.site = &we_emlrtRSI;
      for (a = jp1j; a <= k; a++) {
        A[a - 1] /= A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    k = 1 - j;
    st.site = &xe_emlrtRSI;
    b_st.site = &ye_emlrtRSI;
    c_st.site = &af_emlrtRSI;
    d_st.site = &bf_emlrtRSI;
    jA = b_tmp + 5;
    for (jp1j = 0; jp1j <= k; jp1j++) {
      smax = A[(b_tmp + jp1j * 3) + 3];
      if (smax != 0.0) {
        a = (jA - j) + 1;
        e_st.site = &cf_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          f_st.site = &ne_emlrtRSI;
          check_forloop_overflow_error(f_st);
        }
        for (int32_T ijA{jA}; ijA <= a; ijA++) {
          A[ijA - 1] += A[((b_tmp + ijA) - jA) + 1] * -smax;
        }
      }
      jA += 3;
    }
  }
  if ((info == 0) && (!(A[8] != 0.0))) {
    info = 3;
  }
  return info;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzgetrf.cpp)
