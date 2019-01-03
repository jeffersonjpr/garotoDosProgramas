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

void insereinicio(No **prim,int a){
	if(*prim == NULL) {
		*prim = alocano(a);
	}
	else {
		No *aux = alocano(a);
		aux -> prox = *prim;
		*prim = aux;

	}
}

void inserefim(No **prim,int a){
	if(*prim == NULL) {
		*prim = alocano(a);
	}
	else{
		if((*prim) -> prox == NULL){
			No *aux = alocano(a);
			(*prim) -> prox = aux;
		}
		else{
			inserefim(&(*prim)->prox,a):
		}
	}
}


int main(){
	int i;
	No *a=NULL,*aux = NULL;
	// if(a == NULL) printf("Vazio\n");
	a = alocano(42);
	for(i = 0; i < 10; i++){
		inserefim(&a,i);
	}
	aux = a;
	while(aux != NULL){
		printf("%i\n",aux -> a);
		aux = aux -> prox;
	}
}
