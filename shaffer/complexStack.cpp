#include "book.h"
#include "astack.h"
#include <iostream>
using namespace std;

bool checkExpression(string input){
  int len = input.length(); //length of string
  AStack<char> stack(len);

  stack.push('E');
  int i = 0; //index

  while (i < len){
   char c = input[i]; //first char in string
   if (stack.length() != 0){
    char s = stack.topValue(); //top element in stack
   
   if (c == ')' and s == ')'){
    stack.pop(); //pop )
    i++;
   }
   else if (c == '(' and s == '('){
    stack.pop(); //pop (
    i++;
   }
   else if (c == '*' or '+' and s == '0'){
    stack.pop(); //pop 0
    i++;
   }
   else if (isdigit(c) == true and s == 'E'){
    stack.pop(); //pop E 
    while (isdigit(input[i])==true) //as long as char is a digit
    {i++;} //increment it
   }
   else if (c == '(' and s == 'E'){
    stack.pop(); //pop E
    stack.push(')');
    stack.push('E');
    stack.push('0');
    stack.push('E');
    stack.push('(');
   }
   else {return false;}
  }
 }
 if (stack.length()==0){return true;}
 else{return false;}
}
int main()
{
  string input;
  cout << "enter expression" << endl;
  cin >> input;
  bool result = checkExpression(input);
  if (result==true)
   {cout<<"true"<<endl;}
  else
   {cout<<"false"<<endl;}
};
