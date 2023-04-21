s=tf('s');
Fsw=5e3;	% the frequency of voltage loop set at 5kHz
Tsw=1/Fsw;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% Below one seems to be good without very high overshoot. Nat tested it.
f_pole1 = 4.3		; 	%% in Hz
f_pole2 = 37	; 	%% in Hz
f_zero1 = 2.67		; 	%% in Hz
k = 1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

f_pole1 = 14.3		; 	%% in Hz
f_pole2 = 47	; 	%% in Hz
f_zero1 = 2.67		; 	%% in Hz
k=1;

% % % Desired_compensator_gain_in_dB = 100;
% % % k=20*log(Desired_compensator_gain_in_dB);

pole1 	= 2*pi* f_pole1;
pole2 	= 2*pi* f_pole2;
zero1 	= 2*pi* f_zero1;

%% 2P2Z compensator
Compensator	= k*	 pole1/s *  (1+s/zero1) / (1+s/pole2);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Compensator_digital=c2d(Compensator,Tsw,'tustin');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[NUM, DEN] = tfdata(Compensator_digital);
NUM=NUM{1,1};
V_loop_b0=NUM(1,1);
V_loop_b1=NUM(1,2);
V_loop_b2=NUM(1,3);

DEN=DEN{1,1};
V_loop_a0=DEN(1,1);
V_loop_a1=DEN(1,2);
V_loop_a2=DEN(1,3);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%%%% End of voltage loop. 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%