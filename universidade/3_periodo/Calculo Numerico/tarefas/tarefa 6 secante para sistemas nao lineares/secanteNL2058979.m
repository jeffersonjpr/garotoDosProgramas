function [x0, k] = secanteNL2058979(F,x0,B0)
  e = 10^-4;
  k = 0;
  while (k < 1001 && norm(F(x0)) > e) 
    S = -B0\F(x0);
    x0 = x0 + S;
    B0 = B0 + ((F(x0) * S')/(S'*S));
    k = k + 1;
  endwhile
endfunction
