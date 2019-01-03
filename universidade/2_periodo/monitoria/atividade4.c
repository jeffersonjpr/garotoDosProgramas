#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct site{
	char nome[15],endereco[30];
	struct site *prox;
}site;

//explicação na main
site *alocano(site *prox, char *nome,char *endereco){
	site *aux;
	aux = (site*)malloc(sizeof(site));
	if(aux == NULL) return prox;
	strcpy(aux -> nome,nome);
	strcpy(aux -> endereco,endereco);
	aux -> prox =  prox;
	return aux;
}

site *insereInicioListaCircular(site **prim, char *nome,char *endereco){
	if(*prim == NULL){
		*prim = alocano(NULL,nome,endereco);
		(*prim) -> prox = *prim;
		return *prim;
	}
	(*prim) -> prox = alocano((*prim) -> prox,nome,endereco);
	return *prim;
}

int buscasite(site **prim, char nome[]){
	if(*prim == NULL) return 0;
	site *aux = *prim;
	int n = 0,chave = 1;
	while(1 == 1){
		n++;
		if(!strcmp(aux -> nome,nome)){
			*prim = aux;
			return n;
		}
		if(aux == *prim && chave == 0) return 0;
		else chave = 0;
		aux = aux -> prox;
	}
}
int main(){
	int n;
	char nome[15],endereco[30];
	site *prim = NULL;
	/*
	Como a lista é circular, posso mover o ponteiro livremente
		dentro da lista sem se preocupar com a posiçao dela.
	Assim, eu posso atribuir o ponteiro que aponta pro começo da lista,
		pro site que foi pesquisado por ultimo
	*/
	while(1){
		printf("1 para adicionar o site\n2 para buscar\n");
		printf("Digite opcao:");
		scanf("%i",&n);
		if(n == 1){
			printf("Digite o nome do site:");
			setbuf(stdin,NULL);
			fgets(nome,15,stdin);
			printf("Digite o site:");
			setbuf(stdin,NULL);
			fgets(endereco,30,stdin);
			prim = insereInicioListaCircular(&prim,nome,endereco);
			continue;
		}
		if(n == 2){
			printf("Digite o nome do site para buscar:");
			setbuf(stdin,NULL);
			fgets(nome,15,stdin);
			n = buscasite(&prim,nome);
			if(!n) printf("Site nao encontrado\n");
			printf("%s Encontrado! %i passos;\n",prim -> endereco,n);
			continue;
		}
		if(n >= 3) return 0;
	}
}
