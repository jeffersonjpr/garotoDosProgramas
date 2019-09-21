#include <stdio.h>
#include <stdlib.h>
#include "mt19937ar.h"


typedef struct listae{
        unsigned int chave;
        struct listae *prox;
}listae;

listae *no[1000003];
int tamxx[1000003];

// seta todas as posições para null
void iniciando (int m, listae *no[]){
        for(int i = 0; i < m; i++){
                no[i] = NULL;
                tamxx[i] = 0;
        }
}

// funcao hash
int f_indice(unsigned int chave, int m){
        return chave % m;
}

//funcao de insersao
int insere(listae* no[], unsigned int chave, int m){
        //printf("check insere\n");
        int i = f_indice(chave, m);
        //printf("check insere %u | %i\n", chave, i);
        listae *aux;
        if(no[i] == NULL){
                no[i] = (listae*)malloc(sizeof(listae));
                if(no[i] == NULL) return -1;
                no[i] -> chave = chave;
                no[i] -> prox = NULL;
                return i;
                //printf("check21\n");
        }
        aux = no[i];
        while(aux -> prox != NULL) aux = aux-> prox;
        //printf("check22\n");

        aux -> prox = (listae*)malloc(sizeof(listae));
        if(aux -> prox == NULL) return -1;

        aux -> prox -> chave = chave;
        aux -> prox -> prox = NULL;
        //printf("check23\n");
        return i;
}

//printando
void printa(listae *no[], int m){
        listae *aux;
        for(int i = 0; i < m; i++){
                if(no[i] != NULL){
                        printf("%i |",i);
                        aux = no[i];
                        while (aux != NULL){
                                printf("%u ",aux -> chave);
                                aux = aux -> prox;
                        }
                        puts("");
                }
        }
}
void printa2(listae *no[], int i){
    listae *aux;

    printf("indice %i | ",i);
    aux = no[i];
    while (aux != NULL){
            printf("%u ",aux -> chave);
            aux = aux -> prox;
    }
    puts("");
}

int main(){
        /// TAMANHO PRIMO MAIOR QUE 1 MILHAO = 1000003
        int n = 1000000;
        int m = 1000003;
        int aux, auxm,auxm2,vazio;
        float flotaux = 0.0;


        //printf("Digite o tamanho (m) da tabela:");
        //scanf("%i",&m);

        // criando vetor de ponteiros
        //no = (listae**)malloc(sizeof(listae*) * m);
        //if(no == NULL){
        //    printf("Problema de alocação\n");
        //    return 0;
        //}


        iniciando(m, no);

        for(int i = 0; i < n; i++){
            aux = insere(no, (unsigned int)genrand_int32(), m);
            tamxx[aux] += 1;
        }

        //printa(no,m);

        printf("Tamanho da tabela 1000003 (numero primo maior que 10^6)\n");
        //listae *no[1000003];
        //int tamxx[1000003];

        //QUANTIDADE DE ESPAÇOS VAZIOS NA tabela
        auxm = auxm2 = 0;
        for(int i = 0; i < m; i++){
            if(tamxx[i] == 0) auxm += 1;
        }
        printf("Quantidade de espacos vazios :%i\n",auxm);
        vazio = auxm;

        //tamanho da maior listae
        auxm = auxm2 = 0;
        for(int i = 0; i < m; i++){
            if(tamxx[i] > auxm){
                auxm = tamxx[i];
                auxm2 = i;
            }
        }
        printf("Tamanho da maior lista :%i\n",auxm);
        printa2(no,auxm2);

        //quantidade de lista sem colisões
        auxm = auxm2 = 0;
        for(int i = 0; i < m; i++){
            if(tamxx[i] == 1) auxm += 1;
        }

        printf("Quantidade de listas sem colisoes: %i\n",auxm);

        //tamanho medio das listas
        auxm = auxm2 = 0;
        for(int i = 0; i < m; i++){
            auxm += tamxx[i];
        }
        printf("Tamanho medio das listas :%f\n",(float)auxm/(float)(1000000 - vazio));
}
