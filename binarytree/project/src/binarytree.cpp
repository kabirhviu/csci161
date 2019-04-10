#include <iostream>
#include <queue>
#include "../include/binarytreenode.h"
#include "../include/binarytree.h"

using namespace std;

// Constructor - Create an empty list with no node
template <typename T>
BinaryTree<T>::BinaryTree() : rootPtr(NULL) { }

// Destructor - Remove all the dynamically allocated nodes
template <typename T>
BinaryTree<T>::~BinaryTree() {
   removeSubTree(rootPtr);
   // cout << "Destructor completed..." << endl;
}

template <typename T>
void BinaryTree<T>::removeSubTree(BinaryTreeNode<T>*& ptr) {
   if (ptr) {
      removeSubTree(ptr->leftPtr);   // remove left subtree
      removeSubTree(ptr->rightPtr);  // remove right subtree
      delete ptr;
   }
}

// Is list empty? Check if rootPtr is null
template <typename T>
bool BinaryTree<T>::isEmpty() const { return rootPtr == 0; }

// Push the data in front by dynamically allocate a new node
template <typename T>
void BinaryTree<T>::insert(const T & value) {
   insertNode(rootPtr, value);
}

// Need to pass the pointer by reference so as to modify the caller's copy
template <typename T>
void BinaryTree<T>::insertNode(BinaryTreeNode<T>*& ptr, const T & value) {
   if (ptr == 0) {
      ptr = new BinaryTreeNode<T>(value);
   } else {
      if (value < ptr->data)
         insertNode(ptr->leftPtr, value);
      else if (value > ptr->data)
         insertNode(ptr->rightPtr, value);
      else
         cout << "duplicate value" << endl;
   }
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::searchInTree(const T & value){
  return searchInTree(rootPtr, value);
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::searchInTree(BinaryTreeNode<T> * ptr, const T & value) {
  if(ptr == 0) {
    return NULL;
  }
  else if(value == ptr->data) {
    return ptr;
  }
  else if( value < ptr->data) {
    return searchInTree(ptr->leftPtr, value);
  }
  else {
    return searchInTree(ptr->rightPtr, value);
  }
}

template <typename T>
void BinaryTree<T>::preOrderTraversal(ostream & os) const {
   os << "{ ";
   preOrderSubTree(rootPtr);
   os << '}' << endl;
}

template <typename T>
void BinaryTree<T>::preOrderSubTree(const BinaryTreeNode<T> * ptr, ostream & os) const {
   if (ptr) {
      os << ptr->data << ' ';
      preOrderSubTree(ptr->leftPtr);
      preOrderSubTree(ptr->rightPtr);
   }
}

template <typename T>
void BinaryTree<T>::inOrderTraversal(ostream & os) const {
   os << "{ ";
   inOrderSubTree(rootPtr);
   os << '}' << endl;
}

template <typename T>
void BinaryTree<T>::inOrderSubTree(const BinaryTreeNode<T> * ptr, ostream & os) const {
   if (ptr) {
      inOrderSubTree(ptr->leftPtr);
      os << ptr->data << ' ';
      inOrderSubTree(ptr->rightPtr);
   }
}

template <typename T>
void BinaryTree<T>::postOrderTraversal(ostream & os) const {
   os << "{ ";
   postOrderSubTree(rootPtr);
   os << '}' << endl;
}

template <typename T>
void BinaryTree<T>::postOrderSubTree(const BinaryTreeNode<T> * ptr, ostream & os) const {
   if (ptr) {
      postOrderSubTree(ptr->leftPtr);
      postOrderSubTree(ptr->rightPtr);
      os << ptr->data << ' ';
   }
}

// Breadth First Search (BFS)
template <typename T>
void BinaryTree<T>::breadthFirstTraversal(ostream & os) const {
   queue<BinaryTreeNode<T> * > q;
   if (!isEmpty()) q.push(rootPtr);

   os << "{ ";
   BinaryTreeNode<T> * currentPtr;
   while ((currentPtr = q.front())) {
      cout << currentPtr->data << ' ';
      if (currentPtr->leftPtr) q.push(currentPtr->leftPtr);
      if (currentPtr->rightPtr) q.push(currentPtr->rightPtr);
      q.pop();  // remove this node
   }
   os << '}' << endl;
}

// Overload the stream insertion operator to print the list in in-order traversal
template <typename T>
ostream & operator<< (ostream & os, const BinaryTree<T> & lst) {
   lst.inOrderTraversal(os);
   return os;
}
