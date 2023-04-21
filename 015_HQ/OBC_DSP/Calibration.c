/*
 * Calibration.c
 *
 *  Created on: 2022¦~5¤ë25¤é
 *      Author: MartinChou
 */

//------------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------------
#include "Calibration.h"

int16_T *data;
int16_T Calibration_HexData[512];
int16_T Gain[2];
int16_T Offset[2];
real32_T Calibration_FloatData[10];
uint16_T DSP_CALI_EMPTY;
uint16_T DSP_CALI_ERR;
uint8_T Cali_Verify;
Cali_item_def Cali_item;



real32_T Cali_FData;
int16_T uint8_T_HiWord, uint8_T_LowWord;
int16_T Word;
int16_T Word2;
union {
        int16_T cali[4];
        real32_T f;
      } u;




real32_T HextoFloat(int16_T *Array, size_t arr_size)
{
    int16_T Word1;
    int16_T Word2;

    union {
            int16_T cali[4];
            real32_T f;
          } HextoFloat;

    Word1 = (int16_T)((uint16_T)(Array[0]) << 8);
    Word1 |= (int16_T)((uint16_T)(Array[0]) >> 8);

    Word2 = (int16_T)((uint16_T)(Array[1]) << 8);
    Word2 |= (int16_T)((uint16_T)(Array[1]) >> 8);

    HextoFloat.cali[3] = 0x0000;
    HextoFloat.cali[2] = 0x0000;
    HextoFloat.cali[1] = Word2;
    HextoFloat.cali[0] = Word1;

    return HextoFloat.f;
}

void Calibration_Function(void)
{
    static int i, j, k, l;
    if(Cali_Verify!=0)
    {
        Cali_item.HVDC_VOLT_OBC_ADC_Gain = 1.0f;
        Cali_item.HVDC_VOLT_OBC_ADC_Offset = 0.0f;
        Cali_item.HVDC_CURR_OBC_ADC_Gain = 1.0f;
        Cali_item.HVDC_CURR_OBC_ADC_Offset = 0.0f;
        Cali_item.GRID_VOLT_ADC_Gain = 1.0;
        Cali_item.GRID_VOLT_ADC_Offset = 0.0f;
        Cali_item.GRID_CURR_ADC_Gain = 1.0f;
        Cali_item.GRID_CURR_ADC_Offset = 0.0f;
        Cali_item.BULK_VOLT_ADC_Gain = 1.0f;
        Cali_item.BULK_VOLT_ADC_Offset = 0.0f;
        DSP_CALI_ERR =1;
    }
    else
    {
        for (i=100, j=0; i<161; i+=12, j+=2)
        {

            data = (int16_T *)(0x0000B800 + i);
            Calibration_HexData[i] =  *data;
            data = (int16_T *)(0x0000B800 + i+1);
            Calibration_HexData[i+1] =  *data;
            Gain[0] = Calibration_HexData[i];
            Gain[1] = Calibration_HexData[i+1];
            Calibration_FloatData[j] = HextoFloat(Gain, 2);
            data = (int16_T *)(0x0000B800 + i+2);
            Calibration_HexData[i+2] =  *data;
            data = (int16_T *)(0x0000B800 + i+3);
            Calibration_HexData[i+3] =  *data;
            Offset[0] = Calibration_HexData[i+2];
            Offset[1] = Calibration_HexData[i+3];
            Calibration_FloatData[j+1] = HextoFloat(Offset, 2);
        }
        for (k=0; k<10; k+=2)
        {
            if(Calibration_FloatData[k] - Calibration_FloatData[k+2] < 0.001 && Calibration_FloatData[k+1] - Calibration_FloatData[k+3] < 0.001 && Calibration_FloatData[k] > 0.999 && Calibration_FloatData[k]<1.001 && Calibration_FloatData[k+1] > -0.001 && Calibration_FloatData[k+1] < 0.001)
            {
                Calibration_FloatData[k] = 1;
                Calibration_FloatData[k+1] = 0;
                l++;
                if(l == 5)
                {
                    DSP_CALI_EMPTY =1;
                }
                else
                {

                }
            }
            else if(Calibration_FloatData[k] >= 1.5 || Calibration_FloatData[k] <= 0.5 && Calibration_FloatData[k+1] >= 1000 || Calibration_FloatData[k+1] <= -1000)
            {
                Calibration_FloatData[k] = 1;
                Calibration_FloatData[k+1] = 0;
                DSP_CALI_ERR =1;
            }
            else
            {

            }
            Cali_item.HVDC_VOLT_OBC_ADC_Gain = Calibration_FloatData[0];
            Cali_item.HVDC_VOLT_OBC_ADC_Offset = Calibration_FloatData[1];
            Cali_item.HVDC_CURR_OBC_ADC_Gain = Calibration_FloatData[2];
            Cali_item.HVDC_CURR_OBC_ADC_Offset = Calibration_FloatData[3];
            Cali_item.GRID_VOLT_ADC_Gain = Calibration_FloatData[4];
            Cali_item.GRID_VOLT_ADC_Offset = Calibration_FloatData[5];
            Cali_item.GRID_CURR_ADC_Gain = Calibration_FloatData[6];
            Cali_item.GRID_CURR_ADC_Offset = Calibration_FloatData[7];
            Cali_item.BULK_VOLT_ADC_Gain = Calibration_FloatData[8];
            Cali_item.BULK_VOLT_ADC_Offset = Calibration_FloatData[9];
        }

    }
}
