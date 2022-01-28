#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "scheduler.hpp"

#define MAX_LEN 50

using namespace std;

void run_simulator(string sched_algo){
    Scheduler newComp;

    if(sched_algo=="first come first serve")
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

    for(int i=0; i<simulation_time; i++)
        run_simulator(scheduling_algorithm);

    return 0;
}