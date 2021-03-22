#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* prev = NULL;
	Node* next = NULL;
};

Node* head = NULL;

void insertIntoEmptyList(Node* node) {
	if(head == NULL) {
		head = node;
		head->next = head;
		head->prev = head;
	}
}

void insertAtHead(Node* node) {
	if(head == NULL) {
		insertIntoEmptyList(node);
		return;
	}

	node->next = head;
	node->prev = head->prev;
	head->prev->next = node;
	head->prev = node;
	head = node;
}

void insertAtTail(Node* node) {
	if(head == NULL) {
		insertIntoEmptyList(node);
		return;
	}
	Node* tail = head->prev;
	node->prev = tail;
	node->next = head;
	tail->next = node;
	head->prev = node;
}


void insertAtMiddle(Node* node, Node* after) {
	if (head == NULL) {
		return;
	}

	if(head != NULL && head->prev == after) {
		insertAtTail(node);
		return;
	}

	Node* prev = head;
	while(prev != head->prev && prev != after) {
		prev = prev->next;
	}

	if(prev == after ) {
		node->next = prev->next;
		node->prev = prev;
		prev->next = node;
		node->next->prev = node;
	}

}


void deleteFromHead() {
	if(head == NULL) {
		return;
	}

	Node* node = head;
	head = node->next;
	if (head != node) {
		//list will not be empty after deleting head element
		head->prev = node->prev;
		node->prev->next = head;
	}
	else {
		//list will be empty after deleting the only element.
		head = NULL;
	}
	delete node;
}

void deleteFromTail() {
	if(head == NULL) {
		return;
	}
	Node* tail = head->prev;
	head->prev = tail->prev;
	if(head->prev != tail) {
		//list will not be empty after deleting the tail element.
		head->prev->next = head;
	}
	else {
		//list will be empty after deleting the only element.
		head = NULL;
	}

	delete tail;
}


void deleteFromMiddle(Node* node) {
	if(head == NULL ) {
		return;
	}
	if (head == node) {
		deleteFromHead();
		return;
	}
	if(head->prev == node) {
		deleteFromTail();
		return;
	}
	
	Node* prev = head;
	while(prev != head->prev) {
		if(prev->next == node) {
			prev->next = node->next;
			node->next->prev = prev;
			delete node;
			break;
		}
		prev = prev->next;
	}
}

void showForward() {
	cout<<">> ";
	if(head == NULL) {
		cout<<endl;
		return;
	}
	Node* node = head;
	while(node != head->prev) {
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<node->data<<endl;
}

void showBackward() {
	cout<<"<< ";
	if(head == NULL) {
		cout<<endl;
		return;
	}

	Node* node = head->prev;
	while(node != head) {
		cout<<node->data<<" ";
		node = node->prev;
	}
	cout<<node->data<<endl;
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
