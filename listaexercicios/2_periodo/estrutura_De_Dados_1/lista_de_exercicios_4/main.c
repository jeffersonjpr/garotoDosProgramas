#include "bib.h"
#include <stdlib.h>
#include <stdio.h>

typedef int TipoChave;
typedef int TipoValor;


/*
struct TipoListaSimples{
	TipoChave chave;
	TipoValor valorQualquer;
	struct TipoListaSimples *prox;
};
*/

//programa para testar a blibioteca

//funcao para limpar o terminal
void clear(){
	system("clear");
}

//funcao para printar o menu
void menu(){
	printf("1 para inserir valor no inicio.\n");

	printf("Digite sua opcao:");

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

int main(){
	TipoListaSimples *no;
	int a,x,y;
	do{
		clear();
		menu();
		scanf("%i",&a);
		switch(a){
			case 1:
				x = lerv(1);
				y = lerv(0);
				insereInicioListaSimples(&no,x,y);
				break;
			default:
				break;
		}

	}while(a < 100);
}
