#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UI.h"
#include "library.h"

int main()
{
    Vertex* listVertex = (Vertex*) malloc(5 * sizeof(Vertex));

    for (int i = 0; i < 5; ++i) {

        listVertex[i].name[0] = 'A' + i;
        listVertex[i].name[1] = '\0';
        listVertex[i].weight = i;
    }

    for (int i = 0; i < 5; ++i) {
        printf("%s, %d\n", listVertex[i].name, listVertex[i].weight);
    }

//    inputMenu();
    return 0;
}
