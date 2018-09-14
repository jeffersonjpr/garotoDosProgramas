#include <bits/stdc++.h>
using namespace std;
int fibao[50];
///RUIMMMMMMMMM
int fiboRUIM(int n){
    if(n <= 1) return 1;
    return fiboRUIM(n - 1) + fiboRUIM(n - 2);
}
///RUIMMMMMMMMM
int fiboRUIM2(int n){
    if(n <= 1) return 1;
    return( 2 * fiboRUIM2(n - 2));
}

///MELHOR
int fibomelhor(int n){
    if(fibao[n]) return fibao[n];
    return fibao[n] = fibomelhor(n-1) + fibomelhor(n-2);
}

int main(){
    double duration;
    long long n = 40 ;
    clock_t start;
    fibao[0] = fibao[1] = 1;

    start = clock();
    printf("melhor %i:%i\n",n,fibomelhor(n));
    duration = clock() - start / (double) CLOCKS_PER_SEC;
    printf("Tempo :%lf\n\n",duration);

    start = clock();
    printf("Ruim 1 %i:%i\n",n,fiboRUIM(n));
    duration = clock() - start / (double) CLOCKS_PER_SEC;
    printf("Tempo :%lf\n\n",duration);

    start = clock();
    printf("Ruim 2 %i:%i\n",n,fiboRUIM2(n));
    duration = clock() - start / (double) CLOCKS_PER_SEC;
    printf("Tempo :%lf\n\n",duration);


}
