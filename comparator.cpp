#include "comparator.hpp"

bool FCFSComparator::operator() (const Process& P1, const Process& P2){
            return P1.arrival_time > P2.arrival_time;
    }


bool SRTFComparator::operator() (Process P1, Process P2){
            return P1.arrival_time < P2.arrival_time;
    }