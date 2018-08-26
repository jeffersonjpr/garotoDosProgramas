#include <stdlib.h>
#include <stdio.h>

void concate(int *a,int *b,int **c){
    int maior=*a,i,j = 0,tamc = (sizeof(a) / sizeof(int)); //duvida
    char *bola;

    //acha o maior elemento entre os dois conjuntos
    for(i = 0;i<(sizeof(a) / sizeof(int));i++){
        if(*(a + i) > maior) maior = *(a + i);
    }
    for(i = 0;i<(sizeof(b) / sizeof(int));i++){
        if(*(b + i) > maior) maior = *(b + i);
    }

    //aloca um vetor de char para ser usado como boleana
    bola = malloc(sizeof(char) * (maior + 2));

    //zera todos os elementos do vetor de char
    for(i = 0; i < sizeof(char) * (maior + 2);i++){
        *(bola + i) = 0;
    }

    // basicamente verifica repetiçoes
    for(i = 0;i<(sizeof(a) / sizeof(int));i++){
        if(!*(bola + *(a + i))) *(bola + *(a + i)) = 1;
    }
    // verifica o tamanhho do que sera o vetor c sem repetiçoes
    for(i = 0;i < (sizeof(b) / sizeof(int));i++){
        if(*(bola + *(b + i))) continue;
        else tamc++;
    }

    *c = malloc(sizeof(int) * (tamc + 1));
    printf("%i\n",sizeof(c) / sizeof(int));
    for(i = 0;i<(sizeof(a) / sizeof(int));i++){
        *(*c+i) = *(a + i);
    }

    for(i = (sizeof(a) / sizeof(int));i<tamc;i++){
        if(*(bola + *(b + i))) continue;
        else {
            *(*c+i) = *(b + j);
            j++;
        }
    }

}

int main(){
    int  *a,*b,*c,n,i;
    printf("Tamanho do Primeiro vetor : ");
    scanf("%d",&n);

    a = malloc(sizeof(int) * n);
    for(i = 0;i<n;i++) scanf("%i",a + i);

    printf("Tamanho do Segundo vetor : ");
    scanf("%d",&n);
    b = malloc(sizeof(int) * n);
    for(i = 0;i<n;i++) scanf("%i",b + i);

    // c = malloc(sizeof(int) * (n + (sizeof(a) / sizeof(int)))) ideia descontinuada
    concate(a,b,&c);

    for(i = 0;i < (sizeof(c) / sizeof(int));i++){
        printf("%i ",*(c+i));
    }
}
