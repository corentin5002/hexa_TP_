#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "functions/library.h"
#include "string.h"

int main()
{
    Graph * graphFile = loadGraph("graph/graph_1.txt");

//    printf("%s\n", graphFile->V);
//    printGraph(graphFile);
    Graph * MST = prim(graphFile, 'F');
    printGraph(MST);

//    saveGraph(MST, "graph/MST_1_F");

    printf("======================\n");
    getDistanceFromTop(MST, 'D');

    return 0;
}
