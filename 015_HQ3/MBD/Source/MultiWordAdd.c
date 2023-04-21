/*
 * File: MultiWordAdd.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "MultiWordAdd.h"

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int16_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T carry = 0UL;
  int16_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = (carry != 0UL) ? ((uint32_T)((yi <= u1i) ? 1UL : 0UL)) : ((uint32_T)
      ((yi < u1i) ? 1UL : 0UL));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
