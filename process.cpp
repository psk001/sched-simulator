#include <iostream>
#include "process.h"
 
using namespace std;

Process :: Process(){}

Process :: Process(int pid, int arrival_time, int burst_time){
    process_id=pid;
    arrival_time=arrival_time;
    cpu_burst_time=burst_time;
    completion_time=-1;
    turn_around_time=-1;
    waiting_time=-1;
    response_time=-1;
}

void Process::display_process_data(){
    cout << "Process id: " << process_id << endl;
    cout << "Arrival time: " << arrival_time << endl;
    cout << "CPU burst time: " << cpu_burst_time << endl;
    cout << "Completion time: " << completion_time << endl;
    cout << "Waiting time: " << waiting_time << endl;
    cout << "Response time: " << response_time << endl;

    return;
}
