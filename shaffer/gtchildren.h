#include "book.h"
#include "gentree.h"
#include "llist.h"

template <typename E>
class GTChild : public GTNode {

private:
  E val;
  LList<GTChild*> children; //list containing pointers to children 
  GTNode<E>* parnt;

public:
  E value() { return val; }

  bool isLeaf(){
   if (children->length()==0) {return true;} //if list is empty
   else {return false;}

  GTNode* parent() {return parnt; }

  GTChild* leftmostChild() {
   children->moveToStart();
   return children->getValue(); 
  }

  GTChild* rightSibling() {
   LList<GTChild*> list = parnt->children; //get list of children from parent
   list.moveToStart(); //go to start
  //while (list->element() != this) //while each el does not equal to curr el
  // { 
  //   list->next(); //check next el
  // }
   return list->next()->element(); //get element right of curr element   
  }

  void setValue(E& value){
   children.getValue() /*->element()*/ = value;
  }

  void insertFirst(GTChild<E>* child){
   children->next() = child;}

  void insertNext(GTChild<E>* next){
   children->next()->next() = next;}

//  void removeFirst(){
    

//  void removeNext(){
};
