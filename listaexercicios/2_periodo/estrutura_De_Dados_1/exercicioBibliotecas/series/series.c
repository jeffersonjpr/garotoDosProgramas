#include "../operacoes/operacoes.h"
#include "series.h"
int suma (int a){
	a--;
	int b = 1;
	for(int i = 0;i<=a;i++){
		b = mult(b,2);
	}
	b--;
	return b * 2;
}

int seq(int a){
	_Bool bola =1;
	int soma = 0;
	for(int i = 1;i<=a;i++){
		if(bola){
			soma +=i;
			bola = 0;;
		}
		else{
			soma -= i;
			bola = 1;
		}
	}
	return soma;

}
