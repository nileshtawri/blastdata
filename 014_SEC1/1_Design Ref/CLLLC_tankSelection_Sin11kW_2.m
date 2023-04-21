% CLLLC Design, regulation and protection dimensioning
% Author: Dr. Lim Shu Fan
% First created: 01.04.2022
% Last modified: 27.04.2022
% Revision: 0.2
% Descriptions:
% 0.1: First design attempt to match with implementation 

clear;
%%%%%%%%%%%%%%%% 1. Define System specification %%%%%%%%%%%%%%%%%%%%
effCLLLC=0.97;
Po_rated=11000; %Rated output power
puload=1.0; %ratio of load to full load
Po_LLC=Po_rated*puload;
max_Io=37; % at 250V up to 595V
Vo_Fmin = 250; %output voltage 
Vo_Fmax = 470; 
Io_Fmax = Po_LLC/Vo_Fmin; %output current
VinLLC_Fmax = 800; %max input voltage of LLC 
VinLLC_Fmin = 800; %min input voltage of LLC
RL_250V=Vo_Fmin/max_Io;
RL_298V=298/max_Io;
RL_470V=Vo_Fmax^2/Po_rated;

fr = 153000; %selected resonant frequency

%desired transformer gain Npri/Nsec
n_CLLC=21/9;
%magnetizing inductance
Lm=130*10^-6;
Ln=4.444;
%Lrp=Lm/Ln; %Lrp
Lrp=80*10^-6;
%capacitance selection
%Crp=1/(Lrp*3.14*3.14*4*fr*fr);
Crp=135*10^-9; %Crp
%Lrs=3*Lrp/(n_CLLC*n_CLLC); %m1=3
Lrs=38*10^-6;
%Crs=1/(Lrs*3.14*3.14*4*fr*fr);
Crs=220*10^-9;
Crs_dash=Crs/(n_CLLC*n_CLLC); %Crs'
Lrs_dash = Lrs* (n_CLLC*n_CLLC); %Lrs'

% CLLLC forward gain curve (verify)

Mg_Fmin=n_CLLC*Vo_Fmin/VinLLC_Fmax; % minimum voltage gain at VinLLC_max
Mg_Fmax=n_CLLC*Vo_Fmax/VinLLC_Fmin; % maximum voltage gain at VinLLC_min
Mg_Fmid=n_CLLC*298/VinLLC_Fmin;
%Mg_Fmin=Vo_Fmin/VinLLC_Fmax; % minimum voltage gain at VinLLC_max
%Mg_Fmax=Vo_Fmax/VinLLC_Fmin; % maximum voltage gain at VinLLC_min

fsw=[1:10:300000];
RL=[6.76, 8.07, 20.08, 71.43];
%RL=[20:5:80];

no_fsw=length(fsw);
no_RL=length(RL);

figure(1);
for p=1:1:no_RL
    for j=1:1:no_fsw
      %Zm
      Zm=complex(0, 2*pi*fsw(j)*Lm);
      %Zrp
      Zrp=(1/complex(0,2*pi*fsw(j)*Crp))+complex(0, 2*pi*fsw(j)*Lrp);
      %Zrs
      %Zrs=(1/complex(0, 2*pi*fsw(j)*Crs))+ complex(0, 2*pi*fsw(j)*Lrs);
      Zrs_dash=(1/complex(0,2*pi*fsw(j)*Crs_dash))+ complex(0, 2*pi*fsw(j)*Lrs_dash); %Zrs'
      RL_dash=RL(p)*n_CLLC*n_CLLC *(8/(pi*pi));
      Zx=(Zm*(Zrs_dash+RL_dash))/(Zm+Zrs_dash+RL_dash); %Zm||(Zrs'+RL')
      %Mg(j)=abs((1/n_CLLC)*(Zx*RL_dash / ((Zrp+Zx)*(Zrs_dash+RL_dash))));
      Mg(j)=abs((Zx*RL_dash / ((Zrp+Zx)*(Zrs_dash+RL_dash))));

    end
    plot(fsw,Mg);
    hold on;
end

plot([fsw(1) fsw(no_fsw)],[Mg_Fmax Mg_Fmax], "--");
plot([fsw(1) fsw(no_fsw)],[Mg_Fmin Mg_Fmin], "--");
plot([fsw(1) fsw(no_fsw)],[Mg_Fmid Mg_Fmid], "--");

hold off;
grid on;
xlabel('Frequency f_{sw}');
ylabel('Gain M_g');
xlim([1 300000]);
ylim([0 4]);
title('FCM CLLLC, Lm 160uH, Ln 4.44, RL varying ');
legend('250V at max load (6.76ohm)','298V 100% load (8.07ohm)','470V 100% load (20.08ohm)', '250V 3.5A (71.43ohm)','250V Gf','470V Gf','298V Gf');

% CLLLC reverse gain curve (verify)
Mg_Rmin=VinLLC_Fmin/(n_CLLC*Vo_Fmax); % minimum voltage gain at VinLLC_min
Mg_Rmax=VinLLC_Fmax/(n_CLLC*Vo_Fmin); % maximum voltage gain at VinLLC_max
%Mg_Rmin=Vo_R/VinLLC_R; % minimum voltage gain at VinLLC_max
%Mg_Rmax=Vo_R/VinLLC_R; % maximum voltage gain at VinLLC_min

%RL=[50:5:60];
RL=[58.18, 69.19, 72.73];

no_RL=length(RL);

figure(2);
for p=1:1:no_RL
    for j=1:1:no_fsw
      %Zm
      Zm=complex(0, 2*pi*fsw(j)*Lm);
      %Zrp
      Zrp=(1/complex(0,2*pi*fsw(j)*Crp))+complex(0, 2*pi*fsw(j)*Lrp);
      Zrs_dash=(1/complex(0,2*pi*fsw(j)*Crs_dash))+ complex(0, 2*pi*fsw(j)*Lrs_dash); %Zrs'
      RL_dash=RL(p)*(8/(pi*pi));
      Zx=(Zm*(Zrp+RL_dash))/(Zm+Zrp+RL_dash); %Zm||(Zrp+RL)
      %Mg(j)=abs((n_CLLC)*(Zx*RL_dash / ((Zrs_dash+Zx)*(Zrp+RL_dash))));
      Mg(j)=abs((Zx*RL_dash / ((Zrs_dash+Zx)*(Zrp+RL_dash))));

    end
    plot(fsw,Mg);
    hold on;
end

plot([fsw(1) fsw(no_fsw)],[Mg_Rmax Mg_Rmax], "--");
plot([fsw(1) fsw(no_fsw)],[Mg_Rmin Mg_Rmin], "--");
hold off;
grid on;
xlabel('Frequency f_{sw}');
ylabel('Gain M_g');
xlim([1 200000]);
ylim([0 1.5]);
title('RCM CLLLC, Lm 160uH, Ln 4.44, RL varying ');
legend('800V 100% load at 298-470Vin', '800V max load at 250Vin', '800V 80% load at 250Vin','250V Gr','470V Gr');

