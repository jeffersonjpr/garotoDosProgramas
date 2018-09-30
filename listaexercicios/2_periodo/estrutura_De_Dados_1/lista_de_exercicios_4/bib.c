#include "bib.h"
#include <stdlib.h>
#include <stdio.h>

// typedef int TipoChave;
// typedef int TipoValor;
//
// struct TipoListaSimples{
// 	TipoChave chave;
// 	TipoValor valorQualquer;
// 	struct TipoListaSimples *prox;
// };
// typedef struct TipoListaSimples TipoListaSimples;

//funcao de alocaçao
TipoListaSimples * alocano(int chave,int valor){
	TipoListaSimples *aux;
	aux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
	//verifica se foi possivel alocar
	if(aux == NULL){
		printf("Error 4242 Memoria ram insuficiente.\n");
		return NULL;
	}
	aux -> chave = chave;
	aux -> valorQualquer = valor;
	aux -> prox = NULL;
	return aux;
}

//funcoes da biblioteca, abaixo.

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim,TipoChave chave, TipoValor valor){
	TipoListaSimples *aux;
	if(*prim == NULL){
		*prim = alocano(chave,valor);
		if(*prim == NULL) return NULL;
	}
	else{
		aux = *prim;
		*prim = alocano(chave,valor);

		//verifica se foi possivel alocar
		//se nao foi possivel ele "devolve" o conteudo de aux
		//pra *prim, para que nao haja vazamento de memoria
		if(*prim == NULL){
			printf("Error 4242 Memoria ram insuficiente.\n");
			*prim = aux;
			return *prim;
		}

		(*prim) -> prox = aux;
	}
	return *prim;
}

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor){
	if(prim == NULL){
		printf("Lista vazia.\n");
		return;
	}
	prim -> valorQualquer = novoValor;
}

void removePrimeiroNo(TipoListaSimples **prim){
	TipoListaSimples *aux;
	if(*prim == NULL){
		printf("Lista vazia\n");
		return;
	}
	aux = (*prim) -> prox;
	free(*prim);
	*prim = aux;

}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave){
	if(prim == NULL){
		printf("Chave nao encontrada na lista\n");
		return NULL;
	}
	if(prim -> chave == chave){
		printf("Chave encontrada!\n");
		return prim;
	}
	pesquisaNo(prim -> prox,chave);
}

//insere no final, com retorno ?????
void inserefimcerto(TipoListaSimples **prim,TipoChave chave, TipoValor valor){
	if(*prim == NULL){
		*prim = alocano(chave,valor);
		if(*prim == NULL){
			printf("Error 4242 Memoria ram insuficiente.\n");
			return;
		}
		return;
	}
	inserefimcerto(&(*prim) -> prox,chave,valor);
}
TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim,TipoChave chave, TipoValor valor){
	inserefimcerto(prim,chave,valor);
	return *prim;
}

void removeUltimoNo(TipoListaSimples **prim){
	if(*prim == NULL){
		printf("Lista vazia.\n");
		return;
	}
	if((*prim)->prox == NULL){
		free(*prim);
		*prim = NULL;
		return;
	}
	removeUltimoNo(&(*prim) -> prox);
}
void removeNo(TipoListaSimples **prim, TipoChave chave){
	if(*prim == NULL){
		printf("Valor nao encontrado\n");
		return;
	}
	if((*prim)->chave == chave){
		removePrimeiroNo(&(*prim));
		printf("No removido\n");
		return;
	}
	removeNo(&(*prim)->prox,chave);
}
void liberaNos(TipoListaSimples **prim){
	if(*prim == NULL) return;
	liberaNos(&(*prim)->prox);
	free(*prim);
	*prim = NULL;
}

void copiaListasAux(TipoListaSimples **aux,TipoListaSimples *prim){
	if(prim != NULL){
		*aux = alocano(prim -> chave,prim -> valorQualquer);
	}
	else return;
	copiaListasAux(&(*aux) -> prox,prim -> prox);
}
TipoListaSimples *copiaListas(TipoListaSimples *prim){
	TipoListaSimples *aux;
	copiaListasAux(&aux,prim);
	return aux;
}
int contaconta(TipoListaSimples *aux,int n){
	if(aux -> prox == NULL) return n;
	contaconta(aux,n+1);
}
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1,TipoListaSimples *prim2){
	TipoListaSimples *aux,*aux1,*aux2;
	if(prim1 == null)
	int n;

}
// void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2);
// void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2);
// int contaNo(TipoListaSimples **primLista1);
// int alturaNo(TipoListaSimples **primLista1, TipoChave chave);
