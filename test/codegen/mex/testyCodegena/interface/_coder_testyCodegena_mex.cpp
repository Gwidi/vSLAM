//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_testyCodegena_mex.cpp
//
// Code generation for function '_coder_testyCodegena_mex'
//

// Include files
#include "_coder_testyCodegena_mex.h"
#include "_coder_testyCodegena_api.h"
#include "rt_nonfinite.h"
#include "testyCodegena.h"
#include "testyCodegena_data.h"
#include "testyCodegena_initialize.h"
#include "testyCodegena_terminate.h"
#include "testyCodegena_types.h"
#include "omp.h"
#include <cstddef>
#include <cstring>
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  testyCodegenaStackData *testyCodegenaStackDataGlobal{nullptr};
  testyCodegenaStackDataGlobal =
      static_cast<testyCodegenaStackData *>(new testyCodegenaStackData);
  mexAtExit(&testyCodegena_atexit);
  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&testyCodegena_nestLockGlobal);
  // Module initialization.
  testyCodegena_initialize();
  st.tls = emlrtRootTLSGlobal;
  try { // Dispatch the entry-point.
    testyCodegena_mexFunction(testyCodegenaStackDataGlobal, nlhs, plhs, nrhs,
                              prhs);
    // Module termination.
    testyCodegena_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&testyCodegena_nestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&testyCodegena_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete testyCodegenaStackDataGlobal;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(),
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void testyCodegena_mexFunction(testyCodegenaStackData *SD, int32_T nlhs,
                               mxArray *plhs[3], int32_T nrhs,
                               const mxArray *prhs[13])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 13) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 13, 4,
                        13, "testyCodegena");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "testyCodegena");
  }
  // Call the function.
  testyCodegena_api(SD, prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

// End of code generation (_coder_testyCodegena_mex.cpp)
