#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno{
	char disciplina [30];
	int ra;
	float *n;	
} TipoALuno;

float *aloca_notas(int qtde){
	float *n;
	n = (float*)malloc(sizeof(float) * qtde);
	if (n == NULL) return NULL;
	return n;
}

TipoALuno *aloca_alucos(int tam, int qtde){
	int i;
	TipoALuno *paodequeijo;
	paodequeijo = (TipoALuno*)malloc(sizeof(TipoALuno) * tam);
	if (paodequeijo == NULL) return NULL;
	for(i = 0; i < tam; i++){
		(paodequeijo + i) -> n = (float*)malloc(sizeof(float) * qtde);
		if((paodequeijo + i) -> n == NULL) return NULL;
	}
	return paodequeijo;
}


TipoALuno *desaloca_alunos(int tam,TipoALuno *p){
		int i;
		for(i = 0; i < tam; i++){
			free((p + i) -> n);
		}
		free(p);
		return NULL;
}



int main(){
	int tam,qtde;
	TipoALuno *p;
	scanf("%i%i",&tam,&qtde);
	p = aloca_alucos(tam,qtde);
	p = desaloca_alunos(tam,p);

}


