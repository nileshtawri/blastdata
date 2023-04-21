/*
 * File: PowerDerating_types.h
 *
 * Code generated for Simulink model 'PowerDerating'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jun  6 15:44:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PowerDerating_types_h_
#define RTW_HEADER_PowerDerating_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_LLC_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_LLC_

typedef struct {
  real32_T LLCVolt;
  real32_T LLCCurr;
} PhyValueOut_LLC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_PFC_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_PFC_

typedef struct {
  real32_T GridVoltTheta;
  real32_T GridVoltFreq;
  real32_T GridVoltRms;
  real32_T GridVolt;
  real32_T GridVoltRect;
  real32_T PFCVolt;
  real32_T PFCIswA;
  real32_T PFCIswB;
  real32_T PFCIswC;
  real32_T PFCIswD;
} PhyValueOut_PFC;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_PowerDerating_T RT_MODEL_PowerDerating_T;

#endif                                 /* RTW_HEADER_PowerDerating_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
