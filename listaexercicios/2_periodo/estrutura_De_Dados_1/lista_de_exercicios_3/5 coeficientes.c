#include <stdlib.h>
#include <stdio.h>


typedef struct coe{
    int coef,expt;
    char icg;
}poli;

int main(){
    int n,nn = 0,i,j=0;
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
        scanf("%c",&(velha +i) -> icg);
        if((velha +i) -> icg < 97) (velha +i) -> icg -= 32;
        printf("Digite o expoente do %i termo: ",i+1);
        scanf("%i",&(velha +i) -> expt);
    }


    nova = (poli*)malloc(sizeof(poli));
    nova -> coef = velha -> coef;
    nova -> expt = velha -> expt;
    nova -> icg = velha -> icg;

    for(i = 1;i <n;i++){
        if((nova + nn) -> icg == (velha + i) -> icg){
            if((nova + nn) -> expt == (velha + i) -> expt){
                nova -> coef += velha -> coef;
            }
            else j = 1;
        }
        else j = 1;

        if(j == 1){
            nova = (poli*) realloc(nova,sizeof(poli) * ++nn + 1);
            (nova + nn) -> coef = (velha + i) -> coef;
            (nova + nn) -> expt = (velha + i) -> expt;
            (nova + nn) -> icg = (velha + i) -> icg;
        }
    }


    for(i = 0;i<n;i++){
        printf("      %i ",(velha +i) -> expt)
    }
    printf("\n");
    for(i = 0;i<n;i++){
        printf("%i%c",(velha +i) -> coef,(velha +i) -> icg)
        if(i < n-1) printf(" + ");
    }
    printf("\n");

    for(i = 0;i<nn;i++){
        printf("      %i ",(nova +i) -> expt)
    }
    printf("\n");
    for(i = 0;i<nn;i++){
        printf("%i%c",(nova +i) -> coef,(nova +i) -> icg)
        if(i < nn-1) printf(" + ");
    }
    printf("\n");


}
