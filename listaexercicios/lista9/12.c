#include <stdio.h>

int main(){
	int x[20],y[20],pe=0;
	for(int i = 0;i<20;i++){
		printf("Digite o x%d",i+1);
		scanf("%d",&x[i]);
		printf("Digite o y%d",i+1);
		scanf("%d",&y[i]);
		pe += x[i] * y[i];
	}

	printf("Produto Escalar %d",pe);

}
