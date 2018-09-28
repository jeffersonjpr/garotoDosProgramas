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
		printf("Nao encontrado\n");
		return;
	}
	if((*list) -> chave == a){
		lista *aux;
		aux = (*list) -> prox;
		free(*list);
		*list = aux;
		printf("%i TERMINATED.\n",a);
		return;
	}
	terminate(&(*list) -> prox,a);
}
//printar a lista
void printa(lista *list){
	if(list == NULL) return;
	printf("%i ",list -> chave);
	if(list -> prox == NULL){
		printf("\n");
		return;
	}
	printa(list -> prox);
}

int main(){
	lista *list = NULL;
	int a,n=0;
	while(n < 5){
		printf("1 fim 2 começo 3 printa 4 terminate 6 fim:");
		scanf("%i",&n);
		if(n == 1){
			printf("Digite a chave:");
			scanf("%i",&a);
			alocafim(a,&list);
		}
		if(n == 2){
			printf("Digite a chave:");
			scanf("%i",&a);
			insereini(a,&list);
		}
		if(n == 3){
			printa(list);
		}
		if(n == 4){
			printf("Digite a chave a ser removida:");
			scanf("%i",&a);
			terminate(&list,a);
		}
	}


}
