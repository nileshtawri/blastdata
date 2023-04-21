/*
 * File: rt_modf.c
 *
 * Code generated for Simulink model 'ValueConvert'.
 *
 * Model version                  : 1.172
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Dec  8 17:23:29 2021
 */

#include "rtwtypes.h"
#include <float.h>
#include <math.h>
#include "rt_modf.h"

real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T y;
  boolean_T yEq;
  real32_T q;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      q = fabsf(u0 / u1);
      yEq = (fabsf(q - floorf(q + 0.5F)) <= (FLT_EPSILON * q));
    }

    if (yEq) {
      y = 0.0F;
    } else {
      if ((u0 < 0.0F) != (u1 < 0.0F)) {
        y += u1;
      }
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
