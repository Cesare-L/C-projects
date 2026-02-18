#include <stdio.h>

int main(int argc, char *argv[]) { // argc = argument count (how many string inputs) argv = argument vector (an array of strings)

    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]); // argv[0] is the first string inputed in command line, therefore the name of the program
        return 1;
    }

    for(int i = 0; i < argc; i++) { // every time argc is more than i, execute and add 1 to i 
        printf(" %s", argv[i]); // execute, print out the string at position i of the array
    }

    printf("\n"); // go to newline after for loop condition is false

}
