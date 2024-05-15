/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM_data.c
 *
 * Code generation for function 'helperMonoVisualSLAM_data'
 *
 */

/* Include files */
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                               /* bFirstTime */
    false,                                              /* bInitialized */
    131643U,                                            /* fVersionInfo */
    NULL,                                               /* fErrorFunction */
    "helperMonoVisualSLAM",                             /* fFunctionName */
    NULL,                                               /* fRTCallStack */
    false,                                              /* bDebugMode */
    {484843642U, 120961338U, 3062646369U, 3495121251U}, /* fSigWrd */
    NULL                                                /* fSigMem */
};

emlrtRSInfo t_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/lang/"
    "validateattributes.m" /* pathName */
};

emlrtRSInfo tc_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pathName */
};

emlrtRSInfo kd_emlrtRSI = {
    117,                      /* lineNo */
    "rigidtform3dImpl/set.R", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pathName */
};

emlrtRSInfo ld_emlrtRSI = {
    13,                      /* lineNo */
    "checkRotationMatrix3D", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkRotationMatrix3D.m" /* pathName */
};

emlrtRSInfo md_emlrtRSI = {
    14,                      /* lineNo */
    "checkRotationMatrix3D", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkRotationMatrix3D.m" /* pathName */
};

emlrtRSInfo
    sd_emlrtRSI =
        {
            107,          /* lineNo */
            "callLAPACK", /* fcnName */
            "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
            "svd.m" /* pathName */
};

emlrtRSInfo td_emlrtRSI = {
    34,       /* lineNo */
    "xgesvd", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgesvd.m" /* pathName */
};

emlrtRSInfo vd_emlrtRSI = {
    30,       /* lineNo */
    "xgetrf", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrf.m" /* pathName */
};

emlrtRSInfo ae_emlrtRSI = {
    20,                    /* lineNo */
    "matricesNearlyEqual", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/matricesNearlyEqual.m" /* pathName */
};

emlrtRSInfo be_emlrtRSI = {
    30,                    /* lineNo */
    "matricesNearlyEqual", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/matricesNearlyEqual.m" /* pathName */
};

emlrtRTEInfo emlrtRTEI = {
    123,                      /* lineNo */
    21,                       /* colNo */
    "rigidtform3dImpl/set.R", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pName */
};

const int8_T iv[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};

/* End of code generation (helperMonoVisualSLAM_data.c) */
