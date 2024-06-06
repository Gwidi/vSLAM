//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// string1.cpp
//
// Code generation for function 'string1'
//

// Include files
#include "string1.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
void rtString::init()
{
  static const char_T cv[52]{
      'i', 'm', 'a', 'g', 'e', 's', ':', 'g', 'e', 'o', 't', 'r', 'a',
      'n', 's', ':', 't', 'r', 'a', 'n', 's', 'f', 'o', 'r', 'm', 'a',
      't', 'i', 'o', 'n', 'M', 'a', 't', 'r', 'i', 'x', 'B', 'a', 'd',
      'l', 'y', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e', 'd'};
  for (int32_T i{0}; i < 52; i++) {
    Value[i] = cv[i];
  }
}

} // namespace coder

// End of code generation (string1.cpp)
