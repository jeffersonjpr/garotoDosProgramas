// Cabecalho para a Lista de Exercicios de Fila e Pilha
// Aleffer Rocha, 16 de outubro de 2018

#ifndef _H_FILA_PILHA_
#define _H_FILA_PILHA_

#include <stdio.h>
#include <stdlib.h>

#ifndef _S_NO_
#define _S_NO_

typedef struct celula_str {
    int chave; // Valor chave
    struct celula_str *prox; // Ponteiro para o proximo no
} TipoCelula;

typedef struct inicio_fim {
    TipoCelula *inicio; // Ponteiro para o inicio da fila ou pilha
    TipoCelula *fim; // Ponteiro para o fim da fila ou pilha
} InicioFim;

#endif

// Exercicio 1
InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g);

// Exercicio 5
int QuantidadeElementosFP(InicioFim *fp);

// Exercicio 7
InicioFim *PilhaInversa(InicioFim *p);

// Exercicio 8
InicioFim *FilaImparPar(InicioFim *p);

// Exercicio 14-b
int buscaBinaria(int *v, int k, int ini, int fim);

// Exercicio 15-g
int buscaMenorTrocaPrimeira(int *v, int n);


#endif
