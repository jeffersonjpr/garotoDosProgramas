#include <stdio.h>
#include <math.h>

float ele(float a,float b){

	return sqrt(pow(a,2) + pow(b,2));
}

int main(){
	float a[3];
	for(int i = 0;i<3;i++){
		printf("Digite o %iº lado: ",i+1);
		scanf("%i",&a[i]);
	}
	printf("%f\n",sqrt(pow(a[0],2) + pow(a[1],2)));
	printf("O tamanho da diagonal do paralelepipedo é de %.2f",ele(ele(a[0],a[1]),a[2]));
}
