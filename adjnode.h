/*
Innovation Eternity
*/
#ifndef ADJNODE_H
#define ADJNODE_H

#include<iostream>


typedef struct adjnode{
    int index;
    int data;
    struct adjnode *next;
}adjnode;

typedef struct bucket{
    int bucket_index;
    struct adjnode *head;
    struct bucket *next;
}bucket;



#endif