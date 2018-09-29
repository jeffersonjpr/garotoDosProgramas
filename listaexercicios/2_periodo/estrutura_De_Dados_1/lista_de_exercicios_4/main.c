#include "bib.h"
#include <stdlib.h>
#include <stdio.h>

// typedef int TipoChave;
// typedef int TipoValor;


/*
struct TipoListaSimples{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaSimples *prox;
};
*/

//programa para testar a blibioteca

//funcao para printar o menu
void menu(){
	printf("\n\n");
	printf("O programa possui 3 listas para teste.(1,2,3)\n");
	printf("(0) para imprimir a lista selecionada.\n");
	printf("(1) para inserir chave e valor no inicio da lista selecionada.\n");
	printf("(2) para atualizar o primeiro valor da lista selecionada.\n");
	printf("(3) para remover o primeiro no da lista selecionada.\n");
	printf("(4) para pesquisar um no dado uma chave na lista selecionada.\n");

	printf("Digite sua opcao e o numero da lista separado por espaços:");

}

//funcao para ler valores
int lerv(char i){
	int x;
	if(i){
		printf("Digite a chave:");
		scanf("%i",&x);
	}
	else{
		printf("Digite o valor:");
		scanf("%i",&x);
	}
	return x;
}
//funcao para printar lista
void printaov(TipoListaSimples *no){
	if(no == NULL) {
		printf("\n");
		return;
	}
	printf("Chave: %i Valor: %i\n",no -> chave,no -> valorQualquer);
	printaov(no -> prox);
}
int main(){
	TipoListaSimples *no1,*no2,*no3,*no4;
	no1 = no2 = no3 = no4 =NULL;
	int a,b,x,y;
	do{
		no4 = NULL;
		menu();
		scanf("%i%i",&a,&b);
		printf("\n\n");
		if(b < 1 || b > 3) continue;
		switch(a){
			case 0:
				printf("Lista %i:\n",b);
				if(b == 1) printaov(no1);
				else if(b == 2) printaov(no2);
				else printaov(no3);
				break;

			case 1:
				x = lerv(1);
				y = lerv(0);
				if(b == 1) no1 = insereInicioListaSimples(&no1,x,y);
				else if(b == 2) no2 = insereInicioListaSimples(&no2,x,y);
				else no3 = insereInicioListaSimples(&no3,x,y);
				printf("Valor inserido.\n");
				break;

			case 2:
				x = lerv(0);
				if(b == 1) atualizaValor(no1,x);
				else if(b == 2) atualizaValor(no2,x);
				else atualizaValor(no3,x);
				printf("Valor atualizado.\n");
				break;
			case 3:
				if(b == 1) removePrimeiroNo(&no1);
				else if(b == 2) removePrimeiroNo(&no2);
				else removePrimeiroNo(&no3);
				printf("Removido\n");
				break;
			case 4:
				x = lerv(1);
				if(b == 1) no4 = pesquisaNo(no1,x);
				else if(b == 2) no4 = pesquisaNo(no2,x);
				else no4 = pesquisaNo(no3,x);
				if(no4 != NULL){
					printf("\nEndereco encontrado:\n");
					printf("Local da memoria:%p\n",no4);
					printf("Chave: %i Valor: %i\n",no4 -> chave,no4 -> valorQualquer);
				}

			default:
				break;
		}
	}while(a < 100);
}
