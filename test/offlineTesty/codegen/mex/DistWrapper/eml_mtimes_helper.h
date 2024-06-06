//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_mtimes_helper.h
//
// Code generation for function 'eml_mtimes_helper'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void binary_expand_op(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                      const real_T in2[2], const coder::array<real_T, 1U> &in3);

void binary_expand_op_1(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                        const real_T in2[2],
                        const coder::array<real_T, 1U> &in3);

// End of code generation (eml_mtimes_helper.h)
