#include <stdio.h>
#include <stdlib.h>
// ERRADO DE PROPOSITO
int main(){
	int *p;
	p = (int*)malloc(sizeof(int) * 3);
	*(p + 5) = 4; //Esta realizando uma escrita ilegal;
	printf("%i\n",*(p + 5)); //leitura ilegal
}
