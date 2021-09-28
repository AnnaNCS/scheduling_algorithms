
# Scheduling Algorithms 

Project: Overview of the main operating system scheduling algorithms and their comparisson. The next step will be the inmplementation of several algorithms in C. 

The main goal of this project was to:

* Overview, Implement, and Compaire the algorithms 
* The comparisson of the algorithms will display cases in which each algorithm is at its best efficiency. Metrics such as time and speed will be compaired. 


# Priority Algorithms 

Long-term scheduling:
	Scheduling to enter the ready state from the new processes or the suspended list 

Short-term scheduling
	Scheduling of processees to move from ready state to run on the CPU, as well as movement between running, ready, or blocked states. 

Non-preemptive scheduling algorithm
	Allows a process to run until blocked on a resource or terminated
	
	t1	   t2	      t3	 t4
	|__________|__________|
			      |__________|
			      
	p1 starts at t1 and ends at t3
	p2 should start at t2, waits untils p1 ends, and starts at t3 and ends at t4

Preemptive scheduling algorithm
	May switch betweeen processes
	
	t1	   t2	      t3	 t4
	|__________|          |__________|
		   |__________|
		   
	p1 starts at t1 and is interrupted by p2, which starts at t2 
	p2 finsihes at t3 so that p1 ends at t4

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
