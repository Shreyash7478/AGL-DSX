/*
Innovation Eternity
*/
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include"node.h"
#include"circularlinkedlist.h"


class Queue{
    CircularLinkedList *container;
    public:
        Queue();
        void dequeue();
        void enqueue(int);
        int peek();
        bool is_empty();
        void display();
};

#endif

/*
----Module Documentation----
General Purpose Queue Module

Functions
1. dequeue ->> removes the element added most long ago, accepts no argument, returns no argument, Time Complexity : O(1) 
2. enqueue ->> adds element to queue, accepts integer argument, returns no argument, Time Complexity : O(1)
3. peek ->> returns most ago added element, accepts no parameter, Time Complexity : O(1)
4. is_empty ->> returns true if queue is empty, else returns false, accepts no argument, Time Complexity O(1)
5. display ->> displays entire queue, Time Complexity : O(n)

*/