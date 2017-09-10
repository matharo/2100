nclude "book.h"
#include <string>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include "alist.h"
#include "grlist.h"
#include "grmat.h"
#include "heap.h"
using namespace std;

int minVertex (Graph*, int*);

class DijkElem{
public:
	int vertex, distance;
	DijkElem() {vertex = -1; distance =-1;}
	DijkElem(int v, int d) {vertex =v; distance = d;}
};

class DDComp {
public:
	static bool prior (DijkElem x, DijkElem y)
		{ return x.distance < y.distance;}
};

void DijkstraPQ(Graph* Gr, int* D, int s){
	int i,v,w;
	DijkElem temp;
	DijkElem E[Gr->e()];
	temp.distance = 0; temp.vertex = s;
	E[0] = temp;
	heap <DijkElem, DDComp> H(E, 1, Gr->e());
	for (i=0; i<Gr->n();i++){
		do {
			if (H.size() == 0) return;
			temp = H.removefirst();
			v = temp.vertex;
			}
		while (Gr->getMark(v) == VISITED);
			Gr->setMark(v, VISITED);
			if (D[v] == INFINITY) return;
			for (w=Gr->first(v); w<Gr->n(); w= Gr->next(v,w))
				if (D[w] > (D[v] + Gr->weight(v,w))){
					D[w] = D[v] + Gr->weight(v,w);
					temp.distance = D[w]; temp.vertex=w;
					H.insert(temp);
				}
			}
}	




void Dijkstra(Graph* Gr, int* D, int s){
	int i,v,w;
	for (i=0; i<Gr->n();i++){
		v= minVertex(Gr,D);
		if (D[v] == INFINITY) return;
		Gr->setMark(v,VISITED);
		for (w=Gr->first(v); w<Gr->n(); w= Gr->next(v,w))
			if (D[w] > (D[v] + Gr->weight(v,w)))
				D[w] = D[v] + Gr->weight(v,w);
			}
		}

int minVertex(Graph* Gr, int* D){
	int i, v=-1;
	for (i=0; i< Gr->n(); i++){
		if (Gr->getMark(i) == UNVISITED) {v=i; break;}}
	for (i++; i< Gr->n(); i++){
		if ((Gr->getMark(i) == UNVISITED) && (D[i] < D[v]))
			v = i;}
	return v;
}

void importCSV(string input, AList<string>* vert){
	ifstream file;
	file.open(input.c_str());
	string value;
	while (getline(file,value)){
		int comma = value.find(',');
		int strlength = value.length();	
		string s1= value.substr(0,comma);
		string s2=value.substr(comma+1,strlength-(comma+1));
		int var1=0;
		int var2=0;
		int length= vert->length();
		if (length == 0){
			vert->append(s1);
			var1=1;
			vert->append(s2);
			var2=1;
			}
		else {
			for (vert->moveToStart(); vert->currPos() < vert->length(); vert->next()){
				if (vert->getValue() == s1){
					var1= 1;}
				if (vert->getValue() == s2){
					var2 = 1;}
				}
			}
		if (var1 == 0){vert->append(s1);}
		if (var2 == 0){vert->append(s2);}
		}
	file.close();
	
}
Graph* createGraphl(string input, AList<string>* vert){
	ifstream file;
	int numVert= vert->length();
	file.open(input.c_str());	
	Graphl* csvGraph = new Graphl(vert->length());
	string value;
	while (getline(file,value)){
		int comma = value.find(',');
		int strlength= value.length();
		string s1 = value.substr(0,comma);
		string s2 = value.substr(comma+1, strlength-(comma+1));
		int inS1;
		int inS2;
		for (vert->moveToStart(); vert->currPos() < vert->length(); vert->next()){
			if (vert->getValue() == s1){
				inS1= vert->currPos();}
			else if (vert->getValue() == s2){
				inS2= vert->currPos();}
		} 
		csvGraph->setEdge(inS1,inS2,1);}
	file.close();
	return csvGraph;
}

Graph* createGraphm(string input, AList<string>* vert){
	ifstream file;
	int numVert= vert->length();
	file.open(input.c_str());
	Graphm* csvGraph = new Graphm(vert->length());
	string value;
	while (getline(file, value)){
		int comma = value.find(',');
		int strlength = value.length();
		string s1= value.substr(0,comma);
		string s2 = value.substr(comma+1, strlength-(comma+1));
		int inS1;
		int inS2;
		for (vert->moveToStart(); vert->currPos() < vert->length(); vert->next()){
			if (vert->getValue() == s1){
				inS1= vert->currPos();}
			else if (vert->getValue() == s2){
				inS2=vert->currPos();}
		}
		csvGraph->setEdge(inS1, inS2, 1);}
	file.close();
	return csvGraph;
}


int main(){

string input="newexamplecsv.csv";
	AList<string> vert(10000);
	importCSV(input, &vert);
	Graph* Gr = createGraphl(input, &vert);

int D[Gr->n()];
	for (int i=0; i<Gr->n();i++)
		D[i] = INFINITY;
	D[0]=0;
	DijkstraPQ(Gr, D, 0);
	for (int k=0; k<Gr->n(); k++)
		cout<<D[k] << "\n";
	cout<<endl;

clock_t t1,t2;
	t1 = clock();
	t2 = clock();
	float diff =(float)t2;
	float seconds = diff/ CLOCKS_PER_SEC;
	cout << seconds << endl;

	return 0;
delete Gr;

}
