//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rigidtform3d.h
//
// Code generation for function 'rigidtform3d'
//

#pragma once

// Include files
#include "rigidtform3dImpl.h"
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
class rigidtform3d {
public:
  void init(const emlrtStack &sp, const real_T varargin_1[9],
            const real_T varargin_2[3]);
  void parenReference(const emlrtStack &sp, real_T idx,
                      rigidtform3d &this1) const;
  real_T Translation[3];
  real_T R[9];
  array<images::geotrans::internal::rigidtform3dImpl, 2U> Data;
};

} // namespace coder

// End of code generation (rigidtform3d.h)
