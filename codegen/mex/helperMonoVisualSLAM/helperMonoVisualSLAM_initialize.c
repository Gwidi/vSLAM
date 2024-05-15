/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM_initialize.c
 *
 * Code generation for function 'helperMonoVisualSLAM_initialize'
 *
 */

/* Include files */
#include "helperMonoVisualSLAM_initialize.h"
#include "_coder_helperMonoVisualSLAM_mex.h"
#include "helperMonoVisualSLAM.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void helperMonoVisualSLAM_once(const emlrtStack *sp);

/* Function Definitions */
static void helperMonoVisualSLAM_once(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  helperMonoVisualSLAM_init(&st);
}

void helperMonoVisualSLAM_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    helperMonoVisualSLAM_once(&st);
  }
}

/* End of code generation (helperMonoVisualSLAM_initialize.c) */
