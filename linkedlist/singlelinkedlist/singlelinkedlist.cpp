#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next = NULL;;
};

Node* head = NULL;

void insertAtHead(Node* node) {
	if(head == NULL) {
		head = node;
		return;
	}

	node->next = head;
	head = node;
}

void insertAtMiddle(Node* node, Node* after) {
	Node* prev = head;
	while(prev != NULL && prev != after) {
		prev = prev->next;
	}
	if(prev != NULL && prev == after) {
		node->next = prev->next;
		prev->next = node;
	}

}


void deleteFromHead() {
	if(head == NULL) {
		return;
	}

	Node* node = head;
	head = node->next;
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

	Node* sixth = new Node;
	sixth->data = 60;
	insertAtMiddle(sixth, third);

	showForward();


	Node* seventh = new Node;
	seventh->data = 70;
	insertAtMiddle(seventh, first);

	showForward();


	deleteFromMiddle(sixth);

	showForward();

	deleteFromMiddle(seventh);

	showForward();

	deleteFromHead();

	showForward();

	while(head != NULL) {
		deleteFromHead();
		showForward();
	}	

	
	return 0;
}
