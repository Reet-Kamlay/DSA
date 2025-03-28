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

// Function to insert a node at a specified position
void insertAtPosition(struct Node* head, int position, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from a specified position
void deleteAtPosition(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to search for an element
int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to swap data of two nodes
void swapData(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the entire list
void sortList(struct Node* head) {
    struct Node* temp1;
    struct Node* temp2 = NULL;
    int swapped;
    if (head == NULL)
        return;
    do {
        swapped = 0;
        temp1 = head;
        while (temp1->next != temp2) {
            if (temp1->data > temp1->next->data) {
                swapData(temp1, temp1->next);
                swapped = 1;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    } while (swapped);
}

// Function to reverse the entire list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;
    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at specified position\n");
        printf("3. Insert at end\n");
        printf("4. Delete at specified position\n");
        printf("5. Search element\n");
        printf("6. Count nodes\n");
        printf("7. Sort the entire list\n");
        printf("8. Reverse the entire list\n");
        printf("9. Display the list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(head, position, data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(head, position);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = searchElement(head, key);
                if (position != -1)
                    printf("Element found at position: %d\n", position);
                else
                    printf("Element not found\n");
                break;
            case 6:
                printf("Number of nodes in the list: %d\n", countNodes(head));
                break;
            case 7:
                sortList(head);
                printf("List sorted successfully\n");
                break;
            case 8:
                reverseList(&head);
                printf("List reversed successfully\n");
                break;
            case 9:
                printf("List: ");
                displayList(head);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 10);

    return 0;
}


//Node Structure:
//
//Define a structure for a node containing data and a pointer to the next node.
//Create Node Function:
//
//Function to create a new node with the given data.
//Insert at Beginning:
//
//Create a new node with the given data.
//Set the next pointer of the new node to the current head.
//Update the head pointer to point to the new node.
//Insert at Specified Position:
//
//Create a new node with the given data.
//Traverse the list to the node at position - 1.
//Update the next pointers to insert the new node at the specified position.
//Insert at End:
//
//Create a new node with the given data.
//Traverse the list to the last node.
//Update the next pointer of the last node to point to the new node.
//Delete at Specified Position:
//
//Traverse the list to the node at position - 1.
//Save the pointer to the node to be deleted.
//Update the next pointer of the previous node to skip the node to be deleted.
//Free the memory occupied by the node to be deleted.
//Search Element:
//
//Traverse the list while comparing the data of each node with the given key.
//If a node with the key is found, return its position.
//If the end of the list is reached without finding the key, return -1.
//Count Nodes:
//
//Initialize a counter to 0.
//Traverse the list and increment the counter for each node.
//Return the counter.
//Sort the Entire List:
//
//Implement a sorting algorithm such as Bubble Sort, Selection Sort, Merge Sort, etc.
//Traverse the list and rearrange the nodes according to the sorted order.
//Reverse the Entire List:
//
//Initialize three pointers: prev, current, and next.
//Traverse the list and for each node:
//Update next to point to the next node.
//Update current's next to point to prev.
//Move prev and current one step forward.
//Update the head pointer to point to prev.
//Display the List:
//
//Traverse the list and print the data of each node.
//Menu-Driven Interface:
//
//Implement a loop to display a menu of options and perform the selected operation.
//Terminate the loop when the exit option is selected.
