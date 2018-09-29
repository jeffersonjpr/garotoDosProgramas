#include "bib.h"
typedef int TipoChave;
typedef int TipoValor;

struct TipoListaSimples{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaSimples *prox;
};
typedef struct TipoListaSimples TipoListaSimples;

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

//funcoes da biblioteca abaixo
TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim,TipoChave chave, TipoValor valor){
	if(*prim == NULL){
		*prim = alocano(chave,valor);
		if(*prim == NULL) return NULL;
	}
	else{
		TipoListaSimples *aux;
		aux = (*prim) -> prox;
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
void atualizaValor(TipoListaSimples *prim, TipoValor novoValor);
void removePrimeiroNo(TipoListaSimples **prim);
TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave);
TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim,TipoChave chave);
void removeUltimoNo(TipoListaSimples **prim);
void removeNo(TipoListaSimples **prim, TipoChave chave);
void liberaNos(TipoListaSimples **prim);
TipoListaSimples *copiaListas(TipoListaSimples *prim);
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1,TipoListaSimples *prim2);
void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2);
void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2);
int contaNo(TipoListaSimples **primLista1);
int alturaNo(TipoListaSimples **primLista1, TipoChave chave);
