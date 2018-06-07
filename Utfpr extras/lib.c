#include <stdio.h>
#include "lib.h"

int fat(int n){ //funcao de fatorial
	if(n <= 1) return 1;
	return n * fat(n-1);
}

int pote(int b,int e){ //potencia
	if(b == 0) return 0;
	if(e == 0) return 1;
	if(e == 1) return b;
	return b*pote(b,e-1);
}

int fibra(int n){
	int a = 1, b = 1,c,soma = 2;
	if(n==1) return 1;
	if(n==2) return 2;
	for(int i = 0;i<n-2;i++){
		c = a + b;
		soma += c;
		a = b;
		b = c;
	}
	return soma;
}

float media(int n){
	float me = 0.0,at;
	for(int i = 0;i<n;i++){
		printf("Digite a altura do %iº aluno: ",i+1);
		scanf("%f",&at);
		me+=at;
	}
	return (me / n);
}
