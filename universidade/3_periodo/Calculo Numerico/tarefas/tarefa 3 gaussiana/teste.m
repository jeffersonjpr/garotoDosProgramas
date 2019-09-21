function x = teste(y)
  A1 = [0.18 0.23 0.67; 0.54 0.37 0.10; 0.28 0.40 0.23]
  b1=[308; 350; 342]
  x1 = EGPivoParcial2058979(A1,b1)

  A2 = [0 1 3; 1 0 -2; 3 0 1]
  b2=[1; 1; 2]
  x2 = EGPivoParcial2058979(A2,b2)

  A3 = [0 1 3;1 0 -2;0 0 0]
  b3=[1; 1; 2]
  x3 = EGPivoParcial2058979(A3,b3)

  A4 = [0 1 3;1 0 -2;1 0 -2]
  b4=[1 1 2]
  x4 = EGPivoParcial2058979(A4,b4)

  x = 1;
endfunction
