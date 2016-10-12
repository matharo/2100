#include "queue.h"

template <typename E> class ADeque: public Queue<E>{

private:
  int maxSize;
  int front;
  int rear;
  E *listArray;

public:
  ADeque(int size = defaultSize){
   maxSize = size+1;
   rear = 0;
   front = 1;
   listArray = new E[maxSize];
 } 
  ~ADeque() {delete [] listArray;}
  void clear() {rear = 0; front = 1;}

  void enqueue(const E& it){
   Assert(((rear+2)%maxSize) != front, "Queue is full");
   rear = (rear+1)%maxSize;
   listArray[rear] = it;
  }

  E dequeue() {
   Assert(length()!=0,"Queue is empty");
   E it = listArray[front];
   front = (front+1)%maxSize;
   return it;
  }

  const E& frontValue() const{
   Assert(length()!=0,"Queue is empty");
   return listArray[front];
  }

  int length() const{return ((rear+maxSize)-front+1)%maxSize;}

  void enqueue_front(const E& it){
   Assert((rear+2)%maxSize)!=front,"Queue is full");
   front = (front-1)%maxSize;
   listArray[front]=it;
  }

  E dequeue_back(){
   Assert(length()!=0,"Queue is empty");
   E it = listArray[rear];
   rear = (rear-1)%maxSize;
   return it;
  }
} 
