#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int somasoma(int n[],int tam){
	if(tam == 0) return 0;
	if(n[tam-1] > 0) return n[tam-1] + somasoma(n,tam-1);
	return somasoma(n,tam-1);
}


int main(){
	int n[15];
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0;i<15;i++){
		n[i] = rand() % 100 -50;
		printf("%d ",n[i]);
	}

	printf("\nSoma elementos positivos: %d\n",somasoma(n,15));
}
