#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include <string>

#include "process.hpp"
#include "process-creator.hpp"


class Scheduler{
    public:

    int simulation_time;
    int time_quantum;
    std::vector<Process> result;
    std::priority_queue <Process> ready_queue;

    Scheduler();
    Scheduler(int, int);
    void first_come_first_serve(std::vector<Process>& );
    void shortest_rem_time_first(std::vector<Process>& );
    void round_robin(std::vector<Process>&, int );
        
};

#endif