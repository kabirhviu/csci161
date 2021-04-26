/**
 * @file -  StackADTMain.cpp
 * 
 * Uses both ArrayStack<T> and LinkedListStack<T> ploymorphically with StackADT<T> pointer.
 * ArrayStack<T> has implemented StackADT<T> using an array as the internal data structure for the stack elements.
 * LinkedListStack<T> has implemented StackADT<T> using a linked list as the internal data structure for the stack elements.
 *
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 0.0.1
 * @date - April 25, 2021
 *
 */


#include <iostream>
#include "StackADT.h"
#include "ArrayStack.cpp"
#include "LinkedListStack.cpp"

using namespace std;

int main(){

  StackADT<int>* stack = NULL;

  cout << "************** Testing Stack ADT with Runtime Polymorphism ***************" << endl;
  int choice = -1;
  cout<<"Which StackADT Implementation you want to use?"<<endl;
  cout<<"Enter <1> for ArrayStack and <2> for LinkedListStack: ";
  cin>>choice;
  switch (choice) {
	case 1:
		cout<<"Enter your ArrayStack capacity: ";
		int capacity;
		cin>>capacity;
		cout<<"Your entered ArrayStack capacity: "<<capacity<<endl;
		stack = new ArrayStack<int>(capacity);
		break;
	case 2:
		cout<<"You have chosen LinkedListStack."<<endl;
		stack =new LinkedListStack<int>();
		break;
	default:
		cout<<"Sorry! you did not choose a correct Stack implementation."<<endl;
		exit(-1);

  };
  

  cout << "StackADT<int> isEmpty: " << stack->isEmpty() << endl;
  cout << "StackADT<int> size: " << stack->getSize() << endl;

  try{
    stack->push(100);

    cout << "StackADT<int> isEmpty after pushing 100: " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after pushing 100: " << stack->getSize() << endl;
    cout << "StackADT<int> top after pushing 100: " << stack->peek() << endl;

    stack->push(200);

    cout << "StackADT<int> isEmpty after pushing 200: " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after pushing 200: " << stack->getSize() << endl;
    cout << "StackADT<int> top after pushing 200: " << stack->peek() << endl;

    stack->push(300);

    cout << "StackADT<int> isEmpty after pushing 300: " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after pushing 300: " << stack->getSize() << endl;
    cout << "StackADT<int> top after pushing 300: " << stack->peek() << endl;

    int popped = stack->pop();

    cout << "StackADT<int> isEmpty after popping: " << popped << ": " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after popping: " << popped << ": " << stack->getSize() << endl;
    cout << "StackADT<int> top after popping: " << popped << ": " << stack->peek() << endl;

    stack->push(300);

    int peeked = stack->peek();

    cout << "StackADT<int> isEmpty after peeking: " << peeked << ": " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after peeking: " << peeked << ": " << stack->getSize() << endl;
    cout << "StackADT<int> top after peeking: " << peeked << ": " << stack->peek() << endl;

    stack->push(400);
    stack->push(500);
    stack->push(600);
    stack->push(700);
    stack->push(800);
    stack->push(900);
    stack->push(1000);

    cout << "StackADT<int> isEmpty after pushing 1000: " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after pushing 1000: " << stack->getSize() << endl;
    cout << "StackADT<int> top after pushing 1000: " << stack->peek() << endl;

    stack->push(1100);
    cout << "StackADT<int> isEmpty after pushing 1100: " << stack->isEmpty() << endl;
    cout << "StackADT<int> size after pushing 1100: " << stack->getSize() << endl;
    cout << "StackADT<int> top after pushing 1100: " << stack->peek() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }
  int stackSize = stack->getSize();
  try{
    for (int i=0; i<stackSize; i++) {
      cout << "StackADT<int> pop(): " << stack->pop() << endl;
    }
    cout << "StackADT<int> pop(): " << stack->pop() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }

  cout << "************** End of Testing StackADT with Runtime Polymorphism  ***************" << endl;

  if(stack != NULL) {
  	delete stack;
  }

  return 0;
}
