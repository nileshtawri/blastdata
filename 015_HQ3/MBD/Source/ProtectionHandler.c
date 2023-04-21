/*
 * File: ProtectionHandler.c
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

#include "ProtectionHandler.h"
#include "ProtectionHandler_private.h"

/* System initialize for referenced model: 'ProtectionHandler' */
void ProtectionHandler_Init(RT_MODEL_ProtectionHandler_T * const
  ProtectionHandler_M, const PhyValueOut_PFC *rtu_PhyValueOut_PFC, const
  PhyValueOut_LLC *rtu_PhyValueOut_LLC, const real32_T *rtu_flOBCVoltCmd, const
  real32_T *rtu_flOBCCurrCmd, const real32_T *rtu_flDCCurr, const real32_T
  *rtu_flCoolantTemp, const real32_T *rtu_EVSE_Imax, const boolean_T
  *rtu_blPowerDeratingEn, real32_T *rty_flLLCVoltCmd, real32_T *rty_flLLCCurrCmd,
  OBCProtectionMsg *rty_OBCProtectionMsg)
{
  (void) (rtu_PhyValueOut_PFC);
  (void) (rtu_PhyValueOut_LLC);
  (void) (rtu_flOBCVoltCmd);
  (void) (rtu_flOBCCurrCmd);
  (void) (rtu_flDCCurr);
  (void) (rtu_flCoolantTemp);
  (void) (rtu_EVSE_Imax);
  (void) (rtu_blPowerDeratingEn);
  (void) (rty_flLLCVoltCmd);
  (void) (rty_flLLCCurrCmd);

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' incorporates:
   *  SubSystem: '<S1>/Fault_judgement'
   */
  /* SystemInitialize for ModelReference: '<S2>/Model1' incorporates:
   *  Constant: '<S2>/pp1_PFCVolt'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model1,
                  &(ProtectionHandler_M->dwork.Model1_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model2' incorporates:
   *  Constant: '<S2>/pp2_LLCVolt'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model2,
                  &(ProtectionHandler_M->dwork.Model2_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model3' incorporates:
   *  Constant: '<S2>/pp3_LLCCurr'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model3,
                  &(ProtectionHandler_M->dwork.Model3_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model4' incorporates:
   *  Constant: '<S2>/pp4_GirdLVolt'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model4,
                  &(ProtectionHandler_M->dwork.Model4_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model5' incorporates:
   *  Constant: '<S2>/pp5_GirdLVoltRMS'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model5,
                  &(ProtectionHandler_M->dwork.Model5_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model6' incorporates:
   *  Constant: '<S2>/pp6_GridVoltFreq'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model6,
                  &(ProtectionHandler_M->dwork.Model6_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model7' incorporates:
   *  Constant: '<S2>/pp7_PFCAux'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model7,
                  &(ProtectionHandler_M->dwork.Model7_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model9' incorporates:
   *  Constant: '<S2>/pp8_OBCTemp1'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model9,
                  &(ProtectionHandler_M->dwork.Model9_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model10' incorporates:
   *  Constant: '<S2>/pp9_OBCTemp2'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model10,
                  &(ProtectionHandler_M->dwork.Model10_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model11' incorporates:
   *  Constant: '<S2>/pp10_OBCTemp3'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model11,
                  &(ProtectionHandler_M->dwork.Model11_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model12' incorporates:
   *  Constant: '<S2>/pp11_PFCIswA'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model12,
                  &(ProtectionHandler_M->dwork.Model12_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model13' incorporates:
   *  Constant: '<S2>/pp12_PFCIswB'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model13,
                  &(ProtectionHandler_M->dwork.Model13_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model14' incorporates:
   *  Constant: '<S2>/pp13_PFCIswC'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model14,
                  &(ProtectionHandler_M->dwork.Model14_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model15' incorporates:
   *  Constant: '<S2>/pp14_PFCIswD'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model15,
                  &(ProtectionHandler_M->dwork.Model15_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model8' incorporates:
   *  Constant: '<S2>/pp15_HV_OVP_HW'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model8,
                  &(ProtectionHandler_M->dwork.Model8_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model16' incorporates:
   *  Constant: '<S2>/pp16_HV_SCP_HW'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model16,
                  &(ProtectionHandler_M->dwork.Model16_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model17' incorporates:
   *  Constant: '<S2>/pp17_LLC_OCP_HW'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model17,
                  &(ProtectionHandler_M->dwork.Model17_InstanceData.rtb));

  /* SystemInitialize for ModelReference: '<S2>/Model18' incorporates:
   *  Constant: '<S2>/pp18_PFC_OVP_HW'
   */
  Protection_Init(&ProtectionHandler_M->blockIO.Model18,
                  &(ProtectionHandler_M->dwork.Model18_InstanceData.rtb));

  /* SystemInitialize for BusCreator: '<S2>/Bus Creator' incorporates:
   *  SignalConversion: '<S2>/Signal Conversion1'
   *  SignalConversion: '<S2>/Signal Conversion10'
   *  SignalConversion: '<S2>/Signal Conversion18'
   *  SignalConversion: '<S2>/Signal Conversion2'
   *  SignalConversion: '<S2>/Signal Conversion26'
   *  SignalConversion: '<S2>/Signal Conversion27'
   *  SignalConversion: '<S2>/Signal Conversion28'
   *  SignalConversion: '<S2>/Signal Conversion29'
   *  SignalConversion: '<S2>/Signal Conversion3'
   *  SignalConversion: '<S2>/Signal Conversion30'
   *  SignalConversion: '<S2>/Signal Conversion31'
   *  SignalConversion: '<S2>/Signal Conversion32'
   *  SignalConversion: '<S2>/Signal Conversion4'
   *  SignalConversion: '<S2>/Signal Conversion5'
   *  SignalConversion: '<S2>/Signal Conversion6'
   *  SignalConversion: '<S2>/Signal Conversion7'
   *  SignalConversion: '<S2>/Signal Conversion8'
   *  SignalConversion: '<S2>/Signal Conversion9'
   */
  rty_OBCProtectionMsg->PFCVolt = ProtectionHandler_M->blockIO.Model1;
  rty_OBCProtectionMsg->LLCVolt = ProtectionHandler_M->blockIO.Model2;
  rty_OBCProtectionMsg->LLCCurr = ProtectionHandler_M->blockIO.Model3;
  rty_OBCProtectionMsg->GridVolt = ProtectionHandler_M->blockIO.Model4;
  rty_OBCProtectionMsg->GridVoltRms = ProtectionHandler_M->blockIO.Model5;
  rty_OBCProtectionMsg->GridVoltFreq = ProtectionHandler_M->blockIO.Model6;
  rty_OBCProtectionMsg->PFCAux = ProtectionHandler_M->blockIO.Model7;
  rty_OBCProtectionMsg->OBCTemp1 = ProtectionHandler_M->blockIO.Model9;
  rty_OBCProtectionMsg->OBCTemp2 = ProtectionHandler_M->blockIO.Model10;
  rty_OBCProtectionMsg->OBCTemp3 = ProtectionHandler_M->blockIO.Model11;
  rty_OBCProtectionMsg->PFCIswA = ProtectionHandler_M->blockIO.Model12;
  rty_OBCProtectionMsg->PFCIswB = ProtectionHandler_M->blockIO.Model13;
  rty_OBCProtectionMsg->PFCIswC = ProtectionHandler_M->blockIO.Model14;
  rty_OBCProtectionMsg->PFCIswD = ProtectionHandler_M->blockIO.Model15;
  rty_OBCProtectionMsg->HV_OVP_HW = ProtectionHandler_M->blockIO.Model8;
  rty_OBCProtectionMsg->HV_SCP_HW = ProtectionHandler_M->blockIO.Model16;
  rty_OBCProtectionMsg->LLC_OCP_HW = ProtectionHandler_M->blockIO.Model17;
  rty_OBCProtectionMsg->PFC_OVP_HW = ProtectionHandler_M->blockIO.Model18;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' */

  /* SystemInitialize for ModelReference: '<S1>/Model' */
  PowerDerating_Init((&(ProtectionHandler_M->Model)));
}

/* Output and update for referenced model: 'ProtectionHandler' */
void Protection_PowerDeratingTrigger(RT_MODEL_ProtectionHandler_T * const
  ProtectionHandler_M, const PhyValueOut_PFC *rtu_PhyValueOut_PFC, const
  PhyValueOut_LLC *rtu_PhyValueOut_LLC, const real32_T *rtu_flOBCVoltCmd, const
  real32_T *rtu_flOBCCurrCmd, const real32_T *rtu_flDCCurr, const real32_T
  *rtu_flCoolantTemp, const real32_T *rtu_EVSE_Imax, const boolean_T
  *rtu_blPowerDeratingEn, real32_T *rty_flLLCVoltCmd, real32_T *rty_flLLCCurrCmd)
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/PowerDeratingTrigger' */

  /* ModelReference: '<S1>/Model' */
  PowerDerat_PowerDeratingTrigger((&(ProtectionHandler_M->Model)),
    rtu_flOBCVoltCmd, rtu_flOBCCurrCmd, rtu_flDCCurr, rtu_flCoolantTemp,
    rtu_EVSE_Imax, rtu_blPowerDeratingEn, rtu_PhyValueOut_LLC,
    rtu_PhyValueOut_PFC, rty_flLLCVoltCmd, rty_flLLCCurrCmd);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PowerDeratingTrigger' */
}

/* Output and update for referenced model: 'ProtectionHandler' */
void ProtectionHan_ProtectionTrigger(RT_MODEL_ProtectionHandler_T * const
  ProtectionHandler_M, const PhyValueOut_PFC *rtu_PhyValueOut_PFC, const
  PhyValueOut_LLC *rtu_PhyValueOut_LLC, const PhyValueOut_Other
  *rtu_PhyValueOut_Other, const boolean_T *rtu_blHV_OVP_HW, const boolean_T
  *rtu_blHV_SCP_HW, const boolean_T *rtu_blLLC_OCP_HW, const boolean_T
  *rtu_blPFC_OVP_HW, const boolean_T *rtu_blFault_CMPSS, const boolean_T
  *rtu_blCAN_LOSS, const boolean_T *rtu_blCali_Conf_Err, boolean_T
  *rty_blTemporaryFault, boolean_T *rty_blCriticalFault, OBCProtectionMsg
  *rty_OBCProtectionMsg)
{
  /* local block i/o variables */
  real32_T rtb_PhyValue;
  real32_T rtb_PhyValue_ouvh;
  real32_T rtb_PhyValue_l0kq;
  real32_T rtb_PhyValue_hfuf;
  real32_T rtb_PhyValue_h5id;
  real32_T rtb_PhyValue_puvm;
  real32_T rtb_PhyValue_gwuw;
  real32_T rtb_PhyValue_ozvf;
  real32_T rtb_PhyValue_jipa;
  real32_T rtb_PhyValue_bxj3;
  real32_T rtb_PhyValue_hvm3;
  real32_T rtb_PhyValue_apds;
  real32_T rtb_PhyValue_kueq;
  real32_T rtb_PhyValue_l1kx;
  real32_T rtb_PhyValue_ieoq;
  real32_T rtb_PhyValue_bt1b;
  real32_T rtb_PhyValue_mb3f;
  real32_T rtb_PhyValue_neer;

  /* RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' incorporates:
   *  SubSystem: '<S1>/Integration_Fault'
   */
  /* Logic: '<S3>/OR' */
  *rty_blCriticalFault =
    ((((((((((((((((((((((((((((((((((rty_OBCProtectionMsg->PFCVolt.Error_Up) ||
    (rty_OBCProtectionMsg->PFCVolt.Error_Low)) ||
    (rty_OBCProtectionMsg->LLCVolt.Error_Up)) ||
    (rty_OBCProtectionMsg->LLCVolt.Error_Low)) ||
    (rty_OBCProtectionMsg->LLCCurr.Error_Up)) ||
    (rty_OBCProtectionMsg->LLCCurr.Error_Low)) ||
    (rty_OBCProtectionMsg->GridVolt.Error_Up)) ||
    (rty_OBCProtectionMsg->GridVolt.Error_Low)) ||
    (rty_OBCProtectionMsg->GridVoltRms.Error_Up)) ||
    (rty_OBCProtectionMsg->GridVoltRms.Error_Low)) ||
    (rty_OBCProtectionMsg->GridVoltFreq.Error_Up)) ||
    (rty_OBCProtectionMsg->GridVoltFreq.Error_Low)) ||
    (rty_OBCProtectionMsg->PFCAux.Error_Up)) ||
    (rty_OBCProtectionMsg->PFCAux.Error_Low)) ||
    (rty_OBCProtectionMsg->OBCTemp1.Error_Up)) ||
                       (rty_OBCProtectionMsg->OBCTemp1.Error_Low)) ||
                      (rty_OBCProtectionMsg->OBCTemp2.Error_Up)) ||
                     (rty_OBCProtectionMsg->OBCTemp2.Error_Low)) ||
                    (rty_OBCProtectionMsg->OBCTemp3.Error_Up)) ||
                   (rty_OBCProtectionMsg->OBCTemp3.Error_Low)) ||
                  (rty_OBCProtectionMsg->PFCIswA.Error_Up)) ||
                 (rty_OBCProtectionMsg->PFCIswA.Error_Low)) ||
                (rty_OBCProtectionMsg->PFCIswB.Error_Up)) ||
               (rty_OBCProtectionMsg->PFCIswB.Error_Low)) ||
              (rty_OBCProtectionMsg->PFCIswC.Error_Up)) ||
             (rty_OBCProtectionMsg->PFCIswC.Error_Low)) ||
            (rty_OBCProtectionMsg->PFCIswD.Error_Up)) ||
           (rty_OBCProtectionMsg->PFCIswD.Error_Low)) ||
          (rty_OBCProtectionMsg->HV_OVP_HW.Error_Up)) ||
         (rty_OBCProtectionMsg->HV_SCP_HW.Error_Up)) ||
        (rty_OBCProtectionMsg->LLC_OCP_HW.Error_Up)) ||
       (rty_OBCProtectionMsg->PFC_OVP_HW.Error_Up)) || (*rtu_blFault_CMPSS)) ||
     (*rtu_blCali_Conf_Err));

  /* Logic: '<S3>/OR1' */
  *rty_blTemporaryFault =
    (((((((((((((((((((((((((((((((((rty_OBCProtectionMsg->PFCVolt.Temp_Error_Low)
    || (rty_OBCProtectionMsg->PFCVolt.Temp_Error_Up)) ||
    (rty_OBCProtectionMsg->LLCVolt.Temp_Error_Low)) ||
    (rty_OBCProtectionMsg->LLCVolt.Temp_Error_Up)) ||
    (rty_OBCProtectionMsg->LLCCurr.Temp_Error_Low)) ||
    (rty_OBCProtectionMsg->LLCCurr.Temp_Error_Up)) ||
    (rty_OBCProtectionMsg->GridVolt.Temp_Error_Low)) ||
    (rty_OBCProtectionMsg->GridVolt.Temp_Error_Up)) ||
    (rty_OBCProtectionMsg->GridVoltRms.Temp_Error_Low)) ||
    (rty_OBCProtectionMsg->GridVoltRms.Temp_Error_Up)) ||
    (rty_OBCProtectionMsg->GridVoltFreq.Temp_Error_Low)) ||
    (rty_OBCProtectionMsg->GridVoltFreq.Temp_Error_Up)) ||
    (rty_OBCProtectionMsg->PFCAux.Temp_Error_Low)) ||
    (rty_OBCProtectionMsg->GridVoltFreq.Temp_Error_Up)) ||
                       (rty_OBCProtectionMsg->OBCTemp1.Temp_Error_Low)) ||
                      (rty_OBCProtectionMsg->OBCTemp1.Temp_Error_Up)) ||
                     (rty_OBCProtectionMsg->OBCTemp2.Temp_Error_Low)) ||
                    (rty_OBCProtectionMsg->OBCTemp2.Temp_Error_Up)) ||
                   (rty_OBCProtectionMsg->OBCTemp3.Temp_Error_Low)) ||
                  (rty_OBCProtectionMsg->OBCTemp3.Temp_Error_Up)) ||
                 (rty_OBCProtectionMsg->PFCIswA.Temp_Error_Low)) ||
                (rty_OBCProtectionMsg->PFCIswA.Temp_Error_Up)) ||
               (rty_OBCProtectionMsg->PFCIswB.Temp_Error_Low)) ||
              (rty_OBCProtectionMsg->PFCIswB.Temp_Error_Up)) ||
             (rty_OBCProtectionMsg->PFCIswC.Temp_Error_Low)) ||
            (rty_OBCProtectionMsg->PFCIswC.Temp_Error_Up)) ||
           (rty_OBCProtectionMsg->PFCIswD.Temp_Error_Low)) ||
          (rty_OBCProtectionMsg->PFCIswD.Temp_Error_Up)) ||
         (rty_OBCProtectionMsg->HV_OVP_HW.Temp_Error_Up)) ||
        (rty_OBCProtectionMsg->HV_SCP_HW.Temp_Error_Up)) ||
       (rty_OBCProtectionMsg->LLC_OCP_HW.Temp_Error_Up)) ||
      (rty_OBCProtectionMsg->PFC_OVP_HW.Temp_Error_Up)) || (*rtu_blCAN_LOSS));

  /* RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' incorporates:
   *  SubSystem: '<S1>/Fault_judgement'
   */
  /* SignalConversion: '<S2>/Signal Conversion11' */
  rtb_PhyValue = rtu_PhyValueOut_PFC->PFCVolt;

  /* ModelReference: '<S2>/Model1' incorporates:
   *  Constant: '<S2>/pp1_PFCVolt'
   */
  Protection(&rtb_PhyValue, &(&AnalogParameter_Protection[0])[0],
             &(ProtectionHandler_M)->blockIO.Model1, &((ProtectionHandler_M)
              ->dwork.Model1_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model1_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion13' */
  rtb_PhyValue_ouvh = rtu_PhyValueOut_LLC->LLCVolt;

  /* ModelReference: '<S2>/Model2' incorporates:
   *  Constant: '<S2>/pp2_LLCVolt'
   */
  Protection(&rtb_PhyValue_ouvh, &AnalogParameter_Protection[1],
             &(ProtectionHandler_M)->blockIO.Model2, &((ProtectionHandler_M)
              ->dwork.Model2_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model2_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion12' */
  rtb_PhyValue_l0kq = rtu_PhyValueOut_LLC->LLCCurr;

  /* ModelReference: '<S2>/Model3' incorporates:
   *  Constant: '<S2>/pp3_LLCCurr'
   */
  Protection(&rtb_PhyValue_l0kq, &AnalogParameter_Protection[2],
             &(ProtectionHandler_M)->blockIO.Model3, &((ProtectionHandler_M)
              ->dwork.Model3_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model3_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion14' */
  rtb_PhyValue_hfuf = rtu_PhyValueOut_PFC->GridVolt;

  /* ModelReference: '<S2>/Model4' incorporates:
   *  Constant: '<S2>/pp4_GirdLVolt'
   */
  Protection(&rtb_PhyValue_hfuf, &AnalogParameter_Protection[3],
             &(ProtectionHandler_M)->blockIO.Model4, &((ProtectionHandler_M)
              ->dwork.Model4_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model4_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion15' */
  rtb_PhyValue_h5id = rtu_PhyValueOut_PFC->GridVoltRms;

  /* ModelReference: '<S2>/Model5' incorporates:
   *  Constant: '<S2>/pp5_GirdLVoltRMS'
   */
  Protection(&rtb_PhyValue_h5id, &AnalogParameter_Protection[4],
             &(ProtectionHandler_M)->blockIO.Model5, &((ProtectionHandler_M)
              ->dwork.Model5_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model5_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion16' */
  rtb_PhyValue_puvm = rtu_PhyValueOut_PFC->GridVoltFreq;

  /* ModelReference: '<S2>/Model6' incorporates:
   *  Constant: '<S2>/pp6_GridVoltFreq'
   */
  Protection(&rtb_PhyValue_puvm, &AnalogParameter_Protection[5],
             &(ProtectionHandler_M)->blockIO.Model6, &((ProtectionHandler_M)
              ->dwork.Model6_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model6_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion17' */
  rtb_PhyValue_gwuw = rtu_PhyValueOut_Other->PFCAux;

  /* ModelReference: '<S2>/Model7' incorporates:
   *  Constant: '<S2>/pp7_PFCAux'
   */
  Protection(&rtb_PhyValue_gwuw, &AnalogParameter_Protection[6],
             &(ProtectionHandler_M)->blockIO.Model7, &((ProtectionHandler_M)
              ->dwork.Model7_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model7_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion19' */
  rtb_PhyValue_ozvf = rtu_PhyValueOut_Other->OBCTemp1;

  /* ModelReference: '<S2>/Model9' incorporates:
   *  Constant: '<S2>/pp8_OBCTemp1'
   */
  Protection(&rtb_PhyValue_ozvf, &AnalogParameter_Protection[7],
             &(ProtectionHandler_M)->blockIO.Model9, &((ProtectionHandler_M)
              ->dwork.Model9_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model9_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion20' */
  rtb_PhyValue_jipa = rtu_PhyValueOut_Other->OBCTemp2;

  /* ModelReference: '<S2>/Model10' incorporates:
   *  Constant: '<S2>/pp9_OBCTemp2'
   */
  Protection(&rtb_PhyValue_jipa, &AnalogParameter_Protection[8],
             &(ProtectionHandler_M)->blockIO.Model10, &((ProtectionHandler_M)
              ->dwork.Model10_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model10_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion21' */
  rtb_PhyValue_bxj3 = rtu_PhyValueOut_Other->OBCTemp3;

  /* ModelReference: '<S2>/Model11' incorporates:
   *  Constant: '<S2>/pp10_OBCTemp3'
   */
  Protection(&rtb_PhyValue_bxj3, &AnalogParameter_Protection[9],
             &(ProtectionHandler_M)->blockIO.Model11, &((ProtectionHandler_M)
              ->dwork.Model11_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model11_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion22' */
  rtb_PhyValue_hvm3 = rtu_PhyValueOut_PFC->PFCIswA;

  /* ModelReference: '<S2>/Model12' incorporates:
   *  Constant: '<S2>/pp11_PFCIswA'
   */
  Protection(&rtb_PhyValue_hvm3, &AnalogParameter_Protection[10],
             &(ProtectionHandler_M)->blockIO.Model12, &((ProtectionHandler_M)
              ->dwork.Model12_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model12_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion23' */
  rtb_PhyValue_apds = rtu_PhyValueOut_PFC->PFCIswB;

  /* ModelReference: '<S2>/Model13' incorporates:
   *  Constant: '<S2>/pp12_PFCIswB'
   */
  Protection(&rtb_PhyValue_apds, &AnalogParameter_Protection[11],
             &(ProtectionHandler_M)->blockIO.Model13, &((ProtectionHandler_M)
              ->dwork.Model13_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model13_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion24' */
  rtb_PhyValue_kueq = rtu_PhyValueOut_PFC->PFCIswC;

  /* ModelReference: '<S2>/Model14' incorporates:
   *  Constant: '<S2>/pp13_PFCIswC'
   */
  Protection(&rtb_PhyValue_kueq, &AnalogParameter_Protection[12],
             &(ProtectionHandler_M)->blockIO.Model14, &((ProtectionHandler_M)
              ->dwork.Model14_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model14_InstanceData.rtdw));

  /* SignalConversion: '<S2>/Signal Conversion25' */
  rtb_PhyValue_l1kx = rtu_PhyValueOut_PFC->PFCIswD;

  /* ModelReference: '<S2>/Model15' incorporates:
   *  Constant: '<S2>/pp14_PFCIswD'
   */
  Protection(&rtb_PhyValue_l1kx, &AnalogParameter_Protection[13],
             &(ProtectionHandler_M)->blockIO.Model15, &((ProtectionHandler_M)
              ->dwork.Model15_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model15_InstanceData.rtdw));

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  rtb_PhyValue_ieoq = (*rtu_blHV_OVP_HW) ? 1.0F : 0.0F;

  /* ModelReference: '<S2>/Model8' incorporates:
   *  Constant: '<S2>/pp15_HV_OVP_HW'
   */
  Protection(&rtb_PhyValue_ieoq, &AnalogParameter_Protection[14],
             &(ProtectionHandler_M)->blockIO.Model8, &((ProtectionHandler_M)
              ->dwork.Model8_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model8_InstanceData.rtdw));

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_PhyValue_bt1b = (*rtu_blHV_SCP_HW) ? 1.0F : 0.0F;

  /* ModelReference: '<S2>/Model16' incorporates:
   *  Constant: '<S2>/pp16_HV_SCP_HW'
   */
  Protection(&rtb_PhyValue_bt1b, &AnalogParameter_Protection[15],
             &(ProtectionHandler_M)->blockIO.Model16, &((ProtectionHandler_M)
              ->dwork.Model16_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model16_InstanceData.rtdw));

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  rtb_PhyValue_mb3f = (*rtu_blLLC_OCP_HW) ? 1.0F : 0.0F;

  /* ModelReference: '<S2>/Model17' incorporates:
   *  Constant: '<S2>/pp17_LLC_OCP_HW'
   */
  Protection(&rtb_PhyValue_mb3f, &AnalogParameter_Protection[16],
             &(ProtectionHandler_M)->blockIO.Model17, &((ProtectionHandler_M)
              ->dwork.Model17_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model17_InstanceData.rtdw));

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  rtb_PhyValue_neer = (*rtu_blPFC_OVP_HW) ? 1.0F : 0.0F;

  /* ModelReference: '<S2>/Model18' incorporates:
   *  Constant: '<S2>/pp18_PFC_OVP_HW'
   */
  Protection(&rtb_PhyValue_neer, &AnalogParameter_Protection[17],
             &(ProtectionHandler_M)->blockIO.Model18, &((ProtectionHandler_M)
              ->dwork.Model18_InstanceData.rtb), &((ProtectionHandler_M)
              ->dwork.Model18_InstanceData.rtdw));

  /* BusCreator: '<S2>/Bus Creator' incorporates:
   *  SignalConversion: '<S2>/Signal Conversion1'
   *  SignalConversion: '<S2>/Signal Conversion10'
   *  SignalConversion: '<S2>/Signal Conversion18'
   *  SignalConversion: '<S2>/Signal Conversion2'
   *  SignalConversion: '<S2>/Signal Conversion26'
   *  SignalConversion: '<S2>/Signal Conversion27'
   *  SignalConversion: '<S2>/Signal Conversion28'
   *  SignalConversion: '<S2>/Signal Conversion29'
   *  SignalConversion: '<S2>/Signal Conversion3'
   *  SignalConversion: '<S2>/Signal Conversion30'
   *  SignalConversion: '<S2>/Signal Conversion31'
   *  SignalConversion: '<S2>/Signal Conversion32'
   *  SignalConversion: '<S2>/Signal Conversion4'
   *  SignalConversion: '<S2>/Signal Conversion5'
   *  SignalConversion: '<S2>/Signal Conversion6'
   *  SignalConversion: '<S2>/Signal Conversion7'
   *  SignalConversion: '<S2>/Signal Conversion8'
   *  SignalConversion: '<S2>/Signal Conversion9'
   */
  rty_OBCProtectionMsg->PFCVolt = ProtectionHandler_M->blockIO.Model1;
  rty_OBCProtectionMsg->LLCVolt = ProtectionHandler_M->blockIO.Model2;
  rty_OBCProtectionMsg->LLCCurr = ProtectionHandler_M->blockIO.Model3;
  rty_OBCProtectionMsg->GridVolt = ProtectionHandler_M->blockIO.Model4;
  rty_OBCProtectionMsg->GridVoltRms = ProtectionHandler_M->blockIO.Model5;
  rty_OBCProtectionMsg->GridVoltFreq = ProtectionHandler_M->blockIO.Model6;
  rty_OBCProtectionMsg->PFCAux = ProtectionHandler_M->blockIO.Model7;
  rty_OBCProtectionMsg->OBCTemp1 = ProtectionHandler_M->blockIO.Model9;
  rty_OBCProtectionMsg->OBCTemp2 = ProtectionHandler_M->blockIO.Model10;
  rty_OBCProtectionMsg->OBCTemp3 = ProtectionHandler_M->blockIO.Model11;
  rty_OBCProtectionMsg->PFCIswA = ProtectionHandler_M->blockIO.Model12;
  rty_OBCProtectionMsg->PFCIswB = ProtectionHandler_M->blockIO.Model13;
  rty_OBCProtectionMsg->PFCIswC = ProtectionHandler_M->blockIO.Model14;
  rty_OBCProtectionMsg->PFCIswD = ProtectionHandler_M->blockIO.Model15;
  rty_OBCProtectionMsg->HV_OVP_HW = ProtectionHandler_M->blockIO.Model8;
  rty_OBCProtectionMsg->HV_SCP_HW = ProtectionHandler_M->blockIO.Model16;
  rty_OBCProtectionMsg->LLC_OCP_HW = ProtectionHandler_M->blockIO.Model17;
  rty_OBCProtectionMsg->PFC_OVP_HW = ProtectionHandler_M->blockIO.Model18;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/ProtectionTrigger' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
