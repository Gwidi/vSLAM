//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// monovslam.h
//
// Code generation for function 'monovslam'
//

#pragma once

// Include files
#include "MonoVisualSLAMBuildable.h"
#include "cameraIntrinsics.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct testyCodegenaStackData;

namespace coder {
class rigidtform3d;

}

// Type Definitions
namespace coder {
class monovslam {
public:
  monovslam *init(const emlrtStack &sp, cameraIntrinsics &intrinsics,
                  real_T args_MaxNumPoints, real_T args_SkipMaxFrames,
                  real_T args_NumLevels, real_T args_ScaleFactor,
                  boolean_T args_Verbose,
                  const real_T args_TrackFeatureRange[2],
                  real_T args_LoopClosureThreshold);
  void addFrame(testyCodegenaStackData *SD, const emlrtStack &sp,
                const uint8_T b_I[1310720]);
  void poses(const emlrtStack &sp, rigidtform3d &camPoses);
  boolean_T matlabCodegenIsDeleted;
  cameraIntrinsics Intrinsics;
  real_T ScaleFactor;
  real_T NumLevels;
  real_T MaxNumPoints;
  real_T SkipMaxFrames;
  real_T TrackFeatureRange[2];
  real_T LoopClosureThreshold;
  boolean_T Verbose;
  vision::internal::buildable::MonoVisualSLAMBuildable SlamObj;

private:
  real_T ThreadLevel;
};

} // namespace coder

// End of code generation (monovslam.h)
