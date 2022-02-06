#include <bits/stdc++.h>
#define mx 100000

using namespace std;

int process_count=0;

class Process{
    private:
        int process_id;
        int arrival_time;
        int cpu_burst_time;
        int completion_time;
        int turn_around_time;
        int waiting_time;
        int response_time; 
        int remaining_time; 
        int sec_burst_time; 

    public:
        int total_process_count=0;
        Process(int pid, int arr_time, int br_time){
            process_id=pid;
            arrival_time=arr_time;
            cpu_burst_time=br_time;
            turn_around_time=-1;
            waiting_time=-1;
            response_time=-1;
            completion_time=-1;
            sec_burst_time=br_time;
        }


        void set_burst_time(int br_time){
            cpu_burst_time=br_time;
        }

        void set_response_time(int curr_time){
            response_time=curr_time;
        }

        void set_completion_time(int com_time){
            completion_time=com_time;
        }

        void set_waiting_time(int wait_time){
            waiting_time=wait_time;
        }

        void set_turn_around_time(int ta_time){
            turn_around_time=ta_time;
        }

        int get_process_id(){
            return process_id;
        }

        int get_arrival_time(){
            return arrival_time;
        }

        int get_burst_time(){
            return cpu_burst_time;
        }
 
        int get_completion_time(){
            return completion_time;
        }

        int get_turn_around_time(){
            return turn_around_time;
        }

        int get_waiting_time(){
            return waiting_time;
        }

        int get_response_time(){
            return response_time;
        }

        int get_sec_burst_time(){
            return sec_burst_time;
        }
};


bool fcfs_comparator(Process* p1, Process* p2){
    return p1->get_arrival_time() < p2->get_arrival_time();
}

class SRTF_comparator{
    public:
        bool operator()(Process* p1, Process* p2){
            return p1->get_burst_time() > p2->get_burst_time();
        }
};



// PROCESS CREATOR CLASS

class ProcessCreator{

    public:
        Process** process_list;
        int process_count;

        ProcessCreator(int num_process){
            process_count=num_process;
        }   

        Process** create_process_list(){
            process_list= new Process* [mx];

            for(int i=0; i<mx; i++){
                int rand_arr_time=rand()%mx+1;
                int rand_brst_time=rand()%100+1;
                process_list[i]=new Process(i, rand_arr_time, rand_brst_time);
            }

            sort(process_list, process_list+mx, fcfs_comparator);
            cout << "\t\tsuccessfully created process list\n";
            return process_list;
        }
};

// SCHEDULER CLASS 

class Scheduler{
    int simulation_time;

    public:
        Scheduler(int sim_time){
            simulation_time=sim_time;
        }

        Process** first_come_first_serve(Process** process_list, int number_of_process){
            cout << "\n\t\tStarted running First Come First Serve algorithm\n";
            
            int curr_process_idx=0;
            int prev_process_idx=0;

            ofstream sfile;
            sfile.open("status.txt");

            sfile << "Time" << setw(10) << "Process Id" << setw(10) << "Status\n";
            sfile <<"------------------------------------------------------------\n";

            while(curr_process_idx < number_of_process){
                Process* temp_process = process_list[curr_process_idx];

                if(temp_process->get_arrival_time() >= prev_process_idx){
                    prev_process_idx=temp_process->get_arrival_time();
                    temp_process->set_response_time(0);
                }
                else{
                    temp_process->set_response_time(prev_process_idx-temp_process->get_arrival_time());
                }
                sfile << right ;
                sfile << temp_process->get_arrival_time() << setw(10) << temp_process->get_process_id() << setw(10) << "arrived"  << endl;
                sfile << prev_process_idx << setw(10) << temp_process->get_process_id() << setw(10) << "running" <<  endl;
                
                prev_process_idx+=temp_process->get_burst_time();

                sfile << prev_process_idx << setw(10) << temp_process->get_process_id() << setw(10) << "exited" <<  endl;

                temp_process->set_completion_time(prev_process_idx);
                temp_process->set_turn_around_time(temp_process->get_completion_time()-temp_process->get_arrival_time());
                temp_process->set_waiting_time(temp_process->get_turn_around_time()-temp_process->get_burst_time());
            }

            sfile.close();

            cout << "\n\t\tFinished running First Come First Serve algorithm\n";
            return process_list;
        }

        Process** shortest_rem_time_first(Process** process_list, int num_process){
            cout << "\n\t\tstarted running Shortest Running Time First Algorithm\n";
            int curr_time=0;
            int curr_process_idx=0;

            priority_queue<Process*, vector<Process*>, SRTF_comparator> ready_queue;
            cout << "\n\tpriority queue created\n";

            ofstream sfile;
            sfile.open("status.txt");

            sfile << "Time" << setw(10) << "Process Id" << setw(10) << "Status\n";
            sfile <<"------------------------------------------------------------\n";

            for(curr_time=0; curr_time<=simulation_time; curr_time++){
                while(curr_process_idx < num_process and process_list[curr_process_idx]->get_arrival_time()==curr_time) {
                   // if(process_list[curr_process_idx]->get_arrival_time()==curr_time){
                        sfile << process_list[curr_process_idx]->get_arrival_time() << setw(10) << process_list[curr_process_idx]->get_process_id() << setw(10) << "arrived"  << endl;

                        ready_queue.push(process_list[curr_process_idx]);
                        curr_process_idx++; 
                   // }
                }

                if( ready_queue.size() != 0){
                    Process* temp_process=ready_queue.top();
                    ready_queue.pop();

                    if(temp_process->get_burst_time() > 0){
                        sfile << curr_time << setw(10) << temp_process->get_process_id() << setw(10) << "running"  << endl;
                    }

                    if(temp_process->get_response_time() == -1){
                        temp_process->set_response_time(curr_time-temp_process->get_arrival_time());
                    }

                    if(temp_process->get_burst_time()==0){
                        sfile << curr_time << setw(10) << temp_process->get_process_id() << setw(10) << "exited"  << endl;
                        temp_process->set_completion_time(curr_time);
                        temp_process->set_turn_around_time(temp_process->get_completion_time()-temp_process->get_arrival_time());
                        temp_process->set_waiting_time(temp_process->get_turn_around_time()-temp_process->get_sec_burst_time());
                        temp_process->set_burst_time(temp_process->get_sec_burst_time());                        
                    }

                    else{
                        temp_process->set_burst_time(temp_process->get_burst_time()-1);
                        ready_queue.push(temp_process);
                    }

                }

                // curr_time++;
            }

            sfile.close();

            cout << "\n\t\tfinished running Shortest Running Time First Algorithm\n";
            return process_list;
        }
};

class Simulator{
    int simulation_time;
    int time_quatum;
    int sched_algo;

    public:
        Simulator(){}

        Simulator(int sim_time, int sched_alg, int time_q=-1){
            simulation_time=sim_time*1000;
            sched_algo=sched_alg;
            time_quatum=time_q;
        }

        void start_simulation(){
            cout << "\n\t\tsimulation started\n";

            ProcessCreator process_list_creator(mx);
            Process** process_list = process_list_creator.create_process_list();

            Scheduler newScheduler(simulation_time);

            if(sched_algo==1)
                write_to_file(newScheduler.first_come_first_serve(process_list, mx), mx);

            else if(sched_algo==2)
                write_to_file(newScheduler.shortest_rem_time_first(process_list, mx), mx);

            cout << "\n\t\tsimulation finished\n";
            return;
        }


        void write_to_file(Process** process_list, int len){
            cout << "\n\t\twriting to file started\n";
            ofstream pfile;
            pfile.open("process.txt");

            pfile << "PID" << setw(10) << "AT" << setw(10) << "BT" << setw(10) <<  "CT" << setw(10) << "TAT" << setw(10) << "WT" << setw(10) << "RT\n";

            for(int i=0; i<len; i++){
                pfile << left;
                pfile << setw(10) << process_list[i]->get_process_id();
                pfile << setw(10) << process_list[i]->get_arrival_time() ;
                pfile << setw(10) << process_list[i]->get_burst_time() ;
                pfile << setw(10) << process_list[i]->get_completion_time() ;
                pfile << setw(10) << process_list[i]->get_turn_around_time();
                pfile << setw(10) << process_list[i]->get_waiting_time() ; 
                pfile << setw(10) << process_list[i]->get_response_time() << "\n"; 
            }

            cout << "\n\t\twriting to file finished\n";
            return;
        }   

};


int main(){
    int simulation_time, sched_algo, time_q;

    cout << "Enter simulation time: ";
    cin >> simulation_time;

    cout << "Choose sheduling algorithm\n\t 1 : First Come First Serve\n\t 2 : Shortest Remaining Time First\n\t 3 : Round Robin Algorithm\n\t  ";
    cin >> sched_algo;

    if(sched_algo==1){
        Simulator simulator(simulation_time, sched_algo, 0);
        simulator.start_simulation();
    }
    else if(sched_algo==2){
        Simulator simulator(simulation_time, sched_algo, 0);
        simulator.start_simulation();
    }
    else{
        cout << "\n\tenter a valid choice\n";
    }

    return 0;
}