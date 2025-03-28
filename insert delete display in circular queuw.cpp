#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to insert an element into the circular queue
void enqueue(int element) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue Overflow! Cannot enqueue element.\n");
    } else {
        if (front == -1) {
            front = 0; // Set front to 0 if queue is empty
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("Element %d enqueued into the queue.\n", element);
    }
}

// Function to delete an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Cannot dequeue element.\n");
    } else {
        printf("Element %d dequeued from the queue.\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// Function to display the elements of the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue:\n");
        int i = front;
        do {
            printf("%d\n", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
    }
}

int main() {
    int choice, element;

    do {
        // Display menu
        printf("\nCircular Queue Operations Menu:\n");
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
//Initialize a circular queue array of integers and variables front and rear to keep track of the front and rear of the queue. Initially, set both front and rear to -1.
//Display a menu with options: Enqueue, Dequeue, Display, and Exit.
//Ask the user to choose an option from the menu.
//If the user chooses to Enqueue:
//a. Check if the circular queue is full. If it's full (rear + 1) % MAX_SIZE == front, print "Queue Overflow" message.
//b. If the circular queue is not full, increment rear by 1 using the formula (rear + 1) % MAX_SIZE, and insert the element at queue[rear].
//c. If front is -1, set front to 0.
//If the user chooses to Dequeue:
//a. Check if the circular queue is empty. If it's empty (front == -1), print "Queue Underflow" message.
//b. If the circular queue is not empty, print the element at the front of the queue, and move front forward by 1 using the formula (front + 1) % MAX_SIZE.
//c. If front becomes equal to rear after dequeuing, it means there was only one element in the queue. In this case, set both front and rear to -1 to indicate an empty queue.
//If the user chooses to Display:
//a. Check if the circular queue is empty. If it's empty, print "Queue is empty" message.
//b. If the circular queue is not empty, use a loop to iterate from front to rear, wrapping around to the beginning of the array using the formula (i + 1) % MAX_SIZE, and print each element of the queue.
//If the user chooses to Exit, terminate the program.
//Repeat steps 3-8 until the user chooses to Exit.
