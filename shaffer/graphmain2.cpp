#include "book.h"
#include "grmat.h"
#include "grlist.h"

int minVertex(Graph*, int*);

void Dijkstra(Graph* G, int* D, int s) {
  int i, v, w;
  for (i=0; i<G->n(); i++) {      // Process the vertices
    v = minVertex(G, D);
    if (D[v] == INFINITY) return; // Unreachable vertices
    G->setMark(v, VISITED);
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > (D[v] + G->weight(v, w)))
        D[w] = D[v] + G->weight(v, w);
  }
}

int minVertex(Graph* G, int* D) { // Find min cost vertex
  int i, v = -1;
  for (i=0; i<G->n(); i++)
    if (G->getMark(i) == UNVISITED) { v = i; break; }
  for (i++; i<G->n(); i++)  // Now find smallest D value
    if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
      v = i;
  return v;
}

Graphm* graphMatrix(int size){ //matrix
  E* graphm = new E(size);
  for (int i = 0; i < size; i++){
   for (int j = 0; j<size; j++){
    if (i!=j){
     int r = (rand()%(9-1))+1+1;
     graphm->setEdge(i,j,r);
    }
   }
  }
  return graphm;
}

Graphl* graphList(int size){ //list
  Graphl* graphl = new E(size);
  for (int i = 0; i < size; i++){
   int r = (rand()%(9-1))+1+1;
   graphl->setEdge(i,i+1,r);
  }
  return graphl;
}

int main(){
  int size;
  std::cout<<"Size = ";
  std::cin>>size;

  Graphm* G;
  
  G->graphMatrix<Graphm>(size);
  double start = clock();

  int D[G->n()];
  for (int i = 0; i < G->n(); i++){
    D[i] = INFINITY;
    D[0] = 0;
  }

  Dijkstra(G, D, 0);

  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;

  double duration = clock()-start)/CLOCKS_PER_SEC;
  std::cout<<duration<<endl;
  
  return 0;
}
