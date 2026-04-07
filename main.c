#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"
#include "bus.h"

int main() {
    int choice, src, dest;

    while (1) {
        printf("\n===== SMART BUS TRACKING SYSTEM =====\n");
        printf("1. Show Bus Stops\n");
        printf("2. Show Seat Availability\n");
        printf("3. Find Nearest Stop\n");
        printf("4. Find Best Route\n");
        printf("5. Show Waiting Time\n");
        printf("6. Exit\n");

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
            printf("Enter your location index: ");
            scanf("%d", &src);
            findNearest(src);
            break;

        case 4:
            printf("Enter Source: ");
            scanf("%d", &src);
            printf("Enter Destination: ");
            scanf("%d", &dest);
            dijkstra(src, dest);
            break;

        case 5:
            waitingTime();
            break;

        case 6:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
