/**
 * @file -  LinkedListStack.cpp
 * 
 * Implements StackADT<T> using a linked list as the internal data structure for the stack elements.
 *
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 0.0.1
 * @date - April 25, 2021
 *
 */



#include <iostream>
#include "StackADT.h"

using namespace std;

template <typename T>
class LinkedListStack: public StackADT<T> {

private:
  
  /*
   * Node<T>
   * Private Inner class for LinkedListStack<T> class.
   * This class will be used only inside the LinkedListStack<T> class.
   * For that reason, its member variable data is not required to be encapsulated (private). 
   */
  class Node {
	  public:
	  	T data;
    		Node* next;
		Node(): next(NULL) {}
		Node(T data): data(data), next(NULL) {}
		~Node() {}
  };

  /*
   * @brief - Copies all the linked nodes from 'src' to 'dst'
   * 
   * Internal helper function for LinkedListStack<T> class to copy and link
   * all the linked nodes starting at the node 'src'.
   *
   * @param - dst - the first node of the copied and linked nodes.
   * @param - src - the first node of linked nodes that is being copied.
   */ 
  void deepCopy(Node*& dst, const Node* src) {
  	if(src == NULL) { 
		dst = NULL;
		return;
	}
	dst = new Node(src->data);
       	Node* copy = dst;
	Node* next = src->next;
	while(next != NULL) {
		copy->next = new Node(next->data);
		copy = copy->next;
		next = next->next;
	}
  }	  
  
  /*
   * @brief - Deletes all the linked nodes starting from 'node'.
   * 
   * Internal helper function for LinkedListStack<T> class to delete all the linked nodes starting at 'node'.
   *
   * @param - node - the first node of the linked nodes that are being deleted.
   */ 
  void deepClean(Node*& node) {
	while (node != NULL) {
		Node* remove = node;
		node = node->next;
		delete remove;
	}
  }

  int size;
  Node* top;

public:
  
  /*
   * Default constructor
   */
  LinkedListStack(): StackADT<T>::StackADT(), size(0), top(NULL) {
  	cout<<"LinkedListStack::default constructor......"<<endl;
  }

  /*
   * Copy constructor
   */
  LinkedListStack(const LinkedListStack& copy): StackADT<T>::StackADT(), size(copy.size), top(NULL) {
	deepCopy(top, copy.top);
	cout<<"LinkedListStack::copy constructor......"<<endl;
  }

  /*
   * Move constructor
   */
  LinkedListStack(LinkedListStack&& temp): StackADT<T>::StackADT(), size(temp.size), top(temp.top) {
	  temp.top = NULL;
	  cout<<"LinkedListStack::move constructor......"<<endl;
  }

  /*
   * Destructor
   */
  ~LinkedListStack() {
    deepClean(top);
    cout<<"LinkedListStack::destructor......."<<endl;
  }

  /*
   * Copy assignment operator
   */
  LinkedListStack& operator = (const LinkedListStack& copy) {
	if( *this == copy) {
		return *this;
	}
	deepClean(top);
	deepCopy(top, copy.top);
	size = copy.size;
	cout<<"LinkedListStack::copy assignment......"<<endl;
	return *this;
  }

  /*
   * Move assignment operator
   */
  LinkedListStack& operator = (LinkedListStack&& temp) {
	  if( *this == temp) {
		  return *this;
	  }
	  deepClean(top);	
	  top = temp.top;
	  size = temp.size;
	  temp.top = NULL;
	  cout<<"LinkedListStack::move assignment......"<<endl;
	  return *this;
  }


  /**
   * @brief - Pushes the element on the top of the stack and advances the top
   *
   * This function will be available to use with LinkedListStack<T> object and both LinkedListStack<T> and StackADT<T>
   * references.
   *
   * @param - element, the element to be pushed onto the stack.
   */ 
  void push(T element) override {
    Node* node = new Node(element);
    node->next = top;
    top = node;
    size++;
  }


   /**
   * @brief - Pops the top element of the stack and reverts the top
   *
   * This function will be available to use with LinkedListStack<T> object and both LinkedListStack<T> and StackADT<T>
   * references.
   *
   * @return - top element 
   */ 
  T pop() override {
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


   /**
   * @brief - Gives the top element of the stack and does not revert the top
   *
   * This function will be available to use with LinkedListStack<T> object and both LinkedListStack<T> and StackADT<T>
   * references.
   *
   * @return - top element 
   */ 
  T peek() override {
    if( top != NULL) {
      return top->data;
    }
    else {
      throw "Stack is Empty";
    }
  }


   /**
   * @brief - Gives the current size or the number of elements that has been pushed inot the stack but not popped yet.
   * 
   * This function will be available to use only with LinkedListStack<T> object or reference but not with a
   * StackADT<T> reference.
   *
   * @return - current size of the stack 
   */
  int getSize() override {
    return size;
  }


   /**
   * @brief - Returns true if the stack has no element to pop, false otherwise.
   * 
   * This function will be available to use only with LinkedListStack<T> object or reference but not with a
   * StackADT<T> reference.
   *
   * @return - true if the stack is empty.
   */
  bool isEmpty() override {
    return size == 0 || top == NULL;
  }

};
