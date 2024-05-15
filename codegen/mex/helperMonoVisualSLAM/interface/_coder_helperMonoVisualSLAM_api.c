/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_helperMonoVisualSLAM_api.c
 *
 * Code generation for function '_coder_helperMonoVisualSLAM_api'
 *
 */

/* Include files */
#include "_coder_helperMonoVisualSLAM_api.h"
#include "helperMonoVisualSLAM.h"
#include "helperMonoVisualSLAM_data.h"
#include "helperMonoVisualSLAM_emxutil.h"
#include "helperMonoVisualSLAM_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo u_emlrtRTEI = {
    1,                                 /* lineNo */
    1,                                 /* colNo */
    "_coder_helperMonoVisualSLAM_api", /* fName */
    ""                                 /* pName */
};

/* Function Declarations */
static uint8_T (
    *b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId))[921600];

static const mxArray *b_emlrt_marshallOut(const real_T u[16]);

static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[921600];

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier))[921600];

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[921600]
{
  uint8_T(*y)[921600];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const real_T u[16])
{
  static const int32_T b_iv[2] = {0, 0};
  static const int32_T iv1[2] = {4, 4};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[921600]
{
  static const int32_T dims[3] = {480, 640, 3};
  int32_T b_iv[3];
  uint8_T(*ret)[921600];
  boolean_T bv[3] = {false, false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint8", false, 3U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (uint8_T(*)[921600])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier))[921600]
{
  emlrtMsgIdentifier thisId;
  uint8_T(*y)[921600];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T b_iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

void helperMonoVisualSLAM_api(helperMonoVisualSLAMStackData *SD,
                              const mxArray *prhs, int32_T nlhs,
                              const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *xyzPoint;
  real_T(*camPoses)[16];
  uint8_T(*image)[921600];
  st.tls = emlrtRootTLSGlobal;
  camPoses = (real_T(*)[16])mxMalloc(sizeof(real_T[16]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  image = emlrt_marshallIn(&st, emlrtAlias(prhs), "image");
  /* Invoke the target function */
  emxInit_real_T(&st, &xyzPoint, &u_emlrtRTEI, true);
  helperMonoVisualSLAM(SD, &st, *image, xyzPoint, *camPoses);
  /* Marshall function outputs */
  xyzPoint->canFreeData = false;
  plhs[0] = emlrt_marshallOut(xyzPoint);
  emxFree_real_T(&st, &xyzPoint);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*camPoses);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_helperMonoVisualSLAM_api.c) */
