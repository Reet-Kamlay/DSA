#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Return the index if key is found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[100], size, key;
    
    // Input array size from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Input array elements from user
    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key to search from user
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    // Perform binary search
    int index = binarySearch(arr, size, key);
    
    // Output the result
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    
    return 0;
}


//Start
//
//Initialize variables: low to 0 (index of the first element), high to size - 1 (index of the last element).
//
//Repeat until low is less than or equal to high:
//a. Calculate the middle index: mid = low + (high - low) / 2.
//b. If the element at arr[mid] is equal to the key:
//- Return mid, indicating that the element is found.
//c. If the element at arr[mid] is less than the key:
//- Update low = mid + 1, indicating that the key may be in the right half of the array.
//d. If the element at arr[mid] is greater than the key:
//- Update high = mid - 1, indicating that the key may be in the left half of the array.
//
//If the loop exits, return -1, indicating that the key is not found in the array.
//
//End
