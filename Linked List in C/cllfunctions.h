#ifndef CLLFUNCTIONS_H
#define CLLFUNCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include"sllnode.h"

int ccIsEmpty(sllnode *tail){
    return tail == NULL;
}

//Inserts at Start
sllnode* cllInsertAtStart(sllnode* tail, int data){
    sllnode* new_node = (sllnode*)malloc(sizeof(sllnode));
    new_node->data = data;
    if(ccIsEmpty(tail)){
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    return tail;
}

sllnode* cllInsertAtEnd(sllnode* tail, int data){
    sllnode* new_node = (sllnode*)malloc(sizeof(sllnode));
    new_node->data = data;
    if(ccIsEmpty(tail)){
        new_node->next = new_node;
        return new_node;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    return new_node;
}

sllnode* cllDeleteAtStart(sllnode* tail){
    if(tail->next == tail){
        free(tail);
        return NULL;
    }
    sllnode *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    return tail;
}

int cllFront(sllnode *tail){
    if(ccIsEmpty(tail)){
        return -1;
    }
    return tail->next->data;
}

void cllDisplay(sllnode *tail){
    sllnode *temp = tail;
    printf("HEAD");
    do{
        temp = temp->next;
        printf("-> %d",temp->data);
    }while (temp != tail);
    printf("\n");
}


#endif //CLLFUNCTIONS