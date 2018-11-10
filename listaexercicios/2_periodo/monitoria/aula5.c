#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	char c;
	struct no *prox;
}noo;

int insere(noo **no,char x){
	if(*no == NULL){
		noo *aux = (noo*)malloc(sizeof(noo));
		if(aux == NULL) return 1;
		aux -> c = x;
		aux -> prox = NULL;
		*no = aux;
		return 0;
	}
	noo *aux = (noo*)malloc(sizeof(noo));
	if(aux == NULL) return 1;
	aux -> c = x;
	aux -> prox = *no;
	*no = aux;
	return 0;
}
void removee(noo **no){
	if(*no == NULL) return;
	noo *aux;
	aux = (*no) -> prox;
	free(*no);
	*no = aux;
}

void printa(noo *no){
	noo *aux = no;
	while(aux != NULL){
		printf("%c ",aux -> c);
		aux = aux -> prox;
	}
	printf("\n");
}
int main(){
	noo *p = NULL,*aux;
	int chave,cholc,parent,sinal,n,key,resp;
	chave = cholc = parent = sinal = 0;
	char x;
	while(1 == 1){
		printf("Digite 1 para inserir ou 0 para terminar e verificar:");
		scanf("%i",&n);
		if(n == 1){
			printf("Digite o prox termo: " );
			setbuf(stdin,NULL);
			scanf("%c",&x);
			if(insere(&p,x)) return 0;
		}
		else break;
	}
	key = 0;
	printa(p);
	while(p != NULL){
		x = p -> c;
		removee(&p);
		if(x == '{') chave++;
		else if(x == '(') parent++;
		else if(x == '[') cholc++;
		else if(x == '}') chave--;
		else if(x == ')') parent--;
		else if(x == ']') cholc--;
		else if(x == '*' || x == '+' || x == '-' || x == '/'){
			if(key){
				resp = 0;
				break;
			}
			else key = 1;
		}
		else key = 0;
	}
	while(p != NULL) removee(&p);
	if(!resp) printf("Formula mal formada!\n");
	else if(parent || cholc || chave) printf("Formula mal formada!\n");
	else printf("Formula bem formada!\n");
}

//5 + ( 6 * {7 / 2}) funcionou
//5 ++ 6
