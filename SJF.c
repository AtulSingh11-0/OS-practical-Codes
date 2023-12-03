#include<stdio.h>

typedef struct SJF{
  int id; // id of each Process
  int burstTime; // burst time of each Process
  int waitingTime; // waiting time of each Process
  int turnAroundTime; // turn around time of each Process
} Process;

// funciton declarations
void bubbleSort(Process[], int); // to sort the processes in ascending order
void swap(Process *, Process *); // function to perfrom swapping
void sjfScheduling(Process[], int); // function which contains the main logic for SJF scheduling

int main(void) {

  // inputting the number of processes
  int processes;
  printf("Enter the number of Processes > ");
  scanf("%d", &processes);

  // creating a Process array P depending on the number of processes
  Process p[processes];

  // inputting the burst time for each process
  for(int i = 0; i < processes; i++) {
    printf("Enter burst time for Process %d > ", i+1);
    scanf("%d", &p[i].burstTime);
    p[i].id = i+1; // providing the id manually to each process
  }
  
  /*
  * calling the SJF scheduling function 
  * passing the Process array p to it
  * and also the number of processes
  */
  sjfScheduling(p, processes); 

  return 0;
}

// nothing just performing basic bubble sort
void bubbleSort(Process p[], int n) {
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      /*
      * sorting the processes according to their burst time
      * it will be sorted in ascending order
      * i.e. the smaller the burst time will be
      * the first one it will be to get Executed
      */
      if(p[i].burstTime > p[i+1].burstTime) { 
        swap(&p[i], &p[i+1]); // calling the swap function
      }
    }
  }
}

// this function contains the basic logic needed to perform the SJF scheduling
void sjfScheduling(Process p[], int n) {

  // 1stly i am sorting the Process array by calling the bubbleSort function
  bubbleSort(p, n);

  // declaring and initializing the needed variables
  int totalWaitingTime = 0;
  float avgWaitingTime = 0;

  // displaying the headers
  printf("\nPID\t\tWaiting Time\t\tBurst Time\t\tTurn Around Time\n");

  // setting the waiting time of the 1st process to 0
  p[0].waitingTime = 0;
  for(int i = 0; i < n; i++) {

    // calculating the turn around time of the ith Process
    p[i].turnAroundTime = p[i].burstTime + p[i].waitingTime;

    /*
    * printing respective process IDs,
    * waiting time,
    * Burst time,
    * and Turn around time
    */
    printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].id, p[i].waitingTime, p[i].burstTime, p[i].turnAroundTime);
    
    // calculating the totalWaitingTime
    totalWaitingTime += p[i].waitingTime;

    // setting the waiting time for the i+1th process to the current turn around time
    p[i+1].waitingTime = p[i].turnAroundTime;
  }

  /*
  * calculating the avg waiting time 
  * and also type casted totalWaitingTime to float
  * so as to prevent the logical error of dividing an int/int
  * and hence the result wont be explicitly casted to float
  */
  avgWaitingTime = (float)totalWaitingTime / n;
  printf("\nTotal Waiting time > %d\n", totalWaitingTime);
  printf("Average Waiting time > %.2f\n", avgWaitingTime);
}

/*
* here i have created two pointer variables of type Process
* since Process is an ADT (Abstract Data Type)
* i cannot use normal integer or any such data type over here to perform swapping
* u can also skip doing it using this swap function by writing the below code 
* where u have called the swap function in the bubble sort scope
*
* Code :
* Process temp = p[i];
* p[i+1] = p[i];
* p[i] = temp;
*
*/
void swap(Process *a, Process *b) {
  Process temp = *a;
  *a = *b;
  *b = temp;
}