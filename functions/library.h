#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_SIZE_GRAPH 1000

typedef struct graph {
    char * V;
    char ** Edge;
} Graph;

//region File management
Graph * loadGraph(char * filename, int isTree);
void saveGraph(Graph * graph, char * filename);
//endregion
//region Graph functions
int numberOfEdges(Graph * graph);
Graph * prim(Graph * graph, char initialVertex);
int getDistanceFromTop(Graph * MST, char targetVertex);
char * getEdgeByChildVertex(Graph * graph, char childVertex);
void freeGraph(Graph * graph);
//endregion

#endif