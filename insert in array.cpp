#include <stdio.h>

void insertElement(int arr[], int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

int main() {
    int arr[100]; 
    int size = 5; 
    int position, element;
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert: ");
    scanf("%d", &position);
    insertElement(arr, &size, position, element);
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

//Take input the element to be inserted and the position at which it is to be inserted.
//Check if the position is valid (between 0 and current size of the array).
//Shift all elements from the specified position to the right by one position.
//Insert the new element at the specified position.
//Increment the size of the array.
//Display the updated array.
