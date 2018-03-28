#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

struct Dis {
    string path;
    int value;
    bool visit;
    Dis() {
        visit = false;
        value = 0;
        path = "";
    }
};

class Graph_DG {
private:
    int vexnum;
    int edge;
    int **arc;
    Dis *dis;
public:
    Graph_DG(int vexnum, int edge);
    ~Graph_DG();
    bool check_edge_value(int start, int end, int weight);
    void createGraph();
    void print();
    void Dijkstra(int begin);
    void print_path(int);
};

#endif // DIJKSTRA_H_INCLUDED
