#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* prev = NULL;
	Node* next = NULL;;
};

Node* head = NULL;
Node* tail = NULL;

void insertAtHead(Node* node) {
	if(head == NULL && tail == NULL) {
		head = tail = node;
		return;
	}

	node->next = head;
	head->prev = node;
	head = node;
}

void insertAtTail(Node* node) {
	if(head == NULL && tail == NULL) {
		head = tail = node;
		return;
	}
	node->prev = tail;
	tail->next = node;
	tail = node;
}


void insertAtMiddle(Node* node, Node* after) {
	
	Node* prev = head;
	while(prev != NULL && prev != after) {
		prev = prev->next;
	}
	if(prev != NULL && prev == after) {
		node->next = prev->next;
		node->prev = prev;
		prev->next = node;
		if(node->next != NULL) {
			//inserted at the true middle of the list
			node->next->prev = node;
		}
		else {
			//inserted after the tail
			//tail needs to move to point the new last node 
			tail = node; 
		}
	}

}


void deleteFromHead() {
	if(head == NULL) {
		return;
	}

	Node* node = head;
	head = node->next;
	if (head != NULL) {
		head->prev = NULL;
	}
	else { 
		//list will be empty after the deletion
		//tail must be updated to NULL
		tail = NULL;
	}
	delete node;
}

void deleteFromTail() {
	if(tail == NULL) {
		return;
	}
	Node* node = tail;
	tail = node->prev;
	if(tail != NULL) {
		tail->next = NULL;
	}
	else {
		//list will be empty after the deletion
		//head must be updated to NULL
		head = NULL;
	}

	delete node;
}


void deleteFromMiddle(Node* node) {
	if (head == node) {
		deleteFromHead();
		return;
	}
	Node* prev = head;
	while(prev != NULL && prev->next != NULL) {
		if(prev->next == node) {
			prev->next = node->next;
			if(node->next != NULL) {
				//deleting from the true middle of the list
				node->next->prev = prev;
			}
			else {
				//tail is being deleted
				//tail needs to point the new last element in the list
				tail = prev;
			}

			delete node;
			break;
		}
		prev = prev->next;
	}
}

void showForward() {
	Node* node = head;
	cout<<">> ";
	while(node != NULL) {
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

void showBackward() {
	Node* node = tail;
	cout<<"<< ";
	while(node !=NULL) {
		cout<<node->data<<" ";
		node = node->prev;
	}
	cout<<endl;
}

int main() {

	Node* first = new Node;
	first->data = 10;
	insertAtHead(first);

	Node* second = new Node;
	second->data = 20;
	insertAtHead(second);

	Node* third = new Node;
	third->data = 30;
	insertAtHead(third);

	Node* fourth = new Node;
        fourth->data = 40;
	insertAtHead(fourth);

	Node* fifth = new Node;
	fifth->data = 50;
	insertAtHead(fifth);

	showForward();
	showBackward();	

	Node* sixth = new Node;
	sixth->data = 60;
	insertAtMiddle(sixth, third);

	showForward();
	showBackward();	


	Node* seventh = new Node;
	seventh->data = 70;
	insertAtMiddle(seventh, first);

	showForward();
	showBackward();	


	Node* eight = new Node;
	eight->data = 80;
	insertAtTail(eight);

	showForward();
	showBackward();	


	deleteFromMiddle(sixth);

	showForward();
	showBackward();

	deleteFromMiddle(seventh);

	showForward();
	showBackward();

	deleteFromHead();

	showForward();
	showBackward();

	while(head != NULL) {
		deleteFromTail();
		showForward();
		showBackward();
	}	

	
	return 0;
}
