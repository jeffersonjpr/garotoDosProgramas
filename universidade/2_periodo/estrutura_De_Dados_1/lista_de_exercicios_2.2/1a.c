#include <stdio.h>
#include <stdlib.h>
// ERRADO DE PROPOSITO
int main(){
	int *p;
	p = (int*)malloc(sizeof(int) * 3);
	printf("%i\n",*(p + 5)); //leitura ilegal
}
