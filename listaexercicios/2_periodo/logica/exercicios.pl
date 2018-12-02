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

%exercicio5: verifica se é primo
eprimo(X,Y):-
    X=:=Y,
    !.
eprimo(X,Y):-
    X mod Y =\= 0,
    T is Y + 1,
    eprimo(X,T).
primo(N):-
    eprimo(N,2).

%exercicio7:
medida(cozinha, 2.0, 3.0).
medida(sala, 4.0, 5.5).
medida(quarto, 3.0, 3.5).
medida(banheiro,1.5, 2.0).

tamanho(Comodo,Area):-
    medida(Comodo,X,Y),
    Area is X * Y.
