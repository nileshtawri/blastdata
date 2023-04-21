/*
 * File: RMS.h
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

#ifndef RTW_HEADER_RMS_h_
#define RTW_HEADER_RMS_h_
#include <math.h>
#ifndef RMS_COMMON_INCLUDES_
# define RMS_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RMS_COMMON_INCLUDES_ */

#include "RMS_types.h"

/* Block states (default storage) for model 'RMS' */
typedef struct {
  real32_T UnitDelay4_DSTATE;          /* '<S1>/UnitDelay4' */
  real32_T UnitDelay5_DSTATE;          /* '<S1>/UnitDelay5' */
  real32_T UnitDelay3_DSTATE;          /* '<S1>/Unit Delay3' */
  boolean_T UnitDelay6_DSTATE;         /* '<S1>/UnitDelay6' */
} DW_RMS_fwu4_T;

/* Invariant block signals for model 'RMS' */
typedef struct {
  const real32_T DataTypeConversion;   /* '<S1>/Data Type Conversion' */
  const real32_T DataTypeConversion2;  /* '<S1>/Data Type Conversion2' */
  const real32_T DataTypeConversion3;  /* '<S1>/Data Type Conversion3' */
  const real32_T DataTypeConversion4;  /* '<S1>/Data Type Conversion4' */
} ConstB_RMS_hb4t_T;

typedef struct {
  DW_RMS_fwu4_T rtdw;
} MdlrefDW_RMS_T;

extern void RMS(const real32_T *rtu_Frequency, const real32_T *rtu_Signal,
                real32_T *rty_RMS, DW_RMS_fwu4_T *localDW);

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
 * '<Root>' : 'RMS'
 * '<S1>'   : 'RMS/Vrms'
 */

/*-
 * Requirements for '<Root>': RMS
 */
#endif                                 /* RTW_HEADER_RMS_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
