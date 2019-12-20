#ifndef DLLNODE_H
#define DLLNODE_H

typedef struct dllnode{
    int data;
    struct dllnode *next;
    struct dllnode *prev;
}dllnode;

#endif //DLLNODE_H