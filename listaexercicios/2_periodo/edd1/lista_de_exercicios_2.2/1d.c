#include <stdio.h>
#include <stdlib.h>
// ERRADO DE PROPOSITO
void aloca(void){
	int *p;
	p = malloc(sizeof(int) * 10);
	//aloca e nao libera a memoria depois que a funçao termina
}
int main(){
	int i=0;
	while(i > -1){
		aloca();
	}
}
//ŧrava meu pc
