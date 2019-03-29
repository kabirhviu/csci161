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
  ArrayStack(int capacity) {
    this->capacity = capacity;
    this->elements = new T[capacity];
    this->top =-1;
  }

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
