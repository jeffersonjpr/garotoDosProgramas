#include <stdio.h>

int primo(int n){
        if(n%2==0) return 0;
	for(int i = 3;i<n;i++) if(n%i==0) return 0;
	return 1;
}

int pedenumero(){
        int a,b=1;
        while(b){
                printf("Digite um numero par maior que 2: ");
                scanf("%i",&a);
                if(a%2 == 0)b=0;
                if(a < 2)b=1;
        }
        return a;
}

int chato(int n){
        for(int i = 2;i < n;i++){
                if(primo(i)){
                        for(int j = n;j > 0;j--){
                                if(primo(j)){
                                        if(i+j==n){
                                                printf("%i e igual a %i + %i\n",n,i,j);
                                                return 0;
                                        }
                                }
                                else continue;
                        }
                }
                else continue;
        }
}

int main(){
        int borracha;
        for(int i = 0;i < 15;i++){
                borracha = pedenumero();
                chato(borracha);
        }
}
