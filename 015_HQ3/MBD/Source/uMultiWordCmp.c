/*
 * File: uMultiWordCmp.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "uMultiWordCmp.h"

int16_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  int16_T y;
  uint32_T u1i;
  uint32_T u2i;
  int16_T i;
  y = 0;
  i = n;
  while ((y == 0) && (i > 0)) {
    i--;
    u1i = u1[i];
    u2i = u2[i];
    if (u1i != u2i) {
      y = (u1i > u2i) ? 1 : -1;
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
