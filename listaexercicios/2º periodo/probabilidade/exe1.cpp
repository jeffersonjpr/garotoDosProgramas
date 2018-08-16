#include <bits/stdc++.h>
using namespace std;

float media(int p[],int n){
	int tot = 0;
	for(int i = 0;i<n;i++){
		tot += p[i];
	}
	return (float)tot/(float)n;
}

float mediana(int p[],int n){
	if(n%2 == 0){
		return ((float)p[n/2-1] + (float)p[n/2]) / 2;
	}
	else return p[n/2];
}

float varizes(int p[],int n,float media){
	float resp = 0;
	for(int i = 0;i<n;i++){
		resp+= pow((float)p[i]-media,2);
	}
	return sqrt(resp/(n-1));
}

int main(){
	int tweet[1000],total = 0,resp;
	while(true){
		printf("Digite o numero de tweets na hora(-1 para parar):");
		scanf("%i",&resp);
		if(resp > -1){
			tweet[total]=resp;
			total++;
		}
		else break;
	}
	sort(tweet,tweet + total);
	printf("\n\nA media é: %.3f\n",media(tweet,total));
	printf("A mediana é: %.3f\n",mediana(tweet,total));
	printf("A amplitude é de: %i\n",tweet[total - 1] - tweet[0]);
	printf("A variancia é de: %.3f\n\n",varizes(tweet,total,media(tweet,total)));



}
