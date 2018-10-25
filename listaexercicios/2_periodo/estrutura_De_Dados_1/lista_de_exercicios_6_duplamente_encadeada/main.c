#include "duplamente.h"
#include <stdlib.h>
#include <stdio.h>

void limpano(TipoListaEncadeada *prim){
	if(prim == NULL) return;
	limpano(prim -> prox);
	free(prim);
	prim = NULL;
}

void printar(TipoListaEncadeada *aux){
	if(aux == NULL) return;
	if(aux -> prox == NULL){
		printf("[%i,%i].\n",aux -> chave,aux -> valorQualquer);
		return;
	}
	printf("[%i,%i] ",aux -> chave,aux -> valorQualquer);
	printar(aux -> prox);
}


int main(){
	TipoListaEncadeada *aux,*aux2;
	int a = 0,chave,valor;
	aux = aux2 = NULL;
	while(a < 15){
		printf("1 insrir inicio\n");
		printf("2 insrir fim\n");
		printf("3 remove no chave\n");
		printf("4 copia lista\n");
		printf("5 printar\n");
		printf("opcao:");
		scanf("%i",&a);
		if(a == 1){
			printf("Insira chave: ");
			scanf("%i",&chave);
			printf("Insira Valor: ");
			scanf("%i",&valor);
			insereInicioListaEncadeada(&aux,chave,valor);
		}
		if(a == 2){
			printf("Insira chave: ");
			scanf("%i",&chave);
			printf("Insira Valor: ");
			scanf("%i",&valor);
			insereFimListaEncadeada(&aux,chave,valor);
		}
		if(a == 3){
			printf("Insira Chave: ");
			scanf("%i",&chave);
			removeNo(&aux,chave);
		}
		if(a == 4){
			limpano(aux2);
			aux2 = copiaLista3(aux);
		}
		if(a == 5){
			printf("\nLista 1: ");
			printar(aux);
			printf("Lista 2: ");
			printar(aux2);
			printf("\n");
		}
		if(a > 10) break;
	}
}
