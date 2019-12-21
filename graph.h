/*
Innovation Eternity
*/
#ifndef GRAPH_H
#define GRAPH_H
#include"adjacencymatrix.h"
#include"stack.h"
#include"queue.h"

class DirectedGraph{
    private:
        AdjacencyMatrix *links;
        int no_of_vertices;
    public:
        DirectedGraph(int);
        void addEdge(int,int,int distance = 1);
        void showEdges();
        void breadthFirstSearch(int);
        void depthFirstSearch(int);
};

#endif //GRAPH_H


/*
Graph 
void addEdge(int,int,int distance = 1) : adds edge between given two nodes with distance given as third parameter. 
void showEdges() : displays all edges
void breadthFirstSearch(int) :  BFS of the graph with start vertix as given parameter.
void depthFirstSearch(int) : DFS of graph with start vertix as given parameter.




*/