#include <stdio.h>
#include <stdlib.h>

#define M 160163
#define N 1000000
//M deve corresponder a 5>= N/M =<10, ou seja, um valor primo entre 100.000 e 200.000, 160.163 foi o escolhido
//N é 10^6, o valor total de chaves para o algoritmo

struct No {
    int chave;
    struct No *prox;
}
;typedef struct No no;
;typedef struct No *hash[M];//Ponteiro para a estrutura, facilita na implementação do vetor de ponteiros para estrutura

int inicializa_tabela(hash tabela);

int insere_tabela(hash tabela, int chave);

int funcao_espalhamento(int chave);

void busca_hash(hash tabela, int hash);

void imprime_hash(hash tabela, int hash);



