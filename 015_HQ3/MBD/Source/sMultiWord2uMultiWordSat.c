/*
 * File: sMultiWord2uMultiWordSat.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2uMultiWordSat.h"

void sMultiWord2uMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T y[],
  int16_T n)
{
  uint32_T ys;
  int16_T n1m1;
  boolean_T doSaturation;
  int16_T nc;
  n1m1 = n1 - 1;
  ys = ((u1[n1m1] & 2147483648UL) != 0UL) ? MAX_uint32_T : 0UL;
  doSaturation = (ys != 0UL);
  while ((!doSaturation) && (n1m1 >= n)) {
    doSaturation = (u1[n1m1] != 0UL);
    n1m1--;
  }

  if (doSaturation) {
    ys = ~ys;
    for (n1m1 = 0; n1m1 < n; n1m1++) {
      y[n1m1] = ys;
    }
  } else {
    nc = (n1 < n) ? n1 : n;
    for (n1m1 = 0; n1m1 < nc; n1m1++) {
      y[n1m1] = u1[n1m1];
    }

    while (n1m1 < n) {
      y[n1m1] = ys;
      n1m1++;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
