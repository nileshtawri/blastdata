% NPC PFC Control Loop Design
% Author: 
% First created: 25.05.2022
% Last modified: 18.11.2022
% Revision: 0.2
% Descriptions:
% 0.1: First design attempt with circuit dimensioning
% 0.2: Updated and Simplified the Script for Easy understanding

clear;

%%%%%%%%%%%%% 1. Local Parameter Initialize %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Set Bode Plot Options    
bopt               = bodeoptions;
bopt.Grid          = 'on';
bopt.PhaseMatching = 'on';
bopt.FreqUnits = 'Hz';

%%%%%%%%%%%%%%%%%%% 2. PWM setting %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Fclk=200e6; %PWM clock frequency

Control_Freq=65e3; %switching frequency
Control_Period=1/Control_Freq; % switching period

Tsw_Count=floor(Fclk/Control_Freq/2); %switching period as factor of PWM clock period /Register Value

s=tf('s');
z=tf('z',Control_Period);

%%%%%%%%%%%%% 3. ADC & Feeback Gain/Filter Setting %%%%%%%%%%%%%%%%%%%%%%%%
Vadc_Ref = 3.3; %ADC reference voltage, note different for different design
Adc_Bits = 12; %12 bit ADC
Adc_Max = 2^Adc_Bits-1; %ADC full scale 
Adc_Gain = Adc_Max/Vadc_Ref;

%% iL - Inductor Current sense Feedback & Filter Parameters
L_PFC_Inductor = 182e-6;    %PFC Inductor Value in Henry
iL_CS_Resistor = 0.0005;
iL_Stage1_AMC1301_Gain = 8.2;
iL_Stage2_Opamp_Rin = 2.21e3;
iL_Stage2_Opamp_Rfb = 11e3;
iL_Stage2_Opamp_Gain = iL_Stage2_Opamp_Rfb / iL_Stage2_Opamp_Rin;

iL_Gain_Total = iL_CS_Resistor * iL_Stage1_AMC1301_Gain * iL_Stage2_Opamp_Gain;

iL_Rfilt3=1e3;
iL_Cfilt3=47e-9; 
iL_RC_Filt3 = 1/(2 * pi * iL_Rfilt3 * iL_Cfilt3); %3.3kHz
iL_RC_Filt3_TF = 1/(1+(s*iL_Rfilt3*iL_Cfilt3)); %3.3kHz

%% Vbulk - Voltage sense Feedback & Filter Parameters
vPFC_Cap = 1 / (1/(4*560e-6) + 1/(4*560e-6)) + 10e-6; %new  2240uF

vPFC_Sen_Opamp_Rinp = (300e3 * 5) + 51.1e3;     %Vbulk sense resistance top
vPFC_Sen_Opamp_Rfb = 5.62e3;                    %Vbulk sense resistance bottom
vPFC_Sen_Gain = vPFC_Sen_Opamp_Rfb / (vPFC_Sen_Opamp_Rinp + vPFC_Sen_Opamp_Rfb);              

vPFC_Rfilt1=5.62e3;                %Vbulk sense resistance bottom
vPFC_Cfilt1=0.22e-6;

vPFC_RC_Filt1 = 1/(2 * pi * vPFC_Rfilt1 * vPFC_Cfilt1); %128.72Hz
vPFC_RC_Filt1_TF = 1/(1+(s*vPFC_Rfilt1*vPFC_Cfilt1)); %128.72Hz

Vm = 800/800 * Tsw_Count;   %??%

%%%%%%%%%%%%%%%% 4. System Parameters  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Vph_Nominal = 208;
Cos_Ph = 0.99;

PFC_Vout = 750;     %Vbulk target voltage
Pout_Rated = 11000;  %Rated output power 11kW Per 
Pout_Ratio = 1.0;   %Ratio of O/P load to full load
PFC_Eff = 0.97;     %Estimated Efficiency of PFC
 
PFC_Pout = Pout_Rated * Pout_Ratio;
PFC_Pin = PFC_Pout / PFC_Eff;

Iph_208VAC = PFC_Pin / ( 1 * Vph_Nominal * Cos_Ph); %at nom line
if Iph_208VAC > 32 
    Iph_208VAC = 32;
end

%%%%%%%%%%%%%%%% 5. Control Loop Design %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% % % % % 5a. Uncompensated Current Loop Gain % % % % % % % % % % % % % % %
% 
%
% 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
fprintf ('\n  *** Step 1: Getting Uncompensated Current Loop Gain ***\n')

Gain_CCM = (PFC_Vout * 0.5) / (s * L_PFC_Inductor); % CCM PFC Plant Gain
Tuolgi=(iL_Gain_Total * Adc_Gain * PFC_Vout * 0.5) / (L_PFC_Inductor * Vm);

Uncomp_CurrLp_Gain = iL_Gain_Total * Adc_Gain * Gain_CCM / Vm;
Uncomp_CurrLp_Gain_RC_Filt = Uncomp_CurrLp_Gain * iL_RC_Filt3_TF

%% Calculate / Estimate Other Parameters
Zeros = abs(zero(Uncomp_CurrLp_Gain_RC_Filt));
No_of_Zeros = size(Zeros,1);
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros
    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(Uncomp_CurrLp_Gain_RC_Filt));
No_of_Poles = size(Poles,1);
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(Uncomp_CurrLp_Gain_RC_Filt));
%sisotool(Uncomp_CurrLp_Gain_RC_Filt)

Plant_Margins = allmargin(Uncomp_CurrLp_Gain_RC_Filt);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);

fprintf ('Uncompensated Current Loop Gain Zeros (%u) @  :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('Uncompensated Current Loop Gain Poles (%u) @  :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')

fprintf ('Uncompensated Current Loop DC Gain               = %f dB\n',Kdc)
fprintf ('Uncompensated Current Loop Gain Margin           = %f dB\n',Gm)
fprintf ('Uncompensated Current Loop Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('Uncompensated Current Loop Phase Margin          = %f deg\n',Pm)
fprintf ('Uncompensated Current Loop Phase Margin Frequency= %f Hz\n',PmFreq)

figure(1);
bopt.Title.String = {'Uncompensated Current Loop Gain with Filters'};
bode(Uncomp_CurrLp_Gain_RC_Filt, {2*pi*1, 2*pi*1e6},bopt);

figure(2);
pzmap(Uncomp_CurrLp_Gain_RC_Filt);
grid on;

% % % % % 5b. Current Loop Controller Design % % % % % % % % % % % % % % %
% 
%
% 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n\n  *** Step 2: Designing Current loop Controller / Compensator  ***\n')
fprintf ('          Controller / Compensator Equation :- \n')
fprintf ('               \n')

fci = 6e3;              %target controller bandwidth 6Khz
PMi = (52 / 180) * pi;  %target Phase Margin

Kreq_at_fci = 1 / ((Tuolgi / (2*pi*fci)) * (3/(sqrt(1 + (fci/iL_RC_Filt3)^2))));%Required gain at fci with passive RC

fz1=fci*sqrt((1-sin(PMi))/(1+sin(PMi)));
fp1=fci*sqrt((1+sin(PMi))/(1-sin(PMi)));
fz_RC_i=(1/4)*fci; %1/4*fci

fprintf ('Current Loop Controller Input Parameters:\n')
fprintf ('Target Bandwidth -> fci = %f\n', fci)
fprintf ('Target Phase Margin -> PMi = %f\n', PMi)
fprintf ('Required Gain @ fci -> Kreq = %f\n', Kreq_at_fci)
fprintf ('Frequency of RC Filter Zero -> Fz_RC = %f\n', fz_RC_i)
fprintf ('Frequency of Compensator Zero -> Fz1 = %f\n', fz1)
fprintf ('Frequency of Compensator Pole -> Fp1 = %f\n', fp1)

CurrLp_Cotroller = Kreq_at_fci * (1 + (2 * pi * fz_RC_i) / s) * (1 + s / (2 * pi * fz1)) / (1 + s / (2 * pi * fp1))

CurrLp_Cotroller_in_Zdomain = c2d(CurrLp_Cotroller,Control_Period,'tustin')

Num = CurrLp_Cotroller_in_Zdomain.Numerator;
Den = CurrLp_Cotroller_in_Zdomain.Denominator;

fprintf ('Controller Co-efficients:\n')
fprintf ('       a0           a1          a2    \n')
fprintf ('    %f', Num{:})
fprintf (' \n\n')
fprintf ('       b0           b1          b2    \n')
fprintf ('    %f', Den{:})
fprintf (' \n')

% % % % % 5c. Compensated Current Loop Gain % % % % % % % % % % % % % % % %
% 
%
% 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n\n  *** Step 3: Getting Compensated Current Loop Gain ***\n')
Comp_CurrLp_Gain_WithRC = Uncomp_CurrLp_Gain_RC_Filt * CurrLp_Cotroller

%% Calculate / Estimate Other Parameters
Zeros = abs(zero(Comp_CurrLp_Gain_WithRC));
No_of_Zeros = size(Zeros,1);
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros
    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(Comp_CurrLp_Gain_WithRC));
No_of_Poles = size(Poles,1);
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(Comp_CurrLp_Gain_WithRC));
%sisotool(Comp_CurrLp_Gain_WithRC)

Plant_Margins = allmargin(Comp_CurrLp_Gain_WithRC);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);

fprintf ('Compensated Current Loop Gain Zeros (%u) @  :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('Compensated Current Loop Gain Poles (%u) @  :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')

fprintf ('Compensated Current Loop DC Gain               = %f dB\n',Kdc)
fprintf ('Compensated Current Loop Gain Margin           = %f dB\n',Gm)
fprintf ('Compensated Current Loop Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('Compensated Current Loop Phase Margin          = %f deg\n',Pm)
fprintf ('Compensated Current Loop Phase Margin Frequency= %f Hz\n',PmFreq)

figure(3);
bopt.Title.String = {'Compensated Current Loop Gain with Filters'};
bode(Comp_CurrLp_Gain_WithRC, {2*pi*1, 2*pi*1e6},bopt);

figure(4);
pzmap(Comp_CurrLp_Gain_WithRC);
grid on;

% % % % % 5c. Uncompensated Voltage Loop Gain % % % % % % % % % % % % % % % %
% 
%
% 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n\n  *** Step 4: Getting Uncompensated Voltage Loop Gain ***\n')

vLoop_Out = Iph_208VAC * sqrt(2) * iL_Gain_Total * Adc_Gain; %output voltage of voltage loop at puload (proportional to peak of input current) 

Vo_PFCPlant_TF = (PFC_Pin / ( s * vPFC_Cap * vLoop_Out * (PFC_Vout * 0.5)));

Tuolgv=(vPFC_Sen_Gain * Adc_Gain * PFC_Pin) / (vPFC_Cap * vLoop_Out * (PFC_Vout * 0.5));
Uncomp_VoltLp_Gain = vPFC_Sen_Gain * Adc_Gain * Vo_PFCPlant_TF;
Uncomp_VoltLp_Gain_RC_Filt = Uncomp_VoltLp_Gain * vPFC_RC_Filt1_TF

%% Calculate / Estimate Other Parameters
Zeros = abs(zero(Uncomp_VoltLp_Gain_RC_Filt));
No_of_Zeros = size(Zeros,1);
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros
    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(Uncomp_VoltLp_Gain_RC_Filt));
No_of_Poles = size(Poles,1);
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(Uncomp_VoltLp_Gain_RC_Filt));
%sisotool(Uncomp_VoltLp_Gain_RC_Filt)

Plant_Margins = allmargin(Uncomp_VoltLp_Gain_RC_Filt);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);

fprintf ('Uncompensated Voltage Loop Gain Zeros (%u) @  :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('Uncompensated Voltage Loop Gain Poles (%u) @  :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')

fprintf ('Uncompensated Voltage Loop DC Gain               = %f dB\n',Kdc)
fprintf ('Uncompensated Voltage Loop Gain Margin           = %f dB\n',Gm)
fprintf ('Uncompensated Voltage Loop Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('Uncompensated Voltage Loop Phase Margin          = %f deg\n',Pm)
fprintf ('Uncompensated Voltage Loop Phase Margin Frequency= %f Hz\n',PmFreq)

figure(5);
bopt.Title.String = {'Uncompensated Voltage Loop Gain with Filters'};
bode(Uncomp_VoltLp_Gain_RC_Filt, {2*pi*1, 2*pi*1e6},bopt);

figure(6);
pzmap(Uncomp_VoltLp_Gain_RC_Filt);
grid on;

% % % % % 5d. Voltage Loop Controller Design % % % % % % % % % % % % % % %
% 
%
% 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n\n  *** Step 5: Designing Voltage Loop Controller / Compensator  ***\n')
fprintf ('          Controller / Compensator Equation :- \n')
fprintf ('               \n')

fcv = 18;               %target controller bandwidth 15hz
PMv = (50 / 180) * pi;  %target Phase Margin
delta_PMv_ZOH = 2 * pi * fcv * Control_Period/2;
fp_LPF = 30;            %pole location of LPF to get ~0.5 attenuation factor of >2fline_min ripple 210, 45

Kreq_at_fcv = 1 / ((Tuolgv / (2*pi*fcv)) * (1/(sqrt(1 + (fcv/vPFC_RC_Filt1)^2))) * (1/(sqrt(1 + (fcv/fp_LPF)^2)))); %Required gain at fci with passive RC

fz_RC_v = fcv / tan(PMv + delta_PMv_ZOH + atan(fcv / vPFC_RC_Filt1) + atan(fcv / fp_LPF)); 

fprintf ('Current Loop Controller Input Parameters:\n')
fprintf ('Target Bandwidth -> fcv = %f\n', fcv)
fprintf ('Target Phase Margin -> PMv = %f\n', PMv)
fprintf ('Required Gain @ fcv -> Kreq = %f\n', Kreq_at_fcv)
fprintf ('Frequency of RC Filter Zero -> Fz_RC = %f\n', fz_RC_v)
fprintf ('Frequency of Compensator Pole (1st Stage LPF)-> fp_LPF = %f\n', fp_LPF)

VoltLp_Cotroller = Kreq_at_fcv * (1 + (2 * pi * fz_RC_v) / s) * (1 / (1 + s / (2 * pi * fp_LPF)))

VoltLp_Cotroller_in_Zdomain = c2d(VoltLp_Cotroller,Control_Period,'zoh')

Num = VoltLp_Cotroller_in_Zdomain.Numerator;
Den = VoltLp_Cotroller_in_Zdomain.Denominator;

fprintf ('Controller Co-efficients:\n')
fprintf ('       a0           a1          a2    \n')
fprintf ('    %f', Num{:})
fprintf (' \n\n')
fprintf ('       b0           b1          b2    \n')
fprintf ('    %f', Den{:})
fprintf (' \n')

% % % % % 5e. Compensated Voltage Loop Gain % % % % % % % % % % % % % % % %
% 
%
% 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n\n  *** Step 6: Getting Compensated Voltage Loop Gain ***\n')
Comp_VoltLp_Gain_WithRC = Uncomp_VoltLp_Gain_RC_Filt * VoltLp_Cotroller

%% Calculate / Estimate Other Parameters
Zeros = abs(zero(Comp_VoltLp_Gain_WithRC));
No_of_Zeros = size(Zeros,1);
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros
    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(Comp_VoltLp_Gain_WithRC));
No_of_Poles = size(Poles,1);
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(Comp_VoltLp_Gain_WithRC));
%sisotool(Comp_VoltLp_Gain_WithRC)

Plant_Margins = allmargin(Comp_VoltLp_Gain_WithRC);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);

fprintf ('Compensated Voltage Loop Gain Zeros (%u) @  :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('Compensated Voltage Loop Gain Poles (%u) @  :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')

fprintf ('Compensated Voltage Loop DC Gain               = %f dB\n',Kdc)
fprintf ('Compensated Voltage Loop Gain Margin           = %f dB\n',Gm)
fprintf ('Compensated Voltage Loop Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('Compensated Voltage Loop Phase Margin          = %f deg\n',Pm)
fprintf ('Compensated Voltage Loop Phase Margin Frequency= %f Hz\n',PmFreq)

figure(7);
bopt.Title.String = {'Compensated Voltage Loop Gain with Filters'};
bode(Comp_VoltLp_Gain_WithRC, {2*pi*1, 2*pi*1e6},bopt);

figure(8);
pzmap(Comp_VoltLp_Gain_WithRC);
grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%