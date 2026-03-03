#include "node.h"

Node* createNode(int item, Node* ptr) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->dado = item;
        newNode->next = ptr;
    }
    return newNode;
}
