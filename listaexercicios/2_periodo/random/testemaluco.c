#include <stdio.h>
int main(){
	int j = 1,k=2,*a=&j,*b=&k;
	printf("%i %i\n",*a,*b);
	scanf("%i",a);
	scanf("%i",b);
	printf("%i %i\n",*a,*b);
	if(*a > *b){
		printf("a=%p\n",a);
		printf("b=%p\n",b);
	}
	else{
		printf("b=%p\n",b);
		printf("a=%p\n",a);
	}
	printf("\n\na=%p\n",&j);
	printf("b=%p\n",&k);
}
