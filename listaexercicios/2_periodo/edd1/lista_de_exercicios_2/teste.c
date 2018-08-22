#include <stdio.h>
#include <stdlib.h>

int main(){
    double *a;
    int size;
    scanf("%i",&size);
    a = malloc(sizeof(double) * size);
    for(int i = 0;i<size;i++){
        scanf("%f",a+i);
    }
    for(int i = 0;i<size;i++){
        printf("%f\n",*(a + i));
    }

}
