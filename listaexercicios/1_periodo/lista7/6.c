#include <stdio.h>
#include <math.h>

/*
6) Construa um procedimento que, tem como parâmetros de entrada dois pontos quaisquer no
plano, P(x1,y1) e P(x2,y2), escreva a distância entre eles. A fórmula que efetua tal cálculo é:
sqrt((x2 - x1)^2 + (y2 -y1)^2)
*/

float dist(float x,float x1,float y, float y1);

int main(){
	float x,x1,y,y1;
	printf("Digite a coordenada x do 1º ponto: ");
	scanf("%f",&x);
	printf("Digite a coordenada y do 1º ponto: ");
	scanf("%f",&y);
	printf("Digite a coordenada x do 2º ponto: ");
	scanf("%f",&x1);
	printf("Digite a coordenada y do 2º ponto: ");
	scanf("%f",&y1);
	printf("\nA distancia entre (%.2f,%.2f) e (%.2f,%.2f) é de %.2f.\n",x,y,x1,y1,dist(x,x1,y,y1));

}

float dist(float x,float x1,float y, float y1){
	return sqrt(pow(x-x1,2)+pow(y-y1,2));
}
