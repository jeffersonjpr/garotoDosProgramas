n = [100 200 400 600 800 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000];
s = [0.0003 0.0014 0.0043 0.0126 0.0244 0.0425 0.2163 0.5015 0.9702 1.6451 2.5825 3.7516 5.2557 7.0075 9.0550];

z = log(s)';

a = [ones(length(n),1) log(n)'];

c = (a' * a)\(a' * z);
a = e.^c(1)
b = c(2)

ajuste = @(x) a.* x.^b;
xx = 100:1:10000;
figure();
plot (n,s,'or ;Pontos Tabelados;', xx, ajuste(xx),';Curva de ajuste;');

Erro = sum((s - ajuste(n)).^2)
figure();
plot (log(n),log(s),'or',log(n),log(s));
title('Teste de Alinhamento');


% Resposta: SIM, pois o teste de alinhamento se assemelha a uma reta.

