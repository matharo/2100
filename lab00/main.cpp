#include <iostream>
#include "Vector3D.cpp"
using namespace std;

int main(){

  Vector3D vector;

  for (int i = 0; i < 3; i++){

    int input;

    cout << "Enter a number (#" << i << ")" << endl;
    cin >> input;

    vector.setCoordinate(i,input); 

    vector.absoluteValue();

  }
  for (int i = 0; i < 3; i++){

    cout << vector.getCoordinate(i) << endl;
  } 
}

