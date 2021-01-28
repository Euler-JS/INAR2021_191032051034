#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_no{
    int item;
    struct tipo_no *esq;
    struct tipo_no *dir;
}TREE;

TREE *insere_elemento(TREE *arvore, int item){
    if(arvore == NULL){
        arvore = (TREE *)malloc(sizeof(TREE));
        arvore->item = item;
        arvore->esq = NULL;
        arvore->dir = NULL;
    }else{
        if(item < arvore->item)
          arvore->esq=insere_elemento(arvore->esq,item);
        else
          //if(item > arvore->item)
          arvore->dir=insere_elemento(arvore->dir,item);
          //else
            //arvore->item = item;

    }
    return(arvore);
}
void PreOrdem (TREE *arvore){

    if(arvore != NULL){
        printf ("%i ", arvore->item);
        PreOrdem(arvore->esq);
        PreOrdem(arvore->dir);
    }
}
void EmOrdem(TREE *arvore){

    if(arvore != NULL){
        EmOrdem(arvore->esq);
        printf ("%i ", arvore->item);
        EmOrdem(arvore->dir);
    }
}
void PosOrdem (TREE *arvore){

    if(arvore != NULL){
        PosOrdem(arvore->esq);
        PosOrdem(arvore->dir);
        printf ("%i ", arvore->item);
    }
}