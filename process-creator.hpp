#pragma once
#ifndef PROCESSCREATOR_H
#define PROCESSCREATOR_H
 
#include <vector>
#include "process.hpp"
//#include "scheduler.hpp"

class ProcessCreator{
   // private:
    public:
        std::vector<Process> process_list;
    
  //  public:
        ProcessCreator();
        void create_process_list();
        void display_process_list();
        Process create_new_process();

       // friend class Scheduler;
};

#endif 