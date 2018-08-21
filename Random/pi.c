#include <stdio.h>

int main(){
	int j,k,l;
	j=k=10;
	l=++j;
	j=-j;
	k++;
	j=j+k-(l--);
	printf("%i %i %i\n",j,k,l);
}
