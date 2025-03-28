#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int choice, n, key, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, 0, n - 1, key);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}


//Start
//
//Declare variables:
//
//choice: to store the user's choice from the menu
//n: to store the number of elements in the array
//key: to store the key to be searched
//result: to store the index of the found element
//Read the value of n (the number of elements in the array) from the user.
//
//Declare an array arr of size n to store the elements.
//
//Read the elements of the array arr from the user.
//
//Display the menu options:
//
//Linear Search
//Binary Search
//Exit
//Repeat:
//a. Read the value of choice from the user.
//b. Perform the action based on the value of choice:
//
//If choice is 1:
//Prompt the user to enter the key to be searched.
//Call the linearSearch function passing the array arr, the number of elements n, and the key.
//If the return value is not -1, print "Element found at index: result", otherwise print "Element not found".
//If choice is 2:
//Prompt the user to enter the key to be searched.
//Call the binarySearch function passing the array arr, 0 (low index), n - 1 (high index), and the key.
//If the return value is not -1, print "Element found at index: result", otherwise print "Element not found".
//If choice is 3, exit the loop.
//If choice is not 1, 2, or 3, print "Invalid choice".
//Continue the loop until choice is not equal to 3.
//
//End.
