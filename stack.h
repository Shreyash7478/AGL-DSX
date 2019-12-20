/*
Innovation Eternity
*/
#ifndef STACK_H
#define STACH_H

#include<iostream>
#include"node.h"

class stack{
    node* head;
    public:
        stack();
        int len();
        bool is_empty();
        void push(int);
        void pop();
        int top();
};

#endif

/*
----Module Documentation----
General Purpose Stack Module

Functions 
1. is_empty ->> returns booleans, if empty returns true else false, takes no parameter. Time Complexity : O(1)
2. push ->> takes int parameter to push a element to stack, returns nothing. Time Complexity : O(1)
3. pop ->> pops topmost element, takes no parameter, returns no parameter. Time Complexity : O(1)
4. top ->> returns topmost element without poping, takes no parameter. Time Complexity : O(1)
5. display ->> displays stack from top to bottom, Time Complexity : O(n)

*/