function y0 = SplineBin2058979(x, y, x0)
  nx = length(x);
  ny = length(y);
  #x fora do intervalo
  if(x0 < x(1) || x0 > x(nx))
    y0 = -1;
    return;
  endif
  #tamanho fora 
  if(nx != ny)
    y0 = -1;
    return;
  endif
  comeco = 1;
  meio = fix(nx / 2);
  fim = nx;
  
  while((fim - comeco) > 1)
    if (x0 >= x(meio))
      comeco = meio;
      meio = fix((meio + fim) / 2);
      continue
    endif
    fim = meio;
    meio = fix((comeco + meio) / 2);
  endwhile
  
  y1 = (y(fim) - y(comeco))/(x(fim) - x(comeco));
  y2 = x0 - x(comeco);
  y0 = y(comeco) + (y1 * y2);
endfunction
