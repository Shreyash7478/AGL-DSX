/*
Innovation Eternity
*/
#ifndef NODE_H
#define NODE_H

#include<iostream>

struct node{
    int data;
    node *next;
    node(int, node* Tnext = NULL);
};

#endif

/*
----Module Documentation----
General Purpose Node Module

Functions 
1. Constructor ->> takes two parameters, parameter_1 : data to be stored, parameter_2 : pointer to next node (NULL BY DEAFULT).

*/
