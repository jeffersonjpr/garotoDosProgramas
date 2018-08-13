#include <stdio.h>
#include "../series/series.h"

int main(){
	printf("\n1º Somatorio de 2 = %i\n",suma(2));
	printf("1º Somatorio de 4 = %i\n",suma(4));
	printf("1º Somatorio de 3 = %i\n\n",suma(3));

	printf("2º Somatorio de 3 = %i\n",seq(3));
	printf("2º Somatorio de 5 = %i\n",seq(5));
	printf("2º Somatorio de 6 = %i\n",seq(6));
}
