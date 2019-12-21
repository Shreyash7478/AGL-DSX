#include"adjacencymatrix.h"

AdjacencyMatrix::AdjacencyMatrix(){
    buckets_head = new bucket();
    buckets_head->next = NULL;
}

bucket* AdjacencyMatrix::getBucket(int i){
    bucket* current = buckets_head->next;
    while(current!=NULL && current->bucket_index < i){
        current = current->next;
    }
    if(current != NULL && current->bucket_index == i){
        return current;
    }
    return NULL;
}

adjnode* AdjacencyMatrix::getNode(bucket *header, int j){
    adjnode *current = header->head->next;
    while(current != NULL && current->index < j){
        current = current->next;
    } 
    if(current != NULL && current->index == j){
        return current;
    }
    return NULL;
}

int AdjacencyMatrix::get(int i, int j){
    struct bucket *get_bucket = getBucket(i);
    if(get_bucket == NULL){
        return -1;
    }
    struct adjnode *node = getNode(get_bucket,j);
    if(node == NULL){
        return -1;
    }
    return node->data;
}

bucket* AdjacencyMatrix::addGetBucket(int i){
    bucket* prev = buckets_head;
    bucket* current = buckets_head->next;
    while(current!=NULL && current->bucket_index < i){
        prev = current;
        current = current->next;
    }
    if(current != NULL && current->bucket_index == i){
        return current;
    }
    bucket *new_bucket = new bucket();
    new_bucket->bucket_index = i;
    new_bucket->head = new adjnode();
    new_bucket->head->next=NULL;
    new_bucket->next = current;
    prev->next = new_bucket;
    return new_bucket;
}

void AdjacencyMatrix::addNode(bucket* header, int j, int data){
    adjnode* prev =  header->head;
    adjnode *current = prev->next;
    while(current != NULL && current->index < j){
        prev = current;
        current = current->next;
    } 
    if(current != NULL && current->index == j){
        current->data = data;
        return;
    }
    adjnode *new_node = new adjnode();
    new_node->data = data;
    new_node->index = j;
    prev->next = new_node;
    new_node->next = current;
    return;
}


void AdjacencyMatrix::insert(int i, int j, int Tdata){
    struct bucket *get_bucket = addGetBucket(i);
    addNode(get_bucket,j,Tdata);
}

void AdjacencyMatrix::display(){
    struct bucket *temp = buckets_head->next;
    struct adjnode *temp2;
    while(temp != NULL){
        temp2 = temp->head->next;
        std::cout<<temp->bucket_index<<" -> ";
        while(temp2){
            std::cout<<"("<<temp2->index<<","<<temp2->data<<")\t";
            temp2 = temp2->next;
        }
        temp = temp->next;
        std::cout<<"\n";
    }
}

adjnode* AdjacencyMatrix::getBucketHead(int i){
    struct bucket *get_bucket = getBucket(i);
    if(get_bucket == NULL){
        return NULL;
    }
    return get_bucket->head->next;
}