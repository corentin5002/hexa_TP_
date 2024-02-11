#include "UI.h"
//#include "library.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inputMenu() {

    char input[10];
    int selection, isValidInput = 0;

    do {

        printf("Here are the options available : \n\n"
               "0 - Load a graph / see current one\n"
               "1 - Save the graph\n"
               "2 - Get the minimal spanning tree (Algo Prim)\n"
               "3 - Load a tree / see current one\n"
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

void printGraph(Graph * graph) {
    printf("The current graph is : \n\n");
    printf("Vertices : %s\n", graph->V);
    printf("Edges : \n");
    for (int i = 0; i < numberOfEdges(graph); ++i) {
        char vertex1, vertex2, weight[5];

        vertex1 = graph->Edge[i][0];
        vertex2 = graph->Edge[i][1];
        strcpy(weight, graph->Edge[i] + 2);

        printf("%c <--> %c  w = %s\n",vertex1, vertex2 , weight);
    }
}

char * getFilePath() {
    char filename[100];
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;

    // add the path to graph/ directory
    char * path= (char *) malloc(106 * sizeof(char));
    strcpy(path, "./graph/");
    strcat(path, filename);
    return path;
}