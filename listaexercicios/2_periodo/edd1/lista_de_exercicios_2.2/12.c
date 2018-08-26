#include <stdio.h>
#include <stdlib.h>

void concat(int *a,int *b,int *c){
	int i,x;
	for(i = 0;i < (sizeof(a) / sizeof(int));i++){
		*(c + i) = *(a + i);
	}
	x = sizeof(a)/sizeof(int);
	x+= sizeof(b)/sizeof(int);

	for(i = (sizeof(a) / sizeof(int));i < x;i++){
		*(c + i) = *(b + i - (sizeof(a) / sizeof(int)));
	}

}

int main(){
	int *a,*b,*c,n,m,i;
	printf("tamanho primeiro vetor:");
	scanf("%i",&n);
	a = malloc(sizeof(int) * n);
	printf("elementos do primeiro vetor: ");
	for(i = 0; i < n; i++){
		scanf("%i",a + i);
	}

	printf("tamanho do segundo vetor: ");
	scanf("%i",&m);
	b = malloc(sizeof(int) * m);
	printf("elementos do segundo vetor: ");
	for(i = 0; i < m; i++){
		scanf("%i",b + i);
	}




	c = malloc(sizeof(int) * (n + m));
	concat(a,b,c);
	free(a);
	free(b);
	for(i = 0;i < (n + m);i++){
		printf("%i ",*(c + i));
	}
	printf("\n");
}
