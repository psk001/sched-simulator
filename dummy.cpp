#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

#include "simulator.hpp"

#define MAX_LEN 50

using namespace std;


int main(){
    int simulation_time, time_quantum=1, scheduling_algorithm;

    cout << "Enter scheduling algorithm: \n\t 1: First Come First Serve \n\t 2: Shortest Remaining Time First\n\t 3: Round Robin \n";
    cin >> scheduling_algorithm;
    if(scheduling_algorithm == 3){
        cout << "Enter time quantum: ";        
        cin >> time_quantum;
    }

    cout << "Enter simulation duration: ";
    cin >> simulation_time;
      
    Simulator newSimulator(scheduling_algorithm, simulation_time, time_quantum);

    return 0;
}