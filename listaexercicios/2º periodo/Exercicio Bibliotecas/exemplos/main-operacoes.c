#include <stdio.h>
#include "../operacoes/operacoes.h"

int main(){
	printf("\n5 * 2 = %i\n",mult(5,2));
	printf("9999 * 0 = %i\n",mult(9999,0));
	printf("42 * 1 = %i\n\n",mult(42,1));

	printf("4! = %i\n",fat(4));
	printf("5! = %i\n\n",fat(5));

	printf("4 // 2 = %i\n",diva(4,2));
	printf("8 // 5 = %i\n",diva(8,5));
	printf("10 // 11 = %i\n\n",diva(10,11));
}
