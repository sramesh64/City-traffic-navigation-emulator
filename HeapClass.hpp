#ifndef HEAP_CLASS
#define HEAP_CLASS


#include <iostream>
#include "VertexClass.hpp"

class minheap{
    public:

    minheap(int size);
    ~minheap();
    vertex* extract_min();
    void heapify(int i);
    void build_heap();
    void swap(vertex*& A, vertex*& B);
    bool is_empty();
    void move_up(int index);
    void insert(vertex* A);

    private:
    vertex** array;
    int size;
    int n;


};









#endif