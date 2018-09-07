#include <stdlib.h>
#include <stdio.h>
#include <sting.h>


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
