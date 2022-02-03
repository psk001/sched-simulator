#include <iostream>
#include <fstream>
#include "simulator.hpp"

using namespace std;

Simulator::Simulator(){}

void Simulator::process_result(){
    ofstream writeFile;
    writeFile.open("output.txt");

    // to write writeFile << data;

    writeFile.close();
}