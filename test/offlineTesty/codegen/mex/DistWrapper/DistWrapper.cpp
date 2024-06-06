//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// DistWrapper.cpp
//
// Code generation for function 'DistWrapper'
//

// Include files
#include "DistWrapper.h"
#include "CameraParametersImpl.h"
#include "DistWrapper_data.h"
#include "DistWrapper_internal_types.h"
#include "ImageTransformer.h"
#include "cameraIntrinsics.h"
#include "cameraIntrinsicsArray.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "undistortImage.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "emlrt.h"
#include "omp.h"
#include <algorithm>

// Variable Definitions
static boolean_T intrinsics_not_empty;

static emlrtRSInfo emlrtRSI{
    12,            // lineNo
    "DistWrapper", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/offlineTesty/DistWrapper.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    10,            // lineNo
    "DistWrapper", // fcnName
    "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
    "ciowy/vSLAM/test/offlineTesty/DistWrapper.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    288,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

static emlrtRTEInfo q_emlrtRTEI{
    46,                     // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    48,                     // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    50,                     // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    55,                     // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    56,                     // lineNo
    13,                     // colNo
    "ImageTransformerBase", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformerBase.m" // pName
};

// Function Definitions
void DistWrapper(const emlrtStack *sp, const uint8_T image[1310720],
                 uint8_T outimage[1310720])
{
  static coder::cameraIntrinsics intrinsics;
  static coder::cameraParameters gobj_0;
  static const real_T intrinsicMat[9]{734.42, 0.0,   0.0,    0.0, 735.91,
                                      0.0,    628.2, 507.98, 1.0};
  static const char_T cv[5]{'u', 'i', 'n', 't', '8'};
  coder::cameraIntrinsics r;
  emlrtProfilerSentinel profilerSentinel;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  struct_T expl_temp;
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
  emlrtMEXProfilingFunctionEntryCPP((char_T *)DistWrapper_complete_name,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  // DISTWRAPPER Summary of this function goes here
  //    Detailed explanation goes here
  emlrtMEXProfilingStatement(2, static_cast<boolean_T>(isMexOutdated));
  if (!intrinsics_not_empty) {
    emlrtMEXProfilingStatement(7, static_cast<boolean_T>(isMexOutdated));
    st.site = &b_emlrtRSI;
    b_st.site = &d_emlrtRSI;
    intrinsics.FocalLength[0] = 734.42;
    intrinsics.FocalLength[1] = 735.91;
    intrinsics.PrincipalPoint[0] = 628.2;
    intrinsics.PrincipalPoint[1] = 507.98;
    intrinsics.ImageSize[0] = 1024.0;
    intrinsics.ImageSize[1] = 1280.0;
    intrinsics.RadialDistortion[0] = -0.2524;
    intrinsics.RadialDistortion[1] = 0.0536;
    intrinsics.TangentialDistortion[0] = 0.0;
    intrinsics.TangentialDistortion[1] = 0.0;
    intrinsics.Skew = 0.0;
    std::copy(&intrinsicMat[0], &intrinsicMat[9], &intrinsics.K[0]);
    c_st.site = &e_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    e_st.site = &g_emlrtRSI;
    f_st.site = &i_emlrtRSI;
    e_st.site = &h_emlrtRSI;
    f_st.site = &j_emlrtRSI;
    coder::vision::internal::calibration::CameraParametersImpl::
        parseInputsCodegen(f_st, intrinsics.K, intrinsics.RadialDistortion,
                           intrinsics.TangentialDistortion,
                           intrinsics.ImageSize, expl_temp);
    f_st.site = &k_emlrtRSI;
    g_st.site = &u_emlrtRSI;
    f_st.site = &k_emlrtRSI;
    g_st.site = &v_emlrtRSI;
    f_st.site = &l_emlrtRSI;
    g_st.site = &od_emlrtRSI;
    for (int32_T i{0}; i < 3; i++) {
      gobj_0.K[3 * i] = expl_temp.IntrinsicMatrix[i];
      gobj_0.K[3 * i + 1] = expl_temp.IntrinsicMatrix[i + 3];
      gobj_0.K[3 * i + 2] = expl_temp.IntrinsicMatrix[i + 6];
    }
    g_st.site = &x_emlrtRSI;
    coder::vision::internal::calibration::CameraParametersImpl::
        checkRadialDistortion(g_st, expl_temp.RadialDistortion);
    gobj_0.RadialDistortion[0] = expl_temp.RadialDistortion[0];
    gobj_0.RadialDistortion[1] = expl_temp.RadialDistortion[1];
    g_st.site = &y_emlrtRSI;
    coder::vision::internal::calibration::CameraParametersImpl::
        checkTangentialDistortion(g_st, expl_temp.TangentialDistortion);
    gobj_0.TangentialDistortion[0] = expl_temp.TangentialDistortion[0];
    gobj_0.TangentialDistortion[1] = expl_temp.TangentialDistortion[1];
    g_st.site = &ab_emlrtRSI;
    coder::vision::internal::calibration::CameraParametersImpl::checkImageSize(
        g_st, expl_temp.ImageSize);
    g_st.site = &bb_emlrtRSI;
    h_st.site = &gb_emlrtRSI;
    coder::vision::internal::calibration::CameraParametersImpl::checkImageSize(
        h_st, expl_temp.ImageSize);
    g_st.site = &cb_emlrtRSI;
    f_st.site = &m_emlrtRSI;
    g_st.site = &ib_emlrtRSI;
    gobj_0.UndistortMap.XBounds[0] = -1.0;
    gobj_0.UndistortMap.YBounds[0] = -1.0;
    gobj_0.UndistortMap.XBounds[1] = -1.0;
    gobj_0.UndistortMap.YBounds[1] = -1.0;
    gobj_0.UndistortMap.SizeOfImage.set_size(&q_emlrtRTEI, &g_st, 1, 3);
    gobj_0.UndistortMap.SizeOfImage[0] = 0.0;
    gobj_0.UndistortMap.SizeOfImage[1] = 0.0;
    gobj_0.UndistortMap.SizeOfImage[2] = 0.0;
    gobj_0.UndistortMap.ClassOfImage.set_size(&r_emlrtRTEI, &g_st, 1, 5);
    for (int32_T i{0}; i < 5; i++) {
      gobj_0.UndistortMap.ClassOfImage[i] = cv[i];
    }
    coder::vision::internal::codegen::cameraIntrinsicsArray r1;
    gobj_0.UndistortMap.OutputView.set_size(&s_emlrtRTEI, &g_st, 1, 4);
    gobj_0.UndistortMap.XmapSingle.set_size(&t_emlrtRTEI, &g_st, 2, 2);
    gobj_0.UndistortMap.YmapSingle.set_size(&u_emlrtRTEI, &g_st, 2, 2);
    gobj_0.UndistortMap.OutputView[0] = 's';
    gobj_0.UndistortMap.XmapSingle[0] = 0.0F;
    gobj_0.UndistortMap.YmapSingle[0] = 0.0F;
    gobj_0.UndistortMap.OutputView[1] = 'a';
    gobj_0.UndistortMap.XmapSingle[1] = 0.0F;
    gobj_0.UndistortMap.YmapSingle[1] = 0.0F;
    gobj_0.UndistortMap.OutputView[2] = 'm';
    gobj_0.UndistortMap.XmapSingle[2] = 0.0F;
    gobj_0.UndistortMap.YmapSingle[2] = 0.0F;
    gobj_0.UndistortMap.OutputView[3] = 'e';
    gobj_0.UndistortMap.XmapSingle[3] = 0.0F;
    gobj_0.UndistortMap.YmapSingle[3] = 0.0F;
    intrinsics.CameraParameters = &gobj_0;
    b_st.site = &c_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    d_st.site = &lb_emlrtRSI;
    intrinsics.cameraIntrinsicsArrayData.size[0] = 1;
    intrinsics.cameraIntrinsicsArrayData.size[1] = 1;
    intrinsics.cameraIntrinsicsArrayData.data[0] = r1;
    intrinsics_not_empty = true;
    emlrtMEXProfilingStatement(8, static_cast<boolean_T>(isMexOutdated));
  }
  emlrtMEXProfilingStatement(9, static_cast<boolean_T>(isMexOutdated));
  r = intrinsics;
  st.site = &emlrtRSI;
  coder::undistortImage(st, image, r, outimage);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void DistWrapper_delete()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_DistWrapper_delete_complete_n,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void DistWrapper_emx_free()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_DistWrapper_emx_free_complete,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void DistWrapper_emx_init()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)c_DistWrapper_emx_init_complete,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void DistWrapper_init()
{
  emlrtProfilerSentinel profilerSentinel;
  intrinsics_not_empty = false;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)DistWrapper_init_complete_name,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

void DistWrapper_new()
{
  emlrtProfilerSentinel profilerSentinel;
  emlrtMEXProfilingFunctionEntryCPP((char_T *)DistWrapper_new_complete_name,
                                    static_cast<boolean_T>(isMexOutdated),
                                    &profilerSentinel);
  emlrtMEXProfilingFunctionExitCPP(&profilerSentinel);
}

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

// End of code generation (DistWrapper.cpp)
