#include <stdio.h>

void main(){
    int mat[] = {1,2,3,4,5,6,7,8},*p,x;
    p = mat + 1;
    printf("%i\n",*p);
    x = (*mat)++;
    printf("%i\n",x);
    printf("%i\n",mat[0]);
}
