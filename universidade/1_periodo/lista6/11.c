#include <stdio.h>
#include <stdlib.h>

int idade(){
	int n;
	do {
		printf("Digite sua idade: ");
		scanf("%i",&n);
	} while(n < 1);
	return n;
}

int op(){
	int n;
	do {
		printf("5 para otimo.\n");
		printf("4 para bom.\n");
		printf("3 para regular.\n");
		printf("2 para ruim.\n");
		printf("1 para pessimo.\n");
		printf("Digite sua opniao a respeito do filme: ");
		scanf("%i",&n);
	} while(n < 1 || n > 5);
	return n;
}

int main(){
	int totruim=0,o,i,j,otimo=0,totbom=0,bom=0,pessimo=0,mpes=0,mo=0,mr=0,mruim=0;
	float aux=0;
	for(j = 1;j <= 100;j++){
		i = idade();
		o = op();
		if(o == 5){
			otimo++;
			if(i > mo)mo = i;
		}
		else if(o==4 || o==3){
			totbom++;
			if(o == 3) bom++;
		}
		else if(o == 2){
			mruim += i;
			totruim++;
			if(i > mr)mr = i;
		}
		else if(o ==  1){
			pessimo++;
			if(i > mpes) mpes = i;
		}

	}
	j--;
	printf("\n%i pessoas responderam otimo.\n",otimo);
	aux = ((float)bom*100.0)/(float)totbom;
	printf("\nEntre as pessoas que responderam bom ou regular:\n");
	printf("%.2f%% delas responderam bom.\n",aux);
	printf("%.2f%% delas responderam regular.\n",100.0-aux);
	printf("\n%.2f é a media de idade das pessoas que responderam ruim.\n",(float)mruim/(float)totruim);
	printf("\n%.2f%% é a porcentagem de avalicoes \"pessimo\",a maior idade a escolher essa opcao foi %i\n",((float)pessimo*100)/(float)j,mpes);
	printf("\n%i é a diferenca entre a maior idade que escolheu otimo e a maior idade que escolheu ruim.\n",abs(mr-mo));


}
