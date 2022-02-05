#include <iostream>
#include <bits/stdc++.h>
#include "minheap.hpp"

using namespace std;
 
MinHeap::MinHeap(string namestr){
    name = namestr;
}
  
MinHeap::MinHeap(vector<Process> temp, string namestr){
    min_heap = {temp.begin()+1, temp.end()};
    name = namestr;
    heapify();
}

int MinHeap:: get_parent_idx(int idx){
    return (idx-1)>>1;
}

vector<Process> MinHeap:: get_min_heap() {
    return min_heap;
}

void MinHeap::insert(Process p){
    min_heap.push_back(p); // emplace
}

Process MinHeap:: update_burst_time(int x){
    min_heap[0].set_burst_time(x);
    return min_heap[0];
}

void MinHeap:: heapify(){
    if(name == "FCFS"){
        for(int i=min_heap.size(); i>0; i--){
            for(int idx = i-1; idx != 0 && (min_heap[get_parent_idx(idx)].get_arrival_time() > min_heap[idx].get_arrival_time() || (min_heap[get_parent_idx(idx)].get_arrival_time() == min_heap[idx].get_arrival_time() && min_heap[get_parent_idx(idx)].get_process_id() > min_heap[idx].get_process_id())); idx = get_parent_idx(idx)){
                swap(min_heap[get_parent_idx(idx)], min_heap[idx]);
            }
        }
    }
    else if(name == "SRTF"){
        for(int i=min_heap.size(); i>0; i--){
            for(int idx = i-1; idx != 0 && (min_heap[get_parent_idx(idx)].get_burst_time() > min_heap[idx].get_burst_time() || (min_heap[get_parent_idx(idx)].get_burst_time() == min_heap[idx].get_burst_time() && min_heap[get_parent_idx(idx)].get_process_id() > min_heap[idx].get_process_id())); idx = get_parent_idx(idx)){
                swap(min_heap[get_parent_idx(idx)], min_heap[idx]);
            }
        }
    }
}

void MinHeap::update(vector<Process> &temp){
    min_heap.push_back(min_heap[0]); //emplace
    min_heap = {min_heap.begin()+1, min_heap.end()};

    temp = get_min_heap();
}

int MinHeap:: get_minimum(vector<Process> &temp){
    int idx = min_heap[0].get_process_id();

    min_heap = {min_heap.begin()+1, min_heap.end()};
    heapify();

    temp = get_min_heap();

    return idx;
}
