function [LU x] = DecomposicaoLU2058979(A,b)
  len = length(b);
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
     for j = (i + 1):len
      mi = A(j,i)/A(i,i);
      A(j,i:end) = A(j,i:end) - mi * A(i,i:end);
      
      A(j,i) = mi;
    endfor
    
  endfor
  
  if (A(len,len) == 0)
    LU = -ones(len,len);
    x = -ones(len,1);
  
  else
    
    #calculo y
    y = ones(len,1);
    y(1) = b(1);
    for i = 2:len
      y(i) = b(i) - A(i,1:i-1) * y(1:i-1);
    endfor
    
    #calculo x
    x = ones(len,1);
    x(len) = y(len) / A(len,len);
    for i = len-1:-1:1
      x(i) = (y(i) - ( A(i,(i+1):len) * x((i+1):len)))/(A(i,i));
    endfor
    LU = A;
    x = x;
  endif
endfunction
