#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

// Function to push (insert) an element into the stack
void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        top++;
        stack[top] = element;
        printf("Element %d pushed into the stack.\n", element);
    }
}

// Function to pop (delete) an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
    } else {
        printf("Element %d popped from the stack.\n", stack[top]);
        top--;
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, element;

    do {
        // Display menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user choice
        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
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
//Initialize a stack array of integers and a variable top to keep track of the top element of the stack. Set top to -1 initially.
//Display a menu with options: Push, Pop, Display, and Exit.
//Ask the user to choose an option from the menu.
//If the user chooses to Push:
//a. Check if the stack is full (i.e., top is at MAX_SIZE - 1). If it's full, print "Stack Overflow" message.
//b. If the stack is not full, ask the user to input the element to push onto the stack.
//c. Increment top by 1 and insert the element at stack[top].
//If the user chooses to Pop:
//a. Check if the stack is empty (i.e., top is -1). If it's empty, print "Stack Underflow" message.
//b. If the stack is not empty, print the top element of the stack, decrement top by 1.
//If the user chooses to Display:
//a. Check if the stack is empty. If it's empty, print "Stack is empty" message.
//b. If the stack is not empty, iterate from top to 0 and print each element of the stack.
//If the user chooses to Exit, terminate the program.
//Repeat steps 3-8 until the user chooses to Exit.
