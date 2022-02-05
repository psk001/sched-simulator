#include <iostream>
#include <fstream>
#include "simulator.hpp"
#include "scheduler.hpp"
#include "process-creator.hpp"


using namespace std;

Simulator::Simulator(){}

Simulator::Simulator(int sched_algo, int sim_time, int time_q){
    
    ofstream sfile;
    sfile.open("status.txt");

    sfile << "time\t Process Id\t Status\n";
    sfile << "----------------------------\n";
    sfile.close();

    ProcessCreator newProcessCreator;
    newProcessCreator.create_process_list();
    vector<Process> ready_queue=newProcessCreator.get_process_list();

    Scheduler newScheduler(sim_time, time_q);
    if(sched_algo==1)
        newScheduler.first_come_first_serve(ready_queue);
    
    else if(sched_algo==2)
        newScheduler.shortest_rem_time_first(ready_queue);

    else if(sched_algo==3)
        newScheduler.round_robin(ready_queue, time_q);

    else
        cout << "Choose a valid algorithm\n";

    newProcessCreator.update_ready_queue(ready_queue);

}

