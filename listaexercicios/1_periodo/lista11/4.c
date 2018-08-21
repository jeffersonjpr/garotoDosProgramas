#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int produtao(int n[],int tam){
	if(tam == 0) return 1;
	if(n[tam-1] > 0) return n[tam-1] * produtao(n,tam-1);
	return produtao(n,tam-1);
}


int main(){
	int n[5];
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0;i<5;i++){
		n[i] = rand() % 100 -50;
		printf("%d ",n[i]);
	}

	printf("\nProduto elementos positivos: %d\n",produtao(n,5));
}
