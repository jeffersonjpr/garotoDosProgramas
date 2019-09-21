#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int main(){
        srand(time(NULL));
        int vet[10], chave;
        printf("Vetor:\n");
        for(int i = 0; i < 10; i++){
                vet[i] = rand() % 99 + 1;
                printf("%4.i ",vet[i]);
        }

        printf("\n%i\n",11%2);
        printf("\n%i\n",10%2);
        printf("\n%i\n",12%2);
}
