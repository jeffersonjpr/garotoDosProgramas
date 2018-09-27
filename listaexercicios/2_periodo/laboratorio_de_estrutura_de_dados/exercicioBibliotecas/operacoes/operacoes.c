#include "operacoes.h"

int mult(int a,int b){
	if(a == 0 || b == 0) return 0;
	if(b == 1) return a;
	return a + mult(a,b-1);
}

int fat(int a){
	if(a <= 1)return 1;
	int b = 1;
	for(int i = 1;i<=a;i++){
		b = mult(b,i);
	}
	return b;
}

int proc(int a,int b,int c){
	if(a < b) return c;
	return proc(a - b,b,c + 1);
}

int diva (int a,int b){
	if(b == 0) return -1;
	if(b == 1) return a;
	return proc(a,b,0);
}
