#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to display the array
void display(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n, arr[100];

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on choice
        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                display(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                display(arr, n);
                break;
            case 3:
                selectionSort(arr, n);
                display(arr, n);
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
//Declare variables: choice (integer), n (integer), arr (array of integers).
//
//Input the size of the array (n) from the user.
//
//Input n elements into the array (arr) from the user.
//
//Repeat until the user chooses to exit:
//a. Display the menu options:
//- Bubble Sort
//- Insertion Sort
//- Selection Sort
//- Exit
//b. Input the user's choice (choice).
//c. Perform the action based on the user's choice:
//- If choice is 1:
//- Call the bubbleSort function passing arr and n as arguments.
//- Display the sorted array using the display function.
//- If choice is 2:
//- Call the insertionSort function passing arr and n as arguments.
//- Display the sorted array using the display function.
//- If choice is 3:
//- Call the selectionSort function passing arr and n as arguments.
//- Display the sorted array using the display function.
//- If choice is 4, exit the loop.
//- If choice is not 1, 2, 3, or 4, print "Invalid choice".
//
//End
