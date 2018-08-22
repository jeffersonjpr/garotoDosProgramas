#include <string.h>
#include <stdio.h>

int compara (char comp[],char comp2[]){
    return strcmp(comp,comp2);
}
void concat(char conc[],char conc2[]){
    strcat(conc,conc2);
}
int lent (char lent2[]){
    return strlen(lent2);
}
/*
void duas(char a[],char b[]){
    printf("Digite a primeira string\n");
    fgets(a,200,stdin);
    printf("Digite a segunda string\n");
    fgets(b,100,stdin);
}

void uma(char a[]){
    printf("Digite a string\n");
    fgets(a,200,stdin);
}
*/
int main(){
    //__fpurge(stdin);
    int na = 1;
    char a[100],b[100];
    printf("seu creyxxon\n");
    fflush(stdin);
    while(na != 0){
        printf("1 para comparar,2 para concatenar,3 para calcular tamanho e 0 para sair:");
        scanf("%i",&na);
        /*
        switch(n){
            case 1:
                    duas(a,b);
                    printf("%i\n",compara(a,b));
                    break;
            case 2:
                    duas(a,b);
                    concat(a,b);
                    printf("%s\n",a);
                    break;
            case 3:
                    uma(a);
                    printf("%i\n",lent(a));
                    break;

        }
        */

    }
}


/*
Implemente um programa que possui as função:
Comparar duas strings em C
Concaternar duas strings em C
Calcular o tamanho de uma string em C
Cada função deve receber uma strings de entrada e fornecer um valor de saída.
Leia as entradas e imprima o resultado na tela.
Defina as suposições necessárias a cada código em forma de comentário
*/
