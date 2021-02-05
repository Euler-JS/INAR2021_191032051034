#include <stdio.h>
#include <stdlib.h>

#define RED 1 //Define as cores
#define BLACK 0
int resp;
int cont = 0;
typedef struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
  int cor;
}ArvLLRB;

int cor(struct NO *H){ //Acessa a cor de um nó
  if(H == NULL)
    return BLACK;
  else
    return H->cor;
}
void trocaCor(struct NO *H){ //Inverte a cor do pai e dos filhos
  H->cor = !H->cor;
  if(H->esq != NULL)
    H->esq->cor = !H->esq->cor;
  if(H->dir != NULL)
    H->dir->cor = !H->dir->cor;
}
struct NO* rotacionaEsquerda(struct NO *A){
  struct NO *B = A->dir;
  A->dir = B->esq;
  B->esq = A;
  B->cor = A->cor;
  A->cor = RED;
  return B;
}
struct NO* rotacionaDireita(struct NO *A){
  struct NO *B = A->esq;
  A->esq = B->dir;
  B->dir = A;
  B->cor = A->cor;
  A->cor = RED;
  return B;
}
// Se o filho a esquerda do filho direito é vermelho, aplica uma rotação à direita no filho direito e uma rotação esquerda no pai. Trcoa as cores do nó pai e de seus filhos.
struct NO* move2EsqRED(struct NO* H){
  trocaCor(H);
  if(cor(H->dir->esq)==RED){
    H->dir = rotacionaDireita(H->dir);
    H = rotacionaEsquerda(H);
    trocaCor(H);
  }
  return H;
}
//Se o filho a esquerda do filho esquerdo é vermelho, aplica uma rotação à direita no pai. Troca a cor do pai e de seus filhos
struct NO* move2DirRED(struct NO* H){
  trocaCor(H);
  if(cor(H->esq->esq)==RED){
    H = rotacionaDireita(H);
    trocaCor(H);
  }
  return H;
}
struct NO* balancear(struct NO* H){
  //Nó vermelho é sempre filho à esquerda
  if(cor(H->dir)==RED)
    H = rotacionaEsquerda(H);
  //Filho da direita e neto da esquerda são vermelhos
  if(H->esq != NULL && cor(H->dir)==RED && cor(H->esq->esq)==RED)
    H = rotacionaDireita(H);
  //2 filhos vermelhos: troca a cor!
  if(cor(H->esq)==RED && cor(H->dir)==RED)
    trocaCor(H);
  return H;
}
struct NO* insereNO(struct NO* H,int valor){
  if(H == NULL){
    struct NO *novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL){
      resp = 0;
      return NULL;
    }
    novo->info = valor;
    novo->cor = RED;
    novo->dir = NULL;
    novo->esq = NULL;
    resp = 1;
    //if(cont == 0)
      //novo->cor = BLACK;
    //cont ++;
    return novo;
  }
  if(valor == H->info)
    resp = 0;
  else{
    if(valor < H->info)
      H->esq = insereNO(H->esq,valor);
    else
      H->dir = insereNO(H->dir,valor);
  }
  if(cor(H->dir)==RED && cor(H->esq)==BLACK)
    H = rotacionaEsquerda(H);
  if(cor(H->esq)==RED && cor(H->esq->esq)==RED)
    H = rotacionaDireita(H);
  if(cor(H->esq)==RED && cor(H->dir)==RED)
    trocaCor(H);
  return H;
}
//Função responsável pela busca do local de inserção do nó
/*int insere_ArvLLRB(ArvLLRB *raiz, int valor){
  //int resp;
  *raiz = insereNO(raiz,valor);
  if((*raiz) != NULL)
    *raiz->cor = BLACK;
  return resp;
}*/
void imp_arvoreRB(ArvLLRB *parvRB){
  if(parvRB!=NULL){	
		imp_arvoreRB(parvRB->esq);
    printf("%i(Cor:%i) ",parvRB->info,parvRB->cor);
    imp_arvoreRB(parvRB->dir);
  }
}