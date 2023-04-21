% CLLLC Design, & Closed Loop Compensator Design
% Author: Vinoth
% First created: 08.02.20223
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

    %% CV - Vbulk Feedback Gain Parameters
Vbulk_Sen_Opamp_Rin = (5*560e3) + 100 + 51.1e3;
Vbulk_Sen_Opamp_Rfb = 5.62e3;
Vbulk_Max = Vadc_Ref / (Vbulk_Sen_Opamp_Rfb/Vbulk_Sen_Opamp_Rin);
Adc_Per_Unit_Vbulk = Adc_Max / Vbulk_Max;

    %% CV - Voltage Feedback Filter Parameters
Vbulk_Sen_Filt1_R = 5.62e3;
Vbulk_Sen_Filt1_C = 0.22e-6;
Vbulk_Sen_Filt1_TF = 1/(1+(s*Vbulk_Sen_Filt1_R*Vbulk_Sen_Filt1_C));

Vbulk_Sen_Filt2_R = 1e3;
Vbulk_Sen_Filt2_C = 10e-9;
Vbulk_Sen_Filt2_TF = 1/(1+(s*Vbulk_Sen_Filt2_R*Vbulk_Sen_Filt2_C));

Vbulk_Sen_Filt3_R = 5.62e3;
Vbulk_Sen_Filt3_C = 0.22e-6;
Vbulk_Sen_Filt3_TF = 1/(1+(s*Vbulk_Sen_Filt3_R*Vbulk_Sen_Filt3_C));
    
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
load('CV_Rev_470V_Tune_Data.mat');         

    %% Identify/Estimate Continuous Time Plant Transfer function from the data
CV_Rev_470V_Plant_EstiData = tfest(CV_Rev_470V_OL_Plant_Bode,2)

    %% Calculate / Estimate Other Parameters
CV_Rev_470V_OL_Plant_TF = tf(CV_Rev_470V_Plant_EstiData.Numerator,CV_Rev_470V_Plant_EstiData.Denominator);

Zeros = abs(zero(CV_Rev_470V_OL_Plant_TF));
No_of_Zeros = size(Zeros,1);
for no = 1:No_of_Zeros

    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(CV_Rev_470V_OL_Plant_TF));
No_of_Poles = size(Poles,1);
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(CV_Rev_470V_OL_Plant_TF));

Pl_TF_Den = CV_Rev_470V_Plant_EstiData.Denominator;
Qc_Plant = 1 / ((Pl_TF_Den(1,2)/Pl_TF_Den(1,3))*(sqrt(Pl_TF_Den(1,3))));

Plant_Margins = allmargin(CV_Rev_470V_OL_Plant_TF);
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

figure(1);
bopt.Title.String = {'CV Rev 470V Open Loop Plant - Estimated Bode'};
bode(CV_Rev_470V_Plant_EstiData, {2*pi*10, 2*pi*3e5},bopt);

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

CV_Rev_470V_OL_Plant_TF_WFilt = CV_Rev_470V_OL_Plant_TF * Adc_Per_Unit_Vbulk * Vbulk_Sen_Filt1_TF * Vbulk_Sen_Filt2_TF * Vbulk_Sen_Filt3_TF
    
    %% Calculate / Estimate Other Parameters
Zeros = abs(zero(CV_Rev_470V_OL_Plant_TF_WFilt));
No_of_Zeros = size(Zeros,1);
Fz = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros
    Fz(no,1) = Zeros(no,1)/(2*pi);
end

Poles = abs(pole(CV_Rev_470V_OL_Plant_TF_WFilt));
No_of_Poles = size(Poles,1);
Fp = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles
    Fp(no,1) = Poles(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(CV_Rev_470V_OL_Plant_TF_WFilt));
sisotool(CV_Rev_470V_OL_Plant_TF_WFilt)

Plant_Margins = allmargin(CV_Rev_470V_OL_Plant_TF_WFilt);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);
    
    %% Display Other estimated data's
fprintf ('CV Rev. 470V Plant(With Filter) Zeros (%u) @  :-\n',No_of_Zeros)
for no = 1:No_of_Zeros
    fprintf ('      %f, ',Fz(no,1))
end
fprintf (' \n')
fprintf ('CV Rev. 470V Plant(With Filter) Poles (%u) @  :-\n',No_of_Poles)
for no = 1:No_of_Poles
    fprintf ('      %f, ',Fp(no,1))
end
fprintf (' \n')

fprintf ('CV Rev. 470V Plant(With Filter) DC Gain               = %f dB\n',Kdc)
fprintf ('CV Rev. 470V Plant(With Filter) Gain Margin           = %f dB\n',Gm)
fprintf ('CV Rev. 470V Plant(With Filter) Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('CV Rev. 470V Plant(With Filter) Phase Margin          = %f deg\n',Pm)
fprintf ('CV Rev. 470V Plant(With Filter) Phase Margin Frequency= %f Hz\n',PmFreq)

figure(2);
bopt.Title.String = {'CV Rev. 470V Open Loop Uncompensated Plant with Sense Filters'};
bode(CV_Rev_470V_OL_Plant_TF_WFilt, {2*pi*10, 2*pi*3e5},bopt);

figure(3);
pzmap(CV_Rev_470V_OL_Plant_TF_WFilt);
grid on;

% % % % % % % % % % 5e. 1P1Z Compensator Design Parameters % % % % % % % %
% 
% 1P1Z Equation => Gc(s) = (KL*(1+((2*Pi*fZl)/s)))
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
fprintf ('\n\n  *** Step 5: 1P1Z Compensator Design Data ***\n')
fprintf ('         1P1Z Compensator Equation :- \n')
fprintf ('              Gc(s) = (KL*(1+((2*Pi*fZl)/s))) \n')

GM_Req_PI = 50;
KL = 1/(10^(GM_Req_PI/20));
FzL = 5000;

fprintf ('1P1Z Compensator Input Parameters:\n')
fprintf ('Required Gain Margin -> Gm_Req = %f\n', GM_Req_PI)
fprintf ('Frequency of Compensator Zero -> FzL = %f\n', FzL)

Compensator_1P1Z_TF = KL*(1+((2*pi*FzL)/s));

Compensator_1P1Z_TF_in_Zdomain = c2d(Compensator_1P1Z_TF,Control_Period,'tustin')

Num = Compensator_1P1Z_TF_in_Zdomain.Numerator;
Den = Compensator_1P1Z_TF_in_Zdomain.Denominator;

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

CV_Rev_470V_1P1Z_CL_TF = Compensator_1P1Z_TF * CV_Rev_470V_OL_Plant_TF_WFilt

    %% Calculate / Estimate Other Parameters
Zeros_CL = abs(zero(CV_Rev_470V_1P1Z_CL_TF));
No_of_Zeros_CL = size(Zeros_CL,1);
Fz_CL = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Zeros_CL
    Fz_CL(no,1) = Zeros_CL(no,1)/(2*pi);
end

Poles_CL = abs(pole(CV_Rev_470V_1P1Z_CL_TF));
No_of_Poles_CL = size(Poles_CL,1);
Fp_CL = [0.0 0.0 0.0 0.0 0.0 0.0];
for no = 1:No_of_Poles_CL
    Fp_CL(no,1) = Poles_CL(no,1)/(2*pi);
end

Kdc = 20 * log10(dcgain(CV_Rev_470V_1P1Z_CL_TF));
sisotool(CV_Rev_470V_1P1Z_CL_TF)

Plant_Margins = allmargin(CV_Rev_470V_1P1Z_CL_TF);
Gm = 20 * log10(Plant_Margins.GainMargin);
GmFreq = Plant_Margins.GMFrequency/(2*pi);
Pm = Plant_Margins.PhaseMargin;
PmFreq=Plant_Margins.PMFrequency/(2*pi);

CL_Stable = isstable(CV_Rev_470V_1P1Z_CL_TF);
    
    %% Display Other estimated data's
fprintf ('CV Rev. 470V Closed Loop Zeros (%u) @  :-\n',No_of_Zeros_CL)
for no = 1:No_of_Zeros_CL
    fprintf ('      %f, ',Fz_CL(no,1))
end
fprintf (' \n')
fprintf ('CV Rev. 470V Closed Loop Poles (%u) @  :-\n',No_of_Poles_CL)
for no = 1:No_of_Poles_CL
    fprintf ('      %f, ',Fp_CL(no,1))
end
fprintf (' \n')
fprintf ('CV Rev. 470V Closed Loop DC Gain               = %f dB\n',Kdc)
fprintf ('CV Rev. 470V Closed Loop Gain Margin           = %f dB\n',Gm)
fprintf ('CV Rev. 470V Closed Loop Gain Margin Frequency = %f Hz\n',GmFreq)
fprintf ('CV Rev. 470V Closed Loop Phase Margin          = %f deg\n',Pm)
fprintf ('CV Rev. 470V Closed Loop Phase Margin Frequency= %f Hz\n',PmFreq)
if CL_Stable==1
    fprintf ('\n        Closed Loop STABLE\n')
else
    fprintf ('\n        Closed Loop UNSTABLE\n')
end

figure(6);
bopt.Title.String = {'CV Rev. 470V Closed Loop Transfer Function with 1P1Z'};
bode(CV_Rev_470V_1P1Z_CL_TF, {2*pi*10, 2*pi*3e5},bopt);

figure(7);
pzmap(CV_Rev_470V_1P1Z_CL_TF);
grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
