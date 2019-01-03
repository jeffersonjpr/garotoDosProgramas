#include "header-lpb.h"

// Exercicio 1
InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g){
    if(f == NULL) return NULL;
    if(g == NULL) return NULL;
    if(f -> fim -> prox == NULL) return g;
    if(g -> fim -> prox == NULL) return f;
    TipoCelula *aux = g -> fim;
    while(aux -> prox != g -> inicio) aux = aux -> prox;
    aux -> prox = f -> fim;
    f -> fim = g -> fim;
    g -> fim = g -> inicio;
    return f;
}

// Exercicio 5
int QuantidadeElementosFP(InicioFim *fp){
    int i,resp= 0;
	TipoCelula *aux;
	if(fp == NULL) return 0;
	if(fp -> inicio  == NULL || fp -> fim == NULL) return 0;
	if(fp -> inicio -> prox == NULL){
		aux = fp -> fim;
		while(aux -> prox != NULL){
			resp++;
			aux = aux -> prox;
		}
		return resp;
	}
	if(fp -> inicio -> prox != NULL){
		aux = fp -> inicio -> prox;
		while(aux != NULL){
			resp++;
			aux = aux -> prox;
		}
		return resp;
	}
	return resp;
}

// Exercicio 7
InicioFim *PilhaInversa(InicioFim *p){
    if(p == NULL) return NULL;
    if(p -> inicio == NULL) return NULL;
    InicioFim *aux;
    TipoCelula *cel = p -> fim;
    aux = (InicioFim*)malloc(sizeof(InicioFim));
    if (aux == NULL) return NULL;
    aux -> inicio = aux -> fim = NULL;
    Cabeca(aux);
    while(cel -> prox != NULL){
        InserePilha(aux,cel -> chave);
        cel = cel -> prox;
    }
    return aux;
}

// Exercicio 8
InicioFim *FilaImparPar(InicioFim *p){
    if(p == NULL) return NULL;
    if(p -> inicio == NULL) return NULL;
    if(p -> inicio -> prox == NULL) return NULL;
    InicioFim *aux;
    TipoCelula *cel = p -> inicio -> prox;
    aux = (InicioFim*)malloc(sizeof(InicioFim));
    if (aux == NULL) return NULL;
    aux -> inicio = aux -> fim = NULL;
    Cabeca(aux);
    while(cel != NULL){
        if(cel -> chave % 2 != 0) InsereFila(aux,cel -> chave);
        cel = cel -> prox;
    }
    cel = p -> inicio -> prox;
    while(cel != NULL){
        if(cel -> chave % 2 == 0) InsereFila(aux,cel -> chave);
        cel = cel -> prox;
    }
    return aux;
}

// Exercicio 14-b
int buscaBinaria(int *v, int k, int ini, int fim){
    if(k == v[(ini + fim)/2]) return 1;
    if(ini >= fim) return 0;
    if(k > v[(ini + fim)/2])
        return buscaBinaria(v,k,(ini + fim)/2 + 1,fim);
    return buscaBinaria(v,k,ini,(ini + fim)/2 - 1);
}

// Exercicio 15-g
int buscaMenorTrocaPrimeira(int *v, int n){
    int menor = v[0],i,aux;
    for(int i = 0; i < n; i++)
        if(v[i] <= menor){
            menor = v[i];
            aux = i;
    }
    i = v[0];
    v[0] = v[aux];
    v[aux] = i;
    return 1;
}
