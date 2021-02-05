#include <iostream>

using namespace std;

void mostrar_heap(int heap[],int n){
  cout << "\nHeap: ";
  for(int i=1;i<=n;i++){
    cout << heap[i] << " ";
  }
} 
void peneira(int heap[],int i, int n){
    int esq,dir,aux,maior;
    esq = 2*i;
    dir = 2*i + 1;
    maior = i;
    if(esq<=n && heap[esq]>heap[maior])
      maior = esq;
    if(dir<=n && heap[dir]>heap[maior])
      maior = dir;
    if(maior != i){
      aux = heap[i];
      heap[i] = heap[maior];
      heap[maior] = aux;
      peneira(heap,maior,n);
    }
}
void criar_maxheap(int heap[], int n){
  int i;
  for(i = n/2; i >= 1; i--){
    peneira(heap, i, n);
  }
}