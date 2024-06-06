//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cameraParameters.h
//
// Code generation for function 'cameraParameters'
//

#pragma once

// Include files
#include "ImageTransformer.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
class cameraParameters {
public:
  void undistortImageImpl(const emlrtStack &sp, const uint8_T b_I[1310720],
                          uint8_T Jout[1310720], real_T newOrigin[2]);
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T K[9];
  vision::internal::calibration::ImageTransformer UndistortMap;
};

} // namespace coder

// End of code generation (cameraParameters.h)
