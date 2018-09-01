#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct miguxos{
    char amigo[15];
}miguinho;

typedef struct arede{
    char nome[15];
    int namigos;
    miguinho *ponto;
}social;

int main(){
    social *mar;
    int n,i,j;
    printf("Digite o numero de usuarios:");
    scanf("%i",&n);
    mar = (social*)malloc(sizeof(social) * n);

    for(i = 0;i < n;i++){
        printf("usuario %i (nome/quantidade/amigos)\n",i+1);
        scanf("%s%i",&(mar + i) -> nome,&(mar + i) -> namigos);
        (mar + i) -> ponto = (miguinho*) malloc(sizeof(miguinho) * (mar + i) -> namigos);
        for(j = 0;j < (mar + i) -> namigos;j++){
            scanf("%s",(mar + i) -> ponto + j);
        }
    }
}
