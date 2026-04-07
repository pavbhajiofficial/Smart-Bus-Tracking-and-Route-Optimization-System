#include <stdio.h>
#include "graph.h"

// Node names
char *nodes[N] = {
    "Main Gate", "Anna Audi", "MGR Block", "SMV",
    "TT", "PRP", "SJT", "MGB", "Library"
};

// Adjacency matrix (distance graph)
int graph[N][N] = {
    {0, 6, 4, 0, 0, 0, 0, 0, 7},
    {6, 0, 3, 0, 0, 0, 0, 0, 5},
    {4, 3, 0, 5, 0, 0, 0, 0, 0},
    {0, 0, 5, 0, 6, 0, 0, 0, 0},
    {0, 0, 0, 6, 0, 4, 3, 0, 0},
    {0, 0, 0, 0, 4, 0, 2, 5, 0},
    {0, 0, 0, 0, 3, 2, 0, 4, 0},
    {0, 0, 0, 0, 0, 5, 4, 0, 6},
    {7, 5, 0, 0, 0, 0, 0, 6, 0}
};

void displayStops() {
    printf("\n📍 Bus Stops:\n");
    for (int i = 0; i < N; i++) {
        printf("%d. %s\n", i, nodes[i]);
    }
}
