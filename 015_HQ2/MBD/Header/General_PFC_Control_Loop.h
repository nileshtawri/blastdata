/*
 * File: General_PFC_Control_Loop.h
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

#ifndef RTW_HEADER_General_PFC_Control_Loop_h_
#define RTW_HEADER_General_PFC_Control_Loop_h_
#include <math.h>
#ifndef General_PFC_Control_Loop_COMMON_INCLUDES_
# define General_PFC_Control_Loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                           /* General_PFC_Control_Loop_COMMON_INCLUDES_ */

#include "General_PFC_Control_Loop_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S12>/UnitDelay' */
  real32_T UnitDelay1_DSTATE;          /* '<S12>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S12>/UnitDelay2' */
  real32_T UnitDelay_DSTATE_o1mb;      /* '<S4>/UnitDelay' */
  real32_T UnitDelay1_DSTATE_ere2;     /* '<S4>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE_jw05;     /* '<S4>/UnitDelay2' */
  real32_T UnitDelay_DSTATE_bqwv;      /* '<S5>/UnitDelay' */
  real32_T UnitDelay1_DSTATE_mkmu;     /* '<S5>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE_ptk1;     /* '<S5>/UnitDelay2' */
  real32_T UnitDelay_DSTATE_ew3i;      /* '<S6>/UnitDelay' */
  real32_T UnitDelay1_DSTATE_j1pu;     /* '<S6>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE_ntfw;     /* '<S6>/UnitDelay2' */
  real32_T UnitDelay_DSTATE_mlpv;      /* '<S7>/UnitDelay' */
  real32_T UnitDelay1_DSTATE_kda5;     /* '<S7>/UnitDelay1' */
  real32_T UnitDelay2_DSTATE_lvzh;     /* '<S7>/UnitDelay2' */
} DW_General_PFC_Control_Loop_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T DataTypeConversion;   /* '<S2>/DataTypeConversion' */
  const real32_T flKd;                 /* '<S4>/DataTypeConversion6' */
  const real32_T flUpLimtit;           /* '<S4>/DataTypeConversion7' */
  const real32_T flLowLimit;           /* '<S4>/DataTypeConversion8' */
  const real32_T flKd_nfzr;            /* '<S5>/DataTypeConversion6' */
  const real32_T flUpLimtit_cnbv;      /* '<S5>/DataTypeConversion7' */
  const real32_T flLowLimit_fz0h;      /* '<S5>/DataTypeConversion8' */
  const real32_T flKd_bda3;            /* '<S6>/DataTypeConversion6' */
  const real32_T flUpLimtit_fi4y;      /* '<S6>/DataTypeConversion7' */
  const real32_T flLowLimit_ha24;      /* '<S6>/DataTypeConversion8' */
  const real32_T flKd_cbjj;            /* '<S7>/DataTypeConversion6' */
  const real32_T flUpLimtit_m3pi;      /* '<S7>/DataTypeConversion7' */
  const real32_T flLowLimit_lpu5;      /* '<S7>/DataTypeConversion8' */
  const real32_T DataTypeConversion_phn1;/* '<S3>/Data Type Conversion' */
  const real32_T DataTypeConversion_hkvo;/* '<S3>/DataTypeConversion' */
  const real32_T flKd_makw;            /* '<S12>/DataTypeConversion6' */
} ConstB_General_PFC_Control_Lo_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T PFC_Vcmd_Out;               /* '<Root>/PFC_Vcmd_Out' */
  real32_T PFC_Vo;                     /* '<Root>/PFC_Vo' */
  real32_T PFC_Vrms;                   /* '<Root>/PFC_Vrms' */
  real32_T PFC_Isw_A;                  /* '<Root>/PFC_Isw_A' */
  real32_T PFC_Isw_B;                  /* '<Root>/PFC_Isw_B' */
  real32_T PFC_Isw_C;                  /* '<Root>/PFC_Isw_C' */
  real32_T PFC_Isw_D;                  /* '<Root>/PFC_Isw_D' */
  boolean_T PFC_Reset;                 /* '<Root>/PFC_Reset' */
  real32_T PFC_Isw_cmd_Init;           /* '<Root>/PFC_Isw_cmd_Init' */
  real32_T PFC_Duty_Init;              /* '<Root>/PFC_Duty_Init' */
  real32_T GridTheta;                  /* '<Root>/GridTheta' */
  real32_T PFC_Duty_Out;               /* '<Root>/PFC_Duty_Out' */
} ExtU_General_PFC_Control_Loop_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T PFC_Duty_A;                 /* '<Root>/PFC_Duty_A' */
  real32_T PFC_Duty_B;                 /* '<Root>/PFC_Duty_B' */
  real32_T PFC_Duty_C;                 /* '<Root>/PFC_Duty_C' */
  real32_T PFC_Duty_D;                 /* '<Root>/PFC_Duty_D' */
} ExtY_General_PFC_Control_Loop_T;

/* Block states (default storage) */
extern DW_General_PFC_Control_Loop_T General_PFC_Control_Loop_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_General_PFC_Control_Loop_T General_PFC_Control_Loop_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_General_PFC_Control_Loop_T General_PFC_Control_Loop_Y;
extern const ConstB_General_PFC_Control_Lo_T General_PFC_Control_Loop_ConstB;/* constant block i/o */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T Full_load_Lo;          /* Variable: Full_load_Lo
                                        * Referenced by: '<S3>/Constant6'
                                        */
extern real32_T Full_load_Up;          /* Variable: Full_load_Up
                                        * Referenced by: '<S3>/Constant5'
                                        */
extern real32_T PFC_Duty_Lower_limit;  /* Variable: PFC_Duty_Lower_limit
                                        * Referenced by:
                                        *   '<S2>/Saturation5'
                                        *   '<S2>/Saturation6'
                                        *   '<S2>/Saturation7'
                                        *   '<S2>/Saturation8'
                                        */
extern real32_T PFC_Duty_Upper_limit;  /* Variable: PFC_Duty_Upper_limit
                                        * Referenced by:
                                        *   '<S2>/Saturation5'
                                        *   '<S2>/Saturation6'
                                        *   '<S2>/Saturation7'
                                        *   '<S2>/Saturation8'
                                        */
extern real32_T PFC_IKi;               /* Variable: PFC_IKi
                                        * Referenced by:
                                        *   '<S2>/Constant13'
                                        *   '<S2>/Constant14'
                                        *   '<S2>/Constant3'
                                        *   '<S2>/Constant7'
                                        */
extern real32_T PFC_IKp;               /* Variable: PFC_IKp
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S2>/Constant11'
                                        *   '<S2>/Constant12'
                                        *   '<S2>/Constant2'
                                        * 0.0096*3.1
                                        */
extern real32_T PFC_Isw_cmd_AB_Gain;   /* Variable: PFC_Isw_cmd_AB_Gain
                                        * Referenced by: '<S3>/Gain2'
                                        */
extern real32_T PFC_VKi;               /* Variable: PFC_VKi
                                        * Referenced by: '<S3>/Constant3'
                                        * 600*1.5
                                        */
extern real32_T PFC_VKp;               /* Variable: PFC_VKp
                                        * Referenced by: '<S3>/Constant1'
                                        * 0.1*0.7
                                        */

/* Model entry point functions */
extern void General_PFC_Control_Loop_initialize(void);
extern void General_PFC_Control_Loop_step(void);

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
 * '<Root>' : 'General_PFC_Control_Loop'
 * '<S1>'   : 'General_PFC_Control_Loop/PFC_Control_Loop'
 * '<S2>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop'
 * '<S3>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Voltage_loop'
 * '<S4>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID'
 * '<S5>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID1'
 * '<S6>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID2'
 * '<S7>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID3'
 * '<S8>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID/SaturationDynamic'
 * '<S9>'   : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID1/SaturationDynamic'
 * '<S10>'  : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID2/SaturationDynamic'
 * '<S11>'  : 'General_PFC_Control_Loop/PFC_Control_Loop/Current_loop/DiscretePID3/SaturationDynamic'
 * '<S12>'  : 'General_PFC_Control_Loop/PFC_Control_Loop/Voltage_loop/DiscretePID'
 * '<S13>'  : 'General_PFC_Control_Loop/PFC_Control_Loop/Voltage_loop/DiscretePID/SaturationDynamic'
 */

/*-
 * Requirements for '<Root>': General_PFC_Control_Loop
 */
#endif                              /* RTW_HEADER_General_PFC_Control_Loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
