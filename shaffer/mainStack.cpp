#include "book.h"
#include "astack.h"
#include <iostream>
using namespace std;

bool isBalanced(string input){
 AStack<char> stack(1000);
  for (int i = 0; i < stack.length(); i++){
   
   if (input[i] == '(' or '['){
    stack.push(input[i]);}
   else if (input[i] == ')' or ']'){
    
    if (stack.length()!=0)
     {stack.pop();} //if stack isn't empty, pop
    else
     {cout<<"no"<<endl;return false;}} //if stack is empty, break
  }
 
  if (stack.length()!=0)
   {cout<<"nop"<<endl;return false;}
  else
   {cout<< "yes"<<endl;return true;}
}

int count(string input){
  

int main(){
  string input;
  cout << "enter a string:" << endl;
  cin >> input;
  isBalanced(input);
};
