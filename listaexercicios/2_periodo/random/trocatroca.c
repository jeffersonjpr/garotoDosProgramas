#include <stdio.h>

void troca(int *a,int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int a = 6,b = 9;
	printf("a=%i b=%i\n",a,b);
	troca(&a,&b);
	printf("a=%i b=%i\n",a,b);
}
