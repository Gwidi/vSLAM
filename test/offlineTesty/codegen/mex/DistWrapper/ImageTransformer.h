//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ImageTransformer.h
//
// Code generation for function 'ImageTransformer'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
class ImageTransformer {
public:
  void generateMap(const emlrtStack &sp, const array<real_T, 2U> &ptsOut);
  array<real32_T, 2U> XmapSingle;
  array<real32_T, 2U> YmapSingle;
  array<real_T, 2U> SizeOfImage;
  array<char_T, 2U> ClassOfImage;
  array<char_T, 2U> OutputView;
  real_T XBounds[2];
  real_T YBounds[2];
};

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (ImageTransformer.h)
