% A funcao falsaposicao.m  utiliza o metodo da Falsa Posicao para encontar
% uma raiz real de uma funcao f continua no intervalo [a,b]
% satisfazendo f(a)*f(b) < 0
% Entrada:
%         f: funcao de uma variavel
%         a: limite inferior do intervalo
%         b: limite superior do intervalo
% Saida:
%         X : a raiz de f(x)

% SUBSTITUA 0000000 PELO SEU NÚMERO DE RA

 
function x = falsaposicao2058979(f,a,b)
  
  if((f(a) * f(b)) >= 0)
    x = -1;
  else
  
    i = 1;
    # primeira verificação
    xk = ((a*f(b)) - (b*f(a))) / (f(b) - f(a));
    if (f(a) * f(xk) < 0)
        b = xk;
      else
        a = xk;
      endif
      
   ###loop
    while (i < 100) && (abs(b - a) >= 10^(-4)) && (abs(f(xk)) >= 10^(-4))
      i = i + 1;
      xk = ((a*f(b)) - (b*f(a))) / (f(b) - f(a));
      
      if (f(a) * f(xk) < 0)
        b = xk;
      else
        a = xk;
      endif
        
    endwhile
    
    x = xk;
  endif
endfunction

