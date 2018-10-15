#include <bits/stdc++.h>
using namespace std;
bool teste[100000];
int main(){
	int n,m,aux1,aux2;
	scanf("%i%i",&n,&m);
	if(n == 1 && m == 0){
		printf("YES\n");
		return 0;
	}
	for(int i = 0; i < m; i++){
		scanf("%i%i",&aux1,&aux2);
		if(teste[aux2]){
			printf("NO\n");
			return 0;
		}
		teste[aux1] = 1;
	}
	printf("YES\n");
}
