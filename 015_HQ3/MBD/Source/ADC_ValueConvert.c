/*
 * File: ADC_ValueConvert.c
 *
 * Code generated for Simulink model 'ADC_ValueConvert'.
 *
 * Model version                  : 1.284
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu May 26 14:12:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADC_ValueConvert.h"
#include "ADC_ValueConvert_private.h"

/* Exported block parameters */
ConversionParameter AnalogParameter_Conversion[18] = { {
    0U,
    0.0F,
    0.122F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    1787.34F,
    0.404F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    409.6F,
    0.0122F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.11872F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.11872F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.196F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.00469F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.01F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.01F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.01F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.0045F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.0045F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.0045F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    0.0045F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    1.0F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    1.0F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    1.0F,
    0.0F,
    1.0F,
    true,
    0.1F
  }, { 0U,
    0.0F,
    1.0F,
    0.0F,
    1.0F,
    true,
    0.1F
  } } ;                                /* Variable: AnalogParameter_Conversion
                                        * Referenced by:
                                        *   '<S3>/p2_LLCVolt'
                                        *   '<S3>/p3_LLCCurr'
                                        *   '<S4>/p11_PFCIswA'
                                        *   '<S4>/p12_PFCIswB'
                                        *   '<S4>/p13_PFCIswC'
                                        *   '<S4>/p14_PFCIswD'
                                        *   '<S4>/p1_PFCVolt'
                                        *   '<S4>/p4_GirdLVolt'
                                        *   '<S4>/p4_GirdNVolt'
                                        *   '<S4>/p5_GirdLVoltRMS'
                                        *   '<S5>/p10_OBCTemp3'
                                        *   '<S5>/p7_PFCAux'
                                        *   '<S5>/p8_OBCTemp1'
                                        *   '<S5>/p9_OBCTemp2'
                                        */

real32_T PLL_Ki = 25.0F;               /* Variable: PLL_Ki
                                        * Referenced by: '<S4>/Model1'
                                        */
real32_T PLL_Kp = 3.0F;                /* Variable: PLL_Kp
                                        * Referenced by: '<S4>/Model1'
                                        */

/* Block signals (default storage) */
B_ADC_ValueConvert_T ADC_ValueConvert_B;

/* Block states (default storage) */
DW_ADC_ValueConvert_T ADC_ValueConvert_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ADC_ValueConvert_T ADC_ValueConvert_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ADC_ValueConvert_T ADC_ValueConvert_Y;

/* Model step function */
#pragma CODE_SECTION(ADC_ValueConvert_step,".TI.ramfunc");
void ADC_ValueConvert_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Theta;
  real32_T rtb_Frequency;
  real32_T rtb_RMS;
  real32_T rtb_RMS_e1u3;
  real32_T rtb_RMS_pust;
  real32_T rtb_RMS_cawo;
  real32_T rtb_RMS_kzos;
  uint16_T rtb_Adc;
  uint16_T rtb_Adc_hbka;
  uint16_T rtb_Adc_cwkx;
  uint16_T rtb_Adc_gg1w;
  uint16_T rtb_Adc_oyz1;
  uint16_T rtb_Adc_hz0n;
  uint16_T rtb_Adc_bqsf;
  uint16_T rtb_Adc_jqao;
  uint16_T rtb_Adc_i5sy;
  uint16_T rtb_Adc_cwas;
  uint16_T rtb_Adc_puhm;
  uint16_T rtb_Adc_iven;
  uint16_T rtb_Adc_bruy;
  real32_T rtb_GridVolt;
  real32_T rtb_GridVoltRms;
  real32_T rtb_OBCTemp3;
  real32_T rtb_PFCIswC_RMS;
  real32_T rtb_PFCIswB_RMS;
  real32_T rtb_LLCVolt;
  real32_T rtb_LLCCurr;

  /* SignalConversion: '<S3>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/wLLCVoltAdc'
   */
  rtb_Adc = ADC_ValueConvert_U.wLLCVoltAdc;

  /* ModelReference: '<S3>/Model1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/p2_LLCVolt'
   */
  ValueConvert(&rtb_Adc, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[1],
               &ADC_ValueConvert_B.Value,
               &(ADC_ValueConvert_DW.Model1_InstanceData.rtdw));

  /* SignalConversion: '<S3>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/wLLCCurrAdc'
   */
  rtb_Adc_hbka = ADC_ValueConvert_U.wLLCCurrAdc;

  /* ModelReference: '<S3>/Model2' incorporates:
   *  Constant: '<S3>/Constant7'
   *  Constant: '<S3>/Constant8'
   *  Constant: '<S3>/p3_LLCCurr'
   */
  ValueConvert(&rtb_Adc_hbka, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[2],
               &ADC_ValueConvert_B.Value_b0re,
               &(ADC_ValueConvert_DW.Model2_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/wGridVoltLAdc'
   */
  rtb_Adc_cwkx = ADC_ValueConvert_U.wGridVoltLAdc;

  /* ModelReference: '<S4>/Model3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/p4_GirdLVolt'
   */
  ValueConvert(&rtb_Adc_cwkx, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[3],
               &ADC_ValueConvert_B.Value_dmkb,
               &(ADC_ValueConvert_DW.Model3_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/wGridVoltNAdc'
   */
  rtb_Adc_gg1w = ADC_ValueConvert_U.wGridVoltNAdc;

  /* ModelReference: '<S4>/Model2' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant7'
   *  Constant: '<S4>/p4_GirdNVolt'
   */
  ValueConvert(&rtb_Adc_gg1w, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[3],
               &ADC_ValueConvert_B.Value_lunw,
               &(ADC_ValueConvert_DW.Model2_InstanceData_f4yo.rtdw));

  /* Sum: '<S4>/Add' */
  rtb_GridVolt = ADC_ValueConvert_B.Value_dmkb - ADC_ValueConvert_B.Value_lunw;

  /* SignalConversion: '<S4>/Signal Conversion2' */
  rtb_GridVoltRms = rtb_GridVolt;

  /* ModelReference: '<S4>/Model1' */
  ACParameter(&rtb_GridVoltRms, &rtb_Theta, &rtb_Frequency, &rtb_RMS,
              &(ADC_ValueConvert_DW.Model1_InstanceData_pe5b.rtdw));

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S4>/p5_GirdLVoltRMS'
   */
  rtb_GridVoltRms = rtb_RMS * AnalogParameter_Conversion[4].CaliGain;

  /* Sum: '<S7>/Add' incorporates:
   *  Constant: '<S4>/p5_GirdLVoltRMS'
   */
  rtb_GridVoltRms += AnalogParameter_Conversion[4].CaliOffset;

  /* SignalConversion: '<S4>/Signal Conversion7' */
  rtb_OBCTemp3 = rtb_Frequency;

  /* SignalConversion: '<S4>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/wPFCVoltAdc'
   */
  rtb_Adc_oyz1 = ADC_ValueConvert_U.wPFCVoltAdc;

  /* ModelReference: '<S4>/Model' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/p1_PFCVolt'
   */
  ValueConvert(&rtb_Adc_oyz1, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &(&AnalogParameter_Conversion[0])
               [0], &ADC_ValueConvert_B.Value_dzxx,
               &(ADC_ValueConvert_DW.Model_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion14' incorporates:
   *  Inport: '<Root>/PFCIswAAdc'
   */
  rtb_Adc_hz0n = ADC_ValueConvert_U.PFCIswAAdc;

  /* ModelReference: '<S4>/Model6' incorporates:
   *  Constant: '<S4>/Constant13'
   *  Constant: '<S4>/Constant14'
   *  Constant: '<S4>/p11_PFCIswA'
   */
  ValueConvert(&rtb_Adc_hz0n, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[10],
               &ADC_ValueConvert_B.Value_d12z,
               &(ADC_ValueConvert_DW.Model6_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion10' */
  rtb_PFCIswC_RMS = ADC_ValueConvert_B.Value_d12z;

  /* SignalConversion: '<S4>/Signal Conversion15' incorporates:
   *  Inport: '<Root>/PFCIswBAdc'
   */
  rtb_Adc_bqsf = ADC_ValueConvert_U.PFCIswBAdc;

  /* ModelReference: '<S4>/Model7' incorporates:
   *  Constant: '<S4>/Constant15'
   *  Constant: '<S4>/Constant16'
   *  Constant: '<S4>/p12_PFCIswB'
   */
  ValueConvert(&rtb_Adc_bqsf, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[11],
               &ADC_ValueConvert_B.Value_caf1,
               &(ADC_ValueConvert_DW.Model7_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion11' */
  rtb_PFCIswB_RMS = ADC_ValueConvert_B.Value_caf1;

  /* SignalConversion: '<S4>/Signal Conversion16' incorporates:
   *  Inport: '<Root>/PFCIswCAdc'
   */
  rtb_Adc_jqao = ADC_ValueConvert_U.PFCIswCAdc;

  /* ModelReference: '<S4>/Model8' incorporates:
   *  Constant: '<S4>/Constant17'
   *  Constant: '<S4>/Constant18'
   *  Constant: '<S4>/p13_PFCIswC'
   */
  ValueConvert(&rtb_Adc_jqao, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[12],
               &ADC_ValueConvert_B.Value_ma15,
               &(ADC_ValueConvert_DW.Model8_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion12' */
  rtb_LLCVolt = ADC_ValueConvert_B.Value_ma15;

  /* SignalConversion: '<S4>/Signal Conversion17' incorporates:
   *  Inport: '<Root>/PFCIswDAdc'
   */
  rtb_Adc_i5sy = ADC_ValueConvert_U.PFCIswDAdc;

  /* ModelReference: '<S4>/Model9' incorporates:
   *  Constant: '<S4>/Constant19'
   *  Constant: '<S4>/Constant20'
   *  Constant: '<S4>/p14_PFCIswD'
   */
  ValueConvert(&rtb_Adc_i5sy, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[13],
               &ADC_ValueConvert_B.Value_lkel,
               &(ADC_ValueConvert_DW.Model9_InstanceData.rtdw));

  /* SignalConversion: '<S4>/Signal Conversion13' */
  rtb_LLCCurr = ADC_ValueConvert_B.Value_lkel;

  /* Outport: '<Root>/PhyValueOut_PFC' incorporates:
   *  Abs: '<S4>/Abs'
   *  BusCreator generated from: '<Root>/PhyValueOut_PFC'
   *  SignalConversion: '<S4>/Signal Conversion'
   *  SignalConversion: '<S4>/Signal Conversion5'
   */
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.GridVoltTheta = rtb_Theta;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.GridVoltFreq = rtb_OBCTemp3;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.GridVoltRms = rtb_GridVoltRms;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.GridVolt = rtb_GridVolt;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.GridVoltRect = fabsf(rtb_GridVolt);
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.PFCVolt =
    ADC_ValueConvert_B.Value_dzxx;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.PFCIswA = rtb_PFCIswC_RMS;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.PFCIswB = rtb_PFCIswB_RMS;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.PFCIswC = rtb_LLCVolt;
  ADC_ValueConvert_Y.PhyValueOut_PFC_peb1.PFCIswD = rtb_LLCCurr;

  /* ModelReference: '<S6>/Model4' */
  RMS(&rtb_OBCTemp3, &rtb_PFCIswC_RMS, &rtb_RMS_e1u3,
      &(ADC_ValueConvert_DW.Model4_InstanceData.rtdw));

  /* ModelReference: '<S6>/Model1' */
  RMS(&rtb_OBCTemp3, &rtb_PFCIswB_RMS, &rtb_RMS_pust,
      &(ADC_ValueConvert_DW.Model1_InstanceData_bjs0.rtdw));

  /* ModelReference: '<S6>/Model2' */
  RMS(&rtb_OBCTemp3, &rtb_LLCVolt, &rtb_RMS_cawo,
      &(ADC_ValueConvert_DW.Model2_InstanceData_klhf.rtdw));

  /* ModelReference: '<S6>/Model3' */
  RMS(&rtb_OBCTemp3, &rtb_LLCCurr, &rtb_RMS_kzos,
      &(ADC_ValueConvert_DW.Model3_InstanceData_kz1l.rtdw));

  /* SignalConversion: '<S5>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/wPFCAuxAdc'
   */
  rtb_Adc_cwas = ADC_ValueConvert_U.wPFCAuxAdc;

  /* ModelReference: '<S5>/Model3' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant12'
   *  Constant: '<S5>/p7_PFCAux'
   */
  ValueConvert(&rtb_Adc_cwas, ADC_ValueConvert_ConstP.pooled1,
               ADC_ValueConvert_ConstP.pooled3, &AnalogParameter_Conversion[6],
               &ADC_ValueConvert_B.Value_cxdu,
               &(ADC_ValueConvert_DW.Model3_InstanceData_e5pe.rtdw));

  /* SignalConversion: '<S5>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/wOBCTemp3Adc'
   */
  rtb_Adc_puhm = ADC_ValueConvert_U.wOBCTemp3Adc;

  /* ModelReference: '<S5>/Model2' incorporates:
   *  Constant: '<S5>/Constant7'
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/p10_OBCTemp3'
   */
  ValueConvert(&rtb_Adc_puhm, ADC_ValueConvert_ConstP.pooled2,
               ADC_ValueConvert_ConstP.pooled4, &AnalogParameter_Conversion[9],
               &ADC_ValueConvert_B.Value_pwgq,
               &(ADC_ValueConvert_DW.Model2_InstanceData_hqbf.rtdw));

  /* SignalConversion: '<S5>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/wOBCTemp2Adc'
   */
  rtb_Adc_iven = ADC_ValueConvert_U.wOBCTemp2Adc;

  /* ModelReference: '<S5>/Model1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S5>/p9_OBCTemp2'
   */
  ValueConvert(&rtb_Adc_iven, ADC_ValueConvert_ConstP.pooled2,
               ADC_ValueConvert_ConstP.pooled4, &AnalogParameter_Conversion[8],
               &ADC_ValueConvert_B.Value_dvws,
               &(ADC_ValueConvert_DW.Model1_InstanceData_gvlm.rtdw));

  /* SignalConversion: '<S5>/Signal Conversion9' incorporates:
   *  Inport: '<Root>/wOBCTemp1Adc'
   */
  rtb_Adc_bruy = ADC_ValueConvert_U.wOBCTemp1Adc;

  /* ModelReference: '<S5>/Model' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S5>/p8_OBCTemp1'
   */
  ValueConvert(&rtb_Adc_bruy, ADC_ValueConvert_ConstP.pooled2,
               ADC_ValueConvert_ConstP.pooled4, &AnalogParameter_Conversion[7],
               &ADC_ValueConvert_B.Value_ozef,
               &(ADC_ValueConvert_DW.Model_InstanceData_l3u2.rtdw));

  /* SignalConversion: '<S5>/Signal Conversion' */
  rtb_LLCCurr = ADC_ValueConvert_B.Value_ozef;

  /* SignalConversion: '<S6>/Signal Conversion10' */
  rtb_LLCVolt = rtb_RMS_e1u3;

  /* SignalConversion: '<S6>/Signal Conversion11' */
  rtb_PFCIswB_RMS = rtb_RMS_pust;

  /* SignalConversion: '<S6>/Signal Conversion12' */
  rtb_PFCIswC_RMS = rtb_RMS_cawo;

  /* SignalConversion: '<S5>/Signal Conversion2' */
  rtb_OBCTemp3 = ADC_ValueConvert_B.Value_pwgq;

  /* Outport: '<Root>/PhyValueOut_Other' incorporates:
   *  BusCreator: '<S2>/Bus Creator3'
   *  SignalConversion: '<S5>/Signal Conversion1'
   *  SignalConversion: '<S5>/Signal Conversion5'
   *  SignalConversion: '<S6>/Signal Conversion13'
   */
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.PFCIswA_RMS = rtb_LLCVolt;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.PFCIswB_RMS = rtb_PFCIswB_RMS;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.PFCIswC_RMS = rtb_PFCIswC_RMS;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.PFCIswD_RMS = rtb_RMS_kzos;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.PFCAux =
    ADC_ValueConvert_B.Value_cxdu;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.OBCTemp3 = rtb_OBCTemp3;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.OBCTemp2 =
    ADC_ValueConvert_B.Value_dvws;
  ADC_ValueConvert_Y.PhyValueOut_Other_hqpw.OBCTemp1 = rtb_LLCCurr;

  /* SignalConversion: '<S3>/Signal Conversion2' */
  rtb_LLCCurr = ADC_ValueConvert_B.Value_b0re;

  /* SignalConversion: '<S3>/Signal Conversion1' */
  rtb_LLCVolt = ADC_ValueConvert_B.Value;

  /* Outport: '<Root>/PhyValueOut_LLC' incorporates:
   *  BusCreator generated from: '<Root>/PhyValueOut_LLC'
   */
  ADC_ValueConvert_Y.PhyValueOut_LLC_dvi4.LLCVolt = rtb_LLCVolt;
  ADC_ValueConvert_Y.PhyValueOut_LLC_dvi4.LLCCurr = rtb_LLCCurr;
}

/* Model initialize function */
void ADC_ValueConvert_initialize(void)
{
  /* SystemInitialize for ModelReference: '<S3>/Model1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/p2_LLCVolt'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value);

  /* SystemInitialize for ModelReference: '<S3>/Model2' incorporates:
   *  Constant: '<S3>/Constant7'
   *  Constant: '<S3>/Constant8'
   *  Constant: '<S3>/p3_LLCCurr'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_b0re);

  /* SystemInitialize for ModelReference: '<S4>/Model3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/p4_GirdLVolt'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_dmkb);

  /* SystemInitialize for ModelReference: '<S4>/Model2' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant7'
   *  Constant: '<S4>/p4_GirdNVolt'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_lunw);

  /* SystemInitialize for ModelReference: '<S4>/Model' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/p1_PFCVolt'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_dzxx);

  /* SystemInitialize for ModelReference: '<S4>/Model6' incorporates:
   *  Constant: '<S4>/Constant13'
   *  Constant: '<S4>/Constant14'
   *  Constant: '<S4>/p11_PFCIswA'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_d12z);

  /* SystemInitialize for ModelReference: '<S4>/Model7' incorporates:
   *  Constant: '<S4>/Constant15'
   *  Constant: '<S4>/Constant16'
   *  Constant: '<S4>/p12_PFCIswB'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_caf1);

  /* SystemInitialize for ModelReference: '<S4>/Model8' incorporates:
   *  Constant: '<S4>/Constant17'
   *  Constant: '<S4>/Constant18'
   *  Constant: '<S4>/p13_PFCIswC'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_ma15);

  /* SystemInitialize for ModelReference: '<S4>/Model9' incorporates:
   *  Constant: '<S4>/Constant19'
   *  Constant: '<S4>/Constant20'
   *  Constant: '<S4>/p14_PFCIswD'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_lkel);

  /* SystemInitialize for ModelReference: '<S5>/Model3' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant12'
   *  Constant: '<S5>/p7_PFCAux'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_cxdu);

  /* SystemInitialize for ModelReference: '<S5>/Model2' incorporates:
   *  Constant: '<S5>/Constant7'
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/p10_OBCTemp3'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_pwgq);

  /* SystemInitialize for ModelReference: '<S5>/Model1' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S5>/p9_OBCTemp2'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_dvws);

  /* SystemInitialize for ModelReference: '<S5>/Model' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S5>/p8_OBCTemp1'
   */
  ValueConvert_Init(&ADC_ValueConvert_B.Value_ozef);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
