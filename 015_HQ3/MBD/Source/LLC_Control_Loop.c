/*
 * File: LLC_Control_Loop.c
 *
 * Code generated for Simulink model 'LLC_Control_Loop'.
 *
 * Model version                  : 1.220
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Apr  6 14:36:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LLC_Control_Loop.h"
#include "LLC_Control_Loop_private.h"

/* Exported block parameters */
real32_T flCCKi = 0.35F;               /* Variable: flCCKi
                                        * Referenced by: '<S1>/Constant9'
                                        */
real32_T flCCKp = 0.01F;               /* Variable: flCCKp
                                        * Referenced by: '<S1>/Constant8'
                                        */
real32_T flCVKi = 0.11925F;             /* Variable: flCVKi
                                        * Referenced by: '<S1>/Constant1'
                                        * 0.03

                                          0.3*2
                                        */
real32_T flCVKp = 0.003375F;             /* Variable: flCVKp
                                        * Referenced by: '<S1>/Constant'
                                        * 0.001

                                          0.1*2
                                        */
real32_T flCtrlLowLimit = 0.0F;        /* Variable: flCtrlLowLimit
                                        * Referenced by:
                                        *   '<S1>/Constant3'
                                        *   '<S1>/Constant6'
                                        */
real32_T flCtrlUpLimit = 1667.0F;      /* Variable: flCtrlUpLimit
                                        * Referenced by:
                                        *   '<S1>/Constant11'
                                        *   '<S1>/Constant5'
                                        */

/* Block states (default storage) */
DW_LLC_Control_Loop_T LLC_Control_Loop_DW;

/* External inputs (root inport signals with default storage) */
ExtU_LLC_Control_Loop_T LLC_Control_Loop_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_LLC_Control_Loop_T LLC_Control_Loop_Y;

/* Model step function */
#pragma CODE_SECTION(LLC_Control_Loop_step,".TI.ramfunc");
void LLC_Control_Loop_step(void)
{
  real32_T rtb_flCtrlOutTheta;
  real32_T rtb_flError;
  real32_T rtb_flError_iqwb;
  real32_T rtb_flError_last1;
  real32_T rtb_Add5;
  real32_T rtb_flError_last1_ocxl;
  real32_T rtb_Add5_nffi;

  /* Sum: '<S2>/Add' incorporates:
   *  Inport: '<Root>/PhyValueOut_LLC'
   *  Inport: '<Root>/flLLCVoltRef'
   *  SignalConversion: '<S1>/SignalConversion1'
   */
  rtb_flError = LLC_Control_Loop_U.flLLCVoltRef -
    LLC_Control_Loop_U.PhyValueOut_LLC_mtcd.LLCVolt;

  /* UnitDelay: '<S2>/UnitDelay' */
  rtb_flError_last1 = LLC_Control_Loop_DW.UnitDelay_DSTATE;

  /* Switch: '<S2>/Switch' incorporates:
   *  Inport: '<Root>/LLC_Reset'
   *  UnitDelay: '<S2>/UnitDelay2'
   */
  if (LLC_Control_Loop_U.LLC_Reset) {
    rtb_Add5_nffi = LLC_Control_Loop_ConstB.flInitValue;
  } else {
    rtb_Add5_nffi = LLC_Control_Loop_DW.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Sum: '<S2>/Add2' incorporates:
   *  Sum: '<S2>/Add6'
   *  UnitDelay: '<S2>/UnitDelay'
   */
  rtb_Add5 = rtb_flError - LLC_Control_Loop_DW.UnitDelay_DSTATE;

  /* Sum: '<S2>/Add5' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  DataTypeConversion: '<S2>/DataTypeConversion4'
   *  DataTypeConversion: '<S2>/DataTypeConversion5'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Sum: '<S2>/Add1'
   *  Sum: '<S2>/Add2'
   *  Sum: '<S2>/Add3'
   *  Sum: '<S2>/Add4'
   *  Sum: '<S2>/Add7'
   *  UnitDelay: '<S2>/UnitDelay'
   *  UnitDelay: '<S2>/UnitDelay1'
   */
  rtb_Add5 = (((flCVKp * rtb_Add5) + (flCVKi * rtb_flError)) +
              (LLC_Control_Loop_ConstB.flKd * ((rtb_Add5 -
    LLC_Control_Loop_DW.UnitDelay_DSTATE) +
    LLC_Control_Loop_DW.UnitDelay1_DSTATE))) + rtb_Add5_nffi;

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant3'
   *  DataTypeConversion: '<S2>/DataTypeConversion7'
   *  DataTypeConversion: '<S2>/DataTypeConversion8'
   *  RelationalOperator: '<S4>/LowerRelop1'
   *  RelationalOperator: '<S4>/UpperRelop'
   *  Switch: '<S4>/Switch'
   */
  if (rtb_Add5 > flCtrlUpLimit) {
    rtb_Add5 = flCtrlUpLimit;
  } else {
    if (rtb_Add5 < flCtrlLowLimit) {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S1>/Constant3'
       *  DataTypeConversion: '<S2>/DataTypeConversion8'
       */
      rtb_Add5 = flCtrlLowLimit;
    }
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/PhyValueOut_LLC'
   *  Inport: '<Root>/flLLCCurrRef'
   *  SignalConversion: '<S1>/SignalConversion6'
   */
  rtb_flError_iqwb = LLC_Control_Loop_U.flLLCCurrRef -
    LLC_Control_Loop_U.PhyValueOut_LLC_mtcd.LLCCurr;

  /* UnitDelay: '<S3>/UnitDelay' */
  rtb_flError_last1_ocxl = LLC_Control_Loop_DW.UnitDelay_DSTATE_exj3;

  /* Switch: '<S3>/Switch' incorporates:
   *  Inport: '<Root>/LLC_Reset'
   *  UnitDelay: '<S3>/UnitDelay2'
   */
  if (LLC_Control_Loop_U.LLC_Reset) {
    rtb_Add5_nffi = LLC_Control_Loop_ConstB.flInitValue_dhlv;
  } else {
    rtb_Add5_nffi = LLC_Control_Loop_DW.UnitDelay2_DSTATE_i1xh;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Add2' incorporates:
   *  Sum: '<S3>/Add6'
   *  UnitDelay: '<S3>/UnitDelay'
   */
  rtb_flCtrlOutTheta = rtb_flError_iqwb -
    LLC_Control_Loop_DW.UnitDelay_DSTATE_exj3;

  /* Sum: '<S3>/Add5' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   *  DataTypeConversion: '<S3>/DataTypeConversion4'
   *  DataTypeConversion: '<S3>/DataTypeConversion5'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   *  Sum: '<S3>/Add1'
   *  Sum: '<S3>/Add2'
   *  Sum: '<S3>/Add3'
   *  Sum: '<S3>/Add4'
   *  Sum: '<S3>/Add7'
   *  UnitDelay: '<S3>/UnitDelay'
   *  UnitDelay: '<S3>/UnitDelay1'
   */
  rtb_Add5_nffi += ((flCCKp * rtb_flCtrlOutTheta) + (flCCKi * rtb_flError_iqwb))
    + (LLC_Control_Loop_ConstB.flKd_lpwk * ((rtb_flCtrlOutTheta -
         LLC_Control_Loop_DW.UnitDelay_DSTATE_exj3) +
        LLC_Control_Loop_DW.UnitDelay1_DSTATE_b54s));

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  DataTypeConversion: '<S3>/DataTypeConversion7'
   *  DataTypeConversion: '<S3>/DataTypeConversion8'
   *  RelationalOperator: '<S5>/LowerRelop1'
   *  RelationalOperator: '<S5>/UpperRelop'
   *  Switch: '<S5>/Switch'
   */
  if (rtb_Add5_nffi > flCtrlUpLimit) {
    rtb_Add5_nffi = flCtrlUpLimit;
  } else {
    if (rtb_Add5_nffi < flCtrlLowLimit) {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S1>/Constant6'
       *  DataTypeConversion: '<S3>/DataTypeConversion8'
       */
      rtb_Add5_nffi = flCtrlLowLimit;
    }
  }

  /* End of Switch: '<S5>/Switch2' */

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant4'
   *  Gain: '<S1>/Gain3'
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  Inport: '<Root>/flLLCVoltRef'
   *  MinMax: '<S1>/Min'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add3'
   */
  rtb_flCtrlOutTheta = ((0.2F * LLC_Control_Loop_U.flLLCVoltRef) + 1.8*(400.0F -
    LLC_Control_Loop_U.PhyValueOut_PFC_mjhy.PFCVolt)) + fminf(rtb_Add5,
    rtb_Add5_nffi);

  /* Saturate: '<S1>/Saturation' */
  if (rtb_flCtrlOutTheta > 1667.0F) {
    /* Outport: '<Root>/wCtrlOutFreq' incorporates:
     *  DataTypeConversion: '<S1>/DataTypeConversion2'
     */
    LLC_Control_Loop_Y.wCtrlOutFreq = (uint16_T)1667.0F;
  } else if (rtb_flCtrlOutTheta < 556.0F) {
    /* Outport: '<Root>/wCtrlOutFreq' incorporates:
     *  DataTypeConversion: '<S1>/DataTypeConversion2'
     */
    LLC_Control_Loop_Y.wCtrlOutFreq = (uint16_T)556.0F;
  } else {
    /* Outport: '<Root>/wCtrlOutFreq' incorporates:
     *  DataTypeConversion: '<S1>/DataTypeConversion2'
     */
    LLC_Control_Loop_Y.wCtrlOutFreq = (uint16_T)rtb_flCtrlOutTheta;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_flCtrlOutTheta > 556.0F) {
    rtb_flCtrlOutTheta = 556.0F;
  } else {
    if (rtb_flCtrlOutTheta < 278.0F) {
      rtb_flCtrlOutTheta = 278.0F;
    }
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Outport: '<Root>/wCtrlOutTheta' incorporates:
   *  DataTypeConversion: '<S1>/DataTypeConversion1'
   */
  LLC_Control_Loop_Y.wCtrlOutTheta = (uint16_T)rtb_flCtrlOutTheta;

  /* Update for UnitDelay: '<S2>/UnitDelay' */
  LLC_Control_Loop_DW.UnitDelay_DSTATE = rtb_flError;

  /* Update for UnitDelay: '<S2>/UnitDelay1' */
  LLC_Control_Loop_DW.UnitDelay1_DSTATE = rtb_flError_last1;

  /* Update for UnitDelay: '<S2>/UnitDelay2' */
  LLC_Control_Loop_DW.UnitDelay2_DSTATE = rtb_Add5;

  /* Update for UnitDelay: '<S3>/UnitDelay' */
  LLC_Control_Loop_DW.UnitDelay_DSTATE_exj3 = rtb_flError_iqwb;

  /* Update for UnitDelay: '<S3>/UnitDelay1' */
  LLC_Control_Loop_DW.UnitDelay1_DSTATE_b54s = rtb_flError_last1_ocxl;

  /* Update for UnitDelay: '<S3>/UnitDelay2' */
  LLC_Control_Loop_DW.UnitDelay2_DSTATE_i1xh = rtb_Add5_nffi;
}

/* Model initialize function */
void LLC_Control_Loop_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
