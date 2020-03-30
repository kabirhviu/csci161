#include <iostream>
#include "StackADT.h"

using namespace std;

template <typename T>
class ArrayStack: public StackADT<T> {
private:
  int top;
  int capacity;
  T* elements;

public:
  ArrayStack(int capacity): top(-1), capacity(capacity), elements(new T[capacity]) { }

  ~ArrayStack() {
    delete [] elements;
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
