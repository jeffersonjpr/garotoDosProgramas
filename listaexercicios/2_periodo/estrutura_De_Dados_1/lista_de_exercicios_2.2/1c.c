#include <stdio.h>
#include <stdlib.h>
// ERRADO DE PROPOSITO
int main(){
	char *p;
	int i=0;
	p = (char*)malloc(sizeof(char) * 2);
	while(i > -1){
		printf("%c",*(p + i++)); //esta acessando lugar de memoria protegido
	}
}
