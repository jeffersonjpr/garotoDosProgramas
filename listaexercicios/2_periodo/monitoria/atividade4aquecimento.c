#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int chave;
	struct lista *prox;
}lista;

lista *alocano(int chave, lista *prox){
	lista *aux;
	aux = (lista*)malloc(sizeof(lista));
	if(aux == NULL) return prox;
	aux -> chave = chave;
	aux -> prox =  prox;
	return aux;
}

lista *insereInicioListaCircular(lista **prim, int chave){
	if(*prim == NULL){
		*prim = alocano(chave,NULL);
		(*prim) -> prox = *prim;
		return *prim;
	}
	(*prim) -> prox = alocano(chave,(*prim) -> prox);
	return *prim;
}

void simples(int chave, lista *aux){
	if(aux == NULL) {
		aux = (lista*)malloc(sizeof(lista));
		aux -> chave = chave;
		aux -> prox = NULL;
		return;
	}
	simples(chave,aux -> prox);
}

int verificalista(lista *p){
	if(p == NULL) return 1;
	lista *aux = p -> prox;
	while(aux != p){
		if(aux == NULL) return 1;
		aux = aux -> prox;
	}
	return 0;
}
int main(){
	lista *um,*dois;
	int a = 1,b = 1;
	um = dois = NULL;
	um = insereInicioListaCircular(&um,2);
	um = insereInicioListaCircular(&um,3);
	um = insereInicioListaCircular(&um,4);
	simples(1,dois);
	simples(2,dois);
	simples(3,dois);
 	a = verificalista(um);
	if(a) printf("Simples\n");
	else printf("Circular\n");
 	b = verificalista(dois);
	if(b) printf("Simples\n");
	else printf("Circular\n");
}
