#include <stdio.h>

int checatrans(int a,int m[a][a]){
	for(int i = 0;i < a;i++){
		for(int j = 0;j < a;j++){
			if(m[i][j] != m[j][i]) return 0;
		}
	}
	return 1;
}

int main(){
	int a;
	printf("Digite numeros de linhas/colunas da matriz: ");
	scanf(" %d",&a);
	int m[a][a];
	for(int i = 0;i < a;i++){
		for(int j = 0;j < a;j++){
			scanf(" %d",&m[i][j]);
		}
	}

	if(checatrans(a,m)) printf("A matriz é transposta.\n");
	else printf("A matriz nao é transposta.\n");

}
