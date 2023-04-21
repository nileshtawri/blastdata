/*
 * File: Control_SM_test_types.h
 *
 * Code generated for Simulink model 'Control_SM_test'.
 *
 * Model version                  : 1.122
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu May 26 11:24:56 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Control_SM_test_types_h_
#define RTW_HEADER_Control_SM_test_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
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
#endif                                 /* RTW_HEADER_Control_SM_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
