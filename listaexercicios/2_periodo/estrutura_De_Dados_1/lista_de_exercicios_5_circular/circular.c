#include "circular.h"
#include <stdlib.h>
/*
struct TipoListaCircular{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaCircular *prox;
};
*/

TipoListaCircular *alocano(int chave, int valor, TipoListaCircular *prox){
	TipoListaCircular *aux;
	aux = (TipoListaCircular*)malloc(sizeof(TipoListaCircular));
	if(aux == NULL) return prox;
	aux -> chave = chave;
	aux -> valorQualquer = valor;
	aux -> prox =  prox;
	return aux;
}

TipoListaCircular *insereInicioListaCircular(TipoListaCircular **prim, TipoChave chave, TipoValor valor){
	if(*prim == NULL){
		*prim = alocano(chave,valor,NULL);
		(*prim) -> prox = *prim;
		return *prim;
	}
	(*prim) -> prox = alocano(chave,valor,(*prim) -> prox);
	return *prim;
}

void removeNo(TipoListaCircular **prim, TipoChave chave){
	if(*prim == NULL) return;
	if(*prim == (*prim) -> prox && (*prim) -> chave == chave){
		free(*prim);
		*prim = NULL;
		return;
	}
	TipoListaCircular *aux = (*prim) -> prox,*aux2;
	//caso a chave seja o primeiro elemento da lista
	if(aux -> chave == chave){
		aux2 = aux -> prox;
		free(aux);
		(*prim) -> prox = aux2;
		return;
	}
	//caso a chave exista depois da primeira posiçao
		//este loop nao é infinito kkkk
	while(1 == 1){
		if(aux -> prox -> chave == chave){
			aux2 = aux -> prox -> prox;
			free(aux -> prox);
			aux -> prox = aux2;
			return;
		}
		if(aux == (*prim) -> prox) return;
		aux = aux -> prox;
	}
}

//funçao feita para auxiliar na copiaListaPar
void auxiliarcopia(TipoListaCircular *prim,TipoListaCircular **aux){
	if(prim == NULL) return;
	auxiliarcopia(prim -> prox,&(*aux));
	if(prim -> chave % 2 == 0) insereInicioListaCircular(&(*aux),prim -> chave, prim -> valorQualquer);
}

TipoListaCircular *copiaListaPar(TipoListaCircular *prim){
	TipoListaCircular *aux = prim -> prox,*resp = NULL;
	//transformei em lista normal, pra auxiliar na recursao.
	prim -> prox = NULL;
	auxiliarcopia(aux,&resp);
	prim -> prox = aux;
	return resp;
}
