#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "scheduler.hpp"

class Simulator{
    public:
        Simulator();
        Simulator(Scheduler);
        void process_result();
};

#endif