//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// constrainToRotationMatrix3D.h
//
// Code generation for function 'constrainToRotationMatrix3D'
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
namespace images {
namespace geotrans {
namespace internal {
void constrainToRotationMatrix3D(const emlrtStack &sp, const real_T R[9],
                                 real_T Rc[9]);

}
} // namespace geotrans
} // namespace images
} // namespace coder

// End of code generation (constrainToRotationMatrix3D.h)
