#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // Perform Insertion Sort
    insertionSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


//Start the Insertion Sort algorithm with the input array arr[] and the number of elements 'n'.
//
//Iterate 'i' from 1 to n-1:
//a. Set key = arr[i] as the current element to be inserted into the sorted subarray.
//b. Initialize 'j' to i - 1.
//
//While j >= 0 and arr[j] > key:
//a. Move elements of arr[0..j], that are greater than key, to one position ahead of their current position.
//b. Decrement j by 1.
//
//After the while loop in step 3, insert the key at the appropriate position in the sorted subarray (arr[j + 1] = key).
//
//Continue iterating 'i' from 1 to n-1 and repeat steps 2 to 4 until the entire array is sorted.
//
//End the Insertion Sort algorithm.
