//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena_internal_types.h
//
// Code generation for function 'testyCodegena'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "testyCodegena_types.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct cell_16 {
  coder::array<char_T, 2U> f1;
  real_T f2;
  real_T f3;
  real_T f4;
  real_T f5;
};

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtEqualityCheckInfo {
  int32_T nDims;
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

// End of code generation (testyCodegena_internal_types.h)
