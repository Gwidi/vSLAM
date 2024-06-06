//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cameraIntrinsics.h
//
// Code generation for function 'cameraIntrinsics'
//

#pragma once

// Include files
#include "cameraIntrinsicsArray.h"
#include "rtwtypes.h"
#include "coder_bounded_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder {
class cameraParameters;

}

// Type Definitions
namespace coder {
class cameraIntrinsics {
public:
  real_T FocalLength[2];
  real_T PrincipalPoint[2];
  real_T ImageSize[2];
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T Skew;
  real_T K[9];
  cameraParameters *CameraParameters;
  bounded_array<vision::internal::codegen::cameraIntrinsicsArray, 1U, 2U>
      cameraIntrinsicsArrayData;
};

} // namespace coder

// End of code generation (cameraIntrinsics.h)
