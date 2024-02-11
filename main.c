#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "functions/library.h"
#include "string.h"

int main()
{
    int reload, quit = 0;

    Graph * graph = NULL, * MST = NULL;

// Set of test
//    graph = loadGraph("./graph/graphTP.txt", 0);
//    MST = prim(graph, 'D');
    while (!quit) {
        int selection = -1;
        selection = inputMenu();

        switch (selection) {
            case 0:
                printf("Loading graph\n");
                reload = 0;

                // Case where a graph is already loaded
                if(graph != NULL){
                    printGraph(graph);
                    printf("Do you want to load another graph ? (y/n): \n");
                    char input[2];
                    fgets(input, sizeof(input), stdin); // Read the entire line
                    if(input[0] == 'y'){
                        reload = 1;
                    }
                    //clear buffer
                    fgets(input, sizeof(input), stdin);
                    freeGraph(graph);
                } else {
                    reload = 1;
                }

                if (reload){
                    char * path = getFilePath();
                    graph = loadGraph(path, 0);

                    if (graph != NULL) {
                        printf("Graph loaded successfully\n");
                    }
                }
                printf("\n");
                break;
            case 1:
                printf("Saving graph\n");

                if(graph != NULL) {
                    char filename[100];
                    printf("Enter the filename: ");

                    fgets(filename, sizeof(filename), stdin);
                    filename[strcspn(filename, "\n")] = 0;

                    char path[106] = "./graph/";
                    strcat(path, filename);

                    saveGraph(graph,path);
                }
                else {
                    printf("No graph to save\n");
                }
                printf("\n");
                break;
            case 2:
                printf("Getting minimal spanning tree (Using Prim)\n");

                if(graph != NULL && numberOfEdges(graph) > 0){
                    char initialVertex;
                    printf("Enter the initial vertex: ");
                    scanf(" %c", &initialVertex);
                    // clear buffer
                    getchar();

                    // Case a MST is already generated, we free the old one
                    if (MST != NULL){
                        freeGraph(MST);
                    }

                    MST = prim(graph, initialVertex);
                    printf("\nMinimal Spanning Tree (MST) found\n");
                }
                else {
                    printf("The graph is empty or it doesn't have any edge, no MST can be found\n");
                }
                printf("\n");
                break;
            case 3:
                printf("Loading tree\n");
                reload = 0;

                // Case where a tree is already loaded
                if(MST != NULL){
                    printGraph(MST);
                    printf("Do you want to load another tree ? (y/n): \n");
                    char input[2];
                    fgets(input, sizeof(input), stdin);
                    if(input[0] == 'y'){
                        reload = 1;
                    }
                    //clear buffer
                    fgets(input, sizeof(input), stdin);

                    freeGraph(MST);
                } else {
                    reload = 1;
                }


                if (reload){
                    char filename[100];

                    printf("Enter the filename: ");
                    fgets(filename, sizeof(filename), stdin);
                    filename[strcspn(filename, "\n")] = 0;

                    // add the path to graph/ directory
                    char path[106] = "./graph/";
                    strcat(path, filename);
                    MST = loadGraph(path, 1);

                    if (MST != NULL) {
                        printf("Tree loaded successfully\n");
                    }
                }
                printf("\n");
                break;
            case 4:
                printf("Saving tree\n");
                if(MST != NULL) {
                    printf("Enter the filename: ");
                    char * path = getFilePath();

                    saveGraph(MST,path);
                }
                else {
                    printf("No tree to save\n");
                }

                printf("\n");
                break;
            case 5:
                printf("Getting distance to a vertex (from the tree)\n");

                if(MST != NULL) {
                    char targetVertex;
                    int validInput = 0;
                    while (!validInput){
                        printf("Enter the target vertex: ");
                        scanf(" %c", &targetVertex);
                        // clear buffer
                        getchar();

                        if (strchr(MST->V, targetVertex) == NULL){
                            printf("The vertex %c is not in the tree\n", targetVertex);
                        } else {
                            validInput = 1;
                        }
                    }
                    int distance = getDistanceFromTop(MST, targetVertex);
                    printf("The distance from the top to %c is %d\n", targetVertex, distance);
                }
                printf("\n");
                break;
            case 6:
                printf("");
                int verifyQuit;
                verifyQuit = 0;
                while (!verifyQuit){
                    printf("Are you sure you want to quit ? (y/n): \n");

                    char input[2];
                    fgets(input, sizeof(input), stdin); // Read the entire line
                    if(input[0] == 'y'){
                        printf("\nQuitting the application\n");

                        //free the memory
                        freeGraph(graph);
                        freeGraph(MST);

                        verifyQuit = 1;
                        quit = 1;
                        printf("Goodbye and have a nice day !\n");
                    } else if(input[0] == 'n'){
                        verifyQuit = 1;
                    } else {
                        printf("Invalid input. Please enter a number.\n");
                    }
                }
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }

    return 0;
}
