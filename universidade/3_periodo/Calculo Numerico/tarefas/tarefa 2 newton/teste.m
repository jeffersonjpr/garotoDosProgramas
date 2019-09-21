function x = teste(y)
  
  f1 = @(x) x^3-9*x+3;
  df1 = @(x) 3*x^2-9;
  sol1 = newton2058979(f1,df1,0.5)

  
  f2 = @(x) exp(-x^2)-cos(x);
  df2 = @(x) -2*x*exp(-x^2)+sin(x);
  sol2 = newton2058979(f2,df2,5.5)
  
  f3 = @(x) x^2+x-6;
  df3 = @(x) 2*x+1;
  sol3a = newton2058979(f3,df3,-0.5)
  sol3b = newton2058979(f3,df3,1.5)
  
  f4 = @(x) x^2;
  df4 = @(x) 2*x;
  sol4 = newton2058979(f4,df4,0)
  
  x = 1;
endfunction
