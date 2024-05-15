/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkTransformationMatrixCondition.c
 *
 * Code generation for function 'checkTransformationMatrixCondition'
 *
 */

/* Include files */
#include "checkTransformationMatrixCondition.h"
#include "helperMonoVisualSLAM_data.h"
#include "rt_nonfinite.h"
#include "xzgetrf.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pe_emlrtRSI = {
    38,                   /* lineNo */
    "isBadlyConditioned", /* fcnName */
    "/Applications/MATLAB_R2023b.app/toolbox/images/images/+images/+geotrans/"
    "+internal/checkTransformationMatrixCondition.m" /* pathName */
};

static emlrtRSInfo
    qe_emlrtRSI =
        {
            14,      /* lineNo */
            "rcond", /* fcnName */
            "/Applications/MATLAB_R2023b.app/toolbox/eml/lib/matlab/matfun/"
            "rcond.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI =
    {
        44,      /* lineNo */
        "rcond", /* fcnName */
        "/Applications/MATLAB_R2023b.app/toolbox/eml/eml/+coder/+internal/"
        "rcond.m" /* pathName */
};

/* Function Definitions */
boolean_T isBadlyConditioned(const emlrtStack *sp, const real_T A[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_A[9];
  real_T normA;
  real_T rc;
  real_T s;
  int32_T b_i;
  int32_T b_j;
  int32_T j;
  int32_T jA;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &qe_emlrtRSI;
  rc = 0.0;
  normA = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    s = (muDoubleScalarAbs(A[3 * j]) + muDoubleScalarAbs(A[3 * j + 1])) +
        muDoubleScalarAbs(A[3 * j + 2]);
    if (muDoubleScalarIsNaN(s)) {
      normA = rtNaN;
      exitg1 = true;
    } else {
      if (s > normA) {
        normA = s;
      }
      j++;
    }
  }
  if (!(normA == 0.0)) {
    int32_T ipiv[3];
    c_st.site = &re_emlrtRSI;
    memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
    d_st.site = &vd_emlrtRSI;
    xzgetrf(&d_st, b_A, ipiv);
    jA = 2;
    int32_T exitg2;
    do {
      exitg2 = 0;
      if (jA + 1 > 0) {
        if (b_A[jA + 3 * jA] == 0.0) {
          exitg2 = 1;
        } else {
          jA--;
        }
      } else {
        real_T x[3];
        real_T ainvnm;
        int32_T iter;
        int32_T jump;
        int32_T kase;
        ainvnm = 0.0;
        iter = 2;
        kase = 1;
        jump = 1;
        j = 0;
        x[0] = 0.33333333333333331;
        x[1] = 0.33333333333333331;
        x[2] = 0.33333333333333331;
        int32_T exitg3;
        do {
          exitg3 = 0;
          if (kase == 1) {
            int32_T ix;
            for (b_j = 0; b_j < 3; b_j++) {
              int32_T i;
              jA = b_j + b_j * 3;
              i = 1 - b_j;
              for (b_i = 0; b_i <= i; b_i++) {
                ix = (b_j + b_i) + 1;
                x[ix] -= x[b_j] * b_A[(jA + b_i) + 1];
              }
            }
            for (b_j = 2; b_j >= 0; b_j--) {
              jA = b_j + b_j * 3;
              x[b_j] /= b_A[jA];
              for (b_i = 0; b_i < b_j; b_i++) {
                ix = (b_j - b_i) - 1;
                x[ix] -= x[b_j] * b_A[(jA - b_i) - 1];
              }
            }
          } else {
            for (b_j = 0; b_j < 3; b_j++) {
              jA = b_j * 3;
              s = x[b_j];
              for (b_i = 0; b_i < b_j; b_i++) {
                s -= b_A[jA + b_i] * x[b_i];
              }
              x[b_j] = s / b_A[jA + b_j];
            }
            for (b_j = 2; b_j >= 0; b_j--) {
              int32_T i;
              jA = b_j * 3;
              s = x[b_j];
              i = b_j + 2;
              for (b_i = 3; b_i >= i; b_i--) {
                s -= b_A[(jA + b_i) - 1] * x[b_i - 1];
              }
              x[b_j] = s;
            }
          }
          if (jump == 1) {
            real_T absrexk;
            real_T ainvnm_tmp;
            s = muDoubleScalarAbs(x[0]);
            absrexk = muDoubleScalarAbs(x[1]);
            ainvnm_tmp = muDoubleScalarAbs(x[2]);
            ainvnm = (s + absrexk) + ainvnm_tmp;
            if ((!muDoubleScalarIsInf(ainvnm)) &&
                (!muDoubleScalarIsNaN(ainvnm))) {
              if (s > 2.2250738585072014E-308) {
                x[0] /= s;
              } else {
                x[0] = 1.0;
              }
              if (absrexk > 2.2250738585072014E-308) {
                x[1] /= absrexk;
              } else {
                x[1] = 1.0;
              }
              if (ainvnm_tmp > 2.2250738585072014E-308) {
                x[2] /= ainvnm_tmp;
              } else {
                x[2] = 1.0;
              }
              kase = 2;
              jump = 2;
            } else {
              exitg3 = 1;
            }
          } else if (jump == 2) {
            real_T absrexk;
            j = 0;
            s = muDoubleScalarAbs(x[0]);
            absrexk = muDoubleScalarAbs(x[1]);
            if (!(absrexk <= s)) {
              j = 1;
              s = absrexk;
            }
            if (!(muDoubleScalarAbs(x[2]) <= s)) {
              j = 2;
            }
            iter = 2;
            x[0] = 0.0;
            x[1] = 0.0;
            x[2] = 0.0;
            x[j] = 1.0;
            kase = 1;
            jump = 3;
          } else if (jump == 3) {
            real_T absrexk;
            real_T ainvnm_tmp;
            s = muDoubleScalarAbs(x[0]);
            absrexk = muDoubleScalarAbs(x[1]);
            ainvnm_tmp = muDoubleScalarAbs(x[2]);
            ainvnm = (s + absrexk) + ainvnm_tmp;
            if (ainvnm <= x[0]) {
              x[0] = 1.0;
              x[1] = -1.5;
              x[2] = 2.0;
              kase = 1;
              jump = 5;
            } else {
              if (s > 2.2250738585072014E-308) {
                x[0] /= s;
              } else {
                x[0] = 1.0;
              }
              if (absrexk > 2.2250738585072014E-308) {
                x[1] /= absrexk;
              } else {
                x[1] = 1.0;
              }
              if (ainvnm_tmp > 2.2250738585072014E-308) {
                x[2] /= ainvnm_tmp;
              } else {
                x[2] = 1.0;
              }
              kase = 2;
              jump = 4;
            }
          } else if (jump == 4) {
            real_T absrexk;
            jA = j;
            j = 0;
            s = muDoubleScalarAbs(x[0]);
            absrexk = muDoubleScalarAbs(x[1]);
            if (!(absrexk <= s)) {
              j = 1;
              s = absrexk;
            }
            if (!(muDoubleScalarAbs(x[2]) <= s)) {
              j = 2;
            }
            if ((muDoubleScalarAbs(x[jA]) != muDoubleScalarAbs(x[j])) &&
                (iter <= 5)) {
              iter++;
              x[0] = 0.0;
              x[1] = 0.0;
              x[2] = 0.0;
              x[j] = 1.0;
              kase = 1;
              jump = 3;
            } else {
              x[0] = 1.0;
              x[1] = -1.5;
              x[2] = 2.0;
              kase = 1;
              jump = 5;
            }
          } else if (jump == 5) {
            s = 2.0 *
                ((muDoubleScalarAbs(x[0]) + muDoubleScalarAbs(x[1])) +
                 muDoubleScalarAbs(x[2])) /
                3.0 / 3.0;
            if (s > ainvnm) {
              ainvnm = s;
            }
            exitg3 = 1;
          }
        } while (exitg3 == 0);
        if (ainvnm != 0.0) {
          rc = 1.0 / ainvnm / normA;
        }
        if (muDoubleScalarIsNaN(rc)) {
          boolean_T p;
          p = false;
          for (jA = 0; jA < 9; jA++) {
            if (p || muDoubleScalarIsNaN(b_A[jA])) {
              p = true;
            }
          }
          if (!p) {
            rc = 0.0;
          }
        }
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  return rc < 2.2204460492503131E-16;
}

/* End of code generation (checkTransformationMatrixCondition.c) */
