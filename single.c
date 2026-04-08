// smart_bus_system.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 6   // number of stops

// Stop names
char *stops[N] = {
    "Central", "Egmore", "T Nagar",
    "Guindy", "Velachery", "Tambaram"
};

// Graph (adjacency matrix)
int graph[N][N] = {
    {0, 5, 0, 0, 0, 0},
    {5, 0, 4, 0, 0, 0},
    {0, 4, 0, 7, 3, 0},
    {0, 0, 7, 0, 0, 0},
    {0, 0, 3, 0, 0, 6},
    {0, 0, 0, 0, 6, 0}
};

// Bus structure
typedef struct {
    float lat;
    float lon;
} Bus;

Bus buses[2] = {
    {13.0827, 80.2707},
    {13.0500, 80.2200}
};

// -----------------------------
// Simulate live tracking
// -----------------------------
void updateBusLocations() {
    for (int i = 0; i < 2; i++) {
        buses[i].lat += ((rand() % 100) - 50) / 100000.0;
        buses[i].lon += ((rand() % 100) - 50) / 100000.0;
    }
}

void showBuses() {
    updateBusLocations();
    printf("\n🚍 Live Bus Locations:\n");
    for (int i = 0; i < 2; i++) {
        printf("Bus %d -> Lat: %.5f, Lon: %.5f\n", i + 1, buses[i].lat, buses[i].lon);
    }
}

// -----------------------------
// Dijkstra Algorithm
// -----------------------------
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%s", stops[j]);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %s", stops[j]);
}

void dijkstra(int start, int end) {
    int dist[N];
    int visited[N] = {0};
    int parent[N];

    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\n📍 Shortest Route:\n");
    printPath(parent, end);
    printf("\nTotal Distance: %d\n", dist[end]);
}

// -----------------------------
// Menu
// -----------------------------
void showStops() {
    printf("\nBus Stops:\n");
    for (int i = 0; i < N; i++) {
        printf("%d. %s\n", i, stops[i]);
    }
}

int main() {
    srand(time(0));
    int choice;

    while (1) {
        printf("\n====== SMART BUS SYSTEM ======\n");
        printf("1. Show Live Bus Locations\n");
        printf("2. Find Optimized Route\n");
        printf("3. Show Bus Stops\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        switch (choice) {
            case 1:
                showBuses();
                break;

            case 2: {
                int start, end;
                showStops();
                printf("Enter start stop number: ");
                scanf("%d", &start);
                printf("Enter end stop number: ");
                scanf("%d", &end);

                if (start >= 0 && start < N && end >= 0 && end < N) {
                    dijkstra(start, end);
                } else {
                    printf("Invalid input!\n");
                }
                break;
            }

            case 3:
                showStops();
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
