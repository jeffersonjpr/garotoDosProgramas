#include <stdlib.h>
#include <stdio.h>
int main(){
	int *p=(int *) malloc(2*sizeof(int));
	printf("%p\n",p);
	printf("%p\n",p+1); //0x949b00C
	printf("%p\n",(char*)p+1); //0x949b009
	return 0;
}
