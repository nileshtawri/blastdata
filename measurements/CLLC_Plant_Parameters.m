%Execution rate
Step_Rate = 1e-7;
Control_Step_Rate  = 50e-6;

%Resonant tank Base parameters
CrP = 132e-9;
LrP = 36e-6;
n = 20.0/9.0;
Ln = 160e-6 / LrP;
Lm = Ln * LrP;
CrS = 216.0e-9;
LrS = 22e-6;

%Individual Resonant tank parameters with Tolerance
% Tol_C1P = 0.05;  % +5%
% Tol_L1P = 0.12;  % +12%
% 
% Tol_C1S = -0.05;  % +5%
% Tol_L1S = -0.12;  % +12%

Tol_C1P = 0;  % 
Tol_L1P = 0;  % 

Tol_C1S = 0;  % 
Tol_L1S = 0;  % 

%CLLLC1 Tolerance
CrP1 = CrP * (1.0 + Tol_C1P);
LrP1 = LrP * (1.0 + Tol_L1P);
Lm1 = Ln*LrP1;

CrS1 = CrS * (1.0 + Tol_C1S);
LrS1 = LrS * (1.0 + Tol_L1S);

%Configurations
Loop_Select = 1;        %0 - Open Loop, 1 - Closed Loop
Reverse = 0;            %Forward = 0, Reverse = 1

if Loop_Select == 0 % if Open Loop    
    Power_Limit = 100;

    if Reverse == 0    
        %input parameters
        V_Input = 800;
        V_Output = 250;

        %Load 
        R_Load = (V_Output * V_Output)/ Power_Limit;

        Freq_Sw = 100.0e3; %Range 50K - 140Khz
    else
        %input parameters
        V_Input = 480;
        V_Output = 800;

        %Load 
        R_Load = (V_Output * V_Output)/ Power_Limit;    

        Freq_Sw = 83e3; %Range 60K - 92Khz
    end
else %Closed Loop
    Charger_Mode = 1; % 0 - CC, 1 - CV
    Power_Limit = 9250; %11KW
    
    V_Input = 800;
        
    if Charger_Mode == 0 % CC mode
        Cmd_Ref = 23.4; %A
        % Nominal Value for Tuning %
        % 31.43A => 11KW => 350V
        % 23.4A => 11KW => 470V
        R_Load = Power_Limit /(Cmd_Ref * Cmd_Ref);  %Ohms
    else
        Cmd_Ref = 250; %V
        % Nominal Value for Tuning %
        % 350V => 11KW => 31.43A
        % 470V => 11KW => 23.4A
        % 250V => 9.25KW => 37A
        R_Load = (Cmd_Ref * Cmd_Ref) / Power_Limit;  %Ohms
    end    
end


