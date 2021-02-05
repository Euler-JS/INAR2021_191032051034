#include <iostream>
#include "avl.h"
#include "heap.hpp"
#include "busca.h"
#include "rbtree.h"
#include <time.h>
#include <math.h>

using namespace std;

int existe(int *v, int n, int TAM)
{
	int i;
	for(i = 0; i < TAM; ++i) {
		if(v[i] == n) {
			return 1;
		}
	}
	return 0;
}
int proximoValor(int *v, int TAM)
{
	int r;
	srand((unsigned int)time((time_t *)NULL));
	do {
		r = rand() % (TAM+1);
	} while(existe(v, r, TAM)); // se o número já existe, randomiza de novo

	return r;
}
int main() {
  int heap[100],heap2[1000],heap3[10000],heap4[100000],v[100],v2[1000],v3[10000],v4[100000]; //Heap
  arvore *arv=NULL; //AVL
  TREE *arvore=NULL; //Busca
  ArvLLRB *raiz = NULL; //Rubro-Negra
  int x; 
  clock_t Ticks[2];
  double tempoHeap;
  double tempoAVL;
  double tempoBusca;
  double tempoRB;
  double media;
  double soma = 0;
  double somaDesv = 0;
  double tempos[10];
  double desvio;
  
  //Vetor com ordenação ascendente
  //Vetor de 100 elementos
  //Heap
  cout << "VETOR ORDENADO ASCENDENTE COM 100 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  for(int j=0;j<10;j++){
    for(int i=1;i<=100;i++)
      heap[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap,100);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim vetor de 100 elementos

  //Vetor de 1000 elementos
  //Heap
  cout << "\n\nVETOR ORDENADO ASCENDENTE COM 1000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=1000;i++)
      heap2[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap2,1000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 1000 elementos

  //Vetor de 10000 elementos
  //Heap
  cout << "\n\nVETOR ORDENADO ASCENDENTE COM 10000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=10000;i++)
      heap3[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap3,10000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 10000 elementos

  //Vetor de 100000
  //Heap
  cout << "\n\nVETOR ORDENADO ASCENDENTE COM 100000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=100000;i++)
      heap4[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap4,100000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100000;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100000;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor  de 100000
  //Fim vetor com ordenação ascendente

  //Vetor com ordenação descendente
  //Vetor de 100 elementos
  //Heap
  cout << "\n\nVETOR ORDENADO DESCENDENTE COM 100 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=100;i>=1;i--)
      heap[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap,100);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=100;i>=1;i--)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=100;i>=1;i--)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=100;i>=1;i--){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 100 elementos

  //Vetor de 1000 elementos
  //Heap
  cout << "\n\nVETOR ORDENADO DESCENDENTE COM 1000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1000;i>=1;i--)
      heap2[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap2,1000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=1000;i>=1;i--)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=1000;i>=1;i--)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=1000;i>=1;i--){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 1000 elementos

  //Vetor de 10000 elementos
  //Heap
  cout << "\n\nVETOR ORDENADO DESCENDENTE COM 10000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=10000;i>=1;i--)
      heap3[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap3,10000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=10000;i>=1;i--)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=10000;i>=1;i--)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=10000;i>=1;i--){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 10000 elementos

  //Vetor de 100000
  //Heap
  cout << "\n\nVETOR ORDENADO DESCENDENTE COM 100000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=100000;i>=1;i--)
      heap4[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap4,100000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=100000;i>=1;i--)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=100000;i>=1;i--)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=100000;i>=1;i--){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,i);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 100000
  //Fim do vetor com ordenação descendente

  //Vetor aleartório
  //Vetor com 100 elementos
  for(int i=0;i<100;i++)
    v[i] = proximoValor(v,100);
  //Heap
  cout << "\n\nVETOR ALEARTÓRIO COM 100 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=100;i++)
      heap[i] = v[i-1];
    Ticks[0] = clock();
    criar_maxheap(heap,100);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++)
      arv = inserir(arv,v[i]);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++)
      arvore = insere_elemento(arvore,v[i]);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v[i]);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor com 100 elementos

  //Vetor de 1000 elementos
  for(int i=0;i<1000;i++)
    v2[i] = proximoValor(v2,1000);
  //Heap
  cout << "\n\nVETOR ALEARTÓRIO COM 1000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=1000;i++)
      heap2[i] = v2[i-1];
    Ticks[0] = clock();
    criar_maxheap(heap2,1000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++)
      arv = inserir(arv,v2[i]);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++)
      arvore = insere_elemento(arvore,v2[i]);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v2[i]);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 1000 elementos

  //Vetor de 10000 elementos
  for(int i=0;i<10000;i++)
    v3[i] = proximoValor(v3,100);
  //Heap
  cout << "\n\nVETOR ALEARTÓRIO COM 10000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=10000;i++)
      heap3[i] = v3[i-1];
    Ticks[0] = clock();
    criar_maxheap(heap3,10000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++)
      arv = inserir(arv,v3[i]);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++)
      arvore = insere_elemento(arvore,v3[i]);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v3[i]);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 10000 elementos

  //Vetor com 100000
  for(int i=0;i<100000;i++)
    v4[i] = proximoValor(v4,100);
  //Heap
  cout << "\n\nVETOR ALEARTÓRIO COM 100 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=100000;i++)
      heap4[i] = v4[i-1];
    Ticks[0] = clock();
    criar_maxheap(heap4,100000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100000;i++)
      arv = inserir(arv,v4[i]);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100000;i++)
      arvore = insere_elemento(arvore,v4[i]);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v4[i]);
    }
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor com 100000
  //Fim do vetor aleartório

  //Vetor 10% desordenado
  //Vetor com 100 elementos
  //Heap
  cout << "\n\nVETOR 10% DESORDENADO COM 100 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=10;i++)
      heap[i] = v[i-1];
    for(int i=11;i<=100;i++)
      heap[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap,100);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10;i++)
      arv = inserir(arv,v[i]);
    for(int i=10;i<100;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10;i++)
      arvore = insere_elemento(arvore,v[i]);
    for(int i=10;i<100;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v[i]);
    }
    for(int i=10;i<100;i++)
      raiz = insereNO(raiz,i);
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor com 100 elementos

  //Vetor com 1000 elementos
  //Heap
  cout << "\n\nVETOR 10% DESORDENADO COM 1000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=100;i++)
      heap2[i] = v2[i-1];
    for(int i=101;i<=1000;i++)
      heap2[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap2,1000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++)
      arv = inserir(arv,v2[i]);
    for(int i=100;i<1000;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++)
      arvore = insere_elemento(arvore,v2[i]);
    for(int i=100;i<1000;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<100;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v2[i]);
    }
    for(int i=100;i<1000;i++)
      raiz = insereNO(raiz,i);
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor com 1000 elementos

  //Vetor de 10000 elementos
  //Heap
  cout << "\n\nVETOR 10% DESORDENADO COM 10000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=1000;i++)
      heap3[i] = v3[i-1];
    for(int i=1001;i<=10000;i++)
      heap3[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap3,10000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++)
      arv = inserir(arv,v3[i]);
    for(int i=1000;i<10000;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++)
      arvore = insere_elemento(arvore,v3[i]);
    for(int i=1000;i<10000;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<1000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v3[i]);
    }
    for(int i=1000;i<10000;i++)
      raiz = insereNO(raiz,i);
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Vetor de 10000 elementos

  //Vetor de 100000 elementos
  //Heap
  cout << "\n\nVETOR 10% DESORDENADO COM 100000 ELEMENTOS" << endl << endl;
  cout << "Heap:" << endl;
  soma = 0;
  for(int j=0;j<10;j++){
    for(int i=1;i<=10000;i++)
      heap4[i] = v4[i-1];
    for(int i=10001;i<=100000;i++)
      heap4[i] = i;
    Ticks[0] = clock();
    criar_maxheap(heap4,100000);
    Ticks[1] = clock();
    tempoHeap = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //mostrar_heap(heap,100);
    soma = soma + tempoHeap;
    tempos[j] = tempoHeap; 
    printf("\nTempo gasto na execução %i: %g ms.", j+1, tempoHeap); 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);

  //Árvore AVL
  cout << endl << endl << "Arvore AVL: \n";
  soma = 0;
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++)
      arv = inserir(arv,v4[i]);
    for(int i=10000;i<100000;i++)
      arv = inserir(arv,i);
    Ticks[1] = clock();
    tempoAVL = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvore(arv);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoAVL); 
    soma = soma + tempoAVL;
    tempos[j] = tempoAVL; 
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arv = NULL;

  //Árvore binária de busca
  soma = 0;
  cout << endl << endl << "Arvore de Busca: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++)
      arvore = insere_elemento(arvore,v4[i]);
    for(int i=10000;i<100000;i++)
      arvore = insere_elemento(arvore,i);
    Ticks[1] = clock();
    tempoBusca = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //EmOrdem(arvore);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoBusca);
    soma = soma + tempoBusca;
    tempos[j] = tempoBusca;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  somaDesv = 0;
  printf("\nDesvio padrao: %g ms.",desvio);
  arvore = NULL;

  //Árvore Rubro-Negra
  soma = 0;
  cout << endl << endl << "Arvore Rubro-Negra: \n";
  for(int j=0;j<10;j++){
    Ticks[0] = clock();
    for(int i=0;i<10000;i++){
      //x = insere_ArvLLRB(raiz,i);
      raiz = insereNO(raiz,v4[i]);
    }
    for(int i=10000;i<100000;i++)
      raiz = insereNO(raiz,i);
    Ticks[1] = clock();
    tempoRB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    //imp_arvoreRB(raiz);
    printf("\nTempo gasto na execução %i: %g ms.", j+1,tempoRB);
    soma = soma + tempoRB;
    tempos[j] = tempoRB;
  }
  media = soma/10;
  printf("\nMedia de tempo gasto: %g ms.",media);
  for(int i=0;i<10;i++)
    somaDesv = somaDesv + pow(media-tempos[i],2);
  desvio = somaDesv/10;
  printf("\nDesvio padrao: %g ms.",desvio);
  raiz = NULL;
  //Fim do vetor de 100000 elementos
  //Fim do vetor 10% desordenado
}