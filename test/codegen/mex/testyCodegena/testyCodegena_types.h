//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// testyCodegena_types.h
//
// Code generation for function 'testyCodegena'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#define MAX_THREADS omp_get_max_threads()

// Type Definitions
namespace coder {
namespace vision {
namespace internal {
namespace vslam {
enum class vslamStatusType : uint8_T
{
  TrackingLost = 0, // Default value
  TrackingSuccessful,
  FrequentKeyFrames
};

}
} // namespace internal
} // namespace vision
} // namespace coder
struct monovslam_addFrame {
  uint8_T Iu8_grayT[1310720];
};

struct testyCodegenaStackData {
  monovslam_addFrame f0;
};

// End of code generation (testyCodegena_types.h)
