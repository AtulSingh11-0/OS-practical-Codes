#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
* processes -> number of processes
* waiting time -> The time spent by a process waiting in the ready queue
* tAt -> The time since the process entered into ready queue
* totalWaitingTime -> adding the waiting time for all the processes
* avgWaitingTime -> finding the avg waiting time a process needed to spent
* exe[] -> execution time/ burst time of each process
*/

int main (void) {
  
  // variable declaration
  int processes, waitingTime, tAt, totalWaitingTime;
  float avgWaitingTime;
  // variable initialization
  waitingTime = tAt = totalWaitingTime = avgWaitingTime = 0;

  // inputting the number of processes
  printf("Input Number of processes > ");
  scanf("%d", &processes);
  // creating an array based on the number of process
  int exe[processes];

  // inputting the execution time for each process
  for(int i = 0; i < processes; i++) {
    printf("Enter exe time for Process %d > ",i+1);
    scanf("%d", &exe[i]);
  }

  // printing the respective process IDs and Burst time
  printf("\nPID\t\t\tBurst Time\n");
  for(int i = 0; i < processes; i++) {
    printf("P%d\t\t\t%d\n", i+1, exe[i]);
  }
  
  /*
  * printing respective process IDs,
  * waiting time,
  * Burst time,
  * and Turn around time
  */
  printf("\nPID\t\tWaiting Time\t\tBurst Time\t\tTurn Around Time\n");
  for(int i = 0; i < processes; i++) {
    tAt = waitingTime + exe[i];
    printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i+1, waitingTime, exe[i], tAt);
    totalWaitingTime += waitingTime; // calculating totalWaiting time
    waitingTime = tAt; 
    /*
    * updating the waiting time with the turn Around time
    * in each and every iteration
    */
  }

  /*
  * calculating the avg waiting time 
  * and also type casted totalWaitingTime to float
  * so as to prevent the logical error of dividing an int/int
  * and hence the result wont be explicitly casted to float
  */
  avgWaitingTime = (float)totalWaitingTime / processes;
  printf("\nTotal Waiting time > %d\n", totalWaitingTime);
  printf("Average Waiting time > %.2f\n", avgWaitingTime);

  return 0;
}