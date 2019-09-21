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

//Fim lista simples


//exercicio 2
void printalista(lista *prim){
        if(prim == NULL){
                printf("\n");
                return;
        }
        printf("%4.i ",prim -> chave);
        printalista(prim -> prox);
}
//exercicio 2



int main(){
        srand(time(NULL));
        int chave,aux;

        //gerando a lista
        lista *prim = NULL;

        printf("Impressao para teste(nao recursiva)\n");
        for(int i = 0; i < 10; i++){
                aux = rand() % 200 + 1;
                inserelista(&prim, aux);
                printf("%4.i ",aux);
        }
        printf("\n");
        printf("Impressao recursiva :\n");
        printalista(prim);


}
