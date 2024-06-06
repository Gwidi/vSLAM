//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzsvdc.cpp
//
// Code generation for function 'xzsvdc'
//

// Include files
#include "xzsvdc.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xscal.h"
#include "xswap.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include "blas.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo wd_emlrtRSI{
    452,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo xd_emlrtRSI{
    431,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo yd_emlrtRSI{
    418,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    415,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo be_emlrtRSI{
    404,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    377,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo de_emlrtRSI{
    375,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo ee_emlrtRSI{
    358,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo fe_emlrtRSI{
    275,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo ge_emlrtRSI{
    264,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo he_emlrtRSI{
    144,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo ie_emlrtRSI{
    138,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo je_emlrtRSI{
    106,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo ke_emlrtRSI{
    101,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

static emlrtRSInfo oe_emlrtRSI{
    21,                   // lineNo
    "scaleVectorByRecip", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "scaleVectorByRecip.m" // pathName
};

static emlrtRTEInfo r_emlrtRTEI{
    293,      // lineNo
    13,       // colNo
    "xzsvdc", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    13,     // lineNo
    9,      // colNo
    "sqrt", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtRSInfo rg_emlrtRSI{
    159,      // lineNo
    "xzsvdc", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzsvdc.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
namespace reflapack {
void b_xzsvdc(const emlrtStack &sp, real_T A[16], real_T S[4])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[4];
  real_T s[4];
  real_T work[4];
  real_T anrm;
  real_T b;
  real_T cscale;
  real_T nrm;
  real_T r;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T ii;
  int32_T iter;
  int32_T m;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T doscale;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  s[3] = 0.0;
  e[3] = 0.0;
  work[3] = 0.0;
  doscale = false;
  anrm = b_xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    d_xzlascl(anrm, cscale, A);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    d_xzlascl(anrm, cscale, A);
  }
  for (m = 0; m < 3; m++) {
    boolean_T apply_transform;
    qp1 = m + 2;
    iter = m + (m << 2);
    qq = iter + 1;
    apply_transform = false;
    st.site = &ke_emlrtRSI;
    nrm = blas::b_xnrm2(st, 4 - m, A, iter + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[iter] < 0.0) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      s[m] = sqds;
      st.site = &je_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &oe_emlrtRSI;
        blas::b_xscal(b_st, 4 - m, 1.0 / sqds, A, iter + 1);
      } else {
        qs = (iter - m) + 4;
        for (int32_T k{qq}; k <= qs; k++) {
          A[k - 1] /= s[m];
        }
      }
      A[iter]++;
      s[m] = -s[m];
    } else {
      s[m] = 0.0;
    }
    for (qs = qp1; qs < 5; qs++) {
      qq = m + ((qs - 1) << 2);
      if (apply_transform) {
        blas::b_xaxpy(4 - m,
                      -(blas::b_xdotc(4 - m, A, iter + 1, A, qq + 1) / A[iter]),
                      iter + 1, A, qq + 1);
      }
      e[qs - 1] = A[qq];
    }
    if (m + 1 <= 2) {
      st.site = &ie_emlrtRSI;
      nrm = blas::c_xnrm2(st, 3 - m, e, m + 2);
      if (nrm == 0.0) {
        e[m] = 0.0;
      } else {
        if (e[m + 1] < 0.0) {
          e[m] = -nrm;
        } else {
          e[m] = nrm;
        }
        st.site = &he_emlrtRSI;
        sm = e[m];
        if (muDoubleScalarAbs(e[m]) >= 1.0020841800044864E-292) {
          b_st.site = &oe_emlrtRSI;
          blas::c_xscal(b_st, 3 - m, 1.0 / e[m], e, m + 2);
        } else {
          for (int32_T k{qp1}; k < 5; k++) {
            e[k - 1] /= sm;
          }
        }
        e[m + 1]++;
        e[m] = -e[m];
        for (ii = qp1; ii < 5; ii++) {
          work[ii - 1] = 0.0;
        }
        for (qs = qp1; qs < 5; qs++) {
          st.site = &rg_emlrtRSI;
          blas::xaxpy(st, 3 - m, e[qs - 1], A, (m + ((qs - 1) << 2)) + 2, work,
                      m + 2);
        }
        for (qs = qp1; qs < 5; qs++) {
          blas::xaxpy(3 - m, -e[qs - 1] / e[m + 1], work, m + 2, A,
                      (m + ((qs - 1) << 2)) + 2);
        }
      }
    }
  }
  m = 2;
  s[3] = A[15];
  e[2] = A[14];
  e[3] = 0.0;
  iter = 0;
  sqds = s[0];
  if (s[0] != 0.0) {
    nrm = muDoubleScalarAbs(s[0]);
    r = s[0] / nrm;
    sqds = nrm;
    s[0] = nrm;
    e[0] /= r;
  }
  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    r = nrm / e[0];
    e[0] = nrm;
    s[1] *= r;
  }
  snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
  sqds = s[1];
  if (s[1] != 0.0) {
    nrm = muDoubleScalarAbs(s[1]);
    r = s[1] / nrm;
    sqds = nrm;
    s[1] = nrm;
    e[1] /= r;
  }
  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    r = nrm / e[1];
    e[1] = nrm;
    s[2] *= r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[1]));
  sqds = s[2];
  if (s[2] != 0.0) {
    nrm = muDoubleScalarAbs(s[2]);
    r = s[2] / nrm;
    sqds = nrm;
    s[2] = nrm;
    e[2] = A[14] / r;
  }
  if (e[2] != 0.0) {
    nrm = muDoubleScalarAbs(e[2]);
    r = nrm / e[2];
    e[2] = nrm;
    s[3] = A[15] * r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[2]));
  sqds = s[3];
  if (s[3] != 0.0) {
    nrm = muDoubleScalarAbs(s[3]);
    sqds = nrm;
    s[3] = nrm;
  }
  snorm =
      muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(sqds), 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(&sp, &r_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      qp1 = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        qq = 4;
      } else {
        qs = m + 2;
        qq = m + 2;
        exitg2 = false;
        while ((!exitg2) && (qq >= ii)) {
          qs = qq;
          if (qq == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (qq < m + 2) {
              nrm = muDoubleScalarAbs(e[qq - 1]);
            }
            if (qq > ii + 1) {
              nrm += muDoubleScalarAbs(e[qq - 2]);
            }
            r = muDoubleScalarAbs(s[qq - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) ||
                (r <= 1.0020841800044864E-292)) {
              s[qq - 1] = 0.0;
              exitg2 = true;
            } else {
              qq--;
            }
          }
        }
        if (qs == ii) {
          qq = 3;
        } else if (qs == m + 2) {
          qq = 1;
        } else {
          qq = 2;
          ii = qs;
        }
      }
      switch (qq) {
      case 1:
        r = e[m];
        e[m] = 0.0;
        for (int32_T k{qp1}; k >= ii + 1; k--) {
          st.site = &ee_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          if (k > ii + 1) {
            nrm = e[k - 2];
            r = -sn * nrm;
            e[k - 2] = nrm * scale;
          }
        }
        break;
      case 2:
        r = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &de_emlrtRSI;
        for (int32_T k{ii + 1}; k <= m + 2; k++) {
          st.site = &ce_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          nrm = e[k - 1];
          r = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        r = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = b * b + nrm;
          st.site = &be_emlrtRSI;
          if (r < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          r = muDoubleScalarSqrt(r);
          if (b < 0.0) {
            r = -r;
          }
          r = nrm / (b + r);
        } else {
          r = 0.0;
        }
        r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        st.site = &ae_emlrtRSI;
        for (int32_T k{ii + 1}; k <= qp1; k++) {
          st.site = &yd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&r, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[k - 2] = r;
          }
          nrm = e[k - 1];
          r = s[k - 1];
          sm = scale * r + sn * nrm;
          e[k - 1] = scale * nrm - sn * r;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &xd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          nrm = e[k - 1];
          r = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = r;
        iter++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < 4) && (s[ii] < s[qp1])) {
          nrm = s[ii];
          s[ii] = s[qp1];
          s[qp1] = nrm;
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
  S[3] = s[3];
  if (doscale) {
    b_xzlascl(cscale, anrm, S);
  }
}

void xzsvdc(const emlrtStack &sp, real_T A[9], real_T U[9], real_T S[3],
            real_T V[9])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T anrm;
  real_T b;
  real_T cscale;
  real_T f;
  real_T nrm;
  real_T rt;
  real_T scale;
  real_T snorm;
  real_T sqds;
  int32_T i;
  int32_T ii;
  int32_T jj;
  int32_T m;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T doscale;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  std::memset(&U[0], 0, 9U * sizeof(real_T));
  std::memset(&V[0], 0, 9U * sizeof(real_T));
  doscale = false;
  anrm = xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    c_xzlascl(anrm, 6.7178761075670888E-139, A);
  }
  for (int32_T q{0}; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qs = q + 3 * q;
    qq = qs + 1;
    apply_transform = false;
    st.site = &ke_emlrtRSI;
    nrm = blas::xnrm2(st, 3 - q, A, qs + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[qs] < 0.0) {
        rt = -nrm;
      } else {
        rt = nrm;
      }
      s[q] = rt;
      st.site = &je_emlrtRSI;
      if (muDoubleScalarAbs(rt) >= 1.0020841800044864E-292) {
        b_st.site = &oe_emlrtRSI;
        blas::xscal(b_st, 3 - q, 1.0 / rt, A, qs + 1);
      } else {
        i = (qs - q) + 3;
        for (int32_T k{qq}; k <= i; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[qs]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (jj = qp1; jj < 4; jj++) {
      qjj = q + 3 * (jj - 1);
      if (apply_transform) {
        blas::xaxpy(3 - q, -(blas::xdotc(3 - q, A, qs + 1, A, qjj + 1) / A[qs]),
                    qs + 1, A, qjj + 1);
      }
      e[jj - 1] = A[qjj];
    }
    for (ii = q + 1; ii < 4; ii++) {
      qjj = (ii + 3 * q) - 1;
      U[qjj] = A[qjj];
    }
    if (q + 1 <= 1) {
      st.site = &ie_emlrtRSI;
      nrm = blas::xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &he_emlrtRSI;
        f = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          blas::xscal(1.0 / e[0], e);
        } else {
          for (int32_T k{qp1}; k < 4; k++) {
            e[k - 1] /= f;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (jj = qp1; jj < 4; jj++) {
          blas::xaxpy(e[jj - 1], A, 3 * (jj - 1) + 2, work);
        }
        for (jj = qp1; jj < 4; jj++) {
          blas::xaxpy(-e[jj - 1] / e[1], work, A, 3 * (jj - 1) + 2);
        }
      }
      for (ii = qp1; ii < 4; ii++) {
        V[ii - 1] = e[ii - 1];
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (int32_T q{1}; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (s[q] != 0.0) {
      for (jj = qp1; jj < 4; jj++) {
        qjj = (q + 3 * (jj - 1)) + 1;
        blas::xaxpy(3 - q, -(blas::xdotc(3 - q, U, qq + 1, U, qjj) / U[qq]),
                    qq + 1, U, qjj);
      }
      for (ii = q + 1; ii < 4; ii++) {
        qjj = (ii + 3 * q) - 1;
        U[qjj] = -U[qjj];
      }
      U[qq]++;
      if (q - 1 >= 0) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (int32_T q{2}; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 5) / V[1]), 2, V, 5);
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 8) / V[1]), 2, V, 8);
    }
    V[3 * q] = 0.0;
    V[3 * q + 1] = 0.0;
    V[3 * q + 2] = 0.0;
    V[q + 3 * q] = 1.0;
  }
  if (s[0] != 0.0) {
    rt = muDoubleScalarAbs(s[0]);
    nrm = s[0] / rt;
    s[0] = rt;
    e[0] /= nrm;
    st.site = &ge_emlrtRSI;
    blas::xscal(st, nrm, U, 1);
  }
  if (e[0] != 0.0) {
    rt = muDoubleScalarAbs(e[0]);
    nrm = rt / e[0];
    e[0] = rt;
    s[1] *= nrm;
    st.site = &fe_emlrtRSI;
    blas::xscal(st, nrm, V, 4);
  }
  if (s[1] != 0.0) {
    rt = muDoubleScalarAbs(s[1]);
    nrm = s[1] / rt;
    s[1] = rt;
    e[1] = A[7] / nrm;
    st.site = &ge_emlrtRSI;
    blas::xscal(st, nrm, U, 4);
  }
  if (e[1] != 0.0) {
    rt = muDoubleScalarAbs(e[1]);
    nrm = rt / e[1];
    e[1] = rt;
    s[2] = A[8] * nrm;
    st.site = &fe_emlrtRSI;
    blas::xscal(st, nrm, V, 7);
  }
  if (s[2] != 0.0) {
    rt = muDoubleScalarAbs(s[2]);
    nrm = s[2] / rt;
    s[2] = rt;
    st.site = &ge_emlrtRSI;
    blas::xscal(st, nrm, U, 7);
  }
  qq = 0;
  snorm = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax(s[0], e[0]),
                                              muDoubleScalarMax(s[1], e[1])),
                            muDoubleScalarMax(s[2], 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (qq >= 75) {
      emlrtErrorWithMessageIdR2018a(&sp, &r_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      jj = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        qjj = 4;
      } else {
        qs = m + 2;
        qjj = m + 2;
        exitg2 = false;
        while ((!exitg2) && (qjj >= ii)) {
          qs = qjj;
          if (qjj == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (qjj < m + 2) {
              nrm = muDoubleScalarAbs(e[qjj - 1]);
            }
            if (qjj > ii + 1) {
              nrm += muDoubleScalarAbs(e[qjj - 2]);
            }
            rt = muDoubleScalarAbs(s[qjj - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s[qjj - 1] = 0.0;
              exitg2 = true;
            } else {
              qjj--;
            }
          }
        }
        if (qs == ii) {
          qjj = 3;
        } else if (qs == m + 2) {
          qjj = 1;
        } else {
          qjj = 2;
          ii = qs;
        }
      }
      switch (qjj) {
      case 1:
        f = e[m];
        e[m] = 0.0;
        for (int32_T k{jj}; k >= ii + 1; k--) {
          st.site = &ee_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&s[k - 1], &f, &sqds, &scale);
          if (k > ii + 1) {
            f = -scale * e[0];
            e[0] *= sqds;
          }
          blas::xrot(V, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sqds, scale);
        }
        break;
      case 2:
        f = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &de_emlrtRSI;
        for (int32_T k{ii + 1}; k <= m + 2; k++) {
          st.site = &ce_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&s[k - 1], &f, &sqds, &scale);
          nrm = e[k - 1];
          f = -scale * nrm;
          e[k - 1] = nrm * sqds;
          blas::xrot(U, 3 * (k - 1) + 1, 3 * (ii - 1) + 1, sqds, scale);
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        f = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + f) * (nrm - f) + rt * rt) / 2.0;
        nrm = f * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &be_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        f = (sqds + f) * (sqds - f) + rt;
        nrm = sqds * (e[ii] / scale);
        st.site = &ae_emlrtRSI;
        for (int32_T k{ii + 1}; k <= jj; k++) {
          st.site = &yd_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&f, &nrm, &sqds, &scale);
          if (k > ii + 1) {
            e[0] = f;
          }
          nrm = e[k - 1];
          rt = s[k - 1];
          f = sqds * rt + scale * nrm;
          e[k - 1] = sqds * nrm - scale * rt;
          rt = s[k];
          b = scale * rt;
          rt *= sqds;
          i = 3 * (k - 1) + 1;
          qjj = 3 * k + 1;
          blas::xrot(V, i, qjj, sqds, scale);
          st.site = &xd_emlrtRSI;
          sqds = 0.0;
          scale = 0.0;
          drotg(&f, &b, &sqds, &scale);
          s[k - 1] = f;
          nrm = e[k - 1];
          f = sqds * nrm + scale * rt;
          rt = -scale * nrm + sqds * rt;
          s[k] = rt;
          nrm = scale * e[k];
          e[k] *= sqds;
          blas::xrot(U, i, qjj, sqds, scale);
        }
        e[m] = f;
        qq++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
          st.site = &wd_emlrtRSI;
          blas::xscal(st, V, 3 * ii + 1);
        }
        qp1 = ii + 1;
        while ((ii + 1 < 3) && (s[ii] < s[qp1])) {
          rt = s[ii];
          s[ii] = s[qp1];
          s[qp1] = rt;
          i = 3 * ii + 1;
          qjj = 3 * (ii + 1) + 1;
          blas::xswap(V, i, qjj);
          blas::xswap(U, i, qjj);
          ii = qp1;
          qp1++;
        }
        qq = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
  if (doscale) {
    xzlascl(cscale, anrm, S);
  }
}

void xzsvdc(const emlrtStack &sp, real_T A[9], real_T S[3])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T anrm;
  real_T b;
  real_T cscale;
  real_T nrm;
  real_T r;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T ii;
  int32_T iter;
  int32_T m;
  int32_T qp1;
  int32_T qq;
  int32_T qs;
  boolean_T doscale;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  doscale = false;
  anrm = xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    c_xzlascl(anrm, cscale, A);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    c_xzlascl(anrm, cscale, A);
  }
  for (m = 0; m < 2; m++) {
    boolean_T apply_transform;
    qp1 = m + 2;
    iter = m + 3 * m;
    qq = iter + 1;
    apply_transform = false;
    st.site = &ke_emlrtRSI;
    nrm = blas::xnrm2(st, 3 - m, A, iter + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[iter] < 0.0) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      s[m] = sqds;
      st.site = &je_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &oe_emlrtRSI;
        blas::xscal(b_st, 3 - m, 1.0 / sqds, A, iter + 1);
      } else {
        qs = (iter - m) + 3;
        for (int32_T k{qq}; k <= qs; k++) {
          A[k - 1] /= s[m];
        }
      }
      A[iter]++;
      s[m] = -s[m];
    } else {
      s[m] = 0.0;
    }
    for (qs = qp1; qs < 4; qs++) {
      qq = m + 3 * (qs - 1);
      if (apply_transform) {
        blas::xaxpy(3 - m,
                    -(blas::xdotc(3 - m, A, iter + 1, A, qq + 1) / A[iter]),
                    iter + 1, A, qq + 1);
      }
      e[qs - 1] = A[qq];
    }
    if (m + 1 <= 1) {
      st.site = &ie_emlrtRSI;
      nrm = blas::xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        st.site = &he_emlrtRSI;
        sm = e[0];
        if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
          blas::xscal(1.0 / e[0], e);
        } else {
          for (int32_T k{qp1}; k < 4; k++) {
            e[k - 1] /= sm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (qs = qp1; qs < 4; qs++) {
          blas::xaxpy(e[qs - 1], A, 3 * (qs - 1) + 2, work);
        }
        for (qs = qp1; qs < 4; qs++) {
          blas::xaxpy(-e[qs - 1] / e[1], work, A, 3 * (qs - 1) + 2);
        }
      }
    }
  }
  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  iter = 0;
  sqds = s[0];
  if (s[0] != 0.0) {
    nrm = muDoubleScalarAbs(s[0]);
    r = s[0] / nrm;
    sqds = nrm;
    s[0] = nrm;
    e[0] /= r;
  }
  if (e[0] != 0.0) {
    nrm = muDoubleScalarAbs(e[0]);
    r = nrm / e[0];
    e[0] = nrm;
    s[1] *= r;
  }
  snorm = muDoubleScalarMax(muDoubleScalarAbs(sqds), e[0]);
  sqds = s[1];
  if (s[1] != 0.0) {
    nrm = muDoubleScalarAbs(s[1]);
    r = s[1] / nrm;
    sqds = nrm;
    s[1] = nrm;
    e[1] = A[7] / r;
  }
  if (e[1] != 0.0) {
    nrm = muDoubleScalarAbs(e[1]);
    r = nrm / e[1];
    e[1] = nrm;
    s[2] = A[8] * r;
  }
  snorm = muDoubleScalarMax(snorm,
                            muDoubleScalarMax(muDoubleScalarAbs(sqds), e[1]));
  sqds = s[2];
  if (s[2] != 0.0) {
    nrm = muDoubleScalarAbs(s[2]);
    sqds = nrm;
    s[2] = nrm;
  }
  snorm =
      muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(sqds), 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(&sp, &r_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      qp1 = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        qq = 4;
      } else {
        qs = m + 2;
        qq = m + 2;
        exitg2 = false;
        while ((!exitg2) && (qq >= ii)) {
          qs = qq;
          if (qq == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (qq < m + 2) {
              nrm = muDoubleScalarAbs(e[qq - 1]);
            }
            if (qq > ii + 1) {
              nrm += muDoubleScalarAbs(e[qq - 2]);
            }
            r = muDoubleScalarAbs(s[qq - 1]);
            if ((r <= 2.2204460492503131E-16 * nrm) ||
                (r <= 1.0020841800044864E-292)) {
              s[qq - 1] = 0.0;
              exitg2 = true;
            } else {
              qq--;
            }
          }
        }
        if (qs == ii) {
          qq = 3;
        } else if (qs == m + 2) {
          qq = 1;
        } else {
          qq = 2;
          ii = qs;
        }
      }
      switch (qq) {
      case 1:
        r = e[m];
        e[m] = 0.0;
        for (int32_T k{qp1}; k >= ii + 1; k--) {
          st.site = &ee_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          if (k > ii + 1) {
            r = -sn * e[0];
            e[0] *= scale;
          }
        }
        break;
      case 2:
        r = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &de_emlrtRSI;
        for (int32_T k{ii + 1}; k <= m + 2; k++) {
          st.site = &ce_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &r, &scale, &sn);
          nrm = e[k - 1];
          r = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        r = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = b * b + nrm;
          st.site = &be_emlrtRSI;
          if (r < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          r = muDoubleScalarSqrt(r);
          if (b < 0.0) {
            r = -r;
          }
          r = nrm / (b + r);
        } else {
          r = 0.0;
        }
        r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        st.site = &ae_emlrtRSI;
        for (int32_T k{ii + 1}; k <= qp1; k++) {
          st.site = &yd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&r, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[0] = r;
          }
          nrm = e[k - 1];
          r = s[k - 1];
          sm = scale * r + sn * nrm;
          e[k - 1] = scale * nrm - sn * r;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &xd_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          nrm = e[k - 1];
          r = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = r;
        iter++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < 3) && (s[ii] < s[qp1])) {
          nrm = s[ii];
          s[ii] = s[qp1];
          s[qp1] = nrm;
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
  if (doscale) {
    xzlascl(cscale, anrm, S);
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzsvdc.cpp)
