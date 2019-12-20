#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>

#define DEBUG

class MinHeap{
    private:
        int* arr;
        int len;
        int max;

        int getLeftChild(int);
        int getRightChild(int);
        int parent(int);

        void minheapify(int);
        void heapify();
        void swap(int,int);
        bool isFull();

    public:
        MinHeap(int*,int ,int tmax = 0);   
        int getMin();
        int extractMin();
        bool insert(int);
        
        
        #ifdef DEBUG
        void display();
        #endif //DEBUG
};

#endif //MINHEAP_H