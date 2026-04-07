#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "graph.h"

#define MAX 100

// ---------- PRIORITY QUEUE ----------
struct Node {
    int vertex;
    int dist;
};

struct Node heap[MAX];
int size = 0;

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    int i = size;
    size++;

    while (i && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct Node extractMin() {
    struct Node root = heap[0];
    heap[0] = heap[size-1];
    size--;

    int i = 0;
    while (1) {
        int left = 2*i+1, right = 2*i+2, smallest = i;

        if (left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

// ---------- DIJKSTRA WITH HEAP ----------
void dijkstra(int src, int dest) {
    int dist[N];
    int parent[N];
    bool visited[N] = {0};

    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    size = 0;
    dist[src] = 0;
    insertHeap(src, 0);

    while (size > 0) {
        struct Node node = extractMin();
        int u = node.vertex;

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                insertHeap(v, dist[v]);
            }
        }
    }

    printf("\nShortest Path:\n%s", nodes[src]);
    int temp = dest;
    int path[N], k = 0;

    while (temp != -1) {
        path[k++] = temp;
        temp = parent[temp];
    }

    for (int i = k-2; i >= 0; i--) {
        printf(" -> %s", nodes[path[i]]);
    }

    printf("\nDistance: %d\n", dist[dest]);
}

// ---------- BFS (MINIMUM STOPS) ----------
void bfsShortestStops(int src, int dest) {
    int visited[N] = {0}, parent[N];
    int queue[N], front = 0, rear = 0;

    for (int i = 0; i < N; i++)
        parent[i] = -1;

    visited[src] = 1;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < N; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                queue[rear++] = v;
            }
        }
    }

    printf("\nMinimum Stops Path:\n%s", nodes[src]);

    int temp = dest, path[N], k = 0;
    while (temp != -1) {
        path[k++] = temp;
        temp = parent[temp];
    }

    for (int i = k-2; i >= 0; i--) {
        printf(" -> %s", nodes[path[i]]);
    }

    printf("\nStops: %d\n", k-1);
}

// ---------- GREEDY ----------
void findNearest(int src) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < N; i++) {
        if (graph[src][i] && graph[src][i] < min) {
            min = graph[src][i];
            index = i;
        }
    }

    printf("\nNearest Stop: %s (Distance: %d)\n",
           nodes[index], min);
}
