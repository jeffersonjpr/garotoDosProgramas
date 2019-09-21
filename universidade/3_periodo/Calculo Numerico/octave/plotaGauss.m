% rotina plotagauss.m polota a funcao gaussiana

clear all
clc

%definir o dominio

x = -2:0.01:2;

%definir a imagem

y = fun(x);

plot(x,y,'b')

figure
plot(x,x.^2,'r')

xlabel('x')
ylabel('y')
title('Sino e Parabola')
legend('sino','x^2')

