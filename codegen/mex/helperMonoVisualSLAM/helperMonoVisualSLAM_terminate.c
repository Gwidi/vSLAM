/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM_terminate.c
 *
 * Code generation for function 'helperMonoVisualSLAM_terminate'
 *
 */

/* Include files */
#include "helperMonoVisualSLAM_terminate.h"
#include "_coder_helperMonoVisualSLAM_mex.h"
#include "helperMonoVisualSLAM.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void helperMonoVisualSLAM_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  helperMonoVisualSLAM_delete();
  helperMonoVisualSLAM_free(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void helperMonoVisualSLAM_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (helperMonoVisualSLAM_terminate.c) */
