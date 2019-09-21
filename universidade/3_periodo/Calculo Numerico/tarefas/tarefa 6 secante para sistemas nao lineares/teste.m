function x = teste(x)
  
 fun1 = @(x)[x(1)^2-10*x(1)+x(2)^2+8; x(1)*x(2)^2+x(1)-10*x(2)+8];
B1 = 3*eye(2);
x1 = [5;5]; 
[x1, k1] = secanteNL2058979(fun1, x1, B1)


fun2 = @(x) [2*x(1)^2-2*x(1)-x(2)+1;x(1)^2+x(2)^2-1];
B2 = eye(2);
x2 = ones(2,1);
[x2, k2] = secanteNL2058979(fun2, x2, B2)


fun3 = @(x)[x(1)+x(2)-3; x(1)^2+x(2)^2-9];
B3 = eye(2);
x3 = ones(2,1);
[x3, k3] = secanteNL2058979(fun3, x3, B3)


fun4 = @(x)[3*x(1)-cos(x(2)*x(3))-0.5; x(1)^2-81*(x(2)+0.1)^2+sin(x(3))+1.06; exp(-x(1)*x(2))+20*x(3)+(10*pi-3)/3]; 
B4 = 5*eye(3);
x4 = ones(3,1);
[x4, k4] = secanteNL2058979(fun4, x4, B4)



fun5 = @(x)[x(1)^3*x(2)^5-x(3)-10;2*x(1)-x(1)^2*x(2)+x(3)-2; x(1)+x(2)^2-x(3)-4];
B5 = eye(3);
x5 = ones(3,1);
[x5, k5] = secanteNL2058979(fun5, x5, B5)
endfunction
