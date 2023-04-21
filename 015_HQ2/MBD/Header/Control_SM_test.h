/*
 * File: Control_SM_test.h
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

#ifndef RTW_HEADER_Control_SM_test_h_
#define RTW_HEADER_Control_SM_test_h_
#ifndef Control_SM_test_COMMON_INCLUDES_
# define Control_SM_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Control_SM_test_COMMON_INCLUDES_ */

#include "Control_SM_test_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  boolean_T Relay_On;                  /* '<S2>/Chart' */
} B_Control_SM_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  real32_T flCurrSoft;                 /* '<S3>/Control_state_machine' */
  real32_T flVoltSoft;                 /* '<S3>/Control_state_machine' */
  real32_T PFC_Vsoft;                  /* '<S3>/Control_state_machine' */
  real32_T PFC_Dutysoft;               /* '<S3>/Control_state_machine' */
  real32_T PFC_Vm;                     /* '<S2>/Chart' */
  uint32_T temporalCounter_i2;         /* '<S3>/Control_state_machine' */
  uint16_T temporalCounter_i1;         /* '<S3>/Control_state_machine' */
  uint16_T is_active_c3_Control_SM_test;/* '<S3>/Control_state_machine' */
  uint16_T is_c3_Control_SM_test;      /* '<S3>/Control_state_machine' */
  uint16_T is_Run;                     /* '<S3>/Control_state_machine' */
  uint16_T is_PFC_pre_charge;          /* '<S3>/Control_state_machine' */
  uint16_T is_active_c1_Control_SM_test;/* '<S2>/Chart' */
  uint16_T is_c1_Control_SM_test;      /* '<S2>/Chart' */
} DW_Control_SM_test_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Sum2;                 /* '<S2>/Sum2' */
  const uint16_T Sum3;                 /* '<S2>/Sum3' */
} ConstB_Control_SM_test_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T blReqCtrlOn;               /* '<Root>/blReqCtrlOn' */
  real32_T flLLCVoltCmd;               /* '<Root>/flLLCVoltCmd' */
  real32_T flLLCCurrCmd;               /* '<Root>/flLLCCurrCmd' */
  PhyValueOut_PFC PhyValueOut_PFC_nm4g;/* '<Root>/PhyValueOut_PFC' */
} ExtU_Control_SM_test_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T PFC_Vcmd_Out;               /* '<Root>/PFC_Vcmd_Out' */
  boolean_T PFC_Reset;                 /* '<Root>/PFC_Reset' */
  real32_T PFC_Isw_cmd_Init;           /* '<Root>/PFC_Isw_cmd_Init' */
  real32_T PFC_Duty_Init;              /* '<Root>/PFC_Duty_Init' */
  real32_T flLLCVoltRef;               /* '<Root>/flLLCVoltRef' */
  boolean_T LLC_Reset;                 /* '<Root>/LLC_Reset' */
  real32_T flLLCCurrRef;               /* '<Root>/flLLCCurrRef' */
  boolean_T PFC_PWM_On;                /* '<Root>/PFC_PWM_On' */
  boolean_T LLC_PWM_On;                /* '<Root>/LLC_PWM_On' */
  real32_T Relay_PWM_CMPB;             /* '<Root>/Relay_PWM_CMPB' */
  uint16_T wLLCMinDuty;                /* '<Root>/wLLCMinDuty' */
  real32_T PFC_Duty_Out;               /* '<Root>/PFC_Duty_Out' */
} ExtY_Control_SM_test_T;

/* Block signals (default storage) */
extern B_Control_SM_test_T Control_SM_test_B;

/* Block states (default storage) */
extern DW_Control_SM_test_T Control_SM_test_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Control_SM_test_T Control_SM_test_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Control_SM_test_T Control_SM_test_Y;
extern const ConstB_Control_SM_test_T Control_SM_test_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Control_SM_test_initialize(void);
extern void Control_SM_test_step(void);

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
 * '<Root>' : 'Control_SM_test'
 * '<S1>'   : 'Control_SM_test/Control_SM'
 * '<S2>'   : 'Control_SM_test/Control_SM/Ctrl_fault'
 * '<S3>'   : 'Control_SM_test/Control_SM/Mode_switch'
 * '<S4>'   : 'Control_SM_test/Control_SM/Ctrl_fault/Chart'
 * '<S5>'   : 'Control_SM_test/Control_SM/Mode_switch/Control_state_machine'
 */

/*-
 * Requirements for '<Root>': Control_SM_test
 */
#endif                                 /* RTW_HEADER_Control_SM_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
