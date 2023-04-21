/*
 * File: General_PFC_Control_Loop.c
 *
 * Code generated for Simulink model 'General_PFC_Control_Loop'.
 *
 * Model version                  : 1.262
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Apr 28 11:35:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "General_PFC_Control_Loop.h"
#include "General_PFC_Control_Loop_private.h"

/* Exported block parameters */
real32_T Full_load_Lo = 0.0F;        /* Variable: Full_load_Lo
                                        * Referenced by: '<S3>/Constant6'
                                        */
real32_T Full_load_Up = 100.0F;         /* Variable: Full_load_Up
                                        * Referenced by: '<S3>/Constant5'
                                        */
real32_T PFC_Duty_Lower_limit = 0.0F; /* Variable: PFC_Duty_Lower_limit
                                        * Referenced by:
                                        *   '<S2>/Saturation5'
                                        *   '<S2>/Saturation6'
                                        *   '<S2>/Saturation7'
                                        *   '<S2>/Saturation8'
                                        */
real32_T PFC_Duty_Upper_limit = 0.95F; /* Variable: PFC_Duty_Upper_limit
                                        * Referenced by:
                                        *   '<S2>/Saturation5'
                                        *   '<S2>/Saturation6'
                                        *   '<S2>/Saturation7'
                                        *   '<S2>/Saturation8'
                                        */
real32_T PFC_IKi = 5.0F * 0.00005*10;               /* Variable: PFC_IKi
                                        * Referenced by:
                                        *   '<S2>/Constant13'
                                        *   '<S2>/Constant14'
                                        *   '<S2>/Constant3'
                                        *   '<S2>/Constant7'
                                        */
real32_T PFC_IKp = 0.8F * 0.01;           /* Variable: PFC_IKp
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S2>/Constant11'
                                        *   '<S2>/Constant12'
                                        *   '<S2>/Constant2'
                                        * 0.0096*3.1
                                        */
real32_T PFC_Isw_cmd_AB_Gain = 0.25F;  /* Variable: PFC_Isw_cmd_AB_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
real32_T PFC_VKi = 2.50F * 0.01*0.01;             /* Variable: PFC_VKi 2.5
                                        * Referenced by: '<S3>/Constant3'
                                        * 600*1.5
                                        */
real32_T PFC_VKp = 18.0F * 0.01;              /* Variable: PFC_VKp 18.0
                                        * Referenced by: '<S3>/Constant1'
                                        * 0.1*0.7
                                        */

/* Block states (default storage) */
DW_General_PFC_Control_Loop_T General_PFC_Control_Loop_DW;

/* External inputs (root inport signals with default storage) */
ExtU_General_PFC_Control_Loop_T General_PFC_Control_Loop_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_General_PFC_Control_Loop_T General_PFC_Control_Loop_Y;

/* Model step function */
#pragma CODE_SECTION(General_PFC_Control_Loop_step,".TI.ramfunc");
void General_PFC_Control_Loop_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Switch_cjrf;
  real32_T rtb_Vrect_Duty;
  real32_T rtb_PFC_Duty_D;
  real32_T rtb_flError;
  real32_T rtb_flFB_bafc;
  real32_T rtb_flError_lzc5;
  real32_T rtb_flError_i1mh;
  real32_T rtb_flKpterm_kxrl;
  real32_T rtb_flError_pk14;
  real32_T rtb_flError_last1;
  real32_T rtb_Add4;
  real32_T rtb_flError_last1_atj4;
  real32_T rtb_Add5_h4a2;
  real32_T rtb_flError_last1_by1z;
  real32_T rtb_Add5_htt5;
  real32_T rtb_flError_last1_h5sj;
  real32_T rtb_flError_last1_dbec;
  real32_T rtb_flKpterm_mzov_tmp;

  /* Abs: '<S1>/Abs' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/GridTheta'
   *  Inport: '<Root>/PFC_Vrms'
   *  Product: '<S1>/Product'
   *  Trigonometry: '<S1>/Sin'
   */
  rtb_Vrect_Duty = fabsf(sinf(General_PFC_Control_Loop_U.GridTheta) * (1.414F *
    General_PFC_Control_Loop_U.PFC_Vrms));

  /* Product: '<S2>/Product7' incorporates:
   *  Inport: '<Root>/PFC_Duty_Out'
   *  Inport: '<Root>/PFC_Vo'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Sum15'
   *  Sum: '<S2>/Sum16'
   */
  rtb_PFC_Duty_D = ((General_PFC_Control_Loop_U.PFC_Vo - rtb_Vrect_Duty) /
                    (General_PFC_Control_Loop_U.PFC_Vo +
                     General_PFC_Control_Loop_ConstB.DataTypeConversion)) *
    General_PFC_Control_Loop_U.PFC_Duty_Out;

  /* SignalConversion: '<S3>/SignalConversion1' incorporates:
   *  Inport: '<Root>/PFC_Vo'
   */
  rtb_Switch_cjrf = General_PFC_Control_Loop_U.PFC_Vo;

  /* Sum: '<S12>/Add' incorporates:
   *  Inport: '<Root>/PFC_Vcmd_Out'
   */
  rtb_flError = General_PFC_Control_Loop_U.PFC_Vcmd_Out - rtb_Switch_cjrf;

  /* UnitDelay: '<S12>/UnitDelay' */
  rtb_flError_last1 = General_PFC_Control_Loop_DW.UnitDelay_DSTATE;

  /* DataTypeConversion: '<S12>/DataTypeConversion5' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  rtb_Switch_cjrf = PFC_VKi;

  /* Sum: '<S12>/Add2' incorporates:
   *  Sum: '<S12>/Add6'
   *  UnitDelay: '<S12>/UnitDelay'
   */
  rtb_flError_last1_atj4 = rtb_flError -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE;

  /* Sum: '<S12>/Add4' incorporates:
   *  Constant: '<S3>/Constant1'
   *  DataTypeConversion: '<S12>/DataTypeConversion4'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Add2'
   */
  rtb_Add4 = (PFC_VKp * rtb_flError_last1_atj4) + (rtb_Switch_cjrf * rtb_flError);

  /* Switch: '<S12>/Switch' incorporates:
   *  Inport: '<Root>/PFC_Isw_cmd_Init'
   *  Inport: '<Root>/PFC_Reset'
   *  UnitDelay: '<S12>/UnitDelay2'
   */
  if (General_PFC_Control_Loop_U.PFC_Reset) {
    rtb_Switch_cjrf = General_PFC_Control_Loop_U.PFC_Isw_cmd_Init;
  } else {
    rtb_Switch_cjrf = General_PFC_Control_Loop_DW.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Sum: '<S12>/Add5' incorporates:
   *  Product: '<S12>/Product2'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Add3'
   *  Sum: '<S12>/Add7'
   *  UnitDelay: '<S12>/UnitDelay'
   *  UnitDelay: '<S12>/UnitDelay1'
   */
  rtb_Add4 = (rtb_Add4 + (General_PFC_Control_Loop_ConstB.flKd_makw *
    ((rtb_flError_last1_atj4 - General_PFC_Control_Loop_DW.UnitDelay_DSTATE) +
     General_PFC_Control_Loop_DW.UnitDelay1_DSTATE))) + rtb_Switch_cjrf;

  /* DataTypeConversion: '<S12>/DataTypeConversion8' incorporates:
   *  Constant: '<S3>/Constant6'
   */
  rtb_Switch_cjrf = Full_load_Lo;

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S3>/Constant5'
   *  DataTypeConversion: '<S12>/DataTypeConversion7'
   *  RelationalOperator: '<S13>/LowerRelop1'
   *  RelationalOperator: '<S13>/UpperRelop'
   *  Switch: '<S13>/Switch'
   */
  if (rtb_Add4 > Full_load_Up) {
    rtb_Add4 = Full_load_Up;
  } else {
    if (rtb_Add4 < rtb_Switch_cjrf) {
      /* Switch: '<S13>/Switch' */
      rtb_Add4 = rtb_Switch_cjrf;
    }
  }

  /* End of Switch: '<S13>/Switch2' */

  /* SignalConversion: '<S3>/SignalConversion5' */
  rtb_Switch_cjrf = rtb_Add4;

  /* Sum: '<S3>/Sum12' incorporates:
   *  Inport: '<Root>/PFC_Vrms'
   */
  rtb_flFB_bafc = General_PFC_Control_Loop_U.PFC_Vrms +
    General_PFC_Control_Loop_ConstB.DataTypeConversion_hkvo;

  /* Gain: '<S3>/Gain2' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Product: '<S3>/Divide'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product3'
   */
  rtb_Switch_cjrf = PFC_Isw_cmd_AB_Gain * (90.0F * ((rtb_Switch_cjrf *
    (General_PFC_Control_Loop_ConstB.DataTypeConversion_phn1 / (rtb_flFB_bafc *
    rtb_flFB_bafc))) * rtb_Vrect_Duty));

  /* Sum: '<S4>/Add' incorporates:
   *  Inport: '<Root>/PFC_Isw_A'
   *  SignalConversion: '<S2>/SignalConversion'
   */
  rtb_Vrect_Duty = rtb_Switch_cjrf - General_PFC_Control_Loop_U.PFC_Isw_A;

  /* UnitDelay: '<S4>/UnitDelay' */
  rtb_flError_last1_atj4 = General_PFC_Control_Loop_DW.UnitDelay_DSTATE_o1mb;

  /* Switch: '<S4>/Switch' incorporates:
   *  Inport: '<Root>/PFC_Duty_Init'
   *  Inport: '<Root>/PFC_Reset'
   *  UnitDelay: '<S4>/UnitDelay2'
   */
  if (General_PFC_Control_Loop_U.PFC_Reset) {
    rtb_flFB_bafc = General_PFC_Control_Loop_U.PFC_Duty_Init;
  } else {
    rtb_flFB_bafc = General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_jw05;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/Add2' incorporates:
   *  Sum: '<S4>/Add6'
   *  UnitDelay: '<S4>/UnitDelay'
   */
  rtb_Add5_h4a2 = rtb_Vrect_Duty -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE_o1mb;

  /* Sum: '<S4>/Add5' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant3'
   *  DataTypeConversion: '<S4>/DataTypeConversion4'
   *  DataTypeConversion: '<S4>/DataTypeConversion5'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product2'
   *  Sum: '<S4>/Add1'
   *  Sum: '<S4>/Add2'
   *  Sum: '<S4>/Add3'
   *  Sum: '<S4>/Add4'
   *  Sum: '<S4>/Add7'
   *  UnitDelay: '<S4>/UnitDelay'
   *  UnitDelay: '<S4>/UnitDelay1'
   */
  rtb_Add5_h4a2 = (((PFC_IKp * rtb_Add5_h4a2) + (PFC_IKi * rtb_Vrect_Duty)) +
                   (General_PFC_Control_Loop_ConstB.flKd * ((rtb_Add5_h4a2 -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE_o1mb) +
    General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_ere2))) + rtb_flFB_bafc;

  /* Switch: '<S8>/Switch2' incorporates:
   *  RelationalOperator: '<S8>/LowerRelop1'
   *  RelationalOperator: '<S8>/UpperRelop'
   *  Switch: '<S8>/Switch'
   */
  if (rtb_Add5_h4a2 > General_PFC_Control_Loop_ConstB.flUpLimtit) {
    rtb_Add5_h4a2 = General_PFC_Control_Loop_ConstB.flUpLimtit;
  } else {
    if (rtb_Add5_h4a2 < General_PFC_Control_Loop_ConstB.flLowLimit) {
      /* Switch: '<S8>/Switch' */
      rtb_Add5_h4a2 = General_PFC_Control_Loop_ConstB.flLowLimit;
    }
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Sum: '<S2>/Sum7' */
  rtb_flError_pk14 = rtb_PFC_Duty_D + rtb_Add5_h4a2;

  /* Saturate: '<S2>/Saturation5' */
  if (rtb_flError_pk14 > PFC_Duty_Upper_limit) {
    /* Outport: '<Root>/PFC_Duty_A' */
    General_PFC_Control_Loop_Y.PFC_Duty_A = PFC_Duty_Upper_limit;
  } else if (rtb_flError_pk14 < PFC_Duty_Lower_limit) {
    /* Outport: '<Root>/PFC_Duty_A' */
    General_PFC_Control_Loop_Y.PFC_Duty_A = PFC_Duty_Lower_limit;
  } else {
    /* Outport: '<Root>/PFC_Duty_A' */
    General_PFC_Control_Loop_Y.PFC_Duty_A = rtb_flError_pk14;
  }

  /* End of Saturate: '<S2>/Saturation5' */
  /* Sum: '<S5>/Add' incorporates:
   *  Inport: '<Root>/PFC_Isw_B'
   *  SignalConversion: '<S2>/SignalConversion4'
   */
  rtb_flError_lzc5 = rtb_Switch_cjrf - General_PFC_Control_Loop_U.PFC_Isw_B;

  /* UnitDelay: '<S5>/UnitDelay' */
  rtb_flError_last1_by1z = General_PFC_Control_Loop_DW.UnitDelay_DSTATE_bqwv;

  /* Switch: '<S5>/Switch' incorporates:
   *  Inport: '<Root>/PFC_Duty_Init'
   *  Inport: '<Root>/PFC_Reset'
   *  UnitDelay: '<S5>/UnitDelay2'
   */
  if (General_PFC_Control_Loop_U.PFC_Reset) {
    rtb_flFB_bafc = General_PFC_Control_Loop_U.PFC_Duty_Init;
  } else {
    rtb_flFB_bafc = General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_ptk1;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Sum: '<S5>/Add2' incorporates:
   *  Sum: '<S5>/Add6'
   *  UnitDelay: '<S5>/UnitDelay'
   */
  rtb_Add5_htt5 = rtb_flError_lzc5 -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE_bqwv;

  /* Sum: '<S5>/Add5' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant7'
   *  DataTypeConversion: '<S5>/DataTypeConversion4'
   *  DataTypeConversion: '<S5>/DataTypeConversion5'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   *  Sum: '<S5>/Add1'
   *  Sum: '<S5>/Add2'
   *  Sum: '<S5>/Add3'
   *  Sum: '<S5>/Add4'
   *  Sum: '<S5>/Add7'
   *  UnitDelay: '<S5>/UnitDelay'
   *  UnitDelay: '<S5>/UnitDelay1'
   */
  rtb_Add5_htt5 = (((PFC_IKp * rtb_Add5_htt5) + (PFC_IKi * rtb_flError_lzc5)) +
                   (General_PFC_Control_Loop_ConstB.flKd_nfzr * ((rtb_Add5_htt5
    - General_PFC_Control_Loop_DW.UnitDelay_DSTATE_bqwv) +
    General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_mkmu))) + rtb_flFB_bafc;

  /* Switch: '<S9>/Switch2' incorporates:
   *  RelationalOperator: '<S9>/LowerRelop1'
   *  RelationalOperator: '<S9>/UpperRelop'
   *  Switch: '<S9>/Switch'
   */
  if (rtb_Add5_htt5 > General_PFC_Control_Loop_ConstB.flUpLimtit_cnbv) {
    rtb_Add5_htt5 = General_PFC_Control_Loop_ConstB.flUpLimtit_cnbv;
  } else {
    if (rtb_Add5_htt5 < General_PFC_Control_Loop_ConstB.flLowLimit_fz0h) {
      /* Switch: '<S9>/Switch' */
      rtb_Add5_htt5 = General_PFC_Control_Loop_ConstB.flLowLimit_fz0h;
    }
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Sum: '<S2>/Sum12' */
  rtb_flError_pk14 = rtb_PFC_Duty_D + rtb_Add5_htt5;

  /* Saturate: '<S2>/Saturation6' */
  if (rtb_flError_pk14 > PFC_Duty_Upper_limit) {
    /* Outport: '<Root>/PFC_Duty_B' */
    General_PFC_Control_Loop_Y.PFC_Duty_B = PFC_Duty_Upper_limit;
  } else if (rtb_flError_pk14 < PFC_Duty_Lower_limit) {
    /* Outport: '<Root>/PFC_Duty_B' */
    General_PFC_Control_Loop_Y.PFC_Duty_B = PFC_Duty_Lower_limit;
  } else {
    /* Outport: '<Root>/PFC_Duty_B' */
    General_PFC_Control_Loop_Y.PFC_Duty_B = rtb_flError_pk14;
  }

  /* End of Saturate: '<S2>/Saturation6' */

  /* Sum: '<S6>/Add' incorporates:
   *  Inport: '<Root>/PFC_Isw_C'
   *  SignalConversion: '<S2>/SignalConversion8'
   */
  rtb_flError_i1mh = rtb_Switch_cjrf - General_PFC_Control_Loop_U.PFC_Isw_C;

  /* UnitDelay: '<S6>/UnitDelay' */
  rtb_flError_last1_h5sj = General_PFC_Control_Loop_DW.UnitDelay_DSTATE_ew3i;

  /* Switch: '<S6>/Switch' incorporates:
   *  Inport: '<Root>/PFC_Duty_Init'
   *  Inport: '<Root>/PFC_Reset'
   *  UnitDelay: '<S6>/UnitDelay2'
   */
  if (General_PFC_Control_Loop_U.PFC_Reset) {
    rtb_flFB_bafc = General_PFC_Control_Loop_U.PFC_Duty_Init;
  } else {
    rtb_flFB_bafc = General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_ntfw;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S6>/Add2' incorporates:
   *  Sum: '<S6>/Add6'
   *  UnitDelay: '<S6>/UnitDelay'
   */
  rtb_flError_pk14 = rtb_flError_i1mh -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE_ew3i;

  /* Sum: '<S6>/Add5' incorporates:
   *  Constant: '<S2>/Constant11'
   *  Constant: '<S2>/Constant14'
   *  DataTypeConversion: '<S6>/DataTypeConversion4'
   *  DataTypeConversion: '<S6>/DataTypeConversion5'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Add4'
   *  Sum: '<S6>/Add7'
   *  UnitDelay: '<S6>/UnitDelay'
   *  UnitDelay: '<S6>/UnitDelay1'
   */
  rtb_flFB_bafc += ((PFC_IKp * rtb_flError_pk14) + (PFC_IKi * rtb_flError_i1mh))
    + (General_PFC_Control_Loop_ConstB.flKd_bda3 * ((rtb_flError_pk14 -
         General_PFC_Control_Loop_DW.UnitDelay_DSTATE_ew3i) +
        General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_j1pu));

  /* Switch: '<S10>/Switch2' incorporates:
   *  RelationalOperator: '<S10>/LowerRelop1'
   *  RelationalOperator: '<S10>/UpperRelop'
   *  Switch: '<S10>/Switch'
   */
  if (rtb_flFB_bafc > General_PFC_Control_Loop_ConstB.flUpLimtit_fi4y) {
    rtb_flFB_bafc = General_PFC_Control_Loop_ConstB.flUpLimtit_fi4y;
  } else {
    if (rtb_flFB_bafc < General_PFC_Control_Loop_ConstB.flLowLimit_ha24) {
      /* Switch: '<S10>/Switch' */
      rtb_flFB_bafc = General_PFC_Control_Loop_ConstB.flLowLimit_ha24;
    }
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Sum: '<S2>/Sum10' */
  rtb_flError_pk14 = rtb_PFC_Duty_D + rtb_flFB_bafc;

  /* Saturate: '<S2>/Saturation7' */
  if (rtb_flError_pk14 > PFC_Duty_Upper_limit) {
    /* Outport: '<Root>/PFC_Duty_C' */
    General_PFC_Control_Loop_Y.PFC_Duty_C = PFC_Duty_Upper_limit;
  } else if (rtb_flError_pk14 < PFC_Duty_Lower_limit) {
    /* Outport: '<Root>/PFC_Duty_C' */
    General_PFC_Control_Loop_Y.PFC_Duty_C = PFC_Duty_Lower_limit;
  } else {
    /* Outport: '<Root>/PFC_Duty_C' */
    General_PFC_Control_Loop_Y.PFC_Duty_C = rtb_flError_pk14;
  }

  /* End of Saturate: '<S2>/Saturation7' */

  /* Sum: '<S7>/Add' incorporates:
   *  Inport: '<Root>/PFC_Isw_D'
   */
  rtb_flError_pk14 = rtb_Switch_cjrf - General_PFC_Control_Loop_U.PFC_Isw_D;

  /* UnitDelay: '<S7>/UnitDelay' */
  rtb_flError_last1_dbec = General_PFC_Control_Loop_DW.UnitDelay_DSTATE_mlpv;

  /* DataTypeConversion: '<S7>/DataTypeConversion4' incorporates:
   *  Constant: '<S2>/Constant12'
   */
  rtb_Switch_cjrf = PFC_IKp;

  /* Sum: '<S7>/Add2' incorporates:
   *  Sum: '<S7>/Add6'
   *  UnitDelay: '<S7>/UnitDelay'
   */
  rtb_flKpterm_mzov_tmp = rtb_flError_pk14 -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE_mlpv;

  /* Product: '<S7>/Product' incorporates:
   *  Sum: '<S7>/Add2'
   */
  rtb_flKpterm_kxrl = rtb_Switch_cjrf * rtb_flKpterm_mzov_tmp;

  /* DataTypeConversion: '<S7>/DataTypeConversion5' incorporates:
   *  Constant: '<S2>/Constant13'
   */
  rtb_Switch_cjrf = PFC_IKi;

  /* Sum: '<S7>/Add4' incorporates:
   *  Product: '<S7>/Product1'
   */
  rtb_flKpterm_kxrl += rtb_Switch_cjrf * rtb_flError_pk14;

  /* Switch: '<S7>/Switch' incorporates:
   *  Inport: '<Root>/PFC_Duty_Init'
   *  Inport: '<Root>/PFC_Reset'
   *  UnitDelay: '<S7>/UnitDelay2'
   */
  if (General_PFC_Control_Loop_U.PFC_Reset) {
    rtb_Switch_cjrf = General_PFC_Control_Loop_U.PFC_Duty_Init;
  } else {
    rtb_Switch_cjrf = General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_lvzh;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Sum: '<S7>/Add5' incorporates:
   *  Product: '<S7>/Product2'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Add7'
   *  UnitDelay: '<S7>/UnitDelay'
   *  UnitDelay: '<S7>/UnitDelay1'
   */
  rtb_flKpterm_kxrl = (rtb_flKpterm_kxrl +
                       (General_PFC_Control_Loop_ConstB.flKd_cbjj *
                        ((rtb_flKpterm_mzov_tmp -
    General_PFC_Control_Loop_DW.UnitDelay_DSTATE_mlpv) +
    General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_kda5))) + rtb_Switch_cjrf;

  /* Switch: '<S11>/Switch2' incorporates:
   *  RelationalOperator: '<S11>/LowerRelop1'
   *  RelationalOperator: '<S11>/UpperRelop'
   *  Switch: '<S11>/Switch'
   */
  if (rtb_flKpterm_kxrl > General_PFC_Control_Loop_ConstB.flUpLimtit_m3pi) {
    rtb_flKpterm_kxrl = General_PFC_Control_Loop_ConstB.flUpLimtit_m3pi;
  } else {
    if (rtb_flKpterm_kxrl < General_PFC_Control_Loop_ConstB.flLowLimit_lpu5) {
      /* Switch: '<S11>/Switch' */
      rtb_flKpterm_kxrl = General_PFC_Control_Loop_ConstB.flLowLimit_lpu5;
    }
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Sum: '<S2>/Sum11' */
  rtb_PFC_Duty_D += rtb_flKpterm_kxrl;

  /* Saturate: '<S2>/Saturation8' */
  if (rtb_PFC_Duty_D > PFC_Duty_Upper_limit) {
    /* Outport: '<Root>/PFC_Duty_D' */
    General_PFC_Control_Loop_Y.PFC_Duty_D = PFC_Duty_Upper_limit;
  } else if (rtb_PFC_Duty_D < PFC_Duty_Lower_limit) {
    /* Outport: '<Root>/PFC_Duty_D' */
    General_PFC_Control_Loop_Y.PFC_Duty_D = PFC_Duty_Lower_limit;
  } else {
    /* Outport: '<Root>/PFC_Duty_D' */
    General_PFC_Control_Loop_Y.PFC_Duty_D = rtb_PFC_Duty_D;
  }

  /* End of Saturate: '<S2>/Saturation8' */

  /* Update for UnitDelay: '<S12>/UnitDelay' */
  General_PFC_Control_Loop_DW.UnitDelay_DSTATE = rtb_flError;

  /* Update for UnitDelay: '<S12>/UnitDelay1' */
  General_PFC_Control_Loop_DW.UnitDelay1_DSTATE = rtb_flError_last1;

  /* Update for UnitDelay: '<S12>/UnitDelay2' */
  General_PFC_Control_Loop_DW.UnitDelay2_DSTATE = rtb_Add4;

  /* Update for UnitDelay: '<S4>/UnitDelay' */
  General_PFC_Control_Loop_DW.UnitDelay_DSTATE_o1mb = rtb_Vrect_Duty;

  /* Update for UnitDelay: '<S4>/UnitDelay1' */
  General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_ere2 = rtb_flError_last1_atj4;

  /* Update for UnitDelay: '<S4>/UnitDelay2' */
  General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_jw05 = rtb_Add5_h4a2;

  /* Update for UnitDelay: '<S5>/UnitDelay' */
  General_PFC_Control_Loop_DW.UnitDelay_DSTATE_bqwv = rtb_flError_lzc5;

  /* Update for UnitDelay: '<S5>/UnitDelay1' */
  General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_mkmu = rtb_flError_last1_by1z;

  /* Update for UnitDelay: '<S5>/UnitDelay2' */
  General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_ptk1 = rtb_Add5_htt5;

  /* Update for UnitDelay: '<S6>/UnitDelay' */
  General_PFC_Control_Loop_DW.UnitDelay_DSTATE_ew3i = rtb_flError_i1mh;

  /* Update for UnitDelay: '<S6>/UnitDelay1' */
  General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_j1pu = rtb_flError_last1_h5sj;

  /* Update for UnitDelay: '<S6>/UnitDelay2' */
  General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_ntfw = rtb_flFB_bafc;

  /* Update for UnitDelay: '<S7>/UnitDelay' */
  General_PFC_Control_Loop_DW.UnitDelay_DSTATE_mlpv = rtb_flError_pk14;

  /* Update for UnitDelay: '<S7>/UnitDelay1' */
  General_PFC_Control_Loop_DW.UnitDelay1_DSTATE_kda5 = rtb_flError_last1_dbec;

  /* Update for UnitDelay: '<S7>/UnitDelay2' */
  General_PFC_Control_Loop_DW.UnitDelay2_DSTATE_lvzh = rtb_flKpterm_kxrl;
}

/* Model initialize function */
void General_PFC_Control_Loop_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
