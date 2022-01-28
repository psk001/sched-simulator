#include <iostream>
#include <bits/stdc++.h>
#include "process-creator.hpp"


using namespace std;

int main(){
    int simulation_time, time_quantum;;
    string scheduling_algorithm;

    if(scheduling_algorithm == "round robin")        
        std::cin >> time_quantum;
    
    ProcessCreator fProcessCreator;

    fProcessCreator.create_process_list();
    fProcessCreator.display_process_list();

    return 0;
}