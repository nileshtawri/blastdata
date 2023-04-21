/*
 * File: PowerDerating.c
 *
 * Code generated for Simulink model 'PowerDerating'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jun  6 15:44:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PowerDerating.h"
#include "PowerDerating_private.h"

/* System initialize for referenced model: 'PowerDerating' */
void PowerDerating_Init(RT_MODEL_PowerDerating_T * const PowerDerating_M)
{
  (void) (PowerDerating_M);
}

/* Output and update for referenced model: 'PowerDerating' */
void PowerDerat_PowerDeratingTrigger(RT_MODEL_PowerDerating_T * const
  PowerDerating_M, const real32_T *rtu_flOBCVoltCmd, const real32_T
  *rtu_flOBCCurrCmd, const real32_T *rtu_flDCCurr, const real32_T
  *rtu_flCoolantTemp, const real32_T *rtu_EVSE_Imax, const boolean_T
  *rtu_blPowerDeratingEn, const PhyValueOut_LLC *rtu_PhyValueOut_LLC, const
  PhyValueOut_PFC *rtu_PhyValueOut_PFC, real32_T *rty_flLLCVoltCmd, real32_T
  *rty_flLLCCurrCmd)
{
  real32_T rtb_Saturation_nmox;
  real32_T rtb_Product1_pklu;
  real32_T rtb_Add;
  real32_T tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/PowerDeratingTrigger' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* Saturate: '<S1>/Saturation' */
  if ((*rtu_flOBCCurrCmd) > 22.1F) {
    rtb_Product1_pklu = 22.1F;
  } else if ((*rtu_flOBCCurrCmd) < 0.0F) {
    rtb_Product1_pklu = 0.0F;
  } else {
    rtb_Product1_pklu = *rtu_flOBCCurrCmd;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Sum: '<S1>/Add' */
  rtb_Add = rtb_Product1_pklu + (*rtu_flDCCurr);

  /* Relay: '<S4>/Relay' */
  PowerDerating_M->dwork.Relay_Mode = ((rtu_PhyValueOut_PFC->GridVoltRms >=
    175.0F) || ((rtu_PhyValueOut_PFC->GridVoltRms > 170.0F) &&
                (PowerDerating_M->dwork.Relay_Mode)));

  /* Product: '<S4>/Product1' */
  rtb_Product1_pklu *= *rtu_flOBCVoltCmd;

  /* If: '<S4>/If' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S6>/Constant'
   *  Product: '<S5>/Product'
   *  RelationalOperator: '<S4>/Relational Operator'
   *  SignalConversion generated from: '<S6>/flMaxPower'
   *  Sum: '<S5>/Add'
   */
  if ((*rtu_flCoolantTemp) >= 65.0F) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    rtb_Saturation_nmox = 26533.0F - ((*rtu_flCoolantTemp) * 306.66F);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    rtb_Saturation_nmox = 6600.0F;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If' */

  /* Relay: '<S4>/Relay' */
  if (PowerDerating_M->dwork.Relay_Mode) {
    tmp = 1.0F;
  } else {
    tmp = 0.0F;
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant5'
   */
  if (tmp > 0.0F) {
    tmp = 32.0F;
  } else {
    tmp = 16.0F;
  }

  /* End of Switch: '<S4>/Switch' */

  /* MinMax: '<S4>/Min' incorporates:
   *  Gain: '<S4>/Gain'
   *  MinMax: '<S4>/Min1'
   *  Product: '<S4>/Product'
   */
  rtb_Product1_pklu = fminf(fminf(rtb_Saturation_nmox, 0.945F *
    (rtu_PhyValueOut_PFC->GridVoltRms * fminf(tmp, *rtu_EVSE_Imax))),
    rtb_Product1_pklu);

  /* Saturate: '<S4>/Saturation' */
  if (rtb_Product1_pklu > 6600.0F) {
    rtb_Product1_pklu = 6600.0F;
  } else {
    if (rtb_Product1_pklu < 0.0F) {
      rtb_Product1_pklu = 0.0F;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Sum: '<S3>/Add' incorporates:
   *  Abs: '<S3>/Abs'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Product: '<S3>/Divide'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Add1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Product1_pklu = ((rtb_Product1_pklu / (fabsf(rtu_PhyValueOut_LLC->LLCVolt)
    + 2.22044605E-16F)) * 0.05F) + (0.95F *
    PowerDerating_M->dwork.UnitDelay_DSTATE);

  /* Saturate: '<S3>/Saturation' */
  if (rtb_Product1_pklu > 22.1F) {
    rtb_Saturation_nmox = 22.1F;
  } else if (rtb_Product1_pklu < 0.0F) {
    rtb_Saturation_nmox = 0.0F;
  } else {
    rtb_Saturation_nmox = rtb_Product1_pklu;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Saturate: '<S1>/Saturation1' */
  if ((*rtu_flOBCVoltCmd) > 450.0F) {
    *rty_flLLCVoltCmd = 450.0F;
  } else if ((*rtu_flOBCVoltCmd) < 250.0F) {
    *rty_flLLCVoltCmd = 250.0F;
  } else {
    *rty_flLLCVoltCmd = *rtu_flOBCVoltCmd;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Switch: '<S1>/Switch' */
  if (*rtu_blPowerDeratingEn) {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Constant: '<S1>/Constant'
     *  RelationalOperator: '<S2>/LowerRelop1'
     *  RelationalOperator: '<S2>/UpperRelop'
     *  Switch: '<S2>/Switch'
     */
    if (rtb_Add > rtb_Saturation_nmox) {
      *rty_flLLCCurrCmd = rtb_Saturation_nmox;
    } else if (((real_T)rtb_Add) < 0.0) {
      /* Switch: '<S2>/Switch' incorporates:
       *  Constant: '<S1>/Constant'
       */
      *rty_flLLCCurrCmd = (real32_T)0.0;
    } else {
      *rty_flLLCCurrCmd = rtb_Add;
    }

    /* End of Switch: '<S2>/Switch2' */
  } else {
    *rty_flLLCCurrCmd = rtb_Add;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  PowerDerating_M->dwork.UnitDelay_DSTATE = rtb_Product1_pklu;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PowerDeratingTrigger' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
