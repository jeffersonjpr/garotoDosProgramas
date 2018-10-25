#include "lib.h"
// Recebe como parametro de entrada uma fila ou pilha x
// e cria um no cabeca em x.

/*
minha funçao cabeça nao deixa inserir quando a fila/pilha
 nao esta vazia
As funçoes de impressao, imprimem em uma linha;
 */
int Cabeca(InicioFim *x){
    if(x == NULL) return 0;
    if(x -> inicio != NULL) return 0;
    TipoCelula *aux;
    aux = (TipoCelula*)malloc(sizeof(TipoCelula));
    if(aux == NULL) return 0;
    aux -> chave = -1;
    aux -> prox = NULL;
    x -> inicio = aux;
    x -> fim = aux;
    return 1;
}
// Recebe como parametro de entrada uma fila ou pilha x
// e verifica se x esta vazia.
int Vazia(InicioFim *x){
    if(x == NULL) return -1;
    if(x -> inicio == NULL) return 2;
    if(x -> inicio -> prox == NULL) return 1;
    return 0;
}

// Recebe como parametro de entrada uma fila f e um inteiro k.
// Insere um item na fila f com valor chave k.
int InsereFila(InicioFim *f, int k){
    if(f -> inicio == NULL || f -> fim == NULL){
        int x = Cabeca(f);
        if(!x) return 0;
    }
    TipoCelula *aux;
    aux = (TipoCelula*)malloc(sizeof(TipoCelula));
    if(aux == NULL) return 0;
    aux -> chave = k;
    aux -> prox = NULL;
    f -> fim -> prox = aux;
    f -> fim = aux;
    return 1;
}

// Recebe como parametro de entrada uma fila f.
// Remove um item da fila f.
int RemoveFila(InicioFim *f){

}

// Recebe como parametro de entrada uma fila f.
// Remove todos os itens da fila f.
int FFVazia(InicioFim *f){

}

// Recebe como parametro de entrada uma fila f.
// Imprime todos os elementos de f.
void ImprimeFila(InicioFim *f){
    if(f == NULL) return;
    if(f -> inicio == NULL) return;
    TipoCelula *aux = f -> inicio -> prox;
    while(aux != NULL){
        printf("%i ",aux -> chave);
        aux = aux -> prox;
    }
    printf("\n");
}

// Recebe como parametro de entrada uma pilha p e um inteiro k.
// Insere um item na pilha p com valor chave k.
int InserePilha(InicioFim *p, int k){
    if(p == NULL) return 0;
    if(p -> inicio == NULL || p -> fim == NULL){
        int xa = Cabeca(p);
        if(!xa) return 0;
    }
    TipoCelula *aux = NULL;
    aux = (TipoCelula*)malloc(sizeof(TipoCelula));
    if(aux == NULL) return 0;
    aux -> chave = k;
    aux -> prox = p -> fim;
    p -> fim = aux;
    return 1;
}

// Recebe como parametro de entrada uma pilha p.
// Remove um item da pilha p.
int RetiraPilha(InicioFim *p);

// Recebe como parametro de entrada uma pilha p.
// Remove todos os itens da pilha p.
int FPVazia(InicioFim *f);

// Recebe como parametro de entrada uma pilha p.
// Imprime todos os elementos de p.
void ImprimePilha(InicioFim *p){
    if(p == NULL) return;
    if(p -> inicio == NULL || p -> fim == NULL) return;
    TipoCelula *aux;
    aux = p -> fim;
    while(aux -> prox != NULL){
        printf("%i ",aux -> chave);
        aux = aux -> prox;
    }
    printf("\n");
}

// Lista de Exercicios de Fila e pilha

// Exercicio 1 *
InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g){

}

// Exercicio 2
InicioFim *ConcatenaFila(InicioFim *f, InicioFim *g){

}

// Exercicio 3
InicioFim *ConcatenaFilaPilha(InicioFim *f, InicioFim *p){

}

// Exercicio 4
InicioFim *ConcatenaPilhaFila(InicioFim *p, InicioFim *f){

}

// Exercicio 5 *
int QuantidadeElementosFP(InicioFim *fp){

}

// Exercicio 6
InicioFim *FilaInversa(InicioFim *f){

}

// Exercicio 7 *
InicioFim *PilhaInversa(InicioFim *p){

}

// Exercicio 8 *
InicioFim *FilaImparPar(InicioFim *p){

}

// Exercicio 9
InicioFim *PilhaImparPar(InicioFim *p){

}

// Exercicio 10
InicioFim *FilaParRemovidos(InicioFim *f){

}

// Exercicio 11
InicioFim *PilhaImparRemovidos(InicioFim *p){

}

// Exercicio 12
int SomaElementosFilha(InicioFim *p){

}

// Exercicio 13
int ProdutoElementosPilha(InicioFim *p){

}

// Exercicio 14-a
int buscaSequencial(int *v, int k, int ini, int fim){

}

// Exercicio 14-b *
int buscaBinaria(int *v, int k, int ini, int fim){

}

// Exercicio 15-a
int buscaMaior(int *v, int n){

}

// Exercicio 15-b
int buscaMenor(int *v, int n){

}

// Exercicio 15-c
int buscaSomaPares(int *v, int n){

}

// Exercicio 15-d
int buscaSomaImpares(int *v, int n){

}

// Exercicio 15-e
int buscaMaiorPar(int *v, int n){

}

// Exercicio 15-f
int buscaMaiorImpar(int *v, int n){

}

// Exercicio 15-g *
int buscaMenorTrocaPrimeira(int *v, int n){

}

// Exercicio 15-h
int buscaMaiorTrocaUltima(int *v, int n){

}
