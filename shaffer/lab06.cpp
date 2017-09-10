#include "book.h"
#include "BSTNode.h"
#include <iostream>
using namespace std;

template <typename E>
void printSorted(BinNode<E>* root){
  if (root==NULL) return;  
  printSorted(root->right());
  cout<<root->element()<<endl;
  printSorted(root->left());
}

template <typename E>
void printRange(BinNode<E>* root, E low, E high){
  if (root==NULL)return;
  if (root->element()>= low && root->element()<= high)
  { 
    printRange(root->left(),low,high);
    cout<<root->element()<<endl;
    printRange(root->right(),low,high);
  }}

template <typename E>
bool checkBST(BinNode<E>* root){
  if (root==NULL) return true;
  bool left = checkBST(root->left()); 
  bool right = checkBST(root->right());
  if (!left || !right) {return false;} // if either subtree fails the BST property, then whole tree does too!
  else {return true;}  //if left or right are both false = fail BTS prop = 0
  //if left/right == true/1 == 

  if (root->left() != NULL){
   if (root->left()->element() > root->element())
     return false;
   else
     return true; }

  if (root->right() != NULL){
   if (root->right()->element() < root->element())
     return false;
   else
     return true;}
}

int main(){
  BSTNode<int,int>* root = new BSTNode<int,int>(1,7);
  BSTNode<int,int>* left = new BSTNode<int,int>(2,5);
  BSTNode<int,int>* right = new BSTNode<int,int>(3,8);
  left->setLeft(new BSTNode<int,int>(4,1));
  left->setRight(new BSTNode<int,int>(5,6));
  root->setLeft(left);
  root->setRight(right);

  printSorted(root);
  cout<<endl;
  printRange(root,1,7);
  cout<<endl;
  if (checkBST(root) == true)
    {cout<<"true"<<endl;}
  else 
    {cout<<"false"<<endl;}
};
