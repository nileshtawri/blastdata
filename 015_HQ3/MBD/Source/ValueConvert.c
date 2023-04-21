/*
 * File: ValueConvert.c
 *
 * Code generated for Simulink model 'ValueConvert'.
 *
 * Model version                  : 1.189
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu May 26 13:49:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ValueConvert.h"
#include "ValueConvert_private.h"
#include "LookUp_real32_T_U16.h"

/* System initialize for referenced model: 'ValueConvert' */
void ValueConvert_Init(real32_T *rty_Value)
{
  /* SystemInitialize for Merge: '<S3>/Merge' */
  *rty_Value = 0.0F;
}

/* Output and update for referenced model: 'ValueConvert' */
void ValueConvert(const uint16_T *rtu_Adc, const real32_T rtu_LUT[166], const
                  uint16_T rtu_Index[166], const ConversionParameter
                  *rtu_ConversionParameter, real32_T *rty_Value,
                  DW_ValueConvert_fwu4_T *localDW)
{
  /* local block i/o variables */
  real32_T rtb_LookupTableDynamic;
  real32_T rtb_Product;

  /* If: '<S2>/If' */
  if (rtu_ConversionParameter->Conversion == 1U) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* S-Function (sfix_look1_dyn): '<S5>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S5>/Lookup Table Dynamic'
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Integer        U16
     * Input2  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real32_T_U16( &(rtb_LookupTableDynamic), &rtu_LUT[0], (*rtu_Adc),
                        &rtu_Index[0], 165U);

    /* SignalConversion generated from: '<S5>/PhyValue' */
    rtb_Product = rtb_LookupTableDynamic;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Product: '<S6>/Product' incorporates:
     *  Sum: '<S6>/Add'
     */
    rtb_Product = (((real32_T)(*rtu_Adc)) - rtu_ConversionParameter->Offset) *
      rtu_ConversionParameter->Gain;

    /* End of Outputs for SubSystem: '<S2>/Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* Product: '<S4>/Product' */
  rtb_Product *= rtu_ConversionParameter->CaliGain;

  /* If: '<S3>/If' incorporates:
   *  Inport: '<S8>/Value'
   *  Sum: '<S4>/Add'
   */
  if (rtu_ConversionParameter->FilterEnable) {
    /* Outputs for IfAction SubSystem: '<S3>/Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S7>/Constant'
     *  Product: '<S7>/Product'
     *  Product: '<S7>/Product2'
     *  Sum: '<S4>/Add'
     *  Sum: '<S7>/Add1'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    rtb_Product = ((rtb_Product + rtu_ConversionParameter->CaliOffset) * (1.0F -
      rtu_ConversionParameter->FilterA)) + (rtu_ConversionParameter->FilterA *
      localDW->UnitDelay_DSTATE);

    /* SignalConversion generated from: '<S7>/ValueOut' */
    *rty_Value = rtb_Product;

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    localDW->UnitDelay_DSTATE = rtb_Product;

    /* End of Outputs for SubSystem: '<S3>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S3>/Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    *rty_Value = rtb_Product + rtu_ConversionParameter->CaliOffset;

    /* End of Outputs for SubSystem: '<S3>/Subsystem1' */
  }

  /* End of If: '<S3>/If' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
