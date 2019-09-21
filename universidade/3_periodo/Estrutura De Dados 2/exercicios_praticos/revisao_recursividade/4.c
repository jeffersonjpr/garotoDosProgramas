#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// exercicio 4
int pesquisavet(int *v,int chave, int n){
        if(n <= 0) return 0;
        if(*v == chave) return 1;
        if(n - 1 <= 0) return 0;
        return pesquisavet(v + 1, chave, n-1);
}
// exercicio 4
int main(){
        srand(time(NULL));
        int vet[10], chave;
        printf("Vetor:\n");
        for(int i = 0; i < 10; i++){
                vet[i] = rand() % 99 + 1;
                printf("%4.i ",vet[i]);
        }

        printf("\nDigite o elemento a ser pesquisado: ");
        scanf("%i",&chave);

        if(pesquisavet(vet, chave, 10)) printf("A chave pertence ao vetor!\n");
        else printf("A chave nao pertence ao vetor!\n");
}
