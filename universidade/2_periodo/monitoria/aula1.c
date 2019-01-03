#include <stdlib.h>
#include <stdio.h>

typedef struct x{
	int a;
	struct x *prox;
}No;

No * alocano(int x){
	No *aux = (No*)malloc(sizeof(No));
	if(aux == NULL) return NULL;
	aux -> a = x;
	aux -> prox = NULL;
	return aux;
}
int main(){
	int i;
	No *a=NULL,*aux = NULL;
	if(a == NULL) printf("Vazio\n");
	a = alocano(42);
	aux = a;
	for(i = 1; i< 10; i++){
		aux -> prox = alocano(i);
		aux = aux -> prox;
	}

	for(aux = a; aux != NULL;aux = aux -> prox){
		printf("%i \n",aux -> a);
	}
}
