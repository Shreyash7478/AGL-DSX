#include"hstb.h"
hashtable::hashtable(){
    for(int i =0;i<9;i++){
        bucket[i] = NULL;
    }
    last_added=NULL;
    eol = new node;
    eol->key=-1;
    eol->next=NULL;
    eol->prev_ele=NULL;
    eol->next_ele = NULL;
}

int hashtable::hashfunction(int key){
    return key % 9;
}

int hashtable::insert(int key){
    int bucket_index = hashfunction(key);
    node *new_node = new node;
    new_node->key=key;
    new_node->next=NULL;
    new_node->prev_ele=NULL;
    new_node->next_ele=NULL;
    if(bucket[bucket_index]==NULL){
        bucket[bucket_index] = new_node;
    }else{
        node *temp = bucket[bucket_index];
        if(temp->key==key){
            return 0;
        }
        while(temp->next!=NULL){
            if(temp->key==key){
                return 0;
            }
            temp=temp->next;
        }
        temp->next=new_node;
    }
    if(last_added!=NULL){
        last_added->next_ele=new_node;
        new_node->prev_ele=last_added;
        last_added=new_node;
    }else{
        last_added=new_node;
    }
    
    return 1;
}

node* hashtable::search(int key){
    int bucket_index = hashfunction(key);
    if (bucket[bucket_index] == NULL){
        return eol;
    }else{
        node *temp = bucket[bucket_index];
        while (temp != NULL){
            if (temp->key == key){
                return temp;
            }
            temp = temp->next;
        }
    }
    return eol;
}

int hashtable::del(int key){
    int bucket_index = hashfunction(key);
    if (bucket[bucket_index] == NULL){
        return 0;
    }else{
        node *prev = bucket[bucket_index];
        if(prev->key == key){
            prev->prev_ele->next_ele=prev->next_ele;
            prev->next_ele->prev_ele=prev->prev_ele;
            bucket[bucket_index] = prev->next;
            delete prev;
            return 1;
        }
        node *temp = prev->next;
        while (temp != NULL){
            if (temp->key == key){
                temp->prev_ele->next_ele = temp->next_ele;
                temp->next_ele->prev_ele = temp->prev_ele;
                prev->next = temp->next;
                delete temp;
                return 1;
            }
            prev = prev->next;
            temp = prev->next;
        }
    }
    return 0;
}
node* hashtable::operator[](int index){
    return search(index);
}

node* hashtable::EOL(){
    return eol;
}

hashtable hashtable::union_(hashtable t2){
    node* temp = last_added;
    hashtable to_return;
    while(temp!=NULL){
        to_return.insert(temp->key);
        temp=temp->prev_ele;
    }
    temp = t2.last_added;
    while(temp!=NULL){
        to_return.insert(temp->key);
        temp = temp->prev_ele;
    }
    return to_return;
}

hashtable hashtable::intersection(hashtable t2){
    node *temp = last_added;
    hashtable to_return;
    while (temp != NULL){
        if(t2.search(temp->key)!=t2.EOL()){
            to_return.insert(temp->key);
        }
        temp = temp->prev_ele;
    }
    return to_return;
}

hashtable hashtable::difference(hashtable t2){
    node *temp = last_added;
    hashtable to_return;
    while (temp != NULL){
        if (t2.search(temp->key) == t2.EOL())
        {
            to_return.insert(temp->key);
        }
        temp=temp->prev_ele;
    }
    return to_return;
}

bool hashtable::subset(hashtable t2){
    node *temp = t2.last_added;
    while(temp!=NULL){
        if(search(temp->key)==EOL()){
            return false;
        }
        temp = temp->prev_ele;
    }
    return true;
}

void hashtable::enumerate(){
    node *temp = last_added;
    std::cout<<"Key\n";
    while(temp!=NULL){
        std::cout<<temp->key<<"\n";
        temp=temp->prev_ele;
    }
}
