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

// Function to insert a node at a specified position
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

// Function to delete a node from a specified position
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
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
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

// Function to search for an element
int searchElement(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Function to count the number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the entire list
struct Node* reverseList(struct Node* head) {
    struct Node *temp = NULL, *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
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
    int choice, data, position, key;
    do {
        printf("\nMenu:\n");
        printf("u) Creation\n");
        printf("v) Insert at beginning\n");
        printf("w) Insert at a specified position\n");
        printf("x) Insert at end\n");
        printf("y) Delete an element from a specified position\n");
        printf("z) Search an element\n");
        printf("aa) Count\n");
        printf("bb) Sort the entire list (Not implemented)\n");
        printf("cc) Reverse the entire list\n");
        printf("dd) Display the list\n");
        printf("ee) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 'u':
                printf("Enter data to create the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 'v':
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 'w':
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, position, data);
                break;
            case 'x':
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 'y':
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 'z':
                printf("Enter element to search: ");
                scanf("%d", &key);
                position = searchElement(head, key);
                if (position != -1)
                    printf("Element found at position %d\n", position);
                else
                    printf("Element not found\n");
                break;
            case 'aa':
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 'bb':
                printf("Sort the entire list (Not implemented)\n");
                break;
            case 'cc':
                head = reverseList(head);
                printf("List reversed\n");
                break;
            case 'dd':
                printf("List: ");
                displayList(head);
                break;
            case 'ee':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 'ee');

    return 0;
}




//Start
//
//Define a structure for the node (struct Node) with integer data, and pointers to the previous and next nodes.
//
//Define functions for creating a new node (createNode), inserting a node at the beginning (insertAtBeginning), inserting a node at a specified position (insertAtPosition), inserting a node at the end (insertAtEnd), deleting a node from a specified position (deleteFromPosition), searching for an element (searchElement), counting the number of nodes (countNodes), reversing the entire list (reverseList), and displaying the list (displayList).
//
//Declare a pointer to the head of the doubly linked list (head) and initialize it to NULL.
//
//Display the menu options:
//
//Creation
//Insert at beginning
//Insert at a specified position
//Insert at end
//Delete an element from a specified position
//Search an element
//Count
//Sort the entire list (Not implemented)
//Reverse the entire list
//Display the list
//Exit
//Repeat:
//a. Read the value of choice from the user.
//b. Perform the action based on the value of choice:
//
//If choice is 'u':
//Prompt the user to enter the data for the first node.
//Call the createNode function and assign the returned pointer to head.
//If choice is 'v':
//Prompt the user to enter the data for the new node.
//Call the insertAtBeginning function passing head and the data.
//If choice is 'w':
//Prompt the user to enter the data and position for the new node.
//Call the insertAtPosition function passing head, position, and the data.
//If choice is 'x':
//Prompt the user to enter the data for the new node.
//Call the insertAtEnd function passing head and the data.
//If choice is 'y':
//Prompt the user to enter the position of the node to delete.
//Call the deleteFromPosition function passing head and the position.
//If choice is 'z':
//Prompt the user to enter the key to search.
//Call the searchElement function passing head and the key.
//If choice is 'aa':
//Call the countNodes function passing head.
//If choice is 'bb':
//Print a message that the sorting operation is not implemented.
//If choice is 'cc':
//Call the reverseList function passing head.
//If choice is 'dd':
//Call the displayList function passing head.
//If choice is 'ee', exit the loop.
//If choice is not 'u', 'v', 'w', 'x', 'y', 'z', 'aa', 'bb', 'cc', 'dd', or 'ee', print "Invalid choice".
//Continue the loop until choice is not equal to 'ee'.
//
//End
