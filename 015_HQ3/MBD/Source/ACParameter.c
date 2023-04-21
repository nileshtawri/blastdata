/*
 * File: ACParameter.c
 *
 * Code generated for Simulink model 'ACParameter'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Apr  6 13:14:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACParameter.h"
#include "ACParameter_private.h"

/* Output and update for referenced model: 'ACParameter' */
#pragma CODE_SECTION(ACParameter,".TI.ramfunc");
void ACParameter(const real32_T *rtu_Signal, real32_T *rty_Theta, real32_T
                 *rty_Frequency, real32_T *rty_RMS, DW_ACParameter_fwu4_T
                 *localDW)
{
  real32_T rtb_Sum3;
  real32_T rtb_Sum8;
  real32_T rtb_Saturation1;
  real32_T rtb_Sum5;
  real32_T rtb_Sum1;
  boolean_T rtb_RelationalOperator1;
  real32_T rtb_Sum14;
  real32_T rty_Frequency_0;

  /* Abs: '<S2>/Abs1' */
  rtb_Sum3 = fabsf(*rtu_Signal);

  /* Switch: '<S2>/Switch1' incorporates:
   *  UnitDelay: '<S2>/UnitDelay4'
   *  UnitDelay: '<S2>/UnitDelay6'
   */
  if (localDW->UnitDelay6_DSTATE) {
    rtb_Sum8 = ACParameter_ConstB.DataTypeConversion4;
  } else {
    rtb_Sum8 = localDW->UnitDelay4_DSTATE;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Sum: '<S2>/Sum14' incorporates:
   *  Product: '<S2>/Product7'
   */
  rtb_Sum14 = (rtb_Sum3 * rtb_Sum3) + rtb_Sum8;

  /* Switch: '<S2>/Switch2' incorporates:
   *  UnitDelay: '<S2>/UnitDelay5'
   *  UnitDelay: '<S2>/UnitDelay6'
   */
  if (localDW->UnitDelay6_DSTATE) {
    rtb_Sum8 = ACParameter_ConstB.DataTypeConversion2;
  } else {
    rtb_Sum8 = localDW->UnitDelay5_DSTATE;
  }

  /* End of Switch: '<S2>/Switch2' */

  /* Sum: '<S2>/Sum8' */
  rtb_Sum8 += ACParameter_ConstB.DataTypeConversion;

  /* Saturate: '<S2>/Saturation1' */
  if (rtb_Sum8 > 667.0F) {
    rtb_Saturation1 = 667.0F;
  } else if (rtb_Sum8 < 250.0F) {
    rtb_Saturation1 = 250.0F;
  } else {
    rtb_Saturation1 = rtb_Sum8;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Sum: '<S3>/Sum5' incorporates:
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   *  Product: '<S3>/Product3'
   *  UnitDelay: '<S3>/UnitDelay'
   *  UnitDelay: '<S3>/UnitDelay3'
   */
  rtb_Sum5 = (((*rtu_Signal) * localDW->UnitDelay3_DSTATE) *
              ACParameter_ConstB.wt) + (ACParameter_ConstB.Sum4 *
    localDW->UnitDelay_DSTATE);

  /* Sum: '<S3>/Sum1' incorporates:
   *  Gain: '<S3>/PLL_Ki'
   *  Gain: '<S3>/PLL_Sampletime'
   *  UnitDelay: '<S3>/UnitDelay1'
   */
  rtb_Sum1 = (5.0E-5F * (PLL_Ki * rtb_Sum5)) + localDW->UnitDelay1_DSTATE;

  /* Sum: '<S3>/Sum3' incorporates:
   *  Constant: '<S3>/w_init'
   */
  rtb_Sum3 = rtb_Sum1 + 345.575195F;

  /* Gain: '<S3>/w_to_f_Gain' */
  *rty_Frequency = 0.159154937F * rtb_Sum3;

  /* Saturate: '<S2>/Saturation' */
  if ((*rty_Frequency) > 80.0F) {
    rty_Frequency_0 = 80.0F;
  } else if ((*rty_Frequency) < 30.0F) {
    rty_Frequency_0 = 30.0F;
  } else {
    rty_Frequency_0 = *rty_Frequency;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
   *  Product: '<S2>/Divide1'
   */
  rtb_RelationalOperator1 = (rtb_Saturation1 >
    (ACParameter_ConstB.DataTypeConversion3 / rty_Frequency_0));

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay3'
   */
  *rty_RMS = localDW->UnitDelay3_DSTATE_hi41;

  /* Switch: '<S2>/Switch3' */
  if (rtb_RelationalOperator1) {
    /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
     *  Product: '<S2>/Divide2'
     *  Sqrt: '<S2>/Sqrt'
     */
    *rty_RMS = sqrtf(rtb_Sum14 / rtb_Saturation1);
  }

  /* End of Switch: '<S2>/Switch3' */

  /* Switch: '<S3>/Switch5' incorporates:
   *  Constant: '<S3>/Theta_Upperlimit'
   *  RelationalOperator: '<S3>/Relational Operator2'
   *  UnitDelay: '<S3>/UnitDelay2'
   */
  if (localDW->UnitDelay2_DSTATE > 6.28318548F) {
    rtb_Saturation1 = ACParameter_ConstB.DataTypeConversion5;
  } else {
    rtb_Saturation1 = localDW->UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S3>/Switch5' */

  /* Sum: '<S3>/Sum6' incorporates:
   *  Gain: '<S3>/PLL_Kp'
   *  Gain: '<S3>/PLL_Sampletime1'
   *  Sum: '<S3>/Sum2'
   */
  *rty_Theta = (5.0E-5F * (rtb_Sum3 + (PLL_Kp * rtb_Sum5))) + rtb_Saturation1;

  /* Update for UnitDelay: '<S2>/UnitDelay6' */
  localDW->UnitDelay6_DSTATE = rtb_RelationalOperator1;

  /* Update for UnitDelay: '<S2>/UnitDelay4' */
  localDW->UnitDelay4_DSTATE = rtb_Sum14;

  /* Update for UnitDelay: '<S2>/UnitDelay5' */
  localDW->UnitDelay5_DSTATE = rtb_Sum8;

  /* Update for UnitDelay: '<S3>/UnitDelay3' incorporates:
   *  Trigonometry: '<S3>/TrigonometricFunction'
   */
  localDW->UnitDelay3_DSTATE = cosf(rtb_Saturation1);

  /* Update for UnitDelay: '<S3>/UnitDelay' */
  localDW->UnitDelay_DSTATE = rtb_Sum5;

  /* Update for UnitDelay: '<S3>/UnitDelay1' */
  localDW->UnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  localDW->UnitDelay3_DSTATE_hi41 = *rty_RMS;

  /* Update for UnitDelay: '<S3>/UnitDelay2' */
  localDW->UnitDelay2_DSTATE = *rty_Theta;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
