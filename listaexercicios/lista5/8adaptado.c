#include <stdio.h>

int main(){
	int soma = 0;
	printf("Todos os numeros perfeitos de 0 a 100000\n");
	for(int i = 2;i < 100001;i++){
		soma = 0;
		for(int j = 1;j < i;j++){
			if(i%j == 0) soma += j;
		}
		if(soma == i) {
			printf("%i é um numero perfeito\n",i);
		}
	}
}
