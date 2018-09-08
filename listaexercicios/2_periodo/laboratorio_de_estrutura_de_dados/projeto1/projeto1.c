#include <stdlib.h>
#include <stdio.h>
#include <sting.h>
#include <time.h>

srand(time(NULL));

typedef struct placar{
	int tent,resp1,resp2,*numeros;
}jogo;

void ler_senha(int *aposta,int n){
	int i,x=0;
	for(i = 0; i<n; i++){
		while(x == 0){
			scanf("%i",&x);
		}
		aposta[i] = x;
		x = 0
	}
}

void sorteia_valores(int *sorteio, int n){
	char rule = 0;
	int i,j;
	for(i = 0; i < n;i++){
		sorteio[i] = (rand() % 9) + 1;
		for(j = 0;j<n;j++){
			if(j == i) continue;
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
	for(i = 0; i<n; i++){
		for(j = 0; j < n;j++){
			if(senha[i] == senhaus[j]) *resp2++;
		}
	}

	for(i = 0; i < n; i++){
		if(senha[i] == senhaus[i]) *resp1++;
	}

	*resp2 -= *resp1;
}
