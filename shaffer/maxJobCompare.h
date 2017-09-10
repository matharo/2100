#include "job.h"

class maxJobCompare{

public:
  bool prior(Job job1, Job job2) //input two Job objects
  { 

    int pval1 = job1.getPriorityVal();
    int pval2 = job2.getPriorityVal();

    if (pval1 > pval2)
     {return true;}
    else {return false;}
  }
};
