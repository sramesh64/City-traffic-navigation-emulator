#include "VertexClass.hpp"

#include <iostream>

//VERTEX member functions

vertex::vertex(){

}

vertex::vertex(int vertex_ID){
    ID = vertex_ID;
    edges_head = nullptr;    
}

vertex::~vertex() {//GPT

    edge* current = edges_head;
    while (current != nullptr) {
        edge* next_edge = current->get_next_edge();
        delete current;
        current = next_edge;
    }

    edges_head = nullptr;
}


void vertex::add_edge(int neighbor, double d, double s){
    edge* new_edge = new edge(neighbor, d, s);
    new_edge -> set_next_edge(edges_head);
    edges_head = new_edge;

}


void vertex::update_edge(int neighbor, double d, double s){//GPT
    edge* current = edges_head;
    while (current != nullptr) {
        if (current->get_neighbor_vertex() == neighbor) {
 
            current->set_d(d);
            current->set_s(s);
            return;
        }
        current = current->get_next_edge();
    }


}

void vertex::print(){
    edge* current = edges_head;
    while (current != nullptr) {
        std::cout << current -> get_neighbor_vertex() << " ";
        current = current -> get_next_edge();
    }

}


void vertex::delete_edge(int a){
    //find the edge with edge -> neighbor_vertex == a, and delete that edge (set next_edge of previous element to the next element)
    edge* current = edges_head;
    edge* previous = nullptr;

    while (current != nullptr) {
        if (current->get_neighbor_vertex() == a) {

            if (previous != nullptr) {
                //previous->next_edge = current->next_edge;
                previous -> set_next_edge(current ->get_next_edge());
            } else {
                edges_head = current -> get_next_edge();
            }

            delete current;
            //std::cout << "edge has been deleted\n";
            return;
        }

        previous = current;
        current = current -> get_next_edge();
    }
}

bool vertex::find_edge(int b){
    edge* current = edges_head;
    while(current != nullptr){
        if(current -> get_neighbor_vertex() == b) return true;
        current = current -> get_next_edge();

    }
    return false;

}


edge* vertex::get_edges_head(){
    return edges_head;
}

double vertex::get_time(){
    return time;
}

bool vertex::get_visited(){
    return visited;
}

vertex* vertex::get_predecessor(){
    return predecessor;
}

int vertex::get_ID(){
    return ID;
}

void vertex::set_time(double _time){
    time = _time;

}

void vertex::set_visited(bool _visited){
    visited = _visited;
}

void vertex::set_predecessor(vertex* _predecessor){
    predecessor = _predecessor;
}