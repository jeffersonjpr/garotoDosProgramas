function area = simpsonR2058979(f,a,b,n)
  if(mod(n,2) != 0)
    area = -1;
  else
  x = linspace(a,b,n+1);
  h = (b-a) / n;
  area = (h * (f(a) + f(b) + 4*sum(f(x(2:2:n+1))) + 2 * sum(f(x(3:2:n-1))))) / 3;
  endif
endfunction
