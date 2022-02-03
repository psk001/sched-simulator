#include <iostream>
#include <iomanip>
#include "process.hpp"
 
using namespace std;

Process :: Process(){}

Process :: Process(int pid, int arr_time, int burst_time){
    process_id=pid;
    arrival_time=arr_time;
    cpu_burst_time=burst_time;
    completion_time=-1;
    turn_around_time=-1; 
    waiting_time=-1;
    response_time=-1;
}

void Process::display_process_data(){
   
    cout <<  setw(20) << "Process id: " << process_id << endl;
    cout <<  setw(22) << "Arrival time: " << arrival_time << endl;
    cout <<  setw(24) << "CPU burst time: " << cpu_burst_time << endl;
    cout <<  setw(22) << "Waiting time: " << waiting_time << endl;
    cout <<  setw(23) << "Response time: " << response_time << endl;
    cout <<  setw(25) << "turn around time: " << turn_around_time << endl;
    cout <<  setw(25) << "Completion time: " << completion_time << endl;

    cout << "-----------------------------------------\n-----------------------------------------\n";
    return;
}
