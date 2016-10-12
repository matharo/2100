#include "book.h"
#include "BSTNode.h"
#include "aqueue.h"
#include <iostream>

// Count the number of nodes in a binary tree
template <typename E>
int count(BinNode<E>* root) {  //returns 5
  if (root == NULL) return 0;  // Nothing to count
  return 1 + count(root->left())
           + count(root->right());
}

template <typename E>
int height(BinNode<E>* root) { //returns 3
  if (root == NULL) return 0;  

  int left = height(root->left());
  int right = height(root->right());

  if (left > right){return left+1;}
  else { return right+1; }
}

template <typename E>
int leaf_count(BinNode<E>* root) { //returns 3
  if (root == NULL) return 0;

  int left = leaf_count(root->left());
  int right = leaf_count(root->right());
  int sum = left+right;
  
  if (sum  == 0){return 1;}
  
  return sum; 
}

template <typename E>
int sum_nodes(BinNode<E>* root) { //returns 15
  if (root == NULL) return 0;

  int left = sum_nodes(root->left());
  int right = sum_nodes(root->right());
  int top = root->element();
  
  int sum = left + right + top;
  return sum;
}

template <typename E>
bool search(BinNode<E>* root, const E& val) {
  if (root == NULL) {return false;}

  if (root->element() == val){return true;}
  else{
   if (search(root->left(),val)) return true;
   if (search(root->right(),val)) return true;
  return false;}
}

template <typename E>
void print_tree(BinNode<E>* root) {
  if (root == NULL) return;
  
  cout << root->element() << endl;

  print_tree(root->left());
  print_tree(root->right());
}

template <typename E>
void print_tree_by_level(BinNode<E>* root) {
  if (root == NULL) {return;}
  
  AQueue<BinNode<E>*> list, nextL;
  list.enqueue(root);
  while (list->length()!=0){
    BinNode<E>* node = list.frontOf();
    if (node){
    list.enqueue(root->left());
    list.enqueue(root->right());
   
    while (list.length() !=0){
     cout<<list.dequeue()<<endl;}
    }
  }
  print_tree_by_level(root->left());
  print_tree_by_level(root->right());
  
}

int main()
{
  BSTNode<int,int>* root = new BSTNode<int,int>(1,1);
  BSTNode<int,int>* left = new BSTNode<int,int>(2,2);
  BSTNode<int,int>* right = new BSTNode<int,int>(3,3);
  left->setLeft(new BSTNode<int,int>(4,4));
  left->setRight(new BSTNode<int,int>(5,5));
  root->setLeft(left);
  root->setRight(right);
  print_tree(root);
  cout << " Node count = " << count(root) << endl;
  cout << " Height = " << height(root) << endl;
  cout << " Leaf count = " << leaf_count(root) << endl;
  cout << " Sum of node values = " << sum_nodes(root) << endl;
  for (int i=0; i <= 6; i++) {
    if (search(root, i)) {
      cout << "Found " << i << " in the tree..." << endl;
    }
    else {
      cout << "Did not find " << i << " in the tree..." << endl;
    }
  }
  print_tree_by_level(root);
}

