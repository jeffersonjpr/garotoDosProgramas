#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


typedef struct placar{
	int tent,resp1,resp2,*numeros;
}jogo;

void ler_senha(int *aposta,int n){
	int i,j,x=0;
	for(i = 0; i<n; i++){
		//garante que o valor digitado esta de 1 a 9
		while(x <= 0 || x > 9){
			scanf("%i",&x);
		}
		//verifica se o usuario ja dijitou o numero antes
		for(j = 0; j < i; j++){
			if(x == aposta[j]){
				x = 0;
				i--;
				break;
			}
		}
		//se o x nao for igual a zero ele faz a atribuiçao
		if(x) aposta[i] = x;
		x = 0;
	}
}

void sorteia_valores(int *sorteio, int n){
	char rule = 0;
	int i,j;
	for(i = 0; i < n;i++){
		//sorteia um valor de 0 a 8 e soma 1
		sorteio[i] = (rand() % 9) + 1;
		//verifica se o numero ja foi usado antes
		for(j = 0;j<i;j++){
			if(sorteio[i] == sorteio[j]){
				i--;
				break;
			}
		}
	}
}

void compara_senha (int *senha, int *senhaus, int *resp1, int *resp2,int n){
	int i,j;
	*resp1 = 0;
	*resp2 = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j) continue;
			if(senha[i] == senhaus[j]) *resp2++;
		}
	}

	for(i = 0; i < n; i++){
		if(senha[i] == senhaus[i]) *resp1++;
	}

	*resp2 -= *resp1;
}


int main(){
	srand(time(NULL));
	int *a,*b,*d,*e,n = 5;
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);
	ler_senha(a,n);
	for(int i = 0; i < n; i ++){
		printf("%i ",*(a+i));
	}
	printf("\n");

	sorteia_valores(b,n);
	for(int i = 0; i < n; i ++){
		printf("%i ",*(b+i));
	}
	printf("\n");

	compara_senha(b,a,d,e,n);
	printf("%i %i\n",*d,*e);
}
