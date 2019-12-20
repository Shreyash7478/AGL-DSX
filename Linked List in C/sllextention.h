#ifndef SLLEXTENTION_H
#define SLLEXTENTION_H

#include"sllfunctions.h"

static sllnode* sllMergeparts(sllnode* part_one, sllnode* part_two){
    sllnode* temp1 = part_one;
    sllnode* temp2 = part_two;
    sllnode* newlist = NULL;
    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            newlist = sllInsertAtEnd(newlist,temp1->data);
            temp1 = temp1->next;
        }else{
            newlist = sllInsertAtEnd(newlist,temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1){
        newlist = sllInsertAtEnd(newlist,temp1->data);
        temp1 = temp1->next;
    }

    while(temp2){
        newlist = sllInsertAtEnd(newlist,temp2->data);
        temp2 = temp2->next;
    }
    return newlist;
}


sllnode* sllMergesort(sllnode *head, int len){
    if(len == 1 || len == 0){
        return head;
    }
    sllnode *temp = head;
    sllnode *part_one = NULL;
    sllnode *part_two = NULL;
    int k = (len+1)/2;
    while(k--){
        part_one = sllInsertAtEnd(part_one,temp->data);
        temp = temp->next;
    }
    while(temp!=NULL){
        part_two = sllInsertAtEnd(part_two,temp->data);
        temp = temp->next;
    }
    part_one = sllMergesort(part_one,((len+1)/2));
    part_two = sllMergesort(part_two,len/2);

    return sllMergeparts(part_one,part_two);
}

sllnode* sllreverse(sllnode *head){
    sllnode* prev = NULL;
    sllnode* current = head;
    sllnode* next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
#endif //SLLEXTENTION_H