//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzsvdc.h
//
// Code generation for function 'xzsvdc'
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
void b_xzsvdc(const emlrtStack &sp, real_T A[16], real_T S[4]);

void xzsvdc(const emlrtStack &sp, real_T A[9], real_T U[9], real_T S[3],
            real_T V[9]);

void xzsvdc(const emlrtStack &sp, real_T A[9], real_T S[3]);

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzsvdc.h)
