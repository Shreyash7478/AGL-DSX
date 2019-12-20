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