% CLLLC Design, regulation and protection dimensioning
% Author: Dr. Lim Shu Fan
% First created: 01.04.2022
% Last modified: 25.01.2023
% Revision: 2.0
% Descriptions:
% 0.1: First design attempt to match with implementation 
% 2.0: Designing Attempt for New Transformer

clear;
%%%%%%%%%%%%%%%% 1. Define System specification %%%%%%%%%%%%%%%%%%%%
%System pParameters
Vin_Min = 750; %min input voltage of LLC
Vin_Max = 750; %max input voltage of LLC 

Vout_Min = 250; % Minimum output voltage 
Vout_Max = 470; % Maximum output voltage 


PWR_MinL_250V = 925;        %10 Load Current 3.7A
PWR_FL_250V = 9250;         %Max Current 37A
PWR_FL_AFT300V = 11000;     %Max Power 11KW

%Tank Parameters
n_CLLC = 21/9;

%magnetizing inductance
Lm = 130*10^-6;

%Primary Tank Values
Lrp = 80 * 10^-6;
Crp = 135 * 10^-9;

%Secondary Tank Values
Lrs = 38 * 10^-6;
Crs = 220 * 10^-9;

Lrs_dash = Lrs * (n_CLLC * n_CLLC);
Crs_dash = Crs / (n_CLLC * n_CLLC);

%Plot Parameter Calculations
RL_at_250V_FL = (250 * 250)/ PWR_FL_250V;       % 250V FL 37A 6.76 Ohms
RL_at_300V_FL = (300 * 300)/ PWR_FL_AFT300V;    % 300V FL 36.6A 8.18 Ohms
RL_at_350V_FL = (350 * 350)/ PWR_FL_AFT300V;    % 350V FL 31.4A 11.14 Ohms
RL_at_400V_FL = (400 * 400)/ PWR_FL_AFT300V;    % 400V FL 27.5A 14.55 Ohms
RL_at_470V_FL = (470 * 470)/ PWR_FL_AFT300V;    % 470V FL 23.4A 20.08 Ohms
RL_at_250V_MinL = (250 * 250)/ PWR_MinL_250V;   % 250V 10% 3.7A 67.57 Ohms

Gain_Vmin = n_CLLC * Vout_Min / Vin_Max;   % minimum voltage gain at VinLLC_max
Gain_Vmax = n_CLLC * Vout_Max / Vin_Min;   % maximum voltage gain at VinLLC_min

%Plot Parameters 
fsw = [1:10:200000];
%RL = [RL_at_250V_FL, RL_at_300V_FL, RL_at_350V_FL, RL_at_400V_FL, RL_at_470V_FL, RL_at_250V_MinL];
RL = [RL_at_250V_FL, RL_at_300V_FL, RL_at_350V_FL, RL_at_400V_FL, RL_at_470V_FL];

no_fsw = length(fsw);
no_RL = length(RL);

%%%%%%%%%%%%%%%% 2. Plot Forward mode Gain Curves %%%%%%%%%%%%%%%%%%%%
%Plot LLC Gain Curves @ Different Operating points
figure(1);
for p=1:1:no_RL
    for j=1:1:no_fsw
      Zm = complex(0, 2*pi*fsw(j)*Lm);

      Zrp = (1 / complex(0, 2*pi*fsw(j)*Crp)) + complex(0, 2*pi*fsw(j)*Lrp);

      Zrs_dash = (1 / complex(0, 2*pi*fsw(j)*Crs_dash)) + complex(0, 2*pi*fsw(j)*Lrs_dash); %Zrs'
     
      RL_dash = RL(p) * n_CLLC * n_CLLC * (8 / (pi * pi));

      Zx = (Zm * (Zrs_dash + RL_dash)) / (Zm + Zrs_dash + RL_dash); %Zm||(Zrs'+RL')
 
      Mag(j) = abs((Zx * RL_dash / ((Zrp + Zx) * (Zrs_dash + RL_dash))));

    end
    plot(fsw,Mag);
    hold on;
end

%Plot Min & Max Voltage Gains
plot([fsw(1) fsw(no_fsw)],[Gain_Vmin Gain_Vmin], "--");
plot([fsw(1) fsw(no_fsw)],[Gain_Vmax Gain_Vmax], "--");

hold off;
grid on;
xlabel('Frequency f_{sw}');
ylabel('Gain M_g');
xlim([1 200000]);
ylim([0 5.5]);
title('CLLLC Forward Mode, Lm 160uH, Lr1 80uH, Ln Lm/Lr1(1.625), RL varying ');
%legend('250V FL 37A 6.76 Ohms','300V FL 36.6A 8.18 Ohms','350V FL 31.4A 11.14 Ohms', '400V FL 27.5A 14.55 Ohms','470V FL 23.4A 20.08 Ohms','250V 10% 3.7A 67.57 Ohms', '250V Gf','470V Gf');
legend('250V FL 37A 6.76 Ohms','300V FL 36.6A 8.18 Ohms','350V FL 31.4A 11.14 Ohms', '400V FL 27.5A 14.55 Ohms','470V FL 23.4A 20.08 Ohms', '250V Gf','470V Gf');










% % CLLLC reverse gain curve (verify)
% Mg_Rmin=VinLLC_Fmin/(n_CLLC*Vo_Fmax); % minimum voltage gain at VinLLC_min
% Mg_Rmax=VinLLC_Fmax/(n_CLLC*Vo_Fmin); % maximum voltage gain at VinLLC_max
% %Mg_Rmin=Vo_R/VinLLC_R; % minimum voltage gain at VinLLC_max
% %Mg_Rmax=Vo_R/VinLLC_R; % maximum voltage gain at VinLLC_min
% 
% %RL=[50:5:60];
% RL=[58.18, 69.19, 72.73];
% 
% no_RL=length(RL);
% 
% figure(2);
% for p=1:1:no_RL
%     for j=1:1:no_fsw
%       %Zm
%       Zm=complex(0, 2*pi*fsw(j)*Lm);
%       %Zrp
%       Zrp=(1/complex(0,2*pi*fsw(j)*Crp))+complex(0, 2*pi*fsw(j)*Lrp);
%       Zrs_dash=(1/complex(0,2*pi*fsw(j)*Crs_dash))+ complex(0, 2*pi*fsw(j)*Lrs_dash); %Zrs'
%       RL_dash=RL(p)*(8/(pi*pi));
%       Zx=(Zm*(Zrp+RL_dash))/(Zm+Zrp+RL_dash); %Zm||(Zrp+RL)
%       %Mg(j)=abs((n_CLLC)*(Zx*RL_dash / ((Zrs_dash+Zx)*(Zrp+RL_dash))));
%       Mg(j)=abs((Zx*RL_dash / ((Zrs_dash+Zx)*(Zrp+RL_dash))));
% 
%     end
%     plot(fsw,Mg);
%     hold on;
% end
% 
% plot([fsw(1) fsw(no_fsw)],[Mg_Rmax Mg_Rmax], "--");
% plot([fsw(1) fsw(no_fsw)],[Mg_Rmin Mg_Rmin], "--");
% hold off;
% grid on;
% xlabel('Frequency f_{sw}');
% ylabel('Gain M_g');
% xlim([1 200000]);
% ylim([0 1.5]);
% title('RCM CLLLC, Lm 160uH, Ln 4.44, RL varying ');
% legend('800V 100% load at 298-470Vin', '800V max load at 250Vin', '800V 80% load at 250Vin','250V Gr','470V Gr');

