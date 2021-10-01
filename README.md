
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
* Schedules processes strictly according to the process arrival time. The earlier the arrival, the higher the priority. The advantage of FIFO scheduling is it means the cpu will always be working on the task pushed first. This makes sure the first scheduled task is the first one to complete. If you know the order of your program this can be quite useful as you can potentially use this to optimize getting what you need done most urgently first.
</n>

	t1	   t2	      t3	 t4	   t5	      t6	 t7
	|__________|__________|__________|
			      |..........|_________|__________|
			      		 |.........|..........|___________|
	
	.. WAIT TIME 
	__ CPU TIME
	p1 arrives at t1, is the first one to arrive, finishes at t4 
	p2 arrives at t3, is the next one to arrive, waits for p1 and starts at t4, and finishes at t6
	p3 arrives at t4, is the next one to arrive, waist for p2 and starts at t6, and finishes at t7
	
SJF (Shortest Job First) algorithm, also known as SJN (Shortest Job Next)
* Schedules processes according to the total CPU time requirements. The shorter the required CPU time, the higher the priority. The advantage of SJF scheduling is it means the lightest tasks are handled quickly which can leave more cpu resources for heavier tasks. Though it is important to note that if you're not careful it can result in long tasks never getting cpu time they need if you have a ton of shorter tasks.
</n>
	
	t1	   t2	      t3	 t4	   t5	      t6	 t7
	|__________|__________|__________|
			      |..........|.........|__________|___________|
			      		 |_________|
	
	.. WAIT TIME 
	__ CPU TIME
	p1 arrives at t1, is the first one, finishes at t4 
	p2 arrives at t3, has CPU time of 2
	p3 arrives at t4, has CPU time of 1
	=> p3 start first at t4 and finishes at t5 
	   p2 is then able to start at t5 and finishes at t7 


SRT (Shortest Remaining Time) algorithm 
* Schedules processes according to the remaining CPU time needed to complete the work. The shorter the remaining CPU time, the higher the priority. This algorithm is very similar to the aforementioned SFJ scheduling. The difference is this is the preemptive version of it. This means tasks can interrupt other tasks in the event that one requires less cpu time than an already queued task (ie preempt that task). This has the same issues as SJF where longer tasks can end up never getting enough time.
</n>

	t1	   t2	      t3	 t4	   t5	      t6	 t7	    t8	       t9	  t10	     t11
	|__________|__________|..........|.........|..........|..........|__________|__________|__________|__________|
			      |__________|.........|__________|__________|
			      		 |_________|
					 
	.. WAIT TIME 
	__ CPU TIME
	p1 starts at t1, p2 arrives at t3, p3 arrives at t4, 
	at t3, p1 has 4 CPU time left and p2 only 3 	       => p2 starts 
	at t4, p1 has 4 CPU time left, p2 has 2 and p3 has 1   => p3 starts and ends at t5
	at t5, p1 has 4 CPU time left and p2 only 2 	       => p2 continues and ends at t7 
	and at t7 p1 is the only left and continues and ends at t11
	What if for two prosesses that are ready to continue have same CPU time left, which one finishes first? 


# Interactive Processes Scheduling

Time Quantum
* A time unit during which a process is allowed to use the CPU. Usually 10 ~ 100 milliseconds.

Round-robin (RR) algorithm 
* Single queue of processes where the position of a process is solely determined by its position within the queue. The process at the head that used its time, Q, is moved to the back of the queue.

</n>
	
	  t1	      t2	 t3	...   	      tn-1        tn
	p1 |__________|          
	p2            |__________|
	.		
	.			
	pn  					       |__________|
		   
	


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



