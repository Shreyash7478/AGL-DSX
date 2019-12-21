#ifndef DLLFUNCTIONS_H
#define DLLFUNCTIONS_H

#include"dllnode.h"
#include<stdio.h>
#include<stdlib.h>


dllnode* dllHeadInsertAtStart(dllnode* head, int n){
    dllnode* temp2 = (dllnode*)malloc(sizeof(dllnode));
    temp2->data = n;
    temp2->next = head;
    temp2->prev = NULL;
    if(head){
        head->prev = temp2;
    }
    return temp2;
}

dllnode* dllHeadInsertAtEnd(dllnode* head, int n){
    dllnode *temp2 = (dllnode*)malloc(sizeof(dllnode));
    temp2->data = n;
    temp2->next = NULL;
    if(head == NULL){
        return temp2;
    }
    dllnode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = temp2;
    temp2->prev = temp;
    return head;
}

dllnode* dllHeadGetTail(dllnode* head){
    dllnode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

dllnode* dllTailGetHead(dllnode* tail){
    dllnode* temp = tail;
    while(temp->prev!= NULL){
        temp = temp->prev;
    }
    return temp;
}

void dllTailDisplay(dllnode* tail){
    dllnode *temp = tail;
    printf("TAIL");
    while(temp!=NULL){
        printf(" -> %d",temp->data);
        temp = temp->prev;
    }
    printf(" <- HEAD\n");

}

void dllHeadDisplay(dllnode* head){
    dllnode *temp = head;
    printf("HEAD");
    while(temp!=NULL){
        printf(" -> %d",temp->data);
        temp = temp->next;
    }
    printf(" <- TAIL\n");

}

dllnode* dllTailInsertAtStart(dllnode* tail, int data){
    dllnode *temp2 = (dllnode*)malloc(sizeof(dllnode));
    temp2->data = data;
    temp2->prev = NULL;
    if(tail == NULL){
        temp2->next = NULL;
        return temp2;
    }
    dllnode *temp = tail;
    while(temp->prev!=NULL){
        temp = temp->prev;
    }
    temp->prev = temp2;
    temp2->next = temp;
    return tail;
}

dllnode* dllTailInsertAtEnd(dllnode* tail, int data){
    dllnode *temp2 = (dllnode*)malloc(sizeof(dllnode));
    temp2->data = data;
    temp2->prev = tail;
    temp2->next = NULL;
    if(tail != NULL){
        tail->next = temp2;
    }
    return temp2;
}

#endif //DLLFUNCTIONS_H