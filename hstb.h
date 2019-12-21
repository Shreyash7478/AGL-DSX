#include<iostream>
class hashtable;
struct node{
    int key;
    private:
        node *next;
        node *prev_ele;
        node *next_ele;
    friend class hashtable;
};
class hashtable{
    node *bucket[9];
    int hashfunction(int);
    node *eol;
    node *last_added;
    public:
        hashtable();
        int insert(int);
        node* search(int);
        int del(int);
        node* operator[](int index);
        node *EOL();
        hashtable union_(hashtable t2);
        hashtable intersection(hashtable t2);
        hashtable difference(hashtable t2);
        bool subset(hashtable t2);
        void enumerate();
};
