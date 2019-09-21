//Jefferson Michael de Azevedo Junior

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funçao do exercicio abaixo do bloco lista simples

//Lista simples
typedef struct lista{
        int chave;
        struct lista *prox;
}lista;

lista *alocano(int chave){
        lista *aux = (lista*)malloc(sizeof(lista));
        if(aux == NULL) return NULL;
        aux -> chave = chave;
        aux -> prox = NULL;
        return aux;
}

void inserelista(lista **prim,int chave){

        if(*prim == NULL){
                *prim = alocano(chave);
                return;
        }
        inserelista(&(*prim) -> prox,chave);
}

void nuke(lista **prim){
        if(*prim == NULL) return;
        nuke(&(*prim) -> prox);
        free(*prim);
        *prim = NULL;
}

void printalista(lista *prim){
        if(prim == NULL){
                printf("\n");
                return;
        }
        printf("%4.i ",prim -> chave);
        printalista(prim -> prox);
}
//Fim lista simples


//exercicio 3

void printainvertido(lista *prim){
        if(prim == NULL) return;
        printainvertido (prim -> prox);
        printf("%4.i ",prim -> chave);
}

//exercicio 3



int main(){
        srand(time(NULL));
        int chave;

        //gerando a lista
        lista *prim = NULL;
        for(int i = 0; i < 11; i++){
                inserelista(&prim, rand() % 200 + 1);
        }
        printf("Elementos em ordem de adiçao:\n");
        printalista(prim);

        printf("Elementos em ordem invertida:\n");
        printainvertido(prim);
        printf("\n");


}
