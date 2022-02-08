#include <iostream>
#include <cstdlib>
#include <fstream>
#include "process-creator.hpp"
#define mx 1e5

using namespace std; 

ProcessCreator::ProcessCreator(){}

void ProcessCreator::create_process_list(){
   // process_list.clear();

    for(int i=0; i<mx; i++){
        int rand_pid= rand()%10000+10000;
        int rand_arrival_time=rand()%100+1;
        int rand_burst_time=rand()%10+1;
        process_list.push_back(Process(rand_pid, rand_arrival_time, rand_burst_time));
    }
 
    cout << "\n------------Process list succesfully created-----------\n";

    return;
}  

vector<Process> ProcessCreator::get_process_list(){
    return process_list;
}

void ProcessCreator::update_ready_queue(vector<Process> u_ready_queue){
    process_list=u_ready_queue;
}

void ProcessCreator::write_to_file(){
    ofstream pfile;
    pfile.open("output.txt");

    for(int i=0; i<process_list.size(); i++)
        if(process_list[i].get_completion_time()==0){
            pfile << "  " << process_list[i].get_process_id() << " \t" << process_list[i].get_arrival_time() << " \t" << process_list[i].get_burst_time();
            pfile << " \t"  << process_list[i].get_waiting_time() << " \t" << process_list[i].get_response_time()<< " \t\t" << process_list[i].get_turn_around_time();
            pfile << " \t" << process_list[i].get_completion_time() << "\n";    
        }
    }

   // pfile.close();
    return;
}


void ProcessCreator::display_process_list(){
    for(int i=0; i<process_list.size(); i++){
        cout << "Process Number: " << i+1 << endl;
        process_list[i].display_process_data();
        cout << endl;
    }

    return;
}
