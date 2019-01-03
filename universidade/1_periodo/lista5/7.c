#include <stdio.h>
#include <math.h>

int fat(int n){ //funçao de fatorial
	if(n <= 1) return 1;
	return n * fat(n-1);
}


int main(){
	int n,expo=2,fatori=3,regra = -1;
	float x,res; //x inicial e resposta final
	printf("Digite os n termos que deseja somar: ");
	scanf("%i",&n);
	printf("Digite o valor de x: ");
	scanf("%f",&x);
	res = x;// guarda o primeiro valor de x na resposta

	for(int i=1;i<n;i++){ //repete o forloop n-1 vezes.
		res+= (pow(x,expo)/fat(fatori)) * regra;
		regra*=-1;
		expo+=2;
		fatori+=2;
	}

	printf("O valor do somatorio é de %.3f\n",res);

}
