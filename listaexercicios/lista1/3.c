#include <stdio.h>
#include <math.h>

/* Escreva um programa que calcule o volume de uma esfera. Para tanto, o usuário deve fornecer a medida do raio da mesma.*/

int main() {
	float raio,vol;
	printf("Digite a medida do raio: ");
	scanf("%f",&raio);
	vol = (4 * 3.14159265359 * pow(raio,3))/3;
	printf("%.2f é o volume da esfera.\n",vol);

}
