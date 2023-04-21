/*
 * File: ACParameter.h
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

#ifndef RTW_HEADER_ACParameter_h_
#define RTW_HEADER_ACParameter_h_
#include <math.h>
#ifndef ACParameter_COMMON_INCLUDES_
# define ACParameter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACParameter_COMMON_INCLUDES_ */

#include "ACParameter_types.h"

/* Block states (default storage) for model 'ACParameter' */
typedef struct {
  real32_T UnitDelay4_DSTATE;          /* '<S2>/UnitDelay4' */
  real32_T UnitDelay5_DSTATE;          /* '<S2>/UnitDelay5' */
  real32_T UnitDelay3_DSTATE;          /* '<S3>/UnitDelay3' */
  real32_T UnitDelay_DSTATE;           /* '<S3>/UnitDelay' */
  real32_T UnitDelay1_DSTATE;          /* '<S3>/UnitDelay1' */
  real32_T UnitDelay3_DSTATE_hi41;     /* '<S2>/Unit Delay3' */
  real32_T UnitDelay2_DSTATE;          /* '<S3>/UnitDelay2' */
  boolean_T UnitDelay6_DSTATE;         /* '<S2>/UnitDelay6' */
} DW_ACParameter_fwu4_T;

/* Invariant block signals for model 'ACParameter' */
typedef struct {
  const real32_T DataTypeConversion;   /* '<S2>/Data Type Conversion' */
  const real32_T DataTypeConversion2;  /* '<S2>/Data Type Conversion2' */
  const real32_T DataTypeConversion3;  /* '<S2>/Data Type Conversion3' */
  const real32_T DataTypeConversion4;  /* '<S2>/Data Type Conversion4' */
  const real32_T DataTypeConversion5;  /* '<S3>/Data Type Conversion5' */
  const real32_T DataTypeConversion3_antv;/* '<S3>/DataTypeConversion3' */
  const real32_T Gain8;                /* '<S3>/Gain8' */
  const real32_T wt;                   /* '<S3>/Gain1' */
  const real32_T Sum4;                 /* '<S3>/Sum4' */
} ConstB_ACParameter_hb4t_T;

typedef struct {
  DW_ACParameter_fwu4_T rtdw;
} MdlrefDW_ACParameter_T;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T PLL_Ki;                /* Variable: PLL_Ki
                                        * Referenced by: '<S3>/PLL_Ki'
                                        */
extern real32_T PLL_Kp;                /* Variable: PLL_Kp
                                        * Referenced by: '<S3>/PLL_Kp'
                                        */
extern void ACParameter(const real32_T *rtu_Signal, real32_T *rty_Theta,
  real32_T *rty_Frequency, real32_T *rty_RMS, DW_ACParameter_fwu4_T *localDW);

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
 * '<Root>' : 'ACParameter'
 * '<S1>'   : 'ACParameter/Subsystem'
 * '<S2>'   : 'ACParameter/Subsystem/Vrms'
 * '<S3>'   : 'ACParameter/Subsystem/frequency'
 */

/*-
 * Requirements for '<Root>': ACParameter
 */
#endif                                 /* RTW_HEADER_ACParameter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
