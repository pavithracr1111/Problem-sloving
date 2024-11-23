/*
Problem : Convert the below tree structure into a linked list structure, whereas the linked list first element will be the top node in the tree and all the next level nodes are added as next elements in the linked list until all tree nodes are added to the linked list.

*/
#include <stdio.h>

// tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// linked list node
typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

// function to create a tree node
TreeNode *createTreeNode(int data)
{
    TreeNode *new = malloc(sizeof(TreeNode));
    if (new == NULL)
        return -1;
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// function to create a linked list node
ListNode *createListNode(int data)
{
    ListNode *new = malloc(sizeof(ListNode));
    if (new == NULL)
        return -1;
    new->data = data;
    new->next = NULL;
    return new;
}