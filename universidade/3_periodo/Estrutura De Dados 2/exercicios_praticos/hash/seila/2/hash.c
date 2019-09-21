#include <stdio.h>
#include <stdlib.h>

typedef struct listae{
        unsigned int chave;
        struct listae *prox;
}listae;

// seta todas as posições para null
void iniciando (int m, listae **no){
        for(int i = 0; i < m; i++){
                *(no + i) = NULL;
        }
}

// funcao hash
int f_indice(unsigned int chave, int m){
        return (int)chave % m;
}

//funcao de insersao
void insere(listae* no[], unsigned int chave, int m){
        int i = f_indice(chave, m);
        listae *aux;
        if(no[i] == NULL){
                no[i] = (listae*)malloc(sizeof(listae));
                no[i] -> chave = chave;
                no[i] -> prox = NULL;
                return;
        }
        aux = no[i];

        while(aux -> prox != NULL) aux = aux-> prox;

        aux -> prox = (listae*)malloc(sizeof(listae));
        aux -> prox -> chave = chave;
        aux -> prox -> prox = NULL;

}

//printando
void printa(listae *no[], int m){
        listae *aux;
        for(int i = 0; i < m; i++){
                if(no[i] != NULL){
                        printf("%i |",i);
                        aux = no[i];
                        while (aux != NULL){
                                printf("%i ",aux -> chave);
                                aux = aux -> prox;
                        }
                        puts("");
                }
        }
}

int main(){
        listae **no = NULL;
        int m;

        printf("Digite o tamanho (m) da tabela:");
        scanf("%i",&m);

        // criando vetor de ponteiros
        no = (listae**)malloc(sizeof(listae*) * m);
        if(no == NULL) return 0;

        printf("chek 1\n" );
        iniciando(m, no);
        printf("chek 2\n" );

        insere(no, 1, m);
        insere(no, 2, m);
        insere(no, 3, m);
        insere(no, 321312323, m);
        insere(no, 10, m);
        printf("chek 3\n" );
        printa(no, m);

}
