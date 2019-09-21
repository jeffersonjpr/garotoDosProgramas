#include "exercicio-binaria.h"
#include "travessia.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printa(NoArvBinaria *no){
	printf("(");
	if(no == NULL){
		printf(") ");
		return;
	}
	printf("%i ",no -> chave);
	printa(no -> esq);
	printa(no -> dir);
	printf(") ");
}

int scanzao(){
        int k;
        printf("Digite a chave:");
        scanf("%i",&k);
        return k;
}
int main(){
        srand(time(NULL));
        int n = 1,k,*vet;
        NoArvBinaria *raiz = NULL, *auxp= NULL, **auxpp = NULL,*raiz2 = NULL;

        while(n){
                printf("\n0 para sair\n");
                printf("1 para inserir rec\n");
                printf("2 para inserir ite\n");
                printf("3 para printar\n");
                printf("4 para buscar rec\n");
                printf("5 para buscar ite\n");
                printf("6 para busca end do menor\n");
                printf("7 para busca end do maior\n");
                printf("8 para busca endeco do ponteiro\n");
                printf("9 para busca endeco do ponteiro\n");
                printf("10 para busca endeco do ponteiro\n");
                printf("travessia\n");
                printf("11 para printar PREORDEM\n");
                printf("12 para printar EMORDEM\n");
                printf("13 para printar POSORDEM\n");
                printf("14 para contar as folhas\n");
		printf("15 para printar decrescente\n" );
		printf("16 para ordenar vetor usando arvore\n");
		printf("17 para calcular a altura da arvore\n");

		printf("18 para inserir na segunda arvore\n");
		printf("19 para verificar se r2 esta contida em r1\n");


                printf("Digite sua opcao:");
                scanf("%i",&n);
                puts("");

                if (n == 1){
                        k = scanzao();
                        auxp = insereArvBinRec(&raiz,k);
                        if(auxp == NULL){
                                printf("FULL MEMORY\n");
                                return 0;
                        }
                        continue;
                }
                if (n == 2){
                        printf("Digite a chave:");
                        scanf("%i",&k);
                        auxp = insereArvBinIterativa(&raiz,k);
                        if(auxp == NULL){
                                printf("FULL MEMORY\n");
                                return 0;
                        }
                        continue;
                }
                if(n == 3){
                        printa(raiz);
                        puts("");
			printa(raiz2);
                        puts("");
                        continue;
                }
                if(n == 4){
                        printf("Digite a chave:");
                        scanf("%i",&k);
                        auxp = buscaArvBinRec(raiz,k);
                        if(auxp == NULL) printf("Chave nao esta contida na arvore\n");
                        else printf("Chave %i econtrada no endereco %p\n",auxp -> chave, auxp);
                        continue;
                }
                if(n == 5){
                        printf("Digite a chave:");
                        scanf("%i",&k);
                        auxp = buscaArvBinIterativa(raiz,k);
                        if(auxp == NULL) printf("Chave nao esta contida na arvore\n");
                        else printf("Chave %i econtrada no endereco %p\n",auxp -> chave, auxp);
                        continue;
                }
                if(n == 6){
                        auxp = buscaEnderecoDoMenor(raiz);
                        if(auxp == NULL) printf("Arvore vazia\n");
                        else printf("Menor elemento: %i\n",auxp -> chave);
                        continue;
                }
                if(n == 7){
                        auxp = buscaEnderecoDoMaior(raiz);
                        if(auxp == NULL) printf("Arvore vazia\n");
                        else printf("Maior elemento: %i\n",auxp -> chave);
                        continue;
                }
                if(n == 8){
                        k = scanzao();
                        auxpp = buscaEnderecoDoPonteiro(&raiz, k);
                        if(auxpp == NULL) printf("Chave nao encontrada\n");
                        else printf("Chave %i encontrada no endereco %p\n",(*auxpp) -> chave,*auxpp);
                        continue;
                }
                if(n == 9){
                        auxpp = buscaEnderecoDoPonteiroDoMenor(&raiz);
                        if(auxpp == NULL) printf("Arvore vazia\n");
                        else printf("Menor elemento: %i\n",(*auxpp) -> chave);
                        continue;
                }
                if(n == 10){
                        auxpp = buscaEnderecoDoPonteiroDoMaior(&raiz);
                        if(auxpp == NULL) printf("Arvore vazia\n");
                        else printf("Maior elemento: %i\n",(*auxpp) -> chave);
                        continue;
                }
		if(n == 11){
			preordem(raiz);
			puts("");
		}
		if(n == 12){
			emordem(raiz);
			puts("");
		}
		if(n == 13){
			posordem(raiz);
			puts("");
		}
		if(n == 14){
			k = 0;
			contafolhas(raiz, &k);
			printf("%i folhas\n",k);
		}
		if(n == 15){
			printadecrescente(raiz);
			puts("");
		}
		if(n == 16){
			printf("Digite o tamanho do vetor:");
			scanf("%i",&k);
			vet = (int*)malloc(sizeof(int) * k);
			if(vet == NULL) continue;
			for(int i = 0; i < k; i++){
				*(vet + i) = rand() % 100;
			}
			for(int i = 0; i < k; i++) printf("%i ",*(vet + i));
			puts("");
			ordenavetor(vet, k);
			for(int i = 0; i < k; i++) printf("%i ",*(vet + i));
			puts("");
			free(vet);
		}
		if(n == 17){
			calculaaltura(raiz);
			continue;
		}
		if(n == 18){
			k = scanzao();
			insereArvBinRec(&raiz2,k);
			continue;
		}
		if(n == 19){
			if(verificaContido(raiz,raiz2)){
				printf("Arvore r2 esta contida em r1!\n");
			}
			else printf("Arvore r2 nao esta contida em r1\n");
			continue;
		}
        }
}
