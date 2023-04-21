/*
 * File: LLC_Control_Loop.h
 *
 * Code generated for Simulink model 'LLC_Control_Loop'.
 *
 * Model version                  : 1.220
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Apr  6 14:36:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LLC_Control_Loop_h_
#define RTW_HEADER_LLC_Control_Loop_h_
#include <math.h>
#ifndef LLC_Control_Loop_COMMON_INCLUDES_
# define LLC_Control_Loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LLC_Control_Loop_COMMON_INCLUDES_ */

#include "LLC_Control_Loop_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S2>/UnitDelay' */
  real32_T UnitDelay1_DSTATE;          /* '<S2>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/UnitDelay2' */
  real32_T UnitDelay_DSTATE_exj3;      /* '<S3>/UnitDelay' */
  real32_T UnitDelay1_DSTATE_b54s;     /* '<S3>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE_i1xh;     /* '<S3>/UnitDelay2' */
} DW_LLC_Control_Loop_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T flKd;                 /* '<S2>/DataTypeConversion6' */
  const real32_T flInitValue;          /* '<S2>/DataTypeConversion9' */
  const real32_T flKd_lpwk;            /* '<S3>/DataTypeConversion6' */
  const real32_T flInitValue_dhlv;     /* '<S3>/DataTypeConversion9' */
} ConstB_LLC_Control_Loop_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T flLLCVoltRef;               /* '<Root>/flLLCVoltRef' */
  boolean_T LLC_Reset;                 /* '<Root>/LLC_Reset' */
  real32_T flLLCCurrRef;               /* '<Root>/flLLCCurrRef' */
  PhyValueOut_LLC PhyValueOut_LLC_mtcd;/* '<Root>/PhyValueOut_LLC' */
  PhyValueOut_PFC PhyValueOut_PFC_mjhy;/* '<Root>/PhyValueOut_PFC' */
} ExtU_LLC_Control_Loop_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T wCtrlOutFreq;               /* '<Root>/wCtrlOutFreq' */
  uint16_T wCtrlOutTheta;              /* '<Root>/wCtrlOutTheta' */
} ExtY_LLC_Control_Loop_T;

/* Block states (default storage) */
extern DW_LLC_Control_Loop_T LLC_Control_Loop_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_LLC_Control_Loop_T LLC_Control_Loop_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_LLC_Control_Loop_T LLC_Control_Loop_Y;
extern const ConstB_LLC_Control_Loop_T LLC_Control_Loop_ConstB;/* constant block i/o */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T flCCKi;                /* Variable: flCCKi
                                        * Referenced by: '<S1>/Constant9'
                                        */
extern real32_T flCCKp;                /* Variable: flCCKp
                                        * Referenced by: '<S1>/Constant8'
                                        */
extern real32_T flCVKi;                /* Variable: flCVKi
                                        * Referenced by: '<S1>/Constant1'
                                        * 0.03

                                          0.3*2
                                        */
extern real32_T flCVKp;                /* Variable: flCVKp
                                        * Referenced by: '<S1>/Constant'
                                        * 0.001

                                          0.1*2
                                        */
extern real32_T flCtrlLowLimit;        /* Variable: flCtrlLowLimit
                                        * Referenced by:
                                        *   '<S1>/Constant3'
                                        *   '<S1>/Constant6'
                                        */
extern real32_T flCtrlUpLimit;         /* Variable: flCtrlUpLimit
                                        * Referenced by:
                                        *   '<S1>/Constant11'
                                        *   '<S1>/Constant5'
                                        */

/* Model entry point functions */
extern void LLC_Control_Loop_initialize(void);
extern void LLC_Control_Loop_step(void);

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
 * '<Root>' : 'LLC_Control_Loop'
 * '<S1>'   : 'LLC_Control_Loop/LLC_Control_Loop'
 * '<S2>'   : 'LLC_Control_Loop/LLC_Control_Loop/DiscretePID'
 * '<S3>'   : 'LLC_Control_Loop/LLC_Control_Loop/DiscretePID1'
 * '<S4>'   : 'LLC_Control_Loop/LLC_Control_Loop/DiscretePID/SaturationDynamic'
 * '<S5>'   : 'LLC_Control_Loop/LLC_Control_Loop/DiscretePID1/SaturationDynamic'
 */

/*-
 * Requirements for '<Root>': LLC_Control_Loop
 */
#endif                                 /* RTW_HEADER_LLC_Control_Loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
