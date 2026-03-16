#ifndef NODE_H
#define NODE_H

typedef struct node {
    int dado;
    struct node* next;
    struct node* prev;
}Node;

Node* createNode(int elem, Node* ptr);

#endif
