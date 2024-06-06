//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_DistWrapper_api.cpp
//
// Code generation for function '_coder_DistWrapper_api'
//

// Include files
#include "_coder_DistWrapper_api.h"
#include "DistWrapper.h"
#include "DistWrapper_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[1310720];

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier))[1310720];

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId))[1310720];

static const mxArray *emlrt_marshallOut(const uint8_T u[1310720]);

// Function Definitions
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[1310720]
{
  static const int32_T dims[2]{1024, 1280};
  int32_T iv[2];
  uint8_T(*ret)[1310720];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "uint8", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (uint8_T(*)[1310720])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier))[1310720]
{
  emlrtMsgIdentifier thisId;
  uint8_T(*y)[1310720];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId))[1310720]
{
  uint8_T(*y)[1310720];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const uint8_T u[1310720])
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv1[2]{1024, 1280};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void DistWrapper_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  uint8_T(*image)[1310720];
  uint8_T(*outimage)[1310720];
  st.tls = emlrtRootTLSGlobal;
  outimage = (uint8_T(*)[1310720])mxMalloc(sizeof(uint8_T[1310720]));
  // Marshall function inputs
  image = emlrt_marshallIn(st, emlrtAlias(prhs), "image");
  // Invoke the target function
  DistWrapper(&st, *image, *outimage);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(*outimage);
}

// End of code generation (_coder_DistWrapper_api.cpp)
