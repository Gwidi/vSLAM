//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// DistWrapper_data.cpp
//
// Code generation for function 'DistWrapper_data'
//

// Include files
#include "DistWrapper_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

boolean_T isMexOutdated;

const char_T *DistWrapper_complete_name;

const char_T *DistWrapper_new_complete_name;

const char_T *c_DistWrapper_delete_complete_n;

const char_T *DistWrapper_init_complete_name;

const char_T *c_DistWrapper_emx_init_complete;

const char_T *c_DistWrapper_emx_free_complete;

emlrtContext emlrtContextGlobal{
    true,                                               // bFirstTime
    false,                                              // bInitialized
    131643U,                                            // fVersionInfo
    nullptr,                                            // fErrorFunction
    "DistWrapper",                                      // fFunctionName
    nullptr,                                            // fRTCallStack
    false,                                              // bDebugMode
    {484843642U, 120961338U, 3062646369U, 3495121251U}, // fSigWrd
    nullptr                                             // fSigMem
};

emlrtRSInfo c_emlrtRSI{
    26,                                  // lineNo
    "cameraIntrinsics/cameraIntrinsics", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" // pathName
};

emlrtRSInfo d_emlrtRSI{
    25,                                  // lineNo
    "cameraIntrinsics/cameraIntrinsics", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" // pathName
};

emlrtRSInfo e_emlrtRSI{
    100,                                         // lineNo
    "cameraIntrinsicsImpl/cameraIntrinsicsImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

emlrtRSInfo f_emlrtRSI{
    136,                                     // lineNo
    "cameraIntrinsicsImpl/cameraParameters", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsImpl.m" // pathName
};

emlrtRSInfo
    g_emlrtRSI{
        47,                                  // lineNo
        "cameraParameters/cameraParameters", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/"
        "cameraParameters.m" // pathName
    };

emlrtRSInfo
    h_emlrtRSI{
        48,                                  // lineNo
        "cameraParameters/cameraParameters", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/"
        "cameraParameters.m" // pathName
    };

emlrtRSInfo i_emlrtRSI{
    9,                             // lineNo
    "CustomDisplay/CustomDisplay", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/CustomDisplay.m" // pathName
};

emlrtRSInfo j_emlrtRSI{
    246,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo k_emlrtRSI{
    242,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo l_emlrtRSI{
    248,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo m_emlrtRSI{
    267,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo p_emlrtRSI{
    93,                   // lineNo
    "validateattributes", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/lang/"
    "validateattributes.m" // pathName
};

emlrtRSInfo u_emlrtRSI{
    1,                                           // lineNo
    "cameraIntrinsicsBase/cameraIntrinsicsBase", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "cameraIntrinsicsBase.m" // pathName
};

emlrtRSInfo v_emlrtRSI{
    6,                             // lineNo
    "HandleCodegen/HandleCodegen", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+enforcescalar/HandleCodegen.m" // pathName
};

emlrtRSInfo x_emlrtRSI{
    290,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo y_emlrtRSI{
    293,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo ab_emlrtRSI{
    296,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo bb_emlrtRSI{
    297,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo cb_emlrtRSI{
    314,                                   // lineNo
    "CameraParametersImpl/validateInputs", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo gb_emlrtRSI{
    473,                                  // lineNo
    "CameraParametersImpl/set.ImageSize", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/CameraParametersImpl.m" // pathName
};

emlrtRSInfo ib_emlrtRSI{
    23,                                  // lineNo
    "ImageTransformer/ImageTransformer", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+calibration/ImageTransformer.m" // pathName
};

emlrtRSInfo kb_emlrtRSI{
    305,                                                    // lineNo
    "cameraIntrinsics/initializeCameraIntrinsicsArrayData", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsics.m" // pathName
};

emlrtRSInfo lb_emlrtRSI{
    34,                                            // lineNo
    "cameraIntrinsicsArray/cameraIntrinsicsArray", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+codegen/cameraIntrinsicsArray.m" // pathName
};

emlrtRSInfo kc_emlrtRSI{
    39,    // lineNo
    "cat", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t DistWrapper_nestLockGlobal;

emlrtRTEInfo c_emlrtRTEI{
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

// End of code generation (DistWrapper_data.cpp)
