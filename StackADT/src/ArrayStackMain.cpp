#include <iostream>
#include <string>
#include "StackADT.h"
#include "ArrayStack.cpp"

using namespace std;

ArrayStack<string> getColorStack() {
	int count = 7;
	string colors[] = {"Red", "Orange", "Yellow", "Green", "Cyan", "Blue", "Violet"};
	ArrayStack<string> arraystack(count);
	for (int i = 0; i<count; i++) {
		arraystack.push(colors[i]);
	}
	return arraystack;
}

int main(){


  cout << "************** Testing ArrayStack ***************" << endl;
  
  /*
   * ArrayStack default constructor
   */
  ArrayStack<double> arraystackdouble1;  

  cout << "ArrayStack<double> default constructor..." << endl;
  cout << "ArrayStack<double> capacity: " << arraystackdouble1.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble1.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble1.getSize() << endl;

  try {
  cout << "ArrayStack<double> pushing 10.01"<<endl;  
  arraystackdouble1.push(10.01);
  cout << "ArrayStack<double> peek(): " << arraystackdouble1.peek() << endl; 
  
  cout << "ArrayStack<double> pushing 20.02"<<endl; 
  arraystackdouble1.push(20.02);
  cout << "ArrayStack<double> peek(): " << arraystackdouble1.peek() << endl; 

  cout << "ArrayStack<double> pushing 30.03"<<endl; 
  arraystackdouble1.push(30.03);
  cout << "ArrayStack<double> peek(): " << arraystackdouble1.peek() << endl; 
 
  cout << "ArrayStack<double> pushing 40.04"<<endl; 
  arraystackdouble1.push(40.04);
  cout << "ArrayStack<double> peek(): " << arraystackdouble1.peek() << endl; 

  cout << "ArrayStack<double> pushing 50.05"<<endl; 
  arraystackdouble1.push(50.05);
  cout << "ArrayStack<double> peek(): " << arraystackdouble1.peek() << endl; 

  }
  catch (const char* excp) {
	  cout<<excp<<endl;
  }
  cout <<"ArrayStack<double> after pushing 10.01, 20.02, 30.03, 40.04, and 50.05" << endl;
  cout << "ArrayStack<double> capacity: " << arraystackdouble1.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble1.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble1.getSize() << endl;

  try {
	cout << "ArrayStack<double> pop(): " << arraystackdouble1.pop() << endl;
	cout << "ArrayStack<double> pop(): " << arraystackdouble1.pop() << endl;
	cout << "ArrayStack<double> pop(): " << arraystackdouble1.pop() << endl;
	cout << "ArrayStack<double> pop(): " << arraystackdouble1.pop() << endl;
	cout << "ArrayStack<double> pop(): " << arraystackdouble1.pop() << endl;
	cout << "ArrayStack<double> pop(): " << arraystackdouble1.pop() << endl;
  }
  catch (const char* excp) {
	  cout << excp << endl;
  }

 
  /*
   * ArrayStack regular constructor
   */
  
  cout << "ArrayStack<double> regular constructor..." << endl;

  int capacity = 5;
  ArrayStack<double> arraystackdouble2(capacity);  

  cout << "ArrayStack<double> capacity: " << arraystackdouble2.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble2.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble2.getSize() << endl;


  try {

  cout << "ArrayStack<double> pushing 1.1"<<endl;  
  arraystackdouble2.push(1.1);
  cout << "ArrayStack<double> peek(): " << arraystackdouble2.peek() << endl; 
  
  cout << "ArrayStack<double> pushing 2.2"<<endl; 
  arraystackdouble2.push(2.2);
  cout << "ArrayStack<double> peek(): " << arraystackdouble2.peek() << endl; 

  cout << "ArrayStack<double> pushing 3.3"<<endl; 
  arraystackdouble2.push(3.3);
  cout << "ArrayStack<double> peek(): " << arraystackdouble2.peek() << endl; 
 
  cout << "ArrayStack<double> pushing 4.4"<<endl; 
  arraystackdouble2.push(4.4);
  cout << "ArrayStack<double> peek(): " << arraystackdouble2.peek() << endl; 

  cout << "ArrayStack<double> pushing 5.5"<<endl; 
  arraystackdouble2.push(5.5);
  cout << "ArrayStack<double> peek(): " << arraystackdouble2.peek() << endl; 

  }
  catch (const char* excp) {
	  cout<<excp<<endl;
  }

  cout << "ArrayStack<double> after pushing 1.1, 2.2, 3.3, 4.4, and 5.5" << endl;
  cout << "ArrayStack<double> capacity: " << arraystackdouble2.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble2.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble2.getSize() << endl;

  cout << "Attempt to push 6.6 when a the ArrayStack<double> is full"<<endl;
  try {
  	arraystackdouble2.push(6.6);
  }
  catch (const char* excp) {
	  cout<<excp<<endl;
  }


  /*
   * ArrayStack copy constructor
   */
  cout << "ArrayStack<double> copy  constructor..." << endl;
  ArrayStack<double> arraystackdouble3(arraystackdouble2);  

  cout << "ArrayStack<double> capacity: " << arraystackdouble3.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble3.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble3.getSize() << endl;

  while(arraystackdouble3.getSize() > 0) {
	  try {
	  	cout << "ArrayStack<double> pop(): "<< arraystackdouble3.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
  
  cout << "ArrayStack<double> capacity: " << arraystackdouble3.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble3.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble3.getSize() << endl;



  /*
   * ArrayStack move constructor.
   */
  cout << "ArrayStack<string> move constructor......" <<endl;
  ArrayStack<string> arraystackstring1 = getColorStack();

  cout << "ArrayStack<string> capacity: " << arraystackstring1.getCapacity() << endl;
  cout << "ArrayStack<string> isEmpty: " << arraystackstring1.isEmpty() << endl;
  cout << "ArrayStack<string> size: " << arraystackstring1.getSize() << endl;

 
  while(arraystackstring1.getSize() > 0) {
	  try {
	  	cout << "ArrayStack<string> pop(): "<< arraystackstring1.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
   

  cout << "ArrayStack<string> capacity: " << arraystackstring1.getCapacity() << endl;
  cout << "ArrayStack<string> isEmpty: " << arraystackstring1.isEmpty() << endl;
  cout << "ArrayStack<string> size: " << arraystackstring1.getSize() << endl;


  /*
   * ArrayStack copy assignment
   */
  cout << "ArrayStack<double> copy assignment..." << endl;
  ArrayStack<double> arraystackdouble4;

  cout << "ArrayStack<double> before copy assignment" << endl;
  cout << "ArrayStack<double> capacity: " << arraystackdouble4.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble4.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble4.getSize() << endl;

  arraystackdouble4 = arraystackdouble2;  


  cout << "ArrayStack<double> after copy assignment" << endl;
  cout << "ArrayStack<double> capacity: " << arraystackdouble4.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble4.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble4.getSize() << endl;

  while(arraystackdouble4.getSize() > 0) {
	  try {
	  	cout << "ArrayStack<double> pop(): "<< arraystackdouble4.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
  
  cout << "ArrayStack<double> capacity: " << arraystackdouble4.getCapacity() << endl;
  cout << "ArrayStack<double> isEmpty: " << arraystackdouble4.isEmpty() << endl;
  cout << "ArrayStack<double> size: " << arraystackdouble4.getSize() << endl;



   /*
   * ArrayStack move assignment.
   */
  cout << "ArrayStack<string> move assignment......" <<endl;
  ArrayStack<string> arraystackstring2;

  cout << "ArrayStack<string> before move assignment" << endl;
  cout << "ArrayStack<string> capacity: " << arraystackstring2.getCapacity() << endl;
  cout << "ArrayStack<string> isEmpty: " << arraystackstring2.isEmpty() << endl;
  cout << "ArrayStack<string> size: " << arraystackstring2.getSize() << endl;

 
  arraystackstring2 = getColorStack();

  cout << "ArrayStack<string> after move assignment" << endl;
  cout << "ArrayStack<string> capacity: " << arraystackstring2.getCapacity() << endl;
  cout << "ArrayStack<string> isEmpty: " << arraystackstring2.isEmpty() << endl;
  cout << "ArrayStack<string> size: " << arraystackstring2.getSize() << endl;

 
  while(arraystackstring2.getSize() > 0) {
	  try {
	  	cout << "ArrayStack<string> pop(): "<< arraystackstring2.pop() << endl;
	  }
	  catch (const char* excp) {
		  cout << excp << endl;
	  }
  }
   

  cout << "ArrayStack<string> capacity: " << arraystackstring2.getCapacity() << endl;
  cout << "ArrayStack<string> isEmpty: " << arraystackstring2.isEmpty() << endl;
  cout << "ArrayStack<string> size: " << arraystackstring2.getSize() << endl;

 
  cout << "ArrayStack<int>* ..........................................................."<< endl;
  ArrayStack<int>* arraystack = NULL;
  capacity = 20;
 
  arraystack = new ArrayStack<int>(capacity);

  cout << "ArrayStack<int>* capacity: " << arraystack->getCapacity() << endl;
  cout << "ArrayStack<int>* isEmpty: " << arraystack->isEmpty() << endl;
  cout << "ArrayStack<int>* size: " << arraystack->getSize() << endl;

  try{
    arraystack->push(100);

    cout << "ArrayStack<int>* isEmpty after pushing 100: " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after pushing 100: " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after pushing 100: " << arraystack->peek() << endl;

    arraystack->push(200);

    cout << "ArrayStack<int>* isEmpty after pushing 200: " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after pushing 200: " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after pushing 200: " << arraystack->peek() << endl;

    arraystack->push(300);

    cout << "ArrayStack<int>* isEmpty after pushing 300: " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after pushing 300: " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after pushing 300: " << arraystack->peek() << endl;

    int popped = arraystack->pop();

    cout << "ArrayStack<int>* isEmpty after popping: " << popped << ": " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after popping: " << popped << ": " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after popping: " << popped << ": " << arraystack->peek() << endl;

    arraystack->push(300);

    int peeked = arraystack->peek();

    cout << "ArrayStack<int>* isEmpty after peeking: " << peeked << ": " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after peeking: " << peeked << ": " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after peeking: " << peeked << ": " << arraystack->peek() << endl;

    arraystack->push(400);
    arraystack->push(500);
    arraystack->push(600);
    arraystack->push(700);
    arraystack->push(800);
    arraystack->push(900);
    arraystack->push(1000);

    cout << "ArrayStack<int>* isEmpty after pushing 1000: " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after pushing 1000: " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after pushing 1000: " << arraystack->peek() << endl;

    arraystack->push(1100);
    cout << "ArrayStack<int>* isEmpty after pushing 1100: " << arraystack->isEmpty() << endl;
    cout << "ArrayStack<int>* size after pushing 1100: " << arraystack->getSize() << endl;
    cout << "ArrayStack<int>* top after pushing 1100: " << arraystack->peek() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }
  int stackSize = arraystack->getSize();
  try{
    for (int i=0; i<stackSize; i++) {
      cout << "ArrayStack<int>* pop(): " << arraystack->pop() << endl;
    }
    cout << "ArrayStck<int>* pop() " << arraystack->pop() << endl;
  }
  catch (const char* excp){
      cerr << excp << endl;
  }

  cout << "StackADT<int>* ....................................................." << endl;
  StackADT<int>* stack = NULL;
 
  stack = new ArrayStack<int>(capacity);

  //cout << "StackADT<int>* capacity: " << stack->getCapacity() << endl;
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
      cerr << "Push Error: " << excp << endl;
  }
  stackSize = stack->getSize();
  try{
    for (int i=0; i<stackSize; i++) {
      cout << "popped: " << stack->pop() << endl;
    }
    cout << "popped: " << stack->pop() << endl;
  }
  catch (const char* excp){
      cerr << "Pop Error: " << excp << endl;
  }

  /*
   * Releasing memory from dynimically coreated objects
   */
  if(arraystack != NULL) {
  	delete arraystack;
  }

  if(stack != NULL) {
	  delete stack;
  }

  cout << "************** End of Testing ArrayStack ***************" << endl;


  return 0;
}
