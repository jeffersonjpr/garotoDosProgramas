#include <stdio.h>
#include <math.h>
/*
2) Faça um programa que receba do usuário um número positivo e diferente de zero, calcule e
mostre: (para cada calculo utilize procedimentos):
 1. A quadrado do número;
 2. A raiz cúbica do número;
 3. A raiz quadrada do número;
 4. O cubo do número.
 */
int quadrado(int n);
float rcubo(int n);
float rquadrado(int n);
int cubo(int n);

int main(){
	int x;
	do{
		printf("Digite um numero inteiro positivo: ");
		scanf("%i",&x);
	}while(x <= 0);
	printf("\n%i é o quadrado de %i.\n",quadrado(x),x);
	printf("%.2f é a raiz cubica de %i.\n",rcubo(x),x);
	printf("%.2f é a raiz quadrada de %i.\n",rquadrado(x),x);
	printf("%i é o cubo de %i.\n",cubo(x),x);
}


int quadrado(int n){
	return n*n;
}
float rcubo(int n){
	return pow((float)n,0.333333);
}
float rquadrado(int n){
	return pow((float)n,0.5);
}
int cubo(int n){
	return quadrado(n) * n;
}
