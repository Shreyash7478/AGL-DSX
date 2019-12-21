#include<iostream>
#include"set.h"
#include<vector>


void add(int x, struct Node *head){
    Node *temp = head->next;
    Node *prev = head;
    
    while(temp!= NULL){
        if(temp->data == x){
            return;
        }
        temp = temp->next;
        prev = prev->next;
    }
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    prev->next = node;
    head->data= head->data+1;
    
}
struct Node *build(){
    Node *head = new Node;
    head->data = 0;
    head->next = NULL;
    return head;
}
struct Node *build(std::vector<int> arr)
{
    Node* head = new Node;
    head->data = 0;
    head->next = NULL;
    int l = arr.size();
    for(int i =0 ;i<l;i++){
        add(arr[i],head);
    }
    return head;
}
void enumerate(struct Node *head){
    printf("Length : %d\n",head->data);
    Node *temp = head->next;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
bool is_element_of(int x, struct Node *head){
    Node *temp = head->next;
    while(temp!=NULL){
        if(temp->data == x){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

bool is_empty(struct Node *head){
    if(head->data == 0){
        return 1;
    }
    return 0;
}

int size(struct Node *head){
    return head->data;
}

void remove(int x, struct Node *head){
    Node *temp = head;
    while(temp->next != NULL){
        if(temp->next->data == x){
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
            head->data = head->data - 1;
            return;
        }
        temp = temp->next;
    }
}
struct Node *union_(struct Node *head1, struct Node *head2){
    Node *head = build();
    Node *temp = head1->next;
    while(temp != NULL){
        add(temp->data,head);
        temp = temp->next;
    }
    temp = head2->next;
    while(temp != NULL){
        add(temp->data, head);
        temp = temp->next;
    }
    return head;
}

struct Node *difference(struct Node *head1, struct Node *head2){
    Node *head = build();
    Node *temp = head1->next;
    while(temp!=NULL){
        if(!is_element_of(temp->data,head2)){
            add(temp->data,head);
        }
        temp = temp->next;
    }
    return head;  
}

bool subset(struct Node *head2, struct Node *head1){
    Node *temp = head2;
    while(temp !=NULL){
        if(!is_element_of(temp->data,head1)){
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}

struct Node *intersection(struct Node *head1, struct Node *head2){
    Node *to_return = build();
    Node *temp = head1->next;
    int data;
    while(temp!=NULL){
        
        data = temp->data;
        temp = temp->next;
       
        if(is_element_of(data,head2)){
            add(data,to_return);
        }

      
    }

    return to_return;
}


