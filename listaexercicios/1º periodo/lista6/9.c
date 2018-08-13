#include <stdio.h>

int main(){
	int i = 1;
	float fulano = 1.5,ciclano = 1.1;
	do{
		if(ciclano > fulano){
			printf("Foram necessarios %i anos para que o ciclano seja maior que o tal do fulano.\n",i);
			return 0;
		}
		fulano += 0.02;
		ciclano += 0.03;
		i++;
	}while(1 >= 1);
}
