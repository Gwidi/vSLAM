//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// CameraParametersImpl.h
//
// Code generation for function 'CameraParametersImpl'
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

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
class CameraParametersImpl {
public:
  static void checkRadialDistortion(const emlrtStack &sp,
                                    const real_T radialDistortion[2]);
  static void checkImageSize(const emlrtStack &sp, const real_T imageSize[2]);
};

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (CameraParametersImpl.h)
