#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "scheduler.hpp"

#define MAX_LEN 50

using namespace std;

void run_simulator(string sched_algo, int simulation_time){
    Scheduler newComp(simulation_time);

    if(sched_algo=="f")
        newComp.first_come_first_serve();
 
    else if(sched_algo=="round robin")
        newComp.round_robin();

    else if(sched_algo=="shortest time first")
        newComp.shortest_time_first();

    else
        cout << "---enter a valid algorithm---\n";

    return;
}

int main(){
    int simulation_time, time_quantum;;
    string scheduling_algorithm;

    cout << "Enter scheduling algorithm: ";
    getline(cin, scheduling_algorithm);


    if(scheduling_algorithm == "round robin"){
        cout << "Enter time quantum: ";        
        cin >> time_quantum;
    }


    cout << "Enter simulation duration: ";
    cin >> simulation_time;

    
    run_simulator(scheduling_algorithm, simulation_time);

    return 0;
}