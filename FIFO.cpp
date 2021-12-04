//
// Created by Anna Nefedenkova on 09/30/2021.
//
// C++ program implementation First In First Out, followed geeks for geeks guide online for pseudo code 
// 
// In order to run the program on a Mac, go the directory where your code is and run the following:
// % g++ -o FIFO FIFO.cpp
// % ./FIFO 

#include<iostream>
using namespace std;
int processes[10][3];
int wt[10], turnT[10];

void findWaitingTime(int processes[][3], int n)
{
    //the waiting time: the previous process' arrival time + CPU time
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
        wt[i] =  (processes[i-1][1] + processes[i-1][2]) - processes[i][1];
    for (int i = 1; i < n ; i++ )
        if (wt[i] <= 0) {
            wt[i] = 0; }
}

void findTurnAroundTime( int processes[][3], int n)
{   
    // the turn around time: 
    turnT[0] = processes[0][2];
    for (int  i = 1; i < n ; i++)
        turnT[i] = processes[i][2] + wt[i];
}

void makeTable( int processes[][3], int n)
{
    findWaitingTime(processes, n);
    findTurnAroundTime(processes, n);
}
 
int main()
{
    int n; 
    float total_wt, total_turnT;

    cout << "Input number of Process: ";
    cin >> n;

    cout << "...Input the process ID...\n";
    for (int i = 0; i < n; i++) {
        cout << "...Process " << i + 1 << "...\n";
        cout << "Input Process Id: ";
        cin >> processes[i][0];
        cout << "Input Arrival Time: ";
        cin >> processes[i][1];
        cout << "Input CPU Time: ";
        cin >> processes[i][2];
    }

    makeTable(processes, n);

    cout << "Result...\n";
    cout << "Process ID\tArrival Time\tCPU Time\tWaiting "
            "Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i][0] << "\t\t" << processes[i][1] << "\t\t"
            << processes[i][2] << "\t\t" << wt[i] << "\t\t"
            << turnT[i] << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_turnT = total_turnT + turnT[i];
    }

    cout << "Average waiting time = "
         << (float)total_wt / n;
    cout << "\nAverage turn around time = "
         << (float)total_turnT / n;

    return 0;
}