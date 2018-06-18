//problema colhedo fibonacci
#include <stdio.h>

int main(){
	int ferteis,ntot,meses,aux,aux2;
	printf("Digite o numero total de casais de coelhos: ");
	scanf("%i",&ntot);
	printf("Digite o numero de casais de coelhos ferteis: ");
	scanf("%i",&ferteis);
	printf("Digite o numero de meses: ");
	scanf("%i",&meses);
	aux = ntot - ferteis;
	while(meses > 0){
		ntot += ferteis;
		aux2 = ferteis;
		ferteis += aux;
		aux = aux2;
		meses --;
	}
	printf("O numero total de coelhos é %i",ntot *2);


}
