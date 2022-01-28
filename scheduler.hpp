#include <queue>
#include <string>
#include "process-creator.hpp"

class Scheduler{
    std::priority_queue <Process> ready_queue;
   // std::string scheduling_algorithm;

    public:
        Scheduler();
      //  Scheduler(std::string scheduling_algorithm);
        void first_come_first_serve();
        void shortest_time_first();
        void round_robin();
};