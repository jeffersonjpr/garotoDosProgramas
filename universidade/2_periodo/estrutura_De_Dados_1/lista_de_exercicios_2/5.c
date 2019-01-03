#include <stdio.h>

void main(){
    int jump[] = {1,2,3,4,5,6,7,8};
    printf("%i\n",*(jump + 2));
    printf("%i\n",*(jump + 4));
    printf("%p\n",jump);
    printf("%p\n",jump + 1);
    printf("%p\n",jump + 2);
}

/*
(a) *(pulo + 2);
(b) *(pulo + 4);
(c) pulo + 4;
(d) pulo + 2;
*/
