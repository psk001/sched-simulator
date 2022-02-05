#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


#include "scheduler.hpp"
#include "comparator.hpp"
#include "minheap.hpp"

using namespace std;

Scheduler::Scheduler(){}

Scheduler::Scheduler(int sim_time, int time_q){
    simulation_time=sim_time;
    time_quantum=time_q;
}

void Scheduler::first_come_first_serve(vector<Process>& ready_queue){
    cout << "\t\tFirst Come First Serve Algorithm started.....\n";

    vector<Process> result;

    ofstream writeFile;
    writeFile.open("output.txt");
    writeFile << "Process-Id  Arrival  Burst Waiting  Response  Turn-around  Completion\n";
    writeFile << "---------------------------------------------------------------------\n";

    int processCount=0;

    priority_queue <Process, vector<Process>, FCFSComparator> fcfs_queue;
    
    for(auto i: ready_queue){
            fcfs_queue.push(i);
    }

    int current_last_arrival=0;

    Process temp=fcfs_queue.top(); 
    temp.set_waiting_time(0);
    temp.set_completion_time(temp.get_arrival_time()+temp.get_waiting_time()+temp.get_burst_time());
    temp.set_turn_around_time(temp.get_waiting_time()+temp.get_burst_time());
    temp.set_response_time(0);

    result.push_back(temp);

    fcfs_queue.pop();

    for(int i=0; i<simulation_time*1000; i++){

        Process prevProcess=result[processCount];

        temp=fcfs_queue.top();

        temp.set_waiting_time(max(0, prevProcess.get_completion_time()-temp.get_arrival_time())); //temp.get_arrival_time()- temp.get_burst_time()+prevProcess.waiting_time();
        temp.set_turn_around_time(temp.get_waiting_time() + temp.get_burst_time());
        temp.set_completion_time(temp.get_arrival_time()+temp.get_turn_around_time());
        temp.set_response_time(min(prevProcess.get_completion_time(), temp.get_arrival_time()));
        temp.set_turn_around_time(temp.get_burst_time() + temp.get_waiting_time());

        writeFile << "  " << temp.get_process_id() << " \t" << temp.get_arrival_time() << " \t" << temp.get_burst_time();
        writeFile << " \t"  << temp.get_waiting_time() << " \t" << temp.get_response_time()<< " \t\t" << temp.get_turn_around_time();
        writeFile << " \t" << temp.get_completion_time() << endl;


        fcfs_queue.pop();

        result.push_back(temp);

        // if(fcfs_queue.size()==0){
        //     fcfsProcessCreator.create_process_list();
            
        //     for(auto i: fcfsProcessCreator.get_process_list()){
        //         fcfs_queue.push(i);
        //     }
        // }

        processCount++;
    }

    std::cout << "successfully wrote the result to output.txt \n";

    // for(auto i: result)
    //     i.get_display_process_data();

    return;
}

void Scheduler::round_robin(vector<Process>& ready_queue, int time_q){
    cout << "\t\tRound Robin Algorithm started.....\n";
    int timeQuantum=time_q;

    vector<Process> inputList = ready_queue;

    MinHeap minHeap("round robin");

    unordered_map<int, int> col;
    vector<Process> processArr;


    ofstream writeFile;
    writeFile.open("output.txt");
    writeFile << "Process-Id  Arrival  Burst Waiting  Response  Turn-around  Completion\n";
    writeFile << "---------------------------------------------------------------------\n";

    int k=1;

    for(int t=0; t<simulation_time*10; t++){
        cout << "t value: " << t << endl;

        ofstream sfile;
        sfile.open("status.txt");
        

        for(int i=1;i<ready_queue.size(); i++){
            if(ready_queue[i].get_arrival_time()==t){
                minHeap.insert(ready_queue[i]);
                sfile << t << "\t" << ready_queue[i].get_process_id() << "\t" << "Arrived\n" ;
            }
        }

        processArr=minHeap.get_min_heap(); // works

        if(t==k){

            k += min(timeQuantum, processArr[0].get_burst_time());
            processArr[0]=minHeap.update_burst_time(processArr[0].get_burst_time()-min(timeQuantum, processArr[0].get_burst_time()));

            if(col[processArr[0].get_process_id()]==0)
                col[processArr[0].get_process_id()]=t;

            if(processArr[0].get_burst_time()==0 && k<=simulation_time*10){
                inputList[processArr[0].get_process_id()].update(k, col[processArr[0].get_process_id()]);
            }
            else
                minHeap.update(processArr);
        }

        sfile.close();
    }

    writeFile.close();

    return;
}


void Scheduler::shortest_rem_time_first(vector<Process>& ready_queue){
    cout << "\t\tShortest Remaining TIme First Algorithm started....\n";
    MinHeap minHeap("SRTF");

    vector<Process> inputList = ready_queue;

    unordered_map<int, int> col;
    vector<Process> processArr;
    vector<Process> result;

    ofstream writeFile;
    writeFile.open("output.txt");
    writeFile << "Process-Id  Arrival  Burst Waiting  Response  Turn-around  Completion\n";
    writeFile << "---------------------------------------------------------------------\n";

    int k=1;

    for(int t=0; t<simulation_time*10; t++){

        cout << "t value: " << t << endl;

        ofstream sfile;
        sfile.open("status.txt");

        for(int i=1;i<ready_queue.size(); i++){
            if(ready_queue[i].get_arrival_time()==t){
                minHeap.insert(ready_queue[i]);
                sfile << t << "\t" << ready_queue[i].get_process_id() << "\t" << "Arrived\n" ;
            }
        }


        minHeap.heapify();
        processArr=minHeap.get_min_heap();

        if(processArr[0].get_burst_time()){
            processArr[0]=minHeap.update_burst_time(processArr[0].get_burst_time()-1);

            if(not col[processArr[0].get_process_id()])
                col[processArr[0].get_process_id()]=t;
        }

        else{
            inputList[processArr[0].get_process_id()].update(t, col[processArr[0].get_process_id()]);
        }

    }

    writeFile.close();
    return;
}





