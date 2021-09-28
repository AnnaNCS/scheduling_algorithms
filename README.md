
# Scheduling Algorithms 

Project: Overview of the main operating system scheduling algorithms and their comparisson. The next step will be the inmplementation of several algorithms in C. 

The main goal of this project was to:

* Overview, Implement, and Compaire the algorithms 
* The comparisson of the algorithms will display cases in which each algorithm is at its best efficiency. Metrics such as time and speed will be compaired. 


# Priority Algorithms 

Long-term scheduling

Short-term scheduling

Non-preemptive scheduling algorithm

Preemptive scheduling algorithm

# Batch Processes Scheduling

FIFO (First-In-First-Out) algorithm, also known as FCFS (First-Come-First-Served)

SJF (Shortest Job First) algorithm, also known as SJN (Shortest Job Next)

SRT (Shortest Remaining Time) algorithm 

LJT (Longest Job First) algorithm)

LRFT (Longest Remaining Time First) algorithm


# Interactive Processes Scheduling

Before going over the algorithms, it is crucial to 

Round-robin (RR) algorithm 

	○ priority determined solely by a process's position within the queue
	○ process at head of queue has highest priority and is allowed to run for Q time units
	○ when Q ends, process is moved to the tail of the queue and the next process now at the head of queue is allowed to run for Q time units
![image](https://user-images.githubusercontent.com/44881759/135003058-9c1fb0a2-a57b-4713-a68a-f55cdd67a937.png)


Multilevel (ML) scheduling 

Multilevel feedback (MLF) algorithm

# Real Time Processes Scheduling  

Rate monotonic (RM) algorithm

Earliest deadline first (EDF) algorithm
