#include <bits/stdc++.h>
using namespace std;
int main(){
	int ord = 3,ma[2][2],m[3][3],indcol;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			m[i][j] = i+j;
		}
	}

	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			printf("%i ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
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

		for(int i = 0;i<2;i++){
			for(int j = 0;j<2;j++){
				printf("%i ",ma[i][j]);
			}
			printf("\n");
		}

		printf("\n");
		printf("\n");
		printf("\n");
	}
}
