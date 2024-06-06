//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// DistWrapper.h
//
// Code generation for function 'DistWrapper'
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
void DistWrapper(const emlrtStack *sp, const uint8_T image[1310720],
                 uint8_T outimage[1310720]);

void DistWrapper_delete();

void DistWrapper_emx_free();

void DistWrapper_emx_init();

void DistWrapper_init();

void DistWrapper_new();

emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

// End of code generation (DistWrapper.h)
