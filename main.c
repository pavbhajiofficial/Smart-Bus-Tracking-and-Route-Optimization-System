#include <stdio.h>
#include "graph.h"
#include "processing.h"
#include "bus.h"

int main() {
    int choice, src, dest;

    while (1) {
        printf("\n===== SMART BUS SYSTEM =====\n");
        printf("1. Show Stops\n");
        printf("2. Seat Availability\n");
        printf("3. Bus Lookup (Hash Map)\n");
        printf("4. Nearest Stop\n");
        printf("5. Shortest Route (Dijkstra + Heap)\n");
        printf("6. Minimum Stops (BFS)\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            displayStops();
            break;

        case 2:
            displaySeats();
            break;

        case 3:
            displayBusLookup();
            break;

        case 4:
            printf("Enter source: ");
            scanf("%d", &src);
            findNearest(src);
            break;

        case 5:
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);
            dijkstra(src, dest);
            break;

        case 6:
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);
            bfsShortestStops(src, dest);
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
