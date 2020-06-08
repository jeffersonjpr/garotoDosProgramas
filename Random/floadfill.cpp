#include <bits/stdc++.h>
using namespace std;

// busca em profundidade teste

int mat[201][201],n,m,x;

int dfs(int i, int j){
	int cont = 1;
	int x = mat[i][j];
	mat[i][j] = -1;

	if(j+1 < m && mat[i][j+1] == x){
		cont += dfs(i,j+1);
	}
	if(j-1 >= 0 && mat[i][j-1] == x){
		cont += dfs(i,j-1);
	}
	if(i+1 < n && mat[i+1][j] == x){
		cont += dfs(i+1,j);
	}
	if(i-1 >= 0 && mat[i-1][j] == x){
		cont += dfs(i-1,j);
	}

	return cont;
}
int main(){
	int maior = INT_MAX;
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] != -1) maior = min(maior,dfs(i,j));
		}
	}

	cout << maior << endl;
}
