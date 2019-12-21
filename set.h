#include<iostream>
#include<vector>
#ifndef SET_H
#define SET_H

struct Node
{
    int data;
    Node *next;
};

bool is_element_of(int, struct Node*);
bool is_empty(struct Node*);
int size(struct Node*);
void iterate(struct Node*);
void enumerate(struct Node*);

struct Node* build(std::vector<int> arr);
void add(int x,struct Node*);

void remove(int x, struct Node*);
struct Node* union_(struct Node*, struct Node*);
struct Node* intersection(struct Node*, struct Node*);
struct Node* difference(struct Node*, struct Node*);
bool subset(struct Node*, struct Node*);
#endif