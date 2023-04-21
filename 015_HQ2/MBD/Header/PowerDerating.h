/*
 * File: PowerDerating.h
 *
 * Code generated for Simulink model 'PowerDerating'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jun  6 15:44:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PowerDerating_h_
#define RTW_HEADER_PowerDerating_h_
#include <math.h>
#ifndef PowerDerating_COMMON_INCLUDES_
# define PowerDerating_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PowerDerating_COMMON_INCLUDES_ */

#include "PowerDerating_types.h"

/* Block states (default storage) for model 'PowerDerating' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
  boolean_T Relay_Mode;                /* '<S4>/Relay' */
} DW_PowerDerating_fwu4_T;

/* Self model data, for model 'PowerDerating' */
struct tag_RTM_PowerDerating_T {
  DW_PowerDerating_fwu4_T dwork;
};

extern void PowerDerating_Init(RT_MODEL_PowerDerating_T * const PowerDerating_M);
extern void PowerDerat_PowerDeratingTrigger(RT_MODEL_PowerDerating_T * const
  PowerDerating_M, const real32_T *rtu_flOBCVoltCmd, const real32_T
  *rtu_flOBCCurrCmd, const real32_T *rtu_flDCCurr, const real32_T
  *rtu_flCoolantTemp, const real32_T *rtu_EVSE_Imax, const boolean_T
  *rtu_blPowerDeratingEn, const PhyValueOut_LLC *rtu_PhyValueOut_LLC, const
  PhyValueOut_PFC *rtu_PhyValueOut_PFC, real32_T *rty_flLLCVoltCmd, real32_T
  *rty_flLLCCurrCmd);

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
 * '<Root>' : 'PowerDerating'
 * '<S1>'   : 'PowerDerating/Subsystem'
 * '<S2>'   : 'PowerDerating/Subsystem/Saturation Dynamic'
 * '<S3>'   : 'PowerDerating/Subsystem/Subsystem1'
 * '<S4>'   : 'PowerDerating/Subsystem/Subsystem1/Subsystem'
 * '<S5>'   : 'PowerDerating/Subsystem/Subsystem1/Subsystem/If Action Subsystem'
 * '<S6>'   : 'PowerDerating/Subsystem/Subsystem1/Subsystem/If Action Subsystem1'
 */

/*-
 * Requirements for '<Root>': PowerDerating
 */
#endif                                 /* RTW_HEADER_PowerDerating_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
