#include<iostream>
#include"stack.h"
#include"node.h"

stack::stack(){
    head = new node(0);
}

int stack::len(){
    return head->data;
}

bool stack::is_empty(){
    return head->data == 0;
}

void stack::push(int Tdata){
    head->data++;
    node *temp = new node(Tdata,head->next);
    head->next = temp;
}

void stack::pop(){
    if(is_empty()){
        return;
    }
    head->data--;
    node *temp = head->next;
    head->next = temp->next;
    delete(temp);
}

int stack::top(){
    if(is_empty()){
        return -1;
    }
    return head->next->data;
}