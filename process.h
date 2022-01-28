 
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
};