//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena_terminate.cpp
//
// Code generation for function 'testyCodegena_terminate'
//

// Include files
#include "testyCodegena_terminate.h"
#include "_coder_testyCodegena_mex.h"
#include "rt_nonfinite.h"
#include "testyCodegena.h"
#include "testyCodegena_data.h"
#include "omp.h"
#include <cstring>

// Function Declarations
static void emlrtExitTimeCleanupDtorFcn(const void *r);

static void testyCodegena_emx_free_dtor_fcn(const void *r);

// Function Definitions
static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

static void testyCodegena_emx_free_dtor_fcn(const void *r)
{
  testyCodegena_emx_free();
}

void testyCodegena_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&testyCodegena_nestLockGlobal);
  st.tls = emlrtRootTLSGlobal;
  try {
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&emlrtExitTimeCleanupDtorFcn,
                                      nullptr, nullptr, nullptr);
    emlrtEnterRtStackR2012b(&st);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&testyCodegena_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    testyCodegena_delete();
    testyCodegena_emx_free();
    emlrtProfilerUnregisterMEXFcn((char_T *)testyCodegena_complete_name,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)testyCodegena_new_complete_name,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_testyCodegena_delete_complete,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_testyCodegena_init_complete_n,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_testyCodegena_emx_init_comple,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_testyCodegena_emx_free_comple,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&testyCodegena_nestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&testyCodegena_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

void testyCodegena_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (testyCodegena_terminate.cpp)
