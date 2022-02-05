#pragma once
#ifndef PROCESS_H
#define PROCESS_H 
 
class Process{
    private:
        int process_id;
        int arrival_time;
        int cpu_burst_time;
        int completion_time;
        int turn_around_time;
        int waiting_time;
        int response_time;
    
    public:
        Process();
        Process(int pid, int arrival_time, int burst_time);
        void display_process_data();
        int get_process_id();
        int get_arrival_time();
        int get_burst_time();
        int get_completion_time();
        int get_turn_around_time();
        int get_waiting_time();
        int get_response_time();

        void set_burst_time(int );
        void set_completion_time(int );
        void set_turn_around_time(int );
        void set_waiting_time(int );
        void set_response_time(int );
        void update(int, int);

};

#endif