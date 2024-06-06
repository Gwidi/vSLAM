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
#include "rtwtypes.h"
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
  void init(const emlrtStack &sp, const real_T varargin_1[2],
            const real_T varargin_2[2], const real_T varargin_3[2],
            const real_T varargin_5[2], cameraParameters &iobj_0);

private:
  void b_cameraParameters(const emlrtStack &sp) const;

public:
  real_T FocalLength[2];
  real_T PrincipalPoint[2];
  real_T ImageSize[2];
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T Skew;
  real_T K[9];
  cameraParameters *CameraParameters;
};

} // namespace coder

// End of code generation (cameraIntrinsics.h)
