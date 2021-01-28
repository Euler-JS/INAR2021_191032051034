#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
  int num;//Valor(es) inserido(s) na árvore
  int fb;//Fator de balanceamento
  struct Arvore *esq;//Filho da esquerda
  struct Arvore *dir;//Filho da direita
}arvore;
int altura(arvore *arv){//Calcula a altura
  int he,hd;
  if(arv==NULL)
    return(0);
  if(arv->esq==NULL)
    he=0;
  else
    he=1+arv->esq->fb;
  if(arv->dir==NULL)
    hd=0;
  else
    hd=1+arv->dir->fb;
  if(he>hd)
    return(he);
  return(hd);
}
int fat_bal(arvore *arv){//Calcula o fator de balanceamento
  int he,hd;
  if(arv==NULL)
    return(0);
  if(arv->esq==NULL)
    he=0;
  else
    he=1+arv->esq->fb;
  if(arv->dir==NULL)
    hd=0;
  else
    hd=1+arv->dir->fb;
  return(he-hd);
  
}
arvore *rot_dir(arvore *arv){//Rotação à direita
  arvore *arv2;
  arv2=arv->esq;
  arv->esq=arv2->dir;
  arv2->dir=arv;
  arv->fb=altura(arv);
  arv2->fb=altura(arv2);
  return(arv2);
}
arvore *rot_esq(arvore *arv){//Rotação à esquerda
  arvore *arv2;
  arv2=arv->dir;
  arv->dir=arv2->esq;
  arv2->esq=arv;
  arv->fb=altura(arv);
  arv2->fb=altura(arv2);
  return(arv2);
}
arvore *rot_dup_dir(arvore *arv){//Rotação dupla à direita
  arv->esq=rot_esq(arv->esq);
  arv=rot_dir(arv);
  return(arv);
}
arvore *rot_dup_esq(arvore *arv){//Rotação dupla à esquerda
  arv->dir=rot_dir(arv->dir);
  arv=rot_esq(arv);
  return(arv);
}
arvore *inserir(arvore *arv, int num){//Insere elementos na árvore
  //Se a árvore estiver vazia cria a raíz
  if(arv==NULL){
    arv=(arvore*)malloc(sizeof(arvore));
    arv->num=num;
    arv->esq=NULL;
    arv->dir=NULL;
  }else{//Adiciona galhos e folhas
    if(num > arv->num){//Adiciona o valor informado à direita caso num>arv->num
      arv->dir=inserir(arv->dir,num);
      if(fat_bal(arv)==-2){//Testa o equilíbrio do lado direito
        if(num>arv->dir->num)
          arv=rot_esq(arv);//Rotação à esquerda
        else
          arv=rot_dup_esq(arv);//Rotação dupla à esquerda
      }
    }else{//Adiciona o valor informado à esquerda caso num<arv->num
      if(num<arv->num){
        arv->esq=inserir(arv->esq,num);
        if(fat_bal(arv)==2){//Testa o equilíbrio do lado esquerdo
          if(num<arv->esq->num)
            arv=rot_dir(arv);//Rotação à direita
          else
            arv=rot_dup_dir(arv);//Rotação dupla à direita
        }
      }
    }
    arv->fb=altura(arv);//Atualiza a altura
  }
  return(arv);
}
void imp_arvore(arvore *parv){
  if(parv!=NULL){	
		imp_arvore(parv->esq);
    printf("%i(FB:%i) ",parv->num,fat_bal(parv));
    imp_arvore(parv->dir);
  }
}