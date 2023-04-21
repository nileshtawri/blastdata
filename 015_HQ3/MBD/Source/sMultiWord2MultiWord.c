/*
 * File: sMultiWord2MultiWord.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2MultiWord.h"

void sMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T
  n)
{
  uint32_T u1i;
  int16_T nm;
  int16_T i;
  nm = (n1 < n) ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = ((u1[n1 - 1] & 2147483648UL) != 0UL) ? MAX_uint32_T : 0UL;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
