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
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Function to insert a node at a specified position
void insertAtPosition(struct Node* last, int position, int data) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = last->next;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == last->next) {
            printf("Invalid position\n");
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) {
        last = newNode;
    }
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* last, int data) {
    if (last == NULL) {
        return createNode(data);
    }
    struct Node* newNode = createNode(data);
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

// Function to delete a node from a specified position
struct Node* deleteAtPosition(struct Node* last, int position) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position == 1) {
        struct Node* temp = last->next;
        if (temp == last) {
            free(temp);
            return NULL;
        }
        last->next = temp->next;
        free(temp);
        return last;
    }
    struct Node* temp = last->next;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == last->next) {
            printf("Invalid position\n");
            return last;
        }
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == last) {
        last = temp;
    }
    free(delNode);
    return last;
}

// Function to search for an element
int searchElement(struct Node* last, int key) {
    if (last == NULL) {
        printf("List is empty\n");
        return -1;
    }
    struct Node* temp = last->next;
    int position = 1;
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != last->next);
    return -1;
}

// Function to count the number of nodes in the list
int countNodes(struct Node* last) {
    if (last == NULL) {
        return 0;
    }
    struct Node* temp = last->next;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);
    return count;
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
    int choice, data, position, key;
    do {
        printf("\nCircular Linked List Operations:\n");
        printf("k) Creation\n");
        printf("l) Insert at beginning\n");
        printf("m) Insert at a specified position\n");
        printf("n) Insert at end\n");
        printf("o) Delete an element from a specified position\n");
        printf("p) Search an element\n");
        printf("q) Count\n");
        printf("r) Display the list\n");
        printf("s) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'k':
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                last = createNode(data);
                last->next = last;
                break;
            case 'l':
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                last = insertAtBeginning(last, data);
                break;
            case 'm':
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(last, position, data);
                break;
            case 'n':
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                last = insertAtEnd(last, data);
                break;
            case 'o':
                printf("Enter position to delete: ");
                scanf("%d", &position);
                last = deleteAtPosition(last, position);
                break;
            case 'p':
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = searchElement(last, key);
                if (position != -1)
                    printf("Element found at position: %d\n", position);
                else
                    printf("Element not found\n");
                break;
            case 'q':
                printf("Number of nodes in the list: %d\n", countNodes(last));
                break;
            case 'r':
                printf("List: ");
                displayList(last);
                break;
            case 's':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 's');

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
//If the list is empty, set the next pointer of the new node to itself.
//Otherwise, set the next pointer of the new node to the next pointer of the last node and update the next pointer of the last node to point to the new node.
//Update the last pointer to point to the new node.
//Insert at Specified Position:
//
//Traverse the list to the node at position - 1.
//Create a new node with the given data.
//Update the next pointer of the new node to the next pointer of the current node and update the next pointer of the current node to point to the new node.
//If the current node is the last node, update the last pointer to point to the new node.
//Insert at End:
//
//If the list is empty, create a new node with the given data and return it as the last node.
//Create a new node with the given data and update its next pointer to the next pointer of the last node.
//Update the next pointer of the last node to point to the new node and return the new last node.
//Delete at Specified Position:
//
//If the list is empty, print "List is empty" and return NULL.
//If the position is 1, save the pointer to the node to be deleted and update the next pointer of the last node to skip the node to be deleted.
//Free the memory occupied by the node to be deleted.
//If the deleted node is the last node, update the last pointer to point to the previous node.
//Return the last pointer.
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
//Display the List:
//
//Traverse the list and print the data of each node until the last node is reached.
//Menu-Driven Interface:
//
//Implement a loop to display a menu of options and perform the selected operation.
//Terminate the loop when the exit option is selected.
