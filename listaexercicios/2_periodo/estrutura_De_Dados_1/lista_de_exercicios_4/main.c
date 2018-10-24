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
	printf("(0) para imprimir todas as listas.\n");
	printf("(1) para inserir chave e valor no inicio da lista selecionada.\n");
	printf("(2) para atualizar o primeiro valor da lista selecionada.\n");
	printf("(3) para remover o primeiro no da lista selecionada.\n");
	printf("(4) para pesquisar um no, dado uma chave, na lista selecionada.\n");
	printf("(5) para inserir no fim da lista selecionada.\n");
	printf("(6) para remover o ultimo no da lista selecionada.\n");
	printf("(7) para deletar um no, dado uma chave, na lista selecionada.\n");
	printf("(8) para deletar a lista selecionada.\n");
	printf("(9) para copiar a lista selecionada para a lista 3.\n");
	printf("(10) para fazer a intersecao das listas 1 e 2.(destino lista 3)\n");
	printf("(11) para remover o ultimo no da lista selecionada e adiciona-lo a lista 3\n");
	printf("(12) para tlansplantar o ultimo no da lista selecionada e adiciona-lo ao final da lista 3\n");
	printf("(13) para contar o numero de nos da lista selecionada.\n");
	printf("(14) para calcula a altura de um no, dado uma chave.\n");
	printf("(15) para calcula a profundidade de um no, dado uma chave.\n");
	printf("(42) para finalizar o programa.\n");

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
		if(a >= 0 && a != 10 && a != 0){
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
				printf("Lista 1:\n");
				printaov(no1);
				printf("Lista 2:\n");
				printaov(no2);
				printf("Lista 3:\n");
				printaov(no3);

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
				printf("Se possivel, removido.\n");
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

			case 10:
				liberaNos(&no3);
				no3 = intersecaoListas(no1,no2);
				printf("Intersecao pronta.\n");
				break;

			case 11:
				if(b == 1) insereRemove(&no3,&no1);
				else if(b == 2) insereRemove(&no3,&no2);
				else insereRemove(&no3,&no3);
				printf("Valor removido da lista selecionada e adicionado na lista 3\n");
				break;

			case 12:
				if(b == 1) transplantaNo(&no3,&no1);
				else if(b == 2) transplantaNo(&no3,&no2);
				printf("Ultimo no transplantado na lista 3\n");
				break;

			case 13:
				if(b == 1) printf("A lista 1 tem %i nos\n",contaNo(&no1));
				else if(b == 2) printf("A lista 2 tem %i nos\n",contaNo(&no2));
				else printf("A lista 3 tem %i nos\n",contaNo(&no3));
				break;

			case 14:
				x = lerv(1);
				if(b == 1) printf("Altura:%i\n",alturaNo(&no1,x));
				else if(b == 2) printf("Altura:%i\n",alturaNo(&no2,x));
				else printf("Altura:%i\n",alturaNo(&no3,x));
				break;

			case 15:
				x = lerv(1);
				if(b == 1) printf("Profundidade:%i\n",profundidadeNo(&no1,x));
				else if(b == 2) printf("Profundidade:%i\n",profundidadeNo(&no2,x));
				else printf("Profundidade:%i\n",profundidadeNo(&no3,x));
				break;

			default:
				break;
		}
	}while(a < 16);
}
