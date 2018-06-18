/*
4) Faça um programa que receba a idade, a altura de 15 pessoas. Calcule e escreva:
1. a quantidade de pessoas com idade superior a 50 anos;
2. a média das alturas das pessoas com idade entre 10 e 20 anos;
3. a maior altura encontrada;
*/

#include <stdio.h>
int clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return 0;
}
int main(){
	int idade,jovemainda = 0,velhorsera = 0;
	float alt,altj = 0.0,altm = 0.0;
	clear();
	for(int i = 0;i < 15;i++){
		printf("%iº pessoa\n",i + 1);
		printf("Informe sua idade : ");//bloco de idade
		scanf("%i",&idade);
		while(idade < 1){
			printf("Idade Invalida!!\n");
			printf("Informe sua idade : ");
			scanf("%i",&idade);
		}

		printf("Informe sua altura : ");//bloco de altura
		scanf("%f",&alt);
		while(alt < 0.0){
			printf("Altura Invalida!!\n");
			printf("Informe sua altura : ");
			scanf("%f",&alt);
		}

		if(idade > 50) jovemainda++;
		else if(idade >= 10 && idade <= 20){
			velhorsera++;
			altj += alt;
		}
		if(alt > altm) altm = alt;
		clear();

	}
	clear();
	if(jovemainda > 0) printf("Tem %i pessoas com mais de 50 anos.\n",jovemainda);
	else printf("Nao há pessoas com mais de 50 anos\n");

	if(velhorsera != 0) printf("%.2f é a media da altura das pessoas entre 10 e 20 anos.\n",altj/velhorsera);
	else printf("Nao há pessoas com idade entre 10 e 20 anos\n");

	printf("%.2f é a maior altura encontrada.\n",altm);

}
