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

int compara(char *a,miguinho *b){
    int i;
    for(i = 0;i<15;i++){
        if(*(a + i) != b -> amigo[i]) return 0;
    }
    return 1;
}

int main(){
    social *mar;
    int n,i,j,k,pop;
    char a[15],b[15];
    printf("Digite o numero de usuarios:");
    scanf("%i",&n);
    mar = (social*)malloc(sizeof(social) * n);
    if(mar == NULL) return 0;
    for(i = 0;i < n;i++){
        printf("usuario %i (nome/quantidade/amigos)\n",i+1);
        scanf("%s%i",&(mar + i) -> nome,&(mar + i) -> namigos);
        (mar + i) -> ponto = (miguinho*) malloc(sizeof(miguinho) * (mar + i) -> namigos);
        if((mar + i) -> ponto == NULL) return 0;
        for(j = 0;j < (mar + i) -> namigos;j++){
            scanf("%s",(mar + i) -> ponto + j);
        }
    }
    printf("** popularidade **\n");
    for(i = 0; i < n;i++){
        pop = 0;
        for(j = 0;j < n;j++){
            if(i == j) continue;
            for(k = 0; k < (mar + j) -> namigos;k++){
                // a=(mar + i) -> nome;
                // b=(mar + j) -> ponto + k;
                if(compara((mar + i) -> nome,(mar + j) -> ponto + k)){
                    pop++;
                    break;
                }
            }
        }
        printf("%s %i\n",(mar + i) -> nome,pop);
    }
}
