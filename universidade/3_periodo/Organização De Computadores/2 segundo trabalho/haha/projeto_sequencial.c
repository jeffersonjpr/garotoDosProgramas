#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 2048
float a[tam][tam];
float b[tam][tam];
float c[tam][tam];

int main(){
	srand(time(NULL));
	srand(14);
	int limite = 10, size = 2;
	float soma;

	struct timespec start, finish;
	double elapsed, final;

	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			a[i][j] = (float)rand()/(float)(RAND_MAX/limite);
			b[i][j] = (float)rand()/(float)(RAND_MAX/limite);
		}
	}

	/*
	EXCLUIR
	while(x > 0.0001){
		x = (float)rand()/(float)(RAND_MAX/a);
		printf("%f\n",x);
		i++;
	}
	x = 100000000.0;
	printf("%f\n",x);
	x = 10000000000000.0;
	printf("%f\n",x);


	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%.5f ",a[i][j]);
		}
		printf("\n");
	}
	EXCLUIR
	*/

	printf("sequencial\n");
	for (int ha = 2; ha <= tam; ha*=2){
		final = 0.0;
		for(int jay = 0; jay < 10; jay++){
			clock_gettime(CLOCK_MONOTONIC, &start);
			for(int i = 0; i < ha; i++){
				for(int j = 0; j < ha; j++){
					c[i][j] = 0.0;
					for(int k = 0; k < ha; k++){
						c[i][j] += a[i][k] * b[k][j]; //multiplicaçao ta certa
					}
				}
			}
			clock_gettime(CLOCK_MONOTONIC, &finish);

			elapsed = (finish.tv_sec - start.tv_sec);
			elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
			final += elapsed;
			/*/verificando matriz
			if (ha == 4){
				for(int i = 0; i < ha; i++){
					for(int j = 0; j < ha; j++){
						printf("%10.2f ",c[i][j]);
					}
					printf("\n");
				}
			}
			//verificando matriz*/
		}
		final /= 10;
		printf("Tamanho %5.i  Tempo %5.5lf\n", ha, final);
	}
}
