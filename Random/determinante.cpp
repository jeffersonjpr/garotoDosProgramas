#include <bits/stdc++.h>
using namespace std;

int det(int n,int ord,int m[100][100]){
	if(n == 0) return 0;
	if (ord == 1) return n*m[0][0];
	int ma[ord -1][ord -1],soma = 0,indcol;

	for(int i = 0;i<ord;i++){
		for(int j =0;j<ord;j++){
			m[i][j] *= n;
		}
	}
	for(int i = 0;i<ord;i++){ //loop da matriz original
		indcol = 0;
		for(int j = 1;j<ord;j++){
			for(int k = 0;k<ord;k++){
				if(k == i) {
					continue;
				}
				ma[j-1][indcol] = m[j][k];
				indcol++;
			}
			indcol = 0;
		}

		if(i % 2 == 0) soma += det(m[0][i],ord-1,ma);
		else soma += det(m[0][i]* -1,ord-1,ma);

	}

	return soma;
}

int main(){
	return 0;
}
//00 01 02
//10 11 12
//20 21 22

//11 12 13 14 15
