function  [x k] = GaussJacobi2058979(A,b,x0)
  len = length(b);
  erro = 10^(-3);
  k = 0;
  kmax = 1000;
  #verificação das linhas
  teste = 0;
  for i = 1:len
    soma = ( sum( abs( A(i,:))) - abs( A(i,i)))  / abs(A(i,i));
    if (soma >= 1)
      teste = 1;
      break
    endif
  endfor
  #pivoteamento parcial
  if (teste == 1) 
    for i = 1 : len - 1
      [ele, ind] = max(abs(A(i:end,i))); #maior elemento na submatriz coluna
      ind = ind + i - 1; #problema com a submatriz
      
      if (ind != i) #ttroca as linhas
        aux = A(i,:);
        A(i,:) = A(ind,:);
        A(ind,:) = aux;
        
        aux = b(i);
        b(i) = b(ind);
        b(ind) = aux;
      endif
    endfor
    if (A(len,len) * A(len, len-1) == 0)
      x = -ones(len,len);
      return;
    endif
  endif
  #gauss jacobi
  d = diag(diag(A));
  c = eye(len) - (d\A);
  g = d\b;
  while (k < 1000 && (norm(b - (A*x0)) >= erro))
    k = k + 1;
    xprox = (c*x0) + g;
    x0 = xprox;
  endwhile
  x = x0;
  k = k;
endfunction
