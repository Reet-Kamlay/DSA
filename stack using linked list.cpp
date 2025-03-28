#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack underflow\n");
        return NULL;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Function to display the stack
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                top = push(top, data);
                printf("%d pushed onto the stack\n", data);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}



//Start
//
//Define a structure for the node (struct Node) with integer data and a pointer to the next node.
//
//Define functions for creating a new node (createNode), checking if the stack is empty (isEmpty), pushing an element onto the stack (push), popping an element from the stack (pop), and displaying the stack (display).
//
//Declare a pointer to the top of the stack (top) and initialize it to NULL.
//
//Display the menu options:
//
//Push
//Pop
//Display
//Exit
//Repeat:
//a. Read the value of choice from the user.
//b. Perform the action based on the value of choice:
//
//If choice is 1:
//Prompt the user to enter the data to push onto the stack.
//Call the push function passing top and the data.
//If choice is 2:
//Call the pop function passing top.
//If choice is 3:
//Call the display function passing top to display the stack.
//If choice is 4, exit the loop.
//If choice is not 1, 2, 3, or 4, print "Invalid choice".
//Continue the loop until choice is not equal to 4.
//
//End
