#include "circular.h"
#include <stdlib.h>
#include <stdio.h>

void printar(TipoListaCircular *no,TipoListaCircular *aux){
	if(no == aux){
		printf("[%i,%i].\n",aux -> chave,aux -> valorQualquer);
		return;
	}
	printf("[%i,%i] ",aux -> chave,aux -> valorQualquer);
	printar(no,aux -> prox);
}

void breakfast(TipoListaCircular *aux){
	if(aux == NULL) return;
	breakfast(aux -> prox);
	free(aux);
}

int main(){
	TipoListaCircular *aux,*aux2,*aux3;
	aux = aux2 = NULL;
	int n,chave,valor;
	while(1 == 1){
		printf("1 para adicionar no inicio.\n");
		printf("2 para remover dado a chave.\n");
		printf("3 para printar.\n");
		printf("Digite opcao:");
		scanf("%i",&n);
		if(n == 1){
			printf("Digite a chave:");
			scanf("%i",&chave);
			printf("Digite a valor:");
			scanf("%i",&valor);
			insereInicioListaCircular(&aux,chave,valor);
		}
		if(n == 2){
			printf("Digite a chave:");
			scanf("%i",&chave);
			removeNo(&aux,chave);
		}
		if(n == 3){
			if(aux != NULL){
				printf("Lista 1: ");
				printar(aux,aux -> prox);
			}
			if(aux2 != NULL){
				printf("Lista 2: ");
				printar(aux2,aux2 -> prox);
			}
		}
		if(n > 10) break;
		if(aux2 != NULL){
			aux3 = aux2 -> prox;
			aux2 -> prox = NULL;
			breakfast(aux3);
		}
		aux2 = copiaListaPar(aux);
	}
}
