/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//
// Included Files
//

#include "driverlib.h"
#include "device.h"
#include "rtwtypes.h"
#include "nvm.h"
//#include "CAN_define.h"

#define GPIO_PIN_OUTPUTXBAR2 25

#define ADCA_module_BASE ADCA_BASE
#define ADCA_module_RESULT_BASE ADCARESULT_BASE
#define ADCA_CLK_DIV ADC_CLK_DIV_2_0

#define ADCB_module_BASE ADCB_BASE
#define ADCB_module_RESULT_BASE ADCBRESULT_BASE
#define ADCB_CLK_DIV ADC_CLK_DIV_2_0

#define ADCC_module_BASE ADCC_BASE
#define ADCC_module_RESULT_BASE ADCCRESULT_BASE
#define ADCC_CLK_DIV ADC_CLK_DIV_2_0


#define OBC_VOLT_CURR_BASE CMPSS1_BASE
#define PFC_AUX_ADC_BASE CMPSS3_BASE
#define NTC_PFC_MOS_ADC_BASE CMPSS4_BASE
#define NTC_LLC_MOS_ADC_BASE CMPSS5_BASE
#define PFC_CSA_CSD_BASE CMPSS6_BASE
#define PFC_CSB_CSC_BASE CMPSS2_BASE
#define BULK_VOLT_ADC_BASE CMPSS7_BASE
#define DACA_module_BASE DACA_BASE
#define DACB_module_BASE DACB_BASE

#define Can_DATA_LENGTH    8
#define RX_MSG_OBJ_ID      1
#define RX_MSG_OBJ_ID2     2
#define RX_MSG_OBJ_ID3     3
#define TX_MSG_OBJ_ID4     4
#define TX_MSG_OBJ_ID5     5
#define TX_MSG_OBJ_ID6     6
#define TX_MSG_OBJ_ID7     7
#define TX_MSG_OBJ_ID8     8
#define TX_MSG_OBJ_ID9     9
#define TX_MSG_OBJ_ID10    10
#define TX_MSG_OBJ_ID11    11

#define CAN_ID              (0x100)
#define CANRXA_GPIO_CFG      GPIO_30_CANRXA
#define CANTXA_GPIO_CFG      GPIO_31_CANTXA

// Parameter define
# define EPWM_A_LLC EPWM1_BASE
# define EPWM_A_LLC_INITIAL_PERIOD    556U //100kHz, 10n*1000=10us
# define EPWM_A_LLC_INITIAL_PHASE       0U
# define EPWM_A_LLC_INITIAL_CMPA      278U
# define EPWM_A_LLC_INITIAL_CMPB        0U
# define EPWM_A_LLC_TRIP_SIGNAL      EPWM_DC_COMBINATIONAL_TRIPIN1 | EPWM_DC_COMBINATIONAL_TRIPIN2 | EPWM_DC_COMBINATIONAL_TRIPIN3 | EPWM_DC_COMBINATIONAL_TRIPIN6 | EPWM_DC_COMBINATIONAL_TRIPIN4
# define EPWM_A_LLC_DEADBAND_RED       20U
# define EPWM_A_LLC_DEADBAND_FED       20U

# define EPWM_B_LLC EPWM2_BASE
# define EPWM_B_LLC_INITIAL_PERIOD    556U //100kHz, 10n*1000=10us
# define EPWM_B_LLC_INITIAL_PHASE     278U
# define EPWM_B_LLC_INITIAL_CMPA      278U
# define EPWM_B_LLC_INITIAL_CMPB        0U
# define EPWM_B_LLC_TRIP_SIGNAL      EPWM_DC_COMBINATIONAL_TRIPIN1 | EPWM_DC_COMBINATIONAL_TRIPIN2 | EPWM_DC_COMBINATIONAL_TRIPIN3 | EPWM_DC_COMBINATIONAL_TRIPIN6 | EPWM_DC_COMBINATIONAL_TRIPIN4
# define EPWM_B_LLC_DEADBAND_RED       20U
# define EPWM_B_LLC_DEADBAND_FED       20U

# define EPWM_A_PFC EPWM5_BASE
# define EPWM_A_PFC_INITIAL_PERIOD    769U //65kHz, 10n*769.23*2=15.38us
# define EPWM_A_PFC_INITIAL_PHASE       0U
# define EPWM_A_PFC_INITIAL_CMPA        0U
# define EPWM_A_PFC_INITIAL_CMPB      770U
# define EPWM_A_PFC_TRIP_SIGNAL       EPWM_DC_COMBINATIONAL_TRIPIN1 | EPWM_DC_COMBINATIONAL_TRIPIN2 | EPWM_DC_COMBINATIONAL_TRIPIN3 | EPWM_DC_COMBINATIONAL_TRIPIN6 | EPWM_DC_COMBINATIONAL_TRIPIN4
# define EPWM_A_PFC_DEADBAND_RED       10U
# define EPWM_A_PFC_DEADBAND_FED       10U

# define EPWM_B_PFC EPWM7_BASE
# define EPWM_B_PFC_INITIAL_PERIOD    769U //65kHz, 10n*769.23*2=15.38us
# define EPWM_B_PFC_INITIAL_PHASE     384U
# define EPWM_B_PFC_INITIAL_CMPA        0U
# define EPWM_B_PFC_INITIAL_CMPB      770U
# define EPWM_B_PFC_TRIP_SIGNAL       EPWM_DC_COMBINATIONAL_TRIPIN1 | EPWM_DC_COMBINATIONAL_TRIPIN2 | EPWM_DC_COMBINATIONAL_TRIPIN3 | EPWM_DC_COMBINATIONAL_TRIPIN6 | EPWM_DC_COMBINATIONAL_TRIPIN4
# define EPWM_B_PFC_DEADBAND_RED       10U
# define EPWM_B_PFC_DEADBAND_FED       10U

# define EPWM_RELAY EPWM6_BASE
# define EPWM_RELAY_INITIAL_PERIOD    2500U //20kHz, 10n*2500*2=50us
# define EPWM_RELAY_INITIAL_PHASE       0U
# define EPWM_RELAY_INITIAL_CMPA        0U
# define EPWM_RELAY_INITIAL_CMPB        0U
# define EPWM_RELAY_TRIP_SIGNAL      EPWM_DC_COMBINATIONAL_TRIPIN4
# define EPWM_RELAY_DEADBAND_RED       10U
# define EPWM_RELAY_DEADBAND_FED       10U

#define TIMER1OUT           10000U         // Timer1 period time 1:1us

#define DACA_module_BASE DACA_BASE
#define DACB_module_BASE DACB_BASE

// Interrupt Setings for INT_ADCA_module_1
#define INT_ADCA_module_1 INT_ADCA1
#define INT_ADCA_module_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1


extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;

extern uint16_T NTC_LLC_MOS_CMPSS;
extern uint16_T PFC_AUX_CMPSS;
extern uint16_T OBC_VOLT_CMPSS;
extern uint16_T OBC_CURR_CMPSS;
extern uint16_T PFC_CS_CMPSS;
extern uint16_T NTC_PFC_MOS_CMPSS;
extern uint16_T BULK_VOLT_CMPSS;
//
// Linker Defined variables
//
extern uint32_t Cla1ProgRunStart, Cla1ProgLoadStart, Cla1ProgLoadSize;
extern uint32_t Cla1ConstRunStart, Cla1ConstLoadStart, Cla1ConstLoadSize;

extern __interrupt void adcA1ISR(void);
extern __interrupt void sTimer1Isr(void);
extern __interrupt void canISR(void);


void    Board_init();
void    sADCTrigger_Epwm3Init();
void    CMPSS_init();
void    EPWMXBAR_init();
void    OUTPUTXBAR_init();
void    INPUTXBAR_init();
void    ADCA_init();
void    ADCB_init();
void    ADCC_init();
void    sPwmSetupInit();
void    sLLC_PWMInit();
void    sPFC_PWMInit();
void    sRELAY_PWMInit();
void    ASYSCTL_init();
void    SYNC_init();
void    INTERRUPT_init();
void    PinMux_init();
void    sTimerSetup(uint32_t timer1out);
void    initCLA();
void    CAN_init(void);
void	DAC_init(void);
void    CanVariableInit(void);
void    Ifx_CanHandler_processInbox(void);
void    Ifx_CanHandler_processOutbox(void);


//CLA C Tasks defined in Cla1Tasks_C.cla
__attribute__((interrupt))  void Cla1Task1();
__attribute__((interrupt))  void Cla1Task2();
__attribute__((interrupt))  void Cla1Task3();
__attribute__((interrupt))  void Cla1Task4();
__attribute__((interrupt))  void Cla1Task5();
__attribute__((interrupt))  void Cla1Task6();
__attribute__((interrupt))  void Cla1Task7();
__attribute__((interrupt))  void Cla1Task8();

#endif  // end of BOARD_H definition
