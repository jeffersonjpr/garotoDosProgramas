#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

#define tam 4096
#define ntest 3
float a[tam][tam];
float b[tam][tam];
float c[tam][tam];


void* multiplicacao(void * arg){
	int *vetor = (int*)arg;
	int comeco = vetor[0];
	int fim = vetor[1];
	int ha = vetor[2];
	// multiplicaçao da thread
	for(int i = comeco; i < fim && i < ha; i++){
		for(int j = 0; j < ha; j++){
			c[i][j] = 0.0;
			for(int k = 0; k < ha; k++){
				c[i][j] += a[i][k] * b[k][j]; //multiplicaçao ta certa
			}
		}
	}
	free(arg);
	pthread_exit(0);
}

int main(){
	srand(time(NULL));
	FILE *fp;
	char  nome[] = "1.txtxtxtxt";
	//srand(14);
	int limite = 10;
	float soma;

	//tempo
	struct timespec start, finish;
	double elapsed, final;
	//threads
	int nth = 5;
	int *argm, aux;
	pthread_t tids[200];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			a[i][j] = (float)rand()/(float)(RAND_MAX/limite);
			b[i][j] = (float)rand()/(float)(RAND_MAX/limite);
		}
	}

	for(int nth = 4; nth <= 4; nth++){
		printf("%i\n",nth );
		sprintf(nome,"%i.txt",nth);

		fp = fopen(nome,"a");
		fprintf(fp, "Numero de thread %i\n",nth );
		fclose(fp);
		for (int ha = 2; ha <= tam; ha*=2){
			final = 0.0;
			for(int jay = 0; jay < ntest; jay ++){

				clock_gettime(CLOCK_MONOTONIC, &start);
				aux = 0;
				//criando threads
				for(int th = 0; th < nth; th++){
					argm = (int*)malloc(sizeof(int) * 3);
					argm[0] = aux;
					if(ha/nth == 0) aux += 1;
					else aux += (ha / nth);
					argm[1] = aux;
					argm[2] = ha;
					//printf("%i %i %i\n",argm[0], argm[1], argm[2]);
					pthread_create(&tids[th], &attr,multiplicacao, (void*)argm );
				}

				//unindo threads
				for(int th = 0; th < nth; th++){
					pthread_join(tids[th], NULL);
				}
				clock_gettime(CLOCK_MONOTONIC, &finish);




				//calculando tempo
				elapsed = (finish.tv_sec - start.tv_sec);
				elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
				printf("teste %i result:%.8lf\n",jay,elapsed );
				final += elapsed;
				//verificando matriz
				if (ha == 4){
					for(int i = 0; i < ha; i++){
						for(int j = 0; j < ha; j++){
							printf("%10.2f ",c[i][j]);
						}
						printf("\n");
					}
				}
				//verificando matriz
			}
			final /= ntest;
			//fp = fopen(nome,"a");
			//fprintf(fp, "Tamanho %5.i  Tempo %.8lf\n", ha, final);
			//fclose(fp);
			fp = fopen(nome,"a");
			fprintf(fp, " %.8lf ", ha, final);
			fclose(fp);
			printf("Tamanho %5.i  Tempo %.8lf\n", ha, final);
		}
		fp = fopen(nome,"a");
		fprintf(fp, "\n");
		fclose(fp);
	}
}
