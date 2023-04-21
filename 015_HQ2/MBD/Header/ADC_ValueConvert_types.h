/*
 * File: ADC_ValueConvert_types.h
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

#ifndef RTW_HEADER_ADC_ValueConvert_types_h_
#define RTW_HEADER_ADC_ValueConvert_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_Other_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_Other_

typedef struct {
  real32_T PFCIswA_RMS;
  real32_T PFCIswB_RMS;
  real32_T PFCIswC_RMS;
  real32_T PFCIswD_RMS;
  real32_T PFCAux;
  real32_T OBCTemp3;
  real32_T OBCTemp2;
  real32_T OBCTemp1;
} PhyValueOut_Other;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ConversionParameter_
#define DEFINED_TYPEDEF_FOR_ConversionParameter_

typedef struct {
  uint16_T Conversion;
  real32_T Offset;
  real32_T Gain;
  real32_T CaliOffset;
  real32_T CaliGain;
  boolean_T FilterEnable;
  real32_T FilterA;
} ConversionParameter;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_LLC_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_LLC_

typedef struct {
  real32_T LLCVolt;
  real32_T LLCCurr;
} PhyValueOut_LLC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PhyValueOut_PFC_
#define DEFINED_TYPEDEF_FOR_PhyValueOut_PFC_

typedef struct {
  real32_T GridVoltTheta;
  real32_T GridVoltFreq;
  real32_T GridVoltRms;
  real32_T GridVolt;
  real32_T GridVoltRect;
  real32_T PFCVolt;
  real32_T PFCIswA;
  real32_T PFCIswB;
  real32_T PFCIswC;
  real32_T PFCIswD;
} PhyValueOut_PFC;

#endif
#endif                                /* RTW_HEADER_ADC_ValueConvert_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
