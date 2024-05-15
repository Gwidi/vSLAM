/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM_types.h
 *
 * Code generation for function 'helperMonoVisualSLAM'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_c_emxArray_images_geotrans_inte
#define typedef_c_emxArray_images_geotrans_inte
typedef struct {
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} c_emxArray_images_geotrans_inte;
#endif /* typedef_c_emxArray_images_geotrans_inte */

#ifndef typedef_rigidtform3d
#define typedef_rigidtform3d
typedef struct {
  real_T Translation[3];
  real_T R[9];
  c_emxArray_images_geotrans_inte *Data;
} rigidtform3d;
#endif /* typedef_rigidtform3d */

#ifndef typedef_b_monovslam_addFrame
#define typedef_b_monovslam_addFrame
typedef struct {
  uint8_T Iu8_gray[307200];
} b_monovslam_addFrame;
#endif /* typedef_b_monovslam_addFrame */

#ifndef typedef_helperMonoVisualSLAMStackData
#define typedef_helperMonoVisualSLAMStackData
typedef struct {
  b_monovslam_addFrame f0;
} helperMonoVisualSLAMStackData;
#endif /* typedef_helperMonoVisualSLAMStackData */

/* End of code generation (helperMonoVisualSLAM_types.h) */
