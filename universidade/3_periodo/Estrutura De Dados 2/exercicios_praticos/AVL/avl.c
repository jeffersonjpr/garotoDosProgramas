#include <stdio.h>
#include <stdlib.h>


typedef  struct noavl{
         int chave, fb;
         struct noavl *esq, *dir;
 } noavl;


void rotacaoesq(noavl **raiz){
        if(raiz == NULL || *raiz == NULL || (*raiz) -> dir == NULL) return;
        noavl  *aux;
        noavl *filho = (*raiz) -> dir;
        aux = filho -> esq;
        filho -> esq = *raiz;
        (*raiz) -> dir = aux;
        *raiz = filho;
}

void rotacaodir(noavl **raiz){
        if(raiz == NULL || *raiz == NULL || (*raiz) -> esq == NULL) return;
        noavl  *aux;
        noavl *filho = (*raiz) -> esq;
        aux = filho -> dir;
        filho -> dir = *raiz;
        (*raiz) -> esq = aux;
        *raiz = filho;
}

int altura(noavl *raiz){
        if(raiz == NULL) return 0;
        int dir = altura(raiz -> dir);
        int esq = altura(raiz -> esq);

        if(dir > esq) return dir + 1;
        return esq + 1;
}

int insereavl (noavl **raiz, int chave){
        // verifica se a arvore atual é vazia
        if (*raiz == NULL){
                *raiz = (noavl*)malloc(sizeof(noavl));
                *raiz -> chave = chave;
                *raix -> dir = *raiz -> esq = NULL;
                *raiz -> fb = 0; //no recem inserido sempre esta balanceado
                return 1;
        }

}


noavl **buscanoavl(noavl **raiz, int chave){
        if(raiz == NULL || *raiz == NULL) return NULL;
        if((*raiz) -> chave == chave){
                return raiz;
        }
        if((*raiz) -> chave < chave) return buscanoavl(&(*raiz) -> dir, chave);
        return buscanoavl(&(*raiz) -> esq, chave);
}

void insereabp(noavl **raiz, int chave){
        while (*raiz != NULL){
                if ((*raiz) -> chave < chave){
                        raiz = &(*raiz) -> dir;
                        continue;
                }
                raiz = &(*raiz) -> esq;
        }

        *raiz = (noavl*)malloc(sizeof(noavl));
        (*raiz) -> chave = chave;
        (*raiz) -> dir = (*raiz) -> esq = NULL;
        (*raiz) -> fb = 0;
}

void printa(noavl *no, int chave){
        if(chave == 1) printf("(");
        else printf("[");

	if(no == NULL){
                if(chave == 1) printf(")");
                else printf("]");
                return;
	}
	printf("%i ",no -> chave);
	printf("%i ",no -> fb);
	printa(no -> esq, chave * (-1));
	printa(no -> dir, chave * (-1));

        if(chave == 1) printf(")");
        else printf("]");
}

int main(){
        noavl *abp = NULL;
        int chave, n = 1;

        noavl **pai, **filho;

        while (n){
                printf("\n1 para inserir abp\n");
                printf("2 para rotacionar abp\n");
                printf("3 printar abp\n");

                printf("digite opcao:");
                scanf("%i",&n);

                if(n == 1){
                        printf("chave:" );
                        scanf("%i",&chave);
                        insereabp(&abp, chave);
                }
                if(n == 2){
                        printf("(1 esq 2 dir) chave:" );
                        scanf("%i %i",&chave, &n);
                        if(n == 1){
                                rotacaoesq(buscanoavl(&abp, chave));
                        }
                        if(n == 2){
                                rotacaodir(buscanoavl(&abp, chave));
                        }
                }

                if(n == 3){
                        printa(abp, 1);
                }
        }
}
