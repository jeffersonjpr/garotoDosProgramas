#include <bits/stdc++.h>
using namespace std;

int trie [1000][26];
bool end[1000];
int no = 1;

void inseretrie(string s){
	int v = 0;
	for(int i = 0; i < s.size(); i++){
		int idx = s[i] - 'a';
		if(trie[v][idx] == 0){
			trie[v][idx] = no++;
		}
		v = trie[v][idx];
	}
	end[v] = 1;
}

void imprimetodas(string s,int noo){
	if(end[noo]) cout << s << endl;
	for(int i = 0; i< 26; i++){
		if(trie[noo][i]){
			imprimetodas(s + (char)('a' + i),trie[noo][i]);
		}
	}
}
int main(){
	int n;
	string nome;
	scanf("%i",&n);
	for(int i = 0; i < n; i++){
		cin >> nome;
		inseretrie(nome);
	}
	for(int i = 0; i < 20; i++){
		printf("%i: ",i);
		for(int j = 0; j < 26; j++){
			printf(" %i ",trie[i][j]);
		}
		printf(" : %i",end[i]);
		printf("\n");
	}
	imprimetodas("",0);
}
