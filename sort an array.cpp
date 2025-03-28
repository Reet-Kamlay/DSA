#include <stdio.h>

// Function to perform bubble sort on the array
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100]; // Assuming maximum array size is 100
    int size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input the elements of the array
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to sort the array
    bubbleSort(arr, size);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Start with the first element (index 0) of the array.
//Compare the current element with the next element.
//If the current element is greater than the next element, swap them.
//Move to the next pair of elements and repeat steps 2 and 3 until the end of the array is reached.
//After the first pass, the largest element will be at the end of the array.
//Repeat steps 1-5 for the remaining elements (excluding the already sorted ones) until the entire array is sorted.
//The array is now sorted in ascending order.

