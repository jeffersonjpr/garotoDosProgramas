#include <stdio.h>

/*
Dois amigos jogam na loteria toda semana. Escreva um programa que solicite a
quantia com que cada um participou e o valor do prêmio a ser rateado em
partes diretamente proporcionais às quantias de cada um deles. O programa
deve imprimir quanto cada um dos amigos receberá caso sejam ganhadores.

*/

int main(){
	float a1,a2,atot;
	printf("Informe quanto o primeiro amigo contribuiu: ");
	scanf("%f",&a1);
	printf("Informe quanto o segundo amigo contribuiu: ");
	scanf("%f",&a2);
	atot = a1 + a2;
	printf("o primeiro amigo ganhara %.2f%% do premio.\n",(a1*100)/atot);
	printf("o segundo amigo ganhara %.2f%% do premio.\n",(a2*100)/atot);
}
