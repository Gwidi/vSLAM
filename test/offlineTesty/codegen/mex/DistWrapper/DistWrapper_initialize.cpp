//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// DistWrapper_initialize.cpp
//
// Code generation for function 'DistWrapper_initialize'
//

// Include files
#include "DistWrapper_initialize.h"
#include "DistWrapper.h"
#include "DistWrapper_data.h"
#include "_coder_DistWrapper_mex.h"
#include "rt_nonfinite.h"

// Function Declarations
static void DistWrapper_once();

// Function Definitions
static void DistWrapper_once()
{
  int32_T iv[10];
  mex_InitInfAndNan();
  c_DistWrapper_emx_free_complete =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/offlineTesty/"
      "DistWrapper.m>DistWrapper_emx_free(codegen)";
  c_DistWrapper_emx_init_complete =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/offlineTesty/"
      "DistWrapper.m>DistWrapper_emx_init(codegen)";
  DistWrapper_init_complete_name =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/offlineTesty/DistWrapper.m>DistWrapper_init(codegen)";
  c_DistWrapper_delete_complete_n =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/offlineTesty/DistWrapper.m>DistWrapper_delete(codegen)";
  DistWrapper_new_complete_name =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/offlineTesty/DistWrapper.m>DistWrapper_new(codegen)";
  DistWrapper_complete_name =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/offlineTesty/DistWrapper.m>DistWrapper(codegen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  for (int32_T i{0}; i < 10; i++) {
    iv[i] = i + 4;
  }
  emlrtProfilerRegisterMEXFcn(
      (char_T *)DistWrapper_complete_name,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/offlineTesty/DistWrapper.m",
      (char_T *)"DistWrapper", 10, &iv[0],
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)DistWrapper_new_complete_name,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/offlineTesty/DistWrapper.m",
      (char_T *)"DistWrapper>new", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_DistWrapper_delete_complete_n,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/offlineTesty/DistWrapper.m",
      (char_T *)"DistWrapper>delete", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)DistWrapper_init_complete_name,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/offlineTesty/DistWrapper.m",
      (char_T *)"DistWrapper>init", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_DistWrapper_emx_init_complete,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/offlineTesty/DistWrapper.m",
      (char_T *)"DistWrapper>emx_init", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_DistWrapper_emx_free_complete,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/offlineTesty/DistWrapper.m",
      (char_T *)"DistWrapper>emx_free", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  DistWrapper_emx_init();
  DistWrapper_new();
  DistWrapper_init();
}

void DistWrapper_initialize()
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    DistWrapper_once();
  }
  emlrtCheckProfilerStatus();
}

// End of code generation (DistWrapper_initialize.cpp)
