#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template <typename T> class BinaryTree; // Forward reference

template <typename T>
class BinaryTreeNode {
private:
   T data;
   BinaryTreeNode * rightPtr;
   BinaryTreeNode * leftPtr;
public:
   BinaryTreeNode (T d) : data(d), rightPtr(0), leftPtr(0) { };
   T getData() const { return data; };
   BinaryTreeNode * getRightPtr() const { return rightPtr; }
   BinaryTreeNode * getLeftPtr() const  { return leftPtr;  }

friend class BinaryTree<T>;
   // Make BinaryTree class a friend to access private data
};

#endif
