#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 8

void max_heapfy(int v[], int n, int i){
        int esq = (2*i)+1;
        int dir = (2*i)+2;
        int maior;
        if(esq < n && v[i] < v[esq]) maior = esq; //verifica se o filho a esq é maior
        else maior = i;
        if(dir < n && v[maior] < v[dir]) maior = dir; //verifica se o filho a dir é maior

        if(maior != i){  //verifica se algum filho é maior
                int aux = v[i];
                v[i] = v[maior];
                v[maior] = aux;
                max_heapfy(v, n, maior);
        }
}

void constroi_heap(int v[], int n){
        for(int i = n/2; i >= 0; i--) max_heapfy(v,n,i);
}

void printa(int v[],int n){
        for(int i = 0; i < n; i++){
                printf("%i ",v[i]);
        }
        puts("");
}

void blank(int n){
        for(int i = 0; i< n; i++) printf("     ");
}
void printaarv(int v[], int n, int i, int space){
        int esq = 2*i+1;
        int dir = 2*i+2;

        if(dir < n) printaarv(v,n,dir,space + 1);
        else puts("");
        blank(space);
        printf("%i\n",v[i]);
        if(esq < n) printaarv(v,n,esq,space + 1);
        else puts("");
}


int isthisaheap2(int v[], int n, int i){
        if(i > n) return 0;
        int esq = 2*i+1;
        int dir = 2*i+2;
        if(dir < n && v[i] < v[dir]) return 1;
        if(dir < n && v[i] < v[esq]) return 1;
        if(isthisaheap2(v,n,esq)) return 1;
        if(isthisaheap2(v,n,dir)) return 1;
        return 0;
}

void isthisaheap(int v[], int n,int i){
        if(isthisaheap2(v,n,i)) puts("NAO É UM HEAP");
        else puts("é um heap");
}

int main(){
        srand(time(NULL));
        int aux;
        int v[tam];
        int teste[tam + 1];
        for (int i = 0; i < tam; i++) v[i] = rand()%100;
        printa(v,tam);
        isthisaheap(v,tam,0);
        constroi_heap(v,tam);
        printa(v,tam);
        isthisaheap(v,tam,0);
        printf("DIgite o numero:");
        scanf("%i",&aux);
        for(int i = 1; i < tam + 1; i++) teste[i] = v[i-1];
        teste[0] = aux;
        printa(teste,tam + 1);
        isthisaheap(teste,tam + 1,0);
        max_heapfy(teste,tam + 1,0);
        printa(teste,tam + 1);
        isthisaheap(teste,tam + 1,0);
        printaarv(teste,tam + 1, 0,0);


}
