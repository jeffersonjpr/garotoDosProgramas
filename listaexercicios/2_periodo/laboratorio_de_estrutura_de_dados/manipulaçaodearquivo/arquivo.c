#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *arq;
	char nome[10] = "SeuCreyson";
	int idade = 150;
	arq = fopen("file.txt", "w");
	if(arq == NULL) return 0;
	fprintf(arq,"%s %d\n",nome,idade);
	while(idade > 0){
		scanf("%s %i",nome,&idade);
		fprintf(arq,"%s %d\n",nome,idade);
	}

	fclose(arq);
	arq = fopen("file.txt","r");

	while(fscanf(arq,"%s %i",nome,&idade) != EOF){
		printf("%s %i\n",nome,idade);
	}

}
