#include "duplamente.h"
#include <stdlib.h>

/*
struct TipoListaEncadeada{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaEncadeada *prox;
	struct TipoListaEncadeada *ant;
};
typedef struct TipoListaEncadeada TipoListaEncadeada;
*/
TipoListaEncadeada *alocano(TipoChave chave, TipoValor valor){
	TipoListaEncadeada *aux;
	aux = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));
	if(aux == NULL) return NULL;
	aux -> chave = chave;
	aux -> valorQualquer = valor;
	aux -> prox = NULL;
	aux -> ant = NULL;

}
TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor){
	if(*prim == NULL){
		*prim = alocano(chave,valor);
		return *prim;
	}
	TipoListaEncadeada *aux = *prim;
	*prim = alocano(chave,valor);
	if(prim == NULL) return aux;
	(*prim) -> prox = aux;
	aux -> ant = *prim;
	return *prim;
}

TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor){
	if(*prim == NULL){
		*prim = alocano(chave,valor);
		return *prim;
	}
	TipoListaEncadeada *aux = *prim;
	while(aux -> prox != NULL) aux = aux -> prox;
	aux -> prox = alocano(chave,valor);
	if(aux -> prox == NULL) return *prim;
	aux -> prox -> ant = aux;
	return *prim;

}

void removeNo(TipoListaEncadeada **prim, TipoChave chave){
	if(*prim == NULL) return;
	TipoListaEncadeada *aux = *prim;
	while(aux -> chave != chave){
		aux = aux -> prox;
		if(aux == NULL) break;
	}
	if(aux == NULL) return;
	if(aux -> prox == NULL && aux -> ant == NULL){
		free(*prim);
		*prim = NULL;
	}
	if(aux -> ant == NULL){
		*prim = aux -> prox;
		(*prim) -> ant = NULL;
		free(aux);
		return;
	}
	if(aux -> prox == NULL){
		aux = aux -> ant;
		free(aux -> prox);
		aux -> prox = NULL;
		return;
	}

	aux -> ant -> prox = aux -> prox;
	aux -> prox -> ant = aux -> ant;
	free(aux);
}

TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim){
	if(prim == NULL) return NULL;
	TipoListaEncadeada *aux = NULL;
	int i;
	for(i = 1; 1 == 1;i++){
		if(i % 3 == 0){
			aux = insereFimListaEncadeada(&aux,prim -> chave,prim -> valorQualquer);
		}
		if(prim -> prox == NULL) break;
		prim = prim -> prox;
	}
	return aux;
}
