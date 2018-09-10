#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


typedef struct placar{
	int tent,resp1,resp2,*numeros;
}jogo;
void clear(){
	system("clear");
}
void ler_senha(int *aposta,int n){
	int i,j,x=0;
	for(i = 0; i<n; i++){
		//garante que o valor digitado esta de 1 a 9
		while(x <= 0 || x > 9){
			printf("Escolha o %i numero: ",i + 1);
			scanf("%i",&x);
		}
		//verifica se o usuario ja dijitou o numero antes
		for(j = 0; j < i; j++){
			if(x == aposta[j]){
				printf("Numero ja utilizado.\n");
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
			if(*(senha + i) == *(senhaus + j)) *resp2 += 1;
		}
	}

	for(i = 0; i < n; i++){
		if(senha[i] == senhaus[i]) *resp1 += 1;
	}

	*resp2 -= *resp1;
}
//interface do jogo
void interface(jogo *game,int tenta, int n){
	int i,j;
	clear();
	for(i = 0; i < tenta; i++){
		printf("%i ",(game + i) -> tent);
		for(j = 0; j < n; j++){
			printf("%i",*(game + i) -> numeros + j);
		}
		printf(" %i %i\n",(game +i) -> resp1,(game + i) -> resp2);
	}
}
//desalocação
void breakfree(jogo *game,int tenta, int n){
	int i;
	for(i = 0; i < tenta; i++){
		free((game + i) -> numeros);
	}
	free(game);
}

//jogo
void joguinho(int n){
	jogo *game;
	int *senha,tenta = 0;
	senha = (int*)malloc(sizeof(int) * n);
	sorteia_valores(senha,n);
	game = (jogo*)malloc(sizeof(jogo));
	do{
		(game + tenta) -> numeros = (int*)malloc(sizeof(int) * n);
		(game + tenta) -> tent = tenta + 1;
		ler_senha((game + tenta) -> numeros,n);
		compara_senha(senha,(game + tenta) -> numeros,&(game + tenta) -> resp1,&(game + tenta) -> resp2,n);
		interface(game,tenta + 1,n);
		if((game + tenta) -> resp1 == n){
			breakfree(game,tenta,n);
			printf("Voce acertou em %i tentativas\n",tenta + 1);
			break;
		}
		else{
			game = (jogo*)realloc(game,sizeof(jogo) * (tenta + 2));
			tenta++;
		}
	}while(1 == 1);

}

int main(){
	srand(time(NULL));
	int n;
	do{
		printf("1 = facil, 2 = dificil, 3 = teste, 4 = sair: ");
		scanf("%i",&n);
		if(n == 4) return 0;
		if(n == 1){
			n = 3;
			joguinho(n);
		}
	}while(1 == 1);

}
