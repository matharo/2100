// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.
//

#include <iostream>

using namespace std;
class Graph {
private:
  void operator =(const Graph&) {}     // Protect assignment
  Graph(const Graph&) {}         // Protect copy constructor

public:
  Graph() {}          // Default constructor
  virtual ~Graph() {} // Base destructor

  // Initialize a graph of n vertices
  virtual void Init(int n) =0;

  // Return: the number of vertices and edges
  virtual int n() const =0;
  virtual int e() const =0;

  // Return v's first neighbor
  virtual int first(int v) const =0;

 // Return v's next neighbor
  virtual int next(int v, int w) const =0;

  // Set the weight for an edge
  // i, j: The vertices
  // wgt: Edge weight
  virtual void setEdge(int v1, int v2, int wght) =0;
  // i, j: The vertices
  virtual void delEdge(int v1, int v2) =0;

  // Determine if an edge is in the graph
  // i, j: The vertices
  // Return: true if edge i,j has non-zero weight
  virtual bool isEdge(int i, int j) const =0;

  // Return an edge's weight
  // i, j: The vertices
  // Return: The weight of edge i,j, or zero
  virtual int weight(int v1, int v2) const =0;

  // Get and Set the mark value for a vertex
  // v: The vertex
  // val: The value to set
  virtual int getMark(int v) const =0;
  virtual void setMark(int v, int val) =0;


  void exportCSV(ostream& o) const{ //save graph as CSV 
   for (int i = 0; i < n(); i++){
    for (int j = 0; j < n(); j++){
     if (isEdge(i,j)){
      o << i << ";" << j << endl;
     }}}}

  void exportGDF(ostream& o) const{
   for (int i = 0; i < n(); i++){
    for (int j = 0; j < n(); j++){
     if (isEdge(i,j)){
      o << i << "," << j << endl;
  }}}}
};
