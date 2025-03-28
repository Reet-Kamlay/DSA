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

// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return front == NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(*front)) {
        *front = newNode;
    } else {
        (*rear)->next = newNode;
    }
    *rear = newNode;
    printf("%d enqueued into the queue\n", data);
}

// Function to dequeue (delete) an element from the queue
void dequeue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue underflow\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

// Function to display the queue
void display(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
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
//Define functions for creating a new node (createNode), checking if the queue is empty (isEmpty), enqueuing (enqueue) an element into the queue, dequeuing (dequeue) an element from the queue, and displaying the queue (display).
//
//Declare pointers to the front and rear of the queue (front and rear) and initialize them to NULL.
//
//Display the menu options:
//
//Enqueue
//Dequeue
//Display
//Exit
//Repeat:
//a. Read the value of choice from the user.
//b. Perform the action based on the value of choice:
//
//If choice is 1:
//Prompt the user to enter the data to enqueue into the queue.
//Call the enqueue function passing the address of front, rear, and the data.
//If choice is 2:
//Call the dequeue function passing the address of front and rear.
//If choice is 3:
//Call the display function passing front to display the queue.
//If choice is 4, exit the loop.
//If choice is not 1, 2, 3, or 4, print "Invalid choice".
//Continue the loop until choice is not equal to 4.
//
//End
