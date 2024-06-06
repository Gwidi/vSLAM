//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena.cpp
//
// Code generation for function 'testyCodegena'
//

// Include files
#include "testyCodegena.h"
#include "MonoVisualSLAMBuildable.h"
#include "cameraIntrinsics.h"
#include "cameraParameters.h"
#include "monovslam.h"
#include "rigidtform3d.h"
#include "rigidtform3dImpl.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "testyCodegena_types.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mwmathutil.h"
#include "omp.h"
#include "vslam_core_api.hpp"
#include <cstring>

// Variable Definitions
static coder::monovslam vslam;

static boolean_T vslam_not_empty;

static boolean_T xyzPointsInternal_not_empty;

static emlrtRSInfo emlrtRSI{
    18,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    24,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    27,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    28,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    29,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    33,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    39,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    47,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    15,              // lineNo
    "testyCodegena", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    124,                        // lineNo
    "monovslam/hasNewKeyFrame", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo cd_emlrtRSI{
    141,                   // lineNo
    "monovslam/mapPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo dd_emlrtRSI{
    81,                                       // lineNo
    "MonoVisualSLAMBuildable/getWorldPoints", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pathName
};

static emlrtRSInfo ed_emlrtRSI{
    51,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    119,               // lineNo
    "computeDimsData", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo dg_emlrtRSI{
    130,                     // lineNo
    "monovslam/checkStatus", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    81,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    74,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtDCInfo emlrtDCI{
    78,                                       // lineNo
    31,                                       // colNo
    "MonoVisualSLAMBuildable/getWorldPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    1                                       // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    78,                                       // lineNo
    31,                                       // colNo
    "MonoVisualSLAMBuildable/getWorldPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    4                                       // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    45,              // lineNo
    31,              // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m", // pName
    1                                   // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    78,                                       // lineNo
    13,                                       // colNo
    "MonoVisualSLAMBuildable/getWorldPoints", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    1                                       // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    45,              // lineNo
    13,              // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m", // pName
    1                                   // checkKind
};

static emlrtBCInfo emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    47,              // lineNo
    17,              // colNo
    "camPoses",      // aName
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m", // pName
    0                                   // checkKind
};

static emlrtRTEInfo w_emlrtRTEI{
    78,                        // lineNo
    13,                        // colNo
    "MonoVisualSLAMBuildable", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    141,         // lineNo
    13,          // colNo
    "monovslam", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    31,              // lineNo
    5,               // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    50,              // lineNo
    13,              // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    45,              // lineNo
    13,              // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    41,              // lineNo
    13,              // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    39,              // lineNo
    13,              // colNo
    "testyCodegena", // fName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/testyCodegena.m" // pName
};

// Function Definitions
emlrtCTX emlrtGetRootTLSGlobal()
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void testyCodegena(testyCodegenaStackData *SD, const emlrtStack *sp,
                   const uint8_T image[1310720], const real_T imageSize[2],
                   const real_T principalPoint[2], const real_T focalLength[2],
                   const real_T radialDistortion[2], real_T numPoints,
                   real_T numSkipFrames, real_T numLevels, real_T scaleFactor,
                   boolean_T verbose, const real_T trackFeatureRange[2],
                   real_T loopClosureThreshold, boolean_T isReturnAll,
                   coder::array<real_T, 2U> &xyzPoint,
                   coder::array<real_T, 2U> &camPoses,
                   coder::vision::internal::vslam::vslamStatusType *status)
{
  static coder::cameraParameters gobj_1;
  static coder::rigidtform3d camPosesInternal;
  static coder::array<real_T, 2U> xyzPointsInternal;
  coder::cameraIntrinsics b_intrinsics;
  coder::cameraIntrinsics intrinsics;
  coder::rigidtform3d self;
  coder::vision::internal::buildable::MonoVisualSLAMBuildable obj;
  emlrtProfilerSentinel profilerSentinel;
  coder::array<real_T, 2U> output;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_numPoints;
  real_T d;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T numPoses;
  int32_T testyCodegena_numThreads;
  boolean_T guard1;
  boolean_T hasAdded;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionEntryCPP((char_T *)testyCodegena_complete_name,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  //    Copyright 2023 The MathWorks Inc.
  //  image,imageSize, ...
  //  principalPoint,focalLength,radialDistortion,numPoints,numSkipFrames,numLevels,
  //  ... verbose,trackFeatureRange
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  if (!vslam_not_empty) {
    emlrtMEXProfilingStatement(3, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(4, static_cast<boolean_T>(isMexOutdated));
    st.site = &i_emlrtRSI;
    intrinsics.init(st, focalLength, principalPoint, imageSize,
                    radialDistortion, gobj_1);
    emlrtMEXProfilingStatement(5, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(6, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));
    b_intrinsics = intrinsics;
    st.site = &emlrtRSI;
    vslam.init(st, b_intrinsics, numPoints, numSkipFrames, numLevels,
               scaleFactor, verbose, trackFeatureRange, loopClosureThreshold);
    vslam_not_empty = true;
    emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
  }
  //  Process each image frame
  emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
  st.site = &b_emlrtRSI;
  vslam.addFrame(SD, st, image);
  //  Get 3-D map points and camera poses
  emlrtMEXProfilingStatement(10, static_cast<boolean_T>(isMexOutdated));
  guard1 = false;
  if (!xyzPointsInternal_not_empty) {
    guard1 = true;
  } else {
    st.site = &c_emlrtRSI;
    b_st.site = &bd_emlrtRSI;
    obj = vslam.SlamObj;
    hasAdded = MonoVisualSLAM_hasNewKeyFrame(obj.SlamInternal);
    if (hasAdded) {
      guard1 = true;
    }
  }
  if (guard1) {
    real_T d1;
    emlrtMEXProfilingStatement(11, static_cast<boolean_T>(isMexOutdated));
    st.site = &d_emlrtRSI;
    b_st.site = &cd_emlrtRSI;
    obj = vslam.SlamObj;
    b_numPoints = MonoVisualSLAM_getNumWorldPoints(obj.SlamInternal);
    d = b_numPoints * 3.0;
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &b_emlrtDCI, &b_st);
    }
    d1 = static_cast<int32_T>(muDoubleScalarFloor(d));
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, &b_st);
    }
    output.set_size(&w_emlrtRTEI, &b_st, 1, static_cast<int32_T>(d));
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &d_emlrtDCI, &b_st);
    }
    loop_ub = static_cast<int32_T>(d);
    if (static_cast<int32_T>(static_cast<int32_T>(d) < 600)) {
      for (int32_T i{0}; i < loop_ub; i++) {
        output[i] = 0.0;
      }
    } else {
      emlrtEnterParallelRegion(&b_st,
                               static_cast<boolean_T>(omp_in_parallel()));
      testyCodegena_numThreads = emlrtAllocRegionTLSs(
          b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(testyCodegena_numThreads)

      for (int32_T i = 0; i < loop_ub; i++) {
        output[i] = 0.0;
      }
      emlrtExitParallelRegion(&b_st, static_cast<boolean_T>(omp_in_parallel()));
    }
    MonoVisualSLAM_getWorldPoints(obj.SlamInternal, &output[0]);
    if (b_numPoints > 0.0) {
      c_st.site = &dd_emlrtRSI;
      maxdimlen = output.size(1);
      d_st.site = &ed_emlrtRSI;
      e_st.site = &fd_emlrtRSI;
      if ((b_numPoints != muDoubleScalarFloor(b_numPoints)) ||
          muDoubleScalarIsInf(b_numPoints) || (b_numPoints > 2.147483647E+9)) {
        emlrtErrorWithMessageIdR2018a(&e_st, &emlrtRTEI,
                                      "Coder:MATLAB:NonIntegerInput",
                                      "Coder:MATLAB:NonIntegerInput", 4, 12,
                                      MIN_int32_T, 12, MAX_int32_T);
      }
      loop_ub = 1;
      if (output.size(1) > 1) {
        loop_ub = output.size(1);
      }
      maxdimlen = muIntScalarMax_sint32(maxdimlen, loop_ub);
      if (maxdimlen < 3) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }
      if (static_cast<int32_T>(b_numPoints) > maxdimlen) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }
      i1 = 3 * static_cast<int32_T>(b_numPoints);
      if (i1 != output.size(1)) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &b_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }
      loop_ub = static_cast<int32_T>(b_numPoints);
      xyzPointsInternal.set_size(&x_emlrtRTEI, &b_st,
                                 static_cast<int32_T>(b_numPoints), 3);
      maxdimlen = static_cast<int32_T>(b_numPoints);
      if (static_cast<int32_T>(i1 < 600)) {
        for (int32_T i{0}; i < 3; i++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            xyzPointsInternal[i2 + xyzPointsInternal.size(0) * i] =
                output[i + 3 * i2];
          }
        }
      } else {
        emlrtEnterParallelRegion(&b_st,
                                 static_cast<boolean_T>(omp_in_parallel()));
        testyCodegena_numThreads = emlrtAllocRegionTLSs(
            b_st.tls, static_cast<boolean_T>(omp_in_parallel()),
            omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(testyCodegena_numThreads) private(i2)

        for (int32_T i = 0; i < 3; i++) {
          for (i2 = 0; i2 < maxdimlen; i2++) {
            xyzPointsInternal[i2 + xyzPointsInternal.size(0) * i] =
                output[i + 3 * i2];
          }
        }
        emlrtExitParallelRegion(&b_st,
                                static_cast<boolean_T>(omp_in_parallel()));
      }
    } else {
      xyzPointsInternal.set_size(&x_emlrtRTEI, &b_st, 0, 3);
    }
    xyzPointsInternal_not_empty = (xyzPointsInternal.size(0) != 0);
    emlrtMEXProfilingStatement(12, static_cast<boolean_T>(isMexOutdated));
    st.site = &e_emlrtRSI;
    vslam.poses(st, camPosesInternal);
    emlrtMEXProfilingStatement(13, static_cast<boolean_T>(isMexOutdated));
  }
  emlrtMEXProfilingStatement(14, static_cast<boolean_T>(isMexOutdated));
  xyzPoint.set_size(&y_emlrtRTEI, sp, xyzPointsInternal.size(0), 3);
  loop_ub = xyzPointsInternal.size(0) * 3;
  if (static_cast<int32_T>(loop_ub < 600)) {
    for (int32_T i{0}; i < loop_ub; i++) {
      xyzPoint[i] = xyzPointsInternal[i];
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    testyCodegena_numThreads =
        emlrtAllocRegionTLSs(sp->tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(testyCodegena_numThreads)

    for (int32_T i = 0; i < loop_ub; i++) {
      xyzPoint[i] = xyzPointsInternal[i];
    }
    emlrtExitParallelRegion((emlrtCTX)sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  emlrtMEXProfilingStatement(15, static_cast<boolean_T>(isMexOutdated));
  st.site = &f_emlrtRSI;
  b_st.site = &dg_emlrtRSI;
  obj = vslam.SlamObj;
  b_numPoints = MonoVisualSLAM_getNumTrackedPoints(obj.SlamInternal);
  if (b_numPoints < vslam.TrackFeatureRange[0]) {
    *status = coder::vision::internal::vslam::vslamStatusType::TrackingLost;
  } else if (b_numPoints > vslam.TrackFeatureRange[1]) {
    *status =
        coder::vision::internal::vslam::vslamStatusType::FrequentKeyFrames;
  } else {
    *status =
        coder::vision::internal::vslam::vslamStatusType::TrackingSuccessful;
  }
  emlrtMEXProfilingStatement(16, static_cast<boolean_T>(isMexOutdated));
  numPoses = camPosesInternal.Data.size(0) * camPosesInternal.Data.size(1);
  //  Convert camera poses to homogeneous transformation matrices
  //  czy Zwrocic caly Poses czy nie
  emlrtMEXProfilingStatement(17, static_cast<boolean_T>(isMexOutdated));
  if (!isReturnAll) {
    emlrtMEXProfilingStatement(18, static_cast<boolean_T>(isMexOutdated));
    if (numPoses > 0) {
      real_T b_self[16];
      emlrtMEXProfilingStatement(19, static_cast<boolean_T>(isMexOutdated));
      st.site = &g_emlrtRSI;
      camPosesInternal.parenReference(st, static_cast<real_T>(numPoses), self);
      for (i1 = 0; i1 < 3; i1++) {
        maxdimlen = i1 << 2;
        b_self[maxdimlen] = self.R[3 * i1];
        b_self[maxdimlen + 1] = self.R[3 * i1 + 1];
        b_self[maxdimlen + 2] = self.R[3 * i1 + 2];
        b_self[i1 + 12] = self.Translation[i1];
      }
      b_self[3] = 0.0;
      b_self[7] = 0.0;
      b_self[11] = 0.0;
      b_self[15] = 1.0;
      camPoses.set_size(&db_emlrtRTEI, sp, 4, 4);
      for (i1 = 0; i1 < 16; i1++) {
        camPoses[i1] = b_self[i1];
      }
      emlrtMEXProfilingStatement(22, static_cast<boolean_T>(isMexOutdated));
    } else {
      int8_T b_I[16];
      emlrtMEXProfilingStatement(20, static_cast<boolean_T>(isMexOutdated));
      emlrtMEXProfilingStatement(21, static_cast<boolean_T>(isMexOutdated));
      for (i1 = 0; i1 < 16; i1++) {
        b_I[i1] = 0;
      }
      b_I[0] = 1;
      b_I[5] = 1;
      b_I[10] = 1;
      b_I[15] = 1;
      camPoses.set_size(&cb_emlrtRTEI, sp, 4, 4);
      for (i1 = 0; i1 < 16; i1++) {
        camPoses[i1] = b_I[i1];
      }
      emlrtMEXProfilingStatement(22, static_cast<boolean_T>(isMexOutdated));
    }
    emlrtMEXProfilingStatement(32, static_cast<boolean_T>(isMexOutdated));
  } else {
    emlrtMEXProfilingStatement(23, static_cast<boolean_T>(isMexOutdated));
    emlrtMEXProfilingStatement(24, static_cast<boolean_T>(isMexOutdated));
    if (numPoses > 0) {
      emlrtMEXProfilingStatement(25, static_cast<boolean_T>(isMexOutdated));
      d = static_cast<real_T>(numPoses) * 4.0;
      if (d != static_cast<int32_T>(d)) {
        emlrtIntegerCheckR2012b(d, &c_emlrtDCI, (emlrtConstCTX)sp);
      }
      camPoses.set_size(&bb_emlrtRTEI, sp, static_cast<int32_T>(d), 4);
      if (d != static_cast<int32_T>(d)) {
        emlrtIntegerCheckR2012b(d, &e_emlrtDCI, (emlrtConstCTX)sp);
      }
      loop_ub = static_cast<int32_T>(d) << 2;
      if (static_cast<int32_T>(loop_ub < 600)) {
        for (int32_T i{0}; i < loop_ub; i++) {
          camPoses[i] = 0.0;
        }
      } else {
        emlrtEnterParallelRegion((emlrtCTX)sp,
                                 static_cast<boolean_T>(omp_in_parallel()));
        testyCodegena_numThreads = emlrtAllocRegionTLSs(
            sp->tls, static_cast<boolean_T>(omp_in_parallel()),
            omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(testyCodegena_numThreads)

        for (int32_T i = 0; i < loop_ub; i++) {
          camPoses[i] = 0.0;
        }
        emlrtExitParallelRegion((emlrtCTX)sp,
                                static_cast<boolean_T>(omp_in_parallel()));
      }
      emlrtMEXProfilingStatement(26, static_cast<boolean_T>(isMexOutdated));
      for (loop_ub = 0; loop_ub < numPoses; loop_ub++) {
        emlrtMEXProfilingStatement(27, static_cast<boolean_T>(isMexOutdated));
        st.site = &h_emlrtRSI;
        camPosesInternal.parenReference(st, static_cast<real_T>(loop_ub) + 1.0,
                                        self);
        b_numPoints = (static_cast<real_T>(loop_ub) + 1.0) * 4.0 - 3.0;
        maxdimlen = camPoses.size(0);
        for (i1 = 0; i1 < 3; i1++) {
          if ((static_cast<int32_T>(b_numPoints) < 1) ||
              (static_cast<int32_T>(b_numPoints) > maxdimlen)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_numPoints), 1,
                                          maxdimlen, &emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          camPoses[(static_cast<int32_T>(b_numPoints) + camPoses.size(0) * i1) -
                   1] = self.R[3 * i1];
          if ((static_cast<int32_T>(b_numPoints + 1.0) < 1) ||
              (static_cast<int32_T>(b_numPoints + 1.0) > maxdimlen)) {
            emlrtDynamicBoundsCheckR2012b(
                static_cast<int32_T>(b_numPoints + 1.0), 1, maxdimlen,
                &emlrtBCI, (emlrtConstCTX)sp);
          }
          camPoses[(static_cast<int32_T>(b_numPoints + 1.0) +
                    camPoses.size(0) * i1) -
                   1] = self.R[3 * i1 + 1];
          if ((static_cast<int32_T>(b_numPoints + 2.0) < 1) ||
              (static_cast<int32_T>(b_numPoints + 2.0) > maxdimlen)) {
            emlrtDynamicBoundsCheckR2012b(
                static_cast<int32_T>(b_numPoints + 2.0), 1, maxdimlen,
                &emlrtBCI, (emlrtConstCTX)sp);
          }
          camPoses[(static_cast<int32_T>(b_numPoints + 2.0) +
                    camPoses.size(0) * i1) -
                   1] = self.R[3 * i1 + 2];
        }
        if ((static_cast<int32_T>(b_numPoints) < 1) ||
            (static_cast<int32_T>(b_numPoints) > camPoses.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_numPoints), 1,
                                        camPoses.size(0), &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        camPoses[(static_cast<int32_T>(b_numPoints) + camPoses.size(0) * 3) -
                 1] = self.Translation[0];
        if ((static_cast<int32_T>(b_numPoints + 1.0) < 1) ||
            (static_cast<int32_T>(b_numPoints + 1.0) > camPoses.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_numPoints + 1.0),
                                        1, camPoses.size(0), &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        camPoses[(static_cast<int32_T>(b_numPoints + 1.0) +
                  camPoses.size(0) * 3) -
                 1] = self.Translation[1];
        if ((static_cast<int32_T>(b_numPoints + 2.0) < 1) ||
            (static_cast<int32_T>(b_numPoints + 2.0) > camPoses.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_numPoints + 2.0),
                                        1, camPoses.size(0), &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        camPoses[(static_cast<int32_T>(b_numPoints + 2.0) +
                  camPoses.size(0) * 3) -
                 1] = self.Translation[2];
        hasAdded =
            ((static_cast<int32_T>(b_numPoints + 3.0) < 1) ||
             (static_cast<int32_T>(b_numPoints + 3.0) > camPoses.size(0)));
        if (hasAdded) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_numPoints + 3.0),
                                        1, camPoses.size(0), &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        camPoses[static_cast<int32_T>(b_numPoints + 3.0) - 1] = 0.0;
        camPoses[(static_cast<int32_T>(b_numPoints + 3.0) + camPoses.size(0)) -
                 1] = 0.0;
        camPoses[(static_cast<int32_T>(b_numPoints + 3.0) +
                  camPoses.size(0) * 2) -
                 1] = 0.0;
        camPoses[(static_cast<int32_T>(b_numPoints + 3.0) +
                  camPoses.size(0) * 3) -
                 1] = 1.0;
        emlrtMEXProfilingStatement(28, static_cast<boolean_T>(isMexOutdated));
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      emlrtMEXProfilingStatement(31, static_cast<boolean_T>(isMexOutdated));
    } else {
      int8_T b_I[16];
      emlrtMEXProfilingStatement(29, static_cast<boolean_T>(isMexOutdated));
      emlrtMEXProfilingStatement(30, static_cast<boolean_T>(isMexOutdated));
      for (i1 = 0; i1 < 16; i1++) {
        b_I[i1] = 0;
      }
      b_I[0] = 1;
      b_I[5] = 1;
      b_I[10] = 1;
      b_I[15] = 1;
      camPoses.set_size(&ab_emlrtRTEI, sp, 4, 4);
      for (i1 = 0; i1 < 16; i1++) {
        camPoses[i1] = b_I[i1];
      }
      emlrtMEXProfilingStatement(31, static_cast<boolean_T>(isMexOutdated));
    }
    emlrtMEXProfilingStatement(32, static_cast<boolean_T>(isMexOutdated));
  }
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void testyCodegena_delete()
{
  coder::vision::internal::buildable::MonoVisualSLAMBuildable obj;
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_testyCodegena_delete_complete,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  if (!vslam.matlabCodegenIsDeleted) {
    vslam.matlabCodegenIsDeleted = true;
    obj = vslam.SlamObj;
    MonoVisualSLAM_reset(obj.SlamInternal);
  }
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void testyCodegena_emx_free()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_testyCodegena_emx_free_comple,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void testyCodegena_emx_init()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_testyCodegena_emx_init_comple,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void testyCodegena_init()
{
  emlrtProfilerSentinel profilerSentinel;
  xyzPointsInternal_not_empty = false;
  vslam_not_empty = false;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_testyCodegena_init_complete_n,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void testyCodegena_new()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)testyCodegena_new_complete_name,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  vslam.matlabCodegenIsDeleted = true;
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

// End of code generation (testyCodegena.cpp)
