//  main.cpp
//  Q3
//  Created by Sara Akhtar on 5/28/17.
//  Copyright © 2017 Sara Akhtar. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

int isBST(struct node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(struct node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;
    
    return
    isBSTUtil(node->left, min, node->data-1) &&
    isBSTUtil(node->right, node->data+1, max);
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

int main()
{
    struct node *root = newNode(4);
    root->left	 = newNode(2);
    root->right	 = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    
    if(isBST(root))
        printf("It is a BST");
    else
        printf("It is not a BST");
    
    getchar();
    return 0;
} 
