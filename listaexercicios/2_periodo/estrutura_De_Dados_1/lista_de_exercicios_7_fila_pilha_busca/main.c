#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    InicioFim *x;
    x = (InicioFim*)malloc(sizeof(InicioFim));
    if(x == NULL) return 0;
    x -> inicio = x -> fim = NULL;
    for(i = 5; i >= 1; i--){
        InsereFila(x,i);
    }
    ImprimeFila(x);

}
