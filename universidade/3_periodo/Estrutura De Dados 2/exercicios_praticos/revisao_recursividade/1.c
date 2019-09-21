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


//exercicio 1

int pesquisa(lista *prim, int *chave){
        if(prim == NULL) return 0;
        if(prim -> chave == *chave) return 1;
        return pesquisa(prim -> prox, chave);
}

//exercicio 1



int main(){
        srand(time(NULL));
        int chave;

        //gerando a lista
        lista *prim = NULL;
        for(int i = 0; i < 10; i++){
                inserelista(&prim, rand() % 200 + 1);
        }
        printf("Elementos na lista:\n");
        printalista(prim);

        printf("Digite uma chave para pesquisar na lista: ");
        scanf("%i",&chave);


        //chamada da funçao do exercicio
        if(pesquisa(prim,&chave)) printf("A chave pertence a lista!\n");
        else printf("A chave nao pertence a lista!\n");

}
