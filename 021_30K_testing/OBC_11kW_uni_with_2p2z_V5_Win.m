%%%% 
%%%% Digital Control For Power Factor Correction
%%%% This cript is developed to generate the coefficients of PFC controller 
%%%% This is designed with the parameters from 30kW hardware. After completion of the testing, it will be adjusted accordingly for the 11kW uni project. 


%V2 : 
% Bode plots will be plotted in Hz unit
% Each plot will be labelled
% Added coefficient file generation part.
% All of the above sections are completed only for Current loop only.

%V3 : 
% Voltage loop section completed.


%V4 : 
% Clean up.


%V5
% Load condition changed.

%V6
%Filter values changed according to 30kW hardware
%Current sense resistor changed back to 1mohm (one piece only)

%V7
%Tsw_count updated

%V8
%Switching frequency changed to 50kHz

%V9
%Changed the bandwidth of voltage loop to 5Hz

%V10(This is last know good working version.)
%Changed the execution frequency of voltage loop to 5 kHz

%V11 (Rev 10 is last know good working version. PF is good. but output voltage is noisy.)
%Changed the bandwidth of voltage loop to 10Hz. Increased to improve output ripple. 



clear all;
clc;


%%%%%%%%%%%%%%% I/O parameters %%%%%%%%%%%%%%%%%%

Vin_PFC_rms=50;
Vo_PFC=160; %Vbulk target voltage
Po_PFC=500; %Rated output power

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Current loop parameters %%%%%%%%%%%%%%%%%%%%%%%
Fsw=50e3; %switching frequency
Tsw=1/Fsw; % switching period
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Efficiency_PFC=0.97;
Power_Factor=0.99;
Io_PFC=Po_PFC/Vo_PFC; 							%output current
Pin_PFC=Po_PFC/Efficiency_PFC; 					%input power
Iph_rated=Pin_PFC/(Vin_PFC_rms*Power_Factor); 

VADC = 3.3; 			
ADC_bits = 12; 			%12 bit ADC
ADC_FS = 2^ADC_bits-1; 	%ADC full scale 
ADC_gain = ADC_FS/VADC;

Current_sense_resistor=1*1e-3; %30kW New resistor to test at low.
Isolated_amplifier_gain=8.2;
Amplifier_gain_resistor_R1=2.21e3;
Amplifier_gain_resistor_R2=8.06e3; 
Current_sense_gain=Amplifier_gain_resistor_R2/Amplifier_gain_resistor_R1;
Current_sense_gain_tot=Current_sense_gain*Current_sense_resistor*Isolated_amplifier_gain; 

% Bulk voltage sensing
Co_PFC=1/(1/(3*560e-6)+1/(3*560e-6))+ 20e-6; 	%30kW
Vo_sensing_upper_side_resistor=301e3*5+51.1e3; 	%Vbulk sense resistance top
Vo_sensing_low_side_resistor=5.62e3; 			%Vbulk sense resistance bottom
Vo_sensing_filter_cap=0.22e-6;
Vo_PFC_f_fil1=1/(2*pi*Vo_sensing_low_side_resistor*Vo_sensing_filter_cap); 
Vout_sensing_divider_gain=Vo_sensing_low_side_resistor/(Vo_sensing_low_side_resistor+Vo_sensing_upper_side_resistor); 


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Inductor current sensing
LPFC=216e-6; 
Current_sense_resistor=1*1e-3; %30kW New resistor to test at low.
Isolated_amplifier_gain=8.2;
Amplifier_gain_resistor_R1=2.21e3;
Amplifier_gain_resistor_R2=8.06e3; 
Current_sense_gain=Amplifier_gain_resistor_R2/Amplifier_gain_resistor_R1;
Current_sense_gain_tot=Current_sense_gain*Current_sense_resistor*Isolated_amplifier_gain; 

Current_sense_filter_R=1e3;
Current_sense_filter_C=47e-9; 
Current_sense_filter_cutoff_freq=1/(2*pi*Current_sense_filter_R*Current_sense_filter_C); 
Maximum_Inductor_Current=VADC/2/Current_sense_gain_tot; %max current measurable by ADC, offset by 1.65V

% Input voltage sensing
AC_sensing_resistor_upper=390e3*4+240e3+34.8e3; 	%VAC sense resistance top
AC_sensing_resistor_lower=3.3e3; 					%VAC sense resistance bottom
AC_sensing_resistor_divider_gain=AC_sensing_resistor_lower/(AC_sensing_resistor_lower+AC_sensing_resistor_upper); %VAC sense ratio 1/163
Vin_max=VADC/2/AC_sensing_resistor_divider_gain; %max voltage measureable by ADC, offset by 1.65V


Co_PFC=1/(1/(3*560e-6)+1/(3*560e-6))+ 20e-6; %30kW

MCU_Clk_Freq		= 90e6; 					% MCU clock frequency
Tclk				= 1/MCU_Clk_Freq; 			% MCU clock period
Tsw_count			= floor(MCU_Clk_Freq/Fsw); 
DPWM=1/Tsw_count;

s=tf('s');
z=tf('z',Tsw);


% Boost transfer function - duty to inductor current
% CCM_PFC_plant = Gid
CCM_PFC_plant=Vo_PFC/(s*LPFC); %CCM PFC plant  Vo_PFC/(s*LPFC)
Sensing_Gain=(Current_sense_gain_tot*ADC_gain*Vo_PFC)*DPWM/(LPFC);

% Uncompensated_loop_gain - LPF not yet included, (Ti excludes Gcc)
Uncompensated_loop_gain=Current_sense_gain_tot*ADC_gain*CCM_PFC_plant*DPWM;	

Current_loop_filter_gain=1/(1+s*Current_sense_filter_R*Current_sense_filter_C);
Uncompensated_current_loop_gain=Current_sense_gain_tot*ADC_gain*CCM_PFC_plant*Current_loop_filter_gain*DPWM;


fci=6e3; 							%target controller bandwidth 5e3 
fz_RC_i=1/1000*fci;
PMi=45/180*pi; 						%target phase margin 
delta_PMi_ZOH=2*pi*fci*Tsw/2; 

Kp_RC_i=1/(Sensing_Gain/(2*pi*fci)*3/(sqrt(1+(fci/Current_sense_filter_cutoff_freq)^2)));
fz1=fci*sqrt((1-sin(PMi))/(1+sin(PMi)));
fp1=fci*sqrt((1+sin(PMi))/(1-sin(PMi)));

%%Kp_RC_i=2;
Current_loop_compensator=Kp_RC_i*(1+(2*pi*fz_RC_i)/s)*(1+s/(2*pi*fz1))/(1+s/(2*pi*fp1));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% delta = 0;
% f_pole1 = 14.3-delta		; 	%% in Hz
% f_pole2 = 6000-delta	; 	%% in Hz
% f_zero1 = 1000		; 	%% in Hz
% k=1;


% % % % Desired_compensator_gain_in_dB = 100;
% % % % k=20*log(Desired_compensator_gain_in_dB);

% pole1 	= 2*pi* f_pole1;
% pole2 	= 2*pi* f_pole2;
% zero1 	= 2*pi* f_zero1;

% %% 2P2Z compensator
% Compensator	= k*	 pole1/s *  (1+s/zero1) / (1+s/pole2);
% Current_loop_compensator= k*	 pole1/s *  (1+s/zero1) / (1+s/pole2);
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Compensated_current_loop=Current_loop_compensator*Uncompensated_current_loop_gain; % compensated open loop function
Current_loop_compensator_digital=c2d(Current_loop_compensator,Tsw,'tustin');

%%Uncompensated_current_loop_gain_digital=c2d(Uncompensated_current_loop_gain,Tsi,'tustin'); 
%uncompensated open loop function with passive RC in Z domain
%%Compensated_current_loop=Current_loop_compensator_digital*Uncompensated_current_loop_gain_digital; % compensated open loop function

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%figure(2);
options1=bodeoptions('cstprefs');
options1.PhaseVisible = 'off';
%options1.YLim={[-100 100]};
options1.XLim={[1 1e6]};
options1.FreqUnits = 'Hz'; % or 'rad/second', 'rpm', etc.
Mag=subplot(2,1,1);
margin(Compensated_current_loop,options1);
title('Tc_RC_i : Compensated Current Loop Gain');

set(xlabel(''),'visible','off');
options2=bodeoptions('cstprefs');
options2.MagVisible = 'off';
%options2.YLim={[-180 180]};
options2.XLim={[1 1e6]};
options2.FreqUnits = 'Hz'; % or 'rad/second', 'rpm', etc.
Phase=subplot(2,1,2);
margin(Compensated_current_loop,options2);grid on; 
%%Using 'margin' command, margin values must display as positive for stablility
clc

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% what we are doing here until now is checking open loop stability.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[NUM, DEN] = tfdata(Current_loop_compensator_digital);
NUM=NUM{1,1};
I_loop_b0=NUM(1,1);
I_loop_b1=NUM(1,2);
I_loop_b2=NUM(1,3);

DEN=DEN{1,1};
I_loop_a0=DEN(1,1);
disp ('a0 should be 1 and it is not required to put in the controller equation.');
I_loop_a1=DEN(1,2);
I_loop_a2=DEN(1,3);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%% write / print the parameters in the text file. 
filename = fopen( 'Generated_Coefficients.txt', 'a' );
fprintf( filename, '************************************************\n');
fprintf( filename, '************************************************\n');
fprintf( filename, datestr(now,'dd-mm-yyyy -- HH:MM:SS\n\n'));

%% https://lingojam.com/ItalicTextGenerator

fprintf( filename, '► 𝑷𝒍𝒂𝒏𝒕 & 𝑳𝒐𝒂𝒅 𝒑𝒂𝒓𝒂𝒎𝒆𝒕𝒆𝒓𝒔 \n');
fprintf( filename, '𝑰𝒏𝒑𝒖𝒕 𝒗𝒐𝒍𝒕𝒂𝒈𝒆, 𝑽𝒊𝒏_𝒏𝒐𝒎𝒊𝒏𝒂𝒍   = %1.0f V\n',Vin_PFC_rms);
fprintf( filename, '𝑶𝒖𝒕𝒑𝒖𝒕 𝒗𝒐𝒍𝒕𝒂𝒈𝒆, 𝑽𝒐_𝑷𝑭𝑪     = %1.0f V\n',Vo_PFC);
fprintf( filename, '𝑶𝒖𝒕𝒑𝒖𝒕 𝒑𝒐𝒘𝒆𝒓, 𝑷𝒐_𝑷𝑭𝑪      = %1.0f W\n\n\n',Po_PFC);

%fprintf( filename, '************************************************\n');

fprintf( filename, '► 𝑪𝒖𝒓𝒓𝒆𝒏𝒕 𝒍𝒐𝒐𝒑 𝒄𝒐𝒏𝒕𝒓𝒐𝒍𝒍𝒆𝒓 𝒄𝒐𝒆𝒇𝒇𝒊𝒄𝒊𝒆𝒏𝒕𝒔\n');
fprintf( filename, '• 𝑰_𝒍𝒐𝒐𝒑_𝒃0 = %d\n• 𝑰_𝒍𝒐𝒐𝒑_𝒃1 = %d\n• 𝑰_𝒍𝒐𝒐𝒑_𝒃2 = %d\n• 𝑰_𝒍𝒐𝒐𝒑_𝒂1 = %d\n• 𝑰_𝒍𝒐𝒐𝒑_𝒂2 = %d\n\n\n', I_loop_b0, I_loop_b1, I_loop_b2, I_loop_a1,I_loop_a2);
%fprintf( filename, '************************************************\n');

fclose(filename);
clc
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

s=tf('s');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Sampling_time_voltage_loop=1/5e3; % Change the frequency of voltage loop to 5kHz

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

z=tf('z',Sampling_time_voltage_loop);
Voltage_loop_output = Iph_rated*sqrt(2)*Current_sense_gain_tot*ADC_gain; 
PFC_Plant_for_Voltage_Loop=Pin_PFC/(s*Co_PFC*Voltage_loop_output*Vo_PFC); 
Voltage_sensing_filter_gain=1/(1+s*Vo_sensing_low_side_resistor*Vo_sensing_filter_cap);
Uncompensated_voltage_loop_gain=Vout_sensing_divider_gain*ADC_gain*Voltage_sensing_filter_gain*PFC_Plant_for_Voltage_Loop;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% The voltage loop / compensator and compares the output voltage feedback to a constant reference. Its output is fed into amultiplier along with 2 other components; the first is an inverse of the peak input voltage, which is used to normalize the loop gain and make it independent of the line voltage throughout the universal input range. The second component in themultiplier is the instantaneous input voltage; this will shape the current reference to be proportional to the line voltage and achieve a high power factor. The result of themultiplier is a rectified sinusoidal signal that is passed to the current loop reference input. 

% The main design consideration for the voltage compensator is to have a slow dynamic signal across one half line cycle, so that it does not distort the sine wave fed fromthe line voltage. If the voltage compensator is dynamic enough during the line cycle, then the current command will be distorted and notmatch the line feedforward signal, causing higher THDi. Therefore, the voltage controller is designed with a much slower bandwidth compared to the current loop. The typical bandwitch of ~5 Hz can ensure that it will not be dynamic over the 50-60 Hz cycle.



s=tf('s');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% Below one seems to be good without very high overshoot. Nat tested it.
f_pole1 = 4.3		; 	%% in Hz
f_pole2 = 37	; 	%% in Hz
f_zero1 = 2.67		; 	%% in Hz
k = 1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
delta = 0;
f_pole1 = 14.3-delta		; 	%% in Hz
f_pole2 = 47-delta	; 	%% in Hz
f_zero1 = 2.67		; 	%% in Hz
k=1;

% % % Desired_compensator_gain_in_dB = 100;
% % % k=20*log(Desired_compensator_gain_in_dB);

pole1 	= 2*pi* f_pole1;
pole2 	= 2*pi* f_pole2;
zero1 	= 2*pi* f_zero1;

%% 2P2Z compensator
Compensator	= k*	 pole1/s *  (1+s/zero1) / (1+s/pole2);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%% Win : This is for PSIM simulation_Compensated_loopons (if required) for future control parameter designs 
%%%% Obtain the Bode plot data 

% Uncompensated_voltage_loop_gain = Uncompensated_voltage_loop_gain;

% [mag, phase, wout] = bode(Uncompensated_voltage_loop_gain,{1,2*pi*100e3}); 

% % Convert the magnitude and phase data to decibels and degrees, respecTi_Compensated_loopvely
% mag_dB = 20*log10(squeeze(mag));
% phase_deg = squeeze(phase) * 2/pi;
% fout_Hz = wout/(2*pi);

% % Create a matrix of the data
% data = [fout_Hz, mag_dB, phase_deg];

% % Write the data to a text file, 
% fid = fopen('Matlab_exported_data.txt', 'w');
% fprintf(fid, '%12s %12s %12s\n', 'Freq(Hz)', 'Abs(dB)', 'Phase(°)');
% fprintf(fid, '%12.6f %12.6f %12.6f\n', data.');
% fclose(fid);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Compensator_digital=c2d(Compensator,Sampling_time_voltage_loop,'tustin');
Uncompensated_voltage_loop_gaind=c2d(Uncompensated_voltage_loop_gain,Sampling_time_voltage_loop,'zoh');
Compensated_Voltage_Loop_Gain=Compensator*Uncompensated_voltage_loop_gain;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% figure(1);

% options1=bodeoptions('cstprefs');
% options1.PhaseVisible = 'off';
% options1.YLim={[-30 50]};
% options1.XLim={[1 1e3]};
% options1.FreqUnits = 'Hz'; 
% Mag=subplot(2,1,1);
% margin(Compensated_Voltage_Loop_Gain,options1);
% title('Compensated Voltage Loop Gain');

% set(xlabel(''),'visible','off');
% options2=bodeoptions('cstprefs');
% options2.MagVisible = 'off';
% options2.YLim={[-200 -90]};
% options2.XLim={[1 1e3]};
% options2.FreqUnits = 'Hz'; 
% Phase=subplot(2,1,2);
% margin(Compensated_Voltage_Loop_Gain,options2);grid on; 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[NUM, DEN] = tfdata(Compensator_digital);
NUM=NUM{1,1};
V_loop_b0=NUM(1,1);
V_loop_b1=NUM(1,2);
V_loop_b2=NUM(1,3);

DEN=DEN{1,1};
V_loop_a0=DEN(1,1);
disp ('a0 should be 1 and it is not required to put in the controller equation.');
V_loop_a1=DEN(1,2);
V_loop_a2=DEN(1,3);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% write / print the parameters in the text file. 
filename = fopen( 'Generated_Coefficients.txt', 'a' );
fprintf( filename, '► 𝑽𝒐𝒍𝒕𝒂𝒈𝒆 𝒍𝒐𝒐𝒑 𝒄𝒐𝒏𝒕𝒓𝒐𝒍𝒍𝒆𝒓 𝒄𝒐𝒆𝒇𝒇𝒊𝒄𝒊𝒆𝒏𝒕𝒔\n');
fprintf( filename, '• 𝑽_𝒍𝒐𝒐𝒑_𝒃0 = %d\n• 𝑽_𝒍𝒐𝒐𝒑_𝒃1 = %d\n• 𝑽_𝒍𝒐𝒐𝒑_𝒃2 = %d\n• 𝑽_𝒍𝒐𝒐𝒑_𝒂1 = %d\n• 𝑽_𝒍𝒐𝒐𝒑_𝒂2 = %d\n\n', V_loop_b0, V_loop_b1, V_loop_b2,V_loop_a1,V_loop_a2);

fprintf( filename, '\n************************************************\n');
fprintf( filename, '► 𝑻𝒉𝒆 𝒇𝒐𝒓𝒎𝒂𝒕 𝒇𝒐𝒓 𝒄𝒐𝒆𝒇𝒇𝒊𝒄𝒊𝒆𝒏𝒕𝒔 𝒊𝒔 𝒔𝒉𝒐𝒘𝒏 𝒃𝒆𝒍𝒐𝒘.\n\n');
fprintf( filename, '𝒚(𝒌) = 𝒃0 𝒆(𝒌) + 𝒃1 𝒆(𝒌−1) + 𝒃2 𝒆(𝒌−2) − 𝒂1 𝒚(𝒌−1) − 𝒂2 𝒚(𝒌−2)\n\n');

fprintf( filename, '************************************************\n');
fprintf( filename, '◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘◘\n\n\n\n');
fclose(filename);
clc
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
