#include <stdlib.h>
#include <stdio.h>

//struct
typedef struct No{
	int chave;
	struct No *prox;
}No;

No * alocano(int n){
	No *aux;
	aux = (No*)malloc(sizeof(No));
	if(aux == NULL) return NULL;
	aux -> chave = n;
	aux -> prox = NULL;
	return aux;
}
//insere inicio
No * insereini(No **no,int n){
	if(*no == NULL){
		*no = alocano(n);
		if(*no == NULL) return NULL;
		(*no) -> prox = *no;
		return *no;
	}
	No *aux;
	aux = alocano(n);
	if (aux == NULL) return *no;
	aux -> prox = (*no) -> prox;
	(*no) -> prox = aux;
	return *no;
}

//insere final
No * inserefim(No **no,int n){
	if(*no == NULL){
		*no = alocano(n);
		if(*no == NULL) return NULL;
		(*no) -> prox = *no;
		return *no;
	}
	No *aux;
	aux = alocano(n);
	if (aux == NULL) return *no;
	aux -> prox = (*no) -> prox;
	(*no) -> prox = aux;
	*no = aux;
	return *no;
}
//exibe a lista
void printar(No *no,No *aux){
	if(no == aux){
		printf("%i\n",aux -> chave);
		return;
	}
	printf("%i ",aux -> chave);
	printar(no,aux -> prox);
}

//buscar chave
void buscar(No *no,No *aux,int n){
	if(aux -> chave == n){
		printf("Elemento encontrado na lista!\n");
		return;
	}
	if(no == aux){
		printf("Elemento nao encontrado na lista!\n");
		return;
	}
	buscar(no,aux->prox,n);
}
int main(){
	No *no = NULL;
	int n,x;
	while(1 == 1){
		printf("1 inicio\n");
		printf("2 fim\n");
		printf("3 printar\n");
		printf("4 buscar\n");
		printf("Escolha opcao:");
		scanf("%i",&x);
		if(x > 10) break;
		if(x == 1){
			printf("Digite a chave:");
			scanf("%i",&n);
			no = insereini(&no,n);
			continue;
		}
		if(x == 2){
			printf("Digite a chave:");
			scanf("%i",&n);
			no = inserefim(&no,n);
			continue;
		}
		if(x == 3){
			printar(no,no->prox);
			continue;
		}
		if(x == 4){
			printf("Digite a chave:");
			scanf("%i",&n);
			buscar(no,no->prox,n);
			continue;
		}
	}
}
