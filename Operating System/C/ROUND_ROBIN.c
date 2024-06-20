#include <stdio.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

void roundRobin(int arrival[], int burst[], int n);

int main() {
    int arrival[MAX_PROCESSES];
    int burst[MAX_PROCESSES], n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the Arrival time & Burst time of processes: \n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Burst time: ");
        scanf("%d", &burst[i]);
    }

    roundRobin(arrival, burst, n);

    return 0;
}

void roundRobin(int arrival[], int burst[], int n) {
    int remaining_burst[MAX_PROCESSES];
    int completion[MAX_PROCESSES], turnaround[MAX_PROCESSES], waiting[MAX_PROCESSES];
    int time = 0; // Current time
    int quantum = TIME_QUANTUM;
    float total_waiting = 0, total_turnaround = 0;

    // Initialize remaining burst time
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = burst[i];
    }

    while (1) {
        int done = 1; // Flag to check if all processes are done

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time) {
                if (remaining_burst[i] > 0) {
                    done = 0; // There is still at least one process remaining
                    if (remaining_burst[i] > quantum) {
                        // Execute for time quantum
                        time += quantum;
                        remaining_burst[i] -= quantum;
                    } else {
                        // Last execution for this process
                        time += remaining_burst[i];
                        remaining_burst[i] = 0;
                        completion[i] = time;
                        turnaround[i] = completion[i] - arrival[i];
                        waiting[i] = turnaround[i] - burst[i];
                        total_waiting += waiting[i];
                        total_turnaround += turnaround[i];
                    }
                }
            }
        }

        if (done == 1) {
            break; // All processes are done
        }
    }

    float avg_waiting = total_waiting / n;
    float avg_turnaround = total_turnaround / n;

    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}

