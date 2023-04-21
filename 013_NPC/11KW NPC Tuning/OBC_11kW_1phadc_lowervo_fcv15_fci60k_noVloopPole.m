% NPC PFC Control Loop Design
% Author: Dr. Lim Shu Fan
% First created: 25.05.2022
% Last modified: 02.08.2022
% Revision: 0.1
% Descriptions:
% 0.1: First design attempt with circuit dimensioning

clear;
%pkg load control;

%%%%%%%%%%%%%%% System parameters %%%%%%%%%%%%%%%%%%
Vph_min=40;
Vph_nom=50;
Vph_max=60;
fline_min=45;
fline_max=65;
effPFC=0.97;
cos_ph=0.99;
Po_rated=900; %Rated output power
VoPFC=200; %Vbulk target voltage
puload=1.0; %ratio of load to full load
Po_PFC=Po_rated*puload;
Io_PFC=Po_PFC/VoPFC; %output current
Pin_PFC=Po_PFC/effPFC; %input power

Iph_265VAC=Pin_PFC/(1*Vph_max*cos_ph); %at high line
if Iph_265VAC > 32
    Iph_265VAC = 32;
end
Pin_PFC_265VAC = Iph_265VAC*Vph_max*cos_ph;

Iph_85VAC=Pin_PFC/(1*Vph_min*cos_ph); %at low line
if Iph_85VAC > 16
    Iph_85VAC = 16;
end
Pin_PFC_85VAC = Iph_85VAC*Vph_min*cos_ph;

Iph_208VAC=Pin_PFC/(1*Vph_nom*cos_ph); %at nom line
if Iph_208VAC > 32
    Iph_208VAC = 32;
end
Pin_PFC_208VAC = Iph_208VAC*Vph_nom*cos_ph;

Fsw=65e3; %switching frequency
Tsw=1/Fsw*1; % switching period

% MCU parameters
VADC = 3.3; %ADC reference voltage, note different for different design
ADC_bits = 12; %12 bit ADC
ADC_FS = 2^ADC_bits-1; %ADC full scale 
ADC_LSB = VADC/ADC_FS;
ADC_gain = ADC_FS/VADC;
Fclk=200e6; %PWM clock frequency
Tclk=1/Fclk; %PWM clock period
Tsw_count=floor(Fclk/Fsw/2); %switching period as factor of PWM clock period

% Inductor current sensing factor
LPFC=182e-6;  %182uH at full load, 230uH at no load
Rs=0.0005; %current sensing resistor, bipolar current sensed
g_AMC1301=8.2; 
R1_op=2.21e3; 
%R2_op=22.1e3; %plus offset of 1.65V old
R2_op=11e3; %plus offset of 1.65V new
KiL=R2_op/R1_op;
iL_Rfil1=R2_op;
iL_Cfil1=470e-12; 
iL_f_fil1=1/(2*pi*iL_Rfil1*iL_Cfil1); %30.8kHz
iL_Rfil2=1e3;
iL_Cfil2=0.01e-6; 
iL_f_fil2=1/(2*pi*iL_Rfil2*iL_Cfil2); %15.9kHz
iL_Rfil3=1e3;
iL_Cfil3=47e-9; 
iL_f_fil3=1/(2*pi*iL_Rfil3*iL_Cfil3); %3.3kHz
KiL_tot=KiL*Rs*g_AMC1301; 
KiL_tot_IN=KiL_tot*ADC_gain; %gain of iL sensing at ADC, bit/A
KiL_tot_IN_RES=1/KiL_tot_IN; %resolution of iL sensing at ADC, A/bit
ILLMax=VADC/2/KiL_tot; %max current measurable by ADC, offset by 1.65V

% Input voltage sensing factor
Rt_AC=390e3*3+240e3+390e3+34.8e3; %VAC sense resistance top
Rb_AC=3.3e3; %VAC sense resistance bottom
VAC_Cfil1=2200e-12;
VAC_f_fil1=1/(2*pi*Rb_AC*VAC_Cfil1); %21.9kHz
VAC_Rfil2=1e3;
VAC_Cfil2=47e-9;
VAC_f_fil2=1/(2*pi*VAC_Rfil2*VAC_Cfil2); %3.3kHz
KVAC=Rb_AC/(Rb_AC+Rt_AC); %VAC sense ratio 1/163
KVAC_IN=KVAC*ADC_gain; %gain of VAC sensing at ADC, bit/V
KVAC_IN_RES=1/KVAC_IN; %resolution of VAC sensing at ADC, V/bit
VphMax=VADC/2/KVAC; %max voltage measureable by ADC, offset by 1.65V

% Bulk voltage sensing factor
%Co_PFC=1/(1/(4*560e-6)+1/(4*560e-6))+ 4*22e-6; %old
Co_PFC=1/(1/(4*560e-6)+1/(4*560e-6))+ 10e-6; %new
Rt_VoPFC=300e3*5+51.1e3; %Vbulk sense resistance top
Rb_VoPFC=5.62e3; %Vbulk sense resistance bottom
VoPFC_Cfil1=0.22e-6;
VoPFC_f_fil1=1/(2*pi*Rb_VoPFC*VoPFC_Cfil1); %128.72Hz!!
VoPFC_Rfil2=1e3;
VoPFC_Cfil2=0.01e-6;
VoPFC_f_fil2=1/(2*pi*VoPFC_Rfil2*VoPFC_Cfil2); %15.9kHz
KVoPFC=Rb_VoPFC/(Rb_VoPFC+Rt_VoPFC); %Vbulk sense ratio
KVoPFC_IN=KVoPFC*ADC_gain; %VoPFC sensing gain at ADC
KVoPFC_IN_RES=1/KVoPFC_IN; %VoPFC sensing resolution at ADC
VoPFC_Max=VADC/KVoPFC;

% Vmid Bulk voltage sensing factor 
VoPFCmid_Rfil2=1e3;
VoPFCmid_Cfil2=0.01e-6;
VoPFCmid_f_fil2=1/(2*pi*VoPFCmid_Rfil2*VoPFCmid_Cfil2); %15.9kHz
VoPFCmid_Rfil3=1e3;
VoPFCmid_Cfil3=0.01e-6;
VoPFCmid_f_fil3=1/(2*pi*VoPFCmid_Rfil3*VoPFCmid_Cfil3); %15.9kHz
G_noninvOpamp=1+1e3/1.27e3;
KVoPFCmid=(Rb_VoPFC/(Rb_VoPFC+Rt_VoPFC))*G_noninvOpamp; %Vbulk sense ratio
KVoPFCmid_IN=KVoPFCmid*ADC_gain; %VoPFC sensing gain at ADC
KVoPFCmid_IN_RES=1/KVoPFCmid_IN; %VoPFC sensing resolution at ADC
VoPFCmid_Max=VADC/KVoPFCmid;

% Output of vloop and iloop
vloop_out = Iph_208VAC*sqrt(2)*KiL_tot*ADC_gain; %output voltage of voltage loop at puload (proportional to peak of input current) 
Vm = 800/800*Tsw_count;
%Vm=800; %470;

Tsi=Tsw;
s=tf('s');
z=tf('z',Tsi);

% Current loop (1) @Tsw
% uncompensated current loop gain
GCCM=VoPFC/2/(s*LPFC); %CCM PFC plant  VoPFC/(s*LPFC)
Tuolgi=(KiL_tot*ADC_gain*VoPFC/2)/(LPFC*Vm);
%Tuolgi=(VoPFC/2)/(LPFC*Vm); %if use real values

Tuolfi=KiL_tot*ADC_gain*GCCM/Vm*1;
%Tuolfi=GCCM/Vm;

Gopfil1=1/(1+s*iL_Rfil1*iL_Cfil1);
Gopfil2=1/(1+s*iL_Rfil2*iL_Cfil2);
Gopfil3=1/(1+s*iL_Rfil3*iL_Cfil3);
%Tuolf_RCfil_i=GCCM*Gopfil1*Gopfil2*Gopfil3/Vm;
%Tuolf_RCfil_i=KiL_tot*ADC_gain*GCCM*Gopfil1*Gopfil2*Gopfil3/Vm;
Tuolf_RCfil_i=KiL_tot*ADC_gain*GCCM*Gopfil3/Vm*1;

figure(1);
bode(Tuolfi,Tuolf_RCfil_i, {2*pi*1, 2*pi*1e6});

% compensated current loop gain
% Gci=Kpi(1+(2*pi*fzi)/s)
fci=1.0e3; %target controller bandwidth 3.05e3 
PMi=52/180*pi; %target phase margin 55/180*pi

%Only PI
%Kpi=1/(Tuolgi/(2*pi*fci)); %Required gain at fci
delta_PMi_ZOH=2*pi*fci*Tsw/2; %Phase drop due to ZOH in radians
%%PMi+delta_PMI_ZOH=180+angle(Ti(jwc))=180-90-90+tan^(-1)(fc/fzi)
%fzi=fci/tan(PMi+delta_PMi_ZOH); %Required zero location
%Gci=Kpi*(1+(2*pi*fzi)/s); %PI controller in s domain
%Tci=Gci*Tuolfi; %compensated current loop gain in s domain

%GCCMd=c2d(GCCM,Tsi,'zoh'); %CCM PFC plan in z domain via ZOH
%Gcid=c2d(Gci,Tsi,'zoh');
%Tuolfid=c2d(Tuolfi,Tsi,'zoh');
%Tcid=Gcid*Tuolfid; %Compensated current loop gain in z domain

% PI + strong passive RC
% |G(jw)|=sqrt((Re(G(jw))^2+(Im(G(jw))^2), RC -> |G(jw)|=1/(sqrt(1+(w/w0)^2))
% ang(G(jw))=tan^(-1)(Im(G(jw))/Re(G(jw))), RC -> ang(G(jw))=-tan^(-1)(w/w0)
Kp_RC_i=1/(Tuolgi/(2*pi*fci)*1/(sqrt(1+(fci/iL_f_fil1)^2))*1/(sqrt(1+(fci/iL_f_fil2)^2))*1/(sqrt(1+(fci/iL_f_fil3)^2))); %Required gain at fci with passive RC
fz_RC_i=fci/tan(PMi+delta_PMi_ZOH+atan(fci/iL_f_fil1)+atan(fci/iL_f_fil2)+atan(fci/iL_f_fil3)); %Required zero location with passive RC ZOH
Gc_RC_i=Kp_RC_i*(1+(2*pi*fz_RC_i)/s); %PI controller in s domain with passive RC ZOH

fci=6.0e3; %target controller bandwidth 6e3 
PMi=52/180*pi; %target phase margin 52/180*pi
%Kp_RC_i=1/(Tuolgi/(2*pi*fci)*3/(sqrt(1+(fci/iL_f_fil1)^2))*1/(sqrt(1+(fci/iL_f_fil2)^2))*1/(sqrt(1+(fci/iL_f_fil3)^2))); %Required gain at fci with passive RC
Kp_RC_i=1/(Tuolgi/(2*pi*fci)*3/(sqrt(1+(fci/iL_f_fil3)^2))); %Required gain at fci with passive RC
fz1=fci*sqrt((1-sin(PMi))/(1+sin(PMi)));
fp1=fci*sqrt((1+sin(PMi))/(1-sin(PMi)));
fz_RC_i=1/6*fci; %1/10*fz1;
Gc_RC_i=Kp_RC_i*(1+(2*pi*fz_RC_i)/s)*(1+s/(2*pi*fz1))/(1+s/(2*pi*fp1));

Tc_RC_i=Gc_RC_i*Tuolf_RCfil_i;

%Gc_RC_id=c2d(Gc_RC_i,Tsi,'zoh');
Gc_RC_id=c2d(Gc_RC_i,Tsi,'tustin');
%Tuolf_RCfil_id=c2d(Tuolf_RCfil_i,Tsi,'zoh'); %uncompensated open loop function with passive RC in Z domain
Tuolf_RCfil_id=c2d(Tuolf_RCfil_i,Tsi,'tustin'); %uncompensated open loop function with passive RC in Z domain
Tc_RC_id=Gc_RC_id*Tuolf_RCfil_id;

figure(2);
%bode(Tc_RC_i, Tc_RC_id,{2*pi*1,2*pi*1e5});
bode(Tc_RC_i,Tc_RC_id,{2*pi*1,2*pi*1e5});

Tsv=Tsw*1; 
Fsv=1/Tsv;
z=tf('z',Tsv);

%Uncompensated voltage loop gain
GVo_PFCplant=Pin_PFC/(s*Co_PFC*vloop_out*VoPFC/2); 
Gopfilv1=1/(1+s*Rb_VoPFC*VoPFC_Cfil1);
Tuolgv=(KVoPFC*ADC_gain*Pin_PFC)/(Co_PFC*vloop_out*VoPFC/2);
Tuolfv=KVoPFC*ADC_gain*Gopfilv1*GVo_PFCplant;

%Tuolgv=(Pin_PFC)/(Co_PFC*vloop_out*VoPFC/2); 
%Tuolfv=GVo_PFCplant*Gopfilv1;
%Tuolfv=GVo_PFCplant;

figure(3);
bode(Tuolfv,{2*pi*0.1, 2*pi*1e4});

%Compensated voltage loop gain
% Vo single pole filter
fVo_PFCLPF=30; %pole location of LPF to get ~0.5 attenuation factor of >2fline_min ripple 210, 45
%GVo_PFCLPF=1/(1+s/(2*pi*fVo_PFCLPF)); %1 stage LPF in s domain
%GVo_PFCLPFd=c2d(GVo_PFCLPF, Tsv, 'zoh');

%Gcv=Kpv(1+(2*pi*fzv)/s);
fcv=15; %30
PMv=50/180*pi; %60/180*pi
delta_PMv_ZOH=2*pi*fcv*Tsv/2;
%Kpv=1/(Tuolgv/(2*pi*fcv)*1/(sqrt(1+(fcv/VoPFC_f_fil1)^2)));
Kpv=1/(Tuolgv/(2*pi*fcv)*1/(sqrt(1+(fcv/VoPFC_f_fil1)^2))*1/(sqrt(1+(fcv/fVo_PFCLPF)^2)));
%PMv+delta_PMv_ZOH=180+angle(Tv(jwc))=180-90-90+tan^(-1)(fcv/fzv)-tan^(-1)(fcv/fVo_PFCLPF)
%fzv=fcv/tan(PMv+delta_PMv_ZOH+atan(fcv/VoPFC_f_fil1));
fzv=fcv/tan(PMv+delta_PMv_ZOH+atan(fcv/VoPFC_f_fil1)+atan(fcv/fVo_PFCLPF));

%same as k in PSIM
%T=1/(2*pi*fzv) in PSIM

%Gcv=Kpv*(1+(2*pi*fzv)/s);
Gcv=Kpv*(1+(2*pi*fzv)/s); %*GVo_PFCLPF;

Gcvd=c2d(Gcv,Tsv,'zoh');
Tuolfvd=c2d(Tuolfv,Tsv,'zoh');
Tcv=Gcv*Tuolfv;
Tcvd=Gcvd*Tuolfvd;

%figure(6);
%bode(Gcv,Gcvd, {2*pi*0.01,2*pi*1e3});

%use [NUM,DEN]=tfdata(Gcvd) to get the coefficients.
figure(4);
bode(Tcv, Tcvd,{2*pi*0.01,2*pi*1e3});

% Input voltage feedforward LPF (3) %Tsv
% Vg feedforward contributes 0.5% of allowable 1% THD 
% Ratio of 2nd harmonic in rectified input voltage to DC is (4Vpk/3pi)/(2Vpk/pi)
% Vdc=2Vpk/pi=2*sqrt(2)/pi*Vrms
% Vg filter single pole
Vg_att_1p=0.005/((4/3)/2); %required attenuation by 1 stage LPF
f1p=4.5;%Vg_att_1p*2*fline_min; %min pole location of 1 stage LPF
Gf1p=1/(1+s/(2*pi*f1p)); %1 stage LPF in s domain
Gf1pd=c2d(Gf1p,Tsv,'zoh');

%Vg cascaded 2 stage filter
Vg_att_2p=sqrt(Vg_att_1p);
f2p=Vg_att_2p*2*fline_min; %min pole location of 2 stage LPF
Gf2p_1=1/(1+s/(2*pi*f2p));
Gf2p_2=1/(1+s/(2*pi*f2p))*1/(1+s/(2*pi*f2p));

Gf2p_1d=c2d(Gf2p_1,Tsv,'zoh');
Gf2p_2d=Gf2p_1d*Gf2p_1d;
Gf2p_2d1=c2d(Gf2p_2,Tsv,'zoh');

figure(5);
bode(Gf2p_1d, 'b--', Gf2p_2d, 'r', Gf2p_2d1, 'k', {2*pi*1, 2*pi*1e3});

% Check zero, should be postive value: fzv
% Current loop: Gc_RC_id, (a0+a1..)/(b1+b2..)
% Voltage loop: Gcvd, [NUM,DEN]=tfdata(Gcvd), (a0+a1..)/(b1+b2..)