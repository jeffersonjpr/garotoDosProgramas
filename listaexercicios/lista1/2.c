#include <stdio.h>

/* O galão imperial (abreviação: gal) é uma unidade de medida de volume de
líquidos, utilizada no Reino Unido. Sabendo que 1gal equivale a 4,54609 litros,
faça um programa que converta uma determinada quantidade de galões
imperiais em litros.*/

int main() {
	int qnt;
	float galao = 4.54609;
	printf("Digite a quantidade de galoes ");
	scanf("%i",&qnt);
	printf("%i galoes imperiais sao aproximadamente: %.2f litros.\n",qnt,qnt*galao);
	return 0;
}
