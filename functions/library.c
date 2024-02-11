#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

//region File management

Graph * loadGraph(char * filename, int isTree) {

    FILE * graphFile = fopen(filename, "r");
    if (graphFile == NULL) {
        printf("\n/!\\Error: %s not found\n", filename);
        return NULL;
    }

    char bufferVertices[200];
    int n, graphIsTree = 0;

    // In case we want to read a MST not any graph
    if(isTree){
        fscanf(graphFile, "%s", bufferVertices);
        if(strcmp(bufferVertices, "tree") == 0){
            graphIsTree = 1;
            fscanf(graphFile, "%s", bufferVertices);
        } else {
            printf("This file do not contain a tree\n");
            return NULL;
        }
    } else {
        // In case we just want to read a graph not a MST
        fscanf(graphFile, "%s", bufferVertices);
        if(strcmp(bufferVertices, "tree") == 0){
            // We read the second line since the first one is the "tree" mark
            fscanf(graphFile, "%s", bufferVertices);
        }
    }

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

    // If the graph is a tree, we mark it in the last edge
    if(graphIsTree){
        graph->Edge[MAX_SIZE_GRAPH - 1] = (char *) malloc(5 * sizeof(char));
        strcpy(graph->Edge[MAX_SIZE_GRAPH - 1], "tree");
    }

    fclose(graphFile);
    return graph;
}

void saveGraph(Graph * graph, char * filename) {
    FILE * graphFile = fopen(filename, "w");
    if (graphFile == NULL) {
        printf("Error: %s couldn't be reach\n", filename);
        return;
    }
    // If the graph is a tree, we mark it in the first line

    if(
            graph->Edge[MAX_SIZE_GRAPH - 1] != NULL &&
            strcmp(graph->Edge[MAX_SIZE_GRAPH - 1], "tree") == 0
        ){
        fprintf(graphFile, "%s\n", "tree");
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

    MST -> Edge[MAX_SIZE_GRAPH - 1] = (char *) malloc(5 * sizeof(char));
    strcpy(MST->Edge[MAX_SIZE_GRAPH - 1], "tree");

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

int getDistanceFromTop(Graph * MST, char targetVertex){

    if(targetVertex == MST->V[0]){
        return 0;
    }
    char top = MST->V[0];

    // Get index of that connects targetVertex to the tree
    int edgeIndex = 0;
    while(MST->Edge[edgeIndex][1] != targetVertex){
        edgeIndex++;
    }

    int distanceToTop = 0;
    char * currentEdge = MST->Edge[edgeIndex];
    while (currentEdge[0] != top){
        // Increment the distance by the weight of the current edge
        distanceToTop += atoi(currentEdge+2);
        // Get edge that leads to the antecedent of this vertex in the tree
        currentEdge = getEdgeByChildVertex(MST, currentEdge[0]);
    }
    distanceToTop += atoi(currentEdge+2);

    return distanceToTop;
}

char * getEdgeByChildVertex(Graph * graph, char childVertex){
    int edgeIndex = 0;
    while(graph->Edge[edgeIndex][1] != childVertex){
        edgeIndex++;
    }
    return graph->Edge[edgeIndex];
}

void freeGraph(Graph * graph) {
    if (graph != NULL) {
        if(graph->V != NULL) free(graph->V);

        for (int i = 0; i < MAX_SIZE_GRAPH; ++i) {
            if (graph->Edge[i] != NULL)
                free(graph->Edge[i]);
        }
        free(graph->Edge);
        free(graph);
    }
}

//endregion

