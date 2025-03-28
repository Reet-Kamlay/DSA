#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow! Cannot enqueue element.\n");
    } else {
        if (front == -1) {
            front = 0; // Set front to 0 if queue is empty
        }
        rear++;
        queue[rear] = element;
        printf("Element %d enqueued into the queue.\n", element);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot dequeue element.\n");
    } else {
        printf("Element %d dequeued from the queue.\n", queue[front]);
        front++;
    }
}

// Function to display the elements of the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, element;

    do {
        // Display menu
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user choice
        switch(choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


//Start the program.
//Initialize a queue array of integers and variables front and rear to keep track of the front and rear of the queue. Initially, set both front and rear to -1.
//Display a menu with options: Enqueue, Dequeue, Display, and Exit.
//Ask the user to choose an option from the menu.
//If the user chooses to Enqueue:
//a. Check if the queue is full (i.e., rear is at MAX_SIZE - 1). If it's full, print "Queue Overflow" message.
//b. If the queue is not full, increment rear by 1 and insert the element at queue[rear].
//c. If front is -1, set front to 0.
//If the user chooses to Dequeue:
//a. Check if the queue is empty (i.e., front is -1 or front is greater than rear). If it's empty, print "Queue Underflow" message.
//b. If the queue is not empty, print the front element of the queue, increment front by 1.
//If the user chooses to Display:
//a. Check if the queue is empty. If it's empty, print "Queue is empty" message.
//b. If the queue is not empty, iterate from front to rear and print each element of the queue.
//If the user chooses to Exit, terminate the program.
//Repeat steps 3-8 until the user chooses to Exit.
