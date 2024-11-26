#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

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

//Queue node
typedef struct Queue
{
    TreeNode* node;
    struct Queue *link;
} Queue_t;

TreeNode *createTreeNode(int data);
ListNode *createListNode(int data);
struct ListNode* treeToLinkedList(struct TreeNode* root);
Queue_t* createQueueNode(TreeNode* node);
TreeNode* dequeue(Queue_t** front, Queue_t** rear);
int enqueue(Queue_t** front, Queue_t** rear, TreeNode* node);
int isQueueEmpty(Queue_t* front);
void printLinkedList(struct ListNode* head);

#endif