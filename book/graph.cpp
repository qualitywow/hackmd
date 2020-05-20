#include <iostream>
using namespace std;



class Graph {
private:
    int weight;
    Graph * next;

public:
    Graph create();
    Graph InsertVertex(graph, v);
    Graph InsertEdge(graph, v1, v2);
    Graph DeleteVertex(graph, v);
    Graph DeleteEdge(graph, v1, v2);
    Bool IsEmpty(graph);
    List Adjencent(graph, v);
} // Graph

Graph::create() {
    
}
