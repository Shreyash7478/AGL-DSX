/*
Innovation Eternity
*/
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include"adjnode.h"

class AdjacencyMatrix{
    private:
        struct bucket *buckets_head;
        bucket* addGetBucket(int);
        bucket* getBucket(int);
        adjnode* getBucketHead(int);
        adjnode* getNode(bucket*, int);
        void addNode(bucket*,int,int);

    public:
        AdjacencyMatrix();
        void insert(int, int, int);
        int get(int,int);
        void remove(int);
        void display();

        friend class DirectedGraph;  
};

#endif //ADJACENCYMATRIX_H