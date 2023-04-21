/*
 * File: sMultiWordShl.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Feb 10 19:03:37 2022
 */

#include "rtwtypes.h"
#include "sMultiWordShl.h"

void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  int16_T nb;
  int16_T nc;
  int16_T i;
  uint32_T ys;
  uint32_T u1i;
  uint32_T yi;
  uint16_T nr;
  uint16_T nl;
  nb = (int16_T)((uint16_T)(n2 >> 5UL));
  ys = ((u1[n1 - 1] & 2147483648UL) != 0UL) ? MAX_uint32_T : 0UL;
  nc = (nb > n) ? n : nb;
  u1i = 0UL;
  for (i = 0; i < nc; i++) {
    y[i] = 0UL;
  }

  if (nb < n) {
    nl = n2 - (((uint16_T)nb) << 5UL);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc < nb; nc++) {
        yi = (u1i >> ((uint32_T)nr));
        u1i = u1[nc];
        y[i] = (u1i << ((uint32_T)nl)) | yi;
        i++;
      }

      if (i < n) {
        y[i] = (u1i >> ((uint32_T)nr)) | (ys << ((uint32_T)nl));
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
