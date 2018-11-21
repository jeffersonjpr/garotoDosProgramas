#include "ordenacao.h"
/*
Jefferson Michael de Azevedo Junior 15/11/2018
*/

void Troca(int *x, int *y){
    int aux = *y;
    *y = *x;
    *x = aux;
}

void Merge(int *v, int ini, int meio, int fim){
    int aux[fim - ini + 1],i,j = ini;
    int indini = ini,indfim = meio + 1;
    for(i = 0; i < fim - ini + 1; i++){
        if(indini > meio){
            aux[i] = v[indfim++];
            continue;
        }
        if(indfim > fim){
            aux[i] = v[indini++];
            continue;
        }
        if(v[indini] < v[indfim]){
            aux[i] = v[indini++];
            continue;
        }
        else{
            aux[i] = v[indfim++];
        }
    }
    for(i = 0; i < fim - ini + 1; i++){
        v[j] = aux[i];
        j++;
    }
}

/*
BubbleSort
Considere o vetor v[6] = [34,13,51,0,78,14]
ini = 0 /fim = 5
*/
void BubbleSort(int *v, int ini, int fim){
    int chave = 0,i;
    while(!chave){
        chave = 1;
        for(i = ini; i < fim; i++){
            if(v[i] > v[i+1]){
                Troca(v + i,v + i + 1);
                chave = 0;
            }
        }
    }
}

/*
SelectionSort
Considere o vetor v[6] = [34,13,51,0,78,14]
ini = 0 /fim = 5
*/
void SelectionSort(int *v, int ini, int fim){
    if(ini >= fim) return;
    int menor = ini++,i;
    for(i = ini; i <= fim; i++) if(v[i] < v[menor]) menor = i;
    Troca(v + ini - 1,v + menor);
    SelectionSort(v,ini,fim);
}
/*
InsertionSort
Considere o vetor v[6] = [34,13,51,0,78,14]
ini = 0 /fim = 5
*/
void InsertionSort(int *v, int ini, int fim){
    if(fim <= ini) return;
    InsertionSort(v,ini,fim - 1);
    int aux = v[fim],i;
    for(i = fim -1; i >= ini; i--){
        if(v[i] > aux) Troca(v + i,v + i + 1);
        else{
            v[i + 1] = aux;
            return;
        }
    }
}
/*
QuickSort S2
Considere o vetor v[6] = [34,13,51,0,78,14]
ini = 0 /fim = 5
*/
void QuickSort(int *v, int ini, int fim){
    if(ini >= fim) return;
    //pivot = ini
    int i,pmaior = ini + 1;
    for(i = ini + 1; i <= fim; i++){
        if(v[i] < v[ini]) Troca(v + i,v + pmaior++);
    }
    Troca(v + ini,v + --pmaior);
    //elementos menores que o pivot
    QuickSort(v,ini,pmaior - 1);
    //elementos maioress que o pivot
    QuickSort(v,pmaior + 1,fim);

}
/*
ShellSort
Considere o vetor v[6] = [34,13,51,0,78,14]
ini = 0 /fim = 5
*/
void ShellSort(int *v, int ini, int fim){
    int i,h,n = fim - ini + 1,j;
    h = n / 2;
    while(h > 0){
        for(i = ini + h; i <= fim; i++){
            if(v[i] < v[i - h]){
                Troca(v + i,v+i - h);
                j = i - h;
                while(j - h >= ini){
                    if(v[j] < v[j - h]){
                        Troca(v + j, v + j - h);
                    }
                    j -= h;
                }
            }
        }
        h /= 2;
    }
}
/*
MergeSort
Considere o vetor v[6] = [34,13,51,0,78,14]
ini = 0 /fim = 5
*/
void MergeSort(int *v, int ini, int fim){
    if(ini >= fim) return;
    MergeSort(v,ini,(ini + fim) / 2);
    MergeSort(v,((ini + fim) / 2) + 1,fim);
    Merge(v,ini,(ini + fim) / 2,fim);
}
