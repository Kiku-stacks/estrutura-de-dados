#include "node.h"
#include <stdlib.h>

Node* createNode(int elem, Node* ptr){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode !=NULL){
        newNode->dado = elem;
        newNode->next = ptr;
    }
    return newNode;
}
