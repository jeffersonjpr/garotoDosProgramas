#include <stdio.h>
#include <stdlib.h>

void mm(int *vetor,int n,int *min,int *max){
	*min = vetor[0];
	*max = vetor[0];

	for(int i = 0;i< n;i++){
		if(vetor[i]  > *max) *max = vetor[i];
		else if(vetor[i] < *min) *min = vetor[i];
	}
}

void main(){
	int min,Max,n,*vetor;
	scanf("%d",&n); //tamanho do vetor
	vetor=malloc(sizeof(int) * n);

	for(int i = 0;i<n;i++){
		scanf("%i",vetor + i); //escaneia os elementos do vetor
	}

	mm(vetor,n,&min,&Max); // chama a função com o vetor,tamanho,  e os endereços de min e max
	printf("%i %i\n",min,Max);
}
