#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

int getLeafCount(node* node)
{
    if(node == NULL)
        return 0;
    else if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return getLeafCount(node->left) + getLeafCount(node->right);
}

int getNodeCount(node* node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    else
        return getNodeCount(node->left) + getNodeCount(node->right) + 1;
}

int getFullNodes(node* node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    else if (node->left != NULL && node->right != NULL)
        return getFullNodes(node->left) + getFullNodes(node->right) + 1;
    else
        return getFullNodes(node->left) + getFullNodes(node->right);
}

struct node* newNode(int data)
{
    struct node*node = (struct node*)
    malloc(sizeof(struct node));
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

/**
 *      root
 *       /\
 *   left  right
 *    /\
 *left  right
 * return
 */

TEST(test1, test)
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Leaf count of tree is %d\n", getLeafCount(root));
    printf("Node count of tree is %d\n", getNodeCount(root));
    printf("There are %d full nodes in tree\n", getFullNodes(root));
}

TEST(test2, test)
{
    
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Leaf count of tree is %d\n", getLeafCount(root));
    printf("Node count of tree is %d\n", getNodeCount(root));
    printf("There are %d full nodes in tree\n", getFullNodes(root));
}

TEST(test3, test)
{
    
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Leaf count of tree is %d\n", getLeafCount(root));
    printf("Node count of tree is %d\n", getNodeCount(root));
    printf("There are %d full nodes in tree\n", getFullNodes(root));
}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}









