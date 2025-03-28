#include <stdio.h>

// Function to calculate the Fibonacci series recursively
void fibonacci(int n, int a, int b) {
    if (n > 0) {
        printf("%d ", a); // Print the current Fibonacci number
        fibonacci(n - 1, b, a + b); // Recursively calculate the next Fibonacci number
    }
}

int main() {
    int n;

    // Input the number of terms from the user
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);

    // Print the Fibonacci series
    printf("Fibonacci series of %d terms: ", n);
    fibonacci(n, 0, 1);

    return 0;
}


//Start the Fibonacci algorithm with the parameters:
//
//n: The number of terms to be printed
//a: The first Fibonacci number in the series (initialized to 0)
//b: The second Fibonacci number in the series (initialized to 1)
//If n is greater than 0:
//a. Print the current Fibonacci number (a).
//b. Recursively call the Fibonacci function with parameters (n - 1, b, a + b) to calculate and print the next Fibonacci number.
//
//End the Fibonacci algorithm.
