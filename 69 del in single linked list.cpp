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
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to delete a node at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a specified position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return head;
        }
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
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
        printf("2. Delete at beginning\n");
        printf("3. Delete at end\n");
        printf("4. Delete at a specified position\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                head = deleteAtBeginning(head);
                break;
            case 3:
                head = deleteAtEnd(head);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 5:
                printf("List: ");
                displayList(head);
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
//Define functions for creating a new node (createNode), inserting a node at the beginning (insertAtBeginning), deleting a node at the beginning (deleteAtBeginning), deleting a node at the end (deleteAtEnd), deleting a node at a specified position (deleteAtPosition), and displaying the list (displayList).
//
//Declare a pointer to the head of the linked list (head) and initialize it to NULL.
//
//Display the menu options:
//
//Insert at beginning
//Delete at beginning
//Delete at end
//Delete at a specified position
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
//Call the deleteAtBeginning function passing the head pointer.
//If choice is 3:
//Call the deleteAtEnd function passing the head pointer.
//If choice is 4:
//Prompt the user to enter the position of the node to delete.
//Call the deleteAtPosition function passing the head pointer and the position.
//If choice is 5:
//Call the displayList function passing the head pointer to display the list.
//If choice is 6, exit the loop.
//If choice is not 1, 2, 3, 4, 5, or 6, print "Invalid choice".
//Continue the loop until choice is not equal to 6.
//
//End
