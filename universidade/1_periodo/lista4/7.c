/*
7) Sabe-se que o número Neperiano e = 2.7182818 ... (que é um número irracional) pode ser
calculado pela soma dos valores de uma série infinita, como mostrado abaixo:
Fazer um programa em C que calcule este número (e) considerando apenas as 15 (quinze)
primeiras parcelas.
*/

#include <stdio.h>

int fat(int n){
	if (n <= 1) return 1;
	return n * fat(n-1);
}

int main(){
	int a=15,b=0;
	double nep = 0.0;
	while(b < a){
		nep += 1.0/fat(b);
		b++;
	}
	printf("O numero neperiano com 15 parcelas de precisão é: %.15lf\n",nep);
}
