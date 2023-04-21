/*
 * File: HouseKeeping.c
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

#include "HouseKeeping.h"
#include "HouseKeeping_private.h"

/* Exported block parameters */
ProtectionParameter AnalogParameter_Protection[18] = { {
    84U,
    430.0F,
    1.0F,
    410.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    370.0F,
    1.0F,
    0.0F,
    0.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    460.0F,
    0.01F,
    420.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    235.0F,
    0.1F,
    0.0F,
    0.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    24.0F,
    0.1F,
    22.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    24.0F,
    0.1F,
    22.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    390.0F,
    0.01F,
    370.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    84U,
    390.0F,
    0.1F,
    370.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    275.0F,
    0.01F,
    265.0F,
    0.1F,
    0U,
    3U,
    1.0F,
    84U,
    80.0F,
    0.1F,
    90.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    67.0F,
    0.1F,
    65.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    84U,
    43.0F,
    0.1F,
    45.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    18.0F,
    0.1F,
    16.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    9.0F,
    0.1F,
    0.0F,
    0.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    80.0F,
    3.0F,
    70.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    84U,
    80.0F,
    3.0F,
    70.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    110.0F,
    3.0F,
    90.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    84U,
    80.0F,
    3.0F,
    70.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    110.0F,
    3.0F,
    90.0F,
    1.0F,
    0U,
    3U,
    1.0F,
    84U,
    80.0F,
    3.0F,
    70.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    20.0F,
    0.01F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    20.0F,
    3.0F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    20.0F,
    0.01F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    20.0F,
    3.0F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    20.0F,
    0.01F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    20.0F,
    3.0F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    20.0F,
    0.01F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    20.0F,
    3.0F,
    10.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    0.9F,
    0.01F,
    0.1F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    -1.0F,
    0.01F,
    -1.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    0.9F,
    0.01F,
    0.1F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    -1.0F,
    0.01F,
    -1.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    0.9F,
    0.01F,
    0.1F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    -1.0F,
    0.01F,
    -1.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  }, { 84U,
    0.9F,
    0.01F,
    0.1F,
    1.0F,
    84U,
    3U,
    1.0F,
    84U,
    -1.0F,
    0.01F,
    -1.0F,
    1.0F,
    84U,
    3U,
    1.0F,
    0.01F
  } } ;                                /* Variable: AnalogParameter_Protection
                                        * Referenced by: '<S1>/Ref_ProtectionHandler'
                                        */

/* model data */
RT_MODEL_ProtectionHandler_T Ref_ProtectionHandler;

/* model data */
RT_MODEL_StateMachine_T Ref_StateMachine;

/* Block signals (default storage) */
B_HouseKeeping_T HouseKeeping_B;

/* External inputs (root inport signals with default storage) */
ExtU_HouseKeeping_T HouseKeeping_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_HouseKeeping_T HouseKeeping_Y;

/* Model step function */
void PowerDeratingTrigger(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/PowerDeratingTrigger' */

  /* ModelReference: '<S1>/Ref_ProtectionHandler' incorporates:
   *  Inport: '<Root>/EVSE_Imax'
   *  Inport: '<Root>/PhyValueOut_LLC'
   *  Inport: '<Root>/PhyValueOut_Other'
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  Inport: '<Root>/blCAN_LOSS'
   *  Inport: '<Root>/blCali_Conf_Err'
   *  Inport: '<Root>/blFault_CMPSS'
   *  Inport: '<Root>/blHV_OVP_HW'
   *  Inport: '<Root>/blHV_SCP_HW'
   *  Inport: '<Root>/blLLC_OCP_HW'
   *  Inport: '<Root>/blPFC_OVP_HW'
   *  Inport: '<Root>/blPowerDeratingEn'
   *  Inport: '<Root>/flCoolantTemp'
   *  Inport: '<Root>/flDCCurr'
   *  Inport: '<Root>/flOBCCurrCmd'
   *  Inport: '<Root>/flOBCVoltCmd'
   *  Outport: '<Root>/OBCProtectionMsg'
   *  Outport: '<Root>/flLLCCurrCmd'
   *  Outport: '<Root>/flLLCVoltCmd'
   */
  Protection_PowerDeratingTrigger(&Ref_ProtectionHandler,
    &HouseKeeping_U.PhyValueOut_PFC_lers, &HouseKeeping_U.PhyValueOut_LLC_odl4,
    &HouseKeeping_U.flOBCVoltCmd, &HouseKeeping_U.flOBCCurrCmd,
    &HouseKeeping_U.flDCCurr, &HouseKeeping_U.flCoolantTemp,
    &HouseKeeping_U.EVSE_Imax, &HouseKeeping_U.blPowerDeratingEn,
    &HouseKeeping_Y.flLLCVoltCmd, &HouseKeeping_Y.flLLCCurrCmd);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PowerDeratingTrigger' */
}

/* Model step function */
void ProtectionTrigger(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' */

  /* ModelReference: '<S1>/Ref_ProtectionHandler' incorporates:
   *  Inport: '<Root>/EVSE_Imax'
   *  Inport: '<Root>/PhyValueOut_LLC'
   *  Inport: '<Root>/PhyValueOut_Other'
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  Inport: '<Root>/blCAN_LOSS'
   *  Inport: '<Root>/blCali_Conf_Err'
   *  Inport: '<Root>/blFault_CMPSS'
   *  Inport: '<Root>/blHV_OVP_HW'
   *  Inport: '<Root>/blHV_SCP_HW'
   *  Inport: '<Root>/blLLC_OCP_HW'
   *  Inport: '<Root>/blPFC_OVP_HW'
   *  Inport: '<Root>/blPowerDeratingEn'
   *  Inport: '<Root>/flCoolantTemp'
   *  Inport: '<Root>/flDCCurr'
   *  Inport: '<Root>/flOBCCurrCmd'
   *  Inport: '<Root>/flOBCVoltCmd'
   *  Outport: '<Root>/OBCProtectionMsg'
   *  Outport: '<Root>/flLLCCurrCmd'
   *  Outport: '<Root>/flLLCVoltCmd'
   */
  ProtectionHan_ProtectionTrigger(&Ref_ProtectionHandler,
    &HouseKeeping_U.PhyValueOut_PFC_lers, &HouseKeeping_U.PhyValueOut_LLC_odl4,
    &HouseKeeping_U.PhyValueOut_Other_pji3, &HouseKeeping_U.blHV_OVP_HW,
    &HouseKeeping_U.blHV_SCP_HW, &HouseKeeping_U.blLLC_OCP_HW,
    &HouseKeeping_U.blPFC_OVP_HW, &HouseKeeping_U.blFault_CMPSS,
    &HouseKeeping_U.blCAN_LOSS, &HouseKeeping_U.blCali_Conf_Err,
    &HouseKeeping_B.blTemporaryFault, &HouseKeeping_B.blCriticalFault,
    &HouseKeeping_Y.OBCProtectionMsg_nja1);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' */
}

/* Model step function */
void SMTrigger(void)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */

  /* ModelReference: '<S1>/Ref_StateMachine' incorporates:
   *  Inport: '<Root>/blSleepCommand'
   *  Inport: '<Root>/wDiagnosisStatus'
   *  Inport: '<Root>/wDischargeStatus'
   *  Inport: '<Root>/wPrechargeStatus'
   *  Inport: '<Root>/wVCURequest'
   *  Outport: '<Root>/blCANCommunication'
   *  Outport: '<Root>/blProtectionSWEnable'
   *  Outport: '<Root>/blReqCtrlOn'
   *  Outport: '<Root>/blReqDiagnosis'
   *  Outport: '<Root>/blReqSleep'
   *  Outport: '<Root>/wOBCState'
   */
  StateMachine_SMTrigger(&Ref_StateMachine, &HouseKeeping_U.wDiagnosisStatus,
    &HouseKeeping_U.wPrechargeStatus, &HouseKeeping_U.wDischargeStatus,
    &HouseKeeping_U.wVCURequest, &HouseKeeping_B.blTemporaryFault,
    &HouseKeeping_B.blCriticalFault, &HouseKeeping_U.blSleepCommand,
    &HouseKeeping_Y.blReqCtrlOn, &HouseKeeping_Y.blReqDiagnosis,
    &HouseKeeping_Y.wOBCState, &HouseKeeping_Y.blProtectionSWEnable,
    &HouseKeeping_Y.blReqSleep, &HouseKeeping_Y.blCANCommunication);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SMTrigger' */
}

/* Model initialize function */
void HouseKeeping_initialize(void)
{
  /* SystemInitialize for ModelReference: '<S1>/Ref_ProtectionHandler' incorporates:
   *  Inport: '<Root>/EVSE_Imax'
   *  Inport: '<Root>/PhyValueOut_LLC'
   *  Inport: '<Root>/PhyValueOut_Other'
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  Inport: '<Root>/blCAN_LOSS'
   *  Inport: '<Root>/blCali_Conf_Err'
   *  Inport: '<Root>/blFault_CMPSS'
   *  Inport: '<Root>/blHV_OVP_HW'
   *  Inport: '<Root>/blHV_SCP_HW'
   *  Inport: '<Root>/blLLC_OCP_HW'
   *  Inport: '<Root>/blPFC_OVP_HW'
   *  Inport: '<Root>/blPowerDeratingEn'
   *  Inport: '<Root>/flCoolantTemp'
   *  Inport: '<Root>/flDCCurr'
   *  Inport: '<Root>/flOBCCurrCmd'
   *  Inport: '<Root>/flOBCVoltCmd'
   *  Outport: '<Root>/OBCProtectionMsg'
   *  Outport: '<Root>/flLLCCurrCmd'
   *  Outport: '<Root>/flLLCVoltCmd'
   */
  ProtectionHandler_Init(&Ref_ProtectionHandler,
    &HouseKeeping_U.PhyValueOut_PFC_lers, &HouseKeeping_U.PhyValueOut_LLC_odl4,
    &HouseKeeping_U.flOBCVoltCmd, &HouseKeeping_U.flOBCCurrCmd,
    &HouseKeeping_U.flDCCurr, &HouseKeeping_U.flCoolantTemp,
    &HouseKeeping_U.EVSE_Imax, &HouseKeeping_U.blPowerDeratingEn,
    &HouseKeeping_Y.flLLCVoltCmd, &HouseKeeping_Y.flLLCCurrCmd,
    &HouseKeeping_Y.OBCProtectionMsg_nja1);

  /* SystemInitialize for ModelReference: '<S1>/Ref_StateMachine' incorporates:
   *  Inport: '<Root>/blSleepCommand'
   *  Inport: '<Root>/wDiagnosisStatus'
   *  Inport: '<Root>/wDischargeStatus'
   *  Inport: '<Root>/wPrechargeStatus'
   *  Inport: '<Root>/wVCURequest'
   *  Outport: '<Root>/blCANCommunication'
   *  Outport: '<Root>/blProtectionSWEnable'
   *  Outport: '<Root>/blReqCtrlOn'
   *  Outport: '<Root>/blReqDiagnosis'
   *  Outport: '<Root>/blReqSleep'
   *  Outport: '<Root>/wOBCState'
   */
  StateMachine_Init(&Ref_StateMachine, &HouseKeeping_Y.blReqCtrlOn,
                    &HouseKeeping_Y.blReqDiagnosis, &HouseKeeping_Y.wOBCState,
                    &HouseKeeping_Y.blProtectionSWEnable,
                    &HouseKeeping_Y.blReqSleep,
                    &HouseKeeping_Y.blCANCommunication);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
