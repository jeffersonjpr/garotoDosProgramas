#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

//estrutura pras coordenadas
typedef struct cart{
	double r,a,x,y;
}carte;

int main(){
	carte *p;
	int a = 0,resp,i;
	double val = PI / 180.0;
	p = (carte *)malloc(sizeof(carte));
	//maloca apenas para nao dar erro na hr de realocar
	do{
		printf("0 para adicionar,1 para printar,2 para sair\n");
		scanf("%i",&resp);
		if(resp == 0){
			a+=1;
			p = (carte*)realloc(p,sizeof(carte) * a);
			//realoca conforme precisa, nao sei se é mt efieciente essa abordagem
			printf("Digite o raio e o argumento respectivamente: ");
			scanf("%lf%lf",&((p+a-1)-> r),&((p+a-1) -> a));
			(p+a-1) -> x = (p + a - 1) -> r * cos((p + a - 1) -> a * val);
			(p+a-1) -> y = (p + a - 1) -> r * sin((p + a - 1) -> a * val);
		}
		else if(resp == 1){
			if(a == 0){
				printf("Nenhum elemento\n");
				continue;
			}
			for(i = 0; i < a;i++){
				printf("\n%iº Coordenada:\n",i+1);
				printf("Raio:%.3lf Argumento:%.3lf\n",(p + i) -> r,(p + i) -> a);
				printf("Coord X:%.3lf Coord Y:%.3lf\n",(p + i) -> x,(p + i) -> y);
			}
			printf("\n");
		}
		else break;

	}while(resp < 2);
}
