//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_DistWrapper_mex.cpp
//
// Code generation for function '_coder_DistWrapper_mex'
//

// Include files
#include "_coder_DistWrapper_mex.h"
#include "DistWrapper.h"
#include "DistWrapper_data.h"
#include "DistWrapper_initialize.h"
#include "DistWrapper_terminate.h"
#include "_coder_DistWrapper_api.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void DistWrapper_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                             const mxArray *prhs[1])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        11, "DistWrapper");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "DistWrapper");
  }
  // Call the function.
  DistWrapper_api(prhs[0], &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexAtExit(&DistWrapper_atexit);
  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&DistWrapper_nestLockGlobal);
  // Module initialization.
  DistWrapper_initialize();
  st.tls = emlrtRootTLSGlobal;
  try { // Dispatch the entry-point.
    DistWrapper_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    DistWrapper_terminate();
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

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(),
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_DistWrapper_mex.cpp)
