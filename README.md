# HW-2-Operating-systems
# Simple simulation in which processes are assigned lottery tickets, and then gets selected randomly to determine the next process to run.
This project implements a process class that represents each process. With these processes, each process has a unique identifier, several lottery tickets, and other contributing factors. It also implements a Scheduler class that would manage the algorithm for the lottery scheduling. This scheduler has methods that add processes, allocate lottery tickets and selects the next process to run. Lastly it uses a random number generate to simulate this lottery selection process.
# User instructions/Functionality comprehension
Lets see how this code functions and see which process wins the lottery!
* It has private member variables:
  ‘pid’(unique identifier for the process)
  ‘tickets’(# of lottery tickets for the process)

* A constructor is created to initialize ‘pid’ and ‘tickets’
* The public member functions ‘getPID()’ and ‘getTickets()’ are required to retrieve the process ID and the number of tickets
* The scheduler class is then created to manage the scheduling for the lottery.
* It has private member variables
   ‘processes’(a vector in which to store the processes)
* Its public member functions include:
	addProcess - adds a new process to the scheduler,
	allocateTickets- increases the # of tickets for a specified process, and
	selectWInner() - selects a winning process based on lottery tickets at random.

* For the random # generation an function called selectWinner() is created
* This function will start by calculating the total number of tickets
* It will then generate a random winning ticket # by using a mersenne twister generator;
  	Mersenne twister - a well established pseudorandom number generator developed in the 1990s 
* After generating this ticket number it will then go through a loop to iterate and match the processes to the winning number.
* In the main function an instance of the scheduler class is created called ‘scheduler’
Then it adds the processes 
* Tickets are then allocated to a specific process using the allocateTickets() function
* Lastly the selectWinner() function is called and prints out the process ID as the winner of the lottery if there is a winning process selected




## User Warnings
* If the total number of tickets (totalTickets) is calculated as zero, it would result in a division by zero error when trying to generate a winning ticket number. This could happen if all processes have zero tickets or if there are no processes added to the scheduler.
* The method used to generate random numbers (std::random_device and std::mt19937) is generally reliable from the research I had done. However, if the random device fails or the Mersenne Twister engine is not properly seeded, it could lead to non-random or predictable results.
* One last thing if there are any questions about the functionality of the code, the code itself has a thorough and in-depth explanation from the comments I have put on there.



