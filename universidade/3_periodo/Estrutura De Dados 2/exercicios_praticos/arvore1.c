#include <stdio.h>
#include <stdlib.h>

//Acho que foi a primeira arvore que eu tentei fazer, nao sei se ta funcionando
typedef struct abp{
	int chave;
	struct abp *esq,*dir;
}abp;

int abpsearch(abp *no, int chave){
	if(no == NULL) return 0;
	if(no -> chave == chave) return 1;
	if(chave > no -> chave) return abpsearch(no -> dir,chave);
	return abpsearch(no -> esq,chave);
}

void insere(abp **no, int chave){
	if(*no == NULL){
		(*no) = (abp*)malloc(sizeof(abp));
		if(*no == NULL) return; //verificando se conseguiu alocar
		(*no) -> chave = chave;
		(*no) -> dir = (*no) -> esq = NULL;
		return;
	}

	if(chave > (*no) -> chave){
		insere(&(*no) -> dir,chave);
		return;
	}
	insere(&(*no) -> esq,chave);
}

void printa(abp *no){
	printf("(");
	if(no == NULL){
		printf(") ");
		return;
	}
	printf("%i ",no -> chave);
	printa(no -> esq);
	printa(no -> dir);
	printf(") ");
}

abp **buscapai(abp **raiz, int chave){
	if((*raiz) == NULL) return NULL;
	if((*raiz) -> chave == chave) return &(*raiz);
	if((*raiz) -> chave < chave) return buscapai(&(*raiz) -> dir,chave);
	return buscapai(&(*raiz) -> esq, chave);
}

void printaendereco(abp *raiz){
	if(raiz == NULL) return;
	printf("\n   %i\n",raiz -> chave);
	printf("%p\n",raiz -> esq);
	printf("%p\n",&(raiz) -> esq);
	printf("\n%p\n",raiz -> dir);
	printf("%p\n",&(raiz) -> dir);

	printaendereco(raiz -> esq);
	printaendereco(raiz -> dir);
}

int main(){
	abp *no = NULL,**pai;
	int n = 1;
	while(1 == 1){
		printf("0 stop\n");
		printf("1 insere\n");
		printf("2 busca\n");
		printf("3 printa\n");
		printf("4 busca pai\n");
		scanf("%i",&n);
		if(n == 1){
			printf("digite a chave\n");
			scanf("%i",&n);
			insere(&no,n);
			continue;
		}
		if(n == 2){
			printf("digite a chave\n");
			scanf("%i",&n);
			printf("bool %i\n",abpsearch(no,n));
			continue;
		}
		if(n == 3){
			printa(no);
			continue;
		}
		if(n == 4){
			printf("digite a chave:");
			scanf("%i",&n);
			pai = buscapai(&no,n);
			printf("%p\n",(*pai));
			printf("%p\n",pai);
			continue;

		}
		if (n == 5){
			printf("%p\n",no);
			printaendereco(no);
			continue;
		}
		break;
	}
}
