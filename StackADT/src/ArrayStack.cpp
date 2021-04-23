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

  ArrayStack(): top(-1), capacity(capacity), elements(new T[capacity]) {}	  
  
  ArrayStack(int capacity): top(-1), capacity(capacity), elements(new T[capacity]) { }
  
  ArrayStack(const ArrayStack& copy): top(copy.top), capacity(copy.capacity), elements(new T[capacity]) {
	  for (int i=0; i<top; i++) {
		  elements[i] = copy.elements[i];
	  }
  }
  
  ArrayStack(ArrayStack&& temp): top(temp.top), capacity(temp.capacity), elements(temp.elements) {
	  temp.elements = NULL;
  }

  ~ArrayStack() {
    delete [] elements;
  }

  ArrayStack& operator = (const ArrayStack& copy) {
	top = copy.top;
	capacity = copy.capacity;
	delete [] elements;
	elements = new T[capacity];
	for ( int i=0; i<top; i++ ) {
		elements[i] = copy.elements[i];
	}
	return *this;
  }

  ArrayStack& operator = (ArrayStack&& temp) {
	  top = temp.top;
	  capacity = temp.capacity;
	  delete [] elements;
	  elements = temp.elements;
	  return *this;
  }

  int getCapacity() {
    return capacity;
  }

  void push(T element) {
    if(top<(capacity-1)){
      elements[++top] = element;
    }
    else {
      throw "Stack is Full!";
    }
  }

  T pop() {
    if(top != -1) {
      return elements[top--];
    }
    else {
      throw "Stack is Empty!";
    }
  }

  T peek() {
    if(top != -1) {
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
