/*
 * File: Protection_types.h
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.80
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jun 23 09:10:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Protection_types_h_
#define RTW_HEADER_Protection_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_ProtectionParameter_
#define DEFINED_TYPEDEF_FOR_ProtectionParameter_

typedef struct {
  uint16_T TripEnable_Up;
  real32_T TripPoint_Up;
  real32_T TripTime_Up;
  real32_T RecoverPoint_Up;
  real32_T RecoverTime_Up;
  uint16_T RetryEnable_Up;
  uint16_T RetryLimit_Up;
  real32_T RetryTime_Up;
  uint16_T TripEnable_Low;
  real32_T TripPoint_Low;
  real32_T TripTime_Low;
  real32_T RecoverPoint_Low;
  real32_T RecoverTime_Low;
  uint16_T RetryEnable_Low;
  uint16_T RetryLimit_Low;
  real32_T RetryTime_Low;
  real32_T SampleTime;
} ProtectionParameter;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ProtectionMessage_
#define DEFINED_TYPEDEF_FOR_ProtectionMessage_

typedef struct {
  boolean_T Temp_Error_Up;
  boolean_T Error_Up;
  uint16_T Retry_Count_Up;
  real32_T FaultValue_Up;
  boolean_T Temp_Error_Low;
  boolean_T Error_Low;
  uint16_T Retry_Count_Low;
  real32_T FaultValue_Low;
} ProtectionMessage;

#endif
#endif                                 /* RTW_HEADER_Protection_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
