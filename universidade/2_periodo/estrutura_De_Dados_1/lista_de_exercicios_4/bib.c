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
		// printf("Error 4242 Memoria ram insuficiente.\n");
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
			// printf("Error 4242 Memoria ram insuficiente.\n");
			*prim = aux;
			return *prim;
		}

		(*prim) -> prox = aux;
	}
	return *prim;
}

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor){
	if(prim == NULL){
		// printf("Lista vazia.\n");
		return;
	}
	prim -> valorQualquer = novoValor;
}

void removePrimeiroNo(TipoListaSimples **prim){
	TipoListaSimples *aux;
	if(*prim == NULL){
		// printf("Lista vazia\n");
		return;
	}
	aux = (*prim) -> prox;
	free(*prim);
	*prim = aux;

}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave){
	if(prim == NULL){
		// printf("Chave nao encontrada na lista\n");
		return NULL;
	}
	if(prim -> chave == chave){
		// printf("Chave encontrada!\n");
		return prim;
	}
	pesquisaNo(prim -> prox,chave);
}

//insere no final, com retorno ?????
void inserefimcerto(TipoListaSimples **prim,TipoChave chave, TipoValor valor){
	if(*prim == NULL){
		*prim = alocano(chave,valor);
		if(*prim == NULL){
			// printf("Error 4242 Memoria ram insuficiente.\n");
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
		// printf("Lista vazia.\n");
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
		// printf("Valor nao encontrado\n");
		return;
	}
	if((*prim)->chave == chave){
		removePrimeiroNo(&(*prim));
		// printf("No removido\n");
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
	if(aux == NULL) return 0;
	if(aux -> prox == NULL) return n;
	contaconta(aux -> prox,n+1);
}

TipoListaSimples *intersecaoListas(TipoListaSimples *prim1,TipoListaSimples *prim2){
	TipoListaSimples *aux1,*aux2,*aux3 = NULL;
	int n,i;
	if(prim1 == NULL || prim2 == NULL) return NULL;
	n = contaconta(prim1,1);
	aux1 = prim1;
	aux2 = prim2;
	for(i = 0; i< n; i++){
		aux2 = pesquisaNo(prim2,aux1 -> chave);
		if(aux2 != NULL){
			//if(aux2 -> valorQualquer == aux1 -> valorQualquer)
			//intersecao de um conjunto de elementos com duas variaveis, levando em consideracao apenas uma ?
				aux3 = insereFimListaSimples(&aux3,aux1 -> chave,aux1 -> valorQualquer);
				removeNo(&aux2,aux1->chave);
		}
		aux1 = aux1 -> prox;
	}
	return aux3;

}
void insereRemove(TipoListaSimples **primLista1,TipoListaSimples **primLista2){
	TipoListaSimples *aux;
	int auxi,auxj;
	if(*primLista2 == NULL) return;
	aux = *primLista2;
	while(aux -> prox != NULL){ //loop interessante, devia ter feito na funcao anterior
		aux = aux -> prox;
	}
	auxi = aux -> chave;
	auxj = aux -> valorQualquer;
	removeUltimoNo(&(*primLista2));
	insereFimListaSimples(&(*primLista1),auxi,auxj);

}
void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2){
	TipoListaSimples **aux = primLista1,*aux2=*primLista2,*aux3;
	if(*primLista2 == NULL) return;
	while(*aux != NULL) aux = &(*aux)-> prox;
	if(aux2 -> prox != NULL){
		while(aux2 -> prox != NULL) aux2 = aux2 -> prox;
		aux3 = aux2;
		aux2 = *primLista2;
		while(aux2 -> prox != aux3) aux2 = aux2 ->prox;
	}
	else{
		*aux = aux2;
		*primLista2 = NULL;
		return;
	}

	*aux = aux2 -> prox;
	aux2 -> prox = NULL;

}
int contaNo(TipoListaSimples **primLista1){
	if(*primLista1 == NULL) return 0;
	if((*primLista1) -> prox == NULL) return 1;
	return contaNo(&(*primLista1)->prox) + 1;
}

int alturaNo(TipoListaSimples **primLista1, TipoChave chave){
	TipoListaSimples *aux = *primLista1;
	if(*primLista1 == NULL) return -1;
	int n = 0;
	while(aux != NULL){
		if(aux -> chave == chave) break;
		aux = aux -> prox;
		}
	if(aux == NULL) return -1;
	aux = *primLista1;
	while(1 == 1){
		if(aux -> chave == chave){
			while(aux!= NULL){
				n++;
				aux = aux -> prox;
			}
			return n;
		}
		aux = aux -> prox;
	}
}
int profundidadeNo(TipoListaSimples **primLista1, TipoChave chave){
	TipoListaSimples *aux = *primLista1;
	int resp = 0;
	while(aux != NULL){
		if(aux -> chave == chave) break;
		aux = aux -> prox;
	}
	if(aux == NULL) return -1;
	aux = *primLista1;
	while(aux != NULL){
		resp++;
		if(aux-> chave == chave) return resp;
		aux = aux -> prox;
	}
}
