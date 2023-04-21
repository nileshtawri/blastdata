/*
 * File: MultiWordSignedWrap.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "MultiWordSignedWrap.h"

void MultiWordSignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T
  y[])
{
  int16_T n1m1;
  int16_T i;
  uint32_T mask;
  uint32_T ys;
  n1m1 = n1 - 1;
  for (i = 0; i < n1m1; i++) {
    y[i] = u1[i];
  }

  mask = (1UL << ((uint32_T)((uint16_T)(31U - n2))));
  ys = ((u1[n1m1] & mask) != 0UL) ? MAX_uint32_T : 0UL;
  mask = (mask << 1UL) - 1UL;
  y[n1m1] = (u1[n1m1] & mask) | ((~mask) & ys);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
