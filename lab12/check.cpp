#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// this implementation only tells us if the substring is there or not
// We could store indices at the *interior nodes* of the trie if
// we wanted to return the index of the first place where the substring occurs
bool findSubstring(const char* big, const char* small) {
  Trie t;
  int biglen = strlen(big);
  for (int i=0; i < biglen; i++) {
    t.insert(big+i,i);
  }
  return t.longestPrefix(small) == strlen(small);
};

void findUI(const char* b, const char* s) {
  if (findSubstring(b,s)) {
    cout << "String contains \"" << s << "\"!\n";
  }
  else {
    cout << "String does not contain \"" << s << "\"!\n";
  }
};

int main() {

  // the typical setup is that you want to search for many short strings
  // in one long string, so you can just build the trie once and then
  // search very quickly thereafter; we're not doing that here
  
  ifstream md;
  md.open("mobydick.txt");
  ifstream st("startrek.txt");

  string mString;
  string sString;

  while (!md.eof()){getline(md,mString);}
  while (!st.eof()){getline(st,sString);}

  int mLen = mString.length();
  int sLen = sString.length();

  char mobydick[mLen];
  char startrek[sLen];

  for (int i = 0; i < sLen; i++){
   strcat(startrek,&sString[i]); //add all text to char array
  }
  for (int i = 0; i < mLen; i++){
   strcat(mobydick,&mString[i]); //add all text to char array
  }

  md.close(); st.close();

  for (int i=0; i < sLen; i++){
   const char substring[i+1]; //holds at least 1 char
   //strncpy(substring,startrek,i);
   substring = startrek.substr(0,i);
   findUI(mobydick,&substring);//dest,str to be copied, num of chars copied
  }
  
  return 0;
};
