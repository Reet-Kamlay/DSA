#include <stdio.h>

// Function to perform Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    int index = interpolationSearch(arr, n, key);
    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found in the array\n", key);
    
    return 0;
}


//Start
//
//Declare variables: arr (array of integers), n (integer), key (integer), low (integer), high (integer), pos (integer).
//
//Input the size of the array (n) from the user.
//
//Input n elements into the array (arr) from the user in sorted order.
//
//Input the element to search (key) from the user.
//
//Initialize low to 0 and high to n - 1.
//
//Repeat until low is less than or equal to high, and key is greater than or equal to arr[low], and key is less than or equal to arr[high]:
//a. If low is equal to high, check if key is equal to arr[low]. If true, return low, indicating that the element is found. Otherwise, return -1, indicating that the element is not found.
//b. Calculate the position pos using the interpolation formula:
//pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low])) c. If arr[pos] is equal to key, return pos, indicating that the element is found.
//d. If arr[pos] is less than key, update low = pos + 1.
//e. Otherwise, update high = pos - 1.
//
//If the loop exits, return -1, indicating that the element is not found in the array.
//
//End
