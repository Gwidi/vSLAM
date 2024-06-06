//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena.h
//
// Code generation for function 'testyCodegena'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "testyCodegena_types.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void testyCodegena(testyCodegenaStackData *SD, const emlrtStack *sp,
                   const uint8_T image[1310720], const real_T imageSize[2],
                   const real_T principalPoint[2], const real_T focalLength[2],
                   const real_T radialDistortion[2], real_T numPoints,
                   real_T numSkipFrames, real_T numLevels, real_T scaleFactor,
                   boolean_T verbose, const real_T trackFeatureRange[2],
                   real_T loopClosureThreshold, boolean_T isReturnAll,
                   coder::array<real_T, 2U> &xyzPoint,
                   coder::array<real_T, 2U> &camPoses,
                   coder::vision::internal::vslam::vslamStatusType *status);

void testyCodegena_delete();

void testyCodegena_emx_free();

void testyCodegena_emx_init();

void testyCodegena_init();

void testyCodegena_new();

// End of code generation (testyCodegena.h)
