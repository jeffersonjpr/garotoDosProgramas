#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int smalls(int n[],int tam,int x){
	if(tam == 0) return x;
	if(n[tam-1] < x) return smalls(n,tam-1,n[tam-1]);
	return smalls(n,tam-1,x);
}


int main(){
	int n[15];
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0;i<15;i++){
		n[i] = rand() % 100;
		printf("%d ",n[i]);
	}

	printf("\nMenor elemento %d\n",smalls(n,15,n[0]));
}
