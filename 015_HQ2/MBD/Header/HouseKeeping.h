/*
 * File: HouseKeeping.h
 *
 * Code generated for Simulink model 'HouseKeeping'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jun 23 09:11:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HouseKeeping_h_
#define RTW_HEADER_HouseKeeping_h_
#ifndef HouseKeeping_COMMON_INCLUDES_
# define HouseKeeping_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* HouseKeeping_COMMON_INCLUDES_ */

#include "HouseKeeping_types.h"

/* Child system includes */
#include "ProtectionHandler.h"
#include "StateMachine.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  boolean_T blTemporaryFault;          /* '<S1>/Ref_ProtectionHandler' */
  boolean_T blCriticalFault;           /* '<S1>/Ref_ProtectionHandler' */
} B_HouseKeeping_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  PhyValueOut_PFC PhyValueOut_PFC_lers;/* '<Root>/PhyValueOut_PFC' */
  PhyValueOut_LLC PhyValueOut_LLC_odl4;/* '<Root>/PhyValueOut_LLC' */
  PhyValueOut_Other PhyValueOut_Other_pji3;/* '<Root>/PhyValueOut_Other' */
  real32_T flOBCVoltCmd;               /* '<Root>/flOBCVoltCmd' */
  real32_T flOBCCurrCmd;               /* '<Root>/flOBCCurrCmd' */
  real32_T flDCCurr;                   /* '<Root>/flDCCurr' */
  real32_T flCoolantTemp;              /* '<Root>/flCoolantTemp' */
  real32_T EVSE_Imax;                  /* '<Root>/EVSE_Imax' */
  boolean_T blPowerDeratingEn;         /* '<Root>/blPowerDeratingEn' */
  boolean_T blHV_OVP_HW;               /* '<Root>/blHV_OVP_HW' */
  boolean_T blHV_SCP_HW;               /* '<Root>/blHV_SCP_HW' */
  boolean_T blLLC_OCP_HW;              /* '<Root>/blLLC_OCP_HW' */
  boolean_T blPFC_OVP_HW;              /* '<Root>/blPFC_OVP_HW' */
  boolean_T blFault_CMPSS;             /* '<Root>/blFault_CMPSS' */
  boolean_T blCAN_LOSS;                /* '<Root>/blCAN_LOSS' */
  boolean_T blCali_Conf_Err;           /* '<Root>/blCali_Conf_Err' */
  uint16_T wDiagnosisStatus;           /* '<Root>/wDiagnosisStatus' */
  uint16_T wPrechargeStatus;           /* '<Root>/wPrechargeStatus' */
  uint16_T wDischargeStatus;           /* '<Root>/wDischargeStatus' */
  uint16_T wVCURequest;                /* '<Root>/wVCURequest' */
  boolean_T blSleepCommand;            /* '<Root>/blSleepCommand' */
} ExtU_HouseKeeping_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T blReqCtrlOn;                /* '<Root>/blReqCtrlOn' */
  uint16_T blReqDiagnosis;             /* '<Root>/blReqDiagnosis' */
  uint16_T wOBCState;                  /* '<Root>/wOBCState' */
  boolean_T blProtectionSWEnable;      /* '<Root>/blProtectionSWEnable' */
  uint16_T blReqSleep;                 /* '<Root>/blReqSleep' */
  uint16_T blCANCommunication;         /* '<Root>/blCANCommunication' */
  real32_T flLLCVoltCmd;               /* '<Root>/flLLCVoltCmd' */
  real32_T flLLCCurrCmd;               /* '<Root>/flLLCCurrCmd' */
  OBCProtectionMsg OBCProtectionMsg_nja1;/* '<Root>/OBCProtectionMsg' */
} ExtY_HouseKeeping_T;

/* model data */
extern RT_MODEL_ProtectionHandler_T Ref_ProtectionHandler;

/* model data */
extern RT_MODEL_StateMachine_T Ref_StateMachine;

/* Block signals (default storage) */
extern B_HouseKeeping_T HouseKeeping_B;

/* External inputs (root inport signals with default storage) */
extern ExtU_HouseKeeping_T HouseKeeping_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_HouseKeeping_T HouseKeeping_Y;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern ProtectionParameter AnalogParameter_Protection[18];/* Variable: AnalogParameter_Protection
                                                           * Referenced by: '<S1>/Ref_ProtectionHandler'
                                                           */

/* Model entry point functions */
extern void HouseKeeping_initialize(void);

/* Exported entry point function */
extern void PowerDeratingTrigger(void);

/* Exported entry point function */
extern void ProtectionTrigger(void);

/* Exported entry point function */
extern void SMTrigger(void);

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
 * '<Root>' : 'HouseKeeping'
 * '<S1>'   : 'HouseKeeping/HouseKeeping'
 */

/*-
 * Requirements for '<Root>': HouseKeeping
 */
#endif                                 /* RTW_HEADER_HouseKeeping_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
