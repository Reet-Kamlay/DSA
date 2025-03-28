#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return n * factorial(n - 1); // Recursive call to calculate factorial
    }
}

int main() {
    int n;

    // Input the number from the user
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    // Call the factorial function and print the result
    printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}

//Start the Factorial algorithm with the parameter n.
//
//If n is equal to 0 or 1:
//a. Return 1, as factorial of 0 and 1 is 1 (base case).
//
//Otherwise (n > 1):
//a. Calculate the factorial of (n - 1) recursively by calling the factorial function with parameter (n - 1).
//b. Multiply the result obtained in step 3a with n to get the factorial of n.
//c. Return the result obtained in step 3b.
//
//End the Factorial algorithm.
