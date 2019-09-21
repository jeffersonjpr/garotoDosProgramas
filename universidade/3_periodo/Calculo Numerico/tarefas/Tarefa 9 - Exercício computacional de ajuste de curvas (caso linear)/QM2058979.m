x1 = [0.5236 1.0472 1.5708 2.0944 2.618 3.1416 3.6652 4.1888 4.7124 5.236 5.7596 6.2832]';
y1 = [11.8 4.3 13.8 3.9 -18.1 -22.9 -22.9 -23.8 8.2 31.7 34.2 38.4]';
A1 = [ones(12,1) cos(x1) sin(x1) cos(2*x1) sin(2*x1)];
C1 = (A1' * A1)\(A1' * y1)

phi = @(x) C1(1) + C1(2) * cos(x) + C1(3) * sin(x) + C1(4) * cos(2*x) + C1(5)* sin(2*x);
xx1 = 0:0.1:7;
figure();
plot (x1,y1,'or ;Pontos Tabelados;', xx1, phi(xx1),';Curva de ajuste;');
title('Teste 1');

Erro1 = sum((y1 - phi(x1)).^2)

#segundo teste

x2 = [0.8 1.8 2.8 3.8 4.8 5.8 6.8 7.8 8.8 9.8 10 10.2 10.4 10.6 10.8 11 11.2 11.4 11.6 11.8]';
y2 = [0.15 0.52 0.76 1.12 1.47 1.71 2.08 2.56 3.19 4.35 4.55 5.64 6.76 8.17 10.1 12.7 16.2 20.3 30 60]';
A2 = [e.^(-x2) ones(20,1) e.^(x2)];
c2 = (A2' * A2)\(A2' * y2)

phi2 = @(x) c2(1) * e.^(-x) + c2(2) + c2(3) * e.^(x);
xx2 = 0:0.1:12;
figure();
plot (x2,y2,'or ;Pontos Tabelados;', xx2, phi2(xx2),';Curva de ajuste;');
title('Teste 2');
Erro2 = sum((y2 - phi2(x2)).^2)


#terceiro teste
x31 = [0.3 0.6 0.9 0.3 0.6 0.9 0.3 0.6 0.9]';
x32 = [0.001 0.001 0.001 0.01 0.01 0.01 0.05 0.05 0.05 ]';
y3 = [0.04 0.24 0.69 0.13 0.82 2.38 0.31 1.95 5.66]';
A3 = [ones(9,1) x31 x32];
c3 = (A3' * A3)\(A3' * y3)

phi3 = @(x1,x2) c3(1) + c3(2) * x1 + c3(3) * x2;
xx3 = 0:0.1:1;
figure();
#surf(xx3, xx3, phi3(xx3,xx3'));
#mesh (x31,x32,y3,'or ;Pontos Tabelados;', xx3,xx3', phi3(xx3,xx3'),';Curva de ajuste;');
plot3(x31,x32,y3,'or ;Pontos Tabelados;');
hold on
mesh(xx3, xx3, phi3(xx3,xx3'));
title('Teste 3');

Erro3 = sum((y3 - phi3(x31,x32)).^2)