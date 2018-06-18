/*
5) Sabe-se que:
1. 1 pé = 12 polegadas;
2. 1 jarda = 3 pés;
3. 1 milha = 1.760 jardas.
Faça um programa que receba uma medida em pés, faça as conversões a seguir e mostre os
resultados em.
a) polegadas;
b) jardas;
c) milhas.
Para cada conversão faça sua respectiva função.
*/

#include <stdio.h>

float polegar(float x);
float jardim(float x);
float milho(float x);

int main(){
	float pe;
	printf("Digite uma distancia em pes: ");
	scanf("%f",&pe);
	printf("\n%.2f pes é equilavente a %.5f polegadas.\n",pe,polegar(pe));
	printf("%.2f pes é equilavente a %.5f jardas.\n",pe,jardim(pe));
	printf("%.2f pes é equilavente a %.5f milhas.\n",pe,milho(pe));
	printf("Ambas as conversoes tem 5 casas de precisao.\n");
}

float polegar(float x){
	return x*12;
}
float jardim(float x){
	return x/3;
}
float milho(float x){
	return jardim(x)/1760;
}
