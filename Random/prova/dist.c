#include <stdio.h>

int main(){
	float dist[5][5],tot=0;
	int regra = 0,aux=-1,aux2=-1,duas[2],it[4],qtit=0;

	for(int i = 0;i<5;i++){  // atribuir -1 a todas distancias
		for(int j = 0;j<5;j++){
			dist[i][j] = 0;
		}
	}
	for(int i =0;i<5;i++){//loop de atribuição da matriz
		for(int j = 0;j < 5;j++){
			if(i == j) continue;
			if(i > j) continue; // so verifica o triangulo superior
			do{
				printf("\nDigite a distancia da %dº cidade em relacao a %dº cidade:",j+1,i+1);
				scanf("%f",&dist[i][j]);
			}while(dist[i][j] <= 0);
		}
	}
		for(int i = 0;i<5;i++){ // "clona" o triangulo superio no inferior para auxilior no itinerario
			for(int j = 0;j<5;j++){
				if(i == j) continue;
				if(i > j) continue;
				dist[j][i] = dist[i][j];
			}
		}
		
		while(1 == 1){
			//reset das variaveis
			duas[0] = -1;
			aux = -1;
			aux2 = -1;
			tot = 0;


			do{
				if(regra) printf("\nAtencao digite uma opcao valida!");
				printf("\nDigite 1 para saber a distancia entre duas cidades.");
				printf("\nDigite 2 para calcular o trajeto de ate quatro cidades.");
				printf("\nDigite 3 para encerrar.");
				printf("\nDigite dua opcao: ");
				scanf("%i",&aux);
			}while(aux < 1 || aux > 3);
			if(aux == 1){ //distancia entre duas cidades
				for(int i = 0;i<2;i++){
					do{
						printf("\nInforme a %dº cidade:",i+1);
						scanf("%d",&duas[i]);
					}while(duas[i] < 1 || duas[i] > 5);
				}
				printf("A distancia entre a cidades %d e %d e de %.2f\n",duas[0],duas[1],dist[duas[0] -1][duas[1]-1]);
			}
			else if(aux == 2){
				do{
					printf("\nDigite o numero de cidades(maximo 4 e minimo 2)");
					scanf("%d",&qtit);
				}while(qtit < 2 || qtit > 4);
				for(int i = 0;i<qtit;i++){
					do{
						printf("\nDigite a %dº cidade do trajeto: ",i+1);
						scanf("%d",&aux2);
					}while(aux2 < 1 || aux2 > 5);
					it[i] = aux2-1;
				}
				for(int i = 1;i<qtit;i++){
					printf("Cidade %d para %d = %.2f\n",it[i-1]+1,it[i]+1,dist[it[i-1]][it[i]]);
					tot+= dist[it[i-1]][it[i]];
				}
				printf("Distancia total = %.2f\n",tot);
			}
			else if(aux == 3){
				printf("Adeus\n");
				break;
			}
		}
}
