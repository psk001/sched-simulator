#include <queue>
#include <string>

#include "process.hpp"
#include "process-creator.hpp"


class Scheduler{
    int simulation_time;
    std::priority_queue <Process> ready_queue;

    public:
        Scheduler();
        Scheduler(int);
        void first_come_first_serve();
        void shortest_time_first();
        void round_robin();
        
};