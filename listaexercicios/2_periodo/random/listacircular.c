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
No * insereini(No *no,int n){
	if(no == NULL){
		no = vazia(no,n);
		if(no == NULL) return NULL;
		no -> prox = no;
		return no;
	}
}

//insere fim
No * insereini(No *no,int n){
	if(no == NULL){
		no = alocano(n);
		if(no == NULL) return NULL;
		no -> prox = no;
		return no;
	}
}
int main(){
	No *no;

}
