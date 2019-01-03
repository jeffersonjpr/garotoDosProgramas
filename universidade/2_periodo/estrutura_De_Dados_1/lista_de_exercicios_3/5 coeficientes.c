#include <stdlib.h>
#include <stdio.h>


typedef struct coe{
    int coef,expt;
    char icg;
}poli;

int main(){
    int n,nn = 1,i,j=0;
    // n tamanho do vetor original, nn tamanho do vetor simplificado
    poli *velha,*nova;
    printf("Digite a quantidade de termos : ");
    scanf("%i",&n);
    if(n ==0) return 0;
    velha = (poli*)malloc(sizeof(poli) * n);
    if(velha == NULL) return 0;
    for(i = 0;i<n;i++){
        printf("Digite o coeficiente do %i termo: ",i+1);
        scanf("%i",&(velha +i) -> coef);
        printf("Digite a icognita do %i termo: ",i+1);
        scanf(" %c",&(velha +i) -> icg);
        if((velha +i) -> icg < 97) (velha +i) -> icg += 32;
        printf("Digite o expoente do %i termo: ",i+1);
        scanf("%i",&(velha +i) -> expt);
    }


    nova = (poli*)malloc(sizeof(poli));
    nova -> coef = velha -> coef;
    nova -> expt = velha -> expt;
    nova -> icg = velha -> icg;

    for(i = 1;i <n;i++){
        j = 0;
        if((nova + nn - 1) -> icg == (velha + i) -> icg){
            if((nova + nn - 1) -> expt == (velha + i) -> expt){
                (nova + nn - 1) -> coef += velha -> coef;
            }
            else j = 1;
        }
        else j = 1;

        if(j == 1){
            ++nn;
            nova = (poli*)realloc(nova,sizeof(poli) * nn);
            (nova + nn - 1) -> coef = (velha + i) -> coef;
            (nova + nn - 1) -> expt = (velha + i) -> expt;
            (nova + nn - 1) -> icg = (velha + i) -> icg;
        }
    }

    printf("\n\nEquacao original:\n");
    for(i = 0;i<n;i++){
        printf("%i%c^%i",(velha +i) -> coef,(velha +i) -> icg,(velha +i) -> expt);
        if(i < n-1) printf(" + ");
    }
    printf(" = 0\n");
    printf("\nEquacao simplificada:\n");
    for(i = 0;i<nn;i++){
        printf("%i%c^%i",(nova +i) -> coef,(nova +i) -> icg,(nova +i) -> expt);
        if(i < nn-1) printf(" + ");
    }
    printf(" = 0\n\n");

}
