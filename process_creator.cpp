#include <iostream>
#include <cstdlib>
#include <vector>

#include "process_creator.h"

using namespace std; 

void Process_Creator :: create_process_list(){
    
    for(int i=0; i<20; i++){
        int rand_pid= rand()%10000;
        int rand_arrival_time=rand()%10;
        int rand_burst_time=rand()%10;
        process_list.push_back(Process(rand_pid, rand_arrival_time, rand_burst_time));
    }

    cout << "Process list succesfully created\n";

    return;
}


void Process_Creator :: display_process_list(){
    for(int i=0; i<process_list.size(); i++){
        process_list[i].display_process_data();
    }

    return;
}