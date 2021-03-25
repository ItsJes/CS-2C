#ifndef BST_h
#define BST_h

#include <iostream>
#include <stack>

template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree() {}
	BinarySearchTree(const BinarySearchTree & rhs);
	BinarySearchTree(BinarySearchTree<Comparable> && rhs);
	~BinarySearchTree() { makeEmpty(); }

	const Comparable & findMin() const;
	const Comparable & findMax() const;

	bool contains(const Comparable & x) const;
	bool isEmpty() const { return root == NULL; }

	void printTree(std::ostream & out = std::cout) const;
	template <typename Func> void inOrderTraverse(Func f) const;
	void makeEmpty() { makeEmpty(root); }
	void insert(const Comparable & x);
	void insert(Comparable && x);
	void remove(const Comparable & x);

	BinarySearchTree & operator=(const BinarySearchTree & rhs);
	BinarySearchTree & operator=(BinarySearchTree && rhs);

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const Comparable & theElement, BinaryNode *lt, BinaryNode *rt)
			: element(theElement), left(lt), right(rt) { }
		BinaryNode(Comparable && theElement, BinaryNode *lt, BinaryNode *rt)
			: element(std::move(theElement)), left(lt), right(rt) { }
	};
	BinaryNode *root;

	void insert(const Comparable & x, BinaryNode * & t);
	void insert(Comparable && x, BinaryNode * & t);
	void remove(const Comparable & x, BinaryNode * & t);

	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;

	bool contains(const Comparable & x, BinaryNode *t) const;
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t, std::ostream & out) const;

	BinaryNode * clone(BinaryNode *t) const;
};

/**
* Returns true if x is found in the tree.
*/
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x) const
{
	return contains(x, root);
}
/** 10 * Insert x into the tree; duplicates are ignored. 11 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x)
{
	insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable && x)
{
	insert(x, root);
}

/** 18 * Remove x from the tree. Nothing is done if x is not found. 19 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x)
{
	remove(x, root);
}

/**
* Internal method to test if an item is in a subtree.
* x is item to search for. 4 * t is the node that roots the subtree.
*/
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode *t) const
{
	if (t == NULL)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true; // Match 16
}

/**
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item. 4 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::findMin(BinaryNode *t) const
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

/**
* Internal method to find the largest item in a subtree t.
* Return node containing the largest item.
*/
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::findMax(BinaryNode *t) const
{
	if (t != NULL)
		while (t->right != NULL)
			t = t->right;
	return t;
}

/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode *&t)
{
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		; // Duplicate; do nothing
}
/**
* Internal method to insert into a subtree.
* x is the item to insert by moving.
* t is the node that roots the subtree.
* Set the new root of the subtree. 24 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable && x, BinaryNode *&t)
{
	if (t == NULL)
		t = new BinaryNode(std::move(x), NULL, NULL);
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		; // Duplicate; do nothing 35
}

/**
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode *&t)
{
	if (t == NULL)
		return; // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
}

/**
* Internal method to make subtree empty.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

/**
* Copy constructor
*/
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree & rhs)
{
	root = clone(rhs.root);
}

/**
* Internal method to clone subtree.
*/
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::clone(BinaryNode *t) const
{
	if (t == NULL)
		return NULL;
	else
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
}

/**
* Print the tree contents in sorted order.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(std::ostream & out) const
{
	if (isEmpty())
		out << "Empty tree" << std::endl;
	else
		printTree(root, out);
}

/**
* Internal method to print a subtree rooted at t in sorted order.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode *t, std::ostream & out) const
{
	if (t != NULL)
	{
		printTree(t->left, out);
		out << t->element << std::endl;
		printTree(t->right, out);
	}
}

template <typename Comparable>
template <typename Func>
void BinarySearchTree<Comparable>::inOrderTraverse(Func f) const
{
	std::stack<BinaryNode*>stack;
	BinaryNode* node = root;
	while (!stack.empty() || node != NULL)
	{
		if (node != NULL)
		{
			stack.push(node);
			node = node->left;
		}
		else
		{
			node = stack.top();
			stack.pop();
			f(node->element);
			node = node->right;
		}
	}
}

#endif /* BST_h */
