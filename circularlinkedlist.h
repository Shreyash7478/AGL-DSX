#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include"node.h"

class CircularLinkedList{
    private:
        node *tail;
    public:
        CircularLinkedList();

        bool isEmpty();

        void insertAtStart(int);
        void insertAtEnd(int);

        void deleteAtStart();

        int front();

        void display();

};

#endif //CIRCULARLINKEDLIST_H


/*
Cicular Linked List

isEmpty() return bool True if empty and false if not empty

insertAtStart(int) takes integer as parameter and adds at start Time complexity : O(1)
void insertAtEnd(int) takes integer as parameter and adds at end Time complexity : O(1)

deleteAtStart() deletes node at start Time Complexity : O(1)

front() returns integer value of node stored at start O(1)

void display() used for debugging shows entire queue O(n)
*/