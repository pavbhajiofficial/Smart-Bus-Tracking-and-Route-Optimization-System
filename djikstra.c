#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "graph.h"

// Helper function
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Print path
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %s", nodes[j]);
}

// Dijkstra Algorithm
void dijkstra(int src, int dest) {
    int dist[N];
    bool visited[N];
    int parent[N];

    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\n✅ Shortest Path:\n");
    printf("%s", nodes[src]);
    printPath(parent, dest);

    printf("\nDistance: %d\n", dist[dest]);
    printf("Estimated Time: %d mins\n", dist[dest] * 2);
}

// Greedy nearest node
void findNearest(int src) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < N; i++) {
        if (graph[src][i] && graph[src][i] < min) {
            min = graph[src][i];
            index = i;
        }
    }

    printf("\n📍 Nearest Stop: %s (Distance: %d)\n",
           nodes[index], min);
}
