// C++ program to check if a given Binary Tree is symmetric or not
#include <iostream>

using namespace std;

// A Binary Tree Node
struct Node
{
    int key;
    struct Node* left, *right;
};

// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}

// Returns true if trees with roots as root1 and root2 are mirror
bool mirrorImage(struct Node *root1, struct Node *root2)
{
    // If both trees are emptu, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
    
    if (root1 && root2 && root1->key == root2->key)
        return mirrorImage(root1->left, root2->right) &&
        mirrorImage(root1->right, root2->left);
    
    // if neither of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}

// Returns true if a tree is symmetric i.e. mirror image of itself
bool isSymmetric(struct Node* root)
{
    // Check if tre is mirror of itself
    return mirrorImage(root, root);
}

// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    
    cout << isSymmetric(root) ;
    return 0;
}

/*
1
Program ended with exit code: 0
*/
