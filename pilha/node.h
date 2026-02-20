#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct node {
    int dado;
    struct node* next;
} Node;

Node* createNode(int item, Node* ptr) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->dado = item;
        newNode->next = ptr;
    }
    return newNode;
}

#endif
