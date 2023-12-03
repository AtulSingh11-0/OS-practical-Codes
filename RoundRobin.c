#include <stdio.h>

// Function to implement Round Robin scheduling
void roundRobin(int n, int bt[], int quantum){
  int wt[n], tat[n];
  int total_wt = 0, total_tat = 0;

  // Calculate waiting time for each process
  int remaining_time[n];
  for (int i = 0; i < n; i++)
    remaining_time[i] = bt[i];

  int t = 0; // Current time
  while (1){
    int done = 1;

    // Traverse all processes
    for (int i = 0; i < n; i++){
      // If remaining time for a process is greater than 0, process it
      if (remaining_time[i] > 0){
        done = 0; // There is a pending process

        // Decrease remaining time by the quantum
        if (remaining_time[i] > quantum){
          t += quantum;
          remaining_time[i] -= quantum;
        }else{
          // If remaining time is less than or equal to quantum, finish the process
          t += remaining_time[i];
          wt[i] = t - bt[i];
          remaining_time[i] = 0;
        }
      }
    }

    // If all processes are done, break out of the loop
    if (done)
      break;
  }

  // Calculate turnaround time and total waiting time
  for (int i = 0; i < n; i++){
    tat[i] = bt[i] + wt[i];
    total_wt += wt[i];
    total_tat += tat[i];
  }

  // Print results
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

  for (int i = 0; i < n; i++){
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }

  printf("Average Waiting Time: %.2f\n", (float)total_wt / (float)n);
  printf("Average Turnaround Time: %.2f\n", (float)total_tat / (float)n);
}

int main(void){
  // inputting the number of processes
  int processes, timeQuantum;
  printf("Enter the number of processes > ");
  scanf("%d", &processes);

  // creating a Process array P depending on the number of processes
  int p[processes];

  // inputting the burst time for each process
  for (int i = 0; i < processes; i++){
    printf("Enter Burst time for Process %d > ", i + 1);
    scanf("%d", &p[i]);
  }

  printf("Enter time quantum > ");
  scanf("%d", &timeQuantum);

  roundRobin(processes, p, timeQuantum);

  return 0;
}
