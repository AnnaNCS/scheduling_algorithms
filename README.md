
# Scheduling Algorithms 

Project: Overview of the main operating system scheduling algorithms and their comparisson. The next step will be the inmplementation of several algorithms in C. 

The main goal of this project was to:

* Overview, Implement, and Compare the algorithms 
* The comparisson of the algorithms will display cases in which each algorithm is at its best efficiency. Metrics such as time and speed will be compaired. 


# Priority Algorithms 

Long-term scheduling:
* Scheduling to enter the ready state from the new processes or the suspended list

Short-term scheduling
* Scheduling of processees to move from ready state to run on the CPU, as well as movement between running, ready, or blocked states 

Non-preemptive scheduling algorithm
* Allows a process to run until blocked on a resource or terminated
</n>

	t1	   t2	      t3	 t4
	|__________|__________|
			      |__________|
			      
	p1 starts at t1 and ends at t3
	p2 should start at t2, waits untils p1 ends, and starts at t3 and ends at t4

Preemptive scheduling algorithm
* May switch betweeen processes
</n>
	
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

Time Quantum
* A time unit during which a process is allowed to use the CPU. Usually 10 ~ 100 milliseconds.

Round-robin (RR) algorithm 
* Single queue of processes where the position of a process is solely determined by its position within the queue. The process at the head that used its time, Q, is moved to the back of the queue.

</n>
	
	  t1	      t2	 t3	...   	 tn-1        tn
	p1 |__________|          
	p2            |__________|
	.
	.
	.
	pn 					  |__________|
		   
	


Multilevel (ML) scheduling 
* Consists of multiple queues, each given a priority level. The process at each level is executed using the Round-robin algorithm.
When a process enters a higher priority level, process execution is interrupted and is put to the back of the queue.

</n>
	
	     			    CPU
	N	__________[b]_____|_____|
	N-1	__________________|	|
	N-2	__________[c]_____| [a] |
	.			  |	|
	.			  |	|
	1	__________________|_____|
	
	During execution of [a], its process would be interrupted because [b] arrived at a higher priority level.

Multilevel feedback (MLF) algorithm
* MLF is a variation of ML, but it addresses problems of starvation and fairness by using different time quantum at each level and changing the priority of every process dynamically. MLF automatically favors short-running processes while processes with long running times gradually migrate to lower levels


# Real Time Processes Scheduling  

Rate monotonic (RM) algorithm

Earliest deadline first (EDF) algorithm
* EDF prioritizes processes whose deadline is the closest first. The priorities are assigned and changed dynamically. EDF is very efficient as compared to other scheduling algorithms in real-time systems. It can make the CPU utilization to about 100% while still guaranteeing the deadlines of all the tasks.



