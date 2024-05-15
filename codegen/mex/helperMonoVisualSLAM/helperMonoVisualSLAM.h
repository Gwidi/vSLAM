/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * helperMonoVisualSLAM.h
 *
 * Code generation for function 'helperMonoVisualSLAM'
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
void helperMonoVisualSLAM(helperMonoVisualSLAMStackData *SD,
                          const emlrtStack *sp, const uint8_T image[921600],
                          emxArray_real_T *xyzPoint, real_T camPoses[16]);

void helperMonoVisualSLAM_delete(void);

void helperMonoVisualSLAM_free(const emlrtStack *sp);

void helperMonoVisualSLAM_init(const emlrtStack *sp);

/* End of code generation (helperMonoVisualSLAM.h) */
