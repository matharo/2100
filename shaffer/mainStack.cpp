#include <iostream>
using namespace std;
#include "astack.h"

bool isBalanced(string input){

 int slength = input.length();
 AStack<char> stack(slength);
 for (string s : input){
  if (s == "(" or "[")
  { stack.push(s); }
  if (s == ")" or "]")
  { stack.pop(); }
 }
 if (stack.length() == 0)
 { return true ;}
 else { return false; }
}

int main(){

 string input;
 cout<<"Enter a string with parentheses: " <<endl;
 cin>>input;

 isBalanced(input);
};

