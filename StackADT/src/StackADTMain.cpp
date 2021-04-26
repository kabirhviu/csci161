#include <iostream>
#include "StackADT.h"
#include "ArrayStack.cpp"
#include "LinkedListStack.cpp"

using namespace std;

int main(){

  StackADT<int>* stack = NULL;

  cout << "************** Testing Stack ADT with Runtime Polymorphism ***************" << endl;
  int choice = -1;
  cout<<"Which Stack Implementation you want to use?"<<endl;
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
  

  cout << "Stack isEmpty: " << stack->isEmpty() << endl;
  cout << "Stack size: " << stack->getSize() << endl;

  try{
    stack->push(100);

    cout << "Stack isEmpty after pushing 100: " << stack->isEmpty() << endl;
    cout << "Stack size after pushing 100: " << stack->getSize() << endl;
    cout << "Stack top after pushing 100: " << stack->peek() << endl;

    stack->push(200);

    cout << "Stack isEmpty after pushing 200: " << stack->isEmpty() << endl;
    cout << "Stack size after pushing 200: " << stack->getSize() << endl;
    cout << "Stack top after pushing 200: " << stack->peek() << endl;

    stack->push(300);

    cout << "Stack isEmpty after pushing 300: " << stack->isEmpty() << endl;
    cout << "Stack size after pushing 300: " << stack->getSize() << endl;
    cout << "Stack top after pushing 300: " << stack->peek() << endl;

    int popped = stack->pop();

    cout << "Stack isEmpty after popping: " << popped << ": " << stack->isEmpty() << endl;
    cout << "Stack size after popping: " << popped << ": " << stack->getSize() << endl;
    cout << "Stack top after popping: " << popped << ": " << stack->peek() << endl;

    stack->push(300);

    int peeked = stack->peek();

    cout << "Stack isEmpty after peeking: " << peeked << ": " << stack->isEmpty() << endl;
    cout << "Stack size after peeking: " << peeked << ": " << stack->getSize() << endl;
    cout << "Stack top after peeking: " << peeked << ": " << stack->peek() << endl;

    stack->push(400);
    stack->push(500);
    stack->push(600);
    stack->push(700);
    stack->push(800);
    stack->push(900);
    stack->push(1000);

    cout << "Stack isEmpty after pushing 1000: " << stack->isEmpty() << endl;
    cout << "Stack size after pushing 1000: " << stack->getSize() << endl;
    cout << "Stack top after pushing 1000: " << stack->peek() << endl;

    stack->push(1100);
    cout << "Stack isEmpty after pushing 1100: " << stack->isEmpty() << endl;
    cout << "Stack size after pushing 1100: " << stack->getSize() << endl;
    cout << "Stack top after pushing 1100: " << stack->peek() << endl;
  }
  catch (const char* msg){
      cerr << "Push Error: " << msg << endl;
  }
  int stackSize = stack->getSize();
  try{
    for (int i=0; i<stackSize; i++) {
      cout << "popped: " << stack->pop() << endl;
    }
    cout << "popped: " << stack->pop() << endl;
  }
  catch (const char* msg){
      cerr << "Pop Error: " << msg << endl;
  }

  cout << "************** End of Testing StackADT with Runtime Polymorphism  ***************" << endl;

  if(stack != NULL) {
  	delete stack;
  }

  return 0;
}
