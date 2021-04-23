#include <iostream>
#include "StackADT.h"

using namespace std;

template <typename T>
class LinkedListStack: public StackADT<T> {

private:
  class Node {
	  public:
	  	T data;
    		Node* next;
		Node(): next(NULL) {}
		Node(T data): data(data), next(NULL) {}
		~Node() {}
  };

  void copyLinkedNodes(Node*& dst, const Node* src) {
  	if(src == NULL) { 
		dst = NULL;
		return;
	}
	dst = new Node(src->data);
       	Node* prev = dst;
	Node* next = src->next;
	while(next != NULL) {
		prev->next = new Node(next->data);
		prev = prev->next;
		next = next->next;
	}
  }	  

  void deleteLinkedNodes(Node*& node) {
	while (node != NULL) {
		Node* remove = node;
		node = node->next;
		delete remove;
	}
  }

  int size;
  Node* top;

public:
  
  LinkedListStack(): size(0), top(NULL) {}

  LinkedListStack(const LinkedListStack& copy): size(size), top(NULL) {
	copyLinkedNodes(top, copy.top);
  }

  LinkedListStack(LinkedListStack&& temp): size(temp.size), top(temp.top) {
	  temp.top = NULL;
  }

  ~LinkedListStack() {
    deleteLinkedNodes(top);
  }

  LinkedListStack& operator = (const LinkedListStack& copy) {
	deleteLinkedNodes(top);
	copyLinkedNodes(top, copy.top);
	size = copy.size;
  }

  LinkedListStack& operator = (LinkedListStack&& temp) {
	  deleteLinkedNodes(top);	
	  top = temp.top;
	  size = temp.size;
	  temp.top = NULL;
  }

  void push(T element) {
    Node* node = new Node(element);
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
    return size == 0 || top == NULL;
  }

};
