#include <stdio.h>

/*Escreva um programa para ler, calcular e escrever a média aritmética entre dois
números.*/

int main() {
	float n1,n2;
	printf("Digite a 1º nota: \n");
	scanf("%f",&n1);
	printf("Digite a 2º nota: \n");
	scanf("%f",&n2);
	printf("Sua média foi de %.2f\n",(n1+n2)/2);
}
