/*
 * File: uMultiWordGe.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "uMultiWordCmp.h"
#include "uMultiWordGe.h"

boolean_T uMultiWordGe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return uMultiWordCmp(u1, u2, n) >= 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
