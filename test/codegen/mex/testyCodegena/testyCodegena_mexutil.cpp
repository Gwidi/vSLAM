//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena_mexutil.cpp
//
// Code generation for function 'testyCodegena_mexutil'
//

// Include files
#include "testyCodegena_mexutil.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
real_T e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                          const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

real_T emlrt_marshallIn(const emlrtStack &sp,
                        const mxArray *a__output_of_length_,
                        const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(a__output_of_length_), &thisId);
  emlrtDestroyArray(&a__output_of_length_);
  return y;
}

real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

void feval(const emlrtStack &sp, const mxArray *m, const mxArray *m1,
           emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  pArrays[0] = m;
  pArrays[1] = m1;
  emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 0, nullptr, 2, &pArrays[0], "feval",
                        true, &location);
}

// End of code generation (testyCodegena_mexutil.cpp)
