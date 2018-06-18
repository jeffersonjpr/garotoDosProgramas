#include <stdio.h>

int para(int v[], int n,int x){
	int ct = 0;
	for(int i = 0;i<x;i++){
		if(v[i] == n)ct++;
	}
	return ct;
}
int main(){
	int v[1000],z=0,n;
	while(z < 1 || z > 1000){
		printf("\nDigite o tamanho da sequencia de numeros(limite 1000): ");
		scanf("%i",&z);
	}
	printf("\nDigite o numero que deseja verificar se possui repeticoes: ");
	scanf("%i",&n);
	for(int i = 0;i<z;i++){
		printf("\nDigite o %iº numero inteiro: ",i+1);
		scanf("%i",&v[i]);
	}
	printf("\nO numero %i se repete %i vezes.\n",n,para(v,n,z));
}
