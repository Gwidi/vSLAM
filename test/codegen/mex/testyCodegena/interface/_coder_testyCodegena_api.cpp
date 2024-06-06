//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_testyCodegena_api.cpp
//
// Code generation for function '_coder_testyCodegena_api'
//

// Include files
#include "_coder_testyCodegena_api.h"
#include "rt_nonfinite.h"
#include "testyCodegena.h"
#include "testyCodegena_data.h"
#include "testyCodegena_mexutil.h"
#include "testyCodegena_types.h"
#include "coder_array.h"
#include <cstring>

// Function Declarations
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp,
                                    const mxArray *b_nullptr,
                                    const char_T *identifier))[1310720];

static uint8_T (
    *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId))[1310720];

static real_T (*c_emlrt_marshallIn(const emlrtStack &sp,
                                   const mxArray *b_nullptr,
                                   const char_T *identifier))[2];

static real_T (*c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static boolean_T d_emlrt_marshallIn(const emlrtStack &sp,
                                    const mxArray *b_nullptr,
                                    const char_T *identifier);

static boolean_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *
emlrt_marshallOut(const emlrtStack &sp,
                  const coder::vision::internal::vslam::vslamStatusType u);

static uint8_T (*f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[1310720];

static real_T (*g_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static boolean_T h_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

// Function Definitions
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp,
                                    const mxArray *b_nullptr,
                                    const char_T *identifier))[1310720]
{
  emlrtMsgIdentifier thisId;
  uint8_T(*y)[1310720];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static uint8_T (
    *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId))[1310720]
{
  uint8_T(*y)[1310720];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack &sp,
                                   const mxArray *b_nullptr,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack &sp,
                                    const mxArray *b_nullptr,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *
emlrt_marshallOut(const emlrtStack &sp,
                  const coder::vision::internal::vslam::vslamStatusType u)
{
  static const int32_T enumValues[3]{0, 1, 2};
  static const char_T *enumNames[3]{"TrackingLost", "TrackingSuccessful",
                                    "FrequentKeyFrames"};
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  y = nullptr;
  m = nullptr;
  emlrtCheckEnumR2012b((emlrtConstCTX)&sp,
                       "vision.internal.vslam.vslamStatusType", 3,
                       (const char_T **)&enumNames[0], &enumValues[0]);
  b_y = nullptr;
  m1 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *static_cast<uint8_T *>(emlrtMxGetData(m1)) = static_cast<uint8_T>(u);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  emlrtAssign(&y, emlrtCreateEnumR2012b((emlrtConstCTX)&sp,
                                        "vision.internal.vslam.vslamStatusType",
                                        m));
  emlrtDestroyArray(&m);
  return y;
}

static uint8_T (*f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[1310720]
{
  static const int32_T dims[2]{1024, 1280};
  int32_T b_iv[2];
  uint8_T(*ret)[1310720];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "uint8", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (uint8_T(*)[1310720])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*g_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  real_T(*ret)[2];
  int32_T b_iv[2];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T h_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

void testyCodegena_api(testyCodegenaStackData *SD,
                       const mxArray *const prhs[13], int32_T nlhs,
                       const mxArray *plhs[3])
{
  coder::array<real_T, 2U> camPoses;
  coder::array<real_T, 2U> xyzPoint;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*focalLength)[2];
  real_T(*imageSize)[2];
  real_T(*principalPoint)[2];
  real_T(*radialDistortion)[2];
  real_T(*trackFeatureRange)[2];
  real_T loopClosureThreshold;
  real_T numLevels;
  real_T numPoints;
  real_T numSkipFrames;
  real_T scaleFactor;
  uint8_T(*image)[1310720];
  boolean_T isReturnAll;
  boolean_T verbose;
  coder::vision::internal::vslam::vslamStatusType status;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  image = b_emlrt_marshallIn(st, emlrtAlias(prhs[0]), "image");
  imageSize = c_emlrt_marshallIn(st, emlrtAlias(prhs[1]), "imageSize");
  principalPoint =
      c_emlrt_marshallIn(st, emlrtAlias(prhs[2]), "principalPoint");
  focalLength = c_emlrt_marshallIn(st, emlrtAlias(prhs[3]), "focalLength");
  radialDistortion =
      c_emlrt_marshallIn(st, emlrtAlias(prhs[4]), "radialDistortion");
  numPoints = emlrt_marshallIn(st, emlrtAliasP(prhs[5]), "numPoints");
  numSkipFrames = emlrt_marshallIn(st, emlrtAliasP(prhs[6]), "numSkipFrames");
  numLevels = emlrt_marshallIn(st, emlrtAliasP(prhs[7]), "numLevels");
  scaleFactor = emlrt_marshallIn(st, emlrtAliasP(prhs[8]), "scaleFactor");
  verbose = d_emlrt_marshallIn(st, emlrtAliasP(prhs[9]), "verbose");
  trackFeatureRange =
      c_emlrt_marshallIn(st, emlrtAlias(prhs[10]), "trackFeatureRange");
  loopClosureThreshold =
      emlrt_marshallIn(st, emlrtAliasP(prhs[11]), "loopClosureThreshold");
  isReturnAll = d_emlrt_marshallIn(st, emlrtAliasP(prhs[12]), "isReturnAll");
  // Invoke the target function
  testyCodegena(SD, &st, *image, *imageSize, *principalPoint, *focalLength,
                *radialDistortion, numPoints, numSkipFrames, numLevels,
                scaleFactor, verbose, *trackFeatureRange, loopClosureThreshold,
                isReturnAll, xyzPoint, camPoses, &status);
  // Marshall function outputs
  xyzPoint.no_free();
  plhs[0] = emlrt_marshallOut(xyzPoint);
  if (nlhs > 1) {
    camPoses.no_free();
    plhs[1] = emlrt_marshallOut(camPoses);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(st, status);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_testyCodegena_api.cpp)
