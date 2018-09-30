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
	printf("Evite usar a lista 3, pois ela e usada nas funcoes que criam novas listas\n");

	printf("(-1) para limpar o terminal.\n");
	printf("(0) para imprimir a lista selecionada.\n");
	printf("(1) para inserir chave e valor no inicio da lista selecionada.\n");
	printf("(2) para atualizar o primeiro valor da lista selecionada.\n");
	printf("(3) para remover o primeiro no da lista selecionada.\n");
	printf("(4) para pesquisar um no, dado uma chave, na lista selecionada.\n");
	printf("(5) para inserir no fim da lista selecionada.\n");
	printf("(6) para remover o ultimo no da lista selecionada.\n");
	printf("(7) para deletar um no, dado uma chave, na lista selecionada.\n");
	printf("(8) para deletar a lista selecionada.\n");
	printf("(9) para copiar a lista selecionada(evite usar a 3!!).\n");

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
		printf("Digite a opcao:");
		scanf("%i",&a);
		if(a >= 0){
			printf("Digite a lista desejada(1,2,3):");
			scanf("%i",&b);
		}
		else b = 1;

		printf("\n\n\n");
		if(b < 1 || b > 3) continue;
		switch(a){
			case -1:
				system("clear");
				break;
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
			case 5:
				x = lerv(1);
				y = lerv(0);
				if(b == 1) no1 = insereFimListaSimples(&no1,x,y);
				else if(b == 2) no2 = insereFimListaSimples(&no2,x,y);
				else no3 = insereFimListaSimples(&no3,x,y);
				printf("Valor inserido.\n");
				break;
			case 6:
				if(b == 1) removeUltimoNo(&no1);
				else if(b == 2) removeUltimoNo(&no2);
				else removeUltimoNo(&no3);
				printf("Se possivel, removido.\n");
				break;

			case 7:
				x = lerv(1);
				if(b == 1) removeNo(&no1,x);
				else if(b == 2) removeNo(&no2,x);
				else removeNo(&no3,x);
				break;

			case 8:
				if(b == 1) liberaNos(&no1);
				else if(b == 2) liberaNos(&no2);
				else liberaNos(&no3);
				printf("Lista removida.\n");
				break;

			case 9:
				liberaNos(&no3);
				if(b == 1) no3 = copiaListas(no1);
				else if(b == 2) no3 = copiaListas(no2);
				// else no3 = copiaListas(no3); vazamento de memoria
				printf("Lista selecionada copiada para lista 3\n");
				break;

			default:
				break;
		}
	}while(a < 100);
}
