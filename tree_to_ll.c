#include<stdio.h>
#include<stdlib.h>

//tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

//linked list node
typedef struct ListNode
{
    int data;
    struct ListNode* next;
}ListNode;