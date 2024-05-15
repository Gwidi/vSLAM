/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM_internal_types.h
 *
 * Code generation for function 'helperMonoVisualSLAM'
 *
 */

#pragma once

/* Include files */
#include "helperMonoVisualSLAM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_c_vision_internal_buildable_Mon
#define typedef_c_vision_internal_buildable_Mon
typedef struct {
  void *SlamInternal;
} c_vision_internal_buildable_Mon;
#endif /* typedef_c_vision_internal_buildable_Mon */

#ifndef typedef_cameraIntrinsics
#define typedef_cameraIntrinsics
typedef struct {
  real_T FocalLength[2];
  real_T PrincipalPoint[2];
  real_T ImageSize[2];
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T Skew;
  real_T K[9];
} cameraIntrinsics;
#endif /* typedef_cameraIntrinsics */

#ifndef typedef_monovslam
#define typedef_monovslam
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  cameraIntrinsics Intrinsics;
  real_T ScaleFactor;
  real_T NumLevels;
  real_T MaxNumPoints;
  real_T SkipMaxFrames;
  real_T TrackFeatureRange[2];
  real_T LoopClosureThreshold;
  boolean_T Verbose;
  c_vision_internal_buildable_Mon SlamObj;
} monovslam;
#endif /* typedef_monovslam */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtEqualityCheckInfo
#define typedef_rtEqualityCheckInfo
typedef struct {
  int32_T nDims;
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtEqualityCheckInfo;
#endif /* typedef_rtEqualityCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (helperMonoVisualSLAM_internal_types.h) */
