//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// constrainToRotationMatrix3D.cpp
//
// Code generation for function 'constrainToRotationMatrix3D'
//

// Include files
#include "constrainToRotationMatrix3D.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "testyCodegena_data.h"
#include "xzgetrf.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo pd_emlrtRSI{
    10,                            // lineNo
    "constrainToRotationMatrix3D", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/constrainToRotationMatrix3D.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    17,                            // lineNo
    "constrainToRotationMatrix3D", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/constrainToRotationMatrix3D.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    35,                            // lineNo
    "constrainToRotationMatrix3D", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/images/images/+images/+geotrans/"
    "+internal/constrainToRotationMatrix3D.m" // pathName
};

static emlrtRSInfo sd_emlrtRSI{
    36,    // lineNo
    "svd", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/matfun/svd.m" // pathName
};

static emlrtRSInfo td_emlrtRSI{
    52,    // lineNo
    "svd", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/svd.m" // pathName
};

static emlrtRSInfo ue_emlrtRSI{
    21,    // lineNo
    "det", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/matfun/det.m" // pathName
};

// Function Definitions
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void constrainToRotationMatrix3D(const emlrtStack &sp, const real_T R[9],
                                 real_T Rc[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T R_clamped[9];
  real_T V[9];
  real_T b_R_clamped[9];
  real_T minval[9];
  real_T d;
  int32_T ipiv[3];
  int32_T k;
  boolean_T isodd;
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
  for (k = 0; k < 9; k++) {
    R_clamped[k] = muDoubleScalarMax(muDoubleScalarMin(R[k], 1.0), -1.0);
  }
  real_T S[3];
  st.site = &pd_emlrtRSI;
  b_st.site = &sd_emlrtRSI;
  c_st.site = &td_emlrtRSI;
  d_st.site = &ud_emlrtRSI;
  std::copy(&R_clamped[0], &R_clamped[9], &b_R_clamped[0]);
  e_st.site = &vd_emlrtRSI;
  ::coder::internal::reflapack::xzsvdc(e_st, b_R_clamped, minval, S, V);
  for (int32_T i{0}; i < 3; i++) {
    real_T b_d;
    real_T d1;
    d = minval[i];
    b_d = minval[i + 3];
    d1 = minval[i + 6];
    for (k = 0; k < 3; k++) {
      Rc[i + 3 * k] = (d * V[k] + b_d * V[k + 3]) + d1 * V[k + 6];
    }
  }
  st.site = &qd_emlrtRSI;
  b_st.site = &ue_emlrtRSI;
  std::copy(&Rc[0], &Rc[9], &minval[0]);
  c_st.site = &ve_emlrtRSI;
  ::coder::internal::reflapack::xzgetrf(c_st, minval, ipiv);
  isodd = (ipiv[0] > 1);
  d = minval[0] * minval[4] * minval[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    d = -d;
  }
  if (d < 0.0) {
    for (int32_T i{0}; i < 3; i++) {
      k = 3 * i + 1;
      d = Rc[3 * i];
      Rc[3 * i] = Rc[k];
      Rc[k] = d;
    }
  }
  for (int32_T i{0}; i < 9; i++) {
    minval[i] = R_clamped[i] - Rc[i];
  }
  st.site = &rd_emlrtRSI;
  d = b_norm(st, minval) / 2.2204460492503131E-16;
  if (d < 10.0) {
    std::copy(&R_clamped[0], &R_clamped[9], &Rc[0]);
  }
}

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder

// End of code generation (constrainToRotationMatrix3D.cpp)
