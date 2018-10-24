#include

/*
typedef struct celula_str {
    int chave; // Valor chave
    struct celula_str *prox; // Ponteiro para o proximo no
} TipoCelula;

typedef struct inicio_fim {
    TipoCelula *inicio; // Ponteiro para o inicio da fila ou pilha
    TipoCelula *fim; // Ponteiro para o fim da fila ou pilha
} InicioFim;
*/

// Recebe como parametro de entrada uma fila ou pilha x
// e cria um no cabeca em x.
int Cabeca(InicioFim *x);
int Vazia(InicioFim *x);
int InsereFila(InicioFim *f, int k);
int RemoveFila(InicioFim *f);
int FFVazia(InicioFim *f);
void ImprimeFila(InicioFim *f);
int InserePilha(InicioFim *p, int k);
int RetiraPilha(InicioFim *p);
int FPVazia(InicioFim *f);
void ImprimePilha(InicioFim *p);

// Lista de Exercicios de Fila e pilha

InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g);
InicioFim *ConcatenaFila(InicioFim *f, InicioFim *g);
InicioFim *ConcatenaFilaPilha(InicioFim *f. InicioFim *p);
InicioFim *ConcatenaPilhaFila(InicioFim *p, InicioFim *f);
int QuantidadeElementosFP(InicioFim *fp);
InicioFim *FilaInversa(InicioFim *f);
InicioFim *PilhaInversa(InicioFim *p);
InicioFim *FilaImparPar(InicioFim *p);
InicioFim *PilhaImparPar(InicioFim *p);
InicioFim *FilaParRemovidos(InicioFim *f);
InicioFim *PilhaImparRemovidos(InicioFim *p);
int SomaElementosFilha(InicioFim *p);
int ProdutoElementosPilha(InicioFim *p);

// Exercicio 14
int buscaSequencial(int *v, int k, int ini, int fim);
int buscaBinaria(int *v, int k, int ini, int fim);

// Exercicio 15
int buscaMaior(int *v, int n);
int buscaMenor(int *v, int n);
int buscaSomaPares(int *v, int n);
int buscaSomaImpares(int *v, int n);
int buscaMaiorPar(int *v, int n);
int buscaMaiorImpar(int *v, int n);
int buscaMenorTrocaPrimeira(int *v, int n);
int buscaMaiorTrocaUltima(int *v, int n);
