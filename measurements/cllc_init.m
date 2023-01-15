%Create sensors bus
%clear ADCPARAM_STRUCT
%ADCPARAM_STRUCT.adc_batterycurrent = uint16(0);
%ADCPARAM_STRUCT.adc_batteryvoltage = uint16(0);
%ADCPARAM_STRUCT.adc_chargeVoltage = uint16(0);
%ADCPARAM_STRUCT.adc_dcLinkvoltage    = uint16(0);
%ADCPARAM_STRUCT.adc_dcLinkcurrent    = uint16(0);
%ADCPARAM_STRUCT.adc_SOC             = uint16(0);

%tmp_BusName = Simulink.Bus.createObject(ADCPARAM_STRUCT);
%tmp_Bus = evalin('base',tmp_BusName.busName);
%evalin('base',['clear ' tmp_BusName.busName]);
%assignin('base','ADCPARAM_STRUCT',tmp_Bus);
%clear tmp_BusName tmp_Bus


%% Create enumerated types
%if exist('EnumMode','class')~=8
%    Simulink.defineIntEnumType('EnumStatus',...
%        {'INIT','STANDBY','NORMAL','FAULT'},...
%        [0,1,2,3]);
%end
%if exist('EnumDCDC_Mode','class')~=8
%    Simulink.defineIntEnumType('Enummode',...
%        {'forward','reverse'},...
%        [1,0]);
%end

%var_ref_vbat = 150;
%var_ref_iout = 5;

%assert_under = 0;
%tf_status = 0;