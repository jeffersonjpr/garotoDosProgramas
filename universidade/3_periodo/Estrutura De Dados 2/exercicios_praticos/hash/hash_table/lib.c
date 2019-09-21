#include "lib.h"

//Inicializa a tabela com todos os seus valores nulos. Caso após inserções continue nulo, a posição de tal hash está vazia
int inicializa_tabela(hash tabela) {
    int i = 0;
    for (i = 0; i < M; i++) {
        tabela[i] = NULL;
    }
    return 1;
}

//Insere um nó em um determinado local da tabela
int insere_tabela(hash tabela, int chave) {
    int hash_code = 0;
    hash_code = funcao_espalhamento(chave);
    no *novoNo = NULL;
	novoNo = (no*)malloc(sizeof(no));
	if (novoNo == NULL) return 0;
    else {
	    novoNo->chave = chave;
	    novoNo->prox = tabela[hash_code];
	    tabela[hash_code] = novoNo;
        return 1;
    }
}

//Cria os hash codes
int funcao_espalhamento(int chave) {
    return chave % M;
}

//Busca pelo elemento na tabela
void busca_hash(hash tabela, int hash) {
    if (hash < 0 || hash >= M) printf("\nEsta hash não se encontra na tabela.\n");//>= a M pois a hash possui indices de 0 até M-1
    else imprime_hash(tabela, hash);
}

//Imprime todos os elementos da lista que contenham a hash buscada
void imprime_hash(hash tabela, int hash) {
    no *hashAux = NULL;
    hashAux = tabela[hash];
    if (hashAux == NULL) printf("\nNão existem chaves nessa hash.\n");
    else {
        while (hashAux != NULL) {
            printf("->%d ", hashAux->chave);
            hashAux = hashAux->prox;
        }
        printf("\n");
    }
}
