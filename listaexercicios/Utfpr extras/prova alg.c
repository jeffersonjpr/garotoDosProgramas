#include <stdio>

/*
Dois amigos jogam na loteria toda semana. Escreva um programa que solicite a
quantia com que cada um participou e o valor do prêmio a ser rateado em
partes diretamente proporcionais às quantias de cada um deles. O programa
deve imprimir quanto cada um dos amigos receberá caso sejam ganhadores.

*/

int main(){
	float 1a,2a,a#tot;
	printf("Informe quanto o primeiro amigo contribuiu: );
	scanf("%i",1a);
	printf("Informe quanto o segundo amigo contribuiu: ")
	scanf("%i",2a);
	a#tot = 1a + 2a;
	printf("o primeiro amigo ganhara %.2f% do premio./n",1a*100/a#tot);
	printf("o segundo amigo ganhara %.2f% do premio./n",2a*100/a#tot);
