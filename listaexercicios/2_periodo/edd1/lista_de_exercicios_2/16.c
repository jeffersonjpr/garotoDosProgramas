#include <stdio.h>
#include <stdlib.h>

double *max(double *a,int *size){
    int i,j = 0;

    if(a == NULL) return NULL;
    for(i = 0;i < *size;i++){
        if(*(a+i) > *(a+j)) j = i;
    }
    return a + j;
}

int main(){
    int size,i;
    double *vetor = NULL,*maior = NULL;
    scanf("%i",&size);
    vetor = malloc(sizeof(double) * size);
    if(vetor == NULL) return 0;
    for(i = 0;i < size;i++){
        scanf("%lf",vetor + i);
    }
    for(i = 0;i < size;i++){
        printf("%f\n",*(vetor + i));
    }
    maior = max(vetor,&size);
    printf("\n%x\n",maior);
    printf("\n%f\n",*maior);
}
