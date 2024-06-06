//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_testyCodegena_mex.h
//
// Code generation for function '_coder_testyCodegena_mex'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "testyCodegena_types.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void testyCodegena_mexFunction(testyCodegenaStackData *SD, int32_T nlhs,
                               mxArray *plhs[3], int32_T nrhs,
                               const mxArray *prhs[13]);

// End of code generation (_coder_testyCodegena_mex.h)
