//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzgetrf.h
//
// Code generation for function 'xzgetrf'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
int32_T xzgetrf(const emlrtStack &sp, real_T A[9], int32_T ipiv[3]);

}
} // namespace internal
} // namespace coder

// End of code generation (xzgetrf.h)
