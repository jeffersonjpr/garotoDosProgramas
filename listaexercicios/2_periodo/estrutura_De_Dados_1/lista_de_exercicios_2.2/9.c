#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *kakashi(char *str){
	char *ba;
	int a = strlen(str);
	ba = (char*)malloc(sizeof(char) * a);
	ba = str;
	return ba;
}

int main(){
	char *a,*b;
	a = (char*)malloc(sizeof(char) * 30);
	setbuf(stdin,NULL);
	fgets(a,30,stdin);
	b = kakashi(a);
	printf("%s\n",b);
}
