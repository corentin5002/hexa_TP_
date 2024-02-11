#include <stdio.h>
#include <stdlib.h>
#include "library.h"


Vertex * loadGraph(char * filename) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found\n");
        return NULL;
    }

    char buffer[4];
    int n = 4;
    fscanf(file, "%s", buffer);
    Vertex * listVertex = (Vertex*) malloc(sizeof(Vertex));

    for (int i = 0; i < n; ++i) {
        fscanf(file, "%s %d", listVertex[i].name, &listVertex[i].weight);
    }
    fclose(file);
    return listVertex;
}
