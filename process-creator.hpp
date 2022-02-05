#pragma once
#ifndef PROCESSCREATOR_H
#define PROCESSCREATOR_H
 #include <vector>
#include "process.hpp"


class ProcessCreator{
      private:
        std::vector<Process> process_list;
    
      public:
        ProcessCreator();
        void create_process_list();
        void display_process_list();
        std::vector<Process> get_process_list();
        void update_ready_queue(std::vector<Process>);
        void write_to_file();
};

#endif  