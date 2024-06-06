//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// adjustNumScaleLevels.h
//
// Code generation for function 'adjustNumScaleLevels'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace vslam {
void adjustNumScaleLevels(const emlrtStack &sp, const real_T imageSize[2],
                          real_T &numLevels, real_T scaleFactor);

}
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (adjustNumScaleLevels.h)
