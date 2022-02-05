#include <iostream>
#include <iomanip>
#include <fstream>
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

int Process::get_process_id(){
    return process_id;
}

int Process::get_arrival_time(){
    return arrival_time;
}

int Process::get_burst_time(){
    return cpu_burst_time;
}

int Process::get_waiting_time(){
    return waiting_time;
}

int Process::get_response_time(){
    return response_time;
}

int Process::get_turn_around_time(){
    return turn_around_time;
}

int Process::get_completion_time(){
    return completion_time;
}

void Process:: set_burst_time(int time){
    cpu_burst_time=time;
}

void Process::set_waiting_time(int time){
    waiting_time = time;
}

void Process::set_response_time(int time){
    response_time = time;
}

void Process::set_completion_time(int time){
    completion_time = time;
}

void Process::set_turn_around_time(int time){
    turn_around_time = time;
}

void Process::update(int ctime, int rtime){
    completion_time = ctime;
    turn_around_time = completion_time - arrival_time;
    waiting_time = turn_around_time - cpu_burst_time;
    response_time = rtime - arrival_time;
}



void Process::display_process_data(){
   
    cout <<  setw(20) << "Process id: " << process_id << endl;
    cout <<  setw(22) << "Arrival time: " << arrival_time << endl;
    cout <<  setw(24) << "CPU burst time: " << cpu_burst_time << endl;
    cout <<  setw(22) << "Waiting time: " << waiting_time << endl;
    cout <<  setw(23) << "Response time: " << response_time << endl;
    cout <<  setw(25) << "Turn around time: " << turn_around_time << endl;
    cout <<  setw(25) << "Completion time: " << completion_time << endl;

    cout << "-----------------------------------------\n-----------------------------------------\n";
    return;
}
