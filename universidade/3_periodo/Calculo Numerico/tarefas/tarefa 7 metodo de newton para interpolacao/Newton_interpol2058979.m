function y = Newton_interpol2058979(xi, yi, x)
  n = length(xi);
  d = zeros(n);
  
  d(:,1) = yi;
  for i = 2:n
    for k = i:n
      d(k,i) =  (d(k,i-1) - d(k-1,i-1))/(xi(k) - xi(k-(i-1)));
    endfor
  endfor
  
  y = d(1,1);
  for i = 2:n
    xk = 1;
    for j = 1 : i-1
      xk *= (x - xi(j));
    endfor
    y += d(i,i) * xk;
  endfor
  
endfunction