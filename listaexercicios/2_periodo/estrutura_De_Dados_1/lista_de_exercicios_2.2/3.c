#include <stdlib.h>
#include <stdio.h>

int main() {
	int *p = (int *) malloc(2*sizeof(int));
	int **p2 = &p;	 //ponteiro de ponteiro
	p[0] = 2;
	p[1] = 1;
	printf("%i %i\n",p[0],p[1]);
	printf("%i %i\n",*(*p2),*(*p2 + 1));
	return 0;
}
