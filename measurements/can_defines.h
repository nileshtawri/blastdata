#define dsm_struct           main_DWork

#define can_data_rx_tmp      main_B.eCANReceive_o2

//Sec states
#define dsm_0000             dsm_struct##.state_control
#define dsm_0001             dsm_struct##.state_calib
#define dsm_0002             dsm_struct##.state_hkeep

//Sec status
#define dsm_0100             dsm_struct##.status_control 
#define dsm_0101             dsm_struct##.status_fault
#define dsm_0102             dsm_struct##.status_digin
#define dsm_0103             dsm_struct##.status_digout

//Sec adc and calibration
#define dsm_0200             dsm_struct##.llc1_sec_idc
#define dsm_0201             dsm_struct##.llc1_pri_idc
#define dsm_0202             dsm_struct##.vout
#define dsm_0203             dsm_struct##.vbat
#define dsm_0204             dsm_struct##.vaux
#define dsm_0205             dsm_struct##.vbulk
#define dsm_0206             dsm_struct##.llc2_pri_idc
#define dsm_0207             dsm_struct##.llc2_sec_idc
#define dsm_0208             dsm_struct##.llc1_temp_sr
#define dsm_0209             dsm_struct##.llc2_temp_sr
#define dsm_020A             dsm_struct##.temp_outlet
#define dsm_020B             dsm_struct##.gain_vout
#define dsm_020C             dsm_struct##.offset_vout
#define dsm_020D             dsm_struct##.gain_vbat
#define dsm_020E             dsm_struct##.offset_vbat
#define dsm_020F             dsm_struct##.gain_vbulk
#define dsm_0210             dsm_struct##.offset_vbulk
#define dsm_0211             dsm_struct##.gain_llc1_sec_idc
#define dsm_0212             dsm_struct##.offset_llc1_sec_idc
#define dsm_0213             dsm_struct##.gain_llc2_sec_idc
#define dsm_0214             dsm_struct##.offset_llc2_sec_idc

//Control
#define dsm_0300             dsm_struct##.ref_vbat
#define dsm_0301             dsm_struct##.ref_vbat_calib
#define dsm_0302             dsm_struct##.ref_iout
#define dsm_0303             dsm_struct##.ref_iout_calib
#define dsm_0304             dsm_struct##.ref_iout_llc1_calib
#define dsm_0305             dsm_struct##.ref_iout_llc2_calib
#define dsm_0306             dsm_struct##.ref_vbulk_calib
#define dsm_0307             dsm_struct##.ref_vbulk_llc1_calib
#define dsm_0308             dsm_struct##.ref_vbulk_llc2_calib
#define dsm_0309             dsm_struct##.ref_pout
#define dsm_030A             llc1_ts_tbctr
#define dsm_030B             llc1_ps
#define dsm_030C             llc1_burstduty
#define dsm_030D             llc2_ts_tbctr
#define dsm_030E             llc2_ps
#define dsm_030F             llc2_burstduty
#define dsm_0310             dsm_struct##.pfm_kp
#define dsm_0311             dsm_struct##.pfm_ki
#define dsm_0312             dsm_struct##.pfm_integ_max
#define dsm_0313             dsm_struct##.pfm_integ_min
#define dsm_0314             dsm_struct##.pspwm_kp
#define dsm_0315             dsm_struct##.pspwm_ki
#define dsm_0316             dsm_struct##.pspwm_integ_max
#define dsm_0317             dsm_struct##.pspwm_integ_min
#define dsm_0318             dsm_struct##.burstduty_kp
#define dsm_0319             dsm_struct##.burstduty_ki
#define dsm_031A             dsm_struct##.burstduty_integ_max
#define dsm_031B             dsm_struct##.burstduty_integ_min

//Sec info
#define version_major        39 //dsm_0400
#define version_minor        13 //dsm_0400
#define dsm_0401             runtime_adca1
#define dsm_0402             runtime_adcb1
#define dsm_0403             dsm_struct##.runtime_control
#define dsm_0404             dsm_struct##.runtime_idle

//Sec debug
#define dsm_0500             dsm_struct##.llc1_ts_tbctr_buffer
#define dsm_0501             dsm_struct##.llc1_ps_buffer
#define dsm_0502             dsm_struct##.llc1_burstduty_buffer
#define dsm_0503             dsm_struct##.llc2_ts_tbctr_buffer
#define dsm_0504             dsm_struct##.llc2_ps_buffer
#define dsm_0505             dsm_struct##.llc2_burstduty_buffer

//Pri input information
#define dsm_0600             dsm_struct##.status_input
#define dsm_0601             dsm_struct##.input_freq
#define dsm_0602             dsm_struct##.input_power
#define dsm_0603             dsm_struct##.input_voltage_phasea
#define dsm_0604             dsm_struct##.input_voltage_phaseb
#define dsm_0605             dsm_struct##.input_voltage_phasec
#define dsm_0606             dsm_struct##.input_current_phasea
#define dsm_0607             dsm_struct##.input_current_phaseb
#define dsm_0608             dsm_struct##.input_current_phasec

//Pri pfc information
#define dsm_0700             dsm_struct##.status_pfc
#define dsm_0701             dsm_struct##.bulk_voltage
#define dsm_0702             dsm_struct##.mid_bulk_voltage
#define dsm_0703             dsm_struct##.pfc_fw_revision_debug
#define dsm_0704             dsm_struct##.pfc_fw_revision
#define dsm_0705             dsm_struct##.pfc_fw_revision_bootloader

//Pri temperature
#define dsm_0800             dsm_struct##.temp_pfc_fet_hsa
#define dsm_0801             dsm_struct##.temp_pfc_fet_lsa
#define dsm_0802             dsm_struct##.temp_pfc_fet_hsb
#define dsm_0803             dsm_struct##.temp_pfc_fet_lsb
#define dsm_0804             dsm_struct##.temp_pfc_fet_hsc
#define dsm_0805             dsm_struct##.temp_pfc_fet_lsc
#define dsm_0806             dsm_struct##.temp_llc1_fet_hs
#define dsm_0807             dsm_struct##.temp_llc2_fet_hs
#define dsm_0808             dsm_struct##.temp_inlet

//Pri debug
#define dsm_0900             dsm_struct##.debug_msg1
#define dsm_0901             dsm_struct##.debug_msg2
#define dsm_0902             dsm_struct##.debug_msg3
#define dsm_0903             dsm_struct##.debug_msg4
#define dsm_0904             dsm_struct##.debug_msg5
#define dsm_0905             dsm_struct##.debug_msg6
#define dsm_0906             dsm_struct##.pri_fut_en
#define dsm_0907             dsm_struct##.pri_fut_en_buffer

#define sendErrorChksum()                  \
{                                          \
	dsm_struct##.can_data_tx[0] = 0x01;    \
	dsm_struct##.can_data_tx[1] = 0x99;    \
	dsm_struct##.can_data_tx[2] = 0x99;    \
	dsm_struct##.can_data_tx[3] = 0x00;    \
	dsm_struct##.can_data_tx[4] = 0x00;    \
	dsm_struct##.can_data_tx[5] = 0x00;    \
	dsm_struct##.can_data_tx[6] = 0x00;    \
}

#define sendErrorFunc()                    \
{                                          \
	dsm_struct##.can_data_tx[0] = 0x01;    \
	dsm_struct##.can_data_tx[1] = 0x99;    \
	dsm_struct##.can_data_tx[2] = 0x99;    \
	dsm_struct##.can_data_tx[3] = 0x01;    \
	dsm_struct##.can_data_tx[4] = 0x00;    \
	dsm_struct##.can_data_tx[5] = 0x00;    \
	dsm_struct##.can_data_tx[6] = 0x00;    \
}

#define sendBooleanCanDataTx()                                      \
{                                                                   \
	if(can_data_rx_tmp[0] == 0) /*if write*/                        \
	{                                                               \
		*ptr_boolean_dsm = (boolean_T)(uint32_can_func_val);        \
	}                                                               \
	dsm_struct##.can_data_tx[3] = (uint8_T)(*ptr_boolean_dsm);      \
	dsm_struct##.can_data_tx[4] = (uint8_T)(0);                     \
	dsm_struct##.can_data_tx[5] = (uint8_T)(0);                     \
	dsm_struct##.can_data_tx[6] = (uint8_T)(0);                     \
}

#define sendUint8CanDataTx()                                              \
{                                                                         \
	if(can_data_rx_tmp[0] == 0) /*if write*/                              \
	{                                                                     \
		*ptr_uint8_dsm = (uint8_T)(uint32_can_func_val);                  \
	}                                                                     \
	uint32_can_func_val = (uint32_T)(*ptr_uint8_dsm);                     \
	dsm_struct##.can_data_tx[3] = (uint8_T)(uint32_can_func_val);         \
	dsm_struct##.can_data_tx[4] = (uint8_T)(0);                           \
	dsm_struct##.can_data_tx[5] = (uint8_T)(0);                           \
	dsm_struct##.can_data_tx[6] = (uint8_T)(0);                           \
}

#define sendUint16CanDataTx()                                             \
{                                                                         \
	if(can_data_rx_tmp[0] == 0) /*if write*/                              \
	{                                                                     \
		*ptr_uint16_dsm = (uint16_T)(uint32_can_func_val);                \
	}                                                                     \
	uint32_can_func_val = (uint32_T)(*ptr_uint16_dsm);                    \
	dsm_struct##.can_data_tx[3] = (uint8_T)(uint32_can_func_val);         \
	dsm_struct##.can_data_tx[4] = (uint8_T)(uint32_can_func_val >> 8);    \
	dsm_struct##.can_data_tx[5] = (uint8_T)(0);                           \
	dsm_struct##.can_data_tx[6] = (uint8_T)(0);                           \
}

#define sendUint32CanDataTx()                                              \
{                                                                          \
	if(can_data_rx_tmp[0] == 0) /*if write*/                               \
	{                                                                      \
		*ptr_uint32_dsm = (uint32_T)(uint32_can_func_val);                 \
	}                                                                      \
	uint32_can_func_val = (uint32_T)(*ptr_uint32_dsm);                     \
	dsm_struct##.can_data_tx[3] = (uint8_T)(uint32_can_func_val);          \
	dsm_struct##.can_data_tx[4] = (uint8_T)(uint32_can_func_val >> 8);     \
	dsm_struct##.can_data_tx[5] = (uint8_T)(uint32_can_func_val >> 16);    \
	dsm_struct##.can_data_tx[6] = (uint8_T)(uint32_can_func_val >> 24);    \
}

#define sendVersion()                                               \
{                                                                   \
	dsm_struct##.can_data_tx[3] = (uint8_T)(version_minor);         \
	dsm_struct##.can_data_tx[4] = (uint8_T)(version_major);         \
	dsm_struct##.can_data_tx[5] = (uint8_T)(0);                     \
	dsm_struct##.can_data_tx[6] = (uint8_T)(0);                     \
}