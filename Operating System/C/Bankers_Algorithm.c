#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int num_processes, num_resources;
int i,j;
// Function to initialize the need matrix based on maximum and allocation
void calculateNeed() {
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

// Function to check if a process can be executed given available resources
bool canExecute(int process) {
    for (j = 0; j < num_resources; j++) {
        if (need[process][j] > available[j]) {
            return false;
        }
    }
    return true;
}

// Banker's Algorithm to determine safe sequence and state
void bankersAlgorithm() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = { false };
    int safe_sequence[MAX_PROCESSES];
    int num_completed = 0;

    // Initialize work to available resources
    for ( j = 0; j < num_resources; j++) {
        work[j] = available[j];
    }

    while (num_completed < num_processes) {
        bool found = false;

        // Try to find a process that can be executed
        for (i = 0; i < num_processes; i++) {
            if (!finish[i] && canExecute(i)) {
                // Execute process i
                finish[i] = true;
                safe_sequence[num_completed] = i;
                num_completed++;

                // Release allocated resources
                for (j = 0; j < num_resources; j++) {
                    work[j] += allocation[i][j];
                }

                found = true;
            }
        }

        if (!found) {
            printf("System is in an unsafe state.\n");
            return;
        }
    }

    // If all processes are executed safely, print safe sequence and state
    printf("System is in a safe state.\nSafe Sequence: ");
    for ( i = 0; i < num_processes; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter available resources: ");
    for (j = 0; j < num_resources; j++) {
        scanf("%d", &available[j]);
    }

    printf("Enter maximum demand of each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter allocation of each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate need matrix
    calculateNeed();

    // Execute Banker's Algorithm to check for safe state and get safe sequence
    bankersAlgorithm();

    return 0;
}

