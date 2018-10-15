#include <bits/stdc++.h>
using namespace std;
bool teste[1000010];
int main(){
	queue<pair<int,int>> fila;
	int f,s,g,u,d;
	scanf("%i%i%i%i%i",&f,&s,&g,&u,&d);
	fila.push(make_pair(s,0));
	teste[s] = 1;
	while(fila.size()){
		if(fila.front().first == g){
			printf("%i\n",fila.front().second);
			return 0;
		}
		if(fila.front().first + u <= 1000000 && !teste[fila.front().first + u]){
			teste[fila.front().first + u] = 1;
			fila.push(make_pair(fila.front().first + u,fila.front().second + 1));
		}
		if(fila.front().first - d >= 0 && !teste[fila.front().first - d]){
			teste[fila.front().first - d] = 1;
			fila.push(make_pair(fila.front().first - d,fila.front().second + 1));
		}
		fila.pop();
	}
	printf("use the stairs\n");
}
