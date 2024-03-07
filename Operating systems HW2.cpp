#include <iostream>
#include <vector>
#include <random>

class Process {
private:
    int pid;
    int tickets;

//Private member variables
public:
    Process(int id, int ticketCount) : pid(id), tickets(ticketCount) {}

    int getPID() const {
        return pid;
    }

    int getTickets() const {
        return tickets;
    }

    // Public member variables
};

class Scheduler {
private:
    std::vector<Process> processes;
//Creates vector as a private member variable
public:
    void addProcess(const Process& process) {
        processes.push_back(process); //Process paramter is added into the vector using the pushback method
    }

    void allocateTickets(int pid, int numTickets) {
        for (Process& process : processes) { //Iterates through the vector
            if (process.getPID() == pid) { //Sees if the PID matches the given process ID
                process = Process(pid, process.getTickets() + numTickets); //Updates # of tickets for that process by adding numTickets to its current # of tickets.
                return;
            }
        }
        std::cout << "Process with PID " << pid << " not found." << std::endl; //Prints out an error message if pid isnt found
    }

    int selectWinner() {
        if (processes.empty())
            return -1; // Returns negative 1 if no processes available

        // Calculate total number of tickets
        int totalTickets = 0;
        for (const Process& process : processes) //Iterates each process in the processes vector
            totalTickets += process.getTickets();//Calls the getTickets() method to retrieve # of tickets then accumulates

        // Generate a random winning ticket number
        std::random_device rd; //Object to obtain a random seed for the random number generator.
        std::mt19937 gen(rd()); //Creates mersenne twister generator
        std::uniform_int_distribution<> dis(1, totalTickets); //Uniform distribution created with a range of 1 to total tickets
        int winningTicket = dis(gen); //Random number with the specified range is then generated

        // Iterate through processes to find the winner
        int currentTicketCount = 0;
        for (const Process& process : processes) { //Iterates through the vector
            currentTicketCount += process.getTickets(); //Adds the number of tickets for that process to currentTicketCount
            if (currentTicketCount >= winningTicket)
                return process.getPID();//Process ID of the current process is returned as the winner.
        }

        // This point should never be reached
        return -1;
    }
};

int main() {
    Scheduler scheduler;

    // Add processes
    scheduler.addProcess(Process(1, 3));  // Process with 3 tickets
    scheduler.addProcess(Process(2, 2));  // Process with 2 tickets
    scheduler.addProcess(Process(3, 1));  // Process with 1 ticket

    // Allocate tickets to process with PID 2
    scheduler.allocateTickets(2, 2);

    // Select winner
    int winnerPID = scheduler.selectWinner();
    if (winnerPID != -1)
        std::cout << "Process " << winnerPID << " wins the lottery!" << std::endl;
    else
        std::cerr << "No winner selected. No processes available." << std::endl;

    return 0;
}

