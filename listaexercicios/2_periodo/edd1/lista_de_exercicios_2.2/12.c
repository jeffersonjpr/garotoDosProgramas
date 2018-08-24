#include <stdlib.h>
#include <stdio.h>

void concate(int *a,int *b,int *c){
    int maior=*a,i;
    char *bola;
    for(i = 0;i<(sizeof(a) / sizeof(int));i++){
        if(*(a + i) > maior) maior = *(a + i);
    }
    for(i = 0;i<(sizeof(b) / sizeof(int));i++){
        if(*(b + i) > maior) maior = *(b + i);
    }
    bola = malloc(sizeof(char) * (maior + 2));

    


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

    c = malloc(sizeof(int) * (n + (sizeof(a) / sizeof(int))))

    concate(a,b,c);
}
