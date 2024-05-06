#include "GraphClass.hpp"

#include <fstream>
#include <iostream>
#include <cfloat>
#include <cmath>

//GRAPH member functions

graph::graph(){
    for(int i = 0; i < 500001; i++){
        vertices[i] = nullptr;
    }
    size = 0;
    
}

graph::~graph(){
    for(int i = 0; i < 500001; i++){
        delete vertices[i];
        vertices[i] = nullptr;
    }
    
}

void graph::load(std::fstream& fin){
    int a, b;
    double d, s;
    
    while (fin >> a >> b >> d >> s) {
        insert(a, b, d, s);
    }
}
bool graph::insert(int a, int b, double d, double s){
    if(a <= 0 || a > 500000 || b <= 0 || b > 500000 || d <= 0 || s <= 0){
        return false;
    }

    if(vertices[a] != nullptr && vertices[b] != nullptr && vertices[a] -> find_edge(b)){
        vertices[a] -> update_edge(b, d, s);
        vertices[b] -> update_edge(a, d,s);
        return true;
    }

    if(vertices[a] == nullptr){
        vertices[a] = new vertex(a);
        size++;
    }
    if(vertices[b] == nullptr){
        vertices[b] = new vertex(b);
        size++;
    }
    
    vertices[a] -> add_edge(b, d, s);
    vertices[b] -> add_edge(a, d, s);
    return true;
    
}

bool graph::print(int a){
    if(vertices[a] == nullptr){
        return false;
    }
    vertices[a] -> print();
    return true;

}

bool graph::delete_vertex(int a){
    if(vertices[a] == nullptr){
        return false;
    }

    edge* current = vertices[a] -> get_edges_head();
    while(current != nullptr){
        int neighbor =  current -> get_neighbor_vertex();
        vertices[neighbor] -> delete_edge(a);
        current = current->get_next_edge();
    }

    delete vertices[a];
    vertices[a] = nullptr;
    size--;
    return true;
}

bool graph::traffic(int a, int b, double adj_factor){

    if(adj_factor < 0 || adj_factor > 1 || vertices[a] == nullptr || vertices[b] == nullptr) return false;


    bool a_check = false;
    bool b_check = false;

    edge* current = vertices[a] -> get_edges_head();
    while(current != nullptr){
        if(current -> get_neighbor_vertex() == b){
            current -> set_a(adj_factor);
            a_check = true;
            break;
        }
        current = current -> get_next_edge();
    }

    current = vertices[b] -> get_edges_head();
    while(current != nullptr){
        if(current -> get_neighbor_vertex() == a){
            current -> set_a(adj_factor);
            b_check = true;
            break;
        }
        current = current -> get_next_edge();
    }

    return (a_check && b_check);
}

bool graph::update_adj_factor(int a, int b, double adj_factor){
    if(adj_factor < 0 || adj_factor > 1 || vertices[a] == nullptr || vertices[b] == nullptr) return false;

    bool a_check = false;
    bool b_check = false;

    edge* current = vertices[a] -> get_edges_head();
    while(current != nullptr){
        if(current -> get_neighbor_vertex() == a){
            if(current -> get_a() != adj_factor){
                current -> set_a(adj_factor);
                a_check = true;
            }
            break;
            
            
        }
        current = current -> get_next_edge();
    }

    current = vertices[b] -> get_edges_head();
    while(current != nullptr){
        if(current -> get_neighbor_vertex() == b){
            if(current -> get_a() != adj_factor){
                current -> set_a(adj_factor);
                b_check = true;
            }
            break;
        }
        current = current -> get_next_edge();
    }

    return (a_check && b_check);

}

bool graph::update(std::fstream& fin){
    bool updated = false;

    int a, b;
    double adj_factor;

    while (fin >> a >> b >> adj_factor) {
        if (!(a <= 0 || a > 500000 || b <= 0 || b > 500000)){
            if(update_adj_factor(a, b, adj_factor)){
                updated = true;
            } 
        }
    }

    return updated;
}

void graph::dijkstra_alg(int source){

    for(int i = 1; i < 500001; i++){
        if(vertices[i] != nullptr){
            if(i == source){
                vertices[i] -> set_time(0);
                vertices[i] -> set_visited(true);
            }
            
            else{
                vertices[i] -> set_visited(false);
                vertices[i] -> set_time(DBL_MAX);
            }
            vertices[i] -> set_predecessor(nullptr);

        }
    }
    
    minheap heap{size};

    for(int i = 1; i < 500001; i++){
        if(vertices[i]){
            heap.insert(vertices[i]);
        }
    }

    heap.build_heap();

    while(!heap.is_empty()){
        vertex* current = heap.extract_min();
        current -> set_visited(true);

        edge* curr_edge = current -> get_edges_head();
        while(curr_edge != nullptr){


            double new_time = (curr_edge -> get_d())/(curr_edge -> get_s() * curr_edge -> get_a());
            if((!vertices[curr_edge -> get_neighbor_vertex()] -> get_visited()) && current -> get_time() + new_time < vertices[curr_edge -> get_neighbor_vertex()] -> get_time()){
                
                vertices[curr_edge -> get_neighbor_vertex()] -> set_time(current -> get_time() + new_time);
                vertices[curr_edge -> get_neighbor_vertex()] -> set_predecessor(current);
                heap.move_up(vertices[curr_edge -> get_neighbor_vertex()] -> index_in_heap);
            }
            
            curr_edge = curr_edge -> get_next_edge();

        }
    }
    

}


bool graph::path(int a, int b){
    
    if(vertices[a] == nullptr || vertices[b] == nullptr) return false;

    dijkstra_alg(a);

    if(vertices[b] -> get_predecessor() == nullptr) return false;
                                    //std::cout<<"working"<<std::endl;

    vertex* current = vertices[b];
    while (current != nullptr) {
        std::cout << current->get_ID() << " ";
        current = current -> get_predecessor();
    }
    
    return true;

}


double graph::lowest(int a, int b){
    if(vertices[a] == nullptr || vertices[b] == nullptr){
        std::cout << "failure\n";
        return 0;
    }
    double sum = 0;
    dijkstra_alg(a);
    if (vertices[b] == nullptr || vertices[b]->get_predecessor() == nullptr) {
        std::cout << "failure\n";
        return 0;
    }
    vertex* current = vertices[b];
    while (current->get_predecessor() != nullptr) {
        edge* connectingEdge = nullptr;
        edge* edgePtr = current->get_predecessor()->get_edges_head();


        while (edgePtr != nullptr) { //this logic suggested by open ai
            if (edgePtr -> get_neighbor_vertex() == current -> get_ID()) {
                connectingEdge = edgePtr;
                break;
            }
            edgePtr = edgePtr -> get_next_edge();
        }
        sum = sum + (connectingEdge->get_d()) / (connectingEdge->get_s() * connectingEdge->get_a());

        current = current->get_predecessor();
    }

    std::cout << "lowest is " <<sum << "\n";
    return sum;

}