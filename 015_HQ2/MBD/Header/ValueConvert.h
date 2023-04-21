/*
 * File: ValueConvert.h
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

#ifndef RTW_HEADER_ValueConvert_h_
#define RTW_HEADER_ValueConvert_h_
#ifndef ValueConvert_COMMON_INCLUDES_
# define ValueConvert_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ValueConvert_COMMON_INCLUDES_ */

#include "ValueConvert_types.h"

/* Block states (default storage) for model 'ValueConvert' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S7>/Unit Delay' */
} DW_ValueConvert_fwu4_T;

typedef struct {
  DW_ValueConvert_fwu4_T rtdw;
} MdlrefDW_ValueConvert_T;

extern void ValueConvert_Init(real32_T *rty_Value);
extern void ValueConvert(const uint16_T *rtu_Adc, const real32_T rtu_LUT[166],
  const uint16_T rtu_Index[166], const ConversionParameter
  *rtu_ConversionParameter, real32_T *rty_Value, DW_ValueConvert_fwu4_T *localDW);

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
 * '<Root>' : 'ValueConvert'
 * '<S1>'   : 'ValueConvert/Subsystem3'
 * '<S2>'   : 'ValueConvert/Subsystem3/Coversion'
 * '<S3>'   : 'ValueConvert/Subsystem3/Filter'
 * '<S4>'   : 'ValueConvert/Subsystem3/Subsystem'
 * '<S5>'   : 'ValueConvert/Subsystem3/Coversion/If Action Subsystem'
 * '<S6>'   : 'ValueConvert/Subsystem3/Coversion/Subsystem'
 * '<S7>'   : 'ValueConvert/Subsystem3/Filter/Subsystem'
 * '<S8>'   : 'ValueConvert/Subsystem3/Filter/Subsystem1'
 */

/*-
 * Requirements for '<Root>': ValueConvert
 */
#endif                                 /* RTW_HEADER_ValueConvert_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
