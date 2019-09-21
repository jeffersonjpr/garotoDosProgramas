#include <stdio.h>
#include <stdlib.h>

typedef struct listae{
        unsigned int chave;
        struct listae *prox;
}listae;


void iniciando (int m, listae **no){

}
int main(){
        listae **no = NULL;
        int m;

        printf("Digite o tamanho (m) da tabela:");
        scanf("%i",&m);

        no = (listae**)malloc(sizeof(listae*) * m);

        listae no1,no2;
        no1.chave = 1;
        no1.prox = NULL;
        no2.chave = 2;
        no2.prox = NULL;
        *(no) = &no1;
        *(no + 1) = &no2;

        printf("%i %i\n",(*no) -> chave, (*no + 1) -> chave);
        printf("endereco da var:%p\n",&no1);
        printf("end1ºpos do vet:%p\n",*(no));
}
