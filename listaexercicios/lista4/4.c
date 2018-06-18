#include <stdio.h>
#include <stdlib.h>
/*
) Faça um programa que calcule e escreva o valor de S:
		S= 1/1 - 3/2 + 5/3 - 7/4 + ... - 99/50
*/
int main() {
	int b = 1;
	double somatorio = 0,a = 1;
	while(b < 51){
		somatorio += ((a/b) - ((a + 2)/(b + 1)));
		a += 4;
		b += 2;
	}
	printf("%f\n",somatorio);
}
