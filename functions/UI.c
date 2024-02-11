#include "UI.h"
#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inputMenu() {

    char input[10];
    int selection, isValidInput = 0;

    do {

        printf("Here are the options available : \n\n"
               "0 - Load a graph\n"
               "1 - Save the graph\n"
               "2 - Get the minimal spanning tree (Algo Prim)\n"
               "3 - Load a tree\n"
               "4 - Save the tree\n"
               "5 - Get distance to a vertex (from the tree)\n"
               "6 - Quit the application\n");

        printf("\nEnter a number between 0 and %d: ", MAX_VALUE_MENU);
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Check the case the input isn't a digit
        if (input[0] < '0' || input[0] > '9') {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        selection = atoi(input);

        // Validate the number
        if (selection < 0 || selection > MAX_VALUE_MENU) {
            printf("Invalid input. Please enter a number between 0 and %d.\n", MAX_VALUE_MENU);
        } else {
            isValidInput = 1; // Set the flag to false
            break; // Exit the loop if the input is valid
        }
    } while (!isValidInput);

    printf("\n");

    return selection;
}

