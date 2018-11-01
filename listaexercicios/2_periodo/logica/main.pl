adulto(tywin).
adulto(joanna).
adulto(catelyn).
adulto(jaime).
adulto(cersei).
adulto(jonsnow).
adulto(brandon).
adulto(benjen).
adulto(eddard).
adulto(robb).
adulto(lyanna).
anao(tyrion).
jovem(myrcella).
jovem(tommen).
jovem(sansa).
jovem(arya).
jovem(brandon).
jovem(rickon).
jovem(joffrey).

homem(tywin).
homem(jaime).
homem(jonsnow).
homem(brandon).
homem(benjen).
homem(eddard).
homem(robb).
homem(joffrey).
homem(tommen).
homem(brandon).
homem(tyrion).
homem(rickon).
mulher(myrcella).
mulher(lyanna).
mulher(arya).
mulher(catelyn).
mulher(cersei).
mulher(sansa).
mulher(joanna).

projenitor(catelyn, robb).
projenitor(catelyn, sansa).
projenitor(catelyn, arya).
projenitor(catelyn, brandon).
projenitor(catelyn, rickon).
projenitor(eddard, robb).
projenitor(eddard, sansa).
projenitor(eddard, arya).
projenitor(eddard, brandon).
projenitor(eddard, rickon).

projenitor(tywin, jaime).
projenitor(tywin, cersei).
projenitor(tywin, tyrion).
projenitor(joanna, jaime).
projenitor(joanna, cersei).
projenitor(joanna, tyrion).

projenitor(cersei, joffrey).
projenitor(cersei, myrcella).
projenitor(cersei, tommen).
projenitor(jaime, joffrey).
projenitor(jaime, myrcella).
projenitor(jaime, tommen).

pai(X,Y):-
    projenitor(X,Y),
    homem(X).


soma1(X,Y):-
    K is X + Y,
    print(K).

soma2(X,Y,K):-
    K is X + Y.
