/*
Problem : Convert the below tree structure into a linked list structure, whereas the linked list first element will be the top node in the tree and all the next level nodes are added as next elements in the linked list until all tree nodes are added to the linked list.

*/

#include"main.h"

int main() {
    // Create the binary tree
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);
    root->left->left->left = createTreeNode(8);
    root->left->left->right = createTreeNode(9);
    root->right->left->left = createTreeNode(10);
    root->right->right->left = createTreeNode(11);
    root->right->right->left->right = createTreeNode(12);
    root->right->right->left->right->left = createTreeNode(13);
    root->right->right->left->right->left->left = createTreeNode(14);
    root->right->right->left->right->left->left->left = createTreeNode(15);
    root->right->right->left->right->left->left->left->left = createTreeNode(16);
    
    // Convert the tree to a linked list
    struct ListNode* linkedList = treeToLinkedList(root);
    
    // Print the linked list
    printLinkedList(linkedList);
    
    return 0;
}
