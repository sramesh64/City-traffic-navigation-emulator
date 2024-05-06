#ifndef GRAPH_CLASS
#define GRAPH_CLASS
#include "VertexClass.hpp"
#include "EdgeClass.hpp"
#include "HeapClass.hpp"
#include <iostream>

class graph{
    public:

    graph();
    ~graph();
    
    void load(std::fstream& fin);
    bool insert(int a, int b, double d, double s);
    bool print(int a);
    bool delete_vertex(int a);
    bool traffic(int a, int b, double adj_factor);
    bool update_adj_factor(int a, int b, double adj_factor);
    bool update(std::fstream& fin);
    void dijkstra_alg(int a);
    bool path(int a, int b);
    double lowest(int a, int b);

    private:
    vertex* vertices [500001];
    int size;

};



#endif