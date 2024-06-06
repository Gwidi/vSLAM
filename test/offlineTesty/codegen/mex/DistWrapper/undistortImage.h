//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// undistortImage.h
//
// Code generation for function 'undistortImage'
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

// Type Declarations
namespace coder {
class cameraIntrinsics;

}

// Function Declarations
namespace coder {
void undistortImage(const emlrtStack &sp, const uint8_T b_I[1310720],
                    cameraIntrinsics &intrinsics, uint8_T J[1310720]);

}

// End of code generation (undistortImage.h)
