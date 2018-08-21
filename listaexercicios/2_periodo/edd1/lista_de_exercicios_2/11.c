#include <stdio.h>
int main()
{
    char vetor[3] = {'A','B','C'};
    char *j = &vetor[0];
    char aux;

    /*
    aux = vetor[0];
    aux = *(vetor + 2);
    aux = *(j + 1);
    aux = *j;
    j = vetor + 1;
    aux = *j;
    aux = *(j + 1);
    */

    j = vetor;
    printf("j=%c,aux = %c\n\n",*j,aux);

    aux = *++j;
    printf("j=%c,aux = %c\n\n",*j,aux);

    aux = ++*j;
    printf("j=%c,aux = %c\n\n",*j,aux);

    printf("endereço que j aponta:%p\n",j);
    aux = *j++;
    printf("j=%c,aux = %c\n",*j,aux);
    printf("endereço que j aponta:%p\n\n",j);
    
    printf("%c\n",*(j-2));
    printf("%c\n",*(j-1));
    printf("\nAcesso ilegal ?: %c\n",*j);
    printf("Acesso ilegal ?: %c\n\n",vetor[3]);

    aux = *j;
    printf("j=%c,aux = %c\n",*j,aux);
    printf("endereço que j aponta:%p\n\n",j);
    return 0;
}
