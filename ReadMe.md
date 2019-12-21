# C++ implementation of various datastructures.

## Node
### General Purpose Node Module

## Circular Linked List
**uses node.h & node.cpp

* 1. isEmpty() return bool True if empty and false if not empty
* 2. insertAtStart(int) takes integer as parameter and adds at start Time complexity : O(1)
* 3. void insertAtEnd(int) takes integer as parameter and adds at end Time complexity : O(1)
* 4. deleteAtStart() deletes node at start Time Complexity : O(1)
* 5. front() returns integer value of node stored at start O(1)
* 6. void display() used for debugging shows entire queue O(n)



## Queue
### General Purpose Queue Module

Functions
* 1. dequeue ->> removes the element added most long ago, accepts no argument, returns no argument, Time Complexity : O(1) 
* 2. enqueue ->> adds element to queue, accepts integer argument, returns no argument, Time Complexity : O(1)
* 3. peek ->> returns most ago added element, accepts no parameter, Time Complexity : O(1)
* 4. is_empty ->> returns true if queue is empty, else returns false, accepts no argument, Time Complexity O(1)
* 5. display ->> displays entire queue, Time Complexity : O(n)

## Stack
### General Purpose Stack Module

Functions 
* 1. is_empty ->> returns booleans, if empty returns true else false, takes no parameter. Time Complexity : O(1)
* 2. push ->> takes int parameter to push a element to stack, returns nothing. Time Complexity : O(1)
* 3. pop ->> pops topmost element, takes no parameter, returns no parameter. Time Complexity : O(1)
* 4. top ->> returns topmost element without poping, takes no parameter. Time Complexity : O(1)
* 5. display ->> displays stack from top to bottom, Time Complexity : O(n)


## BST
### Binary Search Tree
* 1. void insert(int) insert a node
* 2. void inorder() inorder traversal
* 3. bool operator== (bst bst2) takes bst as argument and return True if they are equal
* 4. bool is_structurally_same(bst bst2) takes a bst as argument and return True if they are structurally equal 
* 5. void mirror_image() gives mirror image of binary tree
* 6. void r30() rotates bst by 120 degree
* 7. void path() displays path to each leaf node
* 8. bool sum_leaf(int) returns True if path sum to a leaf node is equal to given int parameter
* 9. int possible_structs(int) returns no of possible structural combinations of current tree



## Graph 
* 1. void addEdge(int,int,int distance = 1) : adds edge between given two nodes with distance given as third parameter. 
* 2. void showEdges() : displays all edges
* 3. void breadthFirstSearch(int) :  BFS of the graph with start vertix as given parameter.
* 4. void depthFirstSearch(int) : DFS of graph with start vertix as given parameter.