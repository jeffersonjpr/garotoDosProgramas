#include <stdio.h>

void printaendereco(float *array){
    int i;
    for(i = 0;i<10;i++){
        printf("%i elemento: %p\n",i+1,array + i);
    }
}
void main(){
    float haha[10];
    printaendereco(haha);
}
