#include <stdio.h>
#include <stdlib.h>
//
// int main(){
// 	FILE *arq;
// 	char nome[10] = "SeuCreyson";
// 	int idade = 150;
// 	arq = fopen("file.jpr", "w");
// 	if(arq == NULL) return 0;
// 	fprintf(arq,"%s %d\n",nome,idade);
// 	while(idade > 0){
// 		scanf("%s %i",nome,&idade);
// 		if(idade == 0) continue;
// 		fprintf(arq,"%s %d\n",nome,idade);
// 	}
//
// 	fclose(arq);
// 	arq = fopen("file.jpr","r");
//
// 	while(fscanf(arq,"%s %i",nome,&idade) != EOF){
// 		printf("%s %i\n",nome,idade);
// 	}
//
// }

int main(){
	FILE *arq;
	char nome[30],sobren[30];
	int idade,n;
	printf("Quantas vezes:");
	scanf("%i",&n);
	arq = fopen("test.jpr","a");
	if(arq == NULL) return 0;
	while(n > 0){
		printf("Digite nome e sobrenome:");
		scanf("%s%s",nome,sobren);
		printf("Digite idade:");
		scanf("%i",&idade);
		fprintf(arq,"%s %s %i\n",nome,sobren,idade);
		n--;
	}
	fclose(arq);
	arq = fopen("test.jpr","r");
	if(arq == NULL) return 0;
	while(fscanf(arq,"%s %s %i",nome,sobren,&idade) != EOF){
		printf("Nome:%s %s Idade:%i\n",nome,sobren,idade);
	}
	fclose(arq);
}
