#include<stdio.h>


typedef struct {
    int PID, art, brt, prior;
    int q, ready;
} process_structure;

int limit, count, acting_Process, time, j, y;
process_structure tmp;

int QueueProcess(int input1) {
    if (input1 == 0 || input1 == 1 || input1 == 2 || input1 == 3) {
        return 1;
    } else {
        return 2;
    }
}
void takeInput(){
    printf("Enter Number of Processes:\t");
    scanf("%d", &limit);
}

int main() {
    takeInput();

    process_structure process[limit];
    for (count = 0; count < limit; count++) {
        printf("\nPID:\t");
        scanf("%d", &process[count].PID);
        printf("Arrival Time:\t");
        scanf("%d", &process[count].art);
        printf("Burst Time:\t");
        scanf("%d", &process[count].brt);
        printf("Process Priority:\t");
        scanf("%d", &process[count].prior);
        acting_Process = process[count].prior;
        process[count].q = QueueProcess(acting_Process);
        process[count].ready = 0;
    }
    time = process[0].brt;


    for (y = 0; y < limit; y++) {
        for (count = y; count < limit; count++) {
            if (process[count].art < time) {
                process[count].ready = 1;
            }
        }
        for (count = y; count < limit - 1; count++) {
            for (j = count + 1; j < limit; j++) {
                if (process[count].ready == 1 && process[j].ready == 1) {
                    if (process[count].q == 2 && process[j].q == 1) {
                        tmp = process[count];
                        process[count] = process[j];
                        process[j] = tmp;
                    }
                }
            }
        }


        for (count = y; count < limit - 1; count++) {
            for (j = count + 1; j < limit; j++) {
                if (process[count].ready == 1 && process[j].ready == 1) {
                    if (process[count].q == 1 && process[j].q == 1) {
                        if (process[count].brt > process[j].brt) {
                            tmp = process[count];
                            process[count] = process[j];
                            process[j] = tmp;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].PID, time, time + process[y].brt);
        time = time + process[y].brt;
        for (count = y; count < limit; count++) {
            if (process[count].ready == 1) {
                process[count].ready = 0;
            }
        }
    }
    return 0;
}