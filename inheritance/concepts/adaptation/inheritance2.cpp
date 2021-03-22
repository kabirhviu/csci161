#include <iostream>

using namespace std;

class LinkedList;		//Forward declaration is required to use the class in the ListNode 

class ListNode {
private:
  int data;
  ListNode* next;

public:  
  ListNode(int data): data(data), next(NULL) {}
  friend class LinkedList;
  friend ostream& operator << (ostream&, const LinkedList&); 
};

class LinkedList {
  private:
     ListNode* head;
     int size;
  public:
     LinkedList();
     ~LinkedList();
     int getSize();
     bool isEmpty();
     void insertAtFront(int);
     void insertAtEnd(int);
     int removeFromFront();
     int removeFromEnd();
     friend ostream& operator << (ostream&, const LinkedList&);
};

class Stack: public LinkedList {
public:
  Stack();
  ~Stack();
  void push(int);
  int pop();
  // friend ostream& operator << (ostream&, const Stack&);
};

class Queue : public LinkedList {
public:
  Queue();
  ~Queue();
  void enqueue(int element);
  int dequeue();
  // friend ostream& operator << (ostream&, const Queue&);
};

LinkedList::LinkedList():head(new ListNode(-1)), size(0){cout<<"LinkedList constructor....."<<endl;}

LinkedList::~LinkedList(){
  cout<<"LinkedList destructor freeing memory...."<<endl;
  ListNode* current = head->next;
  while(current!=NULL) {
    ListNode* temp = current;
    current = current->next;
    delete temp;
  }
  delete head;
}

int LinkedList::getSize(){ return size;}

bool LinkedList::isEmpty(){ return size==0;}

void LinkedList::insertAtFront(int element){
  ListNode* newNode = new ListNode(element);
  newNode->next = head->next;
  head->next = newNode;
  size++;
}

void LinkedList::insertAtEnd(int element){
  ListNode* newNode = new ListNode(element);
  ListNode* current = head->next;
  if(current == NULL) {
    head->next = newNode;
  }
  else {
    while(current->next != NULL) {
      current= current->next;
    }
    current->next = newNode;
  }
  size++;
}

int LinkedList::removeFromFront(){
  ListNode* current = head->next;
  int element = -1;
  if(current != NULL) {
    element = current->data;
    head->next = current->next;
    delete current;
    size--;
  }
  return element;
}

int LinkedList::removeFromEnd(){
  int element = -1;
  ListNode* current = head->next;
  if(current != NULL) {
    if(current->next == NULL) {
      element = current->data;
      head->next = NULL;
      delete current;
    }
    else {
      while(current->next->next != NULL) {
        current = current->next;
      }
      ListNode* temp = current->next;
      element = temp->data;
      current->next = NULL;
      delete temp;
    }
    size--;
  }
  return element;
}

ostream& operator << (ostream& out, const LinkedList& list) {
  ListNode* current = list.head->next;
  while(current != NULL) {
    out<<current->data<<" ";
    current = current->next;
  }
  return out;
}

Stack::Stack():LinkedList(){cout<<"Stack constructor ...."<<endl;}
Stack::~Stack(){ cout<<"Stack destructor ..."<<endl;}
void Stack::push(int element){
  insertAtFront(element);
}
int Stack::pop(){
  return removeFromFront();
}

//ostream& operator << (ostream& out, const Stack& stack) {
//  Stack::ListNode* current = stack.head->next;
//  while(current != NULL) {
//    out<<current->data<<" ";
//    current = current->next;
//  }
//  return out;
//}

Queue::Queue():LinkedList(){cout<<"Queue constructor....."<<endl;}
Queue::~Queue(){cout<<"Queue destructor....."<<endl;}
void Queue::enqueue(int element){
  insertAtEnd(element);
}
int Queue::dequeue(){
  return removeFromFront();
}

//ostream& operator << (ostream& out, const Queue& queue) {
//  Queue::ListNode* current = queue.head->next;
//  while(current != NULL) {
//    out<<current->data<<" ";
//    current = current->next;
//  }
//  return out;
//}


int main() {

  LinkedList linkedList;
  int elements[] = {10, 20, 30, 40, 50};

  cout<<"List isEmpty: "<<(linkedList.isEmpty()? "true": "false")<<endl;
  for(int i=0; i<5; i++) {
    linkedList.insertAtEnd(elements[i]);
    cout<<"List size after adding "<<elements[i]<< " at end: "<<linkedList.getSize()<<endl;
    cout<<linkedList<<endl;
  }
  cout<<"List isEmpty: "<<(linkedList.isEmpty()? "true": "false")<<endl;
  cout<<"List elements after adding at end:"<<endl<<linkedList<<endl;


  cout<<endl;

  for(int i=0; i<5; i++) {
    linkedList.removeFromEnd();
    cout<<"List size after removing from end : "<<linkedList.getSize()<<endl;
    cout<<linkedList<<endl;
  }

  for(int i=0; i<5; i++) {
    linkedList.insertAtFront(elements[i]);
    cout<<"List size after adding "<<elements[i]<< " at front: "<<linkedList.getSize()<<endl;
    cout<<linkedList<<endl;
  }

  cout<<"List elements after adding at front:"<<endl<<linkedList<<endl;

  for(int i=0; i<5; i++) {
    linkedList.removeFromFront();
    cout<<"List size after removing from front : "<<linkedList.getSize()<<endl;
    cout<<linkedList<<endl;
  }



  Stack stack;
  

  for (int i=0; i<5; i++) {
    stack.push(elements[i]);
  }

  cout<<"Stack isEmpty: "<<(stack.isEmpty()? "true": "false")<<endl;
  cout<<"Stack size: "<<stack.getSize()<<endl;

  /*
   * Stack does not inherit operator << overloaded friend function.
   * Following statment will not work.
   */
  //cout<<stack<<endl; 
 

  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;

  cout<<"Stack isEmpty: "<<(stack.isEmpty()? "true": "false")<<endl;
  cout<<"Stack size: "<<stack.getSize()<<endl;


  /*
   * Unwanted operations on Stack
   */
  stack.insertAtEnd(10);
  stack.insertAtEnd(20);
  stack.insertAtEnd(30);
  cout<<"Stack elements insertion order: 10 20 30"<<endl;
  cout<<"Stack elements removal order that violates stack invarient : ";
  cout<<stack.removeFromFront()<<" ";
  cout<<stack.removeFromFront()<<" ";
  cout<<stack.removeFromFront()<<endl;

  cout<<endl;



  Queue queue;
  for (int i=0; i<5; i++) {
    queue.enqueue(elements[i]);
  }

  cout<<"Queue isEmpty: "<<(queue.isEmpty()? "true": "false")<<endl;
  cout<<"Queue size: "<<queue.getSize()<<endl;


  /*
   * Queue does not inherit operator << overloaded friend function.
   * Following statment will not work.
   */
  //cout<<queue<<endl 
 

  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;

  cout<<"Queue isEmpty: "<<(queue.isEmpty()? "true": "false")<<endl;
  cout<<"Queue size: "<<queue.getSize()<<endl;



  /*
   * Unwanted operations on Queue
   */  
  queue.insertAtFront(10);
  queue.insertAtFront(20);
  queue.insertAtFront(30);
  cout<<"Queue elements insertion order: 10 20 30"<<endl;
  cout<<"Queue elements removal order that violates queue invarient: ";
  cout<<queue.removeFromFront()<<" ";
  cout<<queue.removeFromFront()<<" ";
  cout<<queue.removeFromFront()<<endl;


  return 0;
}
