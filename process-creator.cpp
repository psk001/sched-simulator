#include <iostream>
#include <cstdlib>
#include "process-creator.hpp"

using namespace std; 

ProcessCreator::ProcessCreator(){}

void ProcessCreator::create_process_list(){
    process_list.clear();

    for(int i=0; i<20; i++){
        int rand_pid= rand()%10000;
        int rand_arrival_time=rand()%100;
        int rand_burst_time=rand()%10;
        process_list.push_back(Process(rand_pid, rand_arrival_time, rand_burst_time));
    }

    cout << "\n------------Process list succesfully created-----------\n";

    return;
}  

Process ProcessCreator::create_new_process(){
    int rand_pid= rand()%10000;
    int rand_arrival_time=rand()%10;
    int rand_burst_time=rand()%10;

    Process tempProcess(rand_pid, rand_arrival_time, rand_burst_time);

    return tempProcess;
}

void ProcessCreator::display_process_list(){
    for(int i=0; i<process_list.size(); i++){
        cout << "Process Number: " << i+1 << endl;
        process_list[i].display_process_data();
        cout << endl;
    }

    return;
}