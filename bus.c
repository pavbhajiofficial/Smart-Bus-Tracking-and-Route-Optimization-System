#include <stdio.h>
#include "graph.h"

#define BUS_COUNT 5

int seats[N] = {10,6,8,3,5,2,7,4,9};

// Hash map simulation (busID → location & seats)
int busLocation[BUS_COUNT] = {0, 2, 4, 6, 8};
int busSeats[BUS_COUNT] = {10, 5, 8, 6, 7};

void displaySeats() {
    printf("\nSeat Availability at Stops:\n");
    for (int i = 0; i < N; i++) {
        printf("%s → %d seats\n", nodes[i], seats[i]);
    }
}

void displayBusLookup() {
    printf("\nBus Lookup (Hash Map):\n");
    for (int i = 0; i < BUS_COUNT; i++) {
        printf("Bus %d at %s → %d seats\n",
               i, nodes[busLocation[i]], busSeats[i]);
    }
}
