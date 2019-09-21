#include <stdio.h>

unsigned long long int vetfib[95];
//n maximo 20
unsigned long long int fat(unsigned long long int  n){
        if(n <= 1) return 1;
        return n * fat(n -1);
}


int main(){
        int n;
        printf("Calcular o fatorial de(0 ate 20): ");
        scanf("%i",&n);
        printf("Resultado: %llu\n",fat(n));
}
