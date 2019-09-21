function sol = Taylor2_2058979(x0, y0, xf, h, f, fx, fy)
    xk = (x0:h:xf)';
    yk = zeros(length(x0:h:xf),1);
    yk(1) = y0;
    
    for i = 2:length(xk)
      yk(i) = yk(i-1) + ( h * f(xk(i-1),yk(i-1)) ) + ( h*h / 2 * (fx(xk(i-1),yk(i-1)) + (fy(xk(i-1),yk(i-1)) * f(xk(i-1),yk(i-1)))));
    endfor
     
    sol = [xk yk];
 
endfunction