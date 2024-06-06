//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena_initialize.cpp
//
// Code generation for function 'testyCodegena_initialize'
//

// Include files
#include "testyCodegena_initialize.h"
#include "_coder_testyCodegena_mex.h"
#include "rt_nonfinite.h"
#include "testyCodegena.h"
#include "testyCodegena_data.h"
#include <cstring>

// Function Declarations
static void testyCodegena_once();

// Function Definitions
static void testyCodegena_once()
{
  static const int32_T lineInfo[32]{11, 13, 15, 16, 18, 19, 20, 21, 24, 27, 28,
                                    29, 30, 31, 33, 34, 37, 38, 39, 40, 41, 42,
                                    43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
  mex_InitInfAndNan();
  c_testyCodegena_emx_free_comple =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/testyCodegena.m>testyCodegena_emx_free(codegen)";
  c_testyCodegena_emx_init_comple =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/testyCodegena.m>testyCodegena_emx_init(codegen)";
  c_testyCodegena_init_complete_n =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/testyCodegena.m>testyCodegena_init(codegen)";
  c_testyCodegena_delete_complete =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/testyCodegena.m>testyCodegena_delete(codegen)";
  testyCodegena_new_complete_name =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/testyCodegena.m>testyCodegena_new(codegen)";
  testyCodegena_complete_name =
      "/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
      "ciowy/vSLAM/test/testyCodegena.m>testyCodegena(codegen)";
  isMexOutdated = emlrtProfilerCheckMEXOutdated();
  emlrtProfilerRegisterMEXFcn(
      (char_T *)testyCodegena_complete_name,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/testyCodegena.m",
      (char_T *)"testyCodegena", 32, &lineInfo[0],
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)testyCodegena_new_complete_name,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/testyCodegena.m",
      (char_T *)"testyCodegena>new", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_testyCodegena_delete_complete,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/testyCodegena.m",
      (char_T *)"testyCodegena>delete", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_testyCodegena_init_complete_n,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/testyCodegena.m",
      (char_T *)"testyCodegena>init", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_testyCodegena_emx_init_comple,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/testyCodegena.m",
      (char_T *)"testyCodegena>emx_init", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  emlrtProfilerRegisterMEXFcn(
      (char_T *)c_testyCodegena_emx_free_comple,
      (char_T *)"/Users/busiu/Desktop/Uczelnia/Projekt przejs\xcc\x81"
                "ciowy/vSLAM/test/testyCodegena.m",
      (char_T *)"testyCodegena>emx_free", 0, nullptr,
      static_cast<boolean_T>(isMexOutdated));
  testyCodegena_emx_init();
  testyCodegena_new();
  testyCodegena_init();
}

void testyCodegena_initialize()
{
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
    testyCodegena_once();
  }
  emlrtCheckProfilerStatus();
}

// End of code generation (testyCodegena_initialize.cpp)
