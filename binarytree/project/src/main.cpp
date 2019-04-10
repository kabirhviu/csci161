#include <iostream>
#include "binarytree.cpp"

using namespace std;

int main() {
  int data[] ={6,10,5,15,7,4,9};
   BinaryTree<int> binaryTree;
   for(int i=0; i<7; i++) {
     binaryTree.insert(data[i]);
   }
   BinaryTreeNode<int>* treeNode = binaryTree.searchInTree(15);

   cout<<"Searching 15....."<<endl;
   if(treeNode) {
     cout<<"Found: " <<treeNode->getData()<<endl;
   }
   else {
     cout<<"Not Found"<<endl;
   }

   cout<<"Searching 14....."<<endl;
   treeNode = binaryTree.searchInTree(14);
   if(treeNode) {
     cout<<"Found: " <<treeNode->getData()<<endl;
   }
   else {
     cout<<"Not Found"<<endl;
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
