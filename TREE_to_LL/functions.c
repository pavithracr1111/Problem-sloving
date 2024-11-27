#include "main.h"

// function to create a tree node
TreeNode *createTreeNode(int data)
{
    TreeNode *new = malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// function to create a linked list node
ListNode *createListNode(int data)
{
    ListNode *new = malloc(sizeof(ListNode));
    new->data = data;
    new->next = NULL;
    return new;
}
#include "main.h"

// Function to create a queue node
Queue_t* createQueueNode(TreeNode* node) 
{
    Queue_t* new = malloc(sizeof(Queue_t));
    if (!new) return NULL;
    new->node = node;
    new->link = NULL;
    return new;
}

// Function to enqueue
int enqueue(Queue_t** front, Queue_t** rear, TreeNode* node)
{
    Queue_t* new = createQueueNode(node);
    if (!new) return FAILURE;
    
    if (*rear) {
        (*rear)->link = new;
    } else {
        *front = new;
    }
    *rear = new;
    return SUCCESS;
}

// Function to dequeue
TreeNode* dequeue(Queue_t** front, Queue_t** rear) 
{
    if (*front == NULL) return NULL;
    Queue_t* temp = *front;
    TreeNode* node = temp->node;
    *front = temp->link;
    if (*front == NULL) *rear = NULL; // Update rear if the queue is empty
    free(temp);
    return node;
}

// Check if the queue is empty
int isQueueEmpty(Queue_t* front) 
{
    return (front == NULL);
}



// Function to print the linked list
void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}
