// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.


template <typename E> class List { // List ADT
private:
  void operator =(const List&) {}      // Protect assignment
  List(const List&) {}           // Protect copy constructor

public:
  List() {}          // Default constructor
  virtual ~List() {} // Base destructor

  // Clear contents from the list, to make it empty.
  void clear()
  { for (int i = 0; i < length(); i++)
     moveToEnd();
     remove();
  }

  // Insert an element at the current location.
  // item: The element to be inserted
  virtual void insert(const E& item) = 0;

  // Append an element at the end of the list.
  // item: The element to be appended.
  virtual void append(const E& item) = 0;

  // Remove and return the current element.
  // Return: the element that was removed.
  virtual  E remove() = 0;

  // Set the current position to the start of the list
  void moveToStart()
  { moveToPos(0); }

  // Set the current position to the end of the list
  void moveToEnd()
  {  moveToPos(length()); }

  // Move the current position one step left. No change
  // if already at beginning.
  void prev()
  { currPos()-1; }

  // Move the current position one step right. No change
  // if already at end.
  void next()
  { if (currPos() != length()-1)
    { currPos()+1; }
  }

  // Return: The number of elements in the list.
  virtual int length() const = 0;

  // Return: The position of the current element.
  virtual int currPos() const = 0;

  // Set current position.
  // pos: The position to make current.
  virtual void moveToPos(int pos) = 0;

  // Return: The current element.
  virtual const E& getValue() const = 0;

  bool find(const E& item)
  { 
    for (i = moveToStart(); i.currPos()<length();i.next()) //loop from start
    { if (i.getValue()==item) return true; //see if value is item
    }
      return false; //return false finish looping, and item not found
  }    
};
