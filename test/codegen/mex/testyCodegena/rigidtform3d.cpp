//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rigidtform3d.cpp
//
// Code generation for function 'rigidtform3d'
//

// Include files
#include "rigidtform3d.h"
#include "checkTransformationMatrixCondition.h"
#include "constrainToRotationMatrix3D.h"
#include "norm.h"
#include "rigidtform3dImpl.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo jd_emlrtRSI{
    50,                          // lineNo
    "rigidtform3d/rigidtform3d", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/rigidtform3d.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    51,                          // lineNo
    "rigidtform3d/rigidtform3d", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/rigidtform3d.m" // pathName
};

static emlrtRSInfo ld_emlrtRSI{
    61,                                  // lineNo
    "rigidtform3dImpl/rigidtform3dImpl", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/rigidtform3dImpl.m" // pathName
};

static emlrtRSInfo eg_emlrtRSI{
    39,                                            // lineNo
    "OneDimArrayBehaviorTransform/parenReference", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pathName
};

static emlrtRSInfo fg_emlrtRSI{
    70,                                            // lineNo
    "OneDimArrayBehaviorTransform/parenReference", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pathName
};

static emlrtRSInfo gg_emlrtRSI{
    38,                       // lineNo
    "rigidtform3d/makeEmpty", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/rigidtform3d.m" // pathName
};

static emlrtRSInfo hg_emlrtRSI{
    330,                          // lineNo
    "MatrixTransformation/set.T", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/MatrixTransformation.m" // pathName
};

static emlrtBCInfo g_emlrtBCI{
    -1,                                            // iFirst
    -1,                                            // iLast
    61,                                            // lineNo
    42,                                            // colNo
    "",                                            // aName
    "OneDimArrayBehaviorTransform/parenReference", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m", // pName
    0                                        // checkKind
};

static emlrtRTEInfo kb_emlrtRTEI{
    64,                             // lineNo
    13,                             // colNo
    "OneDimArrayBehaviorTransform", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+internal/"
    "+coder/OneDimArrayBehaviorTransform.m" // pName
};

// Function Definitions
namespace coder {
void rigidtform3d::init(const emlrtStack &sp, const real_T varargin_1[9],
                        const real_T varargin_2[3])
{
  images::geotrans::internal::rigidtform3dImpl r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_varargin_1[9];
  real_T x;
  real_T y;
  boolean_T is_rotation_matrix;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &jd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ld_emlrtRSI;
  c_st.site = &md_emlrtRSI;
  d_st.site = &nd_emlrtRSI;
  images::geotrans::internal::constrainToRotationMatrix3D(d_st, varargin_1,
                                                          r.R);
  d_st.site = &od_emlrtRSI;
  e_st.site = &gf_emlrtRSI;
  x = b_norm(e_st, varargin_1);
  e_st.site = &gf_emlrtRSI;
  y = b_norm(e_st, r.R);
  for (int32_T i{0}; i < 9; i++) {
    b_varargin_1[i] = varargin_1[i] - r.R[i];
  }
  e_st.site = &hf_emlrtRSI;
  is_rotation_matrix =
      (b_norm(e_st, b_varargin_1) /
           muDoubleScalarMax(muDoubleScalarMax(x, y), 1.223247290044539E-294) <=
       1.8189894035458565E-12);
  if (!is_rotation_matrix) {
    emlrtErrorWithMessageIdR2018a(&b_st, &q_emlrtRTEI,
                                  "images:geotrans:invalidRotationMatrix",
                                  "images:geotrans:invalidRotationMatrix", 0);
  }
  std::copy(&r.R[0], &r.R[9], &R[0]);
  Translation[0] = varargin_2[0];
  Translation[1] = varargin_2[1];
  Translation[2] = varargin_2[2];
  st.site = &kd_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  c_st.site = &md_emlrtRSI;
  d_st.site = &nd_emlrtRSI;
  images::geotrans::internal::constrainToRotationMatrix3D(d_st, varargin_1,
                                                          r.R);
  d_st.site = &od_emlrtRSI;
  e_st.site = &gf_emlrtRSI;
  x = b_norm(e_st, varargin_1);
  e_st.site = &gf_emlrtRSI;
  y = b_norm(e_st, r.R);
  for (int32_T i{0}; i < 9; i++) {
    b_varargin_1[i] = varargin_1[i] - r.R[i];
  }
  e_st.site = &hf_emlrtRSI;
  is_rotation_matrix =
      (b_norm(e_st, b_varargin_1) /
           muDoubleScalarMax(muDoubleScalarMax(x, y), 1.223247290044539E-294) <=
       1.8189894035458565E-12);
  if (!is_rotation_matrix) {
    emlrtErrorWithMessageIdR2018a(&b_st, &q_emlrtRTEI,
                                  "images:geotrans:invalidRotationMatrix",
                                  "images:geotrans:invalidRotationMatrix", 0);
  }
  r.Translation[0] = varargin_2[0];
  r.Translation[1] = varargin_2[1];
  r.Translation[2] = varargin_2[2];
  Data.set_size(&fb_emlrtRTEI, &sp, 1, 1);
  Data[0] = r;
}

void rigidtform3d::parenReference(const emlrtStack &sp, real_T idx,
                                  rigidtform3d &this1) const
{
  images::geotrans::internal::rigidtform3dImpl dataArray_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T A_in[16];
  real_T Ac[16];
  real_T b_Ac[16];
  real_T b_A_in[9];
  real_T b_R[9];
  real_T x;
  real_T y;
  int32_T A_in_tmp;
  int32_T i;
  boolean_T is_valid_for_this_class;
  st.prev = &sp;
  st.tls = sp.tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &eg_emlrtRSI;
  b_st.site = &gg_emlrtRSI;
  c_st.site = &jd_emlrtRSI;
  d_st.site = &mf_emlrtRSI;
  e_st.site = &nf_emlrtRSI;
  e_st.site = &pf_emlrtRSI;
  f_st.site = &vf_emlrtRSI;
  c_st.site = &kd_emlrtRSI;
  d_st.site = &mf_emlrtRSI;
  e_st.site = &nf_emlrtRSI;
  e_st.site = &pf_emlrtRSI;
  f_st.site = &vf_emlrtRSI;
  i = Data.size(0) * Data.size(1) - 1;
  if ((static_cast<int32_T>(idx) - 1 < 0) ||
      (static_cast<int32_T>(idx) - 1 > i)) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx) - 1, 0, i,
                                  &g_emlrtBCI, (emlrtConstCTX)&sp);
  }
  dataArray_data = Data[static_cast<int32_T>(idx) - 1];
  this1.Data.set_size(&kb_emlrtRTEI, &sp, 1, 1);
  this1.Data[0] = dataArray_data;
  st.site = &fg_emlrtRSI;
  b_st.site = &hg_emlrtRSI;
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    A_in[A_in_tmp] = dataArray_data.R[3 * i];
    A_in[A_in_tmp + 1] = dataArray_data.R[3 * i + 1];
    A_in[A_in_tmp + 2] = dataArray_data.R[3 * i + 2];
    A_in[i + 12] = dataArray_data.Translation[i];
  }
  A_in[3] = 0.0;
  A_in[7] = 0.0;
  A_in[11] = 0.0;
  A_in[15] = 1.0;
  c_st.site = &nf_emlrtRSI;
  d_st.site = &rf_emlrtRSI;
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    b_A_in[3 * i] = A_in[A_in_tmp];
    b_A_in[3 * i + 1] = A_in[A_in_tmp + 1];
    b_A_in[3 * i + 2] = A_in[A_in_tmp + 2];
  }
  e_st.site = &sf_emlrtRSI;
  images::geotrans::internal::constrainToRotationMatrix3D(e_st, b_A_in, b_R);
  for (i = 0; i < 3; i++) {
    A_in_tmp = i << 2;
    Ac[A_in_tmp] = b_R[3 * i];
    Ac[A_in_tmp + 1] = b_R[3 * i + 1];
    Ac[A_in_tmp + 2] = b_R[3 * i + 2];
    Ac[i + 12] = A_in[i + 12];
  }
  Ac[3] = 0.0;
  Ac[7] = 0.0;
  Ac[11] = 0.0;
  Ac[15] = 1.0;
  c_st.site = &of_emlrtRSI;
  d_st.site = &gf_emlrtRSI;
  x = c_norm(d_st, Ac);
  d_st.site = &gf_emlrtRSI;
  y = c_norm(d_st, A_in);
  for (i = 0; i < 16; i++) {
    b_Ac[i] = Ac[i] - A_in[i];
  }
  d_st.site = &hf_emlrtRSI;
  is_valid_for_this_class =
      (c_norm(d_st, b_Ac) /
           muDoubleScalarMax(muDoubleScalarMax(x, y), 1.223247290044539E-294) <=
       1.8189894035458565E-12);
  if (!is_valid_for_this_class) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &p_emlrtRTEI, "images:geotrans:invalidTransformationMatrix",
        "images:geotrans:invalidTransformationMatrix", 0);
  }
  c_st.site = &pf_emlrtRSI;
  images::geotrans::internal::c_checkTransformationMatrixCond(c_st, Ac);
  c_st.site = &qf_emlrtRSI;
  d_st.site = &bg_emlrtRSI;
  e_st.site = &md_emlrtRSI;
  f_st.site = &nd_emlrtRSI;
  images::geotrans::internal::constrainToRotationMatrix3D(f_st, b_R, this1.R);
  f_st.site = &od_emlrtRSI;
  g_st.site = &gf_emlrtRSI;
  x = b_norm(g_st, b_R);
  g_st.site = &gf_emlrtRSI;
  y = b_norm(g_st, this1.R);
  for (i = 0; i < 9; i++) {
    b_R[i] -= this1.R[i];
  }
  g_st.site = &hf_emlrtRSI;
  is_valid_for_this_class =
      (b_norm(g_st, b_R) /
           muDoubleScalarMax(muDoubleScalarMax(x, y), 1.223247290044539E-294) <=
       1.8189894035458565E-12);
  if (!is_valid_for_this_class) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                                  "images:geotrans:invalidRotationMatrix",
                                  "images:geotrans:invalidRotationMatrix", 0);
  }
  this1.Translation[0] = A_in[12];
  this1.Translation[1] = A_in[13];
  this1.Translation[2] = A_in[14];
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder

// End of code generation (rigidtform3d.cpp)
