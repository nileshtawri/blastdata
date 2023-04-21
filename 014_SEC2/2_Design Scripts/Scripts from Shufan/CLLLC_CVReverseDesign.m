% CLLLC Design, regulation and protection dimensioning
% Author: Dr. Lim Shu Fan
% First created: 27.04.2022
% Last modified: 13.05.2022
% Revision: 0.1
% Descriptions:
% 0.1: Design closed loop CV control for Reverse mode

clear;
% pkg load control;

%%%%%%%%%%%%%%%%%%% 2. PWM setting %%%%%%%%%%%%%%%%%%%%%
VADC = 3.3; %ADC reference voltage, note different for different design
ADC_bits = 12; %12 bit ADC
ADC_FS = 2^ADC_bits-1; %ADC full scale 
ADC_gain = ADC_FS/VADC;
Fclk=30e6; %PWM clock frequency
Tclk=1/Fclk; %PWM clock period

Fsi=20000; 
Tsi=1/Fsi;
s=tf('s');
z=tf('z',Tsi);

%%%%%%%%%%%%%%%%%%% 3. Current sensing and protection %%%%%%%%%%%%%%%%%%%%%
%Output current
K_IOUT=20e-3; %ACS733KLATR-65AB-T, sensitivity mV/A bidirectional
K_IOUT_IN=K_IOUT*ADC_gain; %gain of Io sensing at ADC, bit/A
K_IOUT_IN_RES=1/K_IOUT_IN; %resolution of Io sensing at ADC, A/bit
V_IoOFFSET = VADC/2;
IoMax=(VADC-V_IoOFFSET)/K_IOUT;

%Input current
K_IIN=20e-3; %ACS733KLATR-65AB-T, sensitivity mV/A bidirectional
K_IIN_IN=K_IIN*ADC_gain; %gain of Iin sensing at ADC, bit/A
K_IIN_IN_RES=1/K_IIN_IN; %resolution of Iin sensing at ADC, A/bit
V_IinOFFSET = VADC/2;
IinMax=(VADC-V_IinOFFSET)/K_IIN;

%%%%%%%%%%%%%%%%%%% 4. Voltage sensing and protection %%%%%%%%%%%%%%%%%%%%%
%Output voltage sensing HVDC, Vo_AD before filter
Rt_Vo=4*1e6+71.5e3;
Rb_Vo=23.2e3;
KVo=Rb_Vo/(Rt_Vo+Rb_Vo);
KVo_IN=KVo*ADC_gain; %gain of Vo sensing at ADC, bit/V
KVo_IN_RES=1/KVo_IN; %resolution of Vo sensing at ADC, V/bit
VoMax=VADC/KVo;

Rfil_Vo1=Rb_Vo;
Cfil_Vo1=470e-12;
f_fil_Vo1=1/(2*pi*Rfil_Vo1*Cfil_Vo1);
G_fil_Vo1=1/(sqrt(1+(Fsi/f_fil_Vo1)^2));

Rfil_Vo2=1000;
Cfil_Vo2=0.01e-6;
f_fil_Vo2=1/(2*pi*Rfil_Vo2*Cfil_Vo2);
G_fil_Vo2=1/(sqrt(1+(Fsi/f_fil_Vo2)^2));

%PFC output voltage sensing, PFC_OUT, VPFC_OUT_AD
Rt_Vor=5*300e3+51.1e3;
Rb_Vor=5.62e3;
KVor=Rb_Vor/(Rt_Vor+Rb_Vor);
KVor_IN=KVor*ADC_gain; %gain of Vor sensing at ADC, bit/V
KVor_IN_RES=1/KVor_IN; %resolution of Vor sensing at ADC, V/bit
VorMax=VADC/KVor;

Rfil_Vor1=Rb_Vor;
Cfil_Vor1=0.22e-6;
f_fil_Vor1=1/(2*pi*Rfil_Vor1*Cfil_Vor1);
G_fil_Vor1=1/(sqrt(1+(Fsi/f_fil_Vor1)^2));

Rfil_Vor2=1000;
Cfil_Vor2=0.01e-6;
f_fil_Vor2=1/(2*pi*Rfil_Vor2*Cfil_Vor2);
G_fil_Vor2=1/(sqrt(1+(Fsi/f_fil_Vor2)^2));

Rfil_Vor3=1000;
Cfil_Vor3=0.01e-6;
f_fil_Vor3=1/(2*pi*Rfil_Vor3*Cfil_Vor3);
G_fil_Vor3=1/(sqrt(1+(Fsi/f_fil_Vor3)^2));

%%%%%%%%%%%%%%%%%%% 12. Control loop design %%%%%%%%%%%%%%%%%%%%%
%Uncompensated voltage loop gain reverse CV
%with diode rectifiers
%Vin=800, Vo=470, Tc=365(82kHz), G_DC_LLCplant=-16.0418, f0_LLCplant = 2000, Q_db_LLCplant = -4

G_DC_LLCplant=12.7054; %db
DCgain_LLCplant=(10^(G_DC_LLCplant/20));
fpole1_LLCplant=200;
fpole2_LLCplant=4000;
fzero1_LLCplant=15000;
GVo_LLCplant=DCgain_LLCplant*(1-s/(2*pi*fzero1_LLCplant))/(1+s/(2*pi*fpole1_LLCplant))/(1+s/(2*pi*fpole2_LLCplant)); 
%GVo_LLCplant=DCgain_LLCplant/(1+s/(2*pi*fpole1_LLCplant))/(1+s/(2*pi*fpole2_LLCplant)); 
%Q_db_LLCplant = -4; %found at f0 and finetune to get db and deg at various freq
%Q_LLCplant=(10^(Q_db_LLCplant/20));
%f0_LLCplant = 2000; %found at 90deg
%w0_LLCplant = 2*pi*f0_LLCplant;
%fzero1_LLCplant=18000;
%GVo_LLCplant=DCgain_LLCplant*(1-s/(2*pi*fzero1_LLCplant))/(1+s/(Q_LLCplant*w0_LLCplant)+(s/w0_LLCplant)^2);

GVo_LLCplantd=c2d(GVo_LLCplant,Tsi,'zoh');
figure(1);
bode(GVo_LLCplant, {2*pi*10, 2*pi*1e5});

Tuolfv=GVo_LLCplant*ADC_FS/VorMax*1/(1+s*Rfil_Vor1*Cfil_Vor1)*1/(1+s*Rfil_Vor2*Cfil_Vor2)*1/(1+s*Rfil_Vor3*Cfil_Vor3); %uncompensated open loop gain
Tuolfvd=c2d(Tuolfv,Tsi,'zoh');
figure(2);
bode(Tuolfv, {2*pi*10, 2*pi*1e6});

%Uncompensated voltage loop gain reverse CV
%with diode rectifiers
%Vin=800, Vo=250, Tc=517(58kHz), G_DC_LLCplant=11.6841, fpole1_LLCplant = 35Hz, fpole2_LLCplant=2.4kHz, fzero1_LLCplant=12kHz

G_DC_LLCplant1=11.6841; %db
DCgain_LLCplant1=(10^(G_DC_LLCplant1/20));
fpole1_LLCplant1=35;
fpole2_LLCplant1=2400;
fzero1_LLCplant1=12000;
GVo_LLCplant1=DCgain_LLCplant1*(1-s/(2*pi*fzero1_LLCplant1))/(1+s/(2*pi*fpole1_LLCplant1))/(1+s/(2*pi*fpole2_LLCplant1)); 
%GVo_LLCplant=DCgain_LLCplant/(1+s/(2*pi*fpole1_LLCplant))/(1+s/(2*pi*fpole2_LLCplant)); 
%Q_db_LLCplant = -4; %found at f0 and finetune to get db and deg at various freq
%Q_LLCplant=(10^(Q_db_LLCplant/20));
%f0_LLCplant = 2000; %found at 90deg
%w0_LLCplant = 2*pi*f0_LLCplant;
%fzero1_LLCplant=18000;
%GVo_LLCplant=DCgain_LLCplant*(1-s/(2*pi*fzero1_LLCplant))/(1+s/(Q_LLCplant*w0_LLCplant)+(s/w0_LLCplant)^2);

GVo_LLCplant1d=c2d(GVo_LLCplant1,Tsi,'zoh');
figure(3);
bode(GVo_LLCplant1, {2*pi*10, 2*pi*1e5});

Tuolfv1=GVo_LLCplant1*ADC_FS/VorMax*1/(1+s*Rfil_Vor1*Cfil_Vor1)*1/(1+s*Rfil_Vor2*Cfil_Vor2)*1/(1+s*Rfil_Vor3*Cfil_Vor3); %uncompensated open loop gain
Tuolfv1d=c2d(Tuolfv1,Tsi,'zoh');
figure(4);
bode(Tuolfv1, {2*pi*10, 2*pi*1e6});

% PIT1 KL*(1+(2*pi*fzL)/s)*1/(1+s/(2*pi*fpL)) 
G_fc=15.38; %db, shift to get desired fc
KL=1/(10^(G_fc/20));
fzL=20; % if phase is high at fc, fzL can be placed at high freq
fpL=8000; % to give larger attenuation after fc for higher gain margin

%Gc1=KL*(1+(2*pi*fzL)/s)/(1+s/(2*pi*fpL));
Gc1=KL*(1+(2*pi*fzL)/s);
%Gc1d=c2d(Gc1,Tsi,'zoh');
Gc1d=c2d(Gc1,Tsi,'tustin');

figure(5);
bode(Gc1, {2*pi*10,2*pi*1e6});
%bode(Gc1, Gc1d, {2*pi*10,2*pi*1e5});

%% 2P2Z Kc*(s^2/wz^2 + s/(Qc*wz) +1) / s(s/wp +1)
% G_fc3 = -60, fz3=2500, Qc=0.63, fp3=15000
% G_fc3 = -60, fz3=2200, Qc=0.6, fp3=15000
G_fc3=-15; %db shift curve upwards to get desired fc (if oscillatory response, reduce gain)
KC=1/(10^(G_fc3/20));
fz3=35;   %place below (greater) or equal to dominant resonant pole
wz0=2*pi*fz3;
Qc=0.63;     %place below (lower) or same as dominant pole pair quality factor of plant  
fp3=15000;  %place at ESR zero or at half fsw or to get desired GM
Gc3=KC*(1+s/(Qc*wz0)+(s/wz0)^2)/s/(1+s/(2*pi*fp3));
%Gc3=KC*(1+s/(2*pi*fz3))*(1+s/(2*pi*fz3))/s/(1+s/(2*pi*fp3));
%Gc3d=c2d(Gc3,Tsi,'zoh');
Gc3d=c2d(Gc3,Tsi,'tustin');
figure(6);
bode(Gc3, {2*pi*10,2*pi*1e6});


%Change Gc1 (PI) or Gc3 (2P2Z)
Tcv3=Gc1*Tuolfv; %470V 
Tcv3d=Gc1d*Tuolfvd;
figure(7);
bode(Tcv3, {2*pi*10,2*pi*1e6});

Tcv31=Gc1*Tuolfv1; %250V
Tcv31d=Gc1d*Tuolfv1d;
figure(8);
bode(Tcv31, {2*pi*10,2*pi*1e6});