%Execution rate
Step_Rate = 1e-7;
Control_Step_Rate  = 50e-6;
Fclk = 100e6;

%Resonant tank Base parameters
%A2 Design
CrP = 132e-9;
LrP = 36e-6;
n = 20.0/9.0;
Ln = 80e-6 / LrP;
Lm = Ln * LrP;
CrS = 216.0e-9;
LrS = 22e-6;
transformerCoupling = 0.999; 

%A3 Design
% CrP = 135e-9;
% LrP = 8e-6;
% n = 21.0/9.0;
% Ln = 130e-6 / LrP;
% Lm = Ln * LrP;
% CrS = 220.0e-9;
% LrS = 30e-6;
% transformerCoupling = 0.999; 

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
Loop_Select = 3;        %0 - Open Loop, 1 - Closed Loop with PI block, 2 - Open Loop for bode plot, 3 - closed loop with 2P2Z/PI
Reverse = 1;            %Forward = 0, Reverse = 1
Charger_Mode = 2;       % 0 - CC, 1 - CV forward, 2 - CV reverse

R_series = 3;
KVpri = 0.0036102;
KVsec = 0.00569815;
KIout = 20e-3;
VADC = 3.3;
ADCFS = 4095;

if (Loop_Select == 0 || Loop_Select == 2) % if Open Loop    
    %Power_Limit = 11000;

    if Reverse == 0    
        %input parameters
        V_Input = 750;
        V_Output = 250;

        %Load 
        %R_Load = (V_Output * V_Output)/ Power_Limit;
        I_Load = 37.0;
        V_Load = V_Output - I_Load * R_series;

        Freq_Sw = 82.6e3; %Range 30K - 140Khz
        Ts_Sw = floor(Fclk/Freq_Sw);      

    else
        %input parameters
        V_Input = 250;
        V_Output = 750;

        %Load 
        %R_Load = (V_Output * V_Output)/ Power_Limit;
        I_Load = 9250 / V_Output;
        V_Load = V_Output - I_Load * R_series; %not used. just bypass errors

        Freq_Sw = 55.1e3; %Range 60K - 92Khz
        Ts_Sw = floor(Fclk/Freq_Sw);
    end
else %Closed Loop

    Power_Limit = 11000; %11KW
        
    if Reverse == 0    
        V_Input = 750;
        if Charger_Mode == 0 % CC mode
            %CC forward 2P2Z control parameters
            %G_fc3=-55, fz3=2500, Qc=0.63, fp3=15000
            %a0_cv_F = 0.2451;
            %a1_cv_F = -0.2588;
            %a2_cv_F = 0.0839;
            %b1_cv_F = -0.5959;
            %b2_cv_F = -0.4041;

            %CC forward PI control parameters
            %G_fc=20, fzL=1000
            a0_cv_F = 0.2835;
            a1_cv_F = -0.2188;
            a2_cv_F = 0.0;
            b1_cv_F = -1;
            b2_cv_F = 0.0;
            
            Cmd_Ref = 23.4; %A
            V_Output = 470;
            % Nominal Value for Tuning %
            % 31.43A => 11KW => 350V
            % 23.4A => 11KW => 470V
            %R_Load = Power_Limit /(Cmd_Ref * Cmd_Ref);  %Ohms
            V_Load = V_Output - Cmd_Ref * R_series;
            Cmd_Ref_Ctrl = round(Cmd_Ref * KIout / VADC * ADCFS);   
            I_Load = Cmd_Ref; % for reverse current source 
        else %CV mode
            %CV forward 2P2Z control parameters
            %G_fc3=-55, fz3=2500, Qc=0.63, fp3=15000
            %a0_cv_F = 0.1138;
            %a1_cv_F = -0.1083;
            %a2_cv_F = 0.03398;
            %b1_cv_F = -0.5959;
            %b2_cv_F = -0.4041;

            %CV forward PI control parameters
            %G_fc=20, fzL=2000

%             a0_cv_F = 0.123562;
%             a1_cv_F = -0.0764381;
% 
%             a0_cv_F = 0.095984;
%             a1_cv_F = -0.016485;
% 
%             a0_cv_F = 0.073901;
%             a1_cv_F = -0.038567;

%             a0_cv_F = 0.044041;
            a1_cv_F = -0.019205;
% 
            a0_cv_F = 0.027559;
%             a1_cv_F = -0.008006;
% 
%             a0_cv_F = 0.008273;
%             a1_cv_F = -0.002973;

%             a0_cv_F = 0.261627;
%             a1_cv_F = -0.094028;

            a2_cv_F = 0.0;
            b1_cv_F = -1;
            b2_cv_F = 0.0;
            
            Cmd_Ref = 470; %V
            % Nominal Value for Tuning %
            % 350V => 11KW => 31.43A
            % 470V => 11KW => 23.4A
            % 250V => 9.25KW => 37A
            %R_Load = (Cmd_Ref * Cmd_Ref) / Power_Limit;  %Ohms
            I_Load = Power_Limit/Cmd_Ref;
            if I_Load > 37
                I_Load = 37;
            end
            V_Load = Cmd_Ref - I_Load * R_series;
            Cmd_Ref_Ctrl = round(Cmd_Ref * KVsec / VADC * ADCFS);
        end    
    else
        %input parameters
        V_Input = 470;

        %CV reverse PI control parameters
        %G_fc=20, fzL=2000
        a0_cv_F = 0.01392699;
        a1_cv_F = -0.0060730;
        a2_cv_F = 0.0;
        b1_cv_F = -1;
        b2_cv_F = 0.0;
    
        Cmd_Ref = 750; %V
        I_Load = 11000/Cmd_Ref;       
        V_Load = Cmd_Ref - I_Load * R_series;
        Cmd_Ref_Ctrl = round(Cmd_Ref * KVpri / VADC * ADCFS);
    end
end


