#include <stdio.h>

int maior(float v[]){
	int indice = 0;
	float maior = v[0];
	for(int i = 1;i < 15;i++){
		if(v[i] > maior){
			maior = v[i];
			indice = i;
		}
	}
	return indice;
}
int main(){
	int indice,indicem[15],ct=0,idm=0;
	float vetor[15];
	for (int i = 0;i<15;i++){
		printf("Digite o %iº elemento: ",i+1);
		scanf("%f",&vetor[i]);
	}
	indice = maior(vetor);
	for(int i = 0;i<15;i++){
		if(vetor[indice] == vetor[i]){
			ct++;
			indicem[idm]=i;
			idm++;
		}
	}
	if(ct == 1) printf("O maior elemento é o %f na posicao %i\n",vetor[indice],indice);
	else{
		printf("O maior elemento é o %f nas posiçoes:",vetor[indice]);
		for(int i = 0;i < idm-1;i++){
			printf("%i ",indicem[i]);
		}
		printf("%i.\n",indicem[idm-1]);
	}

}
