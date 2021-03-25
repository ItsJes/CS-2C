#include <iostream>
#include "BST.h"

using namespace std;

template <typename Comparable>
class OutputTree
{
public:
	void operator()(Comparable &x)
	{
		cout << x << endl;
	}
};

int main(int argc, const char * argv[]) {
	BinarySearchTree<int>bst;
	bst.insert(5);
	bst.insert(4);
	bst.insert(6);
	bst.insert(3);
	bst.insert(2);
	bst.insert(7);
	//bst.printTree();
	OutputTree<int>o;
	bst.inOrderTraverse(o);
	return 0;
}
