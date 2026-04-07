#include <stdio.h>
#include "graph.h"

// Seat data
int seats[N] = {10, 6, 8, 3, 5, 2, 7, 4, 9};

void displaySeats() {
    printf("\n🪑 Seat Availability:\n");
    for (int i = 0; i < N; i++) {
        printf("%s → %d seats\n", nodes[i], seats[i]);
    }
}

void waitingTime() {
    printf("\n⏱ Waiting Time:\n");
    for (int i = 0; i < N; i++) {
        int time = 10 - seats[i];
        printf("%s → %d mins\n", nodes[i], time);
    }
}
