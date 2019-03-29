#include <iostream>
#include "StackADT.h"

using namespace std;

template <typename T>
class LinkedListStack: public StackADT<T> {
private:
  struct Node {
    T data;
    Node* next;
  };
  int size;
  Node* top;

public:
  LinkedListStack() {
    size = 0;
    top = NULL;
  }

  ~LinkedListStack() {
    while (!isEmpty()){
      pop();
    }
  }

  void push(T element) {
    Node* node = new Node;
    node->data = element;
    node->next = top;
    top = node;
    size++;
  }

  T pop() {
    if(top != NULL) {
      Node* node = top;
      T data = node->data;
      top = node->next;
      delete node;
      size--;
      return data;
    }
    else {
      throw "Stack is Empty!";
    }
  }

  T peek() {
    if( top != NULL) {
      return top->data;
    }
    else {
      throw "Stack is Empty";
    }
  }

  int getSize() {
    return size;
  }

  bool isEmpty() {
    return size == 0;
  }

};
