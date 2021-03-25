#include <iostream>
#include "BST.h"

int main(int argc, const char * argv[]) {
   BinarySearchTree<int>bst;
   bst.insert(5);
   bst.insert(4);
   bst.insert(6);
   bst.insert(3);
   bst.insert(2);
   bst.insert(7);
   bst.printTree();
   return 0;
}
