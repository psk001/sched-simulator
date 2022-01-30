#include <queue>
#include <string>
#include "process-creator.hpp"

class Scheduler{
    std::priority_queue <Process> ready_queue;
    ProcessCreator newProcess;

    protected:
        bool priorityFCFS(Process, Process);
        bool priorityRR(Process, Process);
        bool prioritySTF(Process, Process);

    public:
        Scheduler();
        void first_come_first_serve();
        void shortest_time_first();
        void round_robin();
};