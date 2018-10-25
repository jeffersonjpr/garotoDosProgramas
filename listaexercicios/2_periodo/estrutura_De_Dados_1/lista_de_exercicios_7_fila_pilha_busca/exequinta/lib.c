#include "header-lpb.h"

// Exercicio 1
InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g){
	if(g -> inicio -> prox == NULL) return f;
	InicioFim *aux = f;
	g -> fim -> prox = f -> inicio -> prox;
	f -> inicio -> prox = g -> inicio -> prox;
	free(g -> inicio);
	free(g);
	g = NULL;
	return f;
}

// Exercicio 5
int QuantidadeElementosFP(InicioFim *fp){
	if(fp -> inicio == NULL) return -1;
	InicioFim aux;
	aux.inicio = fp -> inicio -> prox;
	return 1 + QuantidadeElementosFP(&aux);
}

// Exercicio 7
InicioFim *PilhaInversa(InicioFim *p){

}

// Exercicio 8
InicioFim *FilaImparPar(InicioFim *p);

// Exercicio 14-b
int buscaBinaria(int *v, int k, int ini, int fim);

// Exercicio 15-g
int buscaMenorTrocaPrimeira(int *v, int n);
