//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xaxpy.cpp
//
// Code generation for function 'xaxpy'
//

// Include files
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void b_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[16], int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T i;
    i = n - 1;
    for (int32_T k{0}; k <= i; k++) {
      int32_T i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

void xaxpy(int32_T n, real_T a, const real_T x[4], int32_T ix0, real_T y[16],
           int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T i;
    i = n - 1;
    for (int32_T k{0}; k <= i; k++) {
      int32_T i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * x[(ix0 + k) - 1];
    }
  }
}

void xaxpy(const emlrtStack &sp, int32_T n, real_T a, const real_T x[16],
           int32_T ix0, real_T y[4], int32_T iy0)
{
  int32_T i1;
  int32_T xaxpy_numThreads;
  if (!(a == 0.0)) {
    int32_T i;
    int32_T ix;
    int32_T iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    i = n - 1;
    if (static_cast<int32_T>(n < 600)) {
      for (int32_T k{0}; k <= i; k++) {
        ix = (iy0 + k) - 1;
        y[ix] += a * x[(ix0 + k) - 1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      xaxpy_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(xaxpy_numThreads) private(i1)

      for (int32_T k = 0; k <= i; k++) {
        i1 = iy + k;
        y[i1] += a * x[ix + k];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  }
}

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T i;
    i = n - 1;
    for (int32_T k{0}; k <= i; k++) {
      int32_T i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

void xaxpy(real_T a, const real_T x[9], int32_T ix0, real_T y[3])
{
  if (!(a == 0.0)) {
    for (int32_T k{0}; k < 2; k++) {
      y[k + 1] += a * x[(ix0 + k) - 1];
    }
  }
}

void xaxpy(real_T a, const real_T x[3], real_T y[9], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (int32_T k{0}; k < 2; k++) {
      int32_T i;
      i = (iy0 + k) - 1;
      y[i] += a * x[k + 1];
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xaxpy.cpp)
