clear
close all
eta = load('psi.mat', 'ans');
eta = eta.ans;
tau = load('tau.mat', 'ans');
tau = tau.ans;
u_hat = load('u_hat.mat', 'ans');
u_hat = u_hat.ans;
u_real = load('u_real.mat', 'ans');
u_real = u_real.ans;
u_tilde = load('u_tilde.mat', 'ans');
u_tilde = u_tilde.ans;
dropout = load('dropout.mat', 'ans');
dropout = dropout.ans;
a = 4638;
b = 5361;%length(u_hat(1, :));
%U
f1 = figure;
hold on
grid on
subplot(3, 1, 1);
plot(u_hat(1, a:b), u_hat(2, a:b), u_real(1, a:b), u_real(2, a:b));
title('k_{\psi} = 10 Force X and Y');
xlabel('Time [s]');
ylabel('[m/s]');
legend('U hat', 'U');
subplot(3, 1, 2);
plot(u_tilde(1, a:b), u_tilde(2, a:b));
legend('U tilde');
xlabel('Time [s]');
ylabel('[m/s]');
subplot(3, 1, 3);
plot(dropout(1, a:b), dropout(2:4, a:b));
ylim([-0.1 1.1]);
legend('Dropout in x', 'Dropout in y', 'Dropout in \psi');
xlabel('Time [s]');
ylabel('Dropout');

%force
f2 = figure;
hold on
grid on
plot(tau(1, a:b), tau(2, a:b));
title('Force X');
xlabel('Time [s]');
ylabel('Force [N]');
legend('X');

% psi
f3 = figure;
hold on;
grid on;
plot(eta(1, a:b), eta(4, a:b).*180/pi);
title('\psi');
xlabel('Time [s]');
ylabel('Angle [degrees]');