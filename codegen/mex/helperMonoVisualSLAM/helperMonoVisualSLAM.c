/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM.c
 *
 * Code generation for function 'helperMonoVisualSLAM'
 *
 */

/* Include files */
#include "helperMonoVisualSLAM.h"
#include "OneDimArrayBehaviorTransform.h"
#include "cameraIntrinsics.h"
#include "constrainToRotationMatrix3D.h"
#include "helperMonoVisualSLAM_data.h"
#include "helperMonoVisualSLAM_emxutil.h"
#include "helperMonoVisualSLAM_internal_types.h"
#include "helperMonoVisualSLAM_types.h"
#include "monovslam.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "vslam_core_api.hpp"
#include <string.h>

/* Variable Definitions */
static monovslam vslam;

static boolean_T vslam_not_empty;

static emxArray_real_T *xyzPointsInternal;

static boolean_T xyzPointsInternal_not_empty;

static rigidtform3d camPosesInternal;

static emlrtRSInfo emlrtRSI = {
    16,                     /* lineNo */
    "helperMonoVisualSLAM", /* fcnName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    20,                     /* lineNo */
    "helperMonoVisualSLAM", /* fcnName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    23,                     /* lineNo */
    "helperMonoVisualSLAM", /* fcnName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    24,                     /* lineNo */
    "helperMonoVisualSLAM", /* fcnName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    25,                     /* lineNo */
    "helperMonoVisualSLAM", /* fcnName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    14,                     /* lineNo */
    "helperMonoVisualSLAM", /* fcnName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    40,                    /* lineNo */
    "monovslam/monovslam", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo nb_emlrtRSI = {
    38,                    /* lineNo */
    "monovslam/monovslam", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo ob_emlrtRSI = {
    77,                    /* lineNo */
    "monovslam/monovslam", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo pb_emlrtRSI = {
    30,                                                /* lineNo */
    "MonoVisualSLAMBuildable/MonoVisualSLAMBuildable", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    110,                        /* lineNo */
    "monovslam/hasNewKeyFrame", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo wb_emlrtRSI = {
    127,                   /* lineNo */
    "monovslam/mapPoints", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo xb_emlrtRSI = {
    81,                                       /* lineNo */
    "MonoVisualSLAMBuildable/getWorldPoints", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    119,               /* lineNo */
    "computeDimsData", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    133,               /* lineNo */
    "monovslam/poses", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pathName
                                                                         */
};

static emlrtRSInfo cc_emlrtRSI = {
    100,                                      /* lineNo */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    50,                          /* lineNo */
    "rigidtform3d/rigidtform3d", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/rigidtform3d.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    51,                          /* lineNo */
    "rigidtform3d/rigidtform3d", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/rigidtform3d.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    61,                                  /* lineNo */
    "rigidtform3dImpl/rigidtform3dImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    188,                                    /* lineNo */
    "OneDimArrayBehaviorTransform/horzcat", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    186,                                    /* lineNo */
    "OneDimArrayBehaviorTransform/horzcat", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    185,                                    /* lineNo */
    "OneDimArrayBehaviorTransform/horzcat", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" /* pathName */
};

static emlrtRSInfo
    ue_emlrtRSI =
        {
            28,       /* lineNo */
            "repmat", /* fcnName */
            "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/elmat/"
            "repmat.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    266,                                           /* lineNo */
    46,                                            /* colNo */
    "",                                            /* aName */
    "OneDimArrayBehaviorTransform/copyConcatData", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m", /* pName */
    0                                        /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    97,                                       /* lineNo */
    25,                                       /* colNo */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    58,                   /* lineNo */
    23,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    81,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    74,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    78,                                       /* lineNo */
    31,                                       /* colNo */
    "MonoVisualSLAMBuildable/getWorldPoints", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    1                                       /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    78,                                       /* lineNo */
    31,                                       /* colNo */
    "MonoVisualSLAMBuildable/getWorldPoints", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    4                                       /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    93,                                       /* lineNo */
    31,                                       /* colNo */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    1                                       /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    93,                                       /* lineNo */
    31,                                       /* colNo */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    4                                       /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    78,                                       /* lineNo */
    13,                                       /* colNo */
    "MonoVisualSLAMBuildable/getWorldPoints", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    1                                       /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    93,                                       /* lineNo */
    13,                                       /* colNo */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    1                                       /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    98,                                       /* lineNo */
    50,                                       /* colNo */
    "",                                       /* aName */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    99,                                       /* lineNo */
    42,                                       /* colNo */
    "",                                       /* aName */
    "MonoVisualSLAMBuildable/getCameraPoses", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m", /* pName */
    0                                       /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = {
    7,                      /* lineNo */
    36,                     /* colNo */
    "helperMonoVisualSLAM", /* fName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    7,                      /* lineNo */
    18,                     /* colNo */
    "helperMonoVisualSLAM", /* fName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    78,                        /* lineNo */
    13,                        /* colNo */
    "MonoVisualSLAMBuildable", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    28,                     /* lineNo */
    1,                      /* colNo */
    "helperMonoVisualSLAM", /* fName */
    "/Users/busiu/Documents/MATLAB/Examples/R2023b/vision/"
    "MonocularVisualSimultaneousLocalizationAndMappingExample/"
    "helperMonoVisualSL"
    "AM.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    93,                        /* lineNo */
    13,                        /* colNo */
    "MonoVisualSLAMBuildable", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/+vision/+internal/"
    "+buildable/MonoVisualSLAMBuildable.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    127,         /* lineNo */
    13,          /* colNo */
    "monovslam", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/vision/vision/monovslam.m" /* pName
                                                                         */
};

static emlrtRTEInfo t_emlrtRTEI = {
    263,                            /* lineNo */
    46,                             /* colNo */
    "OneDimArrayBehaviorTransform", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" /* pName */
};

/* Function Definitions */
void helperMonoVisualSLAM(helperMonoVisualSLAMStackData *SD,
                          const emlrtStack *sp, const uint8_T image[921600],
                          emxArray_real_T *xyzPoint, real_T camPoses[16])
{
  static const char_T vocabFilePath[104] =
      "/Applications/MATLAB_R2023b.app/toolbox/vision/builtins/src/shared/"
      "vslamcore/bagOfFeaturesBinary.yml.gz";
  void *obj_SlamInternal;
  c_emxArray_images_geotrans_inte *dataArray;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_real_T *output;
  real_T intrinsics_K[9];
  real_T d;
  real_T numPoints;
  real_T *output_data;
  real_T *xyzPointsInternal_data;
  int32_T b_i;
  int32_T b_output;
  int32_T c_output;
  int32_T i;
  int32_T i1;
  int32_T n;
  int32_T nx;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  xyzPointsInternal_data = xyzPointsInternal->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*    Copyright 2023 The MathWorks Inc. */
  if (!vslam_not_empty) {
    real_T intrinsics_FocalLength[2];
    real_T intrinsics_ImageSize[2];
    real_T intrinsics_PrincipalPoint[2];
    real_T intrinsics_RadialDistortion[2];
    real_T intrinsics_TangentialDistortion[2];
    /*  Create a monovslam class to process the image data */
    /*  in units of pixels */
    st.site = &f_emlrtRSI;
    numPoints = c_cameraIntrinsics_cameraIntrin(
        &st, intrinsics_FocalLength, intrinsics_PrincipalPoint,
        intrinsics_ImageSize, intrinsics_RadialDistortion,
        intrinsics_TangentialDistortion, intrinsics_K);
    st.site = &emlrtRSI;
    b_st.site = &mb_emlrtRSI;
    b_st.site = &nb_emlrtRSI;
    vslam.Intrinsics.FocalLength[0] = intrinsics_FocalLength[0];
    vslam.Intrinsics.FocalLength[1] = intrinsics_FocalLength[1];
    vslam.Intrinsics.PrincipalPoint[0] = intrinsics_PrincipalPoint[0];
    vslam.Intrinsics.PrincipalPoint[1] = intrinsics_PrincipalPoint[1];
    vslam.Intrinsics.ImageSize[0] = intrinsics_ImageSize[0];
    vslam.Intrinsics.ImageSize[1] = intrinsics_ImageSize[1];
    vslam.Intrinsics.RadialDistortion[0] = intrinsics_RadialDistortion[0];
    vslam.Intrinsics.RadialDistortion[1] = intrinsics_RadialDistortion[1];
    vslam.Intrinsics.TangentialDistortion[0] =
        intrinsics_TangentialDistortion[0];
    vslam.Intrinsics.TangentialDistortion[1] =
        intrinsics_TangentialDistortion[1];
    vslam.Intrinsics.Skew = numPoints;
    memcpy(&vslam.Intrinsics.K[0], &intrinsics_K[0], 9U * sizeof(real_T));
    vslam.ScaleFactor = 1.2;
    vslam.NumLevels = 8.0;
    vslam.MaxNumPoints = 1000.0;
    vslam.SkipMaxFrames = 20.0;
    vslam.TrackFeatureRange[0] = 30.0;
    vslam.TrackFeatureRange[1] = 100.0;
    vslam.LoopClosureThreshold = 60.0;
    vslam.Verbose = false;
    b_st.site = &ob_emlrtRSI;
    c_st.site = &pb_emlrtRSI;
    d = muDoubleScalarRound(vslam.Intrinsics.ImageSize[0]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = (int32_T)d;
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }
    d = muDoubleScalarRound(vslam.Intrinsics.ImageSize[1]);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i1 = (int32_T)d;
      } else {
        i1 = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i1 = MAX_int32_T;
    } else {
      i1 = 0;
    }
    obj_SlamInternal = MonoVisualSLAM_constructor(
        vslam.Intrinsics.FocalLength[0], vslam.Intrinsics.FocalLength[1],
        vslam.Intrinsics.PrincipalPoint[0] - 1.0,
        vslam.Intrinsics.PrincipalPoint[1] - 1.0, i, i1, 1.2, 8, 1000, 30, 100,
        20, 60, false, &vocabFilePath[0]);
    vslam.SlamObj.SlamInternal = obj_SlamInternal;
    vslam.matlabCodegenIsDeleted = false;
    vslam_not_empty = true;
  }
  /*  Process each image frame */
  st.site = &b_emlrtRSI;
  monovslam_addFrame(SD, &st, &vslam, image);
  /*  Get 3-D map points and camera poses */
  emxInit_real_T(sp, &output, &p_emlrtRTEI, true);
  c_emxInit_images_geotrans_inter(sp, &dataArray, &t_emlrtRTEI, true);
  guard1 = false;
  if (!xyzPointsInternal_not_empty) {
    guard1 = true;
  } else {
    st.site = &c_emlrtRSI;
    b_st.site = &vb_emlrtRSI;
    hasAdded = MonoVisualSLAM_hasNewKeyFrame(vslam.SlamObj.SlamInternal);
    if (hasAdded) {
      guard1 = true;
    }
  }
  if (guard1) {
    real_T d1;
    real_T numCameras;
    st.site = &d_emlrtRSI;
    b_st.site = &wb_emlrtRSI;
    numPoints = MonoVisualSLAM_getNumWorldPoints(vslam.SlamObj.SlamInternal);
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    emxEnsureCapacity_real_T(&b_st, output, i, &p_emlrtRTEI);
    d = numPoints * 3.0;
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &b_emlrtDCI, &b_st);
    }
    d1 = (int32_T)muDoubleScalarFloor(d);
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &emlrtDCI, &b_st);
    }
    i = output->size[0] * output->size[1];
    nx = (int32_T)d;
    output->size[1] = (int32_T)d;
    emxEnsureCapacity_real_T(&b_st, output, i, &p_emlrtRTEI);
    output_data = output->data;
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &e_emlrtDCI, &b_st);
    }
    for (i = 0; i < nx; i++) {
      output_data[i] = 0.0;
    }
    MonoVisualSLAM_getWorldPoints(vslam.SlamObj.SlamInternal, &output_data[0]);
    if (numPoints > 0.0) {
      c_st.site = &xb_emlrtRSI;
      nx = output->size[1];
      d_st.site = &yb_emlrtRSI;
      e_st.site = &ac_emlrtRSI;
      if ((numPoints != muDoubleScalarFloor(numPoints)) ||
          muDoubleScalarIsInf(numPoints) || (numPoints > 2.147483647E+9)) {
        emlrtErrorWithMessageIdR2018a(&e_st, &c_emlrtRTEI,
                                      "Coder:MATLAB:NonIntegerInput",
                                      "Coder:MATLAB:NonIntegerInput", 4, 12,
                                      MIN_int32_T, 12, MAX_int32_T);
      }
      n = 1;
      if (output->size[1] > 1) {
        n = output->size[1];
      }
      nx = muIntScalarMax_sint32(nx, n);
      if (nx < 3) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }
      if ((int32_T)numPoints > nx) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
            "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }
      if (3 * (int32_T)numPoints != output->size[1]) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &d_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
            "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }
      nx = (int32_T)numPoints;
      i = xyzPointsInternal->size[0] * xyzPointsInternal->size[1];
      xyzPointsInternal->size[0] = (int32_T)numPoints;
      xyzPointsInternal->size[1] = 3;
      emxEnsureCapacity_real_T(&b_st, xyzPointsInternal, i, &s_emlrtRTEI);
      xyzPointsInternal_data = xyzPointsInternal->data;
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          xyzPointsInternal_data[i1 + xyzPointsInternal->size[0] * i] =
              output_data[i + 3 * i1];
        }
      }
    } else {
      xyzPointsInternal->size[0] = 0;
      xyzPointsInternal->size[1] = 3;
    }
    xyzPointsInternal_not_empty = (xyzPointsInternal->size[0] != 0);
    st.site = &e_emlrtRSI;
    b_st.site = &bc_emlrtRSI;
    numCameras = MonoVisualSLAM_getNumCameraPoses(vslam.SlamObj.SlamInternal);
    i = output->size[0] * output->size[1];
    output->size[0] = 1;
    emxEnsureCapacity_real_T(&b_st, output, i, &r_emlrtRTEI);
    d = numCameras * 12.0;
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &d_emlrtDCI, &b_st);
    }
    d1 = (int32_T)muDoubleScalarFloor(d);
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &c_emlrtDCI, &b_st);
    }
    i = output->size[0] * output->size[1];
    nx = (int32_T)d;
    output->size[1] = (int32_T)d;
    emxEnsureCapacity_real_T(&b_st, output, i, &r_emlrtRTEI);
    output_data = output->data;
    if (d != d1) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, &b_st);
    }
    for (i = 0; i < nx; i++) {
      output_data[i] = 0.0;
    }
    MonoVisualSLAM_getCameraPoses(vslam.SlamObj.SlamInternal, &output_data[0]);
    if (numCameras > 0.0) {
      for (i = 0; i < 9; i++) {
        camPosesInternal.R[i] = iv[i];
      }
      camPosesInternal.Translation[0] = 0.0;
      camPosesInternal.Translation[1] = 0.0;
      camPosesInternal.Translation[2] = 0.0;
      camPosesInternal.Data->size[0] = 1;
      camPosesInternal.Data->size[1] = 1;
      i = (int32_T)(numCameras - 1.0);
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, numCameras - 1.0, mxDOUBLE_CLASS,
                                    (int32_T)(numCameras - 1.0), &b_emlrtRTEI,
                                    &b_st);
      if ((int32_T)(numCameras - 1.0) - 1 >= 0) {
        b_output = output->size[1];
        c_output = output->size[1];
      }
      for (b_i = 0; b_i < i; b_i++) {
        real_T R[9];
        numPoints = ((real_T)b_i + 1.0) * 12.0;
        for (i1 = 0; i1 < 9; i1++) {
          nx = (int32_T)((numPoints + 1.0) + (real_T)i1);
          if ((nx < 1) || (nx > b_output)) {
            emlrtDynamicBoundsCheckR2012b(nx, 1, b_output, &b_emlrtBCI, &b_st);
          }
          intrinsics_K[i1] = output_data[nx - 1];
        }
        for (i1 = 0; i1 < 3; i1++) {
          R[3 * i1] = intrinsics_K[i1];
          R[3 * i1 + 1] = intrinsics_K[i1 + 3];
          R[3 * i1 + 2] = intrinsics_K[i1 + 6];
        }
        if (((int32_T)(numPoints + 10.0) < 1) ||
            ((int32_T)(numPoints + 10.0) > c_output)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(numPoints + 10.0), 1,
                                        c_output, &c_emlrtBCI, &b_st);
        }
        if (((int32_T)((numPoints + 10.0) + 1.0) < 1) ||
            ((int32_T)((numPoints + 10.0) + 1.0) > c_output)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((numPoints + 10.0) + 1.0), 1,
                                        c_output, &c_emlrtBCI, &b_st);
        }
        if (((int32_T)((numPoints + 10.0) + 2.0) < 1) ||
            ((int32_T)((numPoints + 10.0) + 2.0) > c_output)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((numPoints + 10.0) + 2.0), 1,
                                        c_output, &c_emlrtBCI, &b_st);
        }
        c_st.site = &cc_emlrtRSI;
        d_st.site = &hd_emlrtRSI;
        e_st.site = &jd_emlrtRSI;
        f_st.site = &kd_emlrtRSI;
        g_st.site = &ld_emlrtRSI;
        constrainToRotationMatrix3D(&g_st, R, intrinsics_K);
        g_st.site = &md_emlrtRSI;
        h_st.site = &ae_emlrtRSI;
        numPoints = b_norm(&h_st, R);
        h_st.site = &ae_emlrtRSI;
        numCameras = b_norm(&h_st, intrinsics_K);
        for (i1 = 0; i1 < 9; i1++) {
          intrinsics_K[i1] = R[i1] - intrinsics_K[i1];
        }
        h_st.site = &be_emlrtRSI;
        hasAdded =
            (b_norm(&h_st, intrinsics_K) /
                 muDoubleScalarMax(muDoubleScalarMax(numPoints, numCameras),
                                   1.223247290044539E-294) <=
             1.8189894035458565E-12);
        if (!hasAdded) {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &emlrtRTEI, "images:geotrans:invalidRotationMatrix",
              "images:geotrans:invalidRotationMatrix", 0);
        }
        d_st.site = &id_emlrtRSI;
        e_st.site = &jd_emlrtRSI;
        f_st.site = &kd_emlrtRSI;
        g_st.site = &ld_emlrtRSI;
        constrainToRotationMatrix3D(&g_st, R, intrinsics_K);
        g_st.site = &md_emlrtRSI;
        h_st.site = &ae_emlrtRSI;
        numPoints = b_norm(&h_st, R);
        h_st.site = &ae_emlrtRSI;
        numCameras = b_norm(&h_st, intrinsics_K);
        for (i1 = 0; i1 < 9; i1++) {
          R[i1] -= intrinsics_K[i1];
        }
        h_st.site = &be_emlrtRSI;
        hasAdded =
            (b_norm(&h_st, R) /
                 muDoubleScalarMax(muDoubleScalarMax(numPoints, numCameras),
                                   1.223247290044539E-294) <=
             1.8189894035458565E-12);
        if (!hasAdded) {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &emlrtRTEI, "images:geotrans:invalidRotationMatrix",
              "images:geotrans:invalidRotationMatrix", 0);
        }
        c_st.site = &cc_emlrtRSI;
        d_st.site = &ee_emlrtRSI;
        c_OneDimArrayBehaviorTransform_(&d_st, camPosesInternal.Translation,
                                        camPosesInternal.R);
        d_st.site = &de_emlrtRSI;
        e_st.site = &ue_emlrtRSI;
        d_st.site = &ce_emlrtRSI;
        dataArray->size[1] = 0;
        i1 = camPosesInternal.Data->size[1];
        for (n = 0; n < i1; n++) {
          if (n > camPosesInternal.Data->size[1] - 1) {
            emlrtDynamicBoundsCheckR2012b(
                n, 0, camPosesInternal.Data->size[1] - 1, &emlrtBCI, &d_st);
          }
          dataArray->size[0] = 1;
          dataArray->size[1]++;
        }
        dataArray->size[0] = 1;
        dataArray->size[1]++;
        camPosesInternal.Data->size[0] = 1;
        camPosesInternal.Data->size[1] = dataArray->size[1];
      }
    } else {
      for (i = 0; i < 9; i++) {
        camPosesInternal.R[i] = iv[i];
      }
      camPosesInternal.Translation[0] = 0.0;
      camPosesInternal.Translation[1] = 0.0;
      camPosesInternal.Translation[2] = 0.0;
      camPosesInternal.Data->size[0] = 1;
      camPosesInternal.Data->size[1] = 1;
      camPosesInternal.Data->size[0] = 0;
      camPosesInternal.Data->size[1] = 0;
    }
  }
  c_emxFree_images_geotrans_inter(sp, &dataArray);
  emxFree_real_T(sp, &output);
  i = xyzPoint->size[0] * xyzPoint->size[1];
  xyzPoint->size[0] = xyzPointsInternal->size[0];
  xyzPoint->size[1] = 3;
  emxEnsureCapacity_real_T(sp, xyzPoint, i, &q_emlrtRTEI);
  output_data = xyzPoint->data;
  nx = xyzPointsInternal->size[0] * 3;
  for (i = 0; i < nx; i++) {
    output_data[i] = xyzPointsInternal_data[i];
  }
  /*  Convert camera poses to homogeneous transformation matrices */
  for (i = 0; i < 3; i++) {
    nx = i << 2;
    camPoses[nx] = camPosesInternal.R[3 * i];
    camPoses[nx + 1] = camPosesInternal.R[3 * i + 1];
    camPoses[nx + 2] = camPosesInternal.R[3 * i + 2];
    camPoses[i + 12] = camPosesInternal.Translation[i];
  }
  camPoses[3] = 0.0;
  camPoses[7] = 0.0;
  camPoses[11] = 0.0;
  camPoses[15] = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void helperMonoVisualSLAM_delete(void)
{
  if (!vslam.matlabCodegenIsDeleted) {
    vslam.matlabCodegenIsDeleted = true;
    MonoVisualSLAM_reset(vslam.SlamObj.SlamInternal);
  }
}

void helperMonoVisualSLAM_free(const emlrtStack *sp)
{
  emxFree_real_T(sp, &xyzPointsInternal);
  emxFreeStruct_rigidtform3d(sp, &camPosesInternal);
}

void helperMonoVisualSLAM_init(const emlrtStack *sp)
{
  vslam.matlabCodegenIsDeleted = true;
  emxInitStruct_rigidtform3d(sp, &camPosesInternal, &n_emlrtRTEI);
  emxInit_real_T(sp, &xyzPointsInternal, &o_emlrtRTEI, false);
  xyzPointsInternal_not_empty = false;
  vslam_not_empty = false;
}

/* End of code generation (helperMonoVisualSLAM.c) */
