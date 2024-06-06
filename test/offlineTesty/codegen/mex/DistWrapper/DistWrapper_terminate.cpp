//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// DistWrapper_terminate.cpp
//
// Code generation for function 'DistWrapper_terminate'
//

// Include files
#include "DistWrapper_terminate.h"
#include "DistWrapper.h"
#include "DistWrapper_data.h"
#include "_coder_DistWrapper_mex.h"
#include "rt_nonfinite.h"
#include "omp.h"

// Function Declarations
static void DistWrapper_emx_free_dtor_fcn(const void *r);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

// Function Definitions
static void DistWrapper_emx_free_dtor_fcn(const void *r)
{
  DistWrapper_emx_free();
}

static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void DistWrapper_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&DistWrapper_nestLockGlobal);
  st.tls = emlrtRootTLSGlobal;
  try {
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&emlrtExitTimeCleanupDtorFcn,
                                      nullptr, nullptr, nullptr);
    emlrtEnterRtStackR2012b(&st);
    emlrtPushHeapReferenceStackR2021a(&st, false, nullptr,
                                      (void *)&DistWrapper_emx_free_dtor_fcn,
                                      nullptr, nullptr, nullptr);
    DistWrapper_delete();
    DistWrapper_emx_free();
    emlrtProfilerUnregisterMEXFcn((char_T *)DistWrapper_complete_name,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)DistWrapper_new_complete_name,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_DistWrapper_delete_complete_n,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)DistWrapper_init_complete_name,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_DistWrapper_emx_init_complete,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtProfilerUnregisterMEXFcn((char_T *)c_DistWrapper_emx_free_complete,
                                  static_cast<boolean_T>(isMexOutdated));
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&DistWrapper_nestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&DistWrapper_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

void DistWrapper_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (DistWrapper_terminate.cpp)
