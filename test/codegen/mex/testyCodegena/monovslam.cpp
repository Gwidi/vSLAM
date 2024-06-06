//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// monovslam.cpp
//
// Code generation for function 'monovslam'
//

// Include files
#include "monovslam.h"
#include "MonoVisualSLAMBuildable.h"
#include "adjustNumScaleLevels.h"
#include "cameraIntrinsics.h"
#include "checkTransformationMatrixCondition.h"
#include "constrainToRotationMatrix3D.h"
#include "norm.h"
#include "rigidtform3d.h"
#include "rigidtform3dImpl.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "testyCodegena_types.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include "omp.h"
#include "vslam_core_api.hpp"
#include <cstring>

// Variable Definitions
static emlrtRSInfo cc_emlrtRSI{
    43,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    44,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo ec_emlrtRSI{
    45,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo fc_emlrtRSI{
    46,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    47,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    48,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo ic_emlrtRSI{
    49,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    50,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo kc_emlrtRSI{
    59,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    41,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    90,                    // lineNo
    "monovslam/monovslam", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    8,                   // lineNo
    "mustBeGreaterThan", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/validators/"
    "mustBeGreaterThan.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    8,                          // lineNo
    "mustBeGreaterThanOrEqual", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/validators/"
    "mustBeGreaterThanOrEqual.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    246,                             // lineNo
    "mustBeMonotonicallyIncreasing", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo qc_emlrtRSI{
    22,           // lineNo
    "validategt", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validategt.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    17,              // lineNo
    "local_num2str", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "private/local_num2str.m" // pathName
};

static emlrtRSInfo
    sc_emlrtRSI{
        15,        // lineNo
        "num2str", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
        "num2str.m" // pathName
    };

static emlrtRSInfo xc_emlrtRSI{
    30,                                                // lineNo
    "MonoVisualSLAMBuildable/MonoVisualSLAMBuildable", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pathName
};

static emlrtRSInfo yc_emlrtRSI{
    115,                  // lineNo
    "monovslam/addFrame", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo ad_emlrtRSI{
    118,                  // lineNo
    "monovslam/addFrame", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    147,               // lineNo
    "monovslam/poses", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    102,                                      // lineNo
    "MonoVisualSLAMBuildable/getCameraPoses", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    98,                                       // lineNo
    "MonoVisualSLAMBuildable/getCameraPoses", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pathName
};

static emlrtRSInfo if_emlrtRSI{
    188,                                    // lineNo
    "OneDimArrayBehaviorTransform/horzcat", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pathName
};

static emlrtRSInfo jf_emlrtRSI{
    186,                                    // lineNo
    "OneDimArrayBehaviorTransform/horzcat", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pathName
};

static emlrtRSInfo kf_emlrtRSI{
    185,                                    // lineNo
    "OneDimArrayBehaviorTransform/horzcat", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pathName
};

static emlrtRSInfo lf_emlrtRSI{
    307,                                                // lineNo
    "OneDimArrayBehaviorTransform/initializeArrayData", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pathName
};

static emlrtRSInfo cg_emlrtRSI{
    38,       // lineNo
    "repmat", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

static emlrtMCInfo emlrtMCI{
    53,        // lineNo
    19,        // colNo
    "flt2str", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/flt2str.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    56,                    // lineNo
    16,                    // colNo
    "monovslam/monovslam", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/monovslam.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    9,              // lineNo
    23,             // colNo
    "mustBeFinite", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/validators/"
    "mustBeFinite.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    12,               // lineNo
    23,               // colNo
    "mustBePositive", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/validators/"
    "mustBePositive.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    13,              // lineNo
    27,              // colNo
    "mustBeInteger", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/validators/"
    "mustBeInteger.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    18,                     // lineNo
    5,                      // colNo
    "binaryRelopValidator", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/validators/private/"
    "binaryRelopValidator.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    22,           // lineNo
    27,           // colNo
    "validategt", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validategt.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    10,             // lineNo
    23,             // colNo
    "validatesize", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatesize.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    15,             // lineNo
    19,             // colNo
    "validatesize", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatesize.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    100,                                      // lineNo
    50,                                       // colNo
    "",                                       // aName
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    0                                       // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    96,                                       // lineNo
    46,                                       // colNo
    "",                                       // aName
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    0                                       // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    93,                                       // lineNo
    13,                                       // colNo
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    1                                       // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    93,                                       // lineNo
    31,                                       // colNo
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    4                                       // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    93,                                       // lineNo
    31,                                       // colNo
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    1                                       // checkKind
};

static emlrtRTEInfo o_emlrtRTEI{
    99,                                       // lineNo
    25,                                       // colNo
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pName
};

static emlrtBCInfo d_emlrtBCI{
    -1,                                            // iFirst
    -1,                                            // iLast
    266,                                           // lineNo
    46,                                            // colNo
    "",                                            // aName
    "OneDimArrayBehaviorTransform/copyConcatData", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    101,                                      // lineNo
    42,                                       // colNo
    "",                                       // aName
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    0                                       // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    97,                                       // lineNo
    38,                                       // colNo
    "",                                       // aName
    "MonoVisualSLAMBuildable/getCameraPoses", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", // pName
    0                                       // checkKind
};

static emlrtRTEInfo eb_emlrtRTEI{
    93,                        // lineNo
    13,                        // colNo
    "MonoVisualSLAMBuildable", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    170,                            // lineNo
    13,                             // colNo
    "OneDimArrayBehaviorTransform", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    272,                            // lineNo
    21,                             // colNo
    "OneDimArrayBehaviorTransform", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    188,                            // lineNo
    20,                             // colNo
    "OneDimArrayBehaviorTransform", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    277,                            // lineNo
    13,                             // colNo
    "OneDimArrayBehaviorTransform", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pName
};

static emlrtRSInfo mg_emlrtRSI{
    53,        // lineNo
    "flt2str", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/flt2str.m" // pathName
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23]);

static const mxArray *b_sprintf(const emlrtStack &sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo &location);

static void emlrt_marshallIn(const emlrtStack &sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23]);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[23]);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[23])
{
  static const int32_T dims[2]{1, 23};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 23);
  emlrtDestroyArray(&src);
}

static const mxArray *b_sprintf(const emlrtStack &sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 2, &pArrays[0],
                               "sprintf", true, &location);
}

static void emlrt_marshallIn(const emlrtStack &sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[23])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[23])
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

namespace coder {
void monovslam::addFrame(testyCodegenaStackData *SD, const emlrtStack &sp,
                         const uint8_T b_I[1310720])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  int32_T addFrame_numThreads;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &yc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &u_emlrtRSI;
  p = true;
  for (int32_T k{0}; k < 2; k++) {
    if (p) {
      d = Intrinsics.ImageSize[k];
      if ((!(d != d)) && (muDoubleScalarIsInf(d) || (!(d >= 0.0)) ||
                          (!(d == muDoubleScalarFloor(d))))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
                                  "MATLAB:validateattributes:badSizeArray",
                                  "MATLAB:validateattributes:badSizeArray", 0);
  }
  p = true;
  for (int32_T k{0}; k < 2; k++) {
    if (p) {
      d = Intrinsics.ImageSize[k];
      if ((!(d != d)) && (!(d == 256.0 * static_cast<real_T>(k) + 1024.0))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:monovslam:incorrectSize", 3, 4, 1, "I");
  }
  st.site = &ad_emlrtRSI;
  emlrtEnterParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
  addFrame_numThreads =
      emlrtAllocRegionTLSs(st.tls, static_cast<boolean_T>(omp_in_parallel()),
                           omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(addFrame_numThreads)

  for (int32_T i = 0; i < 1310720; i++) {
    SD->f0.Iu8_grayT[i] = b_I[i];
  }
  emlrtExitParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
  MonoVisualSLAM_addFrame(SlamObj.SlamInternal, &SD->f0.Iu8_grayT[0], 1024,
                          1280, true);
}

monovslam *monovslam::init(const emlrtStack &sp, cameraIntrinsics &intrinsics,
                           real_T args_MaxNumPoints, real_T args_SkipMaxFrames,
                           real_T args_NumLevels, real_T args_ScaleFactor,
                           boolean_T args_Verbose,
                           const real_T args_TrackFeatureRange[2],
                           real_T args_LoopClosureThreshold)
{
  static const int32_T b_iv[2]{1, 7};
  static const char_T vocabFilePath[98]{
      "/Applications/MATLAB_R2024a.app/toolbox/vision/builtins/src/shared/"
      "vslamcore/bagOfFeatures.bin.gz"};
  static const char_T rfmt[7]{'%', '2', '3', '.', '1', '5', 'e'};
  cameraIntrinsics b_intrinsics;
  monovslam *b_vslam;
  vision::internal::buildable::MonoVisualSLAMBuildable obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T actualNumLevels;
  real_T loopClosureThreshold;
  real_T maxNumPoints;
  real_T numLevels;
  real_T scaleFactor;
  real_T skipMaxFrames;
  real_T threadLevel;
  real_T trackFeatureRange_idx_0;
  real_T trackFeatureRange_idx_1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T k;
  boolean_T b;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_vslam = this;
  st.site = &cc_emlrtRSI;
  st.site = &dc_emlrtRSI;
  if (muDoubleScalarIsInf(args_ScaleFactor) ||
      muDoubleScalarIsNaN(args_ScaleFactor)) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
                                  "MATLAB:validators:mustBeFinite",
                                  "MATLAB:validators:mustBeFinite", 0);
  }
  st.site = &dc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  if (!(args_ScaleFactor > 1.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &k_emlrtRTEI, "MATLAB:validators:mustBeGreaterThan",
        "MATLAB:validators:mustBeGreaterThan", 3, 4, 1, "1");
  }
  st.site = &ec_emlrtRSI;
  p = muDoubleScalarIsInf(args_NumLevels);
  b = muDoubleScalarIsNaN(args_NumLevels);
  if (p || b || (!(args_NumLevels == muDoubleScalarFloor(args_NumLevels)))) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "MATLAB:validators:mustBeInteger",
                                  "MATLAB:validators:mustBeInteger", 0);
  }
  st.site = &ec_emlrtRSI;
  if (p || b) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
                                  "MATLAB:validators:mustBeFinite",
                                  "MATLAB:validators:mustBeFinite", 0);
  }
  st.site = &ec_emlrtRSI;
  b_st.site = &oc_emlrtRSI;
  if (!(args_NumLevels >= 1.0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &k_emlrtRTEI, "MATLAB:validators:mustBeGreaterThanOrEqual",
        "MATLAB:validators:mustBeGreaterThanOrEqual", 3, 4, 1, "1");
  }
  st.site = &fc_emlrtRSI;
  if (!(args_MaxNumPoints > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
  st.site = &fc_emlrtRSI;
  if (muDoubleScalarIsInf(args_MaxNumPoints) ||
      (!(args_MaxNumPoints == muDoubleScalarFloor(args_MaxNumPoints)))) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "MATLAB:validators:mustBeInteger",
                                  "MATLAB:validators:mustBeInteger", 0);
  }
  st.site = &gc_emlrtRSI;
  p = true;
  for (k = 0; k < 2; k++) {
    if (p) {
      actualNumLevels = args_TrackFeatureRange[k];
      if (muDoubleScalarIsInf(actualNumLevels) ||
          muDoubleScalarIsNaN(actualNumLevels) ||
          (!(actualNumLevels == muDoubleScalarFloor(actualNumLevels)))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "MATLAB:validators:mustBeInteger",
                                  "MATLAB:validators:mustBeInteger", 0);
  }
  st.site = &gc_emlrtRSI;
  p = true;
  for (k = 0; k < 2; k++) {
    if ((!p) || (!(args_TrackFeatureRange[k] > 0.0))) {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
  st.site = &hc_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  if (!(args_TrackFeatureRange[1] > args_TrackFeatureRange[0])) {
    char_T numstr[23];
    d_st.site = &qc_emlrtRSI;
    e_st.site = &rc_emlrtRSI;
    f_st.site = &sc_emlrtRSI;
    y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&f_st, 7, m, &rfmt[0]);
    emlrtAssign(&y, m);
    b_y = nullptr;
    m = emlrtCreateDoubleScalar(args_TrackFeatureRange[0]);
    emlrtAssign(&b_y, m);
    g_st.site = &mg_emlrtRSI;
    emlrt_marshallIn(g_st, b_sprintf(g_st, y, b_y, emlrtMCI),
                     "<output of sprintf>", numstr);
    emlrtErrorWithMessageIdR2018a(
        &c_st, &l_emlrtRTEI, "MATLAB:validateattributes:expectedScalar",
        "MATLAB:monovslam:notGreater", 9, 4, 22, "TrackedFeatureRange(2)", 4, 1,
        ">", 4, 23, &numstr[0]);
  }
  st.site = &ic_emlrtRSI;
  if (!(args_SkipMaxFrames > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
  st.site = &ic_emlrtRSI;
  if (muDoubleScalarIsInf(args_SkipMaxFrames) ||
      (!(args_SkipMaxFrames == muDoubleScalarFloor(args_SkipMaxFrames)))) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "MATLAB:validators:mustBeInteger",
                                  "MATLAB:validators:mustBeInteger", 0);
  }
  st.site = &jc_emlrtRSI;
  if (!(args_LoopClosureThreshold > 0.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
                                  "MATLAB:validators:mustBePositive",
                                  "MATLAB:validators:mustBePositive", 0);
  }
  st.site = &jc_emlrtRSI;
  if (muDoubleScalarIsInf(args_LoopClosureThreshold) ||
      (!(args_LoopClosureThreshold ==
         muDoubleScalarFloor(args_LoopClosureThreshold)))) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "MATLAB:validators:mustBeInteger",
                                  "MATLAB:validators:mustBeInteger", 0);
  }
  if ((intrinsics.ImageSize[0] > intrinsics.ImageSize[1]) ||
      (muDoubleScalarIsNaN(intrinsics.ImageSize[0]) &&
       (!muDoubleScalarIsNaN(intrinsics.ImageSize[1])))) {
    actualNumLevels = intrinsics.ImageSize[1];
  } else {
    actualNumLevels = intrinsics.ImageSize[0];
  }
  if (actualNumLevels < 63.0) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &g_emlrtRTEI, "vision:detectORBFeatures:invalidImageSize",
        "vision:detectORBFeatures:invalidImageSize", 0);
  }
  actualNumLevels = args_NumLevels;
  st.site = &kc_emlrtRSI;
  vision::internal::vslam::adjustNumScaleLevels(
      st, intrinsics.ImageSize, actualNumLevels, args_ScaleFactor);
  st.site = &lc_emlrtRSI;
  b_vslam->Intrinsics = intrinsics;
  b_vslam->ScaleFactor = args_ScaleFactor;
  b_vslam->NumLevels = actualNumLevels;
  b_vslam->MaxNumPoints = args_MaxNumPoints;
  b_vslam->SkipMaxFrames = args_SkipMaxFrames;
  b_vslam->TrackFeatureRange[0] = args_TrackFeatureRange[0];
  b_vslam->TrackFeatureRange[1] = args_TrackFeatureRange[1];
  b_vslam->LoopClosureThreshold = args_LoopClosureThreshold;
  b_vslam->Verbose = args_Verbose;
  b_vslam->ThreadLevel = 2.0;
  st.site = &mc_emlrtRSI;
  b_intrinsics = b_vslam->Intrinsics;
  scaleFactor = b_vslam->ScaleFactor;
  numLevels = b_vslam->NumLevels;
  maxNumPoints = b_vslam->MaxNumPoints;
  trackFeatureRange_idx_0 = b_vslam->TrackFeatureRange[0];
  trackFeatureRange_idx_1 = b_vslam->TrackFeatureRange[1];
  skipMaxFrames = b_vslam->SkipMaxFrames;
  loopClosureThreshold = b_vslam->LoopClosureThreshold;
  p = b_vslam->Verbose;
  threadLevel = b_vslam->ThreadLevel;
  b_st.site = &xc_emlrtRSI;
  actualNumLevels = muDoubleScalarRound(b_intrinsics.ImageSize[0]);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      k = static_cast<int32_T>(actualNumLevels);
    } else {
      k = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    k = MAX_int32_T;
  } else {
    k = 0;
  }
  actualNumLevels = muDoubleScalarRound(b_intrinsics.ImageSize[1]);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i = static_cast<int32_T>(actualNumLevels);
    } else {
      i = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }
  actualNumLevels = muDoubleScalarRound(numLevels);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i1 = static_cast<int32_T>(actualNumLevels);
    } else {
      i1 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i1 = MAX_int32_T;
  } else {
    i1 = 0;
  }
  actualNumLevels = muDoubleScalarRound(maxNumPoints);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i2 = static_cast<int32_T>(actualNumLevels);
    } else {
      i2 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i2 = MAX_int32_T;
  } else {
    i2 = 0;
  }
  actualNumLevels = muDoubleScalarRound(trackFeatureRange_idx_0);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i3 = static_cast<int32_T>(actualNumLevels);
    } else {
      i3 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i3 = MAX_int32_T;
  } else {
    i3 = 0;
  }
  actualNumLevels = muDoubleScalarRound(trackFeatureRange_idx_1);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i4 = static_cast<int32_T>(actualNumLevels);
    } else {
      i4 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i4 = MAX_int32_T;
  } else {
    i4 = 0;
  }
  actualNumLevels = muDoubleScalarRound(skipMaxFrames);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i5 = static_cast<int32_T>(actualNumLevels);
    } else {
      i5 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i5 = MAX_int32_T;
  } else {
    i5 = 0;
  }
  actualNumLevels = muDoubleScalarRound(loopClosureThreshold);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i6 = static_cast<int32_T>(actualNumLevels);
    } else {
      i6 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i6 = MAX_int32_T;
  } else {
    i6 = 0;
  }
  actualNumLevels = muDoubleScalarRound(threadLevel);
  if (actualNumLevels < 2.147483648E+9) {
    if (actualNumLevels >= -2.147483648E+9) {
      i7 = static_cast<int32_T>(actualNumLevels);
    } else {
      i7 = MIN_int32_T;
    }
  } else if (actualNumLevels >= 2.147483648E+9) {
    i7 = MAX_int32_T;
  } else {
    i7 = 0;
  }
  obj.SlamInternal = MonoVisualSLAM_constructor(
      b_intrinsics.FocalLength[0], b_intrinsics.FocalLength[1],
      b_intrinsics.PrincipalPoint[0] - 1.0,
      b_intrinsics.PrincipalPoint[1] - 1.0, k, i, scaleFactor, i1, i2, i3, i4,
      i5, i6, p, &vocabFilePath[0], i7);
  b_vslam->SlamObj = obj;
  b_vslam->matlabCodegenIsDeleted = false;
  return b_vslam;
}

void monovslam::poses(const emlrtStack &sp, rigidtform3d &camPoses)
{
  rigidtform3d varargin_1;
  array<images::geotrans::internal::rigidtform3dImpl, 2U> dataArray;
  array<real_T, 2U> tformA;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  real_T t[3];
  real_T numCameras;
  real_T y;
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T poses_numThreads;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &gd_emlrtRSI;
  numCameras = MonoVisualSLAM_getNumCameraPoses(SlamObj.SlamInternal);
  y = numCameras * 12.0;
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &g_emlrtDCI, &st);
  }
  i = static_cast<int32_T>(muDoubleScalarFloor(y));
  if (y != i) {
    emlrtIntegerCheckR2012b(y, &h_emlrtDCI, &st);
  }
  loop_ub_tmp = static_cast<int32_T>(y);
  tformA.set_size(&eb_emlrtRTEI, &st, 1, loop_ub_tmp);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(y, &f_emlrtDCI, &st);
  }
  if (static_cast<int32_T>(y < 600.0)) {
    for (int32_T i1{0}; i1 < loop_ub_tmp; i1++) {
      tformA[i1] = 0.0;
    }
  } else {
    emlrtEnterParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
    poses_numThreads =
        emlrtAllocRegionTLSs(st.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), 6);
#pragma omp parallel for num_threads(poses_numThreads)

    for (int32_T i1 = 0; i1 < loop_ub_tmp; i1++) {
      tformA[i1] = 0.0;
    }
    emlrtExitParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
  }
  MonoVisualSLAM_getCameraPoses(SlamObj.SlamInternal, &tformA[0]);
  if (numCameras > 0.0) {
    real_T R[9];
    real_T b_tformA[9];
    int32_T i3;
    for (i = 0; i < 9; i++) {
      if (i + 1 > tformA.size(1)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, tformA.size(1), &c_emlrtBCI,
                                      &st);
      }
    }
    i = tformA.size(1);
    if (tformA.size(1) < 10) {
      emlrtDynamicBoundsCheckR2012b(10, 1, tformA.size(1), &f_emlrtBCI, &st);
    }
    if (tformA.size(1) < 11) {
      emlrtDynamicBoundsCheckR2012b(11, 1, tformA.size(1), &f_emlrtBCI, &st);
    }
    if (tformA.size(1) < 12) {
      emlrtDynamicBoundsCheckR2012b(12, 1, tformA.size(1), &f_emlrtBCI, &st);
    }
    for (i3 = 0; i3 < 9; i3++) {
      R[i3] = tformA[i3];
    }
    for (i3 = 0; i3 < 3; i3++) {
      b_tformA[3 * i3] = R[i3];
      b_tformA[3 * i3 + 1] = R[i3 + 3];
      b_tformA[3 * i3 + 2] = R[i3 + 6];
    }
    real_T dv[3];
    dv[0] = (*(real_T(*)[3]) & tformA[9])[0];
    dv[1] = (*(real_T(*)[3]) & tformA[9])[1];
    dv[2] = (*(real_T(*)[3]) & tformA[9])[2];
    b_st.site = &id_emlrtRSI;
    camPoses.init(b_st, b_tformA, dv);
    i3 = static_cast<int32_T>(numCameras - 1.0);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numCameras - 1.0, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(numCameras - 1.0),
                                  &o_emlrtRTEI, &st);
    for (int32_T b_i{0}; b_i < i3; b_i++) {
      real_T A_in[16];
      real_T Ac[16];
      int32_T i4;
      boolean_T is_valid_for_this_class;
      numCameras = (static_cast<real_T>(b_i) + 1.0) * 12.0;
      for (i4 = 0; i4 < 9; i4++) {
        loop_ub_tmp =
            static_cast<int32_T>((numCameras + 1.0) + static_cast<real_T>(i4));
        if ((loop_ub_tmp < 1) || (loop_ub_tmp > i)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub_tmp, 1, i, &b_emlrtBCI, &st);
        }
        R[i4] = tformA[loop_ub_tmp - 1];
      }
      if ((static_cast<int32_T>(numCameras + 10.0) < 1) ||
          (static_cast<int32_T>(numCameras + 10.0) > i)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numCameras + 10.0),
                                      1, i, &e_emlrtBCI, &st);
      }
      t[0] = tformA[static_cast<int32_T>(numCameras + 10.0) - 1];
      if ((static_cast<int32_T>((numCameras + 10.0) + 1.0) < 1) ||
          (static_cast<int32_T>((numCameras + 10.0) + 1.0) > i)) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>((numCameras + 10.0) + 1.0), 1, i, &e_emlrtBCI,
            &st);
      }
      t[1] = tformA[static_cast<int32_T>((numCameras + 10.0) + 1.0) - 1];
      if ((static_cast<int32_T>((numCameras + 10.0) + 2.0) < 1) ||
          (static_cast<int32_T>((numCameras + 10.0) + 2.0) > i)) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>((numCameras + 10.0) + 2.0), 1, i, &e_emlrtBCI,
            &st);
      }
      t[2] = tformA[static_cast<int32_T>((numCameras + 10.0) + 2.0) - 1];
      b_st.site = &hd_emlrtRSI;
      for (i4 = 0; i4 < 3; i4++) {
        b_tformA[3 * i4] = R[i4];
        b_tformA[3 * i4 + 1] = R[i4 + 3];
        b_tformA[3 * i4 + 2] = R[i4 + 6];
      }
      c_st.site = &hd_emlrtRSI;
      varargin_1.init(c_st, b_tformA, t);
      c_st.site = &kf_emlrtRSI;
      for (i4 = 0; i4 < 3; i4++) {
        loop_ub_tmp = i4 << 2;
        A_in[loop_ub_tmp] = camPoses.R[3 * i4];
        A_in[loop_ub_tmp + 1] = camPoses.R[3 * i4 + 1];
        A_in[loop_ub_tmp + 2] = camPoses.R[3 * i4 + 2];
        A_in[i4 + 12] = camPoses.Translation[i4];
      }
      A_in[3] = 0.0;
      A_in[7] = 0.0;
      A_in[11] = 0.0;
      A_in[15] = 1.0;
      d_st.site = &lf_emlrtRSI;
      e_st.site = &mf_emlrtRSI;
      f_st.site = &nf_emlrtRSI;
      g_st.site = &rf_emlrtRSI;
      for (i4 = 0; i4 < 3; i4++) {
        loop_ub_tmp = i4 << 2;
        b_tformA[3 * i4] = A_in[loop_ub_tmp];
        b_tformA[3 * i4 + 1] = A_in[loop_ub_tmp + 1];
        b_tformA[3 * i4 + 2] = A_in[loop_ub_tmp + 2];
      }
      h_st.site = &sf_emlrtRSI;
      images::geotrans::internal::constrainToRotationMatrix3D(h_st, b_tformA,
                                                              R);
      for (i4 = 0; i4 < 3; i4++) {
        loop_ub_tmp = i4 << 2;
        Ac[loop_ub_tmp] = R[3 * i4];
        Ac[loop_ub_tmp + 1] = R[3 * i4 + 1];
        Ac[loop_ub_tmp + 2] = R[3 * i4 + 2];
        Ac[i4 + 12] = A_in[i4 + 12];
      }
      Ac[3] = 0.0;
      Ac[7] = 0.0;
      Ac[11] = 0.0;
      Ac[15] = 1.0;
      f_st.site = &of_emlrtRSI;
      g_st.site = &gf_emlrtRSI;
      numCameras = c_norm(g_st, Ac);
      g_st.site = &gf_emlrtRSI;
      y = c_norm(g_st, A_in);
      for (i4 = 0; i4 < 16; i4++) {
        A_in[i4] = Ac[i4] - A_in[i4];
      }
      g_st.site = &hf_emlrtRSI;
      is_valid_for_this_class =
          (c_norm(g_st, A_in) /
               muDoubleScalarMax(muDoubleScalarMax(numCameras, y),
                                 1.223247290044539E-294) <=
           1.8189894035458565E-12);
      if (!is_valid_for_this_class) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &p_emlrtRTEI, "images:geotrans:invalidTransformationMatrix",
            "images:geotrans:invalidTransformationMatrix", 0);
      }
      f_st.site = &pf_emlrtRSI;
      images::geotrans::internal::c_checkTransformationMatrixCond(f_st, Ac);
      f_st.site = &qf_emlrtRSI;
      g_st.site = &bg_emlrtRSI;
      h_st.site = &md_emlrtRSI;
      i_st.site = &nd_emlrtRSI;
      images::geotrans::internal::constrainToRotationMatrix3D(i_st, R,
                                                              b_tformA);
      i_st.site = &od_emlrtRSI;
      j_st.site = &gf_emlrtRSI;
      numCameras = b_norm(j_st, R);
      j_st.site = &gf_emlrtRSI;
      y = b_norm(j_st, b_tformA);
      for (i4 = 0; i4 < 9; i4++) {
        R[i4] -= b_tformA[i4];
      }
      j_st.site = &hf_emlrtRSI;
      is_valid_for_this_class =
          (b_norm(j_st, R) / muDoubleScalarMax(muDoubleScalarMax(numCameras, y),
                                               1.223247290044539E-294) <=
           1.8189894035458565E-12);
      if (!is_valid_for_this_class) {
        emlrtErrorWithMessageIdR2018a(
            &g_st, &q_emlrtRTEI, "images:geotrans:invalidRotationMatrix",
            "images:geotrans:invalidRotationMatrix", 0);
      }
      c_st.site = &jf_emlrtRSI;
      d_st.site = &cg_emlrtRSI;
      c_st.site = &if_emlrtRSI;
      dataArray.set_size(&hb_emlrtRTEI, &c_st, dataArray.size(0), 0);
      i4 = camPoses.Data.size(0) * camPoses.Data.size(1);
      for (int32_T n{0}; n < i4; n++) {
        if (n > camPoses.Data.size(1) - 1) {
          emlrtDynamicBoundsCheckR2012b(n, 0, camPoses.Data.size(1) - 1,
                                        &d_emlrtBCI, &c_st);
        }
        loop_ub_tmp = dataArray.size(1) + 1;
        dataArray.set_size(&ib_emlrtRTEI, &c_st, 1, dataArray.size(1) + 1);
        dataArray[loop_ub_tmp - 1] = camPoses.Data[n];
      }
      loop_ub_tmp = dataArray.size(1) + 1;
      dataArray.set_size(&ib_emlrtRTEI, &c_st, 1, dataArray.size(1) + 1);
      dataArray[loop_ub_tmp - 1] = varargin_1.Data[0];
      camPoses.Data.set_size(&jb_emlrtRTEI, &c_st, 1, loop_ub_tmp);
      for (i4 = 0; i4 < loop_ub_tmp; i4++) {
        camPoses.Data[i4] = dataArray[i4];
      }
    }
  } else {
    images::geotrans::internal::rigidtform3dImpl r;
    camPoses.Translation[0] = 0.0;
    camPoses.Translation[1] = 0.0;
    camPoses.Translation[2] = 0.0;
    for (i = 0; i < 9; i++) {
      int8_T i2;
      i2 = iv[i];
      camPoses.R[i] = i2;
      r.R[i] = i2;
    }
    r.Translation[0] = 0.0;
    r.Translation[1] = 0.0;
    r.Translation[2] = 0.0;
    camPoses.Data.set_size(&fb_emlrtRTEI, &st, 1, 1);
    camPoses.Data[0] = r;
    camPoses.Data.set_size(&gb_emlrtRTEI, &st, 0, 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder

// End of code generation (monovslam.cpp)
