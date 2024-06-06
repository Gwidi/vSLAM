//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xzlascl.cpp
//
// Code generation for function 'xzlascl'
//

// Include files
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace reflapack {
void b_xzlascl(real_T cfrom, real_T cto, real_T A[4])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    A[0] *= mul;
    A[1] *= mul;
    A[2] *= mul;
    A[3] *= mul;
  }
}

void c_xzlascl(real_T cfrom, real_T cto, real_T A[9])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (int32_T j{0}; j < 3; j++) {
      int32_T offset;
      offset = j * 3 - 1;
      A[offset + 1] *= mul;
      A[offset + 2] *= mul;
      A[offset + 3] *= mul;
    }
  }
}

void d_xzlascl(real_T cfrom, real_T cto, real_T A[16])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (int32_T j{0}; j < 4; j++) {
      int32_T offset;
      offset = (j << 2) - 1;
      A[offset + 1] *= mul;
      A[offset + 2] *= mul;
      A[offset + 3] *= mul;
      A[offset + 4] *= mul;
    }
  }
}

void xzlascl(real_T cfrom, real_T cto, real_T A[3])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    A[0] *= mul;
    A[1] *= mul;
    A[2] *= mul;
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzlascl.cpp)
