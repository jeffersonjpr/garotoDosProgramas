#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int i,v[10],x;
    InicioFim *fila1,*fila2,*pilha1,*pilha2;
    //alocaçoes
    fila1 = (InicioFim*)malloc(sizeof(InicioFim));
    if(fila1 == NULL) return 0;
    fila2 = (InicioFim*)malloc(sizeof(InicioFim));
    if(fila2 == NULL) return 0;
    pilha1 = (InicioFim*)malloc(sizeof(InicioFim));
    if(pilha1 == NULL) return 0;
    pilha2 = (InicioFim*)malloc(sizeof(InicioFim));
    if(pilha2 == NULL) return 0;

    //atribuiçoes
    fila1 -> inicio = fila1 -> fim = NULL;
    fila2 -> inicio = fila2 -> fim = NULL;
    pilha1 -> inicio = pilha1 -> fim = NULL;
    pilha2 -> inicio = pilha2 -> fim = NULL;

    //testes

    //ConcatenaPilha
    printf("\n");
    for(i = 1; i <= 5; i++){
        InserePilha(pilha1,rand() % 30+1);
    }
    printf("Pilha 1: ");
    ImprimePilha(pilha1);
    for(i = 1; i <= 5; i++){
        InserePilha(pilha2,rand() % 30+1);
    }
    printf("Pilha 2: ");
    ImprimePilha(pilha2);
    ConcatenaPilha(pilha1,pilha2);
    printf("Concatenacao: ");
    ImprimePilha(pilha1);


    //pilha inversa
    printf("\n");
    printf("Pilha: ");
    ImprimePilha(pilha1);
    free(pilha2 -> inicio);
    free(pilha2);
    pilha2 = PilhaInversa(pilha1);
    printf("Pilha inversa: ");
    ImprimePilha(pilha2);

    //fila impar/par
    for(i = 1; i <= 10; i++){
        InsereFila(fila1,rand() % 30+1);
    }
    printf("\nFila normal: \n");
    ImprimeFila(fila1);
    fila2 = FilaImparPar(fila1);
    printf("Fila impar/par: \n");
    ImprimeFila(fila2);


    //QuantidadeElementosFP
        printf("\nPilha : ");
        ImprimePilha(pilha2);
        printf("Quantidade de elementos:%i\n",QuantidadeElementosFP(pilha2));
        printf("Fila: ");
        ImprimeFila(fila2);
        printf("Quantidade de elementos:%i\n",QuantidadeElementosFP(fila2));
    //busca binaria
    x = rand() % 10;
    printf("\n%i ta no vetor ?\n",x);
    printf("Vetor: " );
    for(i = 0; i < 10; i++){
        v[i] = i;
        printf("%i ",v[i]);
    }
    printf("\n");
    i = buscaBinaria(v,x,0,9);
    if(i) printf("Sim\n");
    else printf("Nao\n\n");

    //buscaMenorTrocaPrimeira
    printf("Fila random:");
    for(i = 0; i < 10; i++){
        v[i] = rand() % 1000;
        printf("%i ",v[i]);
    }
    printf("\n");
    printf("bMTP:");
    x = buscaMenorTrocaPrimeira(v,10);
    for(i = 0; i < 10; i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}
