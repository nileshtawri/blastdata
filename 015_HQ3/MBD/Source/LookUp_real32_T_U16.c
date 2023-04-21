/*
 * File: LookUp_real32_T_U16.c
 *
 * Code generated for Simulink model 'ValueConvert'.
 *
 * Model version                  : 1.176
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Dec 27 17:18:20 2021
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_U16.h"
#include "LookUp_real32_T_U16.h"

/* Lookup Utility LookUp_real32_T_U16 */
void LookUp_real32_T_U16(real32_T *pY, const real32_T *pYData, uint16_T u, const
  uint16_T *pUData, uint16_T iHi)
{
  uint16_T iLeft;
  uint16_T iRght;
  BINARYSEARCH_U16( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      uint16_T num;
      uint16_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = ((real_T)num) / ((real_T)den);
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = (real_T)pYData[iLeft];
      yRghtCast = (real_T)pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = (real32_T)yLeftCast;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
