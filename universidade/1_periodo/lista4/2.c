#include <stdio.h>
#include <stdlib.h>

int fat(int n){
	if(n <= 1) return 1;
	return n * fat(n-1);
}

int main(){
	int a;
	printf("Digite o numero para calcular o fatorial: ");
	scanf("%i",&a);
	printf("O fatorial de %i é %i.\n",a,fat(a));
}
