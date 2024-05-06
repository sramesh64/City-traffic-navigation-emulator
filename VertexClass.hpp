#ifndef VERTEX_CLASS
#define VERTEX_CLASS

#include <iostream>
#include "EdgeClass.hpp"
class vertex{
    public:
    
    vertex();
    vertex(int vertex_ID);
    ~vertex();
    int index_in_heap;
    void add_edge(int neighbor, double d, double s);
    void update_edge(int neighbor, double d, double s);
    void print();
    void delete_edge(int a);
    bool find_edge(int b);

    edge* get_edges_head();
    double get_time();
    bool get_visited();
    vertex* get_predecessor();
    int get_ID();

    void set_time(double _time);
    void set_visited(bool _visited);
    void set_predecessor(vertex* _predecessor);
    

    private:

    edge* edges_head;
    double time;
    bool visited;
    vertex* predecessor;
    int ID;


};


#endif