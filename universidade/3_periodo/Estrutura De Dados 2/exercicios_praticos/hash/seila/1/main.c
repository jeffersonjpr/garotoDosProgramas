#include "lib.h"
#include "mt19937ar.h"

int main(void) {
    int ver = 0, chave = 0, i = 0, cod_hash = 0;
    hash tabela;
    ver = inicializa_tabela(tabela);
    if (ver == 1) printf("\n=>Tabela inicializada.\n");
    printf("\n=>Inserindo valores na tabela...\n");
    for (i = 0; i < N; i++) {
        insere_tabela(tabela, genrand_int32());
    }
    /*
    while(1 == 1){
        printf("\n=>Digite qual hash você deseja buscar(será printado toda a lista com essa hash, caso haja colisão: ");
        scanf("%d", &cod_hash);
        busca_hash(tabela, cod_hash);
    }*/

    for(i = 0; i < N; i++){
        if(tabela[i] != NULL){
            printf("%i | ",i);
            imprime_hash(tabela, i);
        }
    }
    return 0;
}
