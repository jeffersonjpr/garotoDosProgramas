#include <stdio.h>
int main(void){
    int mat[3] = {5, 9 , 11};
    int *ptr;
    ptr = mat;
    printf("%d\n", *ptr + 1);   //6
    printf("%d\n", *(ptr + 1)); //9
    printf("%d\n", *(ptr));     //5
    printf("%d\n", *(ptr + 2)); //11
    return 0;
}
