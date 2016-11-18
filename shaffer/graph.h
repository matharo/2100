// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.
//

#include <string.h>
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

  // Delete an edge
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

#include <iostream>

  void importGDF(istream& in){
    string line = in.getline(); //first line
    while (line){
     AList<int> array;
     int stop = 0;
     line = in.ignore(' '); //ignore spaces
     for (char i : line){
      if (char i == ','){
       array.append(line.substr(stop,i-1);
       stop = i+1;
      }
      array.append(line.substr(stop,i)); //the string
     }
     int node1 = array[0];
     int node2 = array[1];
     int weight = array[2];
     setEdge(node1, node2, weight); //create edge

     line = in.getline(); //get next line
    }
  }

  void importCSV(istream& i) const{
   string line = i.getline();
   while (line){
    AList<int> array;
    int stop = 0;
    line = i.ignore(' ');
    for (int p = 0; p < line.length();p++){
     if (line[p] == ';'){
      array.append(line.substr(stop,p-1);
      stop = p+1;
     }
     array.append(line.substr(stop,p));
    
   node1 = array[0];
   node2 = array[1];
   weight = array[2];
   setEdge(node1,node2,weight);
   line = i.getline();
   }
  }

