#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

//region File management

Graph * loadGraph(char * filename) {

    FILE * graphFile = fopen(filename, "r");
    if (graphFile == NULL) {
        printf("Error: graphFile not found\n");
        return NULL;
    }

    char bufferVertices[200];
    int n;

    fscanf(graphFile, "%s", bufferVertices);
    Graph * graph = (Graph*) malloc(sizeof(Graph));
    n = strlen(bufferVertices);

    graph->V = (char *) malloc((n + 1) * sizeof(char));
    if (graph->V == NULL) {
        printf("Error: memory allocation failed\n");
        return NULL;
    }
    strcpy(graph->V, bufferVertices);

    graph->Edge = (char **) malloc(MAX_SIZE_GRAPH * sizeof(char *));

    int i = 0;

    //clear buffer
    fgets(bufferVertices, sizeof(bufferVertices), graphFile);

    // Read all the lines that remain to get edges
    while (
            fgets(bufferVertices, sizeof(bufferVertices), graphFile) != NULL
            && i < MAX_SIZE_GRAPH
          ) {

        char * bufferEdges = (char *) malloc(7 * sizeof(char));
        if (bufferEdges == NULL) {
            printf("Error: memory allocation failed\n");
            return NULL;
        }

        //Copy the first 6 characters of the bufferVertices to bufferEdges
        sscanf(bufferVertices, "%6s", bufferEdges);
        // Allocate memory for the edge
        graph->Edge[i] = bufferEdges;
        i++;
    }

    fclose(graphFile);
    return graph;
}

void saveGraph(Graph * graph, char * filename) {
    FILE * graphFile = fopen(filename, "w");
    if (graphFile == NULL) {
        printf("Error: graphFile not found\n");
        return;
    }

    fprintf(graphFile, "%s\n", graph->V);

    for (int i = 0; i < numberOfEdges(graph); ++i) {
        fprintf(graphFile, "%s\n", graph->Edge[i]);
    }

    fclose(graphFile);
}

//endregion


int numberOfEdges(Graph * graph) {
    int i = 0;
    while (graph->Edge[i] != NULL) {
        i++;
    }
    return i;
}

//region Prim
Graph * prim(Graph * graph, char initialVertex) {

    // Initialization of the MST
    Graph * MST = (Graph *) malloc(sizeof(Graph));
    char **includedEdges = (char **) malloc(MAX_SIZE_GRAPH * sizeof(char *));

    MST -> V    = (char *) malloc((strlen(graph->V) + 1) * sizeof(char));
    MST -> Edge = (char **) malloc(MAX_SIZE_GRAPH * sizeof(char *));

    MST -> V [0] = initialVertex;
    MST -> V [strlen(graph->V)] = '\0';

    // for each vertex in the graph, add the edge that is outside the tree with the smallest weight
    for (int i = 1; i < strlen(graph->V); ++i) {
        includedEdges[i] = (char *) malloc(7 * sizeof(char));
        char * edgeToInclude = (char *) malloc(7 * sizeof(char));
        int minWeight = 1e6;

        // Find the edge with the smallest weight
        for (int edgeIndex = 0; edgeIndex < numberOfEdges(graph); ++edgeIndex) {
            char vertex1, vertex2;
            char weight[5];
            vertex1 = graph->Edge[edgeIndex][0];
            vertex2 = graph->Edge[edgeIndex][1];
            strcpy(weight, graph->Edge[edgeIndex] + 2);

            // If the edge is not included in the MST and the weight is smaller than the current minimum
            if (
                    strchr(MST->V, vertex1) != NULL ^ strchr(MST->V, vertex2) != NULL
                    && atoi(weight) < minWeight
                )
            {
                // Get weight if it's the smallest
                minWeight = atoi(weight);

                // Get the vertex that isn't included yet
                if (strchr(MST->V, vertex1)){
                    edgeToInclude[0] = vertex1;
                    edgeToInclude[1] = vertex2;
                } else {
                    edgeToInclude[0] = vertex2;
                    edgeToInclude[1] = vertex1;
                }

                strcpy(edgeToInclude + 2, weight);
            }
        }

        // Vertex added with new edgeIndex
        MST -> V[i] = edgeToInclude[1];
        MST -> Edge[i-1] = edgeToInclude;

    }

    return MST;
}


//endregion

