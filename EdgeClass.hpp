#ifndef EDGE_CLASS
#define EDGE_CLASS

class edge{
    public:
    edge(int neighbor, double _d, double _s);
    ~edge();

    edge* get_next_edge();
    void set_next_edge(edge* _edge);
    int get_neighbor_vertex();
    void set_neighbor_vertex(int _neighbor_vertex);

    double get_d();
    void set_d(double _d);

    double get_s();
    void set_s(double _s);

    double get_a();
    void set_a(double _a);


    private:
    edge* next_edge;
    int neighbor_vertex;
    double d;
    double s;
    double a;

};



#endif
