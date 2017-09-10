//job class 

class Job{
private:
  int jobID;
  int priorityVal;

public:

  Job(int jobid, int pval)
  { jobID =  jobid;
    priorityVal = pval; }

  void setJobID(int id)
  { jobID = id; }

  void setPriorityVal(int pval)
  { priorityVal = pval; }

  int getJobID()
  { return jobID; }

  int getPriorityVal()
  { return priorityVal; }

};
