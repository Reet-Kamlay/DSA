#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a node at a given position
struct Node* insertAtPosition(struct Node* head, int position, int data) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;
    }
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    if (temp == head) {
        head = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from a given position
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position < 1) {
        printf("Invalid position\n");
        return head;
    }
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    free(temp);
    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any given position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from any given position\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, position, data);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                printf("List: ");
                displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}



//Start
//
//Define a structure for the node (struct Node) with integer data, and pointers to the previous and next nodes.
//
//Define functions for creating a new node (createNode), inserting a node at the beginning (insertAtBeginning), inserting a node at the end (insertAtEnd), inserting a node at a given position (insertAtPosition), deleting a node from the beginning (deleteFromBeginning), deleting a node from the end (deleteFromEnd), deleting a node from a given position (deleteFromPosition), and displaying the list (displayList).
//
//Declare a pointer to the head of the doubly linked list (head) and initialize it to NULL.
//
//Display the menu options:
//
//Insert at beginning
//Insert at end
//Insert at any given position
//Delete from beginning
//Delete from end
//Delete from any given position
//Display the list
//Exit
//Repeat:
//a. Read the value of choice from the user.
//b. Perform the action based on the value of choice:
//
//If choice is 1:
//Prompt the user to enter the data for the new node.
//Call the insertAtBeginning function passing the head pointer and the data.
//If choice is 2:
//Prompt the user to enter the data for the new node.
//Call the insertAtEnd function passing the head pointer and the data.
//If choice is 3:
//Prompt the user to enter the data for the new node and the position to insert.
//Call the insertAtPosition function passing the head pointer, position, and the data.
//If choice is 4:
//Call the deleteFromBeginning function passing the head pointer.
//If choice is 5:
//Call the deleteFromEnd function passing the head pointer.
//If choice is 6:
//Prompt the user to enter the position to delete.
//Call the deleteFromPosition function passing the head pointer and the position.
//If choice is 7:
//Call the displayList function passing the head pointer to display the list.
//If choice is 8, exit the loop.
//If choice is not 1, 2, 3, 4, 5, 6, 7, or 8, print "Invalid choice".
//Continue the loop until choice is not equal to 8.
//
//End
