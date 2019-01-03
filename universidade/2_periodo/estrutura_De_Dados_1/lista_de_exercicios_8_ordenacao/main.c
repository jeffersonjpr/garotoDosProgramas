#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printavetor(int *v,int n){
    int i;
    for(i = 0; i < n; i++) printf("%3.1i ",*(v + i));
    printf("\n");
}

int verificasorteio(int *v,int ini,int n){
    int i;
    for(i = ini; i < n - 1; i++){
        if(v[i] > v[i+1]){
            printf("No intervalo [%i <= i <= %i] o vetor esta ordenado incorretamente!\n",ini,n - 1);
            return 0;
        }
    }
    printf("No intervalo [%i <= i <= %i] o vetor esta ordenado corretamente!\n",ini,n - 1);
    return 1;
}

void indice(int n){
    int i;
    for(i = 0; i < n; i++) printf("%3.1i ",i);
    printf("\n");
}
void sorteio(int *n,int *ini,int *fim){
    *n = rand()%15+3;
    *ini = rand()%((*n)/2);
    do{ *fim = rand()%(*n); } while(*fim <= *ini);
}
int main(){
    srand(time(NULL));
    int *v,i,x = 10,y=10,n,ini,fim;
    x = rand()%90 + 9;
    y = rand()%90 - 90;


    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n BubbleSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    BubbleSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n SelectionSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    SelectionSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n InsertionSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    InsertionSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n QuickSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    QuickSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n ShellSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    ShellSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n QuickSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    QuickSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

    sorteio(&n,&ini,&fim); //sort vetor
    v = malloc(sizeof(int) * n); // sort vetor

    printf("\n MergeSort:\n");
    for(i = 0; i < n; i++) v[i] = rand()%x+y;
    printavetor(v,n);
    MergeSort(v,ini,fim);
    printavetor(v,n);
    indice(n);
    verificasorteio(v,ini,fim + 1);
    free(v);

}
