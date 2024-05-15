/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkTransformationMatrixCondition.h
 *
 * Code generation for function 'checkTransformationMatrixCondition'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
boolean_T isBadlyConditioned(const emlrtStack *sp, const real_T A[9]);

/* End of code generation (checkTransformationMatrixCondition.h) */
