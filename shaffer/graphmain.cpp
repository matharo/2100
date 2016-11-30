#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "book.h"
#include "grlist.h"
#include "alist.h"
#include "grmat.h"
#include "grdijkl1.cpp"
#include "grdijkm1.cpp"
using namespace std;

void importCSV(string input, AList<string>* vert){
  ifstream file;
  file.open(input.c_str());
  string value;
  while (getline(file,value)){
    int comma = value.find(',');
    int strlength = (value.length())-1;
    string s1 = value.substr(0,comma);
    string s2 = value.substr(comma+1,strlength-(comma+1));
    int var1 = 0; //when 0, means s1/s2 not in AList
    int var2 = 0; //when 1, means already in AList
    int length = vert->length(); //length of AList
    if (length == 0){ //if empty AList
     vert->append(s1); 
     var1=1;
     vert->append(s2); 
     var2=1;
    }
    else {
     for (vert->moveToStart(); vert->currPos() < vert->length(); vert->next()){
      if (vert->getValue() == s1){ var1 = 1;}
      if (vert->getValue() == s2){ var2 = 1;}
     }
    }
   if (var1 == 0){vert->append(s1)};
   if (var2 == 0){vert->append(s2)};
  }
  file.close();
}

Graphl* createGraphl(string input, AList<string>* vert){
  ifstream file;
  int numVert = vert->length();
  file.open(input.c_str());
  Graphl* csvGraph = new Graphl(vert->length());
  string value;
  while (getline(file,value)){
    int comma = value.find(',');
    int strlength = (value.length())-1;
    string s1 = value.substr(0,comma);
    string s2 = value.substr(comma+1,strlength-(comma+1));
    int inS1;
    int inS2;
    for (vert->moveToStart(); vert->currPos() < vert->length(); vert->next()){
      if (vert->getValue() == s1){ inS1 = vert->currPos();}
      else if (vert->getValue() == s2){ inS2 = vert->currPos();}
    }
    csvGraph->setEdge(inS1,inS2,1);
  }
 file.close();
 return csvGraph;
}

Graphm* createGraphm(string input, AList<string>* vert){
  ifstream file;
  int numVert = vert->length();
  file.open(input.c_str());
  Graphm* csvGraph = new Graphm(vert->length());
  string value;
  while (getline(file,value)){
    int comma = value.find(',');
    int strlength = (value.length())-1;
    string s1 = value.substr(0,comma);
    string s2 = value.substr(comma+1,strlength-(comma+1));
    int inS1;
    int inS2;
    for (vert->moveToStart(); vert->currPos() < vert->length(); vert->next()){
      if (vert->getValue() == s1){ inS1 = vert->currPos();}
      else if (vert->getValue() == s2){ inS2 = vert->currPos();}
    }
    csvGraph->setEdge(inS1,inS2,1);
  }
 file.close();
 return csvGraph;
}


int main(){
  string input = "test.csv";
  AList<string> vert(100000);
  importCSV(input,&vert);
  Graphl* Grl = createGraphl(input, &vert);
  Graphm* Grm = createGraphm(input, &vert);
  ofstream outputgrl("output.csv");
  ofstream outputgrm("output2.csv");
  Grl->exportCSV(outputgrl,&vert);
  Grm->exportCSV(outputgrm,&vert);
  
  int D[Grm->n()];
  for (int i = 0; i < Grl->n();i++){
   D[i] = INFINITY;
  }
  D[0]=0;
  Dijkstra(Grm,D,0);
  for (int k = 0; k<Grm->n();k++){
   cout<<D[k]<<endl;
  }
  cout<<endl;
 
  clock_t t1,t2;
  t2 = clock();
  float diff((float)t2 + (float)t1);
  cout << diff << endl;
 
  delete [] Grl;
  delete [] Grm;

  return 0;
}
