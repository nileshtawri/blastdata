/*
 * File: ProtectionHandler_types.h
 *
 * Code generated for Simulink model 'ProtectionHandler'.
 *
 * Model version                  : 1.345
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jun 23 09:11:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ProtectionHandler_types_h_
#define RTW_HEADER_ProtectionHandler_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_LLC_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_LLC_

typedef struct {
  real32_T LLCVolt;
  real32_T LLCCurr;
} PhyValueOut_LLC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_Other_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_Other_

typedef struct {
  real32_T PFCIswA_RMS;
  real32_T PFCIswB_RMS;
  real32_T PFCIswC_RMS;
  real32_T PFCIswD_RMS;
  real32_T PFCAux;
  real32_T OBCTemp3;
  real32_T OBCTemp2;
  real32_T OBCTemp1;
} PhyValueOut_Other;

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

#ifndef DEFINED_TYPEDEF_FOR_OBCProtectionMsg_
#define DEFINED_TYPEDEF_FOR_OBCProtectionMsg_

typedef struct {
  ProtectionMessage PFCVolt;
  ProtectionMessage LLCVolt;
  ProtectionMessage LLCCurr;
  ProtectionMessage GridVolt;
  ProtectionMessage GridVoltRms;
  ProtectionMessage GridVoltFreq;
  ProtectionMessage PFCAux;
  ProtectionMessage OBCTemp1;
  ProtectionMessage OBCTemp2;
  ProtectionMessage OBCTemp3;
  ProtectionMessage PFCIswA;
  ProtectionMessage PFCIswB;
  ProtectionMessage PFCIswC;
  ProtectionMessage PFCIswD;
  ProtectionMessage HV_OVP_HW;
  ProtectionMessage HV_SCP_HW;
  ProtectionMessage LLC_OCP_HW;
  ProtectionMessage PFC_OVP_HW;
} OBCProtectionMsg;

#endif

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

/* Forward declaration for rtModel */
typedef struct tag_RTM_ProtectionHandler_T RT_MODEL_ProtectionHandler_T;

#endif                               /* RTW_HEADER_ProtectionHandler_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
