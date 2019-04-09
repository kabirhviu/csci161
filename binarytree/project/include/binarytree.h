#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "binarytreenode.h"

using namespace std;

template <typename T>
class BinaryTree {
private:
   BinaryTreeNode<T> * rootPtr;

   // private helper functions
   void insertNode(BinaryTreeNode<T>*& ptr, const T & value);
   void preOrderSubTree(const BinaryTreeNode<T> * ptr, ostream & os = cout) const;
   void inOrderSubTree(const BinaryTreeNode<T> * ptr, ostream & os = cout) const;
   void postOrderSubTree(const BinaryTreeNode<T> * ptr, ostream & os = cout) const;
   void removeSubTree(BinaryTreeNode<T>*& ptr);
public:
   BinaryTree();   // Constructor
   ~BinaryTree();  // Destructor
   void insert(const T & value);
   bool isEmpty() const;
   void preOrderTraversal(ostream & os = cout) const;
   void inOrderTraversal(ostream & os = cout) const;
   void postOrderTraversal(ostream & os = cout) const;
   void breadthFirstTraversal(ostream & os = cout) const;

   template <typename U>
   friend ostream & operator<<(ostream&, const BinaryTree<U>&);
      // Overload the stream insertion operator to print the list
};

#endif
