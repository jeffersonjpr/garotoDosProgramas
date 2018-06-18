#include <stdio.h>
int main(){
	int v[20];
	for (int i = 0; i < 20; i++){
		printf("Digite o %iº elemento: ",i+1);
		scanf("%i",&v[i]);
		v[i]*=i;
	}
	for (int i = 0; i < 20; i++){
		printf("%iº elemento:%i\n",i+1,v[i]);
	}
}
