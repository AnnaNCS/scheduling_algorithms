// In order to run the program on a Mac, go to the directory where your code is and run the following:
// % g++ -o batch batch.cpp
// % ./batch

// All three programs were put together and eddited by AnnaN on 12/01/2021 in order to create the final comparison table

// Created by jackjstark on 10/30/2021.
// C++ program implementation Shortest Remaining Time
// SRT

#include <bits/stdc++.h>
#include<iostream>
using namespace std;


struct Process {
    int pid;
    int runTime;
    int arrivalTime;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    };

void calcWaitTime(Process proc[], int n, int waitTime[]) {
    
    int returnTime[n];

    for (int i = 0; i < n; i++)
        returnTime[i] = proc[i].runTime;

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
                           proc[shortest].runTime -
                           proc[shortest].arrivalTime;

            if (waitTime[shortest] < 0)
                waitTime[shortest] = 0;
            }
        t++;
        }
    }

void calcTRT(Process proc[], int n, int waitTime[], int TRT[]) {
    
    for (int i = 0; i < n; i++)
        TRT[i] = proc[i].runTime + waitTime[i];
    }

void calcTimeSRT(Process proc[], int n) {
    
    int waitTime[n], TRT[n], total_waitTime = 0,
            total_TRT = 0;

    calcWaitTime(proc, n, waitTime);

    calcTRT(proc, n, waitTime, TRT);

    cout << "\nSRT\n";
    cout << "Process ID\tRunning Time\tWaiting "
            "Time\tTurnaround Time\n";

    for (int i = 0; i < n; i++) {
        total_waitTime = total_waitTime + waitTime[i];
        total_TRT = total_TRT + TRT[i];
        
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].runTime << "\t\t " << waitTime[i]
             << "\t\t " << TRT[i] << endl;
        }  

    cout << "\nAverage waiting time = "
         << (float)total_waitTime / (float)n;
    cout << "\nAverage turnaround time = "
         << (float)total_TRT / (float)n
         << "\n"
         << "\n";
    }


// Created by AnnaN on 09/30/2021.
// C++ program implementation First In First Out, followed geeks for geeks guide online for pseudo code 
// FIFO

void findWaitingTime(Process proc[], int nn, int wt[]) {

    wt[0] = 0;
    for (int i = 1; i < nn ; i++ )
        wt[i] =  proc[i-1].arrivalTime + wt[i-1] + proc[i-1].runTime - proc[i].arrivalTime;
    for (int i = 1; i < nn ; i++ )
        if (wt[i] < 0) {
            wt[i] = 0; }
    }

void findTurnAroundTime(Process proc[], int nn, int turnT[], int wt[]) {   

    turnT[0] = proc[0].runTime;
    
    for (int  i = 1; i < nn ; i++)
        turnT[i] = proc[i].runTime + wt[i];
    
    }

void calcTimeFIFO(Process proc[], int nn) {
    
    int turnT[nn]; int wt[nn]; int total_wt = 0; int total_turnT = 0;

    findWaitingTime(proc, nn, wt);
    findTurnAroundTime(proc, nn, turnT, wt);
    
    cout << "\nFIFO\n";
    cout << "Process ID\tRunning Time\tWaiting"
            "Time\tTurnaround Time\n";

    for (int i = 0; i < nn; i++) {
        cout << proc[i].pid << "\t\t"
            << proc[i].runTime << "\t\t" << wt[i] << "\t\t"
            << turnT[i] << "\n";
        }    

    for (int i = 0; i < nn; i++) {
        total_wt += wt[i];
        total_turnT = total_turnT + turnT[i];
        }

    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)nn;
    cout << "\nAverage turnaround time = "
         << (float)total_turnT / (float)nn
         << "\n";
    
    }

// Created by AnnaN on 12/03/2021.
// C++ program implementation Shortest Job first, followed tutorialspoint guide online for pseudo code
// SJF

void calcTimeSJF(Process proc[], int n) {
    
    float avg_turnaround_time, avg_waiting_time, avg_response_time;
    int total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0, total_idle_time = 0;
    
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(proc[i].arrivalTime <= current_time && is_completed[i] == 0) {
                if(proc[i].runTime < mn) {
                    mn = proc[i].runTime;
                    idx = i;
                    }
                if(proc[i].runTime == mn) {
                    if(proc[i].arrivalTime < proc[idx].arrivalTime) {
                        mn = proc[i].runTime;
                        idx = i;
                        }
                    }
                }
            }

        if(idx != -1) {
            proc[idx].start_time = current_time;
            proc[idx].completion_time = proc[idx].start_time + proc[idx].runTime;
            proc[idx].turnaround_time = proc[idx].completion_time - proc[idx].arrivalTime;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].runTime;
            proc[idx].response_time = proc[idx].start_time - proc[idx].arrivalTime;
            
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
            total_response_time += proc[idx].response_time;
            total_idle_time += proc[idx].start_time - prev;

            is_completed[idx] = 1;
            completed++;
            current_time = proc[idx].completion_time;
            prev = current_time;
        }
        else {
            current_time++;
        }
        
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time, proc[i].arrivalTime);
        max_completion_time = max(max_completion_time, proc[i].completion_time);
    }

    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    
    cout << "\nSJF\n";
    cout << "Process ID\tRunning Time\tWaiting "
            "Time\tTurnaround Time\n";

    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t\t"
            << proc[i].runTime << "\t\t" << proc[i].waiting_time << "\t\t"
            << proc[i].turnaround_time << "\n";
        } 
      
    cout << "\nAverage waiting time = "
         << avg_waiting_time;
    cout << "\nAverage turnaround time = "
         << avg_turnaround_time
         << "\n";

    } 
    


int main() {

    // process id, run time, arrival time
    Process proc[] = { { 1, 3, 0}, { 2, 6, 2}, { 3, 4, 4}, { 4, 5, 6}, { 5, 2, 8} };
    
    int nn = sizeof(proc) / sizeof(proc[0]);

    // FIFO
    
    
    calcTimeFIFO(proc, nn);

    // SRT
    calcTimeSRT(proc, nn);

    // SJF
    calcTimeSJF(proc, nn);
    
    return 0;
    
    }