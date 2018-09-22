#include <bits/stdc++.h>
using namespace std;

typedef struct no arvore;
struct no{
	int n;
	arvore *e,*d;
};

void maloca(int n, arvore *tree){
	tree = (arvore*)malloc(sizeof(arvore));
	tree -> n = n;
	tree -> e = tree -> d = NULL;
}
void insere(int n,arvore *tree){
	if(tree == NULL) maloca(n,tree);
	else{
		if(n >= tree -> n) maloca(n,tree -> d);
		else maloca(n,tree -> e);
	}
}

void prima(arvore *tree){
	if(tree == NULL) printf("raiz\n");
	else{
		printf("%i\n",tree -> n);
		prima(tree -> e);
		prima(tree -> d);
	}

}

int main(){
	int resp,aux;
	arvore *tree = NULL;
	while(true){
		printf("1 para inserir\n");
		printf("2 para printar\n");
		printf("0 para sair\n");
		printf("Digite sua opcao: ");
		scanf("%i",&resp);

		if(resp == 1){
			printf("Digite o numero para inserir:");
			scanf("%i",&aux);
			insere(aux,tree);
			continue;
		}
		if(resp == 2){
			prima(tree);
			continue;
		}
		else break;
	}
}
