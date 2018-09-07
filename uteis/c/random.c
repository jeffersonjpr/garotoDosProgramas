#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int x,n[11]={},i,qt = 10000;
	srand(time(NULL));
	for(i = 0;i < qt;i++){
		x = rand() % 9;
		n[++x]++;
	}
	for(i = 0;i < 10;i++){
		printf("%.5f\n",((float)n[i]*100)/(float)(qt));
	}
	for(i = 0;i < 10;i++){
		n[10] += n[i];
	}
	printf("\n%.5f\n",((float)n[i]*100)/(float)(qt));
	// x = rand() % 60; /* x vai receber um valor entre 0 e 60 */
	// printf("%d\n",x);
	return 0;
}
