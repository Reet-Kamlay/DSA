#include <stdio.h>

int searchElement(int arr[], int size, int position, int target) {
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
        return -1;
    }
    for (int i = position; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    int arr[100]; 
    int size; 
    int position, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to start searching from: ");
    scanf("%d", &position);
    printf("Enter the target element to search: ");
    scanf("%d", &target);
    int index ;
	index= searchElement(arr, size, position, target);
    if (index != -1) {
        printf("Element %d found at position %d\n", target, index);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}

//Input the size of the array and its elements.
//Input the position to start searching from and the target element to search.
//Check if the position is valid (between 0 and size - 1).
//Search for the target element from the specified position onwards.
//If the element is found, return its index; otherwise, return -1.
//Display the result.
