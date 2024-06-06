//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// DistWrapper_internal_types.h
//
// Code generation for function 'DistWrapper'
//

#pragma once

// Include files
#include "DistWrapper_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct struct_T {
  real_T IntrinsicMatrix[9];
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
};

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtDoubleCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

// End of code generation (DistWrapper_internal_types.h)
