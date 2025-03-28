#include <stdio.h>

// Function to find GCD recursively
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case: GCD(a, 0) = a
    } else {
        return gcd(b, a % b); // Recursive call to find GCD
    }
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);

    // Call the gcd function and print the result
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

    return 0;
}


//Start the GCD algorithm with the parameters:
//
//num1: The first number
//num2: The second number
//If num2 is equal to 0:
//a. Return num1, as GCD(num1, 0) = num1 (base case).
//
//Otherwise:
//a. Recursively call the GCD function with parameters (num2, num1 % num2) to find the GCD of num2 and the remainder of num1 divided by num2.
//
//End the GCD algorithm.
