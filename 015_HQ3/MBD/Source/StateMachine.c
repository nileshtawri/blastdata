/*
 * File: StateMachine.c
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

#include "StateMachine.h"
#include "StateMachine_private.h"
#define StateMachine_IN_Critical_fault (1U)
#define StateMachine_IN_Failure_mode   (1U)
#define StateMachine_IN_Idle_mode      (1U)
#define StateMachine_IN_LowPower_mode  (1U)
#define StateMachine_IN_NO_ACTIVE_CHILD (0U)
#define StateMachine_IN_Off_mode       (2U)
#define StateMachine_IN_On_mode        (3U)
#define StateMachine_IN_Run_mode       (1U)
#define StateMachine_IN_Sleep_mode     (2U)
#define StateMachine_IN_Standby_mode   (2U)
#define StateMachine_IN_Start          (4U)
#define StateMachine_IN_Start_mode     (2U)
#define StateMachine_IN_Temporary_fault (2U)
#define StateMachine_IN_WakeUp_Ceck    (3U)

/* Forward declaration for local functions */
static void StateMachine_Failure_mode(uint16_T *rty_blReqCtrlOn, uint16_T
  *rty_blReqDiagnosis, uint16_T *rty_wOBCState, boolean_T
  *rty_blProtectionSWEnable, uint16_T *rty_blReqSleep, uint16_T
  *rty_blCANCommunication, B_StateMachine_caua_T *localB, DW_StateMachine_fwu4_T
  *localDW);

/* Function for Chart: '<S3>/Chart' */
static void StateMachine_Failure_mode(uint16_T *rty_blReqCtrlOn, uint16_T
  *rty_blReqDiagnosis, uint16_T *rty_wOBCState, boolean_T
  *rty_blProtectionSWEnable, uint16_T *rty_blReqSleep, uint16_T
  *rty_blCANCommunication, B_StateMachine_caua_T *localB, DW_StateMachine_fwu4_T
  *localDW)
{
  if (!localB->blAllFault) {
    localDW->is_Failure_mode = StateMachine_IN_NO_ACTIVE_CHILD;
    localDW->is_c3_StateMachine = StateMachine_IN_Start;
    localDW->is_Start = StateMachine_IN_Start_mode;

    /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
     *  SubSystem: '<S1>/StateMachine'
     */
    /* Chart: '<S3>/Chart'
     *
     * Block requirements for '<S3>/Chart':
     *  1.
     */
    *rty_blReqCtrlOn = 0U;
    *rty_blReqDiagnosis = 1U;
    *rty_wOBCState = 0U;
    *rty_blProtectionSWEnable = (boolean_T)0;
    *rty_blReqSleep = 0U;
    *rty_blCANCommunication = 1U;

    /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
  } else if (localB->T3) {
    localDW->is_Failure_mode = StateMachine_IN_NO_ACTIVE_CHILD;
    localDW->is_c3_StateMachine = StateMachine_IN_Off_mode;
    localDW->is_Off_mode = StateMachine_IN_LowPower_mode;

    /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
     *  SubSystem: '<S1>/StateMachine'
     */
    /* Chart: '<S3>/Chart'
     *
     * Block requirements for '<S3>/Chart':
     *  1.
     */
    *rty_blReqCtrlOn = 0U;
    *rty_blReqDiagnosis = 0U;
    *rty_wOBCState = 4U;
    *rty_blProtectionSWEnable = (boolean_T)0;
    *rty_blReqSleep = 0U;
    *rty_blCANCommunication = 1U;

    /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
  } else if (localDW->is_Failure_mode == 1U) {
    /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
     *  SubSystem: '<S1>/StateMachine'
     */
    /* Chart: '<S3>/Chart'
     *
     * Block requirements for '<S3>/Chart':
     *  1.
     */
    *rty_blReqCtrlOn = 0U;
    *rty_blReqDiagnosis = 0U;
    *rty_wOBCState = 6U;
    *rty_blReqSleep = 0U;
    *rty_blCANCommunication = 1U;

    /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
  } else {
    /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
     *  SubSystem: '<S1>/StateMachine'
     */
    /* Chart: '<S3>/Chart'
     *
     * Block requirements for '<S3>/Chart':
     *  1.
     */
    /* case IN_Temporary_fault: */
    *rty_blReqCtrlOn = 0U;
    *rty_blReqDiagnosis = 0U;
    *rty_wOBCState = 5U;
    *rty_blReqSleep = 0U;
    *rty_blCANCommunication = 1U;

    /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
    if (localB->blCriticalFault) {
      localDW->is_Failure_mode = StateMachine_IN_Critical_fault;

      /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
       *  SubSystem: '<S1>/StateMachine'
       */
      /* Chart: '<S3>/Chart'
       *
       * Block requirements for '<S3>/Chart':
       *  1.
       */
      *rty_blReqCtrlOn = 0U;
      *rty_blReqDiagnosis = 0U;
      *rty_wOBCState = 6U;
      *rty_blProtectionSWEnable = (boolean_T)0;
      *rty_blReqSleep = 0U;
      *rty_blCANCommunication = 1U;

      /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
    }
  }
}

/* System initialize for referenced model: 'StateMachine' */
void StateMachine_Init(RT_MODEL_StateMachine_T * const StateMachine_M, uint16_T *
  rty_blReqCtrlOn, uint16_T *rty_blReqDiagnosis, uint16_T *rty_wOBCState,
  boolean_T *rty_blProtectionSWEnable, uint16_T *rty_blReqSleep, uint16_T
  *rty_blCANCommunication)
{
  (void) (StateMachine_M);
  (void) (rty_blReqCtrlOn);
  (void) (rty_blReqDiagnosis);
  (void) (rty_wOBCState);
  (void) (rty_blProtectionSWEnable);
  (void) (rty_blReqSleep);
  (void) (rty_blCANCommunication);
}

/* Output and update for referenced model: 'StateMachine' */
void StateMachine_SMTrigger(RT_MODEL_StateMachine_T * const StateMachine_M,
  const uint16_T *rtu_wDiagnosisStatus, const uint16_T *rtu_wPrechargeStatus,
  const uint16_T *rtu_wDischargeStatus, const uint16_T *rtu_wVCURequest, const
  boolean_T *rtu_blTemporaryFault, const boolean_T *rtu_blCriticalFault, const
  boolean_T *rtu_blSleepCommand, uint16_T *rty_blReqCtrlOn, uint16_T
  *rty_blReqDiagnosis, uint16_T *rty_wOBCState, boolean_T
  *rty_blProtectionSWEnable, uint16_T *rty_blReqSleep, uint16_T
  *rty_blCANCommunication)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
   *  SubSystem: '<S1>/StateMachine'
   */
  /* Chart: '<S3>/Chart'
   *
   * Block requirements for '<S3>/Chart':
   *  1.
   */
  if (StateMachine_M->dwork.is_active_c3_StateMachine == 0U) {
    StateMachine_M->dwork.is_active_c3_StateMachine = 1U;
    StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_Start;
    StateMachine_M->dwork.is_Start = StateMachine_IN_WakeUp_Ceck;
    *rty_blReqCtrlOn = 0U;
    *rty_blReqDiagnosis = 0U;
    *rty_wOBCState = 0U;
    *rty_blProtectionSWEnable = (boolean_T)0;
    *rty_blReqSleep = 0U;
    *rty_blCANCommunication = 1U;
  } else {
    switch (StateMachine_M->dwork.is_c3_StateMachine) {
     case StateMachine_IN_Failure_mode:
      StateMachine_Failure_mode(rty_blReqCtrlOn, rty_blReqDiagnosis,
        rty_wOBCState, rty_blProtectionSWEnable, rty_blReqSleep,
        rty_blCANCommunication, &(StateMachine_M)->blockIO, &(StateMachine_M)
        ->dwork);
      break;

     case StateMachine_IN_Off_mode:
      if ((StateMachine_M->blockIO.T4) || (StateMachine_M->blockIO.wVCURequest
           != 2U)) {
        StateMachine_M->dwork.is_Off_mode = StateMachine_IN_NO_ACTIVE_CHILD;
        StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_Start;
        StateMachine_M->dwork.is_Start = StateMachine_IN_WakeUp_Ceck;
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 0U;
        *rty_blProtectionSWEnable = (boolean_T)0;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
      } else if (StateMachine_M->dwork.is_Off_mode == 1U) {
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 4U;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
        if (StateMachine_M->blockIO.blSleepCommand) {
          StateMachine_M->dwork.is_Off_mode = StateMachine_IN_Sleep_mode;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 4U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 1U;
          *rty_blCANCommunication = 1U;
        }
      } else {
        /* case IN_Sleep_mode: */
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 4U;
        *rty_blReqSleep = 1U;
        *rty_blCANCommunication = 1U;
      }
      break;

     case StateMachine_IN_On_mode:
      if (StateMachine_M->blockIO.blAllFault) {
        StateMachine_M->dwork.is_On_mode = StateMachine_IN_NO_ACTIVE_CHILD;
        StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_Failure_mode;
        StateMachine_M->dwork.is_Failure_mode = StateMachine_IN_Temporary_fault;
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 5U;
        *rty_blProtectionSWEnable = (boolean_T)0;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
      } else if (StateMachine_M->dwork.is_On_mode == 1U) {
        *rty_blReqCtrlOn = 1U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 3U;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
        if ((StateMachine_M->blockIO.wVCURequest == 0U) ||
            (StateMachine_M->blockIO.wVCURequest == 2U)) {
          StateMachine_M->dwork.is_On_mode = StateMachine_IN_Standby_mode;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 2U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
        }
      } else {
        /* case IN_Standby_mode: */
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 2U;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
        switch (StateMachine_M->blockIO.wVCURequest) {
         case 2U:
          StateMachine_M->dwork.is_On_mode = StateMachine_IN_NO_ACTIVE_CHILD;
          StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_Start;
          StateMachine_M->dwork.is_Start = StateMachine_IN_Idle_mode;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 1U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
          break;

         case 1U:
          StateMachine_M->dwork.is_On_mode = StateMachine_IN_Run_mode;
          *rty_blReqCtrlOn = 1U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 3U;
          *rty_blProtectionSWEnable = (boolean_T)1;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
          break;

         default:
          /* no actions */
          break;
        }
      }
      break;

     default:
      /* case IN_Start: */
      switch (StateMachine_M->dwork.is_Start) {
       case StateMachine_IN_Idle_mode:
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 1U;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
        if (StateMachine_M->blockIO.T3) {
          StateMachine_M->dwork.is_Start = StateMachine_IN_NO_ACTIVE_CHILD;
          StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_Off_mode;
          StateMachine_M->dwork.is_Off_mode = StateMachine_IN_LowPower_mode;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 4U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
        } else {
          if (StateMachine_M->blockIO.wPrechargeStatus == 1U) {
            StateMachine_M->dwork.is_Start = StateMachine_IN_NO_ACTIVE_CHILD;
            StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_On_mode;
            StateMachine_M->dwork.is_On_mode = StateMachine_IN_Standby_mode;
            *rty_blReqCtrlOn = 0U;
            *rty_blReqDiagnosis = 0U;
            *rty_wOBCState = 2U;
            *rty_blProtectionSWEnable = (boolean_T)0;
            *rty_blReqSleep = 0U;
            *rty_blCANCommunication = 1U;
          }
        }
        break;

       case StateMachine_IN_Start_mode:
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 1U;
        *rty_wOBCState = 0U;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
        switch (StateMachine_M->blockIO.wDiagnosisStatus) {
         case 2U:
          StateMachine_M->dwork.is_Start = StateMachine_IN_NO_ACTIVE_CHILD;
          StateMachine_M->dwork.is_c3_StateMachine =
            StateMachine_IN_Failure_mode;
          StateMachine_M->dwork.is_Failure_mode = StateMachine_IN_Critical_fault;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 6U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
          break;

         case 1U:
          StateMachine_M->dwork.is_Start = StateMachine_IN_Idle_mode;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 1U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
          break;

         default:
          /* no actions */
          break;
        }
        break;

       default:
        /* case IN_WakeUp_Ceck: */
        *rty_blReqCtrlOn = 0U;
        *rty_blReqDiagnosis = 0U;
        *rty_wOBCState = 0U;
        *rty_blReqSleep = 0U;
        *rty_blCANCommunication = 1U;
        if (StateMachine_M->blockIO.T9) {
          StateMachine_M->dwork.is_Start = StateMachine_IN_NO_ACTIVE_CHILD;
          StateMachine_M->dwork.is_c3_StateMachine = StateMachine_IN_Off_mode;
          StateMachine_M->dwork.is_Off_mode = StateMachine_IN_LowPower_mode;
          *rty_blReqCtrlOn = 0U;
          *rty_blReqDiagnosis = 0U;
          *rty_wOBCState = 4U;
          *rty_blProtectionSWEnable = (boolean_T)0;
          *rty_blReqSleep = 0U;
          *rty_blCANCommunication = 1U;
        } else {
          if (StateMachine_M->blockIO.wVCURequest != 2U) {
            StateMachine_M->dwork.is_Start = StateMachine_IN_Start_mode;
            *rty_blReqCtrlOn = 0U;
            *rty_blReqDiagnosis = 1U;
            *rty_wOBCState = 0U;
            *rty_blProtectionSWEnable = (boolean_T)0;
            *rty_blReqSleep = 0U;
            *rty_blCANCommunication = 1U;
          }
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' incorporates:
   *  SubSystem: '<S1>/Signal'
   */
  /* Logic: '<S2>/AND' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   */
  StateMachine_M->blockIO.T3 = (((*rtu_wDischargeStatus) == 1U) &&
    ((*rtu_wVCURequest) == 2U));

  /* Logic: '<S2>/AND1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  StateMachine_M->blockIO.T4 = (((*rtu_wDischargeStatus) == 1U) &&
    ((*rtu_wVCURequest) == 3U));

  /* Logic: '<S2>/OR1' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  StateMachine_M->blockIO.blCriticalFault = (((*rtu_wDiagnosisStatus) == 2U) ||
    (*rtu_blCriticalFault));

  /* Logic: '<S2>/OR' */
  StateMachine_M->blockIO.blAllFault = ((*rtu_blTemporaryFault) ||
    (StateMachine_M->blockIO.blCriticalFault));

  /* Logic: '<S2>/AND4' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  StateMachine_M->blockIO.T9 = ((*rtu_blSleepCommand) || ((*rtu_wVCURequest) ==
    2U));

  /* SignalConversion generated from: '<S2>/Transition' */
  StateMachine_M->blockIO.wDiagnosisStatus = *rtu_wDiagnosisStatus;

  /* SignalConversion generated from: '<S2>/Transition' */
  StateMachine_M->blockIO.wPrechargeStatus = *rtu_wPrechargeStatus;

  /* SignalConversion generated from: '<S2>/Transition' */
  StateMachine_M->blockIO.wVCURequest = *rtu_wVCURequest;

  /* SignalConversion generated from: '<S2>/Transition' */
  StateMachine_M->blockIO.blSleepCommand = *rtu_blSleepCommand;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
