#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Site{
	char nome[25],link[35];
	int num_acessos, ativo;
}Tsite;


//calcula tamanho unido, sem repeticoes.
int tamanhosemrep(Tsite *site1, Tsite *site2,int tam1, int tam2){
	int tamtotal = tam1 + tam2,i,j;
	for(i = 0; i < tam1; i++){
		for(j = 0; j < tam2; j++){
			if(strcmp((site1 + i) -> nome,(site2 + j) -> nome) == 0){
				tamtotal--;
				break;
			}
		}
	}
	return tamtotal;
}

//calcula tamanho individual
int tamanho(FILE *dat){
	char auxn[30],auxs[30];
	int auxi,auxx,tamanho = 0;
	rewind(dat);
	while(fscanf(dat,"%s%s%i%i",auxn,auxs,&auxi,&auxx) != EOF){
		tamanho++;
	}

	return tamanho;
}

//em caso de incongluencias, a funcao da prioridade aos dados do primeiro arquivo
Tsite * uniao(Tsite *s1, int n1, Tsite*s2, int n2){
	int tamtotal,i,j,aux;
	Tsite *resp;
	tamtotal = tamanhosemrep(s1,s2,n1,n2);
	
	resp = (Tsite*)malloc(sizeof(Tsite)*tamtotal);
	if(resp == NULL) return NULL;
	
	//faz a atribuicao do primeiro vetor de struct
	for(i = 0; i < n1; i++){
		strcpy((resp + i) -> nome,(s1 + i) -> nome);
		strcpy((resp + i) -> link,(s1 + i) -> link);
		(resp + i) -> num_acessos = (s1 + i) -> num_acessos;
		(resp + i) -> ativo = (s1 + i) -> ativo;
	}
	aux = i;
	//faz a atribuicao do segundo vetor de struct
	for(i = 0; i < n2;i++){
		strcpy((resp + aux) -> nome,(s2 + i) -> nome);
		strcpy((resp + aux) -> link,(s2 + i) -> link);
		(resp + aux) -> num_acessos = (s2 + i) -> num_acessos;
		(resp + aux) -> ativo = (s2 + i) -> ativo;
		for(j = 0; j < aux; j++){
			if(strcmp((resp + j) -> nome,(resp + aux) -> nome) == 0) aux--;
		}
		aux++;
	}
	return resp;
	
}

//alocacao
Tsite * aloca(FILE *site,int n){
	Tsite *aux = (Tsite*)malloc(sizeof(Tsite) * n),auxi;
	int i = 0;
	rewind(site);
	for(i = 0; i < n; i++){
		fscanf(site,"%s%s%i%i",(aux + i) -> nome,(aux + i) -> link,&(aux + i) -> num_acessos,&(aux + i) -> ativo);
	}
	return aux;
}

int main(){
	FILE *site1,*site2,*saida;
	int tam1,tam2,i;
	Tsite *s1,*s2,*resp;
	
	//abrindo arquivos
	site1 = fopen("site1.dat","r");
	if(site1 == NULL) return 0;
	site2 = fopen("site2.dat","r");
	if(site2 == NULL) return 0;
	
	//registrando tamanhanhos individuais
	tam1 = tamanho(site1);
	tam2 = tamanho(site2);
	
	//atribuindo e alocando os vetores de struct
	s1 = aloca(site1,tam1);
	s2 = aloca(site2,tam2);
	
	
	
	//criando arquivo de uniao
	saida = fopen("saidasite.dat","w");
	if(saida == NULL) return 0;
	
	
	//chamando a funcao da prova
	resp = uniao(s1,tam1,s2,tam2);
	
	//printar e gravar no .dat
	for(i = 0; i < tamanhosemrep(s1,s2,tam1,tam2); i++){
		printf("%s %s %i %i\n",(resp + i) -> nome,(resp + i) -> link,(resp + i) -> num_acessos,(resp + i) -> ativo);
		fprintf(saida,"%s %s %i %i\n",(resp + i) -> nome,(resp + i) -> link,(resp + i) -> num_acessos,(resp + i) -> ativo);
	}
	
	//liberando
	free(s1);
	free(s2);
	free(resp);
	
	/*
	O programa funcina normalmente sem isso, mas quando eu tento fechar da algum erro estranho
	//fechando arquivos
	fclose(site1);
	fclose(site2);
	fclose(saida);
	*/
	
	return 0;
}

