eta_0 = [0 0 0];
nu_0 =[0 0 0];
tau = [1.03 0 0];
Par.SensNoiseEnabled = 1;
Par.Freeze.Enable = 0;
Par.Freeze.length = 1;
Par.Freeze.threshold = 2.6;

Par.Step_size = 0.01;
Par.Sample_time = 0.01;
Par.Sample_rate = 1/Par.Sample_time;
Par.Thrust_lim = [1.03 2.5 0.98]';

%% Lowpass filter
Par.Lowpass.omega.c_u = 100;
Par.Lowpass.omega.c_v = Par.Lowpass.omega.c_u;
Par.Lowpass.omega.c_psi = Par.Lowpass.omega.c_u;