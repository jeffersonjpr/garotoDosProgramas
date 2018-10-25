#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct filac{
    int chave;
    struct filac *prox;
}filac;

typedef struct ifila{
    filac *inicio;
    filac *fim;
}ifila;

//insersao
int inserefila(ifila *x, int k){
    if(x -> inicio == NULL || x -> fim == NULL){
        filac  *aux = NULL;
        aux = (filac*)malloc(sizeof(filac));
        if(aux == NULL) return -1;
        aux -> chave = -1;
        aux -> prox = NULL;
        x -> inicio = aux;
        x -> fim = aux;
    }
    filac *aux1;
    aux1 = (filac*)malloc(sizeof(filac));
    if(aux1 == NULL) return -1;
    aux1 -> chave = k;
    aux1 -> prox = NULL;
    x -> fim -> prox = aux1;
    x -> fim = aux1;
    return 1;
}

//remoçao fila
void proximo(ifila *x){
    if(x == NULL) return;
    if(x -> inicio == NULL) return;
    if(x -> inicio -> prox == NULL) return;
    filac *aux;
    aux = x ->inicio;
    x -> inicio = x -> inicio -> prox;
    free(aux);
}

//busca
filac *busca(ifila *x,int k){
    if(x == NULL) return NULL;
    if(x -> inicio == NULL) return NULL;
    filac *aux = x -> inicio -> prox;
    while(aux != NULL){
        if(aux -> chave == k) return aux;
        aux = aux -> prox;
    }
    return NULL;
}
//função para imprimir a fila
void printa(ifila *x){
    if(x == NULL) return;
    if(x -> inicio == NULL) return;
    filac *aux = x -> inicio -> prox;
    while(aux != NULL){
        printf("%i ",aux -> chave);
        aux = aux -> prox;
    }
    printf("\n");
}



int main(){
    srand(time(NULL));
    ifila *x = NULL;
    filac *aux = NULL;
    x = (ifila*)malloc(sizeof(ifila));
    x -> inicio = x -> fim = NULL;
    int i,xa,key;
    //inserindo
    for(i = 1; i <= 10; i++){
        xa = inserefila(x,i);
        if(xa == -1) break;
        printa(x);
    }
    //removendo
    for(i = 1; i <= 10; i++){
        proximo(x);
        printa(x);
    }
    //buscando
    key = rand() % 15;
    for(i = 1; i <= 10; i++){
        xa = inserefila(x,rand() % 15);
        if(xa == -1) break;
    }
    printf("%i Ta na fila ?\n",key);
    printf("Fila: ");
    printa(x);
    aux = busca(x,key);
    if(aux != NULL) printf("Resposta: Sim\n");
    else printf("Resposta: Nao\n");


}
