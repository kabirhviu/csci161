#include <iostream>
#include "binarytree.cpp"

using namespace std;

int main() {
  int data[] ={6,10,5,15,7,4,9};
   BinaryTree<int> binaryTree;
   for(int i=0; i<7; i++) {
     binaryTree.insert(data[i]);
   }
   cout<<"Depth first in-order traversal"<<endl;
   cout << binaryTree;
   cout<<"Depth first pre-order traversal"<<endl;
   binaryTree.preOrderTraversal();
   cout<<"Depth first in-order traversal"<<endl;
   binaryTree.inOrderTraversal();
   cout<<"Depth first post order traversal"<<endl;
   binaryTree.postOrderTraversal();
   cout<<"Breadth first traversal"<<endl;
   binaryTree.breadthFirstTraversal();
   return 0;
}
