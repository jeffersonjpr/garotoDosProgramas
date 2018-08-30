#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265


typedef struct cart{
	double r,a,x,y;
}carte;

int main(){
	carte *p;
	int a = 0,resp,i;
	double aa,bb,val = PI / 180.0;
	p = (carte *)malloc(sizeof(carte));
	do{
		printf("0 para adicionar,1 para printar,2 para sair\n");
		scanf("%i",&resp);
		if(resp == 0){
			a+=1;
			p = (carte*)realloc(p,sizeof(carte) * a);
			printf("Digite o raio e o argumento respectivamente: ");
			scanf("%lf%lf",&((p+a-1)-> r),&((p+a-1) -> a));
			aa = (p + a - 1) -> r;
			bb = (p + a - 1) -> a;
			(p+a-1) -> x = aa * cos(bb * val);
			(p+a-1) -> y = aa * sin(bb * val);
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
