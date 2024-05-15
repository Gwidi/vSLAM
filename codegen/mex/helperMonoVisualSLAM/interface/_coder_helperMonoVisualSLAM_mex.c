/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_helperMonoVisualSLAM_mex.c
 *
 * Code generation for function '_coder_helperMonoVisualSLAM_mex'
 *
 */

/* Include files */
#include "_coder_helperMonoVisualSLAM_mex.h"
#include "_coder_helperMonoVisualSLAM_api.h"
#include "helperMonoVisualSLAM_data.h"
#include "helperMonoVisualSLAM_initialize.h"
#include "helperMonoVisualSLAM_terminate.h"
#include "helperMonoVisualSLAM_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void helperMonoVisualSLAM_mexFunction(helperMonoVisualSLAMStackData *SD,
                                      int32_T nlhs, mxArray *plhs[2],
                                      int32_T nrhs, const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        20, "helperMonoVisualSLAM");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "helperMonoVisualSLAM");
  }
  /* Call the function. */
  helperMonoVisualSLAM_api(SD, prhs[0], nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  helperMonoVisualSLAMStackData *c_helperMonoVisualSLAMStackData = NULL;
  c_helperMonoVisualSLAMStackData =
      (helperMonoVisualSLAMStackData *)emlrtMxCalloc(
          (size_t)1, (size_t)1U * sizeof(helperMonoVisualSLAMStackData));
  mexAtExit(&helperMonoVisualSLAM_atexit);
  /* Module initialization. */
  helperMonoVisualSLAM_initialize();
  /* Dispatch the entry-point. */
  helperMonoVisualSLAM_mexFunction(c_helperMonoVisualSLAMStackData, nlhs, plhs,
                                   nrhs, prhs);
  /* Module termination. */
  helperMonoVisualSLAM_terminate();
  emlrtMxFree(c_helperMonoVisualSLAMStackData);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_helperMonoVisualSLAM_mex.c) */
