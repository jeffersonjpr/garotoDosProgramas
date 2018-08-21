#include <stdio.h>

int soma(int n){
	int soma = 0;
	for(int j =1;j < n;j++){
		if(n%j == 0) soma += j;
	}
	if(soma == n) return 1;
	else return 0;
}

int main(){
	printf("Todos os numeros perfeitos de 0 a 100000\n");
	for(int i = 2;i < 100001;i++){
		if(soma (i)) {
			printf("%i é um numero perfeito\n",i);
		}
	}
}
