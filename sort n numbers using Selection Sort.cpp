#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted part
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Selection Sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Start the Selection Sort algorithm with the input array arr[] and the number of elements 'n'.
//
//Iterate 'i' from 0 to n-2:
//a. Set minIndex = i as the index of the minimum element in the unsorted part of the array.
//
//Within the outer loop:
//a. Iterate 'j' from i+1 to n-1:
//i. If arr[j] is less than arr[minIndex], update minIndex to j.
//
//After completing the inner loop, swap the minimum element (arr[minIndex]) with the first element of the unsorted part (arr[i]).
//
//Continue iterating 'i' from 0 to n-2 and repeat steps 2 to 4 until the entire array is sorted.
//
//End the Selection Sort algorithm.

