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
#include "driverlib.h"
#include "device.h"
#include <board.h>
#include <CAN_define.h>
#include "Configuration.h"

uint16_T NTC_LLC_MOS_CMPSS = 0;
uint16_T PFC_AUX_CMPSS = 0;
uint16_T OBC_VOLT_CMPSS = 0;
uint16_T OBC_CURR_CMPSS = 0;
uint16_T PFC_CS_CMPSS = 0;
uint16_T NTC_PFC_MOS_CMPSS = 0;
uint16_T BULK_VOLT_CMPSS = 0;

void Board_init()
{
    EALLOW;

    PinMux_init();
    ASYSCTL_init();
	CMPSS_init();
    EPWMXBAR_init();
    INPUTXBAR_init();
    OUTPUTXBAR_init();
    ADCA_init();
    ADCB_init();
    ADCC_init();
    sPwmSetupInit();
    INTERRUPT_init();
    sTimerSetup(TIMER1OUT);
    CAN_init();
	DAC_init();
	
    EDIS;

    CanVariableInit();
}

void PinMux_init()
{

    GPIO_setPinConfig(GPIO_30_CANRXA);
    GPIO_setPinConfig(GPIO_31_CANTXA);

    //
    // Configure GPIO/1 as EPWM1A/1B pins respectively LLC_D_C
    //
    GPIO_setPadConfig(0, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_0_EPWM1A);
    GPIO_setPadConfig(1, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_1_EPWM1B);

    //
    // Configure GPIO2/3 as EPWM2A/2B pins respectively LLC_A_B
    //
    GPIO_setPadConfig(2, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_2_EPWM2A);
    GPIO_setPadConfig(3, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_3_EPWM2B);

    //
    // OUTPUTXBAR3 -> LLC_EN_DOL Pinmux
    //
    GPIO_setPinConfig(GPIO_14_OUTPUTXBAR3);

    // HWProtection_Diagnosis
    GPIO_setPinConfig(GPIO_15_GPIO15);
    GPIO_setPadConfig(15, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(15, GPIO_DIR_MODE_OUT);
    GPIO_writePin(15,0);

    // HWProtection_Diagnosis
    GPIO_setPinConfig(GPIO_5_GPIO5);
    GPIO_setPadConfig(5, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(5, GPIO_DIR_MODE_OUT);
    GPIO_writePin(5,0);

    //
    // OUTPUTXBAR4 -> PFC_EN_DOH Pinmux
    //
    GPIO_setPinConfig(GPIO_33_OUTPUTXBAR4);

    /**/GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_7_EPWM4B);
    //
    // Configure GPIO16/17 as EPWM5A/5B pins respectively (PFC_CTRL_A_PWM, PFC_CTRL_B_PWM)
    //
    GPIO_setPadConfig(16, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_16_EPWM5A);

    GPIO_setPadConfig(17, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_17_EPWM5B);

    //
    // Configure GPIO12/13 as EPWM7A/7B pins respectively (PFC_CTRL_C_PWM, PFC_CTRL_D_PWM)
    //
    GPIO_setPadConfig(12, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_12_EPWM7A);

    GPIO_setPadConfig(13, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_13_EPWM7B);

    //
    // Configure GPIO11 as EPWM6B pins respectively
    //

    GPIO_setPadConfig(11, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_11_EPWM6B);
	
    //GPIO_setMasterCore(29, GPIO_CORE_CPU1_CLA1);
    GPIO_setPinConfig(GPIO_29_GPIO29);
    GPIO_setPadConfig(29, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(29, GPIO_DIR_MODE_OUT);
    GPIO_writePin(29,0);
}

void ADCA_init(){
    //ADCA_module initialization

    // ADC Initialization: Write ADC configurations and power up the ADC
    // Configures the ADC module's offset trim
    ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
    // Configures the analog-to-digital converter module prescaler.
    ADC_setPrescaler(ADCA_module_BASE, ADCA_CLK_DIV);
    // Sets the timing of the end-of-conversion pulse
    ADC_setInterruptPulseMode(ADCA_module_BASE, ADC_PULSE_END_OF_CONV);
    // Powers up the analog-to-digital converter core.
    ADC_enableConverter(ADCA_module_BASE);
    // Delay for 1ms to allow ADC time to power up
    DEVICE_DELAY_US(5000);

    // SOC Configuration: Setup ADC EPWM channel and trigger settings
    // Disables SOC burst mode.
    ADC_disableBurstMode(ADCA_module_BASE);
    // Sets the priority mode of the SOCs.
    ADC_setSOCPriority(ADCA_module_BASE, ADC_PRI_ALL_ROUND_ROBIN);
    // Start of Conversion 0 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 0
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN5
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCA_module_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN3, 10U);
    ADC_setInterruptSOCTrigger(ADCA_module_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 1 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 1
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN6
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCA_module_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN6, 10U);
    ADC_setInterruptSOCTrigger(ADCA_module_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 2 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 2
    //      Trigger         : ADC_TRIGGER_EPWM5_SOCB
    //      Channel         : ADC_CH_ADCIN8
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCA_module_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM5_SOCB, ADC_CH_ADCIN4, 10U);
    ADC_setInterruptSOCTrigger(ADCA_module_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 3 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 3
    //      Trigger         : ADC_TRIGGER_EPWM5_SOCB
    //      Channel         : ADC_CH_ADCIN9
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCA_module_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM5_SOCA, ADC_CH_ADCIN9, 10U);
    ADC_setInterruptSOCTrigger(ADCA_module_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
    // ADC Interrupt 1 Configuration
    //      SOC/EOC number  : 0
    //      Interrupt Source: enabled
    //      Continuous Mode : disabled
    ADC_setInterruptSource(ADCA_module_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
    ADC_enableInterrupt(ADCA_module_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADCA_module_BASE, ADC_INT_NUMBER1);
    ADC_disableContinuousMode(ADCA_module_BASE, ADC_INT_NUMBER1);

}
void ADCB_init(){
    //ADCB_module initialization

    // ADC Initialization: Write ADC configurations and power up the ADC
    // Configures the ADC module's offset trim
    ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
    // Configures the analog-to-digital converter module prescaler.
    ADC_setPrescaler(ADCB_module_BASE, ADCB_CLK_DIV);
    // Sets the timing of the end-of-conversion pulse
    ADC_setInterruptPulseMode(ADCB_module_BASE, ADC_PULSE_END_OF_CONV);
    // Powers up the analog-to-digital converter core.
    ADC_enableConverter(ADCB_module_BASE);
    // Delay for 1ms to allow ADC time to power up
    DEVICE_DELAY_US(5000);

    // SOC Configuration: Setup ADC EPWM channel and trigger settings
    // Disables SOC burst mode.
    ADC_disableBurstMode(ADCB_module_BASE);
    // Sets the priority mode of the SOCs.
    ADC_setSOCPriority(ADCB_module_BASE, ADC_PRI_ALL_ROUND_ROBIN);
    // Start of Conversion 0 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 0
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 1 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 1
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN3
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN6, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 2
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 3
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 4
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 5
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER5, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER5, ADC_INT_SOC_TRIGGER_NONE);
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 6
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCB_module_BASE, ADC_SOC_NUMBER6, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCB_module_BASE, ADC_SOC_NUMBER6, ADC_INT_SOC_TRIGGER_NONE);

}
void ADCC_init(){
    //ADCC_module initialization

    // ADC Initialization: Write ADC configurations and power up the ADC
    // Configures the ADC module's offset trim
    ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_3_3V);
    // Configures the analog-to-digital converter module prescaler.
    ADC_setPrescaler(ADCC_module_BASE, ADCC_CLK_DIV);
    // Sets the timing of the end-of-conversion pulse
    ADC_setInterruptPulseMode(ADCC_module_BASE, ADC_PULSE_END_OF_CONV);
    // Powers up the analog-to-digital converter core.
    ADC_enableConverter(ADCC_module_BASE);
    // Delay for 1ms to allow ADC time to power up
    DEVICE_DELAY_US(5000);

    // SOC Configuration: Setup ADC EPWM channel and trigger settings
    // Disables SOC burst mode.
    ADC_disableBurstMode(ADCC_module_BASE);
    // Sets the priority mode of the SOCs.
    ADC_setSOCPriority(ADCC_module_BASE, ADC_PRI_ALL_ROUND_ROBIN);
    // Start of Conversion 0 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 0
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN0
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCC_module_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 10U);
    ADC_setInterruptSOCTrigger(ADCC_module_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 1 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 1
    //      Trigger         : ADC_TRIGGER_EPWM7_SOCA
    //      Channel         : ADC_CH_ADCIN1
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCC_module_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM7_SOCA, ADC_CH_ADCIN1, 10U);
    ADC_setInterruptSOCTrigger(ADCC_module_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 2 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 2
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN3
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCC_module_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN3, 10U);
    ADC_setInterruptSOCTrigger(ADCC_module_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 3 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 3
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN4
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCC_module_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN4, 10U);
    ADC_setInterruptSOCTrigger(ADCC_module_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 4 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 4
    //      Trigger         : ADC_TRIGGER_EPWM7_SOCA
    //      Channel         : ADC_CH_ADCIN5
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCC_module_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM7_SOCB, ADC_CH_ADCIN5, 10U);
    ADC_setInterruptSOCTrigger(ADCC_module_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
    // Start of Conversion 5 Configuration
    // Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
    //      SOC number      : 5
    //      Trigger         : ADC_TRIGGER_EPWM3_SOCA
    //      Channel         : ADC_CH_ADCIN6
    //      Sample Window   : 10 SYSCLK cycles
    //      Interrupt Trigger: ADC_INT_SOC_TRIGGER_ADCINT1
    ADC_setupSOC(ADCC_module_BASE, ADC_SOC_NUMBER5, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN6, 10U);
    ADC_setInterruptSOCTrigger(ADCC_module_BASE, ADC_SOC_NUMBER5, ADC_INT_SOC_TRIGGER_NONE);

}
void ASYSCTL_init(){
    // asysctl initialization
    // Disables the temperature sensor output to the ADC.
    ASysCtl_disableTemperatureSensor();
    // Set the analog voltage reference selection to internal.
    ASysCtl_setAnalogReferenceInternal( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
    // Set the internal analog voltage reference selection to 1.65V.
    ASysCtl_setAnalogReference1P65( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
}
 

void INTERRUPT_init(){

    // Interrupt Setings for INT_ADCA_module_1
    Interrupt_register(INT_ADCA_module_1, &adcA1ISR);
    Interrupt_enable(INT_ADCA_module_1);
    Interrupt_register(INT_TIMER1, &sTimer1Isr);
    Interrupt_enable(INT_TIMER1);
    Interrupt_register(INT_CANA0, &canISR);
    Interrupt_enable(INT_CANA0);
}

void SYNC_init(){
    SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT);
    //SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM7, SYSCTL_SYNC_IN_SRC_EPWM4SYNCOUT);
}

void sPwmSetupInit()
{
    // LLC_PWM1 initialization
    // LLC_PWM2 initialization
    sLLC_PWMInit();

    // PFC_PWM1 initialization
    // PFC_PWM2 initialization
    sPFC_PWMInit();

    // RELAY_PWM
    sRELAY_PWMInit();

    // ADC_Trigger
    sADCTrigger_Epwm3Init();
}

//
// initsTimerSetup - Function to configure CPU Timer1.
//
void sTimerSetup(uint32_t timer1out)
{
    uint32_t temp;

    temp = (uint32_t)(DEVICE_SYSCLK_FREQ / 1000000 * timer1out);

    CPUTimer_setPeriod(CPUTIMER1_BASE, temp);
    CPUTimer_setPreScaler(CPUTIMER1_BASE, 0);
    CPUTimer_stopTimer(CPUTIMER1_BASE);
    CPUTimer_reloadTimerCounter(CPUTIMER1_BASE);
    CPUTimer_setEmulationMode(CPUTIMER1_BASE,
                              CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
    CPUTimer_enableInterrupt(CPUTIMER1_BASE);
    CPUTimer_startTimer(CPUTIMER1_BASE);
}

void CMPSS_init(){
    // Select the value for CMPHNMXSEL.
    ASysCtl_selectCMPHNMux(ASYSCTL_CMPHNMUX_SELECT_1 | ASYSCTL_CMPHNMUX_SELECT_3 | ASYSCTL_CMPHNMUX_SELECT_4 | ASYSCTL_CMPHNMUX_SELECT_5 | ASYSCTL_CMPHNMUX_SELECT_6 | ASYSCTL_CMPHNMUX_SELECT_2 | ASYSCTL_CMPHNMUX_SELECT_7);
    // Select the value for CMPLNMXSEL.
    ASysCtl_selectCMPLNMux(ASYSCTL_CMPLNMUX_SELECT_1 | ASYSCTL_CMPLNMUX_SELECT_3 | ASYSCTL_CMPLNMUX_SELECT_4 | ASYSCTL_CMPLNMUX_SELECT_5 | ASYSCTL_CMPLNMUX_SELECT_6 | ASYSCTL_CMPLNMUX_SELECT_2 | ASYSCTL_CMPLNMUX_SELECT_7);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_1,3U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_1,0U);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_3,0U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_3,0U);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_4,1U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_4,1U);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_5,0U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_5,1U);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_6,2U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_6,3U);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_2,0U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_2,1U);
    // Select the value for CMPHPM[object Object]SEL.
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_7,3U);
    // Select the value for CMPLPM[object Object]SEL.
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_7,0U);

    //OBC_VOLT_CURR initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(OBC_VOLT_CURR_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(OBC_VOLT_CURR_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(OBC_VOLT_CURR_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(OBC_VOLT_CURR_BASE, OBC_CURR_CMPSS);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(OBC_VOLT_CURR_BASE, OBC_VOLT_CMPSS);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(OBC_VOLT_CURR_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(OBC_VOLT_CURR_BASE, 1023U, 32U, 31U);
    // Initializes the digital filter of the high comparator.
    CMPSS_initFilterHigh(OBC_VOLT_CURR_BASE);
    // Initializes the digital filter of the low comparator.
    CMPSS_initFilterLow(OBC_VOLT_CURR_BASE);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(OBC_VOLT_CURR_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(OBC_VOLT_CURR_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(OBC_VOLT_CURR_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(OBC_VOLT_CURR_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(OBC_VOLT_CURR_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(OBC_VOLT_CURR_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(OBC_VOLT_CURR_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(OBC_VOLT_CURR_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(OBC_VOLT_CURR_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(OBC_VOLT_CURR_BASE);

    //PFC_AUX_ADC initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(PFC_AUX_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(PFC_AUX_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(PFC_AUX_ADC_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(PFC_AUX_ADC_BASE, PFC_AUX_CMPSS);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(PFC_AUX_ADC_BASE,4095U);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(PFC_AUX_ADC_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(PFC_AUX_ADC_BASE, 0U, 1U, 1U);
    // Initializes the digital filter of the high comparator.
    CMPSS_initFilterHigh(PFC_AUX_ADC_BASE);
    // Initializes the digital filter of the low comparator.
    CMPSS_initFilterLow(PFC_AUX_ADC_BASE);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(PFC_AUX_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(PFC_AUX_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(PFC_AUX_ADC_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(PFC_AUX_ADC_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(PFC_AUX_ADC_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(PFC_AUX_ADC_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(PFC_AUX_ADC_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(PFC_AUX_ADC_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(PFC_AUX_ADC_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(PFC_AUX_ADC_BASE);

    //NTC_PFC_MOS_ADC initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(NTC_PFC_MOS_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(NTC_PFC_MOS_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(NTC_PFC_MOS_ADC_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(NTC_PFC_MOS_ADC_BASE,4095U);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(NTC_PFC_MOS_ADC_BASE,4095U);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(NTC_PFC_MOS_ADC_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(NTC_PFC_MOS_ADC_BASE, 0U, 1U, 1U);
    // Initializes the digital filter of the high comparator.
    CMPSS_initFilterHigh(NTC_PFC_MOS_ADC_BASE);
    // Initializes the digital filter of the low comparator.
    CMPSS_initFilterLow(NTC_PFC_MOS_ADC_BASE);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(NTC_PFC_MOS_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(NTC_PFC_MOS_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(NTC_PFC_MOS_ADC_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(NTC_PFC_MOS_ADC_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(NTC_PFC_MOS_ADC_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(NTC_PFC_MOS_ADC_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(NTC_PFC_MOS_ADC_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(NTC_PFC_MOS_ADC_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(NTC_PFC_MOS_ADC_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(NTC_PFC_MOS_ADC_BASE);

    //NTC_LLC_MOS_ADC initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(NTC_LLC_MOS_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(NTC_LLC_MOS_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(NTC_LLC_MOS_ADC_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(NTC_LLC_MOS_ADC_BASE,4095U);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(NTC_LLC_MOS_ADC_BASE,4095U);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(NTC_LLC_MOS_ADC_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(NTC_LLC_MOS_ADC_BASE, 0U, 1U, 1U);
    // Initializes the digital filter of the high comparator.
    CMPSS_initFilterHigh(NTC_LLC_MOS_ADC_BASE);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(NTC_LLC_MOS_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(NTC_LLC_MOS_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(NTC_LLC_MOS_ADC_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(NTC_LLC_MOS_ADC_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(NTC_LLC_MOS_ADC_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(NTC_LLC_MOS_ADC_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(NTC_LLC_MOS_ADC_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(NTC_LLC_MOS_ADC_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(NTC_LLC_MOS_ADC_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(NTC_LLC_MOS_ADC_BASE);

    //PFC_CSA_CSD initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(PFC_CSA_CSD_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(PFC_CSA_CSD_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(PFC_CSA_CSD_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(PFC_CSA_CSD_BASE, PFC_CS_CMPSS);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(PFC_CSA_CSD_BASE, PFC_CS_CMPSS);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(PFC_CSA_CSD_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(PFC_CSA_CSD_BASE, 1023U, 32U, 31U);
    // Initializes the digital filter of the high comparator.
    CMPSS_initFilterHigh(PFC_CSA_CSD_BASE);
    // Initializes the digital filter of the low comparator.
    CMPSS_initFilterLow(PFC_CSA_CSD_BASE);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(PFC_CSA_CSD_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(PFC_CSA_CSD_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(PFC_CSA_CSD_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(PFC_CSA_CSD_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(PFC_CSA_CSD_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(PFC_CSA_CSD_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(PFC_CSA_CSD_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(PFC_CSA_CSD_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(PFC_CSA_CSD_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(PFC_CSA_CSD_BASE);

    //PFC_CSB_CSC initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(PFC_CSB_CSC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(PFC_CSB_CSC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(PFC_CSB_CSC_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(PFC_CSB_CSC_BASE, PFC_CS_CMPSS);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(PFC_CSB_CSC_BASE, PFC_CS_CMPSS);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(PFC_CSB_CSC_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(PFC_CSB_CSC_BASE, 1023U, 32U, 31U);
    // Initializes the digital filter of the high comparator.
    CMPSS_initFilterHigh(PFC_CSB_CSC_BASE);
    // Initializes the digital filter of the low comparator.
    CMPSS_initFilterLow(PFC_CSB_CSC_BASE);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(PFC_CSB_CSC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(PFC_CSB_CSC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(PFC_CSB_CSC_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(PFC_CSB_CSC_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(PFC_CSB_CSC_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(PFC_CSB_CSC_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(PFC_CSB_CSC_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(PFC_CSB_CSC_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(PFC_CSB_CSC_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(PFC_CSB_CSC_BASE);

    //BULK_VOLT_ADC initialization
    // Sets the configuration for the high comparator.
    CMPSS_configHighComparator(BULK_VOLT_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the high comparator.
    CMPSS_configLowComparator(BULK_VOLT_ADC_BASE,(CMPSS_INSRC_DAC));
    // Sets the configuration for the internal comparator DACs.
    CMPSS_configDAC(BULK_VOLT_ADC_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    // Sets the value of the internal DAC of the high comparator.
    CMPSS_setDACValueHigh(BULK_VOLT_ADC_BASE, BULK_VOLT_CMPSS);
    // Sets the value of the internal DAC of the low comparator.
    CMPSS_setDACValueLow(BULK_VOLT_ADC_BASE,4095U);
    //  Configures the digital filter of the high comparator.
    CMPSS_configFilterHigh(BULK_VOLT_ADC_BASE, 1023U, 32U, 31U);
    // Configures the digital filter of the low comparator.
    CMPSS_configFilterLow(BULK_VOLT_ADC_BASE, 0U, 1U, 1U);
    // Sets the output signal configuration for the high comparator.
    CMPSS_configOutputsHigh(BULK_VOLT_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the output signal configuration for the low comparator.
    CMPSS_configOutputsLow(BULK_VOLT_ADC_BASE,(CMPSS_TRIPOUT_FILTER | CMPSS_TRIP_FILTER));
    // Sets the comparator hysteresis settings.
    CMPSS_setHysteresis(BULK_VOLT_ADC_BASE,0U);
    // Configures the comparator subsystem's ramp generator.
    CMPSS_configRamp(BULK_VOLT_ADC_BASE,0U,0U,0U,1U,true);
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCHigh(BULK_VOLT_ADC_BASE);
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    CMPSS_disableLatchResetOnPWMSYNCLow(BULK_VOLT_ADC_BASE);
    // Sets the ePWM module blanking signal that holds trip in reset.
    CMPSS_configBlanking(BULK_VOLT_ADC_BASE,1U);
    // Disables an ePWM blanking signal from holding trip in reset.
    CMPSS_disableBlanking(BULK_VOLT_ADC_BASE);
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    CMPSS_configLatchOnPWMSYNC(BULK_VOLT_ADC_BASE,false,false);
    // Enables the CMPSS module.
    CMPSS_enableModule(BULK_VOLT_ADC_BASE);
    // Delay for CMPSS DAC to power up.
    DEVICE_DELAY_US(500);

    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS1_CTRIPH);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS1_CTRIPL);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS2_CTRIPH);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS2_CTRIPL);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS3_CTRIPH);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS4_CTRIPH);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS5_CTRIPH);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS6_CTRIPH);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS6_CTRIPL);
    XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS7_CTRIPH);
}

void EPWMXBAR_init(){
    //EPWMTrip initialization

    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX00_CMPSS1_CTRIPH);   //OBC_CURR
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX01_CMPSS1_CTRIPL);   //OBC_VOLT
    //XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX00_CMPSS1_CTRIPH_OR_L);
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX02_CMPSS2_CTRIPH);   //PFC_CSB
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX03_CMPSS2_CTRIPL);   //PFC_CSC
    //XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX02_CMPSS2_CTRIPH_OR_L);
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX04_CMPSS3_CTRIPH);   //PFC_AUX
    //XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX06_CMPSS4_CTRIPH);   //NTC_PFC_MOS
    //XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX08_CMPSS5_CTRIPH);   //NTC_LLC_MOS
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX10_CMPSS6_CTRIPH);   //PFC_CSA
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX11_CMPSS6_CTRIPL);   //PFC_CSD
    //XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX10_CMPSS6_CTRIPH_OR_L);
    XBAR_setEPWMMuxConfig(XBAR_TRIP4, XBAR_EPWM_MUX12_CMPSS7_CTRIPH);     //BULK_VOLT
    //XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX00 | XBAR_MUX01 | XBAR_MUX02 | XBAR_MUX03 | XBAR_MUX04 | XBAR_MUX06 | XBAR_MUX08 | XBAR_MUX10 | XBAR_MUX11 | XBAR_MUX12);
    //XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX00 | XBAR_MUX12);

    if(Conf_item[26].disable != 84)//DSP_CMPSS_HV_OVP
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX01);
    }
    else
    {

    }
    if(Conf_item[25].disable != 84)//DSP_CMPSS_HV_OCP;
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX00);
    }
    else
    {

    }
    if(Conf_item[27].disable != 84)//DSP_CMPSS_PFC_MOS_OCP
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX02);//PFC_CSB
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX03);//PFC_CSC
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX10);//PFC_CSA
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX11);//PFC_CSD
    }
    else
    {

    }
    if(Conf_item[28].disable != 84)//DSP_CMPSS_PFC_AUX_OVP
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX04);
    }
    else
    {

    }
    /*if(Conf_item[29].disable != 84)//DSP_CMPSS_PFC_MOS_OTP
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX06);
    }
    else
    {

    }
    if(Conf_item[30].disable != 84)//DSP_CMPSS_LLC_MOS_OTP
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX08);
    }
    else
    {

    }*/
    if(Conf_item[31].disable != 84)//DSP_CMPSS_PFC_OVP
    {
        XBAR_enableEPWMMux(XBAR_TRIP4, XBAR_MUX12);
    }
    else
    {

    }


}

void OUTPUTXBAR_init(){
    //LLC_EN_DOL initialization
    XBAR_setOutputLatchMode(XBAR_OUTPUT3, true);
    XBAR_invertOutputSignal(XBAR_OUTPUT3, false);

    //Mux configuration
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX01_CMPSS1_CTRIPOUTL);
    //XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH_OR_L);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX01_INPUTXBAR1);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX03_CMPSS2_CTRIPOUTL);
    //XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH_OR_L);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX04_CMPSS3_CTRIPOUTH);   //PFC_AUX
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX03_INPUTXBAR2);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX05_INPUTXBAR3);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX10_CMPSS6_CTRIPOUTH);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX11_CMPSS6_CTRIPOUTL);
    //XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX10_CMPSS6_CTRIPOUTH_OR_L);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX11_INPUTXBAR6);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT3, XBAR_OUT_MUX12_CMPSS7_CTRIPOUTH);
    //XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX00 | XBAR_MUX01 | XBAR_MUX02 | XBAR_MUX03 | XBAR_MUX05 | XBAR_MUX10 | XBAR_MUX11 | XBAR_MUX12);
    //XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX00);//XBAR_MUX01| XBAR_MUX03 | XBAR_MUX05 | XBAR_MUX11);

    //PFC_EN_DOH initialization
    XBAR_setOutputLatchMode(XBAR_OUTPUT4, false);
    XBAR_invertOutputSignal(XBAR_OUTPUT4, true);

    //Mux configuration
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX01_CMPSS1_CTRIPOUTL);
    //XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH_OR_L);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX01_INPUTXBAR1);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX03_CMPSS2_CTRIPOUTL);
    //XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX02_CMPSS2_CTRIPOUTH_OR_L);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX04_CMPSS3_CTRIPOUTH);   //PFC_AUX
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX03_INPUTXBAR2);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX05_INPUTXBAR3);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX10_CMPSS6_CTRIPOUTH);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX11_CMPSS6_CTRIPOUTL);
    //XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX10_CMPSS6_CTRIPOUTH_OR_L);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX11_INPUTXBAR6);
    XBAR_setOutputMuxConfig(XBAR_OUTPUT4, XBAR_OUT_MUX12_CMPSS7_CTRIPOUTH);
    //XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX00 | XBAR_MUX01 | XBAR_MUX02 | XBAR_MUX03 | XBAR_MUX05 | XBAR_MUX10 | XBAR_MUX11 | XBAR_MUX12);
    //XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX12);

    if(Conf_item[26].disable != 84)//DSP_CMPSS_HV_OVP
    {
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX01);
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX01);
    }
    else
    {

    }
    if(Conf_item[25].disable != 84)//DSP_CMPSS_HV_OCP;
    {
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX00);
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX00);
    }
    else
    {

    }
    if(Conf_item[27].disable != 84)//DSP_CMPSS_PFC_MOS_OCP
    {
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX02);//PFC_CSB
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX03);//PFC_CSC
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX10);//PFC_CSA
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX11);//PFC_CSD
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX02);//PFC_CSB
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX03);//PFC_CSC
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX10);//PFC_CSA
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX11);//PFC_CSD
    }
    else
    {

    }
    if(Conf_item[28].disable != 84)//DSP_CMPSS_PFC_AUX_OVP
    {
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX04);
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX04);
    }
    else
    {

    }
    if(Conf_item[31].disable != 84)//DSP_CMPSS_PFC_OVP
    {
        XBAR_enableOutputMux(XBAR_OUTPUT3, XBAR_MUX12);
        XBAR_enableOutputMux(XBAR_OUTPUT4, XBAR_MUX12);
    }
    else
    {

    }
}

void INPUTXBAR_init(){

    //myINPUTXBAR0 initialization
    XBAR_setInputPin(XBAR_INPUT1, 9);  // PFC_HW_OVP
    XBAR_clearInputFlag(XBAR_INPUT_FLG_INPUT1);
    XBAR_setInputPin(XBAR_INPUT2, 25);  // LLC_OCP_HW
    XBAR_clearInputFlag(XBAR_INPUT_FLG_INPUT2);
    XBAR_setInputPin(XBAR_INPUT3, 39);  // HVDC_HW_SCP
    XBAR_clearInputFlag(XBAR_INPUT_FLG_INPUT3);
    XBAR_setInputPin(XBAR_INPUT6, 59);  // HVDC_HW_OVP
    XBAR_clearInputFlag(XBAR_INPUT_FLG_INPUT6);
}

void CAN_init (void)
{

    CAN_initModule(CANA_BASE);


    CAN_setBitRate(CANA_BASE, DEVICE_SYSCLK_FREQ, 500000, 20);


    CAN_enableInterrupt(CANA_BASE, CAN_INT_IE0 | CAN_INT_ERROR |
                        CAN_INT_STATUS);

    CAN_enableGlobalInterrupt(CANA_BASE, CAN_GLOBAL_INT_CANINT0);

    // Enable CAN test mode with external loopback
    //    CAN_enableTestMode(CANA_BASE, CAN_TEST_EXL);


    //
    // Initialize the transmit message object used for sending CAN messages.
    // Message Object Parameters:
    //      Message Object ID Number: 1
    //      Message Identifier: 0x1
    //      Message Frame: Standard
    //      Message Type: Transmit
    //      Message ID Mask: 0x0
    //      Message Object Flags: Transmit Interrupt
    //      Message Data Length: 4 Bytes
    //
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID4, 0x110, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID5, 0x114, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID6, 0x116, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID7, 0x11A, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID8, 0x11C, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID9, 0x11E, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID10, 0x120, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, TX_MSG_OBJ_ID11, 0x602, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_TX_INT_ENABLE,
                           Can_DATA_LENGTH);
    //
    // Initialize the receive message object used for receiving CAN messages.
    // Message Object Parameters:
    //      Message Object ID Number: 2
    //      Message Identifier: 0x1
    //      Message Frame: Standard
    //      Message Type: Receive
    //      Message ID Mask: 0x0
    //      Message Object Flags: Receive Interrupt
    //      Message Data Length: 4 Bytes
    //
    CAN_setupMessageObject(CANA_BASE, RX_MSG_OBJ_ID, 0x101, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE,
                           Can_DATA_LENGTH);

    CAN_setupMessageObject(CANA_BASE, RX_MSG_OBJ_ID2, 0x112, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_setupMessageObject(CANA_BASE, RX_MSG_OBJ_ID3, 0x100, CAN_MSG_FRAME_STD,
                           CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE,
                           Can_DATA_LENGTH);
    CAN_startModule(CANA_BASE);
}

void sLLC_PWMInit(void)
{
    /*****************EPWM1********************/
    //
    // Set Time-base
    //
    EPWM_setTimeBasePeriod(EPWM_A_LLC, EPWM_A_LLC_INITIAL_PERIOD);
    EPWM_setPhaseShift(EPWM_A_LLC, EPWM_A_LLC_INITIAL_PHASE);
    EPWM_setTimeBaseCounter(EPWM_A_LLC, 0U);
    EPWM_setSyncOutPulseMode(EPWM_A_LLC,EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);
    EPWM_setTimeBaseCounterMode(EPWM_A_LLC, EPWM_COUNTER_MODE_UP);
    EPWM_setClockPrescaler(EPWM_A_LLC, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_disablePhaseShiftLoad(EPWM_A_LLC);
    //
    // Set Counter compare
    //
    EPWM_setCounterCompareValue(EPWM_A_LLC, EPWM_COUNTER_COMPARE_A, EPWM_A_LLC_INITIAL_CMPA);
    //EPWM_setCounterCompareValue(EPWM_A_LLC, EPWM_COUNTER_COMPARE_B, EPWM_A_LLC_INITIAL_CMPB);
    EPWM_setCounterCompareShadowLoadMode(EPWM_A_LLC,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    /*EPWM_setCounterCompareShadowLoadMode(EPWM_A_LLC,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);*/

    //
    // Set actions
    //
    EPWM_setActionQualifierAction(EPWM_A_LLC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM_A_LLC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM_A_LLC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM_A_LLC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    EPWM_setActionQualifierContSWForceAction(EPWM_A_LLC, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(EPWM_A_LLC, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);

    //
    // Trip & Digital compare
    //
    EPWM_selectDigitalCompareTripInput(EPWM_A_LLC, EPWM_DC_TRIP_COMBINATION, EPWM_DC_TYPE_DCAH);
    EPWM_enableDigitalCompareTripCombinationInput(EPWM_A_LLC, EPWM_A_LLC_TRIP_SIGNAL, EPWM_DC_TYPE_DCAH);
    EPWM_setTripZoneDigitalCompareEventCondition(EPWM_A_LLC,
                                                 EPWM_TZ_DC_OUTPUT_A1,
                                                 EPWM_TZ_EVENT_DCXH_HIGH);
    EPWM_setDigitalCompareEventSource(EPWM_A_LLC, EPWM_DC_MODULE_A,
                                      EPWM_DC_EVENT_1,
                                      EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
    EPWM_setDigitalCompareEventSyncMode(EPWM_A_LLC, EPWM_DC_MODULE_A,
                                        EPWM_DC_EVENT_1,
                                        EPWM_DC_EVENT_INPUT_NOT_SYNCED);
    EPWM_enableTripZoneSignals(EPWM_A_LLC, EPWM_TZ_SIGNAL_DCAEVT1);
    //EPWM_enableTripZoneSignals(EPWM_A_LLC, EPWM_TZ_SIGNAL_CBC6);
    EPWM_setTripZoneAction(EPWM_A_LLC, EPWM_TZ_ACTION_EVENT_DCAEVT1, EPWM_TZ_ACTION_LOW);

    //
    // Deadband
    //
    EPWM_setRisingEdgeDeadBandDelayInput(EPWM_A_LLC,  EPWM_DB_INPUT_EPWMA);
    EPWM_setFallingEdgeDeadBandDelayInput(EPWM_A_LLC, EPWM_DB_INPUT_EPWMB);
    EPWM_setDeadBandDelayMode(EPWM_A_LLC, EPWM_DB_RED, true);
    EPWM_setDeadBandDelayMode(EPWM_A_LLC, EPWM_DB_FED, true);
    EPWM_setDeadBandDelayPolarity(EPWM_A_LLC, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    EPWM_setDeadBandDelayPolarity(EPWM_A_LLC, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_A_LLC, EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_A_LLC, EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_setRisingEdgeDelayCount(EPWM_A_LLC,  EPWM_A_LLC_DEADBAND_RED);
    EPWM_setFallingEdgeDelayCount(EPWM_A_LLC, EPWM_A_LLC_DEADBAND_FED);

    //
    // Global load
    //
    EPWM_enableGlobalLoadRegisters(EPWM_A_LLC,
                                   EPWM_GL_REGISTER_TBPRD_TBPRDHR |
                                   EPWM_GL_REGISTER_CMPA_CMPAHR |
                                   EPWM_GL_REGISTER_CMPB_CMPBHR |
                                   EPWM_GL_REGISTER_CMPC |
                                   EPWM_GL_REGISTER_CMPD |
                                   EPWM_GL_REGISTER_DBRED_DBREDHR |
                                   EPWM_GL_REGISTER_DBFED_DBFEDHR |
                                   EPWM_GL_REGISTER_AQCSFRC);
    EPWM_setGlobalLoadTrigger(EPWM_A_LLC, EPWM_GL_LOAD_PULSE_CNTR_ZERO);
    EPWM_enableGlobalLoadOneShotMode(EPWM_A_LLC);
    EPWM_enableGlobalLoad(EPWM_A_LLC);
    //EPWM_setGlobalLoadOneShotLatch(EPWM_A_LLC);

    /*****************EPWM2********************/

    //
    // Set Time-base
    //
    EPWM_setTimeBasePeriod(EPWM_B_LLC, EPWM_B_LLC_INITIAL_PERIOD);
    EPWM_setPhaseShift(EPWM_B_LLC, EPWM_B_LLC_INITIAL_PHASE);
    EPWM_setTimeBaseCounter(EPWM_B_LLC, 0U);
    EPWM_setTimeBaseCounterMode(EPWM_B_LLC, EPWM_COUNTER_MODE_UP);
    EPWM_setClockPrescaler(EPWM_B_LLC, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_enablePhaseShiftLoad(EPWM_B_LLC);

    //
    // Set Counter compare
    //
    EPWM_setCounterCompareValue(EPWM_B_LLC, EPWM_COUNTER_COMPARE_A, EPWM_B_LLC_INITIAL_CMPA);
    //EPWM_setCounterCompareValue(EPWM_B_LLC, EPWM_COUNTER_COMPARE_B, EPWM_B_LLC_INITIAL_CMPB);
    EPWM_setCounterCompareShadowLoadMode(EPWM_B_LLC,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    /*EPWM_setCounterCompareShadowLoadMode(EPWM_B_LLC,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);*/

    //
    // Set actions
    //
    EPWM_setActionQualifierAction(EPWM_B_LLC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM_B_LLC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM_B_LLC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM_B_LLC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    EPWM_setActionQualifierContSWForceAction(EPWM_B_LLC, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(EPWM_B_LLC, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_HIGH);

    //
    // Trip & Digital compare
    //
    EPWM_selectDigitalCompareTripInput(EPWM_B_LLC, EPWM_DC_TRIP_TRIPIN1, EPWM_DC_TYPE_DCAH);
    EPWM_enableDigitalCompareTripCombinationInput(EPWM_B_LLC, EPWM_B_LLC_TRIP_SIGNAL, EPWM_DC_TYPE_DCAH);
    EPWM_setTripZoneDigitalCompareEventCondition(EPWM_B_LLC,
                                                 EPWM_TZ_DC_OUTPUT_A1,
                                                 EPWM_TZ_EVENT_DCXH_HIGH);
    EPWM_setDigitalCompareEventSource(EPWM_B_LLC, EPWM_DC_MODULE_A,
                                      EPWM_DC_EVENT_1,
                                      EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
    EPWM_setDigitalCompareEventSyncMode(EPWM_B_LLC, EPWM_DC_MODULE_A,
                                        EPWM_DC_EVENT_1,
                                        EPWM_DC_EVENT_INPUT_NOT_SYNCED);
    EPWM_enableTripZoneSignals(EPWM_B_LLC, EPWM_TZ_SIGNAL_DCAEVT1);
    //EPWM_enableTripZoneSignals(EPWM_B_LLC, EPWM_TZ_SIGNAL_CBC6);
    EPWM_setTripZoneAction(EPWM_B_LLC, EPWM_TZ_ACTION_EVENT_DCAEVT1, EPWM_TZ_ACTION_LOW);
    //EPWM_forceTripZoneEvent(EPWM_B_LLC, EPWM_TZ_FORCE_EVENT_OST);

    //
    // Deadband
    //
    EPWM_setRisingEdgeDeadBandDelayInput(EPWM_B_LLC,  EPWM_DB_INPUT_EPWMA);
    EPWM_setFallingEdgeDeadBandDelayInput(EPWM_B_LLC, EPWM_DB_INPUT_EPWMB);
    EPWM_setDeadBandDelayMode(EPWM_B_LLC, EPWM_DB_RED, true);
    EPWM_setDeadBandDelayMode(EPWM_B_LLC, EPWM_DB_FED, true);
    EPWM_setDeadBandDelayPolarity(EPWM_B_LLC, EPWM_DB_RED, EPWM_DB_POLARITY_ACTIVE_HIGH);
    EPWM_setDeadBandDelayPolarity(EPWM_B_LLC, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);
    EPWM_setRisingEdgeDelayCountShadowLoadMode(EPWM_B_LLC, EPWM_RED_LOAD_ON_CNTR_ZERO);
    EPWM_setFallingEdgeDelayCountShadowLoadMode(EPWM_B_LLC, EPWM_FED_LOAD_ON_CNTR_ZERO);
    EPWM_setRisingEdgeDelayCount(EPWM_B_LLC,  EPWM_B_LLC_DEADBAND_RED);
    EPWM_setFallingEdgeDelayCount(EPWM_B_LLC, EPWM_B_LLC_DEADBAND_FED);

    //
    // Global load
    //
    EPWM_enableGlobalLoadRegisters(EPWM_B_LLC,
                                   EPWM_GL_REGISTER_TBPRD_TBPRDHR |
                                   EPWM_GL_REGISTER_CMPA_CMPAHR |
                                   EPWM_GL_REGISTER_CMPB_CMPBHR |
                                   EPWM_GL_REGISTER_CMPC |
                                   EPWM_GL_REGISTER_CMPD |
                                   EPWM_GL_REGISTER_DBRED_DBREDHR |
                                   EPWM_GL_REGISTER_DBFED_DBFEDHR |
                                   EPWM_GL_REGISTER_AQCSFRC);
    EPWM_setGlobalLoadTrigger(EPWM_B_LLC, EPWM_GL_LOAD_PULSE_SYNC);
    EPWM_enableGlobalLoadOneShotMode(EPWM_B_LLC);
    EPWM_enableGlobalLoad(EPWM_B_LLC);
    //EPWM_setGlobalLoadOneShotLatch(EPWM_B_LLC);

    EPWM_setupEPWMLinks(EPWM_B_LLC, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);
    EPWM_setupEPWMLinks(EPWM_B_LLC, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_A);
    EPWM_setupEPWMLinks(EPWM_B_LLC, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_GLDCTL2);
}

void sPFC_PWMInit(void)
{
    /*****************EPWM4********************///(PFC_CTRL_A_PWM, PFC_CTRL_B_PWM)
    //
    // Set Time-base
    //
    EPWM_setTimeBasePeriod(EPWM4_BASE, EPWM_A_PFC_INITIAL_PERIOD);
    EPWM_setPhaseShift(EPWM4_BASE, EPWM_A_PFC_INITIAL_PHASE);
    EPWM_setTimeBaseCounter(EPWM4_BASE, 0U);
    EPWM_setSyncOutPulseMode(EPWM4_BASE,EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);
    EPWM_setTimeBaseCounterMode(EPWM4_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_setClockPrescaler(EPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_disablePhaseShiftLoad(EPWM4_BASE);

    SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM7, SYSCTL_SYNC_IN_SRC_EPWM4SYNCOUT);

    //
    // Set Counter compare
    //
    //EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_A_PFC_INITIAL_CMPA);
    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_B, 300);
    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    // Set actions
    //
    /*EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);*/
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    /*****************EPWM5********************///(PFC_CTRL_A_PWM, PFC_CTRL_B_PWM)
    EPWM_setActionQualifierContSWForceAction(EPWM_A_PFC, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(EPWM_A_PFC, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);
    //
    // Enable SOCA
    //
    EPWM_enableADCTrigger(EPWM5_BASE, EPWM_SOC_A);
    EPWM_enableADCTrigger(EPWM5_BASE, EPWM_SOC_B);


    //
    // Configure the SOC to occur on the first up-count event
    //
    EPWM_setADCTriggerSource(EPWM5_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);
    EPWM_setADCTriggerEventPrescale(EPWM5_BASE, EPWM_SOC_A, 1);
    EPWM_setADCTriggerSource(EPWM5_BASE, EPWM_SOC_B, EPWM_SOC_TBCTR_PERIOD);
    EPWM_setADCTriggerEventPrescale(EPWM5_BASE, EPWM_SOC_B, 1);


    //
    // Set Time-base
    //
    EPWM_setTimeBasePeriod(EPWM_A_PFC, EPWM_A_PFC_INITIAL_PERIOD);
    EPWM_setPhaseShift(EPWM_A_PFC, EPWM_A_PFC_INITIAL_PHASE);
    EPWM_setTimeBaseCounter(EPWM_A_PFC, 0U);
    EPWM_setSyncOutPulseMode(EPWM_A_PFC,EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);
    EPWM_setTimeBaseCounterMode(EPWM_A_PFC, EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_setClockPrescaler(EPWM_A_PFC, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_enablePhaseShiftLoad(EPWM_A_PFC);
    //
    // Set Counter compare
    //
    EPWM_setCounterCompareValue(EPWM_A_PFC, EPWM_COUNTER_COMPARE_A, EPWM_A_PFC_INITIAL_CMPA);
    EPWM_setCounterCompareValue(EPWM_A_PFC, EPWM_COUNTER_COMPARE_B, EPWM_A_PFC_INITIAL_PERIOD-EPWM_A_PFC_INITIAL_CMPB);
    EPWM_setCounterCompareShadowLoadMode(EPWM_A_PFC,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM_A_PFC,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    // Set actions
    //
    EPWM_setActionQualifierAction(EPWM_A_PFC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM_A_PFC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM_A_PFC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(EPWM_A_PFC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM_A_PFC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(EPWM_A_PFC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);



    //
    // Trip & Digital compare
    //
    EPWM_selectDigitalCompareTripInput(EPWM_A_PFC, EPWM_DC_TRIP_COMBINATION, EPWM_DC_TYPE_DCAH);
    //EPWM_selectDigitalCompareTripInput(EPWM_A_PFC, EPWM_DC_TRIP_COMBINATION, EPWM_DC_TYPE_DCBH);
    EPWM_enableDigitalCompareTripCombinationInput(EPWM_A_PFC, EPWM_A_PFC_TRIP_SIGNAL, EPWM_DC_TYPE_DCAH);
    //EPWM_enableDigitalCompareTripCombinationInput(EPWM_A_PFC, EPWM_A_PFC_TRIP_SIGNAL, EPWM_DC_TYPE_DCBH);
    EPWM_setTripZoneDigitalCompareEventCondition(EPWM_A_PFC,
                                                 EPWM_TZ_DC_OUTPUT_A2,
                                                 EPWM_TZ_EVENT_DCXH_HIGH);
    //EPWM_setTripZoneDigitalCompareEventCondition(EPWM_A_PFC,
    //                                             EPWM_TZ_DC_OUTPUT_B2,
    //                                             EPWM_TZ_EVENT_DCXH_HIGH);
    EPWM_setDigitalCompareEventSource(EPWM_A_PFC, EPWM_DC_MODULE_A,
                                      EPWM_DC_EVENT_1,
                                      EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
    //EPWM_setDigitalCompareEventSource(EPWM_A_PFC, EPWM_DC_MODULE_B,
    //                                  EPWM_DC_EVENT_1,
    //                                  EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
    EPWM_setDigitalCompareEventSyncMode(EPWM_A_PFC, EPWM_DC_MODULE_A,
                                        EPWM_DC_EVENT_1,
                                        EPWM_DC_EVENT_INPUT_NOT_SYNCED);
    //EPWM_setDigitalCompareEventSyncMode(EPWM_A_PFC, EPWM_DC_MODULE_B,
    //                                    EPWM_DC_EVENT_1,
    //                                    EPWM_DC_EVENT_INPUT_NOT_SYNCED);
    EPWM_enableTripZoneSignals(EPWM_A_PFC, EPWM_TZ_SIGNAL_DCAEVT2);
    //EPWM_enableTripZoneSignals(EPWM_A_PFC, EPWM_TZ_SIGNAL_DCBEVT2);
    //EPWM_enableTripZoneSignals(EPWM_A_PFC, EPWM_TZ_SIGNAL_CBC6);
    EPWM_setTripZoneAction(EPWM_A_PFC, EPWM_TZ_ACTION_EVENT_DCAEVT2, EPWM_TZ_ACTION_LOW);
    //EPWM_setTripZoneAction(EPWM_A_PFC, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);

    //EPWM_clearTripZoneFlag(EPWM_A_PFC, EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_CBC);

    /*****************EPWM7********************///(PFC_CTRL_C_PWM, PFC_CTRL_D_PWM)
    EPWM_setActionQualifierContSWForceAction(EPWM_B_PFC, EPWM_AQ_OUTPUT_A, EPWM_AQ_SW_OUTPUT_LOW);
    EPWM_setActionQualifierContSWForceAction(EPWM_B_PFC, EPWM_AQ_OUTPUT_B, EPWM_AQ_SW_OUTPUT_LOW);

    //
      // Disable SOCA
      //
      EPWM_enableADCTrigger(EPWM7_BASE, EPWM_SOC_A);
      EPWM_enableADCTrigger(EPWM7_BASE, EPWM_SOC_B);

      //
      // Configure the SOC to occur on the first up-count event
      //
      EPWM_setADCTriggerSource(EPWM_B_PFC, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);
      EPWM_setADCTriggerEventPrescale(EPWM_B_PFC, EPWM_SOC_A, 1);
      EPWM_setADCTriggerSource(EPWM_B_PFC, EPWM_SOC_B, EPWM_SOC_TBCTR_PERIOD);
      EPWM_setADCTriggerEventPrescale(EPWM_B_PFC, EPWM_SOC_B, 1);
    //
    // Set Time-base
    //
    EPWM_setTimeBasePeriod(EPWM_B_PFC, EPWM_B_PFC_INITIAL_PERIOD);
    EPWM_setPhaseShift(EPWM_B_PFC, EPWM_B_PFC_INITIAL_PHASE);
    EPWM_setTimeBaseCounter(EPWM_B_PFC, 0U);
    EPWM_setSyncOutPulseMode(EPWM_B_PFC,EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);
    EPWM_setTimeBaseCounterMode(EPWM_B_PFC, EPWM_COUNTER_MODE_UP_DOWN);
    EPWM_setClockPrescaler(EPWM_B_PFC, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
    EPWM_enablePhaseShiftLoad(EPWM_B_PFC);
    //EPWM_disablePhaseShiftLoad(EPWM_B_PFC);
    //
    // Set Counter compare
    //
    EPWM_setCounterCompareValue(EPWM_B_PFC, EPWM_COUNTER_COMPARE_A, EPWM_B_PFC_INITIAL_CMPA);
    EPWM_setCounterCompareValue(EPWM_B_PFC, EPWM_COUNTER_COMPARE_B, EPWM_B_PFC_INITIAL_PERIOD-EPWM_B_PFC_INITIAL_CMPB);
    EPWM_setCounterCompareShadowLoadMode(EPWM_B_PFC,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM_B_PFC,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    // Set actions
    //
    EPWM_setActionQualifierAction(EPWM_B_PFC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM_B_PFC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM_B_PFC,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    EPWM_setActionQualifierAction(EPWM_B_PFC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM_B_PFC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    EPWM_setActionQualifierAction(EPWM_B_PFC,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);


    //
    // Trip & Digital compare
    //
    EPWM_selectDigitalCompareTripInput(EPWM_B_PFC, EPWM_DC_TRIP_COMBINATION, EPWM_DC_TYPE_DCAH);
    //EPWM_selectDigitalCompareTripInput(EPWM_B_PFC, EPWM_DC_TRIP_COMBINATION, EPWM_DC_TYPE_DCBH);
    EPWM_enableDigitalCompareTripCombinationInput(EPWM_B_PFC, EPWM_B_PFC_TRIP_SIGNAL, EPWM_DC_TYPE_DCAH);
    //EPWM_enableDigitalCompareTripCombinationInput(EPWM_B_PFC, EPWM_B_PFC_TRIP_SIGNAL, EPWM_DC_TYPE_DCBH);
    EPWM_setTripZoneDigitalCompareEventCondition(EPWM_B_PFC,
                                                 EPWM_TZ_DC_OUTPUT_A2,
                                                 EPWM_TZ_EVENT_DCXH_HIGH);
    //EPWM_setTripZoneDigitalCompareEventCondition(EPWM_B_PFC,
    //                                             EPWM_TZ_DC_OUTPUT_B2,
    //                                             EPWM_TZ_EVENT_DCXH_HIGH);
    EPWM_setDigitalCompareEventSource(EPWM_B_PFC, EPWM_DC_MODULE_A,
                                      EPWM_DC_EVENT_1,
                                      EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
    //EPWM_setDigitalCompareEventSource(EPWM_B_PFC, EPWM_DC_MODULE_B,
    //                                  EPWM_DC_EVENT_1,
    //                                  EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
    EPWM_setDigitalCompareEventSyncMode(EPWM_B_PFC, EPWM_DC_MODULE_A,
                                        EPWM_DC_EVENT_1,
                                        EPWM_DC_EVENT_INPUT_NOT_SYNCED);
   // EPWM_setDigitalCompareEventSyncMode(EPWM_B_PFC, EPWM_DC_MODULE_B,
   //                                     EPWM_DC_EVENT_1,
   //                                     EPWM_DC_EVENT_INPUT_NOT_SYNCED);
    //EPWM_enableTripZoneSignals(EPWM_B_PFC, EPWM_TZ_SIGNAL_DCAEVT1);
    EPWM_enableTripZoneSignals(EPWM_B_PFC, EPWM_TZ_SIGNAL_DCAEVT2);
    //EPWM_enableTripZoneSignals(EPWM_B_PFC, EPWM_TZ_SIGNAL_DCBEVT2);
    EPWM_setTripZoneAction(EPWM_B_PFC, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);
    //EPWM_setTripZoneAction(EPWM_B_PFC, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);

    //
    // Clear trip flags
    //
    //EPWM_clearTripZoneFlag(EPWM_B_PFC, EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST);
}

void    sRELAY_PWMInit(void)
{
    /*****************EPWM6********************///(RELAY_PWM_H)
    //
    // Set Time-base
    //
        EPWM_setTimeBasePeriod(EPWM_RELAY, EPWM_RELAY_INITIAL_PERIOD);
        EPWM_setPhaseShift(EPWM_RELAY, EPWM_RELAY_INITIAL_PHASE);
        EPWM_setTimeBaseCounter(EPWM_RELAY, 0U);
        EPWM_setTimeBaseCounterMode(EPWM_RELAY, EPWM_COUNTER_MODE_UP_DOWN);
        EPWM_setClockPrescaler(EPWM_RELAY, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);
        //EPWM_enablePhaseShiftLoad(EPWM_RELAY);
        EPWM_disablePhaseShiftLoad(EPWM_RELAY);
    //
    // Set Counter compare
    //
        //EPWM_setCounterCompareValue(EPWM_RELAY, EPWM_COUNTER_COMPARE_A, EPWM_RELAY_INITIAL_CMPA);
        EPWM_setCounterCompareValue(EPWM_RELAY, EPWM_COUNTER_COMPARE_B, EPWM_RELAY_INITIAL_CMPB);
        EPWM_setCounterCompareShadowLoadMode(EPWM_RELAY,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
        EPWM_setCounterCompareShadowLoadMode(EPWM_RELAY,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    // Set actions
    //
        EPWM_setActionQualifierAction(EPWM_RELAY,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
        EPWM_setActionQualifierAction(EPWM_RELAY,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    //
    // Trip & Digital compare
    //
        /*EPWM_selectDigitalCompareTripInput(EPWM_RELAY, EPWM_DC_TRIP_TRIPIN1, EPWM_DC_TYPE_DCAH);
        EPWM_enableDigitalCompareTripCombinationInput(EPWM_RELAY, EPWM_RELAY_TRIP_SIGNAL, EPWM_DC_TYPE_DCAH);
        EPWM_setTripZoneDigitalCompareEventCondition(EPWM_RELAY,
                                                 EPWM_TZ_DC_OUTPUT_A1,
                                                 EPWM_TZ_EVENT_DCXH_HIGH);
        EPWM_setDigitalCompareEventSource(EPWM_RELAY, EPWM_DC_MODULE_A,
                                      EPWM_DC_EVENT_1,
                                      EPWM_DC_EVENT_SOURCE_ORIG_SIGNAL);
        EPWM_setDigitalCompareEventSyncMode(EPWM_RELAY, EPWM_DC_MODULE_A,
                                        EPWM_DC_EVENT_1,
                                        EPWM_DC_EVENT_INPUT_NOT_SYNCED);
        EPWM_enableTripZoneSignals(EPWM_RELAY, EPWM_TZ_SIGNAL_DCAEVT1);
        EPWM_enableTripZoneSignals(EPWM_RELAY, EPWM_TZ_SIGNAL_CBC6);
        EPWM_setTripZoneAction(EPWM_RELAY, EPWM_TZ_ACTION_EVENT_DCAEVT1, EPWM_TZ_ACTION_LOW);*/
}

//
// Function to configure ePWM3 to generate the SOC.
//
void sADCTrigger_Epwm3Init(void)
{
    //
    // Disable SOCA
    //
    EPWM_enableADCTrigger(EPWM3_BASE, EPWM_SOC_A);

    //
    // Configure the SOC to occur on the first up-count event
    //
    EPWM_setADCTriggerSource(EPWM3_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPA);
    EPWM_setADCTriggerEventPrescale(EPWM3_BASE, EPWM_SOC_A, 1);

    //
    // Set the compare A value to 1000 and the period to 1999
    // Assuming ePWM clock is 100MHz, this would give 50kHz sampling
    // 50MHz ePWM clock would give 25kHz sampling, etc.
    // The sample rate can also be modulated by changing the ePWM period
    // directly (ensure that the compare A value is less than the period).
    //
    EPWM_setCounterCompareValue(EPWM3_BASE, EPWM_COUNTER_COMPARE_A, 2000);
    EPWM_setTimeBasePeriod(EPWM3_BASE, 4999);

    //
    // Set the local ePWM module clock divider to /1
    //
    EPWM_setClockPrescaler(EPWM3_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);
    EPWM_disablePhaseShiftLoad(EPWM3_BASE);
    //
    // Freeze the counter
    //
    EPWM_setTimeBaseCounterMode(EPWM3_BASE, EPWM_COUNTER_MODE_UP);
}

void DAC_init()
{
    // DACA_module initialization
    // Set DAC reference voltage.
    DAC_setReferenceVoltage(DACA_module_BASE, DAC_REF_ADC_VREFHI);
    // Set DAC gain mode.
    DAC_setGainMode(DACA_module_BASE, DAC_GAIN_TWO);
    // Set DAC load mode.
    DAC_setLoadMode(DACA_module_BASE, DAC_LOAD_SYSCLK);
    // Enable the DAC output
    DAC_enableOutput(DACA_module_BASE);
    // Set the DAC shadow output
    DAC_setShadowValue(DACA_module_BASE, 0U);

    // DACB_module initialization
    // Set DAC reference voltage.
    DAC_setReferenceVoltage(DACB_module_BASE, DAC_REF_ADC_VREFHI);
    // Set DAC gain mode.
    DAC_setGainMode(DACB_module_BASE, DAC_GAIN_TWO);
    // Set DAC load mode.
    DAC_setLoadMode(DACB_module_BASE, DAC_LOAD_SYSCLK);
    // Enable the DAC output
    DAC_enableOutput(DACB_module_BASE);
    // Set the DAC shadow output
    DAC_setShadowValue(DACB_module_BASE, 0U);

    // Delay for buffered DAC to power up.
    DEVICE_DELAY_US(5000);
}
