#include <stdio.h>

void troca(int **a,int **b){
	int *aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int seu = 6,nome = 9;
	int *a=&seu,*b=&nome;
	printf("a=%i b=%i\n",*a,*b);
	troca(&a,&b);
	printf("a=%i b=%i\n",*a,*b);
}
