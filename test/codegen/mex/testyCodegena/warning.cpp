//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// warning.cpp
//
// Code generation for function 'warning'
//

// Include files
#include "warning.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "testyCodegena_mexutil.h"
#include <cstring>

// Variable Definitions
static emlrtMCInfo f_emlrtMCI{
    14,        // lineNo
    25,        // colNo
    "warning", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warning.m" // pName
};

static emlrtMCInfo g_emlrtMCI{
    14,        // lineNo
    9,         // colNo
    "warning", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warning.m" // pName
};

static emlrtRSInfo qg_emlrtRSI{
    14,        // lineNo
    "warning", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warning.m" // pathName
};

// Function Declarations
static const mxArray *b_feval(const emlrtStack &sp, const mxArray *m1,
                              const mxArray *m2, emlrtMCInfo &location);

// Function Definitions
static const mxArray *b_feval(const emlrtStack &sp, const mxArray *m1,
                              const mxArray *m2, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 2, &pArrays[0],
                               "feval", true, &location);
}

namespace coder {
namespace internal {
void warning(const emlrtStack &sp)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 7};
  static const int32_T iv2[2]{1, 52};
  static const char_T b_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  rtString msgID;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *propValues;
  const mxArray *y;
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  st.prev = &sp;
  st.tls = sp.tls;
  msgID.init();
  y = nullptr;
  propValues = emlrtCreateCharArray(2, &b_iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 7, propValues, &u[0]);
  emlrtAssign(&y, propValues);
  b_y = nullptr;
  propValues = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 7, propValues, &b_u[0]);
  emlrtAssign(&b_y, propValues);
  c_y = nullptr;
  emlrtAssign(&c_y, emlrtCreateClassInstance2022a((emlrtCTX)&sp,
                                                  "coder.internal.string"));
  m = nullptr;
  d_y = nullptr;
  propValues = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 52, propValues, &msgID.Value[0]);
  emlrtAssign(&d_y, propValues);
  emlrtAssign(&m, d_y);
  propValues = m;
  emlrtSetAllProperties((emlrtCTX)&sp, &c_y, 0, 1, (const char_T **)&propNames,
                        (const char_T **)&propClasses, &propValues);
  emlrtAssign(&c_y, emlrtConvertInstanceToRedirectSource(
                        (emlrtCTX)&sp, c_y, 0, "coder.internal.string"));
  st.site = &qg_emlrtRSI;
  feval(st, y, b_feval(st, b_y, c_y, f_emlrtMCI), g_emlrtMCI);
}

} // namespace internal
} // namespace coder

// End of code generation (warning.cpp)
