function x = newton2058979(f, df,x0)
  tol = 10^(-4);
  
  if(abs(f(x0)) < tol)
    x = x0;
  elseif(abs(df(x0)) == 0)
    x = -1;
  else
    x1 = x0 - f(x0)/df(x0);
    
    for i = 1:500
      teste1 = abs(x1 - x0) < max(abs(x1),1) * tol ;  %primera condiçao
      teste2 = abs(x1) < max(abs(x0),1) * tol ;       %segunda condiçao
      
      if(teste1 && teste2)
        break;
      endif
      
      x0 = x1;
      x1 = x0 - f(x0)/df(x0);
    endfor
    
    x = x1;
  
  endif
endfunction
