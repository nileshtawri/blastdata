% CLLLC Design, & Closed Loop Compensator Design CC Forward
% Author: Vinoth
% First created: 01.11.2022
% Last modified: 
% Revision: 1.0
% Descriptions:
% 0.1: Design closed loop CC control for forward mode

clear;
%%%%%%%%%%%%% 1. Local Parameter Initialize %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Set Bode Plot Options    
bopt               = bodeoptions;
bopt.Grid          = 'on';
bopt.PhaseMatching = 'on';
bopt.FreqUnits = 'Hz';

    %%Init Pole , Zero Values
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];

%%%%%%%%%%%%%%%%  v%%% 2. PWM setting %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Fclk=100e6; %PWM clock frequency
Tclk=1/Fclk; %PWM clock period

Control_Freq=20000;                 % Control Loop Exe. Frequency
Control_Period=1/Control_Freq;      % Time Period of it
s=tf('s');
z=tf('z',Control_Period);

%%%%%%%%%%%%% 3. ADC & Feeback Gain/Filter Setting %%%%%%%%%%%%%%%%%%%%%%%%
Vadc_Ref = 3.3;         %ADC reference voltage, note different for different design
Adc_Bits = 12; %12 bit ADC
Adc_Max = 2^Adc_Bits-1; %ADC full scale 
Adc_Gain = Adc_Max/Vadc_Ref;

    %% CV - Voltage Feedback Gain Parameters
VO_Sen_Opamp_Rin = 4e6+71.5e3;
VO_Sen_Opamp_Rfb = 23.2e3;
Vout_Max = Vadc_Ref / (VO_Sen_Opamp_Rfb/VO_Sen_Opamp_Rin);
Adc_Per_Unit_V = Adc_Max / Vout_Max;

    %% CV - Voltage Feedback Filter Parameters
VO_Sen_Filt1_R = 23.2e3;
VO_Sen_Filt1_C = 470e-12;
VO_Sen_Filt1_TF = 1/(1+(s*VO_Sen_Filt1_R*VO_Sen_Filt1_C));

VO_Sen_Filt2_R = 1e3;
VO_Sen_Filt2_C = 10e-9;
VO_Sen_Filt2_TF = 1/(1+(s*VO_Sen_Filt2_R*VO_Sen_Filt2_C));
    
    %% CC - Current Feedback Gain Parameters - ACS733KLATR-65AB-T
IO_Sensitivity_A = 0.02; % 20mV Per Amp
Iout_Max = Vadc_Ref / IO_Sensitivity_A;
Adc_Per_Unit_A = Adc_Max / Iout_Max;

    %% CC - Current Feedback Filter Parameters - Estimated - No Separate Filter
IO_Sen_Filt1_R = 50e3;
IO_Sen_Filt1_C = 0.1e-9;
IO_Sen_Filt1_TF = 1/(1+(s*IO_Sen_Filt1_R*IO_Sen_Filt1_C));

%%%%%%%%%%%%% 4.  %%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%% 5. Control Loop Design %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% % % % % % % % % % 5a. Plant Loop Gain @ 23.4A % % % % % %
% Vin = 750 , out = 470V, 23.4A, Fsw_Period = 2222 (100mhz/45.0khz)
%
% 1. Run Linearization manager (as per steps in ppt).
% 2. Get Open Loop Sweep data 'estsys1' and move to model workspace.
% 3. Rename Variable to 'Config1_OL_Plant_Bode'.
% 4. Save the Plant parameter data to project folder as'.mat' file.
% 5. Load that file and run below script to get Open Loop Plant Parameters.
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n  *** Step 1: Plant Open Loop Transfer Function Data ***\n')

    %% Load Plant Parameters/Variables from Saved File
load('CC_23A4_Tune_Data.mat');         

    %% Identify/Estimate Continuous Time Plant Transfer function from the data
CC_23A4_Plant_EstiData = tfest(CC_23A4_OL_Plant_Bode,2)

    %% Calculate / Estimate Other Parameters
CC_23A4_OL_Plant_TF = tf(CC_23A4_Plant_EstiData.Numerator,CC_23A4_Plant_EstiData.Denominator);

Zeros = abs(zero(CC_23A4_OL_Plant_TF));
No_of_Zeros = size(Zeros,1);
for no = 1:No_of_Zeros

    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(CC_23A4_OL_Plant_TF));
No_of_Poles = size(Poles,1);
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(CC_23A4_OL_Plant_TF));

Pl_TF_Den = CC_23A4_Plant_EstiData.Denominator;
Qc_Plant = 1 / ((Pl_TF_Den(1,2)/Pl_TF_Den(1,3))*(sqrt(Pl_TF_Den(1,3))));

Plant_Margins = allmargin(CC_23A4_OL_Plant_TF);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);
    
    %% Display Other estimated data's
fprintf ('\nPlant Zeros (%u) @            :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('Plant Poles (%u) @            :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')
fprintf ('Plant Pole Q factor        Q0 = %f \n',Qc_Plant )
fprintf (' \n')
fprintf ('Plant DC Gain                 = %f dB\n',Kdc)
fprintf ('Plant Gain Margin             = %f dB\n',Gm)
fprintf ('Plant Gain Margin Frequency   = %f Hz\n',GmFreq)
fprintf ('Plant Phase Margin            = %f deg\n',Pm)
fprintf ('Plant Phase Margin Frequency  = %f Hz\n',PmFreq)
% 
% figure(1);
% bopt.Title.String = {'CC 23.4A Open Loop Plant - Estimated Bode'};
% bode(CC_23A4_Plant_EstiData, {2*pi*10, 2*pi*3e5},bopt);

% % % % % % % % % % 5b. Plant Loop Gain with ADC Filters @ 27.5A % % % % % %
% Vin = 750 , out = 470V, 23.4A, Fsw_Period = 2222 (100mhz/45.0khz)
%
% 1. Run Linearization manager (as per steps in ppt).
% 2. Get Open Loop Sweep data 'estsys1' and move to model workspace.
% 3. Rename Variable to 'Config1_OL_Plant_Bode'.
% 4. Save the Plant parameter data to project folder as'.mat' file.
% 5. Load that file and run below script to get Open Loop Plant Parameters.
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
fprintf ('\n\n  *** Step 2: Plant Open Loop Transfer Function With FB Sense Filters ***\n')

CC_23A4_OL_Plant_TF_WFilt = CC_23A4_OL_Plant_TF * Adc_Per_Unit_V * IO_Sen_Filt1_TF
    
    %% Calculate / Estimate Other Parameters
Zeros = abs(zero(CC_23A4_OL_Plant_TF_WFilt));
No_of_Zeros = size(Zeros,1);
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros
    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(CC_23A4_OL_Plant_TF_WFilt));
No_of_Poles = size(Poles,1);
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(CC_23A4_OL_Plant_TF_WFilt));
% sisotool(CC_23A4_OL_Plant_TF_WFilt)

Plant_Margins = allmargin(CC_23A4_OL_Plant_TF_WFilt);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);
    
    %% Display Other estimated data's
fprintf ('CC 23.4A Plant(With Filter) Zeros (%u) @  :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('CC 23.4A Plant(With Filter) Poles (%u) @  :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')

fprintf ('CC 23.4A Plant(With Filter) DC Gain               = %f dB\n',Kdc)
fprintf ('CC 23.4A Plant(With Filter) Gain Margin           = %f dB\n',Gm)
fprintf ('CC 23.4A Plant(With Filter) Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('CC 23.4A Plant(With Filter) Phase Margin          = %f deg\n',Pm)
fprintf ('CC 23.4A Plant(With Filter) Phase Margin Frequency= %f Hz\n',PmFreq)

% figure(2);
% bopt.Title.String = {'CC 23.4A Open Loop Uncompensated Plant with Sense Filters'};
% bode(CC_23A4_OL_Plant_TF_WFilt, {2*pi*10, 2*pi*3e5},bopt);
% 
% figure(3);
% pzmap(CC_23A4_OL_Plant_TF_WFilt);
% grid on;

% % % % % % % % % % 5c. 2P2Z Compensator Design Parameters % % % % % % % %
% 
% 2P2Z Equation => Gc(s) = (Kc*((s^2/wz0^2)+(s/(Qc*wz0))+1))/(s(1+(s/wp))
% Where,
% Kc = Integral Gain of Compensator 
%
% --For Plant with Complex Poles--
% Qz2 = Quality Factor of Complex Pole frmom plant (to place it in Zero (fZ2)
%                                                          to Compensate it)
% fZ2 = + Compensator Zero Frequency  
%       (place it equal to  or below (Higer Freq.) to dominant resonant pole
%                       from all Configuration/Plant TF)
% fP2 = + Compensator Pole Frequency
%       (place at ESR zero or at half fsw or to get desired Gain Margin)
% 
% Get Above Parameters from Open Loop Sweep Uncompensated data'sfrom all
% Configurations
%
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
% fprintf ('\n\n  *** Step 3: 2P2Z Compensator Design Data ***\n')
% fprintf ('          Compensator Equation :- \n')
% fprintf ('              Kc*((s^2/wz^2) + ((s/(Qc*wz))+1)) / (s((s/wp) +1)) \n')
% 
% GM_Req = -60;
% Qcz2 = 0.63;%Qc_Plant;
% Fz2 = 2200;
% Fp2 = 15000;
% 
% Kc = 1/(10^(GM_Req/20));
% wZ2 = 2*pi*Fz2;
% wP2 = 2*pi*Fp2;
% 
% fprintf ('Compensator Input Parameters:\n')
% fprintf ('Required Gain Margin -> Gm_Req = %f\n', GM_Req)
% fprintf ('Q Factor oz Compensator Zero -> Qcz2 = %f\n', Qcz2)
% fprintf ('Frequency of Compensator Zero -> Fz2 = %f\n', Fz2)
% fprintf ('Frequency of Compensator Pole -> Fp2 = %f\n', Fp2)
% 
% Compensator_TF = Kc * (((1 + (s/(Qcz2*wZ2)) + (s/wZ2)^2)) / (s*(1+(s/wP2))))
% 
% Compensator_TF_in_Zdomain = c2d(Compensator_TF,Control_Period,'tustin')
% 
% Num = Compensator_TF_in_Zdomain.Numerator;
% Den = Compensator_TF_in_Zdomain.Denominator;
% 
% fprintf ('Compensator Co-efficients:\n')
% fprintf ('       a0           a1          a2    \n')
% fprintf ('    %f', Num{:})
% fprintf (' \n\n')
% fprintf ('       b0           b1          b2    \n')
% fprintf ('    %f', Den{:})
% fprintf (' \n')

% % % % % % % % % % 5d. Plotting Closed Loop Transfer Function % % % % % % 
% 
% Get Closed Loop Transfer Function from Compensator and Uncompensated
% Open Loop Transfer Function
%
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% fprintf ('\n\n  *** Step 4: Closed Loop Transfer Function Data with Designed 2P2Z Compensator ***\n')
% 
% CC_23A4_CL_TF = Compensator_TF * CC_23A4_OL_Plant_TF_WFilt
% 
%     %% Calculate / Estimate Other Parameters
% Zeros_CL = abs(zero(CC_23A4_CL_TF));
% No_of_Zeros_CL = size(Zeros_CL,1);
% Fz_CL = [0.0 0.0 0.0 0.0 0.0 0.0];
% for no = 1:No_of_Zeros_CL
%     Fz_CL(no,1) = Zeros_CL(no,1)/(2*pi);
% end
% 
% Poles_CL = abs(pole(CC_23A4_CL_TF));
% No_of_Poles_CL = size(Poles_CL,1);
% Fp_CL = [0.0 0.0 0.0 0.0 0.0 0.0];
% for no = 1:No_of_Poles_CL
%     Fp_CL(no,1) = Poles_CL(no,1)/(2*pi);
% end
% 
% Kdc = 20 * log10(dcgain(CC_23A4_CL_TF));
% sisotool(CC_23A4_CL_TF)
% 
% Plant_Margins = allmargin(CC_23A4_CL_TF);
% Gm = 20 * log10(Plant_Margins.GainMargin);
% GmFreq = Plant_Margins.GMFrequency/(2*pi);
% Pm = Plant_Margins.PhaseMargin;
% PmFreq=Plant_Margins.PMFrequency/(2*pi);
% 
% CL_Stable = isstable(CC_23A4_CL_TF);
%     
%     %% Display Other estimated data's
% fprintf ('CC 23.4A Closed Loop Zeros (%u) @  :-\n',No_of_Zeros_CL)
% for no = 1:No_of_Zeros_CL
%     fprintf ('      %f, ',Fz_CL(no,1))
% end
% fprintf (' \n')
% fprintf ('CC 23.4A Closed Loop Poles (%u) @  :-\n',No_of_Poles_CL)
% for no = 1:No_of_Poles_CL
%     fprintf ('      %f, ',Fp_CL(no,1))
% end
% fprintf (' \n')
% fprintf ('CC 23.4A Closed Loop DC Gain               = %f dB\n',Kdc)
% fprintf ('CC 23.4A Closed Loop Gain Margin           = %f dB\n',Gm)
% fprintf ('CC 23.4A Closed Loop Gain Margin Frequency = %f Hz\n',GmFreq)
% fprintf ('CC 23.4A Closed Loop Phase Margin          = %f deg\n',Pm)
% fprintf ('CC 23.4A Closed Loop Phase Margin Frequency= %f Hz\n',PmFreq)
% if CL_Stable==1
%     fprintf ('\n        Closed Loop STABLE\n')
% else
%     fprintf ('\n        Closed Loop UNSTABLE\n')
% end

% figure(4);
% bopt.Title.String = {'CC 23.4A Closed Loop Transfer Function with 2P2Z'};
% bode(CC_23A4_CL_TF, {2*pi*10, 2*pi*3e5},bopt);
% 
% figure(5);
% pzmap(CC_23A4_CL_TF);
% grid on;

% % % % % % % % % % 5e. PI Compensator Design Parameters % % % % % % % %
% 
% 2P2Z Equation => Gc(s) = (KL*(1+((2*Pi*fZl)/s)))
% Where,
% KL = Integral Gain of Compensator 
%
% --For Plant with Complex Poles--
% fZL = Compensator Zero Frequency  
%       (place it equal to  or below (Higer Freq.) to dominant resonant pole
%                       from all Configuration/Plant TF) 
% Get Above Parameters from Open Loop Sweep Uncompensated data'sfrom all
% Configurations
%
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % 
fprintf ('\n\n  *** Step 5: PI Compensator Design Data ***\n')
fprintf ('          PI Compensator Equation :- \n')
fprintf ('              Gc(s) = (KL*(1+((2*Pi*fZl)/s))) \n')

GM_Req_PI = 50;
KL = 1/(10^(GM_Req_PI/20));
FzL = 500;

fprintf ('PI Compensator Input Parameters:\n')
fprintf ('Required Gain Margin -> Gm_Req = %f\n', GM_Req_PI)
fprintf ('Frequency of Compensator Zero -> FzL = %f\n', FzL)

PI_Compensator_TF = KL*(1+((2*pi*FzL)/s));

PI_Compensator_TF_in_Zdomain = c2d(PI_Compensator_TF,Control_Period,'tustin')

Num = PI_Compensator_TF_in_Zdomain.Numerator;
Den = PI_Compensator_TF_in_Zdomain.Denominator;

fprintf ('Compensator Co-efficients:\n')
fprintf ('       a0           a1          a2    \n')
fprintf ('    %f', Num{:})
fprintf (' \n\n')
fprintf ('       b0           b1          b2    \n')
fprintf ('    %f', Den{:})
fprintf (' \n')

% % % % % % % % % % 5f. Plotting Closed Loop Transfer Function with PI Compensator % % % 
% 
% Get Closed Loop Transfer Function from Compensator and Uncompensated
% Open Loop Transfer Function
%
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
fprintf ('\n\n  *** Step 6: Closed Loop Transfer Function Data with Designed PI Compensator ***\n')

CC_23A4_PI_CL_TF = PI_Compensator_TF * CC_23A4_OL_Plant_TF_WFilt

    %% Calculate / Estimate Other Parameters
Zeros_CL = abs(zero(CC_23A4_PI_CL_TF));
No_of_Zeros_CL = size(Zeros_CL,1);
Fz_CL = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros_CL
    Fz_CL(no,1) = Zeros_CL(no,1)/(2*pi);
end

Poles_CL = abs(pole(CC_23A4_PI_CL_TF));
No_of_Poles_CL = size(Poles_CL,1);
Fp_CL = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles_CL
    Fp_CL(no,1) = Poles_CL(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(CC_23A4_PI_CL_TF));
sisotool(CC_23A4_PI_CL_TF)

Plant_Margins = allmargin(CC_23A4_PI_CL_TF);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);

CL_Stable = isstable(CC_23A4_PI_CL_TF);
    
    %% Display Other estimated data's
fprintf ('CC 23.4A Closed Loop Zeros (%u) @  :-\n',No_of_Zeros_CL)
for no = 1:No_of_Zeros_CL
    fprintf ('      %f, ',Fz_CL(no,1))
end
fprintf (' \n')
fprintf ('CC 23.4A Closed Loop Poles (%u) @  :-\n',No_of_Poles_CL)
for no = 1:No_of_Poles_CL
    fprintf ('      %f, ',Fp_CL(no,1))
end
fprintf (' \n')
fprintf ('CC 23.4A Closed Loop DC Gain               = %f dB\n',Kdc)
fprintf ('CC 23.4A Closed Loop Gain Margin           = %f dB\n',Gm)
fprintf ('CC 23.4A Closed Loop Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('CC 23.4A Closed Loop Phase Margin          = %f deg\n',Pm)
fprintf ('CC 23.4A Closed Loop Phase Margin Frequency= %f Hz\n',PmFreq)
if CL_Stable==1
    fprintf ('\n        Closed Loop STABLE\n')
else
    fprintf ('\n        Closed Loop UNSTABLE\n')
end

figure(6);
bopt.Title.String = {'CC 23.4A Closed Loop Transfer Function with PI'};
bode(CC_23A4_PI_CL_TF, {2*pi*10, 2*pi*3e5},bopt);

figure(7);
pzmap(CC_23A4_PI_CL_TF);
grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
