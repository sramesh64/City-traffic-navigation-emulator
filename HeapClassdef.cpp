#include <iostream>
#include "HeapClass.hpp"

#include <cfloat>
#include <cmath>
//MINHEAP member functions

minheap::minheap(int _size){
    
    size = _size+1;
    //Create a Min Heap of size V where V is the number of vertices in the given graph.
    array = new vertex*[size];
    n = 0;

}

minheap::~minheap() {
    delete[] array;
}

void minheap::build_heap(){
    
    for (int i = floor(n/2); i >= 1; i--){//should this be > instead of >=??
        heapify(i);
    }
    
}

void minheap::heapify(int i){
    int smallest;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && array[left] -> get_time() < array[i] -> get_time()){ //ERROR might be here
        smallest = left;
    }
    else{
        smallest = i;
    }

    if(right <= n && array[right] -> get_time() < array[smallest] -> get_time()){
        smallest = right;
    }

    if(smallest != i){
        swap(array[i], array[smallest]);
        heapify(smallest);

    }

}

void minheap::swap(vertex*& A, vertex*& B){
    vertex* temp = A;

    A = B;

    B = temp;

    //your swap also needs to update index_in_heap
    int tempIndex = A->index_in_heap;
    A->index_in_heap = B->index_in_heap;
    B->index_in_heap = tempIndex;
    
}

vertex* minheap::extract_min(){
    vertex* min = array[1];
    array[1] = array[n];
    

    n--;
    heapify(1);

    return min;
}


bool minheap::is_empty(){
    return n == 0; //the heap is empty when n = 0
}


void minheap::move_up(int index){
    int parent_index = floor(index/2);

    while (index > 1 && array[index] -> get_time() < array[parent_index]-> get_time()) {
        swap(array[index], array[parent_index]);
        index = parent_index;
        parent_index = floor(index/2);
    }

}

void minheap::insert(vertex* A){
    
    n = n + 1;
    int i = n;
    A->index_in_heap = i;  // you need to set index in heap when inserting
    array[i] = A;          //insert the elemnt at the the end of the heap

    int parent_i = floor(i/2);
    while(i > 1 && array[parent_i] -> get_time() > array[i] -> get_time()){
        swap(array[i], array[parent_i]);
        i = parent_i;
        parent_i = floor(i/2);
    }
    
}