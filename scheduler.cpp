#include <iostream>
#include <string>

#include "scheduler.hpp"
#include "comparator.hpp"

using namespace std;

Scheduler::Scheduler(){}

Scheduler::Scheduler(int sim_time){
    simulation_time=sim_time;
}

void Scheduler::first_come_first_serve(){
    ProcessCreator fcfsProcessCreator;
    vector<Process> result;
    int processCount=0;

    fcfsProcessCreator.create_process_list(); 

    priority_queue <Process, vector<Process>, FCFSComparator> fcfs_queue;
    
    for(auto i: fcfsProcessCreator.process_list){
            fcfs_queue.push(i);
    }


    Process temp=fcfs_queue.top(); 
    temp.waiting_time=0;
    temp.completion_time=temp.arrival_time+temp.waiting_time+temp.cpu_burst_time;
    temp.turn_around_time=temp.waiting_time+temp.cpu_burst_time;
    temp.response_time=0;

    result.push_back(temp);

    fcfs_queue.pop();

    for(int i=0; i<20; i++){

        Process prevProcess=result[processCount];

        temp=fcfs_queue.top();

        temp.waiting_time =  max(0, prevProcess.completion_time-temp.arrival_time); //temp.arrival_time- temp.cpu_burst_time+prevProcess.waiting_time;
        temp.turn_around_time = temp.waiting_time + temp.cpu_burst_time;
        temp.completion_time = temp.arrival_time+temp.turn_around_time;
        temp.response_time = min(prevProcess.completion_time, temp.arrival_time);
        temp.turn_around_time = temp.cpu_burst_time + temp.waiting_time;

        result.push_back(temp);

        fcfs_queue.pop();

        // if(fcfs_queue.size()==0){
        //     fcfsProcessCreator.create_process_list();
            
        //     for(auto i: fcfsProcessCreator.process_list){
        //         fcfs_queue.push(i);
        //     }
        // }

        processCount++;
    }

    cout << "After completion of process: \n";

    for(auto i: result)
        i.display_process_data();

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
