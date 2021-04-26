#include <iostream>
#include "StackADT.h"

using namespace std;

#define DEFAULT_CAPACITY 100

template <typename T>
class ArrayStack: public StackADT<T> {
private:
  int top;
  int capacity;
  T* elements;

public:

  ArrayStack(): top(-1), capacity(DEFAULT_CAPACITY), elements(new T[capacity]) {
  	cout<<"ArrayStack::default constructor......."<<endl;
  }	  
  
  ArrayStack(int capacity): top(-1), capacity(capacity), elements(new T[capacity]) { 
  	cout<<"ArrayStack::regular constructor......."<<endl;
  }
  
  ArrayStack(const ArrayStack& copy): top(copy.top), capacity(copy.capacity), elements(new T[capacity]) {
	  for (int i=0; i<=top; i++) {
		  elements[i] = copy.elements[i];
	  }
	  cout<<"ArrayStack::copy constructor......."<<endl;
  }
  
  ArrayStack(ArrayStack&& temp): top(temp.top), capacity(temp.capacity), elements(temp.elements) {
	  temp.elements = NULL;
	  cout<<"ArrayStack::move constructor......"<<endl;
  }

  ~ArrayStack() {
	  if (elements != NULL) {
    		delete [] elements;
	  }
    cout<<"ArrayStack::destructor......"<<endl;
  }

  ArrayStack& operator = (const ArrayStack& copy) {
	top = copy.top;
	capacity = copy.capacity;
	delete [] elements;
	elements = new T[capacity];
	for ( int i=0; i<=top; i++ ) {
		elements[i] = copy.elements[i];
	}
	cout<<"ArrayStack::copy assignment......."<<endl;
	return *this;
  }

  ArrayStack& operator = (ArrayStack&& temp) {
	  top = temp.top;
	  capacity = temp.capacity;
	  delete [] elements;
	  elements = temp.elements;
	  temp.elements = NULL;
	  cout<<"ArrayStack::move assignment......"<<endl;
	  return *this;
  }

  int getCapacity() {
    return capacity;
  }

  void push(T element) {
    if(top < (capacity-1)){
      elements[++top] = element;
    }
    else {
      throw "Stack is Full!";
    }
  }

  T pop() {
    if(top > -1) {
      	    
      return elements[top--];
    }
    else {
      throw "Stack is Empty!";
    }
  }

  T peek() {
    if(top > -1) {
      return elements[top];
    }
    else {
      throw "Stack is Empty";
    }
  }

  int getSize() {
    return top+1;
  }

  bool isEmpty() {
    return top == -1;
  }

};
