/*
 * File: BINARYSEARCH_S16.c
 *
 * Code generated for Simulink model 'ValueConvert'.
 *
 * Model version                  : 1.187
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Feb 15 11:39:34 2022
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_S16.h"

/* Lookup Binary Search Utility BINARYSEARCH_S16 */
void BINARYSEARCH_S16(uint16_T *piLeft, uint16_T *piRght, int16_T u, const
                      int16_T *pData, uint16_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint16_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
