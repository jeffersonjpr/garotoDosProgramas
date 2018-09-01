#include <stdio.h>

void troca (int *i, int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
int main (){
    int a, b;
    a = 10;
    b = 100;
    printf("a = %i b = %i\n",a,b);
    troca(&a, &b);
    printf("a = %i b = %i\n",a,b);
    return 0;
}
