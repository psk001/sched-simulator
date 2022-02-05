#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <string>
#include "process.hpp"
 
class MinHeap{
    private:
        std::vector<Process> min_heap;
        std::string name;
 
    public:
        MinHeap(std::string);
        MinHeap(std::vector<Process>, std::string);
        std::vector<Process> get_min_heap();
        void insert(Process);
        void heapify();
        void update(std::vector<Process>& );
        int get_parent_idx(int);
        int get_minimum(std::vector<Process>& );
        Process update_burst_time(int);

};

#endif

