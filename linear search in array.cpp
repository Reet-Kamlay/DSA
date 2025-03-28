#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index if key is found
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
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key to search from user
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    // Perform linear search
    int index = linearSearch(arr, size, key);
    
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
//Declare an array of integers arr.
//
//Read the size of the array n.
//
//Read the elements of the array arr.
//
//Read the element key to be searched.
//
//Initialize a variable index to store the index of the element found.
//
//Iterate through the array using a loop from index 0 to n-1:
//a. Check if the current element is equal to key.
//b. If it is, assign the current index to index and break out of the loop.
//
//If index is not -1, print "Element found at index: index".
//Else, print "Element not found".
//
//End
