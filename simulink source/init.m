eta_0 = [0 0 0];
nu_0 =[0 0 0];
tau = [1.03 0 0];
Par.K_psi_init = 0.3;
%% noise and dropout
Par.SensNoiseEnabled = 1;
Par.Freeze.Enable = 1;
Par.Freeze.length = 5;
Par.Freeze.threshold = 3.0;

Par.Step_size = 0.01;
Par.Sample_time = 0.01;
Par.Sample_rate = 1/Par.Sample_time;


Par.Thrust_lim = [1.03 2.5 0.98]';

%% Lowpass filter
Par.Lowpass.omega.c_u = 100;
Par.Lowpass.omega.c_v = Par.Lowpass.omega.c_u;
Par.Lowpass.omega.c_psi = Par.Lowpass.omega.c_u;

