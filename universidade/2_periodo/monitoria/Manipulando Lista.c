#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int chave;
	struct lista *prox;
}lista;

lista * alocano(int a){
	lista *aux;
	aux = (lista*)malloc(sizeof(lista));
	if(aux == NULL) return NULL;
	aux -> chave = a;
	aux -> prox = NULL;
	return aux;
}
void alocafim(int a,lista **list){
	if(*list == NULL){
		*list = alocano(a);
		return;
	}
	alocafim(a,&(*list)->prox);

}

void insereini(int a,lista **list){
	if(*list == NULL){
		*list = alocano(a);
	}
	else{
		lista *aux;
		aux = *list;
		*list = alocano(a);
		(*list) -> prox = aux;
		return;
	}
}
//remove o primeiro elemento que seja igual a chave
void terminate(lista **list,int a){
	if(*list == NULL){
		printf("Nao encontrado.");
		return;
	}
	if((*list) -> chave == a){
		lista *aux;
		aux = (*list) -> prox;
		free(*list);
		*list = aux;
		printf("%i Eliminado.",a);
		return;
	}
	terminate(&(*list) -> prox,a);
}
//printar a lista
void printa(lista *list){
	if(list == NULL) return;
	printf("%i ",list -> chave);
	if(list -> prox == NULL){
		return;
	}
	printa(list -> prox);
}

void busca(lista *list,int a){
	if(list == NULL){
		printf("Nao encontrado!");
		return;
	}
	if(list -> chave == a){
		printf("Elemento %i encontrado na lista.",a);
		return;
	}
	busca(list -> prox,a);
}

int main(){
	lista *list = NULL;
	int a,n=0;
	system("clear");
	while(n < 6){
		printf("\n\n1 adiciona no fim.\n2 adiciona no começo.\n3 printa lista.\n4 deletar elemento.\n5 busca.\n6 encerra program.\nDigite sua opcao:");
		scanf("%i",&n);
		if(n == 1){
			printf("Digite a chave para adicionar no fim:");
			scanf("%i",&a);
			alocafim(a,&list);
			system("clear");
		}
		if(n == 2){
			printf("Digite a chave para adicionar no comeco:");
			scanf("%i",&a);
			insereini(a,&list);
			system("clear");
		}
		if(n == 3){
			system("clear");
			printf("lista: ");
			printa(list);
		}
		if(n == 4){
			printf("Digite a chave a ser removida:");
			scanf("%i",&a);
			system("clear");
			terminate(&list,a);
		}
		if(n == 5){
			printf("Digite a chave que deseja buscar:");
			scanf("%i",&a);
			system("clear");
			busca(list,a);
		}
		setbuf(stdin,NULL);
	}


}
