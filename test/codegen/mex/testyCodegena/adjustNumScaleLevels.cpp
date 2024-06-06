//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// adjustNumScaleLevels.cpp
//
// Code generation for function 'adjustNumScaleLevels'
//

// Include files
#include "adjustNumScaleLevels.h"
#include "message.h"
#include "rt_nonfinite.h"
#include "testyCodegena_internal_types.h"
#include "testyCodegena_mexutil.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo tc_emlrtRSI{
    11,                     // lineNo
    "adjustNumScaleLevels", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+vslam/adjustNumScaleLevels.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    16,                     // lineNo
    "adjustNumScaleLevels", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+vslam/adjustNumScaleLevels.m" // pathName
};

static emlrtRSInfo vc_emlrtRSI{
    15,                     // lineNo
    "adjustNumScaleLevels", // fcnName
    "/Applications/MATLAB_R2024a.app/toolbox/vision/vision/+vision/+internal/"
    "+vslam/adjustNumScaleLevels.m" // pathName
};

static emlrtRSInfo
    wc_emlrtRSI{
        29,        // lineNo
        "sprintf", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m" // pathName
    };

static emlrtMCInfo
    b_emlrtMCI{
        53,              // lineNo
        14,              // colNo
        "nonConstPrint", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m" // pName
    };

static emlrtMCInfo
    c_emlrtMCI{
        55,              // lineNo
        15,              // colNo
        "nonConstPrint", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m" // pName
    };

static emlrtMCInfo
    d_emlrtMCI{
        45,                // lineNo
        33,                // colNo
        "message/warning", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
        "message.m" // pName
    };

static emlrtMCInfo
    e_emlrtMCI{
        45,                // lineNo
        17,                // colNo
        "message/warning", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
        "message.m" // pName
    };

static emlrtRTEInfo u_emlrtRTEI{
    14,    // lineNo
    9,     // colNo
    "log", // fName
    "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/elfun/log.m" // pName
};

static emlrtDCInfo
    i_emlrtDCI{
        57,              // lineNo
        53,              // colNo
        "nonConstPrint", // fName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m", // pName
        4            // checkKind
    };

static emlrtRSInfo
    ng_emlrtRSI{
        53,              // lineNo
        "nonConstPrint", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m" // pathName
    };

static emlrtRSInfo
    og_emlrtRSI{
        55,              // lineNo
        "nonConstPrint", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m" // pathName
    };

static emlrtRSInfo
    pg_emlrtRSI{
        45,                // lineNo
        "message/warning", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/eml/+coder/+internal/"
        "message.m" // pathName
    };

static emlrtRSInfo
    sg_emlrtRSI{
        58,              // lineNo
        "nonConstPrint", // fcnName
        "/Applications/MATLAB_R2024a.app/toolbox/eml/lib/matlab/strfun/"
        "sprintf.m" // pathName
    };

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<char_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *tmpStr,
                             const char_T *identifier,
                             coder::array<char_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y);

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo &location);

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            const mxArray *m6, const mxArray *m7,
                            emlrtMCInfo &location);

static const mxArray *length(const emlrtStack &sp, const mxArray *m1,
                             emlrtMCInfo &location);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<char_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T b_iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, b_iv[0], b_iv[1]);
  emlrtImportArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 1, false);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *tmpStr,
                             const char_T *identifier,
                             coder::array<char_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(tmpStr), &thisId, y);
  emlrtDestroyArray(&tmpStr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo &location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 3, &pArrays[0],
                               "feval", true, &location);
}

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            const mxArray *m6, const mxArray *m7,
                            emlrtMCInfo &location)
{
  const mxArray *pArrays[7];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  pArrays[4] = m5;
  pArrays[5] = m6;
  pArrays[6] = m7;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 7, &pArrays[0],
                               "feval", true, &location);
}

static const mxArray *length(const emlrtStack &sp, const mxArray *m1,
                             emlrtMCInfo &location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 1, &pArray, "length",
                               true, &location);
}

namespace coder {
namespace vision {
namespace internal {
namespace vslam {
void adjustNumScaleLevels(const emlrtStack &sp, const real_T imageSize[2],
                          real_T &numLevels, real_T scaleFactor)
{
  static const int32_T b_iv[2]{1, 7};
  static const int32_T iv1[2]{1, 5};
  static const int32_T iv2[2]{1, 7};
  static const int32_T iv3[2]{1, 7};
  static const int32_T iv4[2]{1, 31};
  static const char_T d_u[31]{'v', 'i', 's', 'i', 'o', 'n', ':', 'v',
                              's', 'l', 'a', 'm', '_', 'u', 't', 'i',
                              'l', 's', ':', 'm', 'a', 'x', 'N', 'u',
                              'm', 'L', 'e', 'v', 'e', 'l', 's'};
  static const char_T b_u[7]{'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  static const char_T c_u[7]{'m', 'e', 's', 's', 'a', 'g', 'e'};
  static const char_T u[7]{'s', 'p', 'r', 'i', 'n', 't', 'f'};
  static const char_T formatSpec[5]{'%', '4', '.', '3', 'f'};
  ::coder::internal::message obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *m;
  const mxArray *tmpStr;
  const mxArray *y;
  real_T x;
  int32_T iv5[2];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if ((imageSize[0] > imageSize[1]) || (muDoubleScalarIsNaN(imageSize[0]) &&
                                        (!muDoubleScalarIsNaN(imageSize[1])))) {
    x = imageSize[1];
  } else {
    x = imageSize[0];
  }
  st.site = &tc_emlrtRSI;
  if (x < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
  }
  x = muDoubleScalarLog(x);
  st.site = &tc_emlrtRSI;
  st.site = &tc_emlrtRSI;
  if (scaleFactor < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
  }
  x = muDoubleScalarFloor((x - 4.1431347263915326) /
                          muDoubleScalarLog(scaleFactor));
  if (numLevels > x + 1.0) {
    real_T strSize;
    numLevels = x + 1.0;
    st.site = &uc_emlrtRSI;
    b_st.site = &wc_emlrtRSI;
    tmpStr = nullptr;
    y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
    emlrtAssign(&y, m);
    b_y = nullptr;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&b_st, 5, m, &formatSpec[0]);
    emlrtAssign(&b_y, m);
    c_y = nullptr;
    m = emlrtCreateDoubleScalar(scaleFactor);
    emlrtAssign(&c_y, m);
    c_st.site = &ng_emlrtRSI;
    emlrtAssign(&tmpStr, feval(c_st, y, b_y, c_y, b_emlrtMCI));
    c_st.site = &og_emlrtRSI;
    strSize =
        emlrt_marshallIn(c_st, length(c_st, emlrtAlias(tmpStr), c_emlrtMCI),
                         "<output of length>");
    if (!(strSize >= 0.0)) {
      emlrtNonNegativeCheckR2012b(strSize, &i_emlrtDCI, &b_st);
    }
    c_st.site = &sg_emlrtRSI;
    emlrt_marshallIn(c_st, emlrtAlias(tmpStr), "tmpStr", obj.Arguments.f1);
    emlrtDestroyArray(&tmpStr);
    st.site = &vc_emlrtRSI;
    d_y = nullptr;
    m = emlrtCreateCharArray(2, &iv2[0]);
    emlrtInitCharArrayR2013a(&st, 7, m, &b_u[0]);
    emlrtAssign(&d_y, m);
    e_y = nullptr;
    m = emlrtCreateCharArray(2, &iv3[0]);
    emlrtInitCharArrayR2013a(&st, 7, m, &c_u[0]);
    emlrtAssign(&e_y, m);
    f_y = nullptr;
    m = emlrtCreateCharArray(2, &iv4[0]);
    emlrtInitCharArrayR2013a(&st, 31, m, &d_u[0]);
    emlrtAssign(&f_y, m);
    g_y = nullptr;
    iv5[0] = 1;
    iv5[1] = obj.Arguments.f1.size(1);
    m = emlrtCreateCharArray(2, &iv5[0]);
    emlrtInitCharArrayR2013a(&st, obj.Arguments.f1.size(1), m,
                             &obj.Arguments.f1[0]);
    emlrtAssign(&g_y, m);
    h_y = nullptr;
    m = emlrtCreateDoubleScalar(imageSize[0]);
    emlrtAssign(&h_y, m);
    i_y = nullptr;
    m = emlrtCreateDoubleScalar(imageSize[1]);
    emlrtAssign(&i_y, m);
    j_y = nullptr;
    m = emlrtCreateDoubleScalar(x + 1.0);
    emlrtAssign(&j_y, m);
    k_y = nullptr;
    m = emlrtCreateDoubleScalar(x + 1.0);
    emlrtAssign(&k_y, m);
    b_st.site = &pg_emlrtRSI;
    feval(b_st, d_y, feval(b_st, e_y, f_y, g_y, h_y, i_y, j_y, k_y, d_emlrtMCI),
          e_emlrtMCI);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace vslam
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (adjustNumScaleLevels.cpp)
