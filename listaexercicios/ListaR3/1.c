#include <stdio.h>

int main(){
	float x;
	while(1==1){
		printf("Digite -999 para encerrar.");
		printf("Digite o numero a ser multiplicado por 3: ");
		scanf("%f",&x);
		if((int)x == -999) return 0;
		printf("\nResultado:%f\n\n",x*3);
	}
}
