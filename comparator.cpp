#include "comparator.hpp"

bool FCFSComparator::operator() (Process P1, Process P2){
        return P1.get_arrival_time() > P2.get_arrival_time();
    }


bool SRTFComparator::operator() (Process P1, Process P2){
        return P1.get_burst_time() > P2.get_burst_time();
    }