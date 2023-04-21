/*
 * File: ADC_ValueConvert.h
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

#ifndef RTW_HEADER_ADC_ValueConvert_h_
#define RTW_HEADER_ADC_ValueConvert_h_
#include <math.h>
#ifndef ADC_ValueConvert_COMMON_INCLUDES_
# define ADC_ValueConvert_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ADC_ValueConvert_COMMON_INCLUDES_ */

#include "ADC_ValueConvert_types.h"

/* Child system includes */
#include "ValueConvert.h"
#include "ACParameter.h"
#include "RMS.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct {
  real32_T Value;                      /* '<S3>/Model1' */
  real32_T Value_b0re;                 /* '<S3>/Model2' */
  real32_T Value_dmkb;                 /* '<S4>/Model3' */
  real32_T Value_lunw;                 /* '<S4>/Model2' */
  real32_T Value_dzxx;                 /* '<S4>/Model' */
  real32_T Value_d12z;                 /* '<S4>/Model6' */
  real32_T Value_caf1;                 /* '<S4>/Model7' */
  real32_T Value_ma15;                 /* '<S4>/Model8' */
  real32_T Value_lkel;                 /* '<S4>/Model9' */
  real32_T Value_cxdu;                 /* '<S5>/Model3' */
  real32_T Value_pwgq;                 /* '<S5>/Model2' */
  real32_T Value_dvws;                 /* '<S5>/Model1' */
  real32_T Value_ozef;                 /* '<S5>/Model' */
} B_ADC_ValueConvert_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  MdlrefDW_ValueConvert_T Model1_InstanceData;/* '<S3>/Model1' */
  MdlrefDW_ValueConvert_T Model2_InstanceData;/* '<S3>/Model2' */
  MdlrefDW_ValueConvert_T Model3_InstanceData;/* '<S4>/Model3' */
  MdlrefDW_ValueConvert_T Model2_InstanceData_f4yo;/* '<S4>/Model2' */
  MdlrefDW_ACParameter_T Model1_InstanceData_pe5b;/* '<S4>/Model1' */
  MdlrefDW_ValueConvert_T Model_InstanceData;/* '<S4>/Model' */
  MdlrefDW_ValueConvert_T Model6_InstanceData;/* '<S4>/Model6' */
  MdlrefDW_ValueConvert_T Model7_InstanceData;/* '<S4>/Model7' */
  MdlrefDW_ValueConvert_T Model8_InstanceData;/* '<S4>/Model8' */
  MdlrefDW_ValueConvert_T Model9_InstanceData;/* '<S4>/Model9' */
  MdlrefDW_RMS_T Model4_InstanceData;  /* '<S6>/Model4' */
  MdlrefDW_RMS_T Model1_InstanceData_bjs0;/* '<S6>/Model1' */
  MdlrefDW_RMS_T Model2_InstanceData_klhf;/* '<S6>/Model2' */
  MdlrefDW_RMS_T Model3_InstanceData_kz1l;/* '<S6>/Model3' */
  MdlrefDW_ValueConvert_T Model3_InstanceData_e5pe;/* '<S5>/Model3' */
  MdlrefDW_ValueConvert_T Model2_InstanceData_hqbf;/* '<S5>/Model2' */
  MdlrefDW_ValueConvert_T Model1_InstanceData_gvlm;/* '<S5>/Model1' */
  MdlrefDW_ValueConvert_T Model_InstanceData_l3u2;/* '<S5>/Model' */
} DW_ADC_ValueConvert_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [1:1:166])
   * Referenced by:
   *   '<S3>/Constant2'
   *   '<S3>/Constant7'
   *   '<S4>/Constant1'
   *   '<S4>/Constant13'
   *   '<S4>/Constant15'
   *   '<S4>/Constant17'
   *   '<S4>/Constant19'
   *   '<S4>/Constant2'
   *   '<S4>/Constant3'
   *   '<S5>/Constant1'
   */
  real32_T pooled1[166];

  /* Pooled Parameter (Expression: [-40:1:125])
   * Referenced by:
   *   '<S5>/Constant4'
   *   '<S5>/Constant5'
   *   '<S5>/Constant8'
   */
  real32_T pooled2[166];

  /* Pooled Parameter (Expression: [1:1:166])
   * Referenced by:
   *   '<S3>/Constant5'
   *   '<S3>/Constant8'
   *   '<S4>/Constant14'
   *   '<S4>/Constant16'
   *   '<S4>/Constant18'
   *   '<S4>/Constant20'
   *   '<S4>/Constant4'
   *   '<S4>/Constant6'
   *   '<S4>/Constant7'
   *   '<S5>/Constant12'
   */
  uint16_T pooled3[166];

  /* Pooled Parameter (Expression: [1629:6:2620])
   * Referenced by:
   *   '<S5>/Constant2'
   *   '<S5>/Constant3'
   *   '<S5>/Constant7'
   */
  uint16_T pooled4[166];
} ConstP_ADC_ValueConvert_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T wLLCVoltAdc;                /* '<Root>/wLLCVoltAdc' */
  uint16_T wLLCCurrAdc;                /* '<Root>/wLLCCurrAdc' */
  uint16_T wPFCVoltAdc;                /* '<Root>/wPFCVoltAdc' */
  uint16_T wGridVoltLAdc;              /* '<Root>/wGridVoltLAdc' */
  uint16_T PFCIswAAdc;                 /* '<Root>/PFCIswAAdc' */
  uint16_T PFCIswBAdc;                 /* '<Root>/PFCIswBAdc' */
  uint16_T PFCIswCAdc;                 /* '<Root>/PFCIswCAdc' */
  uint16_T PFCIswDAdc;                 /* '<Root>/PFCIswDAdc' */
  uint16_T wGridVoltNAdc;              /* '<Root>/wGridVoltNAdc' */
  uint16_T wPFCAuxAdc;                 /* '<Root>/wPFCAuxAdc' */
  uint16_T wOBCTemp1Adc;               /* '<Root>/wOBCTemp1Adc' */
  uint16_T wOBCTemp2Adc;               /* '<Root>/wOBCTemp2Adc' */
  uint16_T wOBCTemp3Adc;               /* '<Root>/wOBCTemp3Adc' */
} ExtU_ADC_ValueConvert_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  PhyValueOut_LLC PhyValueOut_LLC_dvi4;/* '<Root>/PhyValueOut_LLC' */
  PhyValueOut_PFC PhyValueOut_PFC_peb1;/* '<Root>/PhyValueOut_PFC' */
  PhyValueOut_Other PhyValueOut_Other_hqpw;/* '<Root>/PhyValueOut_Other' */
} ExtY_ADC_ValueConvert_T;

/* Block signals (default storage) */
extern B_ADC_ValueConvert_T ADC_ValueConvert_B;

/* Block states (default storage) */
extern DW_ADC_ValueConvert_T ADC_ValueConvert_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ADC_ValueConvert_T ADC_ValueConvert_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ADC_ValueConvert_T ADC_ValueConvert_Y;

/* Constant parameters (default storage) */
extern const ConstP_ADC_ValueConvert_T ADC_ValueConvert_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern ConversionParameter AnalogParameter_Conversion[18];/* Variable: AnalogParameter_Conversion
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
extern real32_T PLL_Ki;                /* Variable: PLL_Ki
                                        * Referenced by: '<S4>/Model1'
                                        */
extern real32_T PLL_Kp;                /* Variable: PLL_Kp
                                        * Referenced by: '<S4>/Model1'
                                        */

/* Model entry point functions */
extern void ADC_ValueConvert_initialize(void);
extern void ADC_ValueConvert_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ADC_ValueConvert'
 * '<S1>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC'
 * '<S2>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC/ADCtoPhy_Other'
 * '<S3>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC/Subsystem1'
 * '<S4>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC/Subsystem2'
 * '<S5>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC/ADCtoPhy_Other/Subsystem2'
 * '<S6>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC/ADCtoPhy_Other/Subsystem3'
 * '<S7>'   : 'ADC_ValueConvert/Control_ValueConvert_LLC/Subsystem2/Subsystem'
 */

/*-
 * Requirements for '<Root>': ADC_ValueConvert
 */
#endif                                 /* RTW_HEADER_ADC_ValueConvert_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
