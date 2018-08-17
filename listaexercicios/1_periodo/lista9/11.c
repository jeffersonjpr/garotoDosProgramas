#include <stdio.h>
int x=10;
int invalida(float n[]){
	int cti = 0;
	for(int i = 0;i<x;i++){
		if(n[i] < 0 || n[i] > 10) cti++;
	}
	return cti;
}
float media(float n[]){
	float ct = 0.0;
	for(int i = 0;i<x;i++){
		if(n[i] > 0 || n[i] < 10){
			ct += n[i];
		}
	}
}

int main(){
	float notas[x];
	for(int i = 0;i<x;i++){
		printf("Digite a nota %d",i+1);
		scanf("%d",&notas[i]);
	}
}
