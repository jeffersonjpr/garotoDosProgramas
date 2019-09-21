#include <stdio.h>

unsigned long long int vetfib[95];
//Ate a 94º da sequencia de fibonacci
unsigned long long int fib(int n){
        if(n < 0) return 0;
        if(vetfib[n]) return vetfib[n];
        return vetfib[n] = (fib(n-2) + fib(n-1));
}


int main(){
        unsigned long long int aux;
        int n;
        vetfib[0] = 0;
        vetfib[1] = 0;
        vetfib[2] = 1;
        vetfib[3] = 1;
        printf("Digite a posiçao(1 ate 94): ");
        scanf("%i",&n);
        printf("Numero: %llu\n",fib(n));
}
