#ifndef QUEUE_H
#define QUEUE_H

#include"cllfunctions.h"

typedef struct queue{
    struct sllnode *tail;
}queue;

queue* queueInit(){
    queue *new_queue = (queue*)malloc(sizeof(queue));
    new_queue->tail = NULL;
    return new_queue;
}

int queueFront(queue* iqueue){
    return cllFront(iqueue->tail);
}

void queueDequeue(queue* iqueue){
    iqueue->tail = cllDeleteAtStart(iqueue->tail);
}

void queueEnqueue(queue* iqueue, int data){
    iqueue->tail = cllInsertAtEnd(iqueue->tail,data);
}

#endif //QUEUE_H