function y = exponencial(x, k)
  y = 0;
  for i = 0:k
      y += x^i/(factorial(i));
  endfor
endfunction
