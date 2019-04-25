#include "exercicio-binaria.h"
#include "travessia.h"
#include <stdlib.h>
#include <stdio.h>

/*
struct NoArvBinaria{
  int chave;
  struct NoArvBinaria * esq;
  struct NoArvBinaria * dir;
};

typedef struct NoArvBinaria NoArvBinaria;
*/

void preordem(NoArvBinaria *raiz){
        if(raiz == NULL) return;
        printf("%i ",raiz -> chave);
        preordem(raiz -> esq);
        preordem(raiz -> dir);
}

void emordem(NoArvBinaria *raiz){
        if(raiz == NULL) return;
        emordem(raiz -> esq);
        printf("%i ",raiz -> chave);
        emordem(raiz -> dir);
}

void posordem(NoArvBinaria *raiz){
        if(raiz == NULL) return;
        posordem(raiz -> esq);
        posordem(raiz -> dir);
        printf("%i ",raiz -> chave);
}

void contafolhas(NoArvBinaria *raiz,int *n){
        if(raiz == NULL) return;
        //se esq e direita = nulo, soma 1 no contador
        if(raiz -> esq == NULL && raiz -> dir == NULL){
                *n += 1;
                return;
        }
        contafolhas(raiz -> esq,n);
        contafolhas(raiz -> dir,n);
}

// procedimento emordem com alteraçao na ordem em que se percorre a arvore
void printadecrescente(NoArvBinaria *raiz){
        if (raiz == NULL) return;
        printadecrescente(raiz -> dir);
        printf("%i ",raiz -> chave);
        printadecrescente(raiz -> esq);
}
// ORDENA VETOR
NoArvBinaria *inserecomrep(NoArvBinaria **raiz, int k){
        if(*raiz == NULL){
                *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
                if( raiz == NULL) return NULL;
                (*raiz) -> chave = k;
                (*raiz) -> dir = (*raiz) -> esq = NULL;
                return *raiz;
        }
        if((*raiz) -> chave < k)
                return inserecomrep(&(*raiz) -> dir,k);
        return inserecomrep(&(*raiz) -> esq,k);
}
// vet = ponteiro do vetor
// n = tamanho

void ordenaVetABP(NoArvBinaria *raiz, int **vet){
        if (raiz == NULL) return;
        ordenaVetABP(raiz -> esq, vet);
        **vet = raiz -> chave;
        *vet += 1;
        ordenaVetABP(raiz -> dir, vet);
}
void nuke(NoArvBinaria **raiz){
        if(*raiz == NULL) return;
        nuke(&(*raiz) -> esq);
        nuke(&(*raiz) -> dir);

        free(*raiz);
        *raiz = NULL;
}
void ordenavetor(int *vet, int n){
        if (n <= 0) return;
        NoArvBinaria *aux = NULL;
        for(int i = 0; i < n; i++){
                inserecomrep(&aux,*(vet + i));
        }
        ordenaVetABP(aux, &vet);
        nuke(&aux);
}

// altura
int altura(NoArvBinaria *raiz){
        if (raiz == NULL) return 0;
        int esq, dir;
        esq = altura(raiz -> esq);
        dir = altura(raiz -> dir);
        return 1 + (esq > dir ? esq : dir);
}
void calculaaltura(NoArvBinaria *raiz){
        int k;
        if(raiz == NULL){
                k = -1;
        }
        else k = altura(raiz) - 1;
        printf("%i\n",k );
}

//contido
//verifica se r2 esta contido em r1
int verificaContido(NoArvBinaria *raiz, NoArvBinaria *raiz2){
        if (raiz2  == NULL) return 1;
        if(buscaArvBinRec(raiz, raiz2 -> chave) == NULL) return 0;
        if(verificaContido(raiz, raiz2 -> esq) == 0) return 0;
        if(verificaContido(raiz, raiz2 -> dir) == 0) return 0;
        return 1;
}
