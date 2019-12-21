#include"graph.h"

DirectedGraph::DirectedGraph(int Tvertices){
    links = new AdjacencyMatrix();
    no_of_vertices = Tvertices;
}

void DirectedGraph::addEdge(int from_, int to, int distance){

    links->insert(from_,to,distance);
}

void DirectedGraph::showEdges(){
    links->display();
}

void DirectedGraph::breadthFirstSearch(int current_vertice){
    Queue* vertices = new Queue();
    vertices->enqueue(current_vertice);
    bool *visited = new bool[no_of_vertices]();
    visited[current_vertice] = 1;
    adjnode* neightbors = NULL;
    while(!vertices->is_empty()){
        current_vertice = vertices->peek();
        std::cout<<current_vertice<<"\t";
        
        vertices->dequeue();
        neightbors = links->getBucketHead(current_vertice);
        while(neightbors !=  NULL){
            if(visited[neightbors->index] != 1){
                visited[neightbors->index] = 1;
                vertices->enqueue(neightbors->index);
            }
            neightbors = neightbors->next;
        }
    }
    std::cout<<"\n";
}   

void DirectedGraph::depthFirstSearch(int current_vertice){
    stack* vertices = new stack();
    vertices->push(current_vertice);
    bool *visited = new bool[no_of_vertices]();
    visited[current_vertice] = 1;
    adjnode* neightbors = NULL;
    while(!vertices->is_empty()){
        current_vertice = vertices->top();
        std::cout<<current_vertice<<"\t";
        
        vertices->pop();
        neightbors = links->getBucketHead(current_vertice);
        while(neightbors !=  NULL){
            if(visited[neightbors->index] != 1){
                visited[neightbors->index] = 1;
                vertices->push(neightbors->index);
            }
            neightbors = neightbors->next;
        }
    }
    std::cout<<"\n";
}