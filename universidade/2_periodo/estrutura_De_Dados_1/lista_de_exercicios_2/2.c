#include <stdio.h>

void main(){
    int i, *ptri;
    ptri = &i;
    *ptri = 0;
    printf("%i\n",*ptri);
}
