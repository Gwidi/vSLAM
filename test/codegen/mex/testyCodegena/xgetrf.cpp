//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgetrf.cpp
//
// Code generation for function 'xgetrf'
//

// Include files
#include "xgetrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xgetrf(const emlrtStack &sp, real_T A[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ve_emlrtRSI;
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
  for (int32_T j{0}; j < 3; j++) {
    real_T smax;
    int32_T a;
    int32_T b_tmp;
    int32_T iy;
    int32_T jp1j;
    int32_T k;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    iy = 4 - j;
    a = 0;
    smax = muDoubleScalarAbs(A[b_tmp]);
    for (k = 2; k <= iy; k++) {
      real_T s;
      s = muDoubleScalarAbs(A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (A[b_tmp + a] != 0.0) {
      if (a != 0) {
        iy = j + a;
        smax = A[j];
        A[j] = A[iy];
        A[iy] = smax;
        smax = A[j + 4];
        A[j + 4] = A[iy + 4];
        A[iy + 4] = smax;
        smax = A[j + 8];
        A[j + 8] = A[iy + 8];
        A[iy + 8] = smax;
        smax = A[j + 12];
        A[j + 12] = A[iy + 12];
        A[iy + 12] = smax;
      }
      k = (b_tmp - j) + 4;
      b_st.site = &we_emlrtRSI;
      for (iy = jp1j; iy <= k; iy++) {
        A[iy - 1] /= A[b_tmp];
      }
    }
    k = 2 - j;
    b_st.site = &xe_emlrtRSI;
    c_st.site = &ye_emlrtRSI;
    d_st.site = &af_emlrtRSI;
    e_st.site = &bf_emlrtRSI;
    iy = b_tmp + 6;
    for (jp1j = 0; jp1j <= k; jp1j++) {
      smax = A[(b_tmp + (jp1j << 2)) + 4];
      if (smax != 0.0) {
        a = (iy - j) + 2;
        f_st.site = &cf_emlrtRSI;
        if ((iy <= a) && (a > 2147483646)) {
          g_st.site = &ne_emlrtRSI;
          check_forloop_overflow_error(g_st);
        }
        for (int32_T ijA{iy}; ijA <= a; ijA++) {
          A[ijA - 1] += A[((b_tmp + ijA) - iy) + 1] * -smax;
        }
      }
      iy += 4;
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgetrf.cpp)
