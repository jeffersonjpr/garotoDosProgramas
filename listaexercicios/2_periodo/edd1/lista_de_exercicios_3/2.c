#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//dia/mes/ano
typedef struct dm{
	int dia,mes,ano;
}dma;
//agenda
typedef struct age{
	char nome[60];
	dma data;
}agenda;

void printar(agenda *p,int n){
	int m,a,cont = 0,i;
	printf("Digite o mes e ano que quer verificar:");
	scanf("%i%i",&m,&a);
	for(i = 0;i < n;i++){
		if((p+i) -> data.mes == m){
			if((p+i) -> data.ano == a){
				cont++;
				printf("Compromisso:%s\n",(p + i) -> nome);
				printf("Data:%i/%i/%i\n",(p + i) ->data.dia,(p + i) ->data.mes,(p + i) ->data.ano);
			}
		}
	}
	if(cont == 0) printf("Voce nao tem compromissos nesse dia.\n");
}

int main(){
	int n,i;
	agenda *p;
	printf("Digite quantos compromissos desseja adicionar:");
	scanf("%i",&n);
	p = (agenda *) malloc(sizeof(agenda) * n);
	for(i = 0;i<n;i++){
		printf("Digite o nome do compromisso:");
		setbuf(stdin,NULL);
		fgets((p + i) -> nome,60,stdin);
		strtok((p + i) -> nome,"\n");
		printf("Digite dia mes e ano:");
		scanf("%i%i%i",&((p+i) -> data.dia),&((p+i) -> data.mes),&((p+i) -> data.ano));
	}
	printar(p,n);

}
