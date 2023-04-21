/*
 * File: Protection.c
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

#include "Protection.h"
#include "Protection_private.h"
#define IN_Retry_Time_count_Judgement_L (4U)
#define IN_Retry_Time_count_Judgement_U (4U)
#define P_IN_Error_Recovery_Waiting_Low (2U)
#define P_IN_Retry_Time_count_Limit_Low (5U)
#define Pr_IN_Error_Recovery_Waiting_Up (2U)
#define Pr_IN_Retry_Time_count_Limit_Up (5U)
#define Prote_IN_Retry_Time_Waiting_Low (3U)
#define Protec_IN_Retry_Time_Waiting_Up (3U)
#define Protecti_IN_Recovery_Time_count (1U)
#define Protection_IN_ErrorLog_Low     (1U)
#define Protection_IN_ErrorLog_Up      (1U)
#define Protection_IN_Error_Judge      (1U)
#define Protection_IN_Error_Judge_anuw (2U)
#define Protection_IN_Function_Disable (1U)
#define Protection_IN_Function_Enable  (2U)
#define Protection_IN_NO_ACTIVE_CHILD  (0U)
#define Protection_IN_TripHigh_Error   (2U)
#define Protection_IN_TripLow_Error    (2U)
#define Protection_IN_Trip_Enable      (3U)
#define Protection_IN_Trip_Time_count  (4U)

/* System initialize for referenced model: 'Protection' */
void Protection_Init(ProtectionMessage *rty_ProtectionMessage,
                     B_Protection_caua_T *localB)
{
  /* SystemInitialize for BusCreator generated from: '<Root>/ProtectionMessage' incorporates:
   *  Chart: '<S3>/Chart1'
   *  Chart: '<S4>/Chart1'
   */
  rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
  rty_ProtectionMessage->Error_Up = (boolean_T)0;
  rty_ProtectionMessage->Retry_Count_Up = localB->Retry_Count_Up;
  rty_ProtectionMessage->FaultValue_Up = localB->FaultValue_Up;
  rty_ProtectionMessage->Temp_Error_Low = (boolean_T)0;
  rty_ProtectionMessage->Error_Low = (boolean_T)0;
  rty_ProtectionMessage->Retry_Count_Low = localB->Retry_Count_Low;
  rty_ProtectionMessage->FaultValue_Low = localB->FaultValue_Low;
}

/* Output and update for referenced model: 'Protection' */
void Protection(const real32_T *rtu_PhyValue, const ProtectionParameter
                *rtu_ProtectionParameter, ProtectionMessage
                *rty_ProtectionMessage, B_Protection_caua_T *localB,
                DW_Protection_fwu4_T *localDW)
{
  boolean_T rtb_TripLow_Error;
  boolean_T Error_Up;
  boolean_T Error_Low;
  uint16_T qY;

  /* Chart: '<S6>/Chart' incorporates:
   *  Product: '<S6>/Divide'
   *  Product: '<S6>/Divide1'
   */
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c3_Protection == 0U) {
    localDW->is_active_c3_Protection = 1U;
    localDW->is_c3_Protection = Protection_IN_Function_Enable;
    localDW->is_Function_Enable = Protection_IN_Trip_Enable;
    localB->TripHigh_Error = (boolean_T)0;
  } else if (localDW->is_c3_Protection == 1U) {
    if (rtu_ProtectionParameter->TripEnable_Up != 84U) {
      localDW->is_c3_Protection = Protection_IN_Function_Enable;
      localDW->is_Function_Enable = Protection_IN_Trip_Enable;
      localB->TripHigh_Error = (boolean_T)0;
    }
  } else {
    /* case IN_Function_Enable: */
    if (rtu_ProtectionParameter->TripEnable_Up == 84U) {
      localDW->is_Function_Enable = Protection_IN_NO_ACTIVE_CHILD;
      localDW->is_c3_Protection = Protection_IN_Function_Disable;
      localB->TripHigh_Error = (boolean_T)0;
    } else {
      switch (localDW->is_Function_Enable) {
       case Protecti_IN_Recovery_Time_count:
        if ((*rtu_PhyValue) >= rtu_ProtectionParameter->RecoverPoint_Up) {
          localDW->is_Function_Enable = Protection_IN_TripHigh_Error;
          localB->TripHigh_Error = (boolean_T)1;
        } else if ((localDW->temporalCounter_i1 >= ((uint32_T)((real32_T)
                      (rtu_ProtectionParameter->RecoverTime_Up /
                       rtu_ProtectionParameter->SampleTime)))) &&
                   ((*rtu_PhyValue) < rtu_ProtectionParameter->RecoverPoint_Up))
        {
          localDW->is_Function_Enable = Protection_IN_Trip_Enable;
          localB->TripHigh_Error = (boolean_T)0;
        } else {
          localB->TripHigh_Error = (boolean_T)1;
        }
        break;

       case Protection_IN_TripHigh_Error:
        if ((*rtu_PhyValue) < rtu_ProtectionParameter->RecoverPoint_Up) {
          localDW->is_Function_Enable = Protecti_IN_Recovery_Time_count;
          localDW->temporalCounter_i1 = 0UL;
          localB->TripHigh_Error = (boolean_T)1;
        } else {
          localB->TripHigh_Error = (boolean_T)1;
        }
        break;

       case Protection_IN_Trip_Enable:
        if ((*rtu_PhyValue) > rtu_ProtectionParameter->TripPoint_Up) {
          localDW->is_Function_Enable = Protection_IN_Trip_Time_count;
          localDW->temporalCounter_i1 = 0UL;
          localB->TripHigh_Error = (boolean_T)0;
        } else {
          localB->TripHigh_Error = (boolean_T)0;
        }
        break;

       default:
        /* case IN_Trip_Time_count: */
        if ((*rtu_PhyValue) < rtu_ProtectionParameter->TripPoint_Up) {
          localDW->is_Function_Enable = Protection_IN_Trip_Enable;
          localB->TripHigh_Error = (boolean_T)0;
        } else if ((localDW->temporalCounter_i1 >= ((uint32_T)((real32_T)
                      (rtu_ProtectionParameter->TripTime_Up /
                       rtu_ProtectionParameter->SampleTime)))) &&
                   ((*rtu_PhyValue) > rtu_ProtectionParameter->TripPoint_Up)) {
          localDW->is_Function_Enable = Protection_IN_TripHigh_Error;
          localB->TripHigh_Error = (boolean_T)1;
        } else {
          localB->TripHigh_Error = (boolean_T)0;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Chart: '<S4>/Chart1' incorporates:
   *  Product: '<S4>/Divide'
   */
  if (localDW->temporalCounter_i1_cufv < MAX_uint32_T) {
    localDW->temporalCounter_i1_cufv++;
  }

  if (localDW->is_active_c2_Protection == 0U) {
    localDW->is_active_c2_Protection = 1U;
    localDW->is_c2_Protection = Protection_IN_Function_Enable;
    localDW->is_Function_Enable_cc0g = Protection_IN_Error_Judge;

    /* BusCreator generated from: '<Root>/ProtectionMessage' */
    rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
    Error_Up = (boolean_T)0;
  } else if (localDW->is_c2_Protection == 1U) {
    if (rtu_ProtectionParameter->RetryEnable_Up == 84U) {
      localDW->is_Function_Disable = Protection_IN_NO_ACTIVE_CHILD;
      localDW->is_c2_Protection = Protection_IN_Function_Enable;
      localDW->is_Function_Enable_cc0g = Protection_IN_Error_Judge;

      /* BusCreator generated from: '<Root>/ProtectionMessage' */
      rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
      Error_Up = (boolean_T)0;
    } else if (localDW->is_Function_Disable == 1U) {
      if (!localB->TripHigh_Error) {
        localDW->is_Function_Disable = Protection_IN_Error_Judge_anuw;

        /* BusCreator generated from: '<Root>/ProtectionMessage' */
        rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
        Error_Up = (boolean_T)0;
        localB->Retry_Count_Up = 0U;
        localB->FaultValue_Up = 0.0F;
      } else {
        /* BusCreator generated from: '<Root>/ProtectionMessage' */
        rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
        Error_Up = (boolean_T)0;
      }
    } else {
      /* case IN_Error_Judge: */
      if (localB->TripHigh_Error) {
        localB->FaultValue_Up = *rtu_PhyValue;
        localDW->is_Function_Disable = Protection_IN_ErrorLog_Up;

        /* BusCreator generated from: '<Root>/ProtectionMessage' */
        rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
        Error_Up = (boolean_T)0;
      } else {
        /* BusCreator generated from: '<Root>/ProtectionMessage' */
        rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
        Error_Up = (boolean_T)0;
        localB->Retry_Count_Up = 0U;
        localB->FaultValue_Up = 0.0F;
      }
    }
  } else {
    /* case IN_Function_Enable: */
    if (rtu_ProtectionParameter->RetryEnable_Up != 84U) {
      localDW->is_Function_Enable_cc0g = Protection_IN_NO_ACTIVE_CHILD;
      localDW->is_c2_Protection = Protection_IN_Function_Disable;
      localDW->is_Function_Disable = Protection_IN_Error_Judge_anuw;

      /* BusCreator generated from: '<Root>/ProtectionMessage' */
      rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
      Error_Up = (boolean_T)0;
      localB->Retry_Count_Up = 0U;
      localB->FaultValue_Up = 0.0F;
    } else {
      switch (localDW->is_Function_Enable_cc0g) {
       case Protection_IN_Error_Judge:
        if (localB->TripHigh_Error) {
          localB->FaultValue_Up = *rtu_PhyValue;
          localDW->is_Function_Enable_cc0g = Pr_IN_Error_Recovery_Waiting_Up;

          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)0;
        } else {
          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
          Error_Up = (boolean_T)0;
        }
        break;

       case Pr_IN_Error_Recovery_Waiting_Up:
        if (!localB->TripHigh_Error) {
          localDW->is_Function_Enable_cc0g = Protec_IN_Retry_Time_Waiting_Up;
          localDW->temporalCounter_i1_cufv = 0UL;

          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)0;
        } else {
          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)0;
        }
        break;

       case Protec_IN_Retry_Time_Waiting_Up:
        if (localDW->temporalCounter_i1_cufv >= ((uint32_T)((real32_T)
              (rtu_ProtectionParameter->RetryTime_Up /
               rtu_ProtectionParameter->SampleTime)))) {
          localDW->is_Function_Enable_cc0g = IN_Retry_Time_count_Judgement_U;

          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)0;
        } else {
          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)0;
        }
        break;

       case IN_Retry_Time_count_Judgement_U:
        if ((rtu_ProtectionParameter->RetryLimit_Up == 0U) ||
            (localB->Retry_Count_Up < rtu_ProtectionParameter->RetryLimit_Up)) {
          qY = localB->Retry_Count_Up + /*MW:OvSatOk*/ 1U;
          if (qY < localB->Retry_Count_Up) {
            qY = MAX_uint16_T;
          }

          localB->Retry_Count_Up = qY;
          localDW->is_Function_Enable_cc0g = Protection_IN_Error_Judge;

          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)0;
          Error_Up = (boolean_T)0;
        } else if (localB->Retry_Count_Up >=
                   rtu_ProtectionParameter->RetryLimit_Up) {
          localDW->is_Function_Enable_cc0g = Pr_IN_Retry_Time_count_Limit_Up;

          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)1;
        } else {
          /* BusCreator generated from: '<Root>/ProtectionMessage' */
          rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
          Error_Up = (boolean_T)0;
        }
        break;

       default:
        /* BusCreator generated from: '<Root>/ProtectionMessage' */
        /* case IN_Retry_Time_count_Limit_Up: */
        rty_ProtectionMessage->Temp_Error_Up = (boolean_T)1;
        Error_Up = (boolean_T)1;
        break;
      }
    }
  }

  /* End of Chart: '<S4>/Chart1' */

  /* Chart: '<S5>/Chart' incorporates:
   *  Product: '<S5>/Divide'
   *  Product: '<S5>/Divide1'
   */
  if (localDW->temporalCounter_i1_clcf < MAX_uint32_T) {
    localDW->temporalCounter_i1_clcf++;
  }

  if (localDW->is_active_c4_Protection == 0U) {
    localDW->is_active_c4_Protection = 1U;
    localDW->is_c4_Protection = Protection_IN_Function_Enable;
    localDW->is_Function_Enable_czmp = Protection_IN_Trip_Enable;
    rtb_TripLow_Error = (boolean_T)0;
  } else if (localDW->is_c4_Protection == 1U) {
    if (rtu_ProtectionParameter->TripEnable_Low != 84U) {
      localDW->is_c4_Protection = Protection_IN_Function_Enable;
      localDW->is_Function_Enable_czmp = Protection_IN_Trip_Enable;
      rtb_TripLow_Error = (boolean_T)0;
    } else {
      rtb_TripLow_Error = (boolean_T)0;
    }
  } else {
    /* case IN_Function_Enable: */
    if (rtu_ProtectionParameter->TripEnable_Low == 84U) {
      localDW->is_Function_Enable_czmp = Protection_IN_NO_ACTIVE_CHILD;
      localDW->is_c4_Protection = Protection_IN_Function_Disable;
      rtb_TripLow_Error = (boolean_T)0;
    } else {
      switch (localDW->is_Function_Enable_czmp) {
       case Protecti_IN_Recovery_Time_count:
        if ((*rtu_PhyValue) <= rtu_ProtectionParameter->RecoverPoint_Low) {
          localDW->is_Function_Enable_czmp = Protection_IN_TripLow_Error;
          rtb_TripLow_Error = (boolean_T)1;
        } else if ((localDW->temporalCounter_i1_clcf >= ((uint32_T)((real32_T)
                      (rtu_ProtectionParameter->RecoverTime_Low /
                       rtu_ProtectionParameter->SampleTime)))) &&
                   ((*rtu_PhyValue) > rtu_ProtectionParameter->RecoverPoint_Low))
        {
          localDW->is_Function_Enable_czmp = Protection_IN_Trip_Enable;
          rtb_TripLow_Error = (boolean_T)0;
        } else {
          rtb_TripLow_Error = (boolean_T)1;
        }
        break;

       case Protection_IN_TripLow_Error:
        if ((*rtu_PhyValue) > rtu_ProtectionParameter->RecoverPoint_Low) {
          localDW->is_Function_Enable_czmp = Protecti_IN_Recovery_Time_count;
          localDW->temporalCounter_i1_clcf = 0UL;
          rtb_TripLow_Error = (boolean_T)1;
        } else {
          rtb_TripLow_Error = (boolean_T)1;
        }
        break;

       case Protection_IN_Trip_Enable:
        if ((*rtu_PhyValue) < rtu_ProtectionParameter->TripPoint_Low) {
          localDW->is_Function_Enable_czmp = Protection_IN_Trip_Time_count;
          localDW->temporalCounter_i1_clcf = 0UL;
          rtb_TripLow_Error = (boolean_T)0;
        } else {
          rtb_TripLow_Error = (boolean_T)0;
        }
        break;

       default:
        /* case IN_Trip_Time_count: */
        if ((*rtu_PhyValue) > rtu_ProtectionParameter->TripPoint_Low) {
          localDW->is_Function_Enable_czmp = Protection_IN_Trip_Enable;
          rtb_TripLow_Error = (boolean_T)0;
        } else if ((localDW->temporalCounter_i1_clcf >= ((uint32_T)((real32_T)
                      (rtu_ProtectionParameter->TripTime_Low /
                       rtu_ProtectionParameter->SampleTime)))) &&
                   ((*rtu_PhyValue) < rtu_ProtectionParameter->TripPoint_Low)) {
          localDW->is_Function_Enable_czmp = Protection_IN_TripLow_Error;
          rtb_TripLow_Error = (boolean_T)1;
        } else {
          rtb_TripLow_Error = (boolean_T)0;
        }
        break;
      }
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Chart: '<S3>/Chart1' incorporates:
   *  Product: '<S3>/Divide'
   */
  if (localDW->temporalCounter_i1_hl0c < MAX_uint32_T) {
    localDW->temporalCounter_i1_hl0c++;
  }

  if (localDW->is_active_c5_Protection == 0U) {
    localDW->is_active_c5_Protection = 1U;
    localDW->is_c5_Protection = Protection_IN_Function_Enable;
    localDW->is_Function_Enable_mm01 = Protection_IN_Error_Judge;
    rtb_TripLow_Error = (boolean_T)0;
    Error_Low = (boolean_T)0;
  } else if (localDW->is_c5_Protection == 1U) {
    if (rtu_ProtectionParameter->RetryEnable_Low == 84U) {
      localDW->is_Function_Disable_id2k = Protection_IN_NO_ACTIVE_CHILD;
      localDW->is_c5_Protection = Protection_IN_Function_Enable;
      localDW->is_Function_Enable_mm01 = Protection_IN_Error_Judge;
      rtb_TripLow_Error = (boolean_T)0;
      Error_Low = (boolean_T)0;
    } else if (localDW->is_Function_Disable_id2k == 1U) {
      if (!rtb_TripLow_Error) {
        localDW->is_Function_Disable_id2k = Protection_IN_Error_Judge_anuw;
        Error_Low = (boolean_T)0;
        localB->Retry_Count_Low = 0U;
        localB->FaultValue_Low = 0.0F;
      } else {
        Error_Low = (boolean_T)0;
      }
    } else {
      /* case IN_Error_Judge: */
      if (rtb_TripLow_Error) {
        localB->FaultValue_Low = *rtu_PhyValue;
        localDW->is_Function_Disable_id2k = Protection_IN_ErrorLog_Low;
        Error_Low = (boolean_T)0;
      } else {
        Error_Low = (boolean_T)0;
        localB->Retry_Count_Low = 0U;
        localB->FaultValue_Low = 0.0F;
      }
    }
  } else {
    /* case IN_Function_Enable: */
    if (rtu_ProtectionParameter->RetryEnable_Low != 84U) {
      localDW->is_Function_Enable_mm01 = Protection_IN_NO_ACTIVE_CHILD;
      localDW->is_c5_Protection = Protection_IN_Function_Disable;
      localDW->is_Function_Disable_id2k = Protection_IN_Error_Judge_anuw;
      rtb_TripLow_Error = (boolean_T)0;
      Error_Low = (boolean_T)0;
      localB->Retry_Count_Low = 0U;
      localB->FaultValue_Low = 0.0F;
    } else {
      switch (localDW->is_Function_Enable_mm01) {
       case Protection_IN_Error_Judge:
        if (rtb_TripLow_Error) {
          localB->FaultValue_Low = *rtu_PhyValue;
          localDW->is_Function_Enable_mm01 = P_IN_Error_Recovery_Waiting_Low;
          Error_Low = (boolean_T)0;
        } else {
          Error_Low = (boolean_T)0;
        }
        break;

       case P_IN_Error_Recovery_Waiting_Low:
        if (!rtb_TripLow_Error) {
          localDW->is_Function_Enable_mm01 = Prote_IN_Retry_Time_Waiting_Low;
          localDW->temporalCounter_i1_hl0c = 0UL;
          rtb_TripLow_Error = (boolean_T)1;
          Error_Low = (boolean_T)0;
        } else {
          Error_Low = (boolean_T)0;
        }
        break;

       case Prote_IN_Retry_Time_Waiting_Low:
        if (localDW->temporalCounter_i1_hl0c >= ((uint32_T)((real32_T)
              (rtu_ProtectionParameter->RetryTime_Low /
               rtu_ProtectionParameter->SampleTime)))) {
          localDW->is_Function_Enable_mm01 = IN_Retry_Time_count_Judgement_L;
          rtb_TripLow_Error = (boolean_T)1;
          Error_Low = (boolean_T)0;
        } else {
          rtb_TripLow_Error = (boolean_T)1;
          Error_Low = (boolean_T)0;
        }
        break;

       case IN_Retry_Time_count_Judgement_L:
        if (localB->Retry_Count_Low >= rtu_ProtectionParameter->RetryLimit_Low)
        {
          localDW->is_Function_Enable_mm01 = P_IN_Retry_Time_count_Limit_Low;
          rtb_TripLow_Error = (boolean_T)1;
          Error_Low = (boolean_T)1;
        } else if (localB->Retry_Count_Low <
                   rtu_ProtectionParameter->RetryLimit_Low) {
          qY = localB->Retry_Count_Low + /*MW:OvSatOk*/ 1U;
          if (qY < localB->Retry_Count_Low) {
            qY = MAX_uint16_T;
          }

          localB->Retry_Count_Low = qY;
          localDW->is_Function_Enable_mm01 = Protection_IN_Error_Judge;
          rtb_TripLow_Error = (boolean_T)0;
          Error_Low = (boolean_T)0;
        } else {
          rtb_TripLow_Error = (boolean_T)1;
          Error_Low = (boolean_T)0;
        }
        break;

       default:
        /* case IN_Retry_Time_count_Limit_Low: */
        rtb_TripLow_Error = (boolean_T)1;
        Error_Low = (boolean_T)1;
        break;
      }
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* BusCreator generated from: '<Root>/ProtectionMessage' */
  rty_ProtectionMessage->Error_Up = Error_Up;
  rty_ProtectionMessage->Retry_Count_Up = localB->Retry_Count_Up;
  rty_ProtectionMessage->FaultValue_Up = localB->FaultValue_Up;
  rty_ProtectionMessage->Temp_Error_Low = rtb_TripLow_Error;
  rty_ProtectionMessage->Error_Low = Error_Low;
  rty_ProtectionMessage->Retry_Count_Low = localB->Retry_Count_Low;
  rty_ProtectionMessage->FaultValue_Low = localB->FaultValue_Low;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
