#include <stdio.h>

int fib(int n){
        printf("hahah\n" );
        if(n <= 1) return 0;
        if(n <= 3) return 1;
        return fib(n-1) + fib(n-2);
}


int main(){
        int n;
        printf("Digite a posiçao: ");
        scanf("%i\n",&n);
        printf("Numero: %i\n",fib(n));
}
