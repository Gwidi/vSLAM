/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * OneDimArrayBehaviorTransform.c
 *
 * Code generation for function 'OneDimArrayBehaviorTransform'
 *
 */

/* Include files */
#include "OneDimArrayBehaviorTransform.h"
#include "checkTransformationMatrixCondition.h"
#include "constrainToRotationMatrix3D.h"
#include "helperMonoVisualSLAM_data.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fe_emlrtRSI = {
    307,                                                /* lineNo */
    "OneDimArrayBehaviorTransform/initializeArrayData", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    47,                                  /* lineNo */
    "rigidtform3dImpl/rigidtform3dImpl", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    170,                          /* lineNo */
    "MatrixTransformation/set.A", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    175,                          /* lineNo */
    "MatrixTransformation/set.A", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    188,                          /* lineNo */
    "MatrixTransformation/set.A", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI = {
    191,                          /* lineNo */
    "MatrixTransformation/set.A", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    165,                           /* lineNo */
    "rigidtform3dImpl/constrainA", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    202,              /* lineNo */
    "constrainA_alg", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    17,                                   /* lineNo */
    "checkTransformationMatrixCondition", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkTransformationMatrixCondition.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    22,                                   /* lineNo */
    "checkTransformationMatrixCondition", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkTransformationMatrixCondition.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    8,           /* lineNo */
    "warningIf", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/warningIf.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    183,                                        /* lineNo */
    "rigidtform3dImpl/setUnderlyingParameters", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" /* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    181,                          /* lineNo */
    21,                           /* colNo */
    "MatrixTransformation/set.A", /* fName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" /* pName */
};

/* Function Definitions */
void c_OneDimArrayBehaviorTransform_(const emlrtStack *sp,
                                     const real_T this_Translation[3],
                                     const real_T this_R[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T A_in[16];
  real_T Ac[16];
  real_T R[9];
  real_T b_A_in[9];
  real_T x;
  real_T y;
  int32_T A_in_tmp;
  int32_T i;
  boolean_T is_valid_for_this_class;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    A_in[A_in_tmp] = this_R[3 * i];
    A_in[A_in_tmp + 1] = this_R[3 * i + 1];
    A_in[A_in_tmp + 2] = this_R[3 * i + 2];
    A_in[i + 12] = this_Translation[i];
  }
  A_in[3] = 0.0;
  A_in[7] = 0.0;
  A_in[11] = 0.0;
  A_in[15] = 1.0;
  st.site = &fe_emlrtRSI;
  b_st.site = &ge_emlrtRSI;
  c_st.site = &he_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    b_A_in[3 * i] = A_in[A_in_tmp];
    b_A_in[3 * i + 1] = A_in[A_in_tmp + 1];
    b_A_in[3 * i + 2] = A_in[A_in_tmp + 2];
  }
  e_st.site = &me_emlrtRSI;
  constrainToRotationMatrix3D(&e_st, b_A_in, R);
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    Ac[A_in_tmp] = R[3 * i];
    Ac[A_in_tmp + 1] = R[3 * i + 1];
    Ac[A_in_tmp + 2] = R[3 * i + 2];
    Ac[i + 12] = A_in[i + 12];
  }
  Ac[3] = 0.0;
  Ac[7] = 0.0;
  Ac[11] = 0.0;
  Ac[15] = 1.0;
  c_st.site = &ie_emlrtRSI;
  d_st.site = &ae_emlrtRSI;
  x = c_norm(&d_st, Ac);
  d_st.site = &ae_emlrtRSI;
  y = c_norm(&d_st, A_in);
  for (i = 0; i < 16; i++) {
    A_in[i] = Ac[i] - A_in[i];
  }
  d_st.site = &be_emlrtRSI;
  is_valid_for_this_class =
      (c_norm(&d_st, A_in) /
           muDoubleScalarMax(muDoubleScalarMax(x, y), 1.223247290044539E-294) <=
       1.8189894035458565E-12);
  if (!is_valid_for_this_class) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &k_emlrtRTEI, "images:geotrans:invalidTransformationMatrix",
        "images:geotrans:invalidTransformationMatrix", 0);
  }
  c_st.site = &je_emlrtRSI;
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    b_A_in[3 * i] = Ac[A_in_tmp];
    b_A_in[3 * i + 1] = Ac[A_in_tmp + 1];
    b_A_in[3 * i + 2] = Ac[A_in_tmp + 2];
  }
  d_st.site = &ne_emlrtRSI;
  is_valid_for_this_class = isBadlyConditioned(&d_st, b_A_in);
  d_st.site = &oe_emlrtRSI;
  if (is_valid_for_this_class) {
    e_st.site = &se_emlrtRSI;
    warning(&e_st);
  }
  c_st.site = &ke_emlrtRSI;
  d_st.site = &te_emlrtRSI;
  e_st.site = &kd_emlrtRSI;
  f_st.site = &ld_emlrtRSI;
  constrainToRotationMatrix3D(&f_st, R, b_A_in);
  f_st.site = &md_emlrtRSI;
  g_st.site = &ae_emlrtRSI;
  x = b_norm(&g_st, R);
  g_st.site = &ae_emlrtRSI;
  y = b_norm(&g_st, b_A_in);
  for (i = 0; i < 9; i++) {
    R[i] -= b_A_in[i];
  }
  g_st.site = &be_emlrtRSI;
  is_valid_for_this_class =
      (b_norm(&g_st, R) /
           muDoubleScalarMax(muDoubleScalarMax(x, y), 1.223247290044539E-294) <=
       1.8189894035458565E-12);
  if (!is_valid_for_this_class) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "images:geotrans:invalidRotationMatrix",
                                  "images:geotrans:invalidRotationMatrix", 0);
  }
}

/* End of code generation (OneDimArrayBehaviorTransform.c) */
