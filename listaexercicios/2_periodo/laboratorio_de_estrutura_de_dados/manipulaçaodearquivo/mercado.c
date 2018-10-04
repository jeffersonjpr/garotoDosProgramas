#include <stdio.h>
#include <stdlib.h>

typedef struct merc{
	float preco;
	int id,quantidade;
	char nome[100];
}mercado;


void produtonovo(){
	FILE *arq;
	arq = fopen("lista.jpr","ab");
	if(arq == NULL) return;
	mercado aux;
	printf("Digite o id do produto:");
	scanf("%i",&aux.id);
	printf("Digite o preco do produto:");
	scanf("%f",&aux.preco);
	printf("Digite a quatidade do produto:");
	scanf("%i",&aux.quantidade);
	printf("Digite o nome do produto:");
	setbuf(stdin,NULL);
	fgets(aux.nome,100,stdin);

	fwrite(&aux,sizeof(mercado),1,arq);
	fclose(arq);

}

void printar(){
	FILE *arq;
	arq = fopen("lista.jpr","rb");
	if(arq == NULL) return;
	mercado aux;
	while(fread(&aux,sizeof(mercado),1,arq)){
		printf("\nId do produto:%i\n",aux.id);
		printf("Preco do produto:%.2f\n",aux.preco);
		printf("Quantidade do produto:%i\n",aux.quantidade);
		printf("Nome do produto:%s",aux.nome);
	}
	fclose(arq);
}

void calcularlucro(){
	FILE *arq;
	arq = fopen("lista.jpr","rb");
	if(arq == NULL) return;
	mercado aux;
	float lucro = 0;
	while(fread(&aux,sizeof(mercado),1,arq)){
		lucro += aux.preco * aux.quantidade;
	}
	printf("Lucro esperado:%.3f\n",lucro);
}

void buscar(){
	FILE *arq;
	arq = fopen("lista.jpr","rb");
	if(arq == NULL) return;
	mercado aux;
	int id;
	printf("Digite o id do produto:");
	scanf("%i",&id);
	system("clear");
	while(fread(&aux,sizeof(mercado),1,arq)){
		if(id == aux.id){
			printf("Produto encontrado no estoque.\n");
			printf("Id do produto:%i\n",aux.id);
			printf("Preco do produto:%.2f\n",aux.preco);
			printf("Quantidade do produto:%i\n",aux.quantidade);
			printf("Nome do produto:%s",aux.nome);
			return;
		}
	}
	printf("Produto nao esta no estoque.\n");
	fclose(arq);
}
int main(){
	int n = 0;

	while(n < 42){
		printf("\n(0) Para resetar o estoque");
		printf("\n(1) Adicionar novo produto.\n(2) mostrar todos os produtos\n");
		printf("(3) para pesquisar um produto no estoque.\n");
		printf("(4) Para calcular o lucro esperado.\n");
		scanf("%i",&n);
		if(n == 0){
			system("clear");
			system("rm lista.jpr");
			printf("Estoque resetado.\n");
		}
		if(n == 1){
			system("clear");
			produtonovo();
		}
		if(n == 2){
			system("clear");
			printar();
		}
		if(n == 3){
			system("clear");
			buscar();
		}
		if(n == 4){
			system("clear");
			calcularlucro();
		}
	}
}
