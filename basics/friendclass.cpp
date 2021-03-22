#include <iostream>

using namespace std;

// class Node {
// public:
//   int data;
//   Node* next;
//   Node():data(0), next(NULL) {}
//   Node(int data): data(data), next(NULL) {}
// };

class Node {
private:
  int data;
  Node* next;
public:
  Node():data(0), next(NULL) {}
  Node(int data): data(data), next(NULL) {}
  int getData() {return data;} 
  friend class LinkedList;
};

class LinkedList {
private:
  Node* head;
public:
  LinkedList():head(new Node) {}
  ~LinkedList();
  void append(int data);
  bool remove(int data);
  Node* search(int data);
  void show();
};

LinkedList::~LinkedList() {
  Node* current = head->next;
  while(current!= NULL) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
  delete head;
  cout<<"LinkedList destructor ...."<<endl;
}

void LinkedList::append(int data) {
  Node* newNode = new Node(data);
  Node* current = head->next;
  if(current == NULL) {
    head->next = newNode;
  }
  else {
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

bool LinkedList::remove(int data) {
  Node* current = head->next;
  if(current == NULL) {
    return false;
  }
  else if(current->data == data) {
    head->next = current->next;
    delete current;
    return true;
  }
  else {
    while(current->next != NULL && current->next->data != data) {
      current = current->next;
    }
    if(current->next == NULL) {
      return false;
    }
    else {
      Node* temp = current->next;
      current->next = current->next->next;
      delete temp;
      return true;
    }
  }
}

Node* LinkedList::search(int data) {
  Node* current = head->next;
  while(current!= NULL) {
    if(current->data == data){
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void LinkedList::show() {
  Node* current = head->next;
  while(current!= NULL) {
    cout<<current->data<<" ";
    current = current->next;
  }
  cout<<endl;
}

int main() {
  LinkedList linkedList;
  for(int i=10; i<100; i+=10) {
    linkedList.append(i);
  }

  linkedList.show();
  cout<<"Searching 10: "<<linkedList.search(10)->getData()<<endl;
  cout<<"Searching 15: "<<linkedList.search(15)<<endl;
  cout<<"Searching 90: "<<linkedList.search(90)->getData()<<endl;
  cout<<"Searching 100: "<<linkedList.search(100)<<endl;
  cout<<"After deleting 10: "<<endl;
  linkedList.remove(10);
  linkedList.show();
  cout<<"After deleting 10: "<<endl;
  linkedList.remove(10);
  linkedList.show();
  cout<<"After deleting 50: "<<endl;
  linkedList.remove(50);
  linkedList.show();
  cout<<"After deleting 50: "<<endl;
  linkedList.remove(50);
  linkedList.show();

  cout<<"After deleting 90: "<<endl;
  linkedList.remove(90);
  linkedList.show();

  cout<<"After deleting 90: "<<endl;
  linkedList.remove(90);
  linkedList.show();

  cout<<"After deleting 100: "<<endl;
  linkedList.remove(100);
  linkedList.show();

  return 0;
}
