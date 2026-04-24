#ifndef NODE_H
#define NODE_H

typedef struct node {
    int dado;
    struct node* next;
}Node;

Node* createNode(int elem, Node* ptr);

#endif
