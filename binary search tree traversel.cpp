#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function for inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function for preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}



//Start
//
//Define a structure for the node (struct Node) with integer data and pointers to the left and right child nodes.
//
//Define functions to create a new node (createNode), insert a node into the BST (insert), and perform three types of traversals: inorder (inorderTraversal), preorder (preorderTraversal), and postorder (postorderTraversal).
//
//Declare a pointer to the root of the BST (root) and initialize it to NULL.
//
//Insert nodes with specific values into the BST using the insert function.
//
//Perform inorder traversal:
//a. Start from the root node.
//b. Traverse the left subtree recursively.
//c. Visit the root node.
//d. Traverse the right subtree recursively.
//
//Perform preorder traversal:
//a. Visit the root node.
//b. Traverse the left subtree recursively.
//c. Traverse the right subtree recursively.
//
//Perform postorder traversal:
//a. Traverse the left subtree recursively.
//b. Traverse the right subtree recursively.
//c. Visit the root node.
//
//Print the elements obtained from each traversal.
//
//End
