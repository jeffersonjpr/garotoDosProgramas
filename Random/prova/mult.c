#include <stdio.h>

int mult(int a,int b){
	if(a == 0 || b == 0) return 0;
	if(b == 1) return a;
	return a + mult(a,b-1);
}

int main(){
	//alguns casos testes basico
	int a,b;
	do{
		printf("Digite o primeiro numero: ");
		scanf("%d",&a);
	}while(a < 0);
	do{
		printf("Digite o segundo numero: ");
		scanf("%d",&b);
	}while(b < 0);
	printf("%d*%d=%d\n",a,b,mult(a,b));
}
