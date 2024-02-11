
typedef struct edge {
    char src[2], dest[2];
    int weight;
} Edge;

typedef struct vertex {
    char name[4];
    int weight;
} Vertex;

Vertex * loadGraph(char * filename);