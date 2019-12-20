#include"queue.h"
#include"node.h"
#include<iostream>


bool Queue::is_empty(){
    return container == NULL;
}

void Queue::dequeue(){
    container->deleteAtStart();
}

void Queue::enqueue(int data){
    container->insertAtEnd(data);
}

Queue::Queue(){
    container = new CircularLinkedList();
}

int Queue::peek(){
    return container->front();
}
