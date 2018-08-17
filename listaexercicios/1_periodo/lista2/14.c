#include <stdio.h>
#include <stdlib.h>
/*
14) Escrever um programa que lê um conjunto de 4 valores i,a,b,c, onde i é um valor inteiro e
positivo e a,b,c, são quaisquer valores reais e os escreva. A seguir:
1. Se i = 1 escrever os três valores a,b,c em ordem crescente.
2. Se i = 2 escrever os três valores a,b,c em ordem decrescente.
3. Se i = 3 escrever os três valores a,b,c de forma que o maior entre a,b,c fique dentre os dois.

*/

int  compara (const void * x, const void * y){
	  if(*(float*)x > *(float*)y) return 1;
	  else
	    	if(*(float*)x < *(float*)y) return -1;
			else return 0;
}

int main(){
	int i;
	float a[3];
	printf("Digite 1 para crescente, 2 para decrescente e 3 para maior no meio: ");
	scanf("%i",&i);
	while (i > 3){
		printf("Valor errado!.");
		printf("Digite valores de 1 a 3: ");
		scanf("%i",&i);
	}
	printf("Digite tres valores:\n");
	for(int count = 0;count < 3;count ++){
		printf("Digite %iº valor: ",count+1);
		scanf("%f",&a[count]);
	}

	qsort(a,3,sizeof(float),compara);

	switch(i){
		case 1: printf("%.2f %.2f %.2f\n",a[0],a[1],a[2]); break;
		case 2: printf("%.2f %.2f %.2f\n",a[2],a[1],a[0]); break;
		case 3: printf("%.2f %.2f %.2f\n",a[0],a[2],a[1]); break;
	}



}
