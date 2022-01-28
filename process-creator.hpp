#pragma once
// #ifndef PROCESS_H
// #define PROCESS_H
#include <vector>
#include "process.hpp"

class ProcessCreator{
    std::vector<Process> process_list;
    
    public:
        ProcessCreator();
        void create_process_list();
        void display_process_list();
};

//#endif