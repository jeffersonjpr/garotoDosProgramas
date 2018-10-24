#include "../bib.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void imprimeLista(TipoListaSimples *prim) {
    TipoListaSimples *aux = prim;

	if(aux == NULL) {
		printf("\nLista Vazia!");
        return;
	}

    do {
        printf("Valor => %d | Chave => %d\n", aux->valorQualquer, aux->chave);
        aux = aux->prox;
    } while(aux != NULL);
}

int main(void) {
    TipoListaSimples *lista = NULL, *no = NULL, *lista2 = NULL;
    int chave, i;

    puts("insereInicioListaSimples()");
    for(i = 0; i < 5; i++) {
        chave = rand() % 50;
        printf("Mandei inserir => %d\n", chave);
        insereInicioListaSimples(&lista, chave, -1);
    }

    imprimeLista(lista);
    puts("\n");

    puts("atualizaValor()");
    atualizaValor(lista, -2);
    imprimeLista(lista);

    puts("\n");

    puts("removePrimeiroNo()");
    removePrimeiroNo(&lista);
    imprimeLista(lista);

    puts("\n");

    no = pesquisaNo(lista, 3);

    printf("pesquisaNO => %p\n", no);
    insereFimListaSimples(&lista, 344, -2);

    puts("insereFimListaSimples() // 244");
    imprimeLista(lista);

    puts("removeUltimoNo()");
    removeUltimoNo(&lista);
    imprimeLista(lista);

    puts("removeNo() //3");
    removeNo(&lista, 3);
    imprimeLista(lista);

    puts("copiaListas()");
    lista2 = copiaListas(lista);
    imprimeLista(lista2);

    puts("intersecaoListas()");
    lista2 = intersecaoListas(lista, lista2);
    imprimeLista(lista);

    puts("insereRemove()");
    insereRemove(&lista, &lista2);
    imprimeLista(lista);
    imprimeLista(lista2);

    puts("transplantaNo");
    printf("lista\n");
    imprimeLista(lista);
    printf("lista2\n");
    imprimeLista(lista2);
    printf("tlansplante\n");
    transplantaNo(&lista, &lista2);
    printf("lista\n");
    imprimeLista(lista);
    printf("lista2\n");
    imprimeLista(lista2);

    puts("contaNo()");
    printf("n = %d\n", contaNo(&lista));

    puts("alturaNo()");
    printf("chave = 27 h = %d\n", alturaNo(&lista, 27));

    puts("profundidadeNo() //3");
    printf("chave = 33 p = %d\n", profundidadeNo(&lista, 33));
    imprimeLista(lista);

    puts(" liberaNos()");
    liberaNos(&lista);
    imprimeLista(lista);

    return 0;
}
