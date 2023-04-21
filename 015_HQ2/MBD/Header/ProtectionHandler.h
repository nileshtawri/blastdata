/*
 * File: ProtectionHandler.h
 *
 * Code generated for Simulink model 'ProtectionHandler'.
 *
 * Model version                  : 1.345
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Jun 23 09:11:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ProtectionHandler_h_
#define RTW_HEADER_ProtectionHandler_h_
#ifndef ProtectionHandler_COMMON_INCLUDES_
# define ProtectionHandler_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ProtectionHandler_COMMON_INCLUDES_ */

#include "ProtectionHandler_types.h"

/* Child system includes */
#include "PowerDerating.h"
#include "Protection.h"

/* Block signals for model 'ProtectionHandler' */
typedef struct {
  ProtectionMessage Model1;            /* '<S2>/Model1' */
  ProtectionMessage Model2;            /* '<S2>/Model2' */
  ProtectionMessage Model3;            /* '<S2>/Model3' */
  ProtectionMessage Model4;            /* '<S2>/Model4' */
  ProtectionMessage Model5;            /* '<S2>/Model5' */
  ProtectionMessage Model6;            /* '<S2>/Model6' */
  ProtectionMessage Model7;            /* '<S2>/Model7' */
  ProtectionMessage Model9;            /* '<S2>/Model9' */
  ProtectionMessage Model10;           /* '<S2>/Model10' */
  ProtectionMessage Model11;           /* '<S2>/Model11' */
  ProtectionMessage Model12;           /* '<S2>/Model12' */
  ProtectionMessage Model13;           /* '<S2>/Model13' */
  ProtectionMessage Model14;           /* '<S2>/Model14' */
  ProtectionMessage Model15;           /* '<S2>/Model15' */
  ProtectionMessage Model8;            /* '<S2>/Model8' */
  ProtectionMessage Model16;           /* '<S2>/Model16' */
  ProtectionMessage Model17;           /* '<S2>/Model17' */
  ProtectionMessage Model18;           /* '<S2>/Model18' */
} B_ProtectionHandler_caua_T;

/* Block states (default storage) for model 'ProtectionHandler' */
typedef struct {
  MdlrefDW_Protection_T Model1_InstanceData;/* '<S2>/Model1' */
  MdlrefDW_Protection_T Model2_InstanceData;/* '<S2>/Model2' */
  MdlrefDW_Protection_T Model3_InstanceData;/* '<S2>/Model3' */
  MdlrefDW_Protection_T Model4_InstanceData;/* '<S2>/Model4' */
  MdlrefDW_Protection_T Model5_InstanceData;/* '<S2>/Model5' */
  MdlrefDW_Protection_T Model6_InstanceData;/* '<S2>/Model6' */
  MdlrefDW_Protection_T Model7_InstanceData;/* '<S2>/Model7' */
  MdlrefDW_Protection_T Model9_InstanceData;/* '<S2>/Model9' */
  MdlrefDW_Protection_T Model10_InstanceData;/* '<S2>/Model10' */
  MdlrefDW_Protection_T Model11_InstanceData;/* '<S2>/Model11' */
  MdlrefDW_Protection_T Model12_InstanceData;/* '<S2>/Model12' */
  MdlrefDW_Protection_T Model13_InstanceData;/* '<S2>/Model13' */
  MdlrefDW_Protection_T Model14_InstanceData;/* '<S2>/Model14' */
  MdlrefDW_Protection_T Model15_InstanceData;/* '<S2>/Model15' */
  MdlrefDW_Protection_T Model8_InstanceData;/* '<S2>/Model8' */
  MdlrefDW_Protection_T Model16_InstanceData;/* '<S2>/Model16' */
  MdlrefDW_Protection_T Model17_InstanceData;/* '<S2>/Model17' */
  MdlrefDW_Protection_T Model18_InstanceData;/* '<S2>/Model18' */
} DW_ProtectionHandler_fwu4_T;

/* Self model data, for model 'ProtectionHandler' */
struct tag_RTM_ProtectionHandler_T {
  DW_ProtectionHandler_fwu4_T dwork;
  B_ProtectionHandler_caua_T blockIO;
  RT_MODEL_PowerDerating_T Model;      /* '<S1>/Model' */
};

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern ProtectionParameter AnalogParameter_Protection[18];/* Variable: AnalogParameter_Protection
                                                           * Referenced by:
                                                           *   '<S2>/pp10_OBCTemp3'
                                                           *   '<S2>/pp11_PFCIswA'
                                                           *   '<S2>/pp12_PFCIswB'
                                                           *   '<S2>/pp13_PFCIswC'
                                                           *   '<S2>/pp14_PFCIswD'
                                                           *   '<S2>/pp15_HV_OVP_HW'
                                                           *   '<S2>/pp16_HV_SCP_HW'
                                                           *   '<S2>/pp17_LLC_OCP_HW'
                                                           *   '<S2>/pp18_PFC_OVP_HW'
                                                           *   '<S2>/pp1_PFCVolt'
                                                           *   '<S2>/pp2_LLCVolt'
                                                           *   '<S2>/pp3_LLCCurr'
                                                           *   '<S2>/pp4_GirdLVolt'
                                                           *   '<S2>/pp5_GirdLVoltRMS'
                                                           *   '<S2>/pp6_GridVoltFreq'
                                                           *   '<S2>/pp7_PFCAux'
                                                           *   '<S2>/pp8_OBCTemp1'
                                                           *   '<S2>/pp9_OBCTemp2'
                                                           */
extern void ProtectionHandler_Init(RT_MODEL_ProtectionHandler_T * const
  ProtectionHandler_M, const PhyValueOut_PFC *rtu_PhyValueOut_PFC, const
  PhyValueOut_LLC *rtu_PhyValueOut_LLC, const real32_T *rtu_flOBCVoltCmd, const
  real32_T *rtu_flOBCCurrCmd, const real32_T *rtu_flDCCurr, const real32_T
  *rtu_flCoolantTemp, const real32_T *rtu_EVSE_Imax, const boolean_T
  *rtu_blPowerDeratingEn, real32_T *rty_flLLCVoltCmd, real32_T *rty_flLLCCurrCmd,
  OBCProtectionMsg *rty_OBCProtectionMsg);
extern void Protection_PowerDeratingTrigger(RT_MODEL_ProtectionHandler_T * const
  ProtectionHandler_M, const PhyValueOut_PFC *rtu_PhyValueOut_PFC, const
  PhyValueOut_LLC *rtu_PhyValueOut_LLC, const real32_T *rtu_flOBCVoltCmd, const
  real32_T *rtu_flOBCCurrCmd, const real32_T *rtu_flDCCurr, const real32_T
  *rtu_flCoolantTemp, const real32_T *rtu_EVSE_Imax, const boolean_T
  *rtu_blPowerDeratingEn, real32_T *rty_flLLCVoltCmd, real32_T *rty_flLLCCurrCmd);
extern void ProtectionHan_ProtectionTrigger(RT_MODEL_ProtectionHandler_T * const
  ProtectionHandler_M, const PhyValueOut_PFC *rtu_PhyValueOut_PFC, const
  PhyValueOut_LLC *rtu_PhyValueOut_LLC, const PhyValueOut_Other
  *rtu_PhyValueOut_Other, const boolean_T *rtu_blHV_OVP_HW, const boolean_T
  *rtu_blHV_SCP_HW, const boolean_T *rtu_blLLC_OCP_HW, const boolean_T
  *rtu_blPFC_OVP_HW, const boolean_T *rtu_blFault_CMPSS, const boolean_T
  *rtu_blCAN_LOSS, const boolean_T *rtu_blCali_Conf_Err, boolean_T
  *rty_blTemporaryFault, boolean_T *rty_blCriticalFault, OBCProtectionMsg
  *rty_OBCProtectionMsg);

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
 * '<Root>' : 'ProtectionHandler'
 * '<S1>'   : 'ProtectionHandler/ProtectionHandler'
 * '<S2>'   : 'ProtectionHandler/ProtectionHandler/Fault_judgement'
 * '<S3>'   : 'ProtectionHandler/ProtectionHandler/Integration_Fault'
 */

/*-
 * Requirements for '<Root>': ProtectionHandler
 */
#endif                                 /* RTW_HEADER_ProtectionHandler_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
