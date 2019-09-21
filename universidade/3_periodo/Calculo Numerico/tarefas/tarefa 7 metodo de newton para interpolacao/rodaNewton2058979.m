%teste 1
xi1 = [0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1];
yi1 = [0.5 0.8 1.1 1.4 1.7 2 2.3 2.6 2.9 3.2 3.5];
xx1 = -6:0.1:6;
for i = 1:length(xx1)
  yy1(i) = Newton_interpol2058979(xi1, yi1, xx1(i));
endfor
figure();
plot (xi1,yi1,'or ;Pontos Tabelados;', xx1, yy1,';Polinomio Interpolador;');
title('Teste 1');

%teste 2
xi2 = [0 500 1000 1500 2000 2500];
yi2 = [750 710 670 630 590 560];
xx2 = -1000:0.1:5000;
for i = 1:length(xx2)
  yy2(i) = Newton_interpol2058979(xi2, yi2, xx2(i));
endfor
figure();
plot (xi2,yi2,'or ;Pontos Tabelados;', xx2, yy2,';Polinomio Interpolador;');
title('Teste 2');

%teste 3
xi3 = [10 15 20 25 30 35 40 45 50];
yi3 = [3.45 5.17 6.90 8.62 10.03 12.07 13.79 15.52 17.24];
xx3 = 0:0.1:70;
for i = 1:length(xx3)
  yy3(i) = Newton_interpol2058979(xi3, yi3, xx3(i));
endfor
figure();
plot (xi3,yi3,'or ;Pontos Tabelados;', xx3, yy3,';Polinomio Interpolador;');
title('Teste 3');