/*
 * File: RMS.c
 *
 * Code generated for Simulink model 'RMS'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Feb 21 10:21:17 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RMS.h"
#include "RMS_private.h"

/* Output and update for referenced model: 'RMS' */
#pragma CODE_SECTION(RMS,".TI.ramfunc");
void RMS(const real32_T *rtu_Frequency, const real32_T *rtu_Signal, real32_T
         *rty_RMS, DW_RMS_fwu4_T *localDW)
{
  real32_T rtb_Switch3;
  real32_T rtb_Sum8;
  real32_T rtb_Saturation1;
  boolean_T rtb_RelationalOperator1;
  real32_T rtu_Frequency_0;

  /* Abs: '<S1>/Abs1' */
  rtb_Switch3 = fabsf(*rtu_Signal);

  /* Switch: '<S1>/Switch1' incorporates:
   *  UnitDelay: '<S1>/UnitDelay4'
   *  UnitDelay: '<S1>/UnitDelay6'
   */
  if (localDW->UnitDelay6_DSTATE) {
    rtb_Sum8 = RMS_ConstB.DataTypeConversion4;
  } else {
    rtb_Sum8 = localDW->UnitDelay4_DSTATE;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Sum: '<S1>/Sum14' incorporates:
   *  Product: '<S1>/Product7'
   */
  rtb_Switch3 = (rtb_Switch3 * rtb_Switch3) + rtb_Sum8;

  /* Switch: '<S1>/Switch2' incorporates:
   *  UnitDelay: '<S1>/UnitDelay5'
   *  UnitDelay: '<S1>/UnitDelay6'
   */
  if (localDW->UnitDelay6_DSTATE) {
    rtb_Sum8 = RMS_ConstB.DataTypeConversion2;
  } else {
    rtb_Sum8 = localDW->UnitDelay5_DSTATE;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Sum: '<S1>/Sum8' */
  rtb_Sum8 += RMS_ConstB.DataTypeConversion;

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Sum8 > 667.0F) {
    rtb_Saturation1 = 667.0F;
  } else if (rtb_Sum8 < 250.0F) {
    rtb_Saturation1 = 250.0F;
  } else {
    rtb_Saturation1 = rtb_Sum8;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* Saturate: '<S1>/Saturation' */
  if ((*rtu_Frequency) > 80.0F) {
    rtu_Frequency_0 = 80.0F;
  } else if ((*rtu_Frequency) < 30.0F) {
    rtu_Frequency_0 = 30.0F;
  } else {
    rtu_Frequency_0 = *rtu_Frequency;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
   *  Product: '<S1>/Divide1'
   */
  rtb_RelationalOperator1 = (rtb_Saturation1 > (RMS_ConstB.DataTypeConversion3 /
    rtu_Frequency_0));

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  *rty_RMS = localDW->UnitDelay3_DSTATE;

  /* Switch: '<S1>/Switch3' */
  if (rtb_RelationalOperator1) {
    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  Product: '<S1>/Divide2'
     *  Sqrt: '<S1>/Sqrt'
     */
    *rty_RMS = sqrtf(rtb_Switch3 / rtb_Saturation1);
  }

  /* End of Switch: '<S1>/Switch3' */

  /* Update for UnitDelay: '<S1>/UnitDelay6' */
  localDW->UnitDelay6_DSTATE = rtb_RelationalOperator1;

  /* Update for UnitDelay: '<S1>/UnitDelay4' */
  localDW->UnitDelay4_DSTATE = rtb_Switch3;

  /* Update for UnitDelay: '<S1>/UnitDelay5' */
  localDW->UnitDelay5_DSTATE = rtb_Sum8;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE = *rty_RMS;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
