// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Dijkstra's single-source shortest paths algorithm
// Version 2: Use a priority queue to keep track of which vertex
// is the next closest.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"

#include "grlist.h"
#include "heap.h"

int minVertex(Graph*, int*);

// Simple class to represent objects to be stored in the priority queue
// Store a vertex and its best known distance
class DijkElem {
public:
  int vertex, distance;
  DijkElem() { vertex = -1; distance = -1; }
  DijkElem(int v, int d) { vertex = v; distance = d; }
};

// Comparator class for comparing DijkElem's
class DDComp {
public:
  static bool prior(DijkElem x, DijkElem y)
    { return x.distance < y.distance; }
};

// Dijkstra's shortest paths algorithm with priority queue
void Dijkstra(Graph* G, int* D, int s) {
  int i, v, w;            // v is current vertex
  DijkElem temp;
  DijkElem E[G->e()];     // Heap array with lots of space
  temp.distance = 0; temp.vertex = s;
  E[0] = temp;            // Initialize heap array
  heap<DijkElem, DDComp> H(E, 1, G->e()); // Create heap
  for (i=0; i<G->n(); i++) {         // Now, get distances
    do {
      if (H.size() == 0) return; // Nothing to remove
      temp = H.removefirst();
      v = temp.vertex;
    } while (G->getMark(v) == VISITED);
    G->setMark(v, VISITED);
    if (D[v] == INFINITY) return;    // Unreachable vertices
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > (D[v] + G->weight(v, w))) { // Update D
        D[w] = D[v] + G->weight(v, w);
        temp.distance = D[w]; temp.vertex = w;
        H.insert(temp);   // Insert new distance in heap
      }
  }
}


// Test Dijkstra's algorithm with priority queue
// Version for Adjancency List representation
int main(int argc, char** argv) {
  int size;
  cout<<"Size: (-1 to exit) "<<endl;
  cin>> size;
  if (size == -1){return 0;}
  Graph* G;
  G = graphDense<Graphl>(size); //change to graphDense or graphSparse

  clock_t t1;
  t1 = clock();

  int D[G->n()];
  for (int i=0; i<G->n(); i++)     // Initialize
    D[i] = INFINITY;
  D[0] = 0;

  Dijkstra(G, D, 0);
  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;

  float diff (clock()-t1);
  float seconds = diff/CLOCKS_PER_SEC;
  cout<<"Runtime:"<<seconds<<endl;

  cout<<"Vertices:"<<G->n()<<endl;
  cout<<"Edges:"<<G->n()<<endl;
  return 0;
}
