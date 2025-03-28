#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
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

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



//Start the Bubble Sort algorithm with the input array arr[] and the number of elements 'n'.
//
//Iterate 'i' from 0 to n-1:
//a. Within the outer loop, iterate 'j' from 0 to n-i-1:
//i. Compare arr[j] and arr[j+1].
//ii. If arr[j] is greater than arr[j+1], swap them.
//
//Continue iterating 'i' from 0 to n-1 and 'j' from 0 to n-i-1 until the array is sorted.
//
//End the Bubble Sort algorithm.
