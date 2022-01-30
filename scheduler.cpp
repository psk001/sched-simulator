#include <iostream>
#include <string>
#include "scheduler.hpp"

using namespace std;

Scheduler::Scheduler(){
    ProcessCreator newProcess;
    newProcess.create_process_list();
}

void Scheduler::first_come_first_serve(){
    
    return;
}

void Scheduler::round_robin(){
    cout << "Round Robin algorithm called \n";
    return;
}

void Scheduler::shortest_time_first(){
    cout << "Shortest time first algorithm \n";
    return;
}


bool Scheduler::priorityFCFS(Process A, Process B){
    return A.arrival_time > B.arrival_time;
}