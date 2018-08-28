#include <stdlib.h>
#include <stdio.h>

float *media(float **matrix,int n,int nn){
    float *p,atual;
    int i,j;
    //malloca o vetor de notas (teste)
    p = (float*)malloc(sizeof(float) * n);
    if(p == NULL) return NULL;

    for(i = 0; i < n; i++){
        atual = 0;
        for(j = 0; j < nn; j++){
            atual += matrix[i][j];
        }
        p[i] = atual/nn;
    }
    return p;
}
 int main(){
     float **alunos,*notas;
     int i,j,na,nn;

     printf("Digite o numero de alunos:");
     scanf("%i",&na);
     printf("Digite o numero de notas:");
     scanf("%i",&nn);

     //mallocando matriz com ponteiro e atribuindo valores
     alunos = (float**)malloc(sizeof(float*) * na);
     if(alunos == NULL) return 0;
     for(i = 0; i < na; i++){
         alunos[i] = (float*)malloc(sizeof(float) * nn);
         if(alunos[i] == NULL) return 0;
         printf("Notas do %i aluno:\n",i+1);
         for(j = 0; j < nn; j++){
             printf("Digite a %i nota: ",j + 1);
             scanf("%f",&alunos[i][j]);
         }
     }

     //passando tudo pra funcao
     notas = media(alunos,na,nn);

     //apresentaçao
     printf("\n\n\n");
     for(i = 0; i < na; i++){
         printf("Notas do %i aluno: ",i+1);
         for(j = 0; j < nn; j++){
             printf("%.2f ",alunos[i][j]);
         }
         printf("  Media:%.2f\n",*(notas + i));
     }

     //free so pra treinar

     for(i = 0; i < na; i++){
         free(alunos[i]);
     }
     free(alunos);


 }
