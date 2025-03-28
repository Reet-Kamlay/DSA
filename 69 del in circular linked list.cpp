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

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* last, int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode; // Circular reference for the first node
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode; // Circular reference for the first node
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

// Function to delete a node at the beginning
struct Node* deleteAtBeginning(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (last->next == last) {
        free(last);
        return NULL;
    }
    struct Node* temp = last->next;
    last->next = temp->next;
    free(temp);
    return last;
}

// Function to delete a node at the end
struct Node* deleteAtEnd(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (last->next == last) {
        free(last);
        return NULL;
    }
    struct Node* temp = last;
    while (temp->next != last) {
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    return temp;
}

// Function to display the list
void displayList(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    struct Node* last = NULL;
    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                last = insertAtBeginning(last, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                last = insertAtEnd(last, data);
                break;
            case 3:
                last = deleteAtBeginning(last);
                break;
            case 4:
                last = deleteAtEnd(last);
                break;
            case 5:
                printf("List: ");
                displayList(last);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}



//Start
//
//Define a structure for the node (struct Node) with integer data and a pointer to the next node.
//
//Define functions for creating a new node (createNode), inserting a node at the beginning (insertAtBeginning), inserting a node at the end (insertAtEnd), deleting a node at the beginning (deleteAtBeginning), deleting a node at the end (deleteAtEnd), and displaying the list (displayList).
//
//Declare a pointer to the last node of the linked list (last) and initialize it to NULL.
//
//Display the menu options:
//
//Insert at beginning
//Insert at end
//Delete at beginning
//Delete at end
//Display the list
//Exit
//Repeat:
//a. Read the value of choice from the user.
//b. Perform the action based on the value of choice:
//
//If choice is 1:
//Prompt the user to enter the data for the new node.
//Call the insertAtBeginning function passing the last pointer and the data.
//If choice is 2:
//Prompt the user to enter the data for the new node.
//Call the insertAtEnd function passing the last pointer and the data.
//If choice is 3:
//Call the deleteAtBeginning function passing the last pointer.
//If choice is 4:
//Call the deleteAtEnd function passing the last pointer.
//If choice is 5:
//Call the displayList function passing the last pointer to display the list.
//If choice is 6, exit the loop.
//If choice is not 1, 2, 3, 4, 5, or 6, print "Invalid choice".
//Continue the loop until choice is not equal to 6.
//
//End
