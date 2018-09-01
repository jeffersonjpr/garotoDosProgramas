#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aln{
    int matricula;
    char nome[35];
    float nota[4];
}brick;

void maiornota(brick *curso,int n){
    int id[n],i,cont;
    float nota = -1.1;
    for(i = 0;i < n;i++){
        if((curso + i) -> nota[0] > nota){
            cont = 1;
            id[0] = i;
            nota = (curso + i) -> nota[0];
        }
        else if((curso + i) -> nota[0] == nota){
            id[cont++] = i;
        }
    }

    if(cont == 1){
        printf("%s foi o aluno com a maior nota na primeira prova\nNota:%.3f\n\n",(curso + id[0]) -> nome,nota);
    }
    else{
        printf("Maior nota na primeira prova: %.3f\nAlunos com a mesma nota:\n",nota);
        for(i = 0; i < cont; i++){
            printf("%s\n",(curso + id[i]) -> nome);
        }
        printf("\n");
    }

}

void maiormedia(brick *curso,int n){
    int id[n],i,cont;
    float nota = -1.1;
    for(i = 0;i < n;i++){
        if((curso + i) -> nota[3] > nota){
            cont = 1;
            id[0] = i;
            nota = (curso + i) -> nota[3];
        }
        else if((curso + i) -> nota[3] == nota){
            id[cont++] = i;
        }
    }

    if(cont == 1){
        printf("%s foi o aluno com a maior media \nMedia:%.3f\n\n",(curso + id[0]) -> nome,nota);
    }
    else{
        printf("Maior media: %.3f\nAlunos com a mesma media final:\n",nota);
        for(i = 0; i < cont; i++){
            printf("%s\n",(curso + id[i]) -> nome);
        }
        printf("\n");
    }

}

void menormedia(brick *curso,int n){
    int id[n],i,cont;
    float nota = 11.1;
    for(i = 0;i < n;i++){
        if((curso + i) -> nota[3] < nota){
            cont = 1;
            id[0] = i;
            nota = (curso + i) -> nota[3];
        }
        else if((curso + i) -> nota[3] == nota){
            id[cont++] = i;
        }
    }

    if(cont == 1){
        printf("%s foi o aluno com a menor media \nMedia:%.3f\n\n",(curso + id[0]) -> nome,nota);
    }
    else{
        printf("Menor media: %.3f\n Alunos com a mesma media final:\n",nota);
        for(i = 0; i < cont; i++){
            printf("%s\n",(curso + id[i]) -> nome);
        }
        printf("\n");
    }

}

int main(){
    int n,i,j;
    brick *curso;
    float aux;

    printf("Digite o numero de alunos:");
    scanf("%i",&n);

    curso = (brick*)malloc(sizeof(brick) * n);
    for(i = 0;i<n;i++){
        aux = 0;
        system("clear");
        printf("Digite a matricula do %i aluno:",i+1);
        scanf("%i",&(curso + i) -> matricula);
        printf("Digite o nome do %i aluno:",i+1);
        setbuf(stdin,NULL);
        fgets((curso + i) -> nome,35,stdin);
        strtok((curso + i) -> nome,"\n");
        for(j = 0;j < 3;j++){
            printf("Digite a %i nota: ",j+1);
            scanf("%f",&(curso + i) -> nota[j]);
            aux += (curso + i) -> nota[j];
        }
        //somando e calculando a media
        (curso + i) -> nota[3] = (aux / 3);
    }
    system("clear");
    maiornota(curso,n);
    maiormedia(curso,n);
    menormedia(curso,n);

    printf("Resultado final:\n");
    for(i = 0;i<n;i++){
        if((curso + i) -> nota[3] >= 6.0){
            printf("%35s Matricula:%i Media final:%.3f Aprovado\n",(curso + i) -> nome,(curso + i) -> matricula,(curso + i) -> nota[3]);
        }
        else{
            printf("%35s Matricula:%i Media final:%.3f Reprovado\n",(curso + i) -> nome,(curso + i) -> matricula,(curso + i) -> nota[3]);
        }

    }

}
