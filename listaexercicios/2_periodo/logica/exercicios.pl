%exercicio 2: acha o maior entre tres
maiorDeTres(X,Y,Z):-
    X >= Y,
    X >= Z,
    print(X);
    Y >= X,
    Y >= Z,
    print(Y);
    Z >= Y,
    Z >= X,
    print(Z).

%exercicio 3: acha o menor entre tres
menorDeTres(X,Y,Z):-
    X =< Y,
    X =< Z,
    print(X);
    Y =< X,
    Y =< Z,
    print(Y);
    Z =< Y,
    Z =< X,
    print(Z).

%exercicio 4: fatorial
fatorial(0,1).
fatorial(N,F):-
    N > 0,
    Nx is N - 1,
    fatorial(Nx,Fx),
    F is N * Fx.
