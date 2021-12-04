//
// Created by jackjstark on 10/27/2021.
//

#include <iostream>
using namespace std;


void calcWaitTime(int processes[], int n,
                  int burstTime[], int waitTime[], int quantum) {
    int rm_burstTime[n];
    for (int i = 0; i < n; i++)
        rm_burstTime[i] = burstTime[i];
    int t = 0;

    while (1) {
        bool done = true;

        for (int i = 0; i < n; i++) {

            if (rm_burstTime[i] > 0) {
                done = false;

                if (rm_burstTime[i] > quantum) {
                    t += quantum;
                    rm_burstTime[i] -= quantum;
                } else {
                    t = t + rm_burstTime[i];
                    waitTime[i] = t - burstTime[i];
                    rm_burstTime[i] = 0;
                }
            }
        }

        if (done == true)
            break;
    }
}

void calcTRT(int processes[], int n,
             int burstTime[], int waitTime[], int TRT[]) {
    // calculating TRT

    for (int i = 0; i < n; i++)
        TRT[i] = burstTime[i] + waitTime[i];
}

void calcAvgTime(int processes[], int n, int burstTime[],
                 int quantum) {
    int waitTime[n], TRT[n], total_waitTime = 0, total_TRT = 0;

    calcWaitTime(processes, n, burstTime, waitTime, quantum);

    calcTRT(processes, n, burstTime, waitTime, TRT);

    cout << "Processes " << " Burst time "
         << " Wait Time " << " TRT\n";

    for (int i = 0; i < n; i++) {
        total_waitTime = total_waitTime + waitTime[i];
        total_TRT = total_TRT + TRT[i];
        cout << " " << i + 1 << "\t\t" << burstTime[i] << "\t "
             << waitTime[i] << "\t\t " << TRT[i] << endl;
    }
    cout << "Average wait time = "
         << (float) total_waitTime / (float) n;
    cout << "\nAverage TRT = "
         << (float) total_TRT / (float) n;
}
int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {36, 12, 98};
    int quantum = 2;
    calcAvgTime(processes, n, burst_time, quantum);
    return 0;
}

