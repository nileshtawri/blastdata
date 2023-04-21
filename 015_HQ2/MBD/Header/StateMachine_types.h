/*
 * File: StateMachine_types.h
 *
 * Code generated for Simulink model 'StateMachine'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jun  6 15:40:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_StateMachine_types_h_
#define RTW_HEADER_StateMachine_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_BTEbbx8mldcfM0dClFx9zC_
#define DEFINED_TYPEDEF_FOR_struct_BTEbbx8mldcfM0dClFx9zC_

typedef struct {
  uint16_T wDiagnosisStatus;
  uint16_T wPrechargeStatus;
  boolean_T T3;
  boolean_T T4;
  boolean_T blAllFault;
  boolean_T blCriticalFault;
  uint16_T wVCURequest;
  boolean_T blSleepCommand;
  boolean_T T9;
} struct_BTEbbx8mldcfM0dClFx9zC;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_StateMachine_T RT_MODEL_StateMachine_T;

#endif                                 /* RTW_HEADER_StateMachine_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
