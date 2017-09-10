#include "book.h"
#include "job.h"
#include "maxJobCompare.h"
#include "heap.h"

class PriorityQueue{

private:
  heap<Job, maxJobCompare> h; //create heap object, define template

public:

  void enqueue(int jobID, int priority){ //inserting Job into heap
   Job j(jobID, priority); //create job object
   h.insert(j);
  }

  int dequeue(){ //remove Job with max priority val and return its jobID
   Job j = h.removefirst();
   return j.getJobID();
  }

  void changeweight(int jobID, int newPriority){ 
   //find Job with this jobID 
   //change its priority value to newPriority
   int i = 0;
   for (Job j = h[i]; j < h[h.size()];i++){ //for every Job in the heap array
    if (j.getJobID() == jobID){
     j.setPriorityVal(newPriority);
    }
   }
  }
};
