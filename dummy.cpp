#include <iostream>
#include <bits/stdc++.h>
#include "process_creator.h"

using namespace std;

int main(){
    int simulation_time, time_quantum;;
    string scheduling_algorithm;

    if(scheduling_algorithm == "round robin")        
        cin >> time_quantum;
    
    Process_Creator fProcessCreator;

    fProcessCreator.create_process_list();
    fProcessCreator.display_process_list();

    return 0;
}