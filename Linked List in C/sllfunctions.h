#ifndef SLLFUNCTIONS_H
#define SLLFUNCTIONS_H
#include"sllnode.h"
#include<stdio.h>
#include<stdlib.h>

sllnode* sllDeleteAtStart(sllnode* head){
    if(head == NULL){
        return head;
    }
    sllnode* temp = head;
    head = head->next;
    free(temp);
    return head;
}
 
sllnode* sllDeleteAtEnd(sllnode* head){
    if(head == NULL || head->next == NULL){
        if(head != NULL){
            free(head);
        }
        return NULL;
    }
    sllnode* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

sllnode* sllInsertAtStart(sllnode* head, int n){
    sllnode* temp2 = (sllnode*)malloc(sizeof(sllnode));
    temp2->data = n;
    temp2->next = head;
    return temp2;
}

sllnode* sllInsertAtEnd(sllnode* head, int n){
    sllnode *temp2 = (sllnode*)malloc(sizeof(sllnode));
    temp2->data = n;
    temp2->next = NULL;
    if(head == NULL){
        return temp2;
    }
    sllnode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = temp2;
    return head;
}

void sllDisplay(sllnode* head){
    while(head){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
    return;
}

#endif //SLLFUNCTIONS_H