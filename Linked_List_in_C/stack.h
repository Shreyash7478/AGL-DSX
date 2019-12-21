#ifndef STACK_H
#define STACK_H

#include<stdlib.h>
#include"sllfunctions.h"

typedef struct stack{
    struct sllnode *head;
}stack;

stack* stackInit(){
    stack *new_stack = (stack*)malloc(sizeof(stack));
    new_stack->head = NULL;
    return new_stack;
}

int stackIsEmpty(stack *istack){
    return istack->head == NULL;
}

void stackPush(stack* istack, int data){
    istack->head = sllInsertAtStart(istack->head,data);
}

void stackPop(stack* istack){
    istack->head = sllDeleteAtStart(istack->head);
}

int stackTop(stack* istack){
    if(stackIsEmpty(istack)){
        return -1;
    }
    return istack->head->data;
}

#endif //STACK_H