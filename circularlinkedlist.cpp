#include"circularlinkedlist.h"

CircularLinkedList::CircularLinkedList(){
    tail = NULL;
}

bool CircularLinkedList::isEmpty(){
    return tail == NULL;
}

void CircularLinkedList::insertAtStart(int data){
    node* new_node = new node(data);
    if(isEmpty()){
        new_node->next = new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;
}

void CircularLinkedList::insertAtEnd(int data){
    node* new_node = new node(data);
    if(isEmpty()){
        new_node->next = new_node;
    }else{
        new_node->next = tail->next;
        tail->next = new_node;
    }
    tail = new_node;
}

void CircularLinkedList::deleteAtStart(){
    if(isEmpty()){
        return;
    }
    if(tail->next == tail){
        node *temp = tail;
        tail =  NULL;
        delete(temp);
        return;
    }
    node *temp = tail->next;
    tail->next = temp->next;
    delete(temp);
}

int CircularLinkedList::front(){
    if(isEmpty()){
        return -1;
    }
    return tail->next->data;
}

void CircularLinkedList::display(){
    if(isEmpty()){
        return;
    }
    node *temp = tail;
    std::cout<<"HEAD";
    do{
        temp = temp->next;
        std::cout<<"-> "<<temp->data;
    }while (temp != tail);
    std::cout<<std::endl;
}