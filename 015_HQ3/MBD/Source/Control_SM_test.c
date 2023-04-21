/*
 * File: Control_SM_test.c
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

#include "Control_SM_test.h"
#include "Control_SM_test_private.h"
#define Control_SM_t_IN_NO_ACTIVE_CHILD (0U)
#define Control_SM_t_IN_Ramp_CV_Command (5U)
#define Control_SM_te_IN_PFC_pre_charge (3U)
#define Control_SM_tes_IN_LLC_SoftStart (2U)
#define Control_SM_tes_IN_PFC_Relay_Off (2U)
#define Control_SM_tes_IN_PFC_Relay_PWM (4U)
#define Control_SM_test_IN_LLC_Run     (1U)
#define Control_SM_test_IN_PFC_On      (1U)
#define Control_SM_test_IN_PFC_Relay_On (3U)
#define Control_SM_test_IN_PFC_Vm_Cal  (1U)
#define Control_SM_test_IN_Reset       (1U)
#define Control_SM_test_IN_Run         (2U)
#define Control__IN_Relay_On_Time_count (2U)

/* Block signals (default storage) */
B_Control_SM_test_T Control_SM_test_B;

/* Block states (default storage) */
DW_Control_SM_test_T Control_SM_test_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Control_SM_test_T Control_SM_test_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Control_SM_test_T Control_SM_test_Y;

/* Forward declaration for local functions */
static void Control_SM_test_PFC_Softstart(real32_T PFC_Vcmd, real32_T PFC_Vref);
static void Control_SM_test_Duty_Softstart(real32_T PFC_Dutycmd, real32_T
  PFC_Dutyref);
static void Control_SM_t_enter_atomic_Reset(void);
static real32_T Control_SM_test_SoftStart(real32_T flRef, real32_T flCmd,
  real32_T flSoftValue);
static void Control_SM_test_Run(const boolean_T *PFC_steady, const boolean_T
  *Precharge);

/* Function for Chart: '<S3>/Control_state_machine' */
static void Control_SM_test_PFC_Softstart(real32_T PFC_Vcmd, real32_T PFC_Vref)
{
  if (PFC_Vcmd < PFC_Vref) {
    /* Update for Outport: '<Root>/PFC_Vcmd_Out' */
    Control_SM_test_Y.PFC_Vcmd_Out = PFC_Vcmd + Control_SM_test_DW.PFC_Vsoft;
  } else {
    /* Update for Outport: '<Root>/PFC_Vcmd_Out' */
    Control_SM_test_Y.PFC_Vcmd_Out = PFC_Vref;
  }
}

/* Function for Chart: '<S3>/Control_state_machine' */
static void Control_SM_test_Duty_Softstart(real32_T PFC_Dutycmd, real32_T
  PFC_Dutyref)
{
  if (PFC_Dutycmd < PFC_Dutyref) {
    /* Outport: '<Root>/PFC_Duty_Out' */
    Control_SM_test_Y.PFC_Duty_Out = PFC_Dutycmd +
      Control_SM_test_DW.PFC_Dutysoft;
  } else {
    /* Outport: '<Root>/PFC_Duty_Out' */
    Control_SM_test_Y.PFC_Duty_Out = PFC_Dutyref;
  }
}

/* Function for Chart: '<S3>/Control_state_machine' */
static void Control_SM_t_enter_atomic_Reset(void)
{
  /* Outport: '<Root>/PFC_PWM_On' */
  Control_SM_test_Y.PFC_PWM_On = (boolean_T)0;

  /* Outport: '<Root>/LLC_PWM_On' */
  Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

  /* Outport: '<Root>/PFC_Isw_cmd_Init' */
  Control_SM_test_Y.PFC_Isw_cmd_Init = 0.0F;

  /* Outport: '<Root>/PFC_Duty_Init' */
  Control_SM_test_Y.PFC_Duty_Init = 0.0F;

  /* Outport: '<Root>/PFC_Reset' */
  Control_SM_test_Y.PFC_Reset = (boolean_T)1;

  /* Outport: '<Root>/LLC_Reset' */
  Control_SM_test_Y.LLC_Reset = (boolean_T)1;

  /* Outport: '<Root>/Relay_PWM_CMPB' */
  Control_SM_test_Y.Relay_PWM_CMPB = 0.0F;

  /* Update for Outport: '<Root>/PFC_Vcmd_Out' */
  Control_SM_test_Y.PFC_Vcmd_Out = 100.0F;

  /* Outport: '<Root>/flLLCVoltRef' */
  Control_SM_test_Y.flLLCVoltRef = 0.0F;

  /* Outport: '<Root>/flLLCCurrRef' */
  Control_SM_test_Y.flLLCCurrRef = 0.0F;

  /* Outport: '<Root>/wLLCMinDuty' */
  Control_SM_test_Y.wLLCMinDuty = 330U;
}

/* Function for Chart: '<S3>/Control_state_machine' */
static real32_T Control_SM_test_SoftStart(real32_T flRef, real32_T flCmd,
  real32_T flSoftValue)
{
  real32_T flRefOut;
  if (flRef < flCmd) {
    flRefOut = flRef + flSoftValue;
  } else if (flRef > flCmd) {
    flRefOut = flRef - flSoftValue;
  } else {
    flRefOut = flCmd;
  }

  return flRefOut;
}

/* Function for Chart: '<S3>/Control_state_machine' */
static void Control_SM_test_Run(const boolean_T *PFC_steady, const boolean_T
  *Precharge)
{
  /* Inport: '<Root>/blReqCtrlOn' incorporates:
   *  Inport: '<Root>/PhyValueOut_PFC'
   */
  if ((!Control_SM_test_U.blReqCtrlOn) ||
      (Control_SM_test_U.PhyValueOut_PFC_nm4g.GridVoltRms < 80.0F)) {
    Control_SM_test_DW.is_PFC_pre_charge = Control_SM_t_IN_NO_ACTIVE_CHILD;
    Control_SM_test_DW.is_Run = Control_SM_t_IN_NO_ACTIVE_CHILD;
    Control_SM_test_DW.is_c3_Control_SM_test = Control_SM_test_IN_Reset;
    Control_SM_t_enter_atomic_Reset();
  } else {
    switch (Control_SM_test_DW.is_Run) {
     case Control_SM_test_IN_LLC_Run:
      /* Outport: '<Root>/PFC_PWM_On' */
      Control_SM_test_Y.PFC_PWM_On = (boolean_T)1;

      /* Outport: '<Root>/LLC_PWM_On' */
      Control_SM_test_Y.LLC_PWM_On = (boolean_T)1;

      /* Outport: '<Root>/LLC_Reset' */
      Control_SM_test_Y.LLC_Reset = (boolean_T)0;

      /* Outport: '<Root>/Relay_PWM_CMPB' */
      Control_SM_test_Y.Relay_PWM_CMPB = 1250.0F;

      /* Outport: '<Root>/flLLCVoltRef' incorporates:
       *  Inport: '<Root>/flLLCVoltCmd'
       */
      Control_SM_test_Y.flLLCVoltRef = Control_SM_test_U.flLLCVoltCmd;

      /* Outport: '<Root>/flLLCCurrRef' incorporates:
       *  Inport: '<Root>/flLLCCurrCmd'
       */
      Control_SM_test_Y.flLLCCurrRef = Control_SM_test_SoftStart
        (Control_SM_test_Y.flLLCCurrRef, Control_SM_test_U.flLLCCurrCmd,
         Control_SM_test_DW.flCurrSoft);

      /* Outport: '<Root>/wLLCMinDuty' */
      Control_SM_test_Y.wLLCMinDuty = 417U;
      break;

     case Control_SM_tes_IN_LLC_SoftStart:
      /* Outport: '<Root>/flLLCVoltRef' incorporates:
       *  Inport: '<Root>/flLLCVoltCmd'
       *  Outport: '<Root>/LLC_PWM_On'
       *  Outport: '<Root>/LLC_Reset'
       *  Outport: '<Root>/PFC_PWM_On'
       *  Outport: '<Root>/PFC_Reset'
       *  Outport: '<Root>/Relay_PWM_CMPB'
       *  Outport: '<Root>/flLLCCurrRef'
       *  Outport: '<Root>/wLLCMinDuty'
       */
      if (Control_SM_test_Y.flLLCVoltRef >= Control_SM_test_U.flLLCVoltCmd) {
        Control_SM_test_DW.is_Run = Control_SM_test_IN_LLC_Run;
      } else {
        Control_SM_test_Y.PFC_PWM_On = (boolean_T)1;
        Control_SM_test_Y.LLC_PWM_On = (boolean_T)1;
        Control_SM_test_Y.PFC_Reset = (boolean_T)0;
        Control_SM_test_Y.LLC_Reset = (boolean_T)0;
        Control_SM_test_Y.Relay_PWM_CMPB = 1250.0F;
        Control_SM_test_Y.flLLCVoltRef += Control_SM_test_DW.flVoltSoft;
        Control_SM_test_Y.flLLCCurrRef = 1.0F;
        Control_SM_test_Y.wLLCMinDuty = 330U;
      }
      break;

     default:
      /* case IN_PFC_pre_charge: */
      if ((Control_SM_test_DW.temporalCounter_i2 >= 200000UL) && (!(*Precharge)))
      {
        Control_SM_test_DW.is_PFC_pre_charge = Control_SM_t_IN_NO_ACTIVE_CHILD;
        Control_SM_test_DW.is_Run = Control_SM_t_IN_NO_ACTIVE_CHILD;
        Control_SM_test_DW.is_c3_Control_SM_test = Control_SM_test_IN_Reset;
        Control_SM_t_enter_atomic_Reset();
      } else {
        switch (Control_SM_test_DW.is_PFC_pre_charge) {
         case Control_SM_test_IN_PFC_On:
          if (Control_SM_test_DW.temporalCounter_i1 >= 19600U) {
            Control_SM_test_DW.is_PFC_pre_charge =
              Control_SM_tes_IN_PFC_Relay_PWM;
            Control_SM_test_DW.temporalCounter_i1 = 0U;
          } else {
            /* Outport: '<Root>/PFC_PWM_On' */
            Control_SM_test_Y.PFC_PWM_On = (boolean_T)1;

            /* Outport: '<Root>/LLC_PWM_On' */
            Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/PFC_Reset' */
            Control_SM_test_Y.PFC_Reset = (boolean_T)0;

            /* Outport: '<Root>/LLC_Reset' */
            Control_SM_test_Y.LLC_Reset = (boolean_T)1;

            /* Outport: '<Root>/Relay_PWM_CMPB' */
            Control_SM_test_Y.Relay_PWM_CMPB = 2600.0F;

            /* Update for Outport: '<Root>/PFC_Vcmd_Out' */
            Control_SM_test_PFC_Softstart(Control_SM_test_Y.PFC_Vcmd_Out, 400.0F);

            /* Outport: '<Root>/PFC_Duty_Out' */
            Control_SM_test_Duty_Softstart(Control_SM_test_Y.PFC_Duty_Out, 1.0F);

            /* Outport: '<Root>/flLLCVoltRef' */
            Control_SM_test_Y.flLLCVoltRef = 0.0F;

            /* Outport: '<Root>/flLLCCurrRef' */
            Control_SM_test_Y.flLLCCurrRef = 0.0F;

            /* Outport: '<Root>/wLLCMinDuty' */
            Control_SM_test_Y.wLLCMinDuty = 330U;
          }
          break;

         case Control_SM_tes_IN_PFC_Relay_Off:
          if (Control_SM_test_DW.temporalCounter_i1 >= 10000U) {
            Control_SM_test_DW.is_PFC_pre_charge =
              Control_SM_test_IN_PFC_Relay_On;
            Control_SM_test_DW.temporalCounter_i1 = 0U;
          } else {
            /* Outport: '<Root>/PFC_PWM_On' */
            Control_SM_test_Y.PFC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/LLC_PWM_On' */
            Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/PFC_Reset' */
            Control_SM_test_Y.PFC_Reset = (boolean_T)1;

            /* Outport: '<Root>/LLC_Reset' */
            Control_SM_test_Y.LLC_Reset = (boolean_T)1;

            /* Outport: '<Root>/Relay_PWM_CMPB' */
            Control_SM_test_Y.Relay_PWM_CMPB = 0.0F;

            /* Outport: '<Root>/flLLCVoltRef' */
            Control_SM_test_Y.flLLCVoltRef = 0.0F;

            /* Outport: '<Root>/flLLCCurrRef' */
            Control_SM_test_Y.flLLCCurrRef = 0.0F;

            /* Outport: '<Root>/wLLCMinDuty' */
            Control_SM_test_Y.wLLCMinDuty = 330U;
          }
          break;

         case Control_SM_test_IN_PFC_Relay_On:
          if (Control_SM_test_DW.temporalCounter_i1 >= 400U) {
            Control_SM_test_DW.is_PFC_pre_charge = Control_SM_test_IN_PFC_On;
            Control_SM_test_DW.temporalCounter_i1 = 0U;
          } else {
            /* Outport: '<Root>/PFC_PWM_On' */
            Control_SM_test_Y.PFC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/LLC_PWM_On' */
            Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/PFC_Reset' */
            Control_SM_test_Y.PFC_Reset = (boolean_T)1;

            /* Outport: '<Root>/LLC_Reset' */
            Control_SM_test_Y.LLC_Reset = (boolean_T)1;

            /* Outport: '<Root>/Relay_PWM_CMPB' */
            Control_SM_test_Y.Relay_PWM_CMPB = 2600.0F;

            /* Outport: '<Root>/flLLCVoltRef' */
            Control_SM_test_Y.flLLCVoltRef = 0.0F;

            /* Outport: '<Root>/flLLCCurrRef' */
            Control_SM_test_Y.flLLCCurrRef = 0.0F;

            /* Outport: '<Root>/wLLCMinDuty' */
            Control_SM_test_Y.wLLCMinDuty = 330U;
          }
          break;

         case Control_SM_tes_IN_PFC_Relay_PWM:
          if ((Control_SM_test_DW.temporalCounter_i1 >= 8000U) && (*PFC_steady))
          {
            Control_SM_test_DW.is_PFC_pre_charge =
              Control_SM_t_IN_NO_ACTIVE_CHILD;
            Control_SM_test_DW.is_Run = Control_SM_tes_IN_LLC_SoftStart;
          } else {
            /* Outport: '<Root>/PFC_PWM_On' */
            Control_SM_test_Y.PFC_PWM_On = (boolean_T)1;

            /* Outport: '<Root>/LLC_PWM_On' */
            Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/PFC_Reset' */
            Control_SM_test_Y.PFC_Reset = (boolean_T)0;

            /* Outport: '<Root>/LLC_Reset' */
            Control_SM_test_Y.LLC_Reset = (boolean_T)1;

            /* Outport: '<Root>/Relay_PWM_CMPB' */
            Control_SM_test_Y.Relay_PWM_CMPB = 1250.0F;

            /* Update for Outport: '<Root>/PFC_Vcmd_Out' */
            Control_SM_test_PFC_Softstart(Control_SM_test_Y.PFC_Vcmd_Out, 400.0F);

            /* Outport: '<Root>/flLLCVoltRef' */
            Control_SM_test_Y.flLLCVoltRef = 0.0F;

            /* Outport: '<Root>/flLLCCurrRef' */
            Control_SM_test_Y.flLLCCurrRef = 0.0F;

            /* Outport: '<Root>/wLLCMinDuty' */
            Control_SM_test_Y.wLLCMinDuty = 330U;
          }
          break;

         default:
          /* case IN_Ramp_CV_Command: */
          if ((Control_SM_test_B.Relay_On) &&
              (Control_SM_test_U.PhyValueOut_PFC_nm4g.GridVoltRms > 80.0F)) {
            Control_SM_test_DW.is_PFC_pre_charge =
              Control_SM_tes_IN_PFC_Relay_Off;
            Control_SM_test_DW.temporalCounter_i1 = 0U;
          } else {
            /* Outport: '<Root>/PFC_PWM_On' */
            Control_SM_test_Y.PFC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/LLC_PWM_On' */
            Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

            /* Outport: '<Root>/PFC_Reset' */
            Control_SM_test_Y.PFC_Reset = (boolean_T)1;

            /* Outport: '<Root>/LLC_Reset' */
            Control_SM_test_Y.LLC_Reset = (boolean_T)1;

            /* Outport: '<Root>/Relay_PWM_CMPB' */
            Control_SM_test_Y.Relay_PWM_CMPB = 0.0F;

            /* Outport: '<Root>/flLLCVoltRef' */
            Control_SM_test_Y.flLLCVoltRef = 0.0F;

            /* Outport: '<Root>/flLLCCurrRef' */
            Control_SM_test_Y.flLLCCurrRef = 0.0F;

            /* Outport: '<Root>/wLLCMinDuty' */
            Control_SM_test_Y.wLLCMinDuty = 330U;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Inport: '<Root>/blReqCtrlOn' */
}

/* Model step function */
#pragma CODE_SECTION(Control_SM_test_step,".TI.ramfunc");
void Control_SM_test_step(void)
{
  boolean_T PFC_steady;
  boolean_T Precharge;

  /* Logic: '<S2>/Logical Operator1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  RelationalOperator: '<S2>/Relational Operator2'
   *  RelationalOperator: '<S2>/Relational Operator3'
   *  RelationalOperator: '<S2>/Relational Operator4'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  PFC_steady = (((Control_SM_test_DW.UnitDelay3_DSTATE >= ((real32_T)400U)) &&
                 (Control_SM_test_U.PhyValueOut_PFC_nm4g.PFCVolt <= ((real32_T)
    Control_SM_test_ConstB.Sum2))) &&
                (Control_SM_test_U.PhyValueOut_PFC_nm4g.PFCVolt >= ((real32_T)
    Control_SM_test_ConstB.Sum3)));

  /* RelationalOperator: '<S2>/Relational Operator' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant8'
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Sum'
   */
  Precharge = (Control_SM_test_U.PhyValueOut_PFC_nm4g.PFCVolt >=
               ((Control_SM_test_U.PhyValueOut_PFC_nm4g.GridVoltRms * 1.414F) -
                ((real32_T)4U)));

  /* Chart: '<S2>/Chart' incorporates:
   *  Inport: '<Root>/PhyValueOut_PFC'
   */
  if (Control_SM_test_DW.is_active_c1_Control_SM_test == 0U) {
    Control_SM_test_DW.is_active_c1_Control_SM_test = 1U;
    Control_SM_test_DW.is_c1_Control_SM_test = Control_SM_test_IN_PFC_Vm_Cal;
  } else if (Control_SM_test_DW.is_c1_Control_SM_test == 1U) {
    if (Control_SM_test_U.PhyValueOut_PFC_nm4g.PFCVolt >
        Control_SM_test_DW.PFC_Vm) {
      Control_SM_test_DW.is_c1_Control_SM_test = Control__IN_Relay_On_Time_count;
    } else {
      Control_SM_test_DW.PFC_Vm =
        (Control_SM_test_U.PhyValueOut_PFC_nm4g.GridVoltRms * 1.414F) * 0.8F;
      Control_SM_test_B.Relay_On = (boolean_T)0;
    }
  } else {
    /* case IN_Relay_On_Time_count: */
    Control_SM_test_DW.PFC_Vm =
      (Control_SM_test_U.PhyValueOut_PFC_nm4g.GridVoltRms * 1.414F) * 0.8F;
    Control_SM_test_B.Relay_On = (boolean_T)1;
  }

  /* End of Chart: '<S2>/Chart' */

  /* Chart: '<S3>/Control_state_machine' incorporates:
   *  Inport: '<Root>/PhyValueOut_PFC'
   *  Inport: '<Root>/blReqCtrlOn'
   */
  if (Control_SM_test_DW.temporalCounter_i1 < 32767U) {
    Control_SM_test_DW.temporalCounter_i1 = (uint16_T)((uint32_T)(((uint32_T)
      Control_SM_test_DW.temporalCounter_i1) + 1UL));
  }

  if (Control_SM_test_DW.temporalCounter_i2 < 262143UL) {
    Control_SM_test_DW.temporalCounter_i2++;
  }

  if (Control_SM_test_DW.is_active_c3_Control_SM_test == 0U) {
    Control_SM_test_DW.is_active_c3_Control_SM_test = 1U;
    Control_SM_test_DW.is_c3_Control_SM_test = Control_SM_test_IN_Reset;
    Control_SM_t_enter_atomic_Reset();
  } else if (Control_SM_test_DW.is_c3_Control_SM_test == 1U) {
    if ((Control_SM_test_U.blReqCtrlOn) &&
        (Control_SM_test_U.PhyValueOut_PFC_nm4g.GridVoltRms > 80.0F)) {
      Control_SM_test_DW.is_c3_Control_SM_test = Control_SM_test_IN_Run;
      Control_SM_test_DW.is_Run = Control_SM_te_IN_PFC_pre_charge;
      Control_SM_test_DW.temporalCounter_i2 = 0UL;
      Control_SM_test_DW.is_PFC_pre_charge = Control_SM_t_IN_Ramp_CV_Command;
    } else {
      /* Outport: '<Root>/PFC_PWM_On' */
      Control_SM_test_Y.PFC_PWM_On = (boolean_T)0;

      /* Outport: '<Root>/LLC_PWM_On' */
      Control_SM_test_Y.LLC_PWM_On = (boolean_T)0;

      /* Outport: '<Root>/PFC_Isw_cmd_Init' */
      Control_SM_test_Y.PFC_Isw_cmd_Init = 0.0F;

      /* Outport: '<Root>/PFC_Duty_Init' */
      Control_SM_test_Y.PFC_Duty_Init = 0.0F;

      /* Outport: '<Root>/PFC_Reset' */
      Control_SM_test_Y.PFC_Reset = (boolean_T)1;

      /* Outport: '<Root>/LLC_Reset' */
      Control_SM_test_Y.LLC_Reset = (boolean_T)1;

      /* Outport: '<Root>/Relay_PWM_CMPB' */
      Control_SM_test_Y.Relay_PWM_CMPB = 0.0F;

      /* Outport: '<Root>/PFC_Vcmd_Out' */
      Control_SM_test_Y.PFC_Vcmd_Out = 100.0F;

      /* Outport: '<Root>/flLLCVoltRef' */
      Control_SM_test_Y.flLLCVoltRef = 0.0F;

      /* Outport: '<Root>/flLLCCurrRef' */
      Control_SM_test_Y.flLLCCurrRef = 0.0F;

      /* Outport: '<Root>/wLLCMinDuty' */
      Control_SM_test_Y.wLLCMinDuty = 330U;
    }
  } else {
    /* case IN_Run: */
    Control_SM_test_Run(&PFC_steady, &Precharge);
  }

  /* End of Chart: '<S3>/Control_state_machine' */

  /* Update for UnitDelay: '<S1>/Unit Delay3' incorporates:
   *  Outport: '<Root>/PFC_Vcmd_Out'
   */
  Control_SM_test_DW.UnitDelay3_DSTATE = Control_SM_test_Y.PFC_Vcmd_Out;
}

/* Model initialize function */
void Control_SM_test_initialize(void)
{
  /* SystemInitialize for Chart: '<S3>/Control_state_machine' */
  Control_SM_test_DW.flCurrSoft = 0.0002F;
  Control_SM_test_DW.flVoltSoft = 0.1F;
  Control_SM_test_DW.PFC_Vsoft = 0.03F;
  Control_SM_test_DW.PFC_Dutysoft = 0.0001F;

  /* SystemInitialize for Outport: '<Root>/PFC_Vcmd_Out' incorporates:
   *  Chart: '<S3>/Control_state_machine'
   */
  Control_SM_test_Y.PFC_Vcmd_Out = 100.0F;

  /* SystemInitialize for Outport: '<Root>/PFC_Duty_Out' incorporates:
   *  Chart: '<S3>/Control_state_machine'
   */
  Control_SM_test_Y.PFC_Duty_Out = 0.3F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
