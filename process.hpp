#pragma once
#ifndef PROCESS_H
#define PROCESS_H 
 
class Process{
    //private:
    public:
        int process_id;
        int arrival_time;
        int cpu_burst_time;
        int completion_time;
        int turn_around_time;
        int waiting_time;
        int response_time;
    
 //   public:
        Process();
        Process(int pid, int arrival_time, int burst_time);
        void display_process_data();

        friend class FCFSComparator;
        friend class SRTFComparator;
        friend class RoundRobinComparator;
        friend class Scheduler;

};

#endif