/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * monovslam.h
 *
 * Code generation for function 'monovslam'
 *
 */

#pragma once

/* Include files */
#include "helperMonoVisualSLAM_internal_types.h"
#include "helperMonoVisualSLAM_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void monovslam_addFrame(helperMonoVisualSLAMStackData *SD, const emlrtStack *sp,
                        monovslam *b_vslam, const uint8_T b_I[921600]);

/* End of code generation (monovslam.h) */
