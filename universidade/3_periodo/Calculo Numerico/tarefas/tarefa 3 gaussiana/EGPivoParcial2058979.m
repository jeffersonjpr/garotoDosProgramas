function x = EGPivoParcial2058979(A,b)
  len = length(b);
  x = zeros(len,1);
  for i = 1:len - 1
    [ele, ind] = max(abs(A(i:end,i)));
    ind = ind + i - 1;
    if (ind != i) #trocar a linha com maior elemtno se for diferente do indice
      aux = A(i,:);
      A(i,:) = A(ind,:);
      A(ind,:) = aux;
      
      aux = b(i);
      b(i) = b(ind);
      b(ind) = aux;
    endif
    
    for j = (i + 1):len
      mi = A(j,i)/A(i,i);
      A(j,:) = A(j,:) - mi * A(i,:);
      
      b(j) = b(j) - mi * b(i);
    endfor

endfor
  A = A
  b = b
  if (A(len,len) == 0 && A(len,len-1) == 0)
    x = zeros(len,1);
    x = x - 1;
  else
    x(len) = b(len) / A(len,len);
    for i = len-1:-1:1
      x(i) = (b(i) - ( A(i,(i+1):len) * x((i+1):len)))/(A(i,i));
    endfor
  endif
  
endfunction
