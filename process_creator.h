#include "process.h"

class Process_Creator{
    std::vector<Process> process_list;
    
    public:
        void create_process_list();
        void display_process_list();
};