#include <stdio.h>

// Function to move discs from source pole to destination pole using auxiliary pole
void towerOfHanoi(int numDiscs, char source, char destination, char auxiliary) {
    // Base case: If there is only one disc to move, move it from source to destination
    if (numDiscs == 1) {
        printf("Move disc 1 from %c to %c\n", source, destination);
        return;
    }

    // Move top (numDiscs-1) discs from source to auxiliary using destination as auxiliary pole
    towerOfHanoi(numDiscs - 1, source, auxiliary, destination);

    // Move the bottom disc from source to destination
    printf("Move disc %d from %c to %c\n", numDiscs, source, destination);

    // Move the (numDiscs-1) discs from auxiliary to destination using source as auxiliary pole
    towerOfHanoi(numDiscs - 1, auxiliary, destination, source);
}

int main() {
    int numDiscs;

    // Input the number of discs
    printf("Enter the number of discs: ");
    scanf("%d", &numDiscs);

    // Function call to solve Tower of Hanoi problem
    towerOfHanoi(numDiscs, 'A', 'C', 'B');

    return 0;
}


//Start the Tower of Hanoi algorithm with the parameters:
//
//numDiscs (number of discs to be moved)
//source (pole from which discs are initially stacked)
//destination (pole to which discs are to be moved)
//auxiliary (pole used as an auxiliary to move discs)
//If numDiscs == 1:
//a. Move the top disc from the source pole to the destination pole.
//b. Return.
//
//Otherwise (numDiscs > 1):
//a. Move (numDiscs - 1) discs from the source pole to the auxiliary pole, using the destination pole as an auxiliary, recursively invoking the Tower of Hanoi algorithm with parameters (numDiscs - 1, source, auxiliary, destination).
//b. Move the bottom disc from the source pole to the destination pole.
//c. Move (numDiscs - 1) discs from the auxiliary pole to the destination pole, using the source pole as an auxiliary, recursively invoking the Tower of Hanoi algorithm with parameters (numDiscs - 1, auxiliary, destination, source).
//
//End the Tower of Hanoi algorithm.
