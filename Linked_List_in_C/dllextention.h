#ifndef DLLEXTENTION_H
#define DLLEXTENTION_H

#include"dllfunctions.h"
#include<stdio.h>

dllnode* dllreverse(dllnode *head){
    dllnode* current = head;
    dllnode* next = current->next;

    while(current->next != NULL){
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        current = next;
    }
    current->next = current->prev;
    current->prev = NULL;
    return current;

}













#endif //DLLEXTENTION_H