/*
 * File: Protection.h
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.80
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jun 23 09:10:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Protection_h_
#define RTW_HEADER_Protection_h_
#ifndef Protection_COMMON_INCLUDES_
# define Protection_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Protection_COMMON_INCLUDES_ */

#include "Protection_types.h"

/* Block signals for model 'Protection' */
typedef struct {
  real32_T FaultValue_Up;              /* '<S4>/Chart1' */
  real32_T FaultValue_Low;             /* '<S3>/Chart1' */
  uint16_T Retry_Count_Up;             /* '<S4>/Chart1' */
  uint16_T Retry_Count_Low;            /* '<S3>/Chart1' */
  boolean_T TripHigh_Error;            /* '<S6>/Chart' */
} B_Protection_caua_T;

/* Block states (default storage) for model 'Protection' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<S6>/Chart' */
  uint32_T temporalCounter_i1_clcf;    /* '<S5>/Chart' */
  uint32_T temporalCounter_i1_cufv;    /* '<S4>/Chart1' */
  uint32_T temporalCounter_i1_hl0c;    /* '<S3>/Chart1' */
  uint16_T is_active_c3_Protection;    /* '<S6>/Chart' */
  uint16_T is_c3_Protection;           /* '<S6>/Chart' */
  uint16_T is_Function_Enable;         /* '<S6>/Chart' */
  uint16_T is_active_c4_Protection;    /* '<S5>/Chart' */
  uint16_T is_c4_Protection;           /* '<S5>/Chart' */
  uint16_T is_Function_Enable_czmp;    /* '<S5>/Chart' */
  uint16_T is_active_c2_Protection;    /* '<S4>/Chart1' */
  uint16_T is_c2_Protection;           /* '<S4>/Chart1' */
  uint16_T is_Function_Enable_cc0g;    /* '<S4>/Chart1' */
  uint16_T is_Function_Disable;        /* '<S4>/Chart1' */
  uint16_T is_active_c5_Protection;    /* '<S3>/Chart1' */
  uint16_T is_c5_Protection;           /* '<S3>/Chart1' */
  uint16_T is_Function_Enable_mm01;    /* '<S3>/Chart1' */
  uint16_T is_Function_Disable_id2k;   /* '<S3>/Chart1' */
} DW_Protection_fwu4_T;

typedef struct {
  B_Protection_caua_T rtb;
  DW_Protection_fwu4_T rtdw;
} MdlrefDW_Protection_T;

extern void Protection_Init(ProtectionMessage *rty_ProtectionMessage,
  B_Protection_caua_T *localB);
extern void Protection(const real32_T *rtu_PhyValue, const ProtectionParameter
  *rtu_ProtectionParameter, ProtectionMessage *rty_ProtectionMessage,
  B_Protection_caua_T *localB, DW_Protection_fwu4_T *localDW);

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
 * '<Root>' : 'Protection'
 * '<S1>'   : 'Protection/Subsystem1'
 * '<S2>'   : 'Protection/Subsystem1/Trip'
 * '<S3>'   : 'Protection/Subsystem1/Trip/Retry_Function_Low'
 * '<S4>'   : 'Protection/Subsystem1/Trip/Retry_Function_Up'
 * '<S5>'   : 'Protection/Subsystem1/Trip/Trip_Function_Low'
 * '<S6>'   : 'Protection/Subsystem1/Trip/Trip_Function_Up'
 * '<S7>'   : 'Protection/Subsystem1/Trip/Retry_Function_Low/Chart1'
 * '<S8>'   : 'Protection/Subsystem1/Trip/Retry_Function_Up/Chart1'
 * '<S9>'   : 'Protection/Subsystem1/Trip/Trip_Function_Low/Chart'
 * '<S10>'  : 'Protection/Subsystem1/Trip/Trip_Function_Up/Chart'
 */

/*-
 * Requirements for '<Root>': Protection
 */
#endif                                 /* RTW_HEADER_Protection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
