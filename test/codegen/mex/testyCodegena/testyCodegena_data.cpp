//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena_data.cpp
//
// Code generation for function 'testyCodegena_data'
//

// Include files
#include "testyCodegena_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

boolean_T isMexOutdated;

const char_T *testyCodegena_complete_name;

const char_T *testyCodegena_new_complete_name;

const char_T *c_testyCodegena_delete_complete;

const char_T *c_testyCodegena_init_complete_n;

const char_T *c_testyCodegena_emx_init_comple;

const char_T *c_testyCodegena_emx_free_comple;

emlrtContext emlrtContextGlobal{
    true,                                               // bFirstTime
    false,                                              // bInitialized
    131643U,                                            // fVersionInfo
    nullptr,                                            // fErrorFunction
    "testyCodegena",                                    // fFunctionName
    nullptr,                                            // fRTCallStack
    false,                                              // bDebugMode
    {484843642U, 120961338U, 3062646369U, 3495121251U}, // fSigWrd
    nullptr                                             // fSigMem
};

emlrtRSInfo u_emlrtRSI{
    93,                   // lineNo
    "validateattributes", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/lang/"
    "validateattributes.m" // pathName
};

emlrtRSInfo md_emlrtRSI{
    117,                      // lineNo
    "rigidtform3dImpl/set.R", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pathName
};

emlrtRSInfo nd_emlrtRSI{
    13,                      // lineNo
    "checkRotationMatrix3D", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkRotationMatrix3D.m" // pathName
};

emlrtRSInfo od_emlrtRSI{
    14,                      // lineNo
    "checkRotationMatrix3D", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkRotationMatrix3D.m" // pathName
};

emlrtRSInfo ud_emlrtRSI{
    107,          // lineNo
    "callLAPACK", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/svd.m" // pathName
};

emlrtRSInfo vd_emlrtRSI{
    34,       // lineNo
    "xgesvd", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgesvd.m" // pathName
};

emlrtRSInfo ne_emlrtRSI{
    20,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" // pathName
};

emlrtRSInfo ve_emlrtRSI{
    30,       // lineNo
    "xgetrf", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrf.m" // pathName
};

emlrtRSInfo we_emlrtRSI{
    55,        // lineNo
    "xzgetrf", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzgetrf.m" // pathName
};

emlrtRSInfo xe_emlrtRSI{
    63,        // lineNo
    "xzgetrf", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzgetrf.m" // pathName
};

emlrtRSInfo ye_emlrtRSI{
    45,      // lineNo
    "xgeru", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+blas/"
    "xgeru.m" // pathName
};

emlrtRSInfo af_emlrtRSI{
    45,     // lineNo
    "xger", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+blas/"
    "xger.m" // pathName
};

emlrtRSInfo bf_emlrtRSI{
    15,     // lineNo
    "xger", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+refblas/"
    "xger.m" // pathName
};

emlrtRSInfo cf_emlrtRSI{
    54,      // lineNo
    "xgerx", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+refblas/"
    "xgerx.m" // pathName
};

emlrtRSInfo gf_emlrtRSI{
    20,                    // lineNo
    "matricesNearlyEqual", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/matricesNearlyEqual.m" // pathName
};

emlrtRSInfo hf_emlrtRSI{
    30,                    // lineNo
    "matricesNearlyEqual", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/matricesNearlyEqual.m" // pathName
};

emlrtRSInfo mf_emlrtRSI{
    47,                                  // lineNo
    "rigidtform3dImpl/rigidtform3dImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pathName
};

emlrtRSInfo nf_emlrtRSI{
    294,                          // lineNo
    "MatrixTransformation/set.A", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" // pathName
};

emlrtRSInfo of_emlrtRSI{
    299,                          // lineNo
    "MatrixTransformation/set.A", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" // pathName
};

emlrtRSInfo pf_emlrtRSI{
    312,                          // lineNo
    "MatrixTransformation/set.A", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" // pathName
};

emlrtRSInfo qf_emlrtRSI{
    315,                          // lineNo
    "MatrixTransformation/set.A", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" // pathName
};

emlrtRSInfo rf_emlrtRSI{
    165,                           // lineNo
    "rigidtform3dImpl/constrainA", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pathName
};

emlrtRSInfo sf_emlrtRSI{
    202,              // lineNo
    "constrainA_alg", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pathName
};

emlrtRSInfo vf_emlrtRSI{
    22,                                   // lineNo
    "checkTransformationMatrixCondition", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkTransformationMatrixCondition.m" // pathName
};

emlrtRSInfo bg_emlrtRSI{
    183,                                        // lineNo
    "rigidtform3dImpl/setUnderlyingParameters", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pathName
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t testyCodegena_nestLockGlobal;

emlrtRTEInfo d_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatefinite", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatefinite.m" // pName
};

emlrtRTEInfo e_emlrtRTEI{
    14,                 // lineNo
    37,                 // colNo
    "validatepositive", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" // pName
};

emlrtRTEInfo f_emlrtRTEI{
    13,                // lineNo
    37,                // colNo
    "validateinteger", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" // pName
};

emlrtRTEInfo p_emlrtRTEI{
    305,                          // lineNo
    21,                           // colNo
    "MatrixTransformation/set.A", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" // pName
};

emlrtRTEInfo q_emlrtRTEI{
    123,                      // lineNo
    21,                       // colNo
    "rigidtform3dImpl/set.R", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pName
};

emlrtRTEInfo fb_emlrtRTEI{
    54,             // lineNo
    13,             // colNo
    "rigidtform3d", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/rigidtform3d.m" // pName
};

const int8_T iv[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};

// End of code generation (testyCodegena_data.cpp)
