

#include <stdio.h>
#include <stdlib.h>

#define COUNT 3

int main(int argc, char *argv[]) {
    int remaining[COUNT] = {5, 3, 1};
    int quantum = 2;
    int time = 0;
    int unfinished = 1;

    // Allow a different time quantum from the command line
    if (argc > 1) {
        quantum = atoi(argv[1]);

        if (quantum <= 0) {
            fprintf(stderr, "Quantum must be a positive integer.\n");
            return 1;
        }
    }

    printf("Time quantum: %d ms\n", quantum);
    printf("All processes arrive at t=0.\n\n");

    while (unfinished) {
        unfinished = 0;

        // Visit each process in order
        for (int i = 0; i < COUNT; i++) {
            if (remaining[i] > 0) {
                int run;

                // A process cannot run longer than its quantum
                if (remaining[i] < quantum) {
                    run = remaining[i];
                } else {
                    run = quantum;
                }

                printf("%2d-%2d ms: P%d runs",
                       time, time + run, i + 1);

                time += run;
                remaining[i] -= run;

                printf(" (remaining: %d ms)\n", remaining[i]);

                // Another pass is needed if work remains
                if (remaining[i] > 0) {
                    unfinished = 1;
                }
            }
        }
    }

    printf("\nAll processes complete at t=%d ms.\n", time);

    return 0;
}
