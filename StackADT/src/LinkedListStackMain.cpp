/**
 * @file -  LinkedListStackMain.cpp
 * 
 * Uses LinkedListStack<T> that has implemented StackADT<T> using a linked list as the internal data structure 
 * for the stack elements.
 *
 * @author - Humayun Kabir, Instructor, CSCI 161, VIU
 * @version - 0.0.1
 * @date - April 25, 2021
 *
 */




#include <iostream>
#include <string>
#include "StackADT.h"
#include "LinkedListStack.cpp"

using namespace std;

LinkedListStack<string> getColorStack() {
	int count = 7;
	string colors[] = {"Red", "Orange", "Yellow", "Green", "Cyan", "Blue", "Violet"};
	LinkedListStack<string> linkedliststack;
	for (int i = 0; i<count; i++) {
		linkedliststack.push(colors[i]);
	}
	return linkedliststack;
}

int main(){


  cout << "************** Testing LinkedListStack ***************" << endl;
  
  /*
   * LinkedListStack default constructor
   */
  LinkedListStack<double> linkedliststackdouble1;  

  cout << "LinkedListStack<double> default constructor..." << endl;
  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble1.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble1.getSize() << endl;

  try {
  cout << "LinkedListStack<double> pushing 10.01"<<endl;  
  linkedliststackdouble1.push(10.01);
  cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
  
  cout << "LinkedListStack<double> pushing 20.02"<<endl; 
  linkedliststackdouble1.push(20.02);
  cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 

  cout << "LinkedListStack<double> pushing 30.03"<<endl; 
  linkedliststackdouble1.push(30.03);
  cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 
  cout << "LinkedListStack<double> pushing 40.04"<<endl; 
  linkedliststackdouble1.push(40.04);
  cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 

  cout << "LinkedListStack<double> pushing 50.05"<<endl; 
  linkedliststackdouble1.push(50.05);
  cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 

  }
  catch (const char* excp) {
	  cout<<excp<<endl;
  }
  cout <<"LinkedListStack<double> after pushing 10.01, 20.02, 30.03, 40.04, and 50.05" << endl;
  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble1.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble1.getSize() << endl;

  try {
	cout << "LinkedListStack<double> pop(): " << linkedliststackdouble1.pop() << endl;
	cout << "LinkedListStack<double> pop(): " << linkedliststackdouble1.pop() << endl;
	cout << "LinkedListStack<double> pop(): " << linkedliststackdouble1.pop() << endl;
	cout << "LinkedListStack<double> pop(): " << linkedliststackdouble1.pop() << endl;
	cout << "LinkedListStack<double> pop(): " << linkedliststackdouble1.pop() << endl;
	cout << "LinkedListStack<double> pop(): " << linkedliststackdouble1.pop() << endl;
  }
  catch (const char* excp) {
	  cout << excp << endl;
  }

  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble1.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble1.getSize() << endl;

  try {
	cout << "LinkedListStack<double> pushing 1.1"<<endl; 
  	linkedliststackdouble1.push(1.1);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 2.2"<<endl; 
  	linkedliststackdouble1.push(2.2);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 3.3"<<endl; 
  	linkedliststackdouble1.push(3.3);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 4.4"<<endl; 
  	linkedliststackdouble1.push(4.4);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 5.5"<<endl; 
  	linkedliststackdouble1.push(5.5);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 6.6"<<endl; 
  	linkedliststackdouble1.push(6.6);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 7.7"<<endl; 
  	linkedliststackdouble1.push(7.7);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 8.8"<<endl; 
  	linkedliststackdouble1.push(8.8);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 9.9"<<endl; 
  	linkedliststackdouble1.push(9.9);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 	cout << "LinkedListStack<double> pushing 10.10"<<endl; 
  	linkedliststackdouble1.push(10.10);
  	cout << "LinkedListStack<double> peek(): " << linkedliststackdouble1.peek() << endl; 
 

  }
  catch (const char* excp) {
	  cout << excp << endl;
  }

  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble1.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble1.getSize() << endl;


  /*
   * LinkedListStack copy constructor
   */
  cout << "LinkedListStack<double> copy  constructor..." << endl;
  LinkedListStack<double> linkedliststackdouble3(linkedliststackdouble1);  

  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble3.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble3.getSize() << endl;

  while(linkedliststackdouble3.getSize() > 0) {
	  try {
	  	cout << "LinkedListStack<double> pop(): "<< linkedliststackdouble3.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
  
  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble3.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble3.getSize() << endl;



  /*
   * LinkedListStack move constructor.
   */
  cout << "LinkedListStack<string> move constructor......" <<endl;
  LinkedListStack<string> linkedliststackstring1 = getColorStack();

  cout << "LinkedListStack<string> isEmpty: " << linkedliststackstring1.isEmpty() << endl;
  cout << "LinkedListStack<string> size: " << linkedliststackstring1.getSize() << endl;

 
  while(linkedliststackstring1.getSize() > 0) {
	  try {
	  	cout << "LinkedListStack<string> pop(): "<< linkedliststackstring1.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
   

  cout << "LinkedListStack<string> isEmpty: " << linkedliststackstring1.isEmpty() << endl;
  cout << "LinkedListStack<string> size: " << linkedliststackstring1.getSize() << endl;


  /*
   * LinkedListStack copy assignment
   */
  cout << "LinkedListStack<double> copy assignment..." << endl;
  LinkedListStack<double> linkedliststackdouble4;

  cout << "LinkedListStack<double> before copy assignment" << endl;
  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble4.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble4.getSize() << endl;

  linkedliststackdouble4 = linkedliststackdouble1;  


  cout << "LinkedListStack<double> after copy assignment" << endl;
  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble4.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble4.getSize() << endl;

  while(linkedliststackdouble4.getSize() > 0) {
	  try {
	  	cout << "LinkedListStack<double> pop(): "<< linkedliststackdouble4.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
  
  cout << "LinkedListStack<double> isEmpty: " << linkedliststackdouble4.isEmpty() << endl;
  cout << "LinkedListStack<double> size: " << linkedliststackdouble4.getSize() << endl;



   /*
   * LinkedListStack move assignment.
   */
  cout << "LinkedListStack<string> move assignment......" <<endl;
  LinkedListStack<string> linkedliststackstring2;

  cout << "LinkedListStack<string> before move assignment" << endl;
  cout << "LinkedListStack<string> isEmpty: " << linkedliststackstring2.isEmpty() << endl;
  cout << "LinkedListStack<string> size: " << linkedliststackstring2.getSize() << endl;

 
  linkedliststackstring2 = getColorStack();

  cout << "LinkedListStack<string> after move assignment" << endl;
  cout << "LinkedListStack<string> isEmpty: " << linkedliststackstring2.isEmpty() << endl;
  cout << "LinkedListStack<string> size: " << linkedliststackstring2.getSize() << endl;

 
  while(linkedliststackstring2.getSize() > 0) {
	  try {
	  	cout << "LinkedListStack<string> pop(): "<< linkedliststackstring2.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
   

  cout << "LinkedListStack<string> isEmpty: " << linkedliststackstring2.isEmpty() << endl;
  cout << "LinkedListStack<string> size: " << linkedliststackstring2.getSize() << endl;

 
  cout << "LinkedListStack<int>* ..........................................................."<< endl;
  LinkedListStack<int>* linkedliststack = NULL;
 
  linkedliststack = new LinkedListStack<int>();

  cout << "LinkedListStack<int>* isEmpty: " << linkedliststack->isEmpty() << endl;
  cout << "LinkedListStack<int>* size: " << linkedliststack->getSize() << endl;

  try{
    linkedliststack->push(100);

    cout << "LinkedListStack<int>* isEmpty after pushing 100: " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after pushing 100: " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after pushing 100: " << linkedliststack->peek() << endl;

    linkedliststack->push(200);

    cout << "LinkedListStack<int>* isEmpty after pushing 200: " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after pushing 200: " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after pushing 200: " << linkedliststack->peek() << endl;

    linkedliststack->push(300);

    cout << "LinkedListStack<int>* isEmpty after pushing 300: " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after pushing 300: " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after pushing 300: " << linkedliststack->peek() << endl;

    int popped = linkedliststack->pop();

    cout << "LinkedListStack<int>* isEmpty after popping: " << popped << ": " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after popping: " << popped << ": " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after popping: " << popped << ": " << linkedliststack->peek() << endl;

    linkedliststack->push(300);

    int peeked = linkedliststack->peek();

    cout << "LinkedListStack<int>* isEmpty after peeking: " << peeked << ": " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after peeking: " << peeked << ": " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after peeking: " << peeked << ": " << linkedliststack->peek() << endl;

    linkedliststack->push(400);
    linkedliststack->push(500);
    linkedliststack->push(600);
    linkedliststack->push(700);
    linkedliststack->push(800);
    linkedliststack->push(900);
    linkedliststack->push(1000);

    cout << "LinkedListStack<int>* isEmpty after pushing 1000: " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after pushing 1000: " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after pushing 1000: " << linkedliststack->peek() << endl;

    linkedliststack->push(1100);
    cout << "LinkedListStack<int>* isEmpty after pushing 1100: " << linkedliststack->isEmpty() << endl;
    cout << "LinkedListStack<int>* size after pushing 1100: " << linkedliststack->getSize() << endl;
    cout << "LinkedListStack<int>* top after pushing 1100: " << linkedliststack->peek() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }
  int stackSize = linkedliststack->getSize();
  try{
    for (int i=0; i<stackSize; i++) {
      cout << "LinkedListStack<int>* pop(): " << linkedliststack->pop() << endl;
    }
    cout << "ArrayStck<int>* pop() " << linkedliststack->pop() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }

  cout << "StackADT<int>* ....................................................." << endl;
  StackADT<int>* stack = NULL;
 
  stack = new LinkedListStack<int>();

  cout << "StackADT<int>* isEmpty: " << stack->isEmpty() << endl;
  cout << "StackADT<int>* size: " << stack->getSize() << endl;

  try{
    stack->push(100);

    cout << "StackADT<int>* isEmpty after pushing 100: " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after pushing 100: " << stack->getSize() << endl;
    cout << "StackADT<int>* top after pushing 100: " << stack->peek() << endl;

    stack->push(200);

    cout << "StackADT<int>* isEmpty after pushing 200: " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after pushing 200: " << stack->getSize() << endl;
    cout << "StackADT<int>* top after pushing 200: " << stack->peek() << endl;

    stack->push(300);

    cout << "StackADT<int>* isEmpty after pushing 300: " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after pushing 300: " << stack->getSize() << endl;
    cout << "StackADT<int>* top after pushing 300: " << stack->peek() << endl;

    int popped = stack->pop();

    cout << "StackADT<int>* isEmpty after popping: " << popped << ": " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after popping: " << popped << ": " << stack->getSize() << endl;
    cout << "StackADT<int>* top after popping: " << popped << ": " << stack->peek() << endl;

    stack->push(300);

    int peeked = stack->peek();

    cout << "StackADT<int>* isEmpty after peeking: " << peeked << ": " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after peeking: " << peeked << ": " << stack->getSize() << endl;
    cout << "StackADT<int>* top after peeking: " << peeked << ": " << stack->peek() << endl;

    stack->push(400);
    stack->push(500);
    stack->push(600);
    stack->push(700);
    stack->push(800);
    stack->push(900);
    stack->push(1000);

    cout << "StackADT<int>* isEmpty after pushing 1000: " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after pushing 1000: " << stack->getSize() << endl;
    cout << "StackADT<int>* top after pushing 1000: " << stack->peek() << endl;

    stack->push(1100);
    cout << "StackADT<int>* isEmpty after pushing 1100: " << stack->isEmpty() << endl;
    cout << "StackADT<int>* size after pushing 1100: " << stack->getSize() << endl;
    cout << "StackADT<int>* top after pushing 1100: " << stack->peek() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }
  stackSize = stack->getSize();
  try{
    for (int i=0; i<stackSize; i++) {
      cout << "StackADT<int> pop(): " << stack->pop() << endl;
    }
    cout << "StackADT<int> pop(): " << stack->pop() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }

  /*
   * Releasing memory from dynimically coreated objects
   */
  if(linkedliststack != NULL) {
  	delete linkedliststack;
  }

  if(stack != NULL) {
	  delete stack;
  }

  cout << "************** End of Testing LinkedListStack ***************" << endl;


  return 0;
}
