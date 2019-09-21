#include "exercicio-binaria.h"

/*
struct NoArvBinaria
{
  int chave;
  struct NoArvBinaria * esq;
  struct NoArvBinaria * dir;
};

typedef struct NoArvBinaria NoArvBinaria;
*/



/*
 * PROCEDIMENTOS DE BUSCA CLASSICOS
 * devolve o endereco do no cujo valor chave eh k
 * ou NULL caso tal no nao exista na arvore enraizada
 * por raiz.
 */
NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k){
        if (raiz == NULL) return NULL;
        if (raiz -> chave == k) return raiz;
        if (raiz -> chave < k) return buscaArvBinRec (raiz -> dir, k);
        return buscaArvBinRec(raiz -> esq, k);
}

NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k){
        while (raiz != NULL){
                if (raiz -> chave == k) return raiz;
                if (raiz -> chave < k){
                        raiz = raiz -> dir;
                        continue;
                }
                raiz = raiz -> esq;
        }
        return NULL;
}

/*
 *  Para a função de busca abaixo atente para o fato de que
 *  a árvore indicada NAO é de pesquisa!
 */
NoArvBinaria *buscaAB(NoArvBinaria *raiz, int k){
        if (raiz == NULL) return NULL;
        if (raiz -> chave == k) return raiz;

        NoArvBinaria *aux = NULL;
        aux = buscaAB(raiz -> dir, k);
        if (aux != NULL) return aux;

        aux = buscaAB(raiz -> esq, k);
        return aux;
}


/*
 * PROCEDIMENTOS DE BUSCA DO MENOR/MAIOR
 * 1) devolve o endereco do no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 * 2) devolve o endereco do no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 */
NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz){
        if (raiz == NULL) return NULL;
        if (raiz -> esq == NULL) return raiz;
        return buscaEnderecoDoMenor(raiz -> esq);
}
NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz){
        if (raiz == NULL) return NULL;
        if (raiz -> dir == NULL) return raiz;
        return buscaEnderecoDoMaior(raiz -> dir);
}


/*
 * PROCEDIMENTO DE BUSCA DO ENDERECO DO PONTEIRO DO NO k
 * devolve o endereco onde est� armazenado o endereco do no
 * cujo valor chave eh k ou NULL caso tal no nao exista. O
 * no raiz da arvore dada esta armazenado no endereco *raiz.
 * Assuma que a arvore pode estar vazia, nesse caso *raiz==NULL.
 * i.e.: Para arvores nao vazias, a funcao deve devolver um
 * ponteiro x tal que a seguinte  condicao seja satisfeita:
 * (*x)->chave == k
 */
NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k){
        if (*raiz == NULL) return NULL;
        if((*raiz) -> chave == k) return raiz;

        if((*raiz) -> chave < k) return buscaEnderecoDoPonteiro(&(*raiz) -> dir, k);
        return buscaEnderecoDoPonteiro(&(*raiz) -> esq, k);
}


/*
 * PROCEDIMENTOS DE BUSCA DO ENDERECO DO PONTEIRO DO MENOR/MAIOR
 * 1) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
            tal que (*x)->chave eh o menor valor chave de toda a arvore dada
 * 2) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
 *          tal que (*x)->chave eh o maior valor chave de toda a arvore dada
 * O parametro de entrada raiz eh o endereco do ponteiro para o raiz
 * da arvore.
 */
NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz){
        if(*raiz == NULL) return NULL;
        if((*raiz) -> esq == NULL) return raiz;
        return buscaEnderecoDoPonteiroDoMenor(&(*raiz) -> esq);
}
NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz){
        if(*raiz == NULL) return NULL;
        if((*raiz) -> dir == NULL) return raiz;
        return buscaEnderecoDoPonteiroDoMaior(&(*raiz) -> dir);
}

/*
 * Assume que *folha aponta para um no folha
 * de uma arvore binaria de pesquisa qualquer.
 * O procedimento deve remover tal no.
 */
void removeFolha(NoArvBinaria **folha){
        free(*folha);
        *folha = NULL;
}

/*
 * Assume que *raiz != NULL
 * O no armazenado no endereco *raiz TEM NECESSARIAMENTE
 * UM FILHO ARMAZENADO EM (*raiz)->esq OU (exclusivo) (*raiz)->dir.
 * O procedimento deve remover o no armazenado em *raiz e
 * fazer com que *raiz passe a apontar pelo filho do no a
 * ser removido
 */
void removeNoComSomenteUmFilho(NoArvBinaria **raiz){
        NoArvBinaria *aux;
        if((*raiz) -> dir == NULL) aux = (*raiz) -> esq;
        else aux = (*raiz) -> dir;
        free(*raiz);
        *raiz = aux;
}

/*
 * PROCEDIMENTOS DE INSERCAO
 * insere um no com chave igual a k numa arvore binaria
 * de pesquisa dada. O no raiz da arvore dada esta armazenado
 * no endereco *raiz. Assuma que a arvore pode estar vazia
 * nesse caso *raiz==NULL.
 * Devolve o endereco do no recem criado ou o endereco do no
 * que ja contenha chave igual a k.
 */
NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k){
        if(*raiz == NULL){
                *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
                if( raiz == NULL) return NULL;
                (*raiz) -> chave = k;
                (*raiz) -> dir = (*raiz) -> esq = NULL;
                return *raiz;
        }
        if((*raiz) -> chave == k) return *raiz;
        if((*raiz) -> chave < k)
                return insereArvBinRec(&(*raiz) -> dir,k);
        return insereArvBinRec(&(*raiz) -> esq,k);
}

NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k){
        while(*raiz != NULL){
                if((*raiz) -> chave == k) return *raiz;
                if ((*raiz) -> chave < k){
                        raiz = &(*raiz) -> dir;
                        continue;
                }
                raiz = &(*raiz) -> esq;
        }

        *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
        if( raiz == NULL) return NULL;
        (*raiz) -> chave = k;
        (*raiz) -> dir = (*raiz) -> esq = NULL;
        return *raiz;
}

void removeArvBinRec(NoArvBinaria **raiz, int k){
        return;
}
