#include"minheap.h"

MinHeap::MinHeap(int *tarr, int tlen, int tmax){
    if(tmax == 0){
        max = 2*tlen;
    }
    arr = new int[max];
    len = tlen;
    for(int i = 0 ; i < len ; i++){
        arr[i] = tarr[i];
    }
    heapify();
}

inline int MinHeap::getLeftChild(int root){
    return 2*root + 1;
}

inline int MinHeap::getRightChild(int root){
    return 2*root + 2;
}

inline int MinHeap::parent(int child){
    return  child/2;
}

inline bool MinHeap::isFull(){
    return len == max;
}

void MinHeap::swap(int n1, int n2){
    arr[n1] += arr[n2];
    arr[n2] = arr[n1] - arr[n2];
    arr[n1] = arr[n1] - arr[n2];
}

void MinHeap::minheapify(int root){
    int smallest = root;
    int temp = getLeftChild(root);
    if(temp < len && arr[temp] < arr[root]){
        smallest = temp;
    }
    temp = getRightChild(root);
    if(temp < len && arr[temp] < arr[smallest]){
        smallest = temp;
    }
    if(smallest != root){
        swap(smallest,root);
        minheapify(smallest);   
    }
}

void MinHeap::heapify(){
    int last_leaf_node = len/2 - 1;
    for(int i = last_leaf_node ; i >= 0 ; i--){
        minheapify(i);
    }
}

bool MinHeap::insert(int data){
    //Check if heap is full
    if(isFull()){
        //If heap is full return with value 1
        return 1; 
    }
    arr[len] = data;
    int i = len;
    int iparent;
    while(i > 0){
        iparent = parent(i);
        if(arr[i] > arr[iparent]){
             break;           
        }
        swap(i,iparent);
        i = iparent;
    }
    len++;
    return 0;
}

int MinHeap::getMin(){
    return arr[0];
}

int MinHeap::extractMin(){
    int imin = arr[0];
    len--;
    arr[0] = arr[len];
    minheapify(0);
    return imin;
}

#ifdef DEBUG
void MinHeap::display(){
    int level_change_at = 1;
    for(int i = 0 ; i < len ; i++){
        if(level_change_at == i){
            std::cout<<"\n";
            level_change_at = 2*level_change_at + 1;
        }
        std::cout<<arr[i]<<"\t";
    }
    std::cout<<std::endl;
}
#endif