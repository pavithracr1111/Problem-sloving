#include"main.h"

struct ListNode* treeToLinkedList(struct TreeNode* root)
 {
    if (root == NULL) return NULL;
    
    Queue_t* front = NULL;  // Front of the queue
    Queue_t* rear = NULL;   // Rear of the queue
    
    struct ListNode* head = NULL; // Head of the linked list
    struct ListNode* tail = NULL; // Tail of the linked list

    // Enqueue the root node
    enqueue(&front, &rear, root);

    // Perform level-order traversal
    while (!isQueueEmpty(front)) 
    {
        struct TreeNode* current = dequeue(&front, &rear);
        
        // Create a linked list node from the current tree node
        struct ListNode* newListNode = createListNode(current->data);
        if (!newListNode) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        
        // Add the node to the linked list
        if (!head) {
            head = tail = newListNode;
        } else {
            tail->next = newListNode;
            tail = newListNode;
        }

        // Enqueue the left and right children of the current node
        if (current->left) enqueue(&front, &rear, current->left);
        if (current->right) enqueue(&front, &rear, current->right);
    }
    
    return head;
}
