/*
 * Calibration.h
 *
 *  Created on: 2022¦~5¤ë25¤é
 *      Author: MartinChou
 */

#ifndef CALIBRATION_H_
#define CALIBRATION_H_


#include "rtwtypes.h"
#include "string.h"


extern uint16_T DSP_CALI_EMPTY;
extern uint16_T DSP_CALI_ERR;
extern uint8_T Cali_Verify;


typedef struct
{
    real32_T HVDC_VOLT_OBC_ADC_Gain;
    real32_T HVDC_VOLT_OBC_ADC_Offset;
    real32_T HVDC_CURR_OBC_ADC_Gain;
    real32_T HVDC_CURR_OBC_ADC_Offset;
    real32_T GRID_VOLT_ADC_Gain;
    real32_T GRID_VOLT_ADC_Offset;
    real32_T GRID_CURR_ADC_Gain;
    real32_T GRID_CURR_ADC_Offset;
    real32_T BULK_VOLT_ADC_Gain;
    real32_T BULK_VOLT_ADC_Offset;
}Cali_item_def;

extern Cali_item_def Cali_item;

real32_T HextoFloat(int16_T *Array, size_t arr_size);
void    Calibration_Function(void);

#endif /* CALIBRATION_H_ */
