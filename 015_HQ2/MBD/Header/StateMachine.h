/*
 * File: StateMachine.h
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

#ifndef RTW_HEADER_StateMachine_h_
#define RTW_HEADER_StateMachine_h_
#ifndef StateMachine_COMMON_INCLUDES_
# define StateMachine_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StateMachine_COMMON_INCLUDES_ */

#include "StateMachine_types.h"

/* Block signals for model 'StateMachine' */
typedef struct {
  uint16_T wDiagnosisStatus;
                   /* '<S2>/BusConversion_InsertedFor_Transition_at_inport_0' */
  uint16_T wPrechargeStatus;
                   /* '<S2>/BusConversion_InsertedFor_Transition_at_inport_0' */
  uint16_T wVCURequest;
                   /* '<S2>/BusConversion_InsertedFor_Transition_at_inport_0' */
  boolean_T T3;                        /* '<S2>/AND' */
  boolean_T T4;                        /* '<S2>/AND1' */
  boolean_T blCriticalFault;           /* '<S2>/OR1' */
  boolean_T blAllFault;                /* '<S2>/OR' */
  boolean_T T9;                        /* '<S2>/AND4' */
  boolean_T blSleepCommand;
                   /* '<S2>/BusConversion_InsertedFor_Transition_at_inport_0' */
} B_StateMachine_caua_T;

/* Block states (default storage) for model 'StateMachine' */
typedef struct {
  uint16_T is_active_c3_StateMachine;  /* '<S3>/Chart' */
  uint16_T is_c3_StateMachine;         /* '<S3>/Chart' */
  uint16_T is_Start;                   /* '<S3>/Chart' */
  uint16_T is_Failure_mode;            /* '<S3>/Chart' */
  uint16_T is_Off_mode;                /* '<S3>/Chart' */
  uint16_T is_On_mode;                 /* '<S3>/Chart' */
} DW_StateMachine_fwu4_T;

/* Self model data, for model 'StateMachine' */
struct tag_RTM_StateMachine_T {
  DW_StateMachine_fwu4_T dwork;
  B_StateMachine_caua_T blockIO;
};

extern void StateMachine_Init(RT_MODEL_StateMachine_T * const StateMachine_M,
  uint16_T *rty_blReqCtrlOn, uint16_T *rty_blReqDiagnosis, uint16_T
  *rty_wOBCState, boolean_T *rty_blProtectionSWEnable, uint16_T *rty_blReqSleep,
  uint16_T *rty_blCANCommunication);
extern void StateMachine_SMTrigger(RT_MODEL_StateMachine_T * const
  StateMachine_M, const uint16_T *rtu_wDiagnosisStatus, const uint16_T
  *rtu_wPrechargeStatus, const uint16_T *rtu_wDischargeStatus, const uint16_T
  *rtu_wVCURequest, const boolean_T *rtu_blTemporaryFault, const boolean_T
  *rtu_blCriticalFault, const boolean_T *rtu_blSleepCommand, uint16_T
  *rty_blReqCtrlOn, uint16_T *rty_blReqDiagnosis, uint16_T *rty_wOBCState,
  boolean_T *rty_blProtectionSWEnable, uint16_T *rty_blReqSleep, uint16_T
  *rty_blCANCommunication);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'StateMachine'
 * '<S1>'   : 'StateMachine/Subsystem1'
 * '<S2>'   : 'StateMachine/Subsystem1/Signal'
 * '<S3>'   : 'StateMachine/Subsystem1/StateMachine'
 * '<S4>'   : 'StateMachine/Subsystem1/Signal/Compare To Constant'
 * '<S5>'   : 'StateMachine/Subsystem1/Signal/Compare To Constant1'
 * '<S6>'   : 'StateMachine/Subsystem1/Signal/Compare To Constant2'
 * '<S7>'   : 'StateMachine/Subsystem1/Signal/Compare To Constant3'
 * '<S8>'   : 'StateMachine/Subsystem1/Signal/Compare To Constant4'
 * '<S9>'   : 'StateMachine/Subsystem1/Signal/Compare To Constant5'
 * '<S10>'  : 'StateMachine/Subsystem1/StateMachine/Chart'
 */

/*-
 * Requirements for '<Root>': StateMachine
 */
#endif                                 /* RTW_HEADER_StateMachine_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
