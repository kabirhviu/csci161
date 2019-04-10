#include <iostream>

using namespace std;

class LinkedList {
protected:
  class ListNode {
    public:
       int data;
       ListNode* next;
       ListNode(int data): data(data), next(NULL) {}
  };
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
     int* asArray();
     friend ostream& operator << (ostream&, const LinkedList&);
};

class Stack: public LinkedList {
public:
  Stack();
  ~Stack();
  void push(int);
  int pop();
  friend ostream& operator << (ostream&, const Stack&);
};

class Queue : public LinkedList {
public:
  Queue();
  ~Queue();
  void enqueue(int element);
  int dequeue();
  friend ostream& operator << (ostream&, const Queue&);
};

LinkedList::LinkedList():head(new ListNode(-1)), size(0){}

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

int* LinkedList::asArray() {
  ListNode* current = head->next;
  if(current == NULL) {
    return NULL;
  }
  int* arr = new int[size];
  int i = 0;
  while(current!=NULL) {
    arr[i++] = current->data;
    current = current->next;
  }
  return arr;
}

ostream& operator << (ostream& out, const LinkedList& list) {
  LinkedList::ListNode* current = list.head->next;
  while(current != NULL) {
    out<<current->data<<" ";
    current = current->next;
  }
  return out;
}

Stack::Stack():LinkedList(){}
Stack::~Stack(){}
void Stack::push(int element){
  insertAtFront(element);
}
int Stack::pop(){
  return removeFromFront();
}

ostream& operator << (ostream& out, const Stack& stack) {
  Stack::ListNode* current = stack.head->next;
  while(current != NULL) {
    out<<current->data<<" ";
    current = current->next;
  }
  return out;
}

Queue::Queue():LinkedList(){}
Queue::~Queue(){}
void Queue::enqueue(int element){
  insertAtEnd(element);
}
int Queue::dequeue(){
  return removeFromFront();
}

ostream& operator << (ostream& out, const Queue& queue) {
  Queue::ListNode* current = queue.head->next;
  while(current != NULL) {
    out<<current->data<<" ";
    current = current->next;
  }
  return out;
}

int main() {

  LinkedList linkedList;
  int elements[] = {10, 20, 30, 40, 50};
  int* elementsFromList;
  int listSize;

  cout<<"List isEmpty: "<<(linkedList.isEmpty()? "true": "false")<<endl;
  for(int i=0; i<5; i++) {
    linkedList.insertAtEnd(elements[i]);
    cout<<"List size after adding "<<elements[i]<< " at end: "<<linkedList.getSize()<<endl;
    cout<<linkedList<<endl;
  }
  cout<<"List isEmpty: "<<(linkedList.isEmpty()? "true": "false")<<endl;
  cout<<"List elements after adding at end:"<<endl<<linkedList<<endl;

  listSize = linkedList.getSize();
  elementsFromList = linkedList.asArray();
  cout<<"List elements as Array: "<<endl;
  for(int i=0; i<listSize; i++) {
    cout<<elementsFromList[i]<<" ";
  }

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

  cout<<stack<<endl;

  elementsFromList = stack.asArray();
  cout<<"Stack elements as Array: "<<endl;
  for(int i=0; i<listSize; i++) {
    cout<<elementsFromList[i]<<" ";
  }
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;
  cout<<stack.pop()<<endl;

  cout<<"Stack isEmpty: "<<(stack.isEmpty()? "true": "false")<<endl;
  cout<<"Stack size: "<<stack.getSize()<<endl;


  Queue queue;
  for (int i=0; i<5; i++) {
    queue.enqueue(elements[i]);
  }

  cout<<queue<<endl;
  elementsFromList = queue.asArray();
  cout<<"Queue elements as Array: "<<endl;
  for(int i=0; i<listSize; i++) {
    cout<<elementsFromList[i]<<" ";
  }
  cout<<endl;

  cout<<"Queue isEmpty: "<<(queue.isEmpty()? "true": "false")<<endl;
  cout<<"Queue size: "<<queue.getSize()<<endl;

  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;
  cout<<queue.dequeue()<<endl;

  cout<<"Queue isEmpty: "<<(queue.isEmpty()? "true": "false")<<endl;
  cout<<"Queue size: "<<queue.getSize()<<endl;
  return 0;
}
