#include <stdlib.h>
#include <stdio.h>

//funcao de comparacao decrescente
int comp(int *a,int *b){
    return (*b - *a);
}
int decrescente(int *a,int * b,int *c){
    int vetor[] = {*a,*b,*c};
    qsort(vetor,3,sizeof(int),comp);
    *a = vetor[0];
    *b = vetor[1];
    *c = vetor[2];
    if((*a == *b) && (*b == *c)) return 1;
    else return 0;
}
int main(){
    int a,b,c,res;
    scanf("%i%i%i",&a,&b,&c);

    res = decrescente(&a,&b,&c);
    printf("%i %i %i\n",a,b,c);

    if(res) printf("Todos os valores sao iguais.\n");
    else printf("Ha valores diferentes.\n");
}
