#include "EdgeClass.hpp"
#include <iostream>

//EDGE member functions


edge::edge(int neighbor, double _d, double _s){
    neighbor_vertex = neighbor;
    d = _d;
    s = _s;
    a = 1;
}
edge::~edge(){

}

edge* edge::get_next_edge(){
    return next_edge;
}
void edge::set_next_edge(edge* _edge){
    next_edge = _edge;
}

int edge::get_neighbor_vertex(){
    return neighbor_vertex;
}

void set_neighbor_vertex(int _neighbor_vertex){
    _neighbor_vertex = _neighbor_vertex;
}

double edge::get_d(){
    return d;
}

void edge::set_d(double _d){
    d = _d;
}

double edge::get_s(){
    return s;
}

void edge::set_s(double _s){
    s = _s;
}

double edge::get_a(){
    return a;
}

void edge::set_a(double _a){
    a = _a;
}