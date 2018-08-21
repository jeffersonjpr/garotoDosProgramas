#include <stdio.h>

int main(){
	int k,d,a,id,contadora = 1;
	while(contadora < 6){
		printf("Digite o id do %d jogador: ",contadora);
		scanf("%i",&id);
		printf("Digite o numero de abates do %d jogador: ",contadora);
		scanf("%i",&k);
		printf("Digite o numero de mortes do %d jogador: ",contadora);
		scanf("%i",&d);
		printf("Digite o numero de assistencias do %d jogador: ",contadora);
		scanf("%i",&a);

		printf("O jogador com id %i, a teve uma pontuacao de:%.2f\n",id,(k*2 + (float)a*1.5 - 3*d));
		contadora++;
	}
}
