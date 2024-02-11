#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_SIZE_GRAPH 1000

typedef struct graph {
    char * V;
    char ** Edge;
} Graph;

//region File management
Graph * loadGraph(char * filename);
void saveGraph(Graph * graph, char * filename);
//endregion
int numberOfEdges(Graph * graph);
Graph * prim(Graph * graph, char initialVertex);
char ** getEdgesConnected(Graph * graph, char * includedVertices);


#endif