//
// Created by jackj on 9/29/2021.
//
// C++ program implementation Shortest Job first, followed geeks for geeks guide online for pseudo code and text formatting
//ToDo Might be able to make this faster at a later date,
//possible loop unrolling or something else can be done
//
// In order to run the program on a Mac, go the directory where your code is and run the following:
// % g++ -o SJF SJF.cpp
// % ./SJF 

#include <iostream>
using namespace std;
int arr[10][6];

void processSwap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrangeArrival(int num, int arr[][6])
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (arr[j][1] > arr[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    processSwap(&arr[j][k], &arr[j + 1][k]);
                }
            }
        }
    }
}

void completionTime(int num, int arr[][6])
{
    int temp, val;
    arr[0][3] = arr[0][1] + arr[0][2];
    arr[0][5] = arr[0][3] - arr[0][1];
    arr[0][4] = arr[0][5] - arr[0][2];

    for (int i = 1; i < num; i++) {
        temp = arr[i - 1][3];
        int low = arr[i][2];

        for (int j = i; j < num; j++) {
            if (temp >= arr[j][1] && low >= arr[j][2]) {
                low = arr[j][2];
                val = j;
            }
        }
        arr[val][3] = temp + arr[val][2];
        arr[val][5] = arr[val][3] - arr[val][1];
        arr[val][4] = arr[val][5] - arr[val][2];

        for (int k = 0; k < 6; k++) {
            processSwap(&arr[val][k], &arr[i][k]);
        }
    }
}

int main()
{
    int num, temp;

    cout << "Input number of Process: ";
    cin >> num;

    cout << "...Input the process ID...\n";
    for (int i = 0; i < num; i++) {
        cout << "...Process " << i + 1 << "...\n";
        cout << "Input Process Id: ";
        cin >> arr[i][0];
        cout << "Input Arrival Time: ";
        cin >> arr[i][1];
        cout << "Input CPU Time: ";
        cin >> arr[i][2];
    }

    cout << "Before Arrange...\n";
    cout << "Process ID\tArrival Time\tCPU Time\n";
    for (int i = 0; i < num; i++) {
        cout << arr[i][0] << "\t\t" << arr[i][1] << "\t\t"
             << arr[i][2] << "\n";
    }

    arrangeArrival(num, arr);
    completionTime(num, arr);
    cout << "Final Result...\n";
    cout << "Process ID\tArrival Time\tCPU Time\tWaiting "
            "Time\tTurnaround Time\n";
    for (int i = 0; i < num; i++) {
        cout << arr[i][0] << "\t\t" << arr[i][1] << "\t\t"
             << arr[i][2] << "\t\t" << arr[i][4] << "\t\t"
             << arr[i][5] << "\n";
    }
}