//
// Created by jackj on 10/30/2021.
//
// Shortest Remaining Time (aka Premeptive Shortage Job First)

#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int arrivalTime;
};


void calcWaitTime(Process proc[], int n,
                     int waitTime[])
{
    int returnTime[n];

    for (int i = 0; i < n; i++)
        returnTime[i] = proc[i].burstTime;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, fin_Time;
    bool check = false;


    while (complete != n) {

        for (int j = 0; j < n; j++) {
            if ((proc[j].arrivalTime <= t) &&
                (returnTime[j] < minm) && returnTime[j] > 0) {
                minm = returnTime[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }
        returnTime[shortest]--;

        minm = returnTime[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (returnTime[shortest] == 0) {

            complete++;
            check = false;

            fin_Time = t + 1;

            waitTime[shortest] = fin_Time -
                           proc[shortest].burstTime -
                           proc[shortest].arrivalTime;

            if (waitTime[shortest] < 0)
                waitTime[shortest] = 0;
        }
        t++;
    }
}

void calcTRT(Process proc[], int n,
                        int waitTime[], int TRT[])
{
    for (int i = 0; i < n; i++)
        TRT[i] = proc[i].burstTime + waitTime[i];
}

void calcAvgTime(Process proc[], int n)
{
    int waitTime[n], TRT[n], total_waitTime = 0,
            total_TRT = 0;


    calcWaitTime(proc, n, waitTime);


    calcTRT(proc, n, waitTime, TRT);


    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_waitTime = total_waitTime + waitTime[i];
        total_TRT = total_TRT + TRT[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].burstTime << "\t\t " << waitTime[i]
             << "\t\t " << TRT[i] << endl;
    }

    cout << "\nAverage waiting time = "
         << (float)total_waitTime / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_TRT / (float)n;
}


int main()
{
    Process proc[] = { { 1, 6, 1 }, { 2, 8, 1 },
                       { 3, 7, 2 }, { 4, 3, 3 } };
    int n = sizeof(proc) / sizeof(proc[0]);

    calcAvgTime(proc, n);
    return 0;
}