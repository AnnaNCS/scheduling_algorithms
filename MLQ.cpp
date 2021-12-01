//
// Created by jackj on 11/30/2021.
//


#include<stdio.h>

int PID[20], burstTime[20], su[20], waitTime[20], turnAroundTime[20], i, k, n, temp;
float waitTime_Average, turnAroundTime_Average;

void endResult(float waitTime_Average, float turnAroundTime_Average) {
    printf("\nProcess\t\t Process Type \tBurst time\tWait Time\tTRT");
    for (i = 0; i < n; i++)
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ", PID[i], su[i], burstTime[i], waitTime[i], turnAroundTime[i]);


    printf("\nAverage Waiting Time:   %f", waitTime_Average / n);
    printf("\nAverage Turnaround Time:    %f", turnAroundTime_Average / n);

}

void computeAverage() {
    for (i = 1; i < n; i++) {
        waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
        turnAroundTime[i] = turnAroundTime[i - 1] + burstTime[i];
        waitTime_Average = waitTime_Average + waitTime[i];
        turnAroundTime_Average = turnAroundTime_Average + turnAroundTime[i];
    }
}

void input() {
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        PID[i] = i;
        printf("Enter the Burst Time %d:", i);
        scanf("%d", &burstTime[i]);
        printf("Process Type: System (0) or User Process (1)");
        scanf("%d", &su[i]);
    }

}

void schedule() {

    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (su[i] > su[k]) {
                temp = PID[i];
                PID[i] = PID[k];
                PID[k] = temp;
                temp = burstTime[i];
                burstTime[i] = burstTime[k];
                burstTime[k] = temp;
                temp = su[i];
                su[i] = su[k];
                su[k] = temp;
            }
    waitTime_Average = waitTime[0] = 0;
    turnAroundTime_Average = turnAroundTime[0] = burstTime[0];
}

int main() {
    input();
    schedule();
    computeAverage();
    endResult(waitTime_Average, turnAroundTime_Average);

}


