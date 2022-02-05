#pragma once
#ifndef COMPARATOR_H
#define COMAPRATOR_H

#include "process.hpp"

class FCFSComparator{
    public:
        bool operator() (const Process, const Process);
};

class SRTFComparator{
    public:
        bool operator() (const Process , const Process);
};

#endif
