/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM_emxutil.h
 *
 * Code generation for function 'helperMonoVisualSLAM_emxutil'
 *
 */

#pragma once

/* Include files */
#include "helperMonoVisualSLAM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_emxFree_images_geotrans_inter(
    const emlrtStack *sp, c_emxArray_images_geotrans_inte **pEmxArray);

void c_emxInit_images_geotrans_inter(
    const emlrtStack *sp, c_emxArray_images_geotrans_inte **pEmxArray,
    const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxFreeStruct_rigidtform3d(const emlrtStack *sp, rigidtform3d *pStruct);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInitStruct_rigidtform3d(const emlrtStack *sp, rigidtform3d *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation, boolean_T doPush);

/* End of code generation (helperMonoVisualSLAM_emxutil.h) */
