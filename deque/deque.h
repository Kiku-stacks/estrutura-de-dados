#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdbool.h>
#include "node.h"

typedef struct {
    Node* front;
    Node* back;
    int tamanho;
}Deque;

void initDeque(Deque* d);
void destroyDeque(Deque* d);
bool isEmpty(Deque* d);
int front(Deque* d);          
int back(Deque* d);
void popFront(Deque* d, int *elemento);
void popBack(Deque* d, int *elemento);      
void makeEmpty(Deque* d);
void pushBack(Deque* d, int elem); 
void pushFront(Deque* d, int elem); 
int size(Deque* d);
void findItem(Deque* dq, int item);
void printFrontBack(Deque* d);
void printBackFront(Deque* d);


#endif
